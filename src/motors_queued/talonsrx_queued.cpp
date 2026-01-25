#include "motors_queued/talonsrx_queued.h"

namespace CanControl
{
    TalonSrxQueued::TalonSrxQueued(CanController& controller, uint8_t device_id)
        : TalonSrx(controller.get_mcp(), device_id), can_controller_(&controller)
    {
        can_controller_->add_periodic_sender(this);
    }

    MCP2515::ERROR TalonSrxQueued::dispatch_frame(const can_frame& frame, bool periodic)
    {
        if (periodic)
        {
            // Update periodic frame
            periodic_frame_     = frame;
            has_periodic_frame_ = true;
            last_update_ms_     = millis();
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

    bool TalonSrxQueued::send_periodic(MCP2515& mcp)
    {
        if (!has_periodic_frame_)
            return false;

        // Check timeout
        if (millis() - last_update_ms_ > SAFETY_TIMEOUT_MS)
        {
            // Timeout: Stop sending
            return false;
        }

        return mcp.sendMessage(&periodic_frame_) == MCP2515::ERROR_OK;
    }

} // namespace CanControl
