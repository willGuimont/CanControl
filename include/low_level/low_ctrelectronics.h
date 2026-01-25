#pragma once

#include "low_level/low_level.h"

#include <stdint.h>
#include <string.h>

// Low-level helpers for building Talon SRX / Victor SPX CAN frames
// using the non-FRC firmware control scheme documented by CTRE.
//
// These functions work purely at the CAN-frame level: they take a
// logical device number and requested output, then build an internal
// basic_can_frame that can be converted to an mcp2515 can_frame via
// basic_to_can_frame(). The higher-level TalonSrx and
// VictorSpxw rappers own an MCP2515 instance and call these
// helpers for you.

namespace CanControl::LowLevel::TalonSrx
{
    using talon_can_frame = ::CanControl::LowLevel::basic_can_frame;

    // Base control-frame arbitration constant used for PercentOutput.
    // This matches the CONTROL value in CTRE's non-FRC Talon/Victor examples.
    static constexpr uint32_t TALON_CONTROL_ARBITRATION_ID = 0x040080u;

    // Device family base IDs (OR with CONTROL and device number).
    //  - TALON_SRX_BASE_ID  : Talon SRX
    //  - VICTOR_SPX_BASE_ID : Victor SPX
    static constexpr uint32_t TALON_SRX_BASE_ID  = 0x02040000u;
    static constexpr uint32_t VICTOR_SPX_BASE_ID = 0x01040000u;

    // Global enable/disable frame arbitration ID (29-bit extended ID).
    // ArbID is 0x401BF; first data byte is 0 (disable) or 1 (enable).
    static constexpr uint32_t CTRE_GLOBAL_ENABLE_ARB_ID = 0x000401BFu;

    // Build a Talon SRX PercentOutput control frame for the given device
    // number in the range [0, 62] and desired output in the range [-1, 1].
    talon_can_frame talon_build_percent_output(uint8_t device_number, float percent_output);

    // Build a Victor SPX PercentOutput control frame using the same
    // PercentOutput encoding as Talon SRX.
    talon_can_frame victor_build_percent_output(uint8_t device_number, float percent_output);

    // Build the global enable/disable frame used by CTRE motor controllers.
    // When enable == true, the first data byte is 1, otherwise 0.
    talon_can_frame build_global_enable(bool enable);
} // namespace CanControl::LowLevel::TalonSrx
