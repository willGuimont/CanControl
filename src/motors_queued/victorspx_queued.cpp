#include "motors_queued/victorspx_queued.h"

namespace CanControl
{
    VictorSpxQueued::VictorSpxQueued(CanController& controller, uint8_t device_id)
        : VictorSpx(device_id), can_controller_(&controller)
    {
        registered_ = can_controller_->add_periodic_sender(this) == CanController::Error::Ok;
    }

    VictorSpxQueued::~VictorSpxQueued()
    {
        if (registered_)
            can_controller_->remove_periodic_sender(this);
    }

    MCP2515::ERROR VictorSpxQueued::dispatch_frame(const can_frame& frame, bool periodic)
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

        if (can_controller_->queue_frame(frame) == CanController::Error::Ok)
        {
            return MCP2515::ERROR_OK;
        }
        else
        {
            return MCP2515::ERROR_FAILTX;
        }
    }

    bool VictorSpxQueued::get_periodic_frame(can_frame& frame, unsigned long now_ms)
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
