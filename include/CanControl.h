#pragma once

#include "motors/sparkmax.h"
#include "motors/talonsrx.h"
#include "motors/victorspx.h"
#include "low_level/frc_can_utils.h"

namespace CanControl
{
    // Convenience helpers: send the FRC/WPILib heartbeat frame used to
    // enable/keep-alive CAN motor devices (Spark Max, Talon SRX, Victor SPX).

    // Send a heartbeat given a pre-built RobotState.
    inline MCP2515::ERROR send_heartbeat(MCP2515& controller, const heartbeat::RobotState& state)
    {
        auto frc = heartbeat::to_frc_can_frame(state);
        auto raw = to_can_frame(frc);
        return controller.sendMessage(&raw);
    }

    // Send a heartbeat from an existing frc_can_frame.
    inline MCP2515::ERROR send_heartbeat(MCP2515& controller, const frc_can_frame& frame)
    {
        auto raw = to_can_frame(frame);
        return controller.sendMessage(&raw);
    }

    // Return a raw `can_frame` ready for transmission for more advanced use.
    inline can_frame heartbeat_to_canframe(const heartbeat::RobotState& state)
    {
        return to_can_frame(heartbeat::to_frc_can_frame(state));
    }

    // Return a default zeroed heartbeat `can_frame` (all payload bytes zero).
    // Useful when a minimal/empty heartbeat is desired.
    inline can_frame default_heartbeat_frame()
    {
        return to_can_frame(heartbeat::to_frc_can_frame(heartbeat::RobotState{}));
    }

} // namespace CanControl
