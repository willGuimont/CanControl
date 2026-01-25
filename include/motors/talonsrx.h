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
    /**
     * @brief High-level wrapper around the low-level CTRE API.
     * The motor also needs to periodically receive the global frame (send once every 20ms with send_global_enable)
     */
    class TalonSrx
    {
      public:
        /**
         * @brief Construct a new Talon Srx object.
         *
         * @param controller Reference to the MCP2515 controller.
         * @param device_id CAN ID of the motor controller (0-63).
         */
        TalonSrx(MCP2515& controller, uint8_t device_id);
        virtual ~TalonSrx() = default;

        /**
         * @brief Set the Talon SRX/Victor SPX PercentOutput demand in the
         * range [-1, 1]. Values outside this range are clamped.
         *
         * @param percent_output Percentage output [-1, 1].
         * @return MCP2515::ERROR Status of the transmission.
         */
        MCP2515::ERROR set_percent_output(float percent_output);

        /**
         * @brief Send the CTRE global enable/disable frame.
         *
         * @param controller Reference to the MCP2515 controller.
         * @param enable True to enable, false to disable.
         * @return MCP2515::ERROR Status of the transmission.
         */
        static MCP2515::ERROR send_global_enable(MCP2515& controller, bool enable);

      protected:
        virtual MCP2515::ERROR dispatch_frame(const can_frame& frame, bool periodic = false);

      private:
        MCP2515* controller_;
        uint8_t  device_id_;
    };

} // namespace CanControl
