#include "can_controller.h"

#include "CanControl.h"

#ifndef ARDUINO
#include <chrono>
#include <thread>
#endif

namespace CanControl
{

    CanController::CanController(MCP2515& controller) : controller_(&controller), heartbeat_state_(default_heartbeat())
    {
    }

    CanController::CanController(Transport& transport, Clock& clock)
        : transport_(&transport), clock_(&clock), heartbeat_state_(default_heartbeat())
    {
    }

    CanController::Error CanController::from_transport_error(MCP2515::ERROR error)
    {
        switch (error)
        {
        case MCP2515::ERROR_OK:
            return Error::Ok;
        case MCP2515::ERROR_ALLTXBUSY:
            return Error::TransmitBusy;
        case MCP2515::ERROR_FAILINIT:
            return Error::InitializationFailed;
        case MCP2515::ERROR_FAILTX:
            return Error::TransmitFailed;
        case MCP2515::ERROR_NOMSG:
            return Error::NoMessage;
        case MCP2515::ERROR_FAIL:
            return Error::TransportFailure;
        default:
            return Error::TransportFailure;
        }
    }

    MCP2515::ERROR CanController::reset_transport()
    {
        return transport_ ? transport_->reset() : controller_->reset();
    }

    MCP2515::ERROR CanController::set_bitrate(CAN_SPEED speed, CAN_CLOCK clock)
    {
        return transport_ ? transport_->set_bitrate(speed, clock) : controller_->setBitrate(speed, clock);
    }

    MCP2515::ERROR CanController::set_normal_one_shot_mode()
    {
        return transport_ ? transport_->set_normal_one_shot_mode() : controller_->setNormalOneShotMode();
    }

    MCP2515::ERROR CanController::send_frame(const struct can_frame& frame)
    {
        if (transport_)
            return transport_->send(frame);

        struct can_frame copy = frame;
        return controller_->sendMessage(&copy);
    }

    unsigned long CanController::now_ms() const
    {
        if (clock_)
            return clock_->now_ms();
#ifdef ARDUINO
        return millis();
#else
        using namespace std::chrono;
        return static_cast<unsigned long>(duration_cast<milliseconds>(steady_clock::now().time_since_epoch()).count());
#endif
    }

    void CanController::delay_ms(unsigned long duration_ms)
    {
        if (clock_)
        {
            clock_->delay_ms(duration_ms);
            return;
        }
#ifdef ARDUINO
        delay(duration_ms);
#else
        std::this_thread::sleep_for(std::chrono::milliseconds(duration_ms));
#endif
    }

    CanController::Error CanController::queue_frame(const struct can_frame& frame)
    {
        if (full_)
        {
            return Error::QueueFull;
        }

        queue_[head_] = frame;
        head_         = (head_ + 1) % QUEUE_SIZE;
        if (head_ == tail_)
        {
            full_ = true;
        }
        return Error::Ok;
    }

    CanController::Error CanController::setup(CAN_SPEED speed, CAN_CLOCK clock)
    {
        MCP2515::ERROR error = MCP2515::ERROR_OK;

        MCP2515::ERROR e1 = reset_transport();
        if (e1 != MCP2515::ERROR_OK)
        {
            error = e1;
        }
        delay_ms(10);

        MCP2515::ERROR e2 = set_bitrate(speed, clock);
        if (e2 != MCP2515::ERROR_OK)
        {
            error = e2;
        }
        delay_ms(10);

        MCP2515::ERROR e3 = set_normal_one_shot_mode();
        if (e3 != MCP2515::ERROR_OK)
        {
            error = e3;
        }
        delay_ms(10);

        return from_transport_error(error);
    }

