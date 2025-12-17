#pragma once

#include "low_level/low_ctrelectronics.h"

#include <mcp2515.h>
#include <stdint.h>

namespace CanControl
{
    // High-level convenience wrapper for Victor SPX using the
    // CTRE non-FRC PercentOutput framing (see low_ctrelectronics).
    class VictorSpxMotor
    {
      public:
        VictorSpxMotor(MCP2515& controller, uint8_t device_id);

        void     set_controller(MCP2515& controller);
        void     set_device_id(uint8_t device_id);
        MCP2515* controller() const;
        uint8_t  device_id() const;

        // Set the Victor SPX PercentOutput demand in the range
        // [-1, 1]. Values outside this range are clamped.
        MCP2515::ERROR set_percent_output(float percent_output);

        // Send the CTRE global enable/disable frame.
        MCP2515::ERROR send_global_enable(bool enable);

      private:
        MCP2515* controller_;
        uint8_t  device_id_;
    };
} // namespace CanControl
