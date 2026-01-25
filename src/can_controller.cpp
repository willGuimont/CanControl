#include "can_controller.h"

#include "CanControl.h"

namespace CanControl
{

    CanController::CanController(MCP2515& controller) : controller_(controller), heartbeat_state_(default_heartbeat())
    {
    }

    bool CanController::queue_frame(const struct can_frame& frame)
    {
        if (full_)
        {
            return false;
        }

        queue_[head_] = frame;
        head_         = (head_ + 1) % QUEUE_SIZE;
        if (head_ == tail_)
        {
            full_ = true;
        }
        return true;
    }

    MCP2515::ERROR CanController::setup(CAN_SPEED speed, CAN_CLOCK clock)
    {
        MCP2515::ERROR error = MCP2515::ERROR_OK;

        MCP2515::ERROR e1 = controller_.reset();
        if (e1 != MCP2515::ERROR_OK)
        {
            error = e1;
        }
        delay(10);

        MCP2515::ERROR e2 = controller_.setBitrate(speed, clock);
        if (e2 != MCP2515::ERROR_OK)
        {
            error = e2;
        }
        delay(10);

        MCP2515::ERROR e3 = controller_.setNormalOneShotMode();
        if (e3 != MCP2515::ERROR_OK)
        {
            error = e3;
        }
        delay(10);

        return error;
    }

    void CanController::update(unsigned long dt_ms)
    {
        time_since_last_heartbeat_ms_ += dt_ms;
        time_since_last_ctre_enable_ms_ += dt_ms;
        time_since_last_send_ms_ += dt_ms;

        // Rate limiting
        if (time_since_last_send_ms_ < send_interval_ms_)
        {
            return;
        }

        // Handle Heartbeat (Priority 1)
        if (heartbeat_enabled_ && time_since_last_heartbeat_ms_ >= heartbeat_period_ms_)
        {
            // Try to send heartbeat immediately
            if (send_heartbeat())
            {
                time_since_last_heartbeat_ms_ = 0;
                time_since_last_send_ms_      = 0; // Reset send timer
                return;                            // Only one frame per update period if we hit the limit
            }
        }

        // Handle CTRE Global Enable (Priority 2)
        if (ctre_enable_active_ && time_since_last_ctre_enable_ms_ >= ctre_enable_period_ms_)
        {
            if (send_ctre_global_enable())
            {
                time_since_last_ctre_enable_ms_ = 0;
                time_since_last_send_ms_        = 0;
                return;
            }
        }

        // Process Queue (Priority 3)
        // If we didn't send a heartbeat or CTRE enable, try to send a queued message.
        if (!(!full_ && head_ == tail_)) // While not empty
        {
            struct can_frame& frame = queue_[tail_];
            MCP2515::ERROR    err   = controller_.sendMessage(&frame);

            if (err == MCP2515::ERROR_OK)
            {
                // Successfully sent
                tail_ = (tail_ + 1) % QUEUE_SIZE;
                full_ = false;

                time_since_last_send_ms_ = 0;
                return; // Done for this cycle
            }
            else
            {
                // Hardware buffers full or error
                // Retry next time.
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

                if (sender->send_periodic(controller_))
                {
                    time_since_last_send_ms_ = 0;
                    return;
                }
            }
        }
    }

    bool CanController::add_periodic_sender(PeriodicSender* sender)
    {
        if (periodic_count_ >= MAX_PERIODIC_SENDERS)
        {
            return false;
        }
        periodic_senders_[periodic_count_++] = sender;
        return true;
    }

    bool CanController::send_heartbeat()
    {
        can_frame      frame = heartbeat_to_canframe(heartbeat_state_);
        MCP2515::ERROR err   = controller_.sendMessage(&frame);
        return (err == MCP2515::ERROR_OK);
    }

    bool CanController::send_ctre_global_enable()
    {
        return TalonSrx::send_global_enable(controller_, ctre_enable_state_);
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

    void CanController::set_send_interval(unsigned long interval_ms)
    {
        send_interval_ms_ = interval_ms;
    }

    bool CanController::has_pending_frames() const
    {
        // Queue is empty if head == tail and not full
        return !(!full_ && head_ == tail_);
    }

} // namespace CanControl
