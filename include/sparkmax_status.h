#pragma once

#include <mcp2515.h>
#include <stdint.h>

namespace CanControl
{
    /** Compact cached values exposed by SparkMax's public getters.
     * Zero-initialize before use. received_mask bit N means a valid Status N arrived.
     * applied_output is the signed raw value; divide by 32767.0f for duty cycle.
     * For other telemetry fields, decode into a caller-owned generated Spark_STATUS_N_t.
     */
    struct SparkMaxStatus
    {
        uint16_t received_mask      = 0;
        int16_t  applied_output     = 0;
        float    position           = 0.0f;
        bool     hard_forward_limit = false;
        bool     hard_reverse_limit = false;
    };

    /// Updates only the fields belonging to a valid Status 0..9 frame for device_id.
    /// Returns false for unrelated or truncated frames and leaves status unchanged.
    bool update_sparkmax_status(SparkMaxStatus& status, uint8_t device_id, const can_frame& frame);
} // namespace CanControl
