#pragma once

#include "low_level/low_ctrelectronics.h"

#include <mcp2515.h>
#include <stdint.h>

namespace CanControl
{
    // High-level wrapper around the low-level CTRE API.
    // See
    // https://github.com/CrossTheRoadElec/Phoenix5-Examples/blob/master/HERO%20C%23/HERO%20Low%20Level%20Percent%20Output%20Example/Program.cs
    // The motor also needs to periodically receive the global frame (send once every 20ms with send_global_enable)
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
        static MCP2515::ERROR send_global_enable(MCP2515& controller, bool enable);

      private:
        MCP2515* controller_;
        uint8_t  device_id_;
    };

} // namespace CanControl
