#pragma once

#include "heartbeat.h"
#include "low_level/low_ctrelectronics.h"
#include "low_level/low_sparkmax_params.h"
#include "sparkmax_status.h"

namespace CanControl
{
    namespace Commands
    {
        // Stateless commands: no motor objects, queues, heap allocation, or implicit heartbeats.
        // Direct sends return the MCP2515 result. The caller owns timing and retries.
        // build_* functions do not send; convert their results with to_can_frame() for a queue.
        using Frame = LowLevel::basic_can_frame;

        can_frame      to_can_frame(const Frame& frame);
        MCP2515::ERROR send(MCP2515& controller, const Frame& frame);
        MCP2515::ERROR send_ctre_global_enable(MCP2515& controller, bool enabled);

        namespace SparkMax
        {
            // Duty cycle is clamped to [-1, 1]. Defaults match the SparkMax class.
            Frame build_duty_cycle(uint8_t device_id, float duty, uint8_t pid_slot = 0,
                                   int16_t arbitrary_feedforward = 0, uint8_t arbitrary_feedforward_units = 1u);
            MCP2515::ERROR set_duty_cycle(MCP2515& controller, uint8_t device_id, float duty, uint8_t pid_slot = 0,
                                          int16_t arbitrary_feedforward = 0, uint8_t arbitrary_feedforward_units = 1u);
            Frame          build_position(uint8_t device_id, float position, uint8_t pid_slot = 0,
                                          int16_t arbitrary_feedforward = 0, uint8_t arbitrary_feedforward_units = 0u);
            MCP2515::ERROR set_position(MCP2515& controller, uint8_t device_id, float position, uint8_t pid_slot = 0,
                                        int16_t arbitrary_feedforward = 0, uint8_t arbitrary_feedforward_units = 0u);
            Frame          build_velocity(uint8_t device_id, float velocity, uint8_t pid_slot = 0,
                                          int16_t arbitrary_feedforward = 0, uint8_t arbitrary_feedforward_units = 0u);
            MCP2515::ERROR set_velocity(MCP2515& controller, uint8_t device_id, float velocity, uint8_t pid_slot = 0,
                                        int16_t arbitrary_feedforward = 0, uint8_t arbitrary_feedforward_units = 0u);
            Frame          build_reset_safe_parameters(uint8_t device_id);
            MCP2515::ERROR reset_safe_parameters(MCP2515& controller, uint8_t device_id);
            Frame          build_primary_encoder_position(uint8_t device_id, float position, uint8_t data_type = 3u);
            MCP2515::ERROR set_primary_encoder_position(MCP2515& controller, uint8_t device_id, float position,
                                                        uint8_t data_type = 3u);
            MCP2515::ERROR stop(MCP2515& controller, uint8_t device_id);

            // Raw parameter bits, or typed parameter values. Integer widths select the overload.
            Frame          build_parameter(uint8_t device_id, uint8_t parameter_id, uint32_t raw_value);
            MCP2515::ERROR set_parameter(MCP2515& controller, uint8_t device_id, uint8_t parameter_id, uint32_t value);
            MCP2515::ERROR set_parameter(MCP2515& controller, uint8_t device_id, uint8_t parameter_id, int32_t value);
            MCP2515::ERROR set_parameter(MCP2515& controller, uint8_t device_id, uint8_t parameter_id, float value);
            MCP2515::ERROR set_parameter(MCP2515& controller, uint8_t device_id, uint8_t parameter_id, bool value);

            // PID slots 0..3; invalid slots return ERROR_FAIL without sending.
            MCP2515::ERROR set_pid_p(MCP2515& controller, uint8_t device_id, float value, uint8_t slot = 0);
            MCP2515::ERROR set_pid_i(MCP2515& controller, uint8_t device_id, float value, uint8_t slot = 0);
            MCP2515::ERROR set_pid_d(MCP2515& controller, uint8_t device_id, float value, uint8_t slot = 0);
            MCP2515::ERROR set_pid_f(MCP2515& controller, uint8_t device_id, float value, uint8_t slot = 0);

        } // namespace SparkMax

        namespace TalonSrx
        {
            Frame          build_percent_output(uint8_t device_id, float output);
            MCP2515::ERROR set_percent_output(MCP2515& controller, uint8_t device_id, float output);
        } // namespace TalonSrx
        namespace VictorSpx
        {
            Frame          build_percent_output(uint8_t device_id, float output);
            MCP2515::ERROR set_percent_output(MCP2515& controller, uint8_t device_id, float output);
        } // namespace VictorSpx
    } // namespace Commands
} // namespace CanControl
