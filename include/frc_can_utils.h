#include <can.h>
#include <frc_can.h>

inline can_frame to_can_frame(const CanControl::frc_can_frame &f)
{
    can_frame out{};
    out.can_id = f.id.raw;
    out.can_dlc = f.dlc;
    memcpy(out.data, f.data, f.dlc);
    return out;
}

inline CanControl::frc_can_frame from_can_frame(const can_frame &f)
{
    CanControl::frc_can_frame out{};
    out.id.raw = f.can_id & 0x1FFFFFFFu;
    out.dlc = f.can_dlc;
    memcpy(out.data, f.data, 8);
    return out;
}