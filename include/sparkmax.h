#pragma once

#include "low_level/low_sparkmax.h"

#include <mcp2515.h>

namespace CanControl
{
    // High-level wrapper around the low-level SparkMax CAN API.
    class SparkMax
    {
      public:
        // Construct a motor wrapper bound to a specific MCP2515 controller
        // and Spark device ID.
        SparkMax(MCP2515& controller, uint8_t device_id);

        // Change the bound controller or device id after construction.
        void set_controller(MCP2515& controller);
        void set_device_id(uint8_t device_id);

        MCP2515* controller() const;
        uint8_t  device_id() const;

        // Set duty-cycle output in the range [-1, 1].
        MCP2515::ERROR set_duty_cycle(float duty, uint8_t pid_slot = 0, int16_t arbitrary_feedforward = 0,
                                      uint8_t arbitrary_feedforward_units = 1u);

        // Set position setpoint (units are whatever the Spark is configured for).
        MCP2515::ERROR set_position(float position, uint8_t pid_slot = 0, int16_t arbitrary_feedforward = 0,
                                    uint8_t arbitrary_feedforward_units = 0u);

        // Set velocity setpoint (units are whatever the Spark is configured for).
        MCP2515::ERROR set_velocity(float velocity, uint8_t pid_slot = 0, int16_t arbitrary_feedforward = 0,
                                    uint8_t arbitrary_feedforward_units = 0u);

        // Convenience helper to stop the motor (zero duty cycle).
        MCP2515::ERROR stop();

      private:
        CanControl::LowLevel::SparkMax::SparkCanDevice device_;
    };
} // namespace CanControl
