#pragma once

#include "low_level/frc_can.h"

#include <can.h>

namespace CanControl
{
    // Convert an frc_can_frame (FRC/WPILib 29-bit ID layout) into a
    // raw mcp2515 can_frame suitable for transmission on the bus.
    inline can_frame to_can_frame(const CanControl::frc_can_frame& f)
    {
        can_frame out{};
        out.can_id  = f.id.raw;
        out.can_dlc = f.dlc > CLASSIC_CAN_MAX_DLC ? CLASSIC_CAN_MAX_DLC : f.dlc;
        memset(out.data, 0, sizeof(out.data));
        if (out.can_dlc > 0u)
        {
            memcpy(out.data, f.data, out.can_dlc);
        }
        return out;
    }

    // Convert a received mcp2515 can_frame into an frc_can_frame by
    // masking off valid FRC arbitration ID & flag bits and copying the payload.
    inline CanControl::frc_can_frame from_can_frame(const can_frame& f)
    {
        CanControl::frc_can_frame out{};
        out.id.raw = f.can_id & (CanControl::frc_can_id::MASK_frc_id | EFF_FLAG | RTR_FLAG | ERR_FLAG);
        out.dlc    = f.can_dlc > CLASSIC_CAN_MAX_DLC ? CLASSIC_CAN_MAX_DLC : f.can_dlc;
        memset(out.data, 0, sizeof(out.data));
        if (out.dlc > 0u)
        {
            memcpy(out.data, f.data, out.dlc);
        }
        return out;
    }
} // namespace CanControl
