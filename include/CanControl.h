#pragma once

#include "low_level/frc_can_utils.h"

// Re-export motors wrappers
#include "motors/sparkmax.h"
#include "motors/talonsrx.h"
#include "motors/victorspx.h"

namespace CanControl
{
    // Convenience helpers: send the FRC/WPILib heartbeat frame used to
    // enable/keep-alive CAN motor devices.

    /**
     * @brief Sends a heartbeat frame to the CAN bus using the provided RobotState.
     *
     * @param controller Reference to the MCP2515 controller.
     * @param state The RobotState object containing enablement flags.
     * @return MCP2515::ERROR Status of the CAN transmission.
     */
    inline MCP2515::ERROR send_heartbeat(MCP2515& controller, const heartbeat::RobotState& state)
    {
        auto frc = heartbeat::to_frc_can_frame(state);
        auto raw = to_can_frame(frc);
        return controller.sendMessage(&raw);
    }

    /**
     * @brief Sends a heartbeat frame from a pre-constructed FRC CAN frame.
     *
     * @param controller Reference to the MCP2515 controller.
     * @param frame The FRC CAN frame to send.
     * @return MCP2515::ERROR Status of the CAN transmission.
     */
    inline MCP2515::ERROR send_heartbeat(MCP2515& controller, const frc_can_frame& frame)
    {
        auto raw = to_can_frame(frame);
        return controller.sendMessage(&raw);
    }

    /**
     * @brief Converts a RobotState to a raw CAN frame for transmission.
     *
     * @param state The RobotState object.
     * @return can_frame The raw CAN frame.
     */
    inline can_frame heartbeat_to_canframe(const heartbeat::RobotState& state)
    {
        return to_can_frame(heartbeat::to_frc_can_frame(state));
    }

    /**
     * @brief Creates a default RobotState with Motors Enabled and System Watchdog valid.
     *
     * @return heartbeat::RobotState A default enabled state.
     */
    inline heartbeat::RobotState default_heartbeat()
    {
        return heartbeat::RobotState(120,   // matchTimeSeconds
                                     1,     // matchNumber
                                     0,     // replayNumber
                                     false, // redAlliance
                                     true,  // enabled           <- Must be true
                                     false, // autonomous
                                     false, // testMode
                                     true,  // systemWatchdog    <- Must be true
                                     0,     // tournamentType
                                     25,    // timeOfDay_yr
                                     1,     // timeOfDay_month
                                     1,     // timeOfDay_day
                                     12,    // timeOfDay_hr
                                     0,     // timeOfDay_min
                                     0      // timeOfDay_sec
        );
    }

} // namespace CanControl
