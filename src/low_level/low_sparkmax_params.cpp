// AUTO-GENERATED FILE. DO NOT EDIT. See gen.py
#include "low_level/low_sparkmax_params.h"

#include <mcp2515.h>
#include <string.h>

namespace CanControl::LowLevel::SparkMax
{

    int write_parameter_raw(MCP2515& controller, uint8_t device_id, uint8_t parameter_id, uint32_t value)
    {
        Spark_PARAMETER_WRITE_t pw{};
        pw.PARAMETER_ID = parameter_id;
        pw.VALUE        = value;
        struct can_frame out{};
        ::CanControl::LowLevel::basic_to_can_frame(spark_build_PARAMETER_WRITE(device_id, &pw), &out);
        return (int)controller.sendMessage(&out);
    }

    int set_parameter(MCP2515& controller, uint8_t device_id, uint8_t param_id, float value)
    {
        union
        {
            float    f;
            uint32_t u;
        } conv = {.f = value};
        return write_parameter_raw(controller, device_id, param_id, conv.u);
    }

    int set_parameter(MCP2515& controller, uint8_t device_id, uint8_t param_id, uint32_t value)
    {
        return write_parameter_raw(controller, device_id, param_id, value);
    }

    int set_parameter(MCP2515& controller, uint8_t device_id, uint8_t param_id, int32_t value)
    {
        return write_parameter_raw(controller, device_id, param_id, (uint32_t)value);
    }

    int set_parameter(MCP2515& controller, uint8_t device_id, uint8_t param_id, bool value)
    {
        return write_parameter_raw(controller, device_id, param_id, value ? 1u : 0u);
    }

} // namespace CanControl::LowLevel::SparkMax