    CanController::Error CanController::update(unsigned long dt_ms)
    {
        time_since_last_heartbeat_ms_ += dt_ms;
        time_since_last_ctre_enable_ms_ += dt_ms;
        time_since_last_send_ms_ += dt_ms;

        // Rate limiting
        if (time_since_last_send_ms_ < send_interval_ms_)
        {
            return Error::Ok;
        }

        // Handle Heartbeat (Priority 1)
        if (heartbeat_enabled_ && time_since_last_heartbeat_ms_ >= heartbeat_period_ms_)
        {
            // Try to send heartbeat immediately
            const Error error = send_heartbeat();
            if (error == Error::Ok)
            {
                time_since_last_heartbeat_ms_ = 0;
                time_since_last_send_ms_      = 0; // Reset send timer
                return Error::Ok;                  // Only one frame per update period
            }
            return error;
        }

        // Handle CTRE Global Enable (Priority 2)
        if (ctre_enable_active_ && time_since_last_ctre_enable_ms_ >= ctre_enable_period_ms_)
        {
            const Error error = send_ctre_global_enable();
            if (error == Error::Ok)
            {
                time_since_last_ctre_enable_ms_ = 0;
                time_since_last_send_ms_        = 0;
                return Error::Ok;
            }
            return error;
        }

        // Process Queue (Priority 3)
        // If we didn't send a heartbeat or CTRE enable, try to send a queued message.
        if (!(!full_ && head_ == tail_)) // While not empty
        {
            struct can_frame& frame = queue_[tail_];
            MCP2515::ERROR    err   = send_frame(frame);

            if (err == MCP2515::ERROR_OK)
            {
                // Successfully sent
                tail_ = (tail_ + 1) % QUEUE_SIZE;
                full_ = false;

                time_since_last_send_ms_ = 0;
                return Error::Ok; // Done for this cycle
            }
            else
            {
                // Hardware buffers full or error
                // Retry next time.
                return from_transport_error(err);
            }
        }

        // Periodic Senders (Priority 4)
        // If nothing else to send, cycle through registered periodic senders
        if (periodic_count_ > 0)
        {
            // Try up to periodic_count_ times to find one that wants to send
            for (size_t i = 0; i < periodic_count_; i++)
            {
                PeriodicSender* sender = periodic_senders_[periodic_index_];
                periodic_index_        = (periodic_index_ + 1) % periodic_count_;

                struct can_frame frame{};
                if (sender->get_periodic_frame(frame, now_ms()))
                {
                    const Error error = from_transport_error(send_frame(frame));
                    if (error == Error::Ok)
                        time_since_last_send_ms_ = 0;
                    return error;
                }
            }
        }
        return Error::Ok;
    }

    CanController::Error CanController::add_periodic_sender(PeriodicSender* sender)
    {
        if (sender == nullptr)
            return Error::InvalidArgument;
        for (size_t i = 0; i < periodic_count_; ++i)
        {
            if (periodic_senders_[i] == sender)
                return Error::AlreadyRegistered;
        }
        if (periodic_count_ >= MAX_PERIODIC_SENDERS)
            return Error::SenderLimitReached;
        periodic_senders_[periodic_count_++] = sender;
        return Error::Ok;
    }

    CanController::Error CanController::remove_periodic_sender(PeriodicSender* sender)
    {
        if (sender == nullptr)
            return Error::InvalidArgument;
        for (size_t i = 0; i < periodic_count_; ++i)
        {
            if (periodic_senders_[i] != sender)
                continue;

            for (size_t j = i + 1; j < periodic_count_; ++j)
                periodic_senders_[j - 1] = periodic_senders_[j];
            --periodic_count_;
            periodic_senders_[periodic_count_] = nullptr;
            periodic_index_                    = periodic_count_ == 0 ? 0 : periodic_index_ % periodic_count_;
            return Error::Ok;
        }
        return Error::NotRegistered;
    }

    CanController::Error CanController::send_heartbeat()
    {
        can_frame      frame = heartbeat_to_canframe(heartbeat_state_);
        MCP2515::ERROR err   = send_frame(frame);
        return from_transport_error(err);
    }

    CanController::Error CanController::send_ctre_global_enable()
    {
        LowLevel::TalonSrx::talon_can_frame low = LowLevel::TalonSrx::build_global_enable(ctre_enable_state_);
        struct can_frame                    frame{};
        LowLevel::basic_to_can_frame(low, &frame);
        return from_transport_error(send_frame(frame));
    }

    void CanController::set_heartbeat(bool enabled)
    {
        heartbeat_enabled_ = enabled;
    }

    void CanController::set_heartbeat_period(unsigned long period_ms)
    {
        heartbeat_period_ms_ = period_ms;
    }

    void CanController::set_heartbeat_state(const heartbeat::RobotState& state)
    {
        heartbeat_state_ = state;
    }

    void CanController::set_ctre_global_enable(bool enabled)
    {
        ctre_enable_active_ = enabled;
    }

    void CanController::set_ctre_global_enable_period(unsigned long period_ms)
    {
        ctre_enable_period_ms_ = period_ms;
    }

    void CanController::set_ctre_global_enable_state(bool state_enabled)
    {
        ctre_enable_state_ = state_enabled;
    }

    void CanController::set_send_interval(unsigned long interval_ms)
    {
        send_interval_ms_ = interval_ms;
    }

    bool CanController::has_pending_frames() const
    {
        // Queue is empty if head == tail and not full
        return !(!full_ && head_ == tail_);
    }

    CanController::Error CanController::flush(unsigned long interval_ms, unsigned long timeout_ms)
    {
        if (interval_ms == 0)
            interval_ms = 1;

        unsigned long elapsed_ms = 0;
        while (has_pending_frames())
        {
            if (elapsed_ms >= timeout_ms)
                return Error::Timeout;
            update(interval_ms);
            delay_ms(interval_ms);
            elapsed_ms += interval_ms;
        }
        return Error::Ok;
    }

} // namespace CanControl
