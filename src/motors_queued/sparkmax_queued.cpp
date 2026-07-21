#include "motors_queued/sparkmax_queued.h"

namespace CanControl
{
    SparkMaxQueued::SparkMaxQueued(CanController& controller, uint8_t device_id)
        : SparkMax(device_id), can_controller_(&controller)
    {
        registered_ = can_controller_->add_periodic_sender(this);
    }

    SparkMaxQueued::~SparkMaxQueued()
    {
        if (registered_)
            can_controller_->remove_periodic_sender(this);
    }

    MCP2515::ERROR SparkMaxQueued::dispatch_frame(const LowLevel::SparkMax::spark_can_frame& frame, bool periodic)
    {
        struct can_frame out{};
        LowLevel::basic_to_can_frame(frame, &out);

        if (periodic)
        {
            if (!registered_)
                return MCP2515::ERROR_FAILINIT;
            periodic_frame_     = out;
            has_periodic_frame_ = true;
            last_update_ms_     = can_controller_->now_ms();
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

    bool SparkMaxQueued::get_periodic_frame(can_frame& frame, unsigned long now_ms)
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
