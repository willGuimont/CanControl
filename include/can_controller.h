#pragma once

#include "low_level/frc_can.h"
#include "low_level/low_ctrelectronics.h"

#include <mcp2515.h>
#include <stdint.h>

namespace CanControl
{
    /**
     * @brief High-level wrapper handling queuing of CAN frames and sending them
     * with proper flow control and heartbeat management.
     */
    class CanController
    {
      public:
        static constexpr size_t QUEUE_SIZE = 32;

        CanController(MCP2515& controller);

        /**
         * @return true If the frame was added successfully.
         * @return false If the queue is full.
         */
        bool queue_frame(const struct can_frame& frame);

        /**
         * @brief Setup the MCP2515.
         *
         * @param speed The CAN bus speed (e.g., CAN_1000KBPS).
         * @param clock The clock frequency (e.g., MCP_16MHZ).
         * @return MCP2515::ERROR Status of the initialization.
         */
        MCP2515::ERROR setup(CAN_SPEED speed, CAN_CLOCK clock);

        /**
         * @brief Handles sending queued frames, heartbeats, and periodic messages.
         *
         * @param dt_ms Delta time in milliseconds since the last call.
         */
        void update(unsigned long dt_ms);

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

        /**
         * @param period_ms Period in milliseconds.
         */
        void set_ctre_global_enable_period(unsigned long period_ms);

        /**
         * @return true If queue has frames.
         * @return false If queue is empty.
         */
        bool has_pending_frames() const;

        /**
         * @brief Set the minimum interval between sending frames (rate limiting).
         *
         * @param interval_ms Interval in milliseconds.
         */
        void set_send_interval(unsigned long interval_ms);

        MCP2515& get_mcp() const
        {
            return controller_;
        }

        /**
         * @brief Interface for devices that need to send a frame periodically
         * when the bus has spare capacity.
         */
        class PeriodicSender
        {
          public:
            /**
             * @param mcp Reference to the MCP2515 driver.
             * @return true If a frame was sent.
             * @return false If no frame was sent (e.g., timeout or nothing to send).
             */
            virtual bool send_periodic(MCP2515& mcp) = 0;
        };

        /**
         * @return true If added successfully.
         * @return false If the list is full.
         */
        bool add_periodic_sender(PeriodicSender* sender);

      private:
        MCP2515& controller_;

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

        bool send_heartbeat();

        // CTRE Global Enable configuration
        bool          ctre_enable_active_             = false; // Disabled by default
        bool          ctre_enable_state_              = true;  // The value to send (enable=true)
        unsigned long ctre_enable_period_ms_          = 20;    // Default 20ms
        unsigned long time_since_last_ctre_enable_ms_ = 0;

        bool send_ctre_global_enable();

        static constexpr size_t MAX_PERIODIC_SENDERS = 8;
        PeriodicSender*         periodic_senders_[MAX_PERIODIC_SENDERS];
        size_t                  periodic_count_ = 0;
        size_t                  periodic_index_ = 0;
    };

} // namespace CanControl
