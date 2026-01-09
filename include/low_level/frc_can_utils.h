#pragma once

#include <can.h>

#include "low_level/frc_can.h"

namespace CanControl
{
    // Convert an frc_can_frame (FRC/WPILib 29-bit ID layout) into a
    // raw mcp2515 can_frame suitable for transmission on the bus.
    inline can_frame to_can_frame(const CanControl::frc_can_frame& f)
    {
        can_frame out{};
        out.can_id  = f.id.raw;
        out.can_dlc = f.dlc;
        memcpy(out.data, f.data, f.dlc);
        return out;
    }

    // Convert a received mcp2515 can_frame into an frc_can_frame by
    // masking off the FRC arbitration ID bits and copying the payload.
    inline CanControl::frc_can_frame from_can_frame(const can_frame& f)
    {
        CanControl::frc_can_frame out{};
        out.id.raw = f.can_id & CanControl::frc_can_id::MASK_frc_id;
        out.dlc    = f.can_dlc;
        memcpy(out.data, f.data, 8);
        return out;
    }
} // namespace CanControl
