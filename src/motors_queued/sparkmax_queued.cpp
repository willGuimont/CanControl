#include "motors_queued/sparkmax_queued.h"

namespace CanControl
{
    SparkMaxQueued::SparkMaxQueued(CanController& controller, uint8_t device_id)
        : SparkMax(controller.get_mcp(), device_id), can_controller_(&controller)
    {
        can_controller_->add_periodic_sender(this);
    }

    MCP2515::ERROR SparkMaxQueued::dispatch_frame(const LowLevel::SparkMax::spark_can_frame& frame, bool periodic)
    {
        struct can_frame out{};
        LowLevel::basic_to_can_frame(frame, &out);

        if (periodic)
        {
            periodic_frame_     = out;
            has_periodic_frame_ = true;
            last_update_ms_     = millis();
            return MCP2515::ERROR_OK;
        }

        if (can_controller_->queue_frame(out))
        {
            return MCP2515::ERROR_OK;
        }
        else
        {
            return MCP2515::ERROR_FAILTX;
        }
    }

    bool SparkMaxQueued::send_periodic(MCP2515& mcp)
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
