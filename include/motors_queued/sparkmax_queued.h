#pragma once

#include "can_controller.h"
#include "motors/sparkmax.h"

namespace CanControl
{
    /**
     * @brief Queue-based wrapper for Spark Max motors.
     * Inherits from SparkMax logic but sends frames via the CanController queue
     * or stored periodic senders rather than immediate transmission.
     */
    class SparkMaxQueued : public SparkMax, public CanController::PeriodicSender
    {
      public:
        /**
         * @brief Construct a new Spark Max Queued object.
         *
         * @param controller Reference to the CanController.
         * @param device_id CAN ID of the motor (0-63).
         */
        SparkMaxQueued(CanController& controller, uint8_t device_id);

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
        MCP2515::ERROR dispatch_frame(const LowLevel::SparkMax::spark_can_frame& frame, bool periodic = false) override;

      private:
        CanController*             can_controller_;
        can_frame                  periodic_frame_;
        bool                       has_periodic_frame_ = false;
        unsigned long              last_update_ms_     = 0;
        static const unsigned long SAFETY_TIMEOUT_MS   = 100;
    };

} // namespace CanControl
