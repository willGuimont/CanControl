#include "motors_queued/talonsrx_queued.h"

namespace CanControl
{
    TalonSrxQueued::TalonSrxQueued(CanController& controller, uint8_t device_id)
        : TalonSrx(device_id), can_controller_(&controller)
    {
        registered_ = can_controller_->add_periodic_sender(this);
    }

    TalonSrxQueued::~TalonSrxQueued()
    {
        if (registered_)
            can_controller_->remove_periodic_sender(this);
    }

    MCP2515::ERROR TalonSrxQueued::dispatch_frame(const can_frame& frame, bool periodic)
    {
        if (periodic)
        {
            if (!registered_)
                return MCP2515::ERROR_FAILINIT;
            // Update periodic frame
            periodic_frame_     = frame;
            has_periodic_frame_ = true;
            last_update_ms_     = can_controller_->now_ms();
            return MCP2515::ERROR_OK;
        }

        if (can_controller_->queue_frame(frame))
        {
            return MCP2515::ERROR_OK;
        }
        else
        {
            return MCP2515::ERROR_FAILTX;
        }
    }

    bool TalonSrxQueued::get_periodic_frame(can_frame& frame, unsigned long now_ms)
    {
        if (!has_periodic_frame_)
            return false;

        // Check timeout
        if (now_ms - last_update_ms_ > SAFETY_TIMEOUT_MS)
        {
            // Timeout: Stop sending
            return false;
        }

        frame = periodic_frame_;
        return true;
    }

} // namespace CanControl
