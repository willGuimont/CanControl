#pragma once

#include "low_level/low_ctrelectronics.h"

#include <mcp2515.h>
#include <stdint.h>

namespace CanControl
{
    // High-level convenience wrapper around the low-level Talon SRX
    // framing helpers. Similar in spirit to SparkMotor, this class
    // owns a device ID and an MCP2515 controller and exposes simple
    // methods for setting percent output and sending the global
    // enable/disable frame.
    class TalonSrxMotor
    {
      public:
        TalonSrxMotor(MCP2515& controller, uint8_t device_id);

        void     set_controller(MCP2515& controller);
        void     set_device_id(uint8_t device_id);
        MCP2515* controller() const;
        uint8_t  device_id() const;

        // Set the Talon SRX/Victor SPX PercentOutput demand in the
        // range [-1, 1]. Values outside this range are clamped.
        MCP2515::ERROR set_percent_output(float percent_output);

        // Send the CTRE global enable/disable frame.
        MCP2515::ERROR send_global_enable(bool enable);

      private:
        MCP2515* controller_;
        uint8_t  device_id_;
    };

} // namespace CanControl
