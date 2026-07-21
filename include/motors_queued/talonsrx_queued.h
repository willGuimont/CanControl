#pragma once

#include "can_controller.h"
#include "motors/talonsrx.h"

namespace CanControl
{
    /**
     * @brief Queue-based wrapper for Talon SRX motors.
     * Inherits from TalonSrx logic but sends frames via the CanController queue
     * or stored periodic senders rather than immediate transmission.
     */
    class TalonSrxQueued : public TalonSrx, public CanController::PeriodicSender
    {
      public:
        TalonSrxQueued(CanController& controller, uint8_t device_id);
        ~TalonSrxQueued() override;

        TalonSrxQueued(const TalonSrxQueued&)            = delete;
        TalonSrxQueued& operator=(const TalonSrxQueued&) = delete;

        /**
         * @brief Implementation of PeriodicSender interface.
         * Sends the most recent control frame if available.
         *
         * @param frame Destination for the current control frame.
         * @param now_ms Current monotonic time.
         * @return true If a non-expired control frame is available.
         */
        bool get_periodic_frame(can_frame& frame, unsigned long now_ms) override;

      protected:
        MCP2515::ERROR dispatch_frame(const can_frame& frame, bool periodic = false) override;

      private:
        CanController*             can_controller_;
        can_frame                  periodic_frame_;
        bool                       has_periodic_frame_ = false;
        bool                       registered_         = false;
        unsigned long              last_update_ms_     = 0;
        static const unsigned long SAFETY_TIMEOUT_MS   = 100;
    };

} // namespace CanControl
