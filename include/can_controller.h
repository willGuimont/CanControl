#pragma once

#include "low_level/frc_can.h"
#include "low_level/low_ctrelectronics.h"

#include <mcp2515.h>
#include <stdint.h>

#ifndef CANCONTROL_QUEUE_SIZE
#define CANCONTROL_QUEUE_SIZE 64
#endif

namespace CanControl
{
    /**
     * @brief High-level wrapper handling queuing of CAN frames and sending them
     * with proper flow control and heartbeat management.
     */
    class CanController
    {
      public:
        enum class Error : uint8_t
        {
            Ok,
            TransportFailure,
            TransmitBusy,
            InitializationFailed,
            TransmitFailed,
            NoMessage,
            QueueFull,
            InvalidArgument,
            SenderLimitReached,
            AlreadyRegistered,
            NotRegistered,
            Timeout,
        };

        static constexpr size_t QUEUE_SIZE = CANCONTROL_QUEUE_SIZE;
        static_assert(QUEUE_SIZE > 0, "CANCONTROL_QUEUE_SIZE must be greater than zero");

        class Transport
        {
          public:
            virtual ~Transport()                                                 = default;
            virtual MCP2515::ERROR reset()                                       = 0;
            virtual MCP2515::ERROR set_bitrate(CAN_SPEED speed, CAN_CLOCK clock) = 0;
            virtual MCP2515::ERROR set_normal_one_shot_mode()                    = 0;
            virtual MCP2515::ERROR send(const struct can_frame& frame)           = 0;
        };

        class Clock
        {
          public:
            virtual ~Clock()                                          = default;
            virtual unsigned long now_ms() const                      = 0;
            virtual void          delay_ms(unsigned long duration_ms) = 0;
        };

        CanController(MCP2515& controller);
        CanController(Transport& transport, Clock& clock);

        CanController(const CanController&)            = delete;
        CanController& operator=(const CanController&) = delete;

        /**
         * @return Error::Ok on acceptance, Error::QueueFull if the queue is full.
         */
        Error queue_frame(const struct can_frame& frame);

        /**
         * @brief Setup the MCP2515.
         *
         * @param speed The CAN bus speed (e.g., CAN_1000KBPS).
         * @param clock The clock frequency (e.g., MCP_16MHZ).
         * @return Error::Ok on success, otherwise the transport error.
         */
        Error setup(CAN_SPEED speed, CAN_CLOCK clock);

        /**
         * @brief Handles sending queued frames, heartbeats, and periodic messages.
         *
         * @param dt_ms Delta time in milliseconds since the last call.
         * @return Error::Ok if idle, rate limited, or sent; otherwise the transmission error.
         * Failed frames remain eligible for retry on a later update.
         */
        Error update(unsigned long dt_ms);

        void set_heartbeat(bool enabled);

        /**
         * @param period_ms Period in milliseconds.
         */
        void set_heartbeat_period(unsigned long period_ms);

        /**
         * @param state The state to broadcast (Enabled, Disabled, E-Stop, etc.).
         */
        void set_heartbeat_state(const heartbeat::RobotState& state);

        /**
         * @brief Required for Talon SRX and Victor SPX operation.
         *
         * @param enabled True to enable sending, false to disable.
         */
        void set_ctre_global_enable(bool enabled);

        void set_ctre_global_enable_period(unsigned long period_ms);

        /**
         * @brief Set the state to be sent in the CTRE global enable frame.
         *
         * @param state_enabled True to send "Enable", false to send "Disable".
         */
        void set_ctre_global_enable_state(bool state_enabled);

        /**
         * @return true If queue has frames.
         * @return false If queue is empty.
         */
        bool has_pending_frames() const;

        /**
         * @brief Blocks until all queued frames have been sent or the timeout expires.
         * Calls update() and delay() in a loop. Use during setup only.
         *
         * @param interval_ms Polling interval in milliseconds (default 10).
         * @param timeout_ms Maximum time to wait in milliseconds (default 5000).
         * @return Error::Ok if every queued frame was sent, Error::Timeout otherwise.
         * Transmission errors are retried until the timeout expires.
         */
        Error flush(unsigned long interval_ms = 10, unsigned long timeout_ms = 5000);

        /**
         * @brief Set the minimum interval between sending frames (rate limiting).
         *
         * @param interval_ms Interval in milliseconds.
         */
        void set_send_interval(unsigned long interval_ms);

        /**
         * @brief Interface for devices that need to send a frame periodically
         * when the bus has spare capacity.
         */
        class PeriodicSender
        {
          public:
            virtual ~PeriodicSender() = default;

            /**
             * @param frame Destination for the frame to send.
             * @param now_ms Current monotonic time.
             * @return true If a frame is ready to send.
             */
            virtual bool get_periodic_frame(struct can_frame& frame, unsigned long now_ms) = 0;
        };

        /**
         * @return Error::Ok, InvalidArgument (null), AlreadyRegistered, or SenderLimitReached.
         * The sender must unregister before destruction. Queued motor wrappers do this automatically.
         * This controller must outlive its queued motors.
         */
        Error add_periodic_sender(PeriodicSender* sender);
        /// Returns Error::Ok, InvalidArgument (null), or NotRegistered.
        Error remove_periodic_sender(PeriodicSender* sender);

        unsigned long now_ms() const;

      private:
        MCP2515*   controller_ = nullptr;
        Transport* transport_  = nullptr;
        Clock*     clock_      = nullptr;

        static Error   from_transport_error(MCP2515::ERROR error);
        MCP2515::ERROR reset_transport();
        MCP2515::ERROR set_bitrate(CAN_SPEED speed, CAN_CLOCK clock);
        MCP2515::ERROR set_normal_one_shot_mode();
        MCP2515::ERROR send_frame(const struct can_frame& frame);
        void           delay_ms(unsigned long duration_ms);

        // Circular buffer for queue
        struct can_frame queue_[QUEUE_SIZE];
        size_t           head_ = 0;
        size_t           tail_ = 0;
        bool             full_ = false;

        // Rate limiting
        unsigned long send_interval_ms_        = 5;
        unsigned long time_since_last_send_ms_ = 0;

        // Heartbeat configuration
        bool                  heartbeat_enabled_            = true;
        unsigned long         heartbeat_period_ms_          = 20;
        unsigned long         time_since_last_heartbeat_ms_ = 0;
        heartbeat::RobotState heartbeat_state_;

        Error send_heartbeat();

        // CTRE Global Enable configuration
        bool          ctre_enable_active_             = false; // Disabled by default
        bool          ctre_enable_state_              = true;  // The value to send (enable=true)
        unsigned long ctre_enable_period_ms_          = 20;    // Default 20ms
        unsigned long time_since_last_ctre_enable_ms_ = 0;

        Error send_ctre_global_enable();

        static constexpr size_t MAX_PERIODIC_SENDERS = 8;
        PeriodicSender*         periodic_senders_[MAX_PERIODIC_SENDERS];
        size_t                  periodic_count_ = 0;
        size_t                  periodic_index_ = 0;
    };

} // namespace CanControl
