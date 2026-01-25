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

        /**
         * @brief Implementation of PeriodicSender interface.
         * Sends the most recent control frame if available.
         *
         * @param mcp Reference to the MCP2515 driver.
         * @return true If a frame was sent.
         * @return false If no frame sent (timeout or empty).
         */
        bool send_periodic(MCP2515& mcp) override;

      protected:
        MCP2515::ERROR dispatch_frame(const can_frame& frame, bool periodic = false) override;

      private:
        CanController*             can_controller_;
        can_frame                  periodic_frame_;
        bool                       has_periodic_frame_ = false;
        unsigned long              last_update_ms_     = 0;
        static const unsigned long SAFETY_TIMEOUT_MS   = 100;
    };

} // namespace CanControl
