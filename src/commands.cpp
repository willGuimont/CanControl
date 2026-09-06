#include "commands.h"

namespace CanControl
{
    namespace Commands
    {
        can_frame to_can_frame(const Frame& frame)
        {
            can_frame raw{};
            LowLevel::basic_to_can_frame(frame, &raw);
            return raw;
        }

        MCP2515::ERROR send(MCP2515& controller, const Frame& frame)
        {
            can_frame raw = to_can_frame(frame);
            return controller.sendMessage(&raw);
        }

        MCP2515::ERROR send_ctre_global_enable(MCP2515& controller, bool enabled)
        {
            return send(controller, LowLevel::TalonSrx::build_global_enable(enabled));
        }

        namespace SparkMax
        {
            using namespace LowLevel::SparkMax;
            Frame build_duty_cycle(uint8_t device_id, float duty, uint8_t pid_slot, int16_t arbitrary_feedforward,
                                   uint8_t arbitrary_feedforward_units)
            {
                // Clamp duty cycle to [-1, 1] like the example code.
                if (duty > 1.0f)
                    duty = 1.0f;
                if (duty < -1.0f)
                    duty = -1.0f;

                Spark_DUTY_CYCLE_SETPOINT_t frame{};
                frame.SETPOINT                    = duty;
                frame.ARBITRARY_FEEDFORWARD       = arbitrary_feedforward;
                frame.PID_SLOT                    = pid_slot;
                frame.ARBITRARY_FEEDFORWARD_UNITS = arbitrary_feedforward_units;
                return LowLevel::SparkMax::spark_build_DUTY_CYCLE_SETPOINT(device_id, &frame);
            }

            Frame build_position(uint8_t device_id, float position, uint8_t pid_slot, int16_t arbitrary_feedforward,
                                 uint8_t arbitrary_feedforward_units)
            {
                Spark_POSITION_SETPOINT_t frame{};
                frame.SETPOINT                    = position;
                frame.ARBITRARY_FEEDFORWARD       = arbitrary_feedforward;
                frame.PID_SLOT                    = pid_slot;
                frame.ARBITRARY_FEEDFORWARD_UNITS = arbitrary_feedforward_units;

                return LowLevel::SparkMax::spark_build_POSITION_SETPOINT(device_id, &frame);
            }

            Frame build_velocity(uint8_t device_id, float velocity, uint8_t pid_slot, int16_t arbitrary_feedforward,
                                 uint8_t arbitrary_feedforward_units)
            {
                Spark_VELOCITY_SETPOINT_t frame{};
                frame.SETPOINT                    = velocity;
                frame.ARBITRARY_FEEDFORWARD       = arbitrary_feedforward;
                frame.PID_SLOT                    = pid_slot;
                frame.ARBITRARY_FEEDFORWARD_UNITS = arbitrary_feedforward_units;

                return LowLevel::SparkMax::spark_build_VELOCITY_SETPOINT(device_id, &frame);
            }

            Frame build_reset_safe_parameters(uint8_t device_id)
            {
                Spark_RESET_SAFE_PARAMETERS_t frame{};
                frame.MAGIC_NUMBER = 36292u;
                return LowLevel::SparkMax::spark_build_RESET_SAFE_PARAMETERS(device_id, &frame);
            }

            Frame build_primary_encoder_position(uint8_t device_id, float position, uint8_t data_type)
            {
                LowLevel::SparkMax::Spark_SET_PRIMARY_ENCODER_POSITION_t frame{};
                frame.POSITION  = position;
                frame.DATA_TYPE = data_type;
                return LowLevel::SparkMax::spark_build_SET_PRIMARY_ENCODER_POSITION(device_id, &frame);
            }

            MCP2515::ERROR set_duty_cycle(MCP2515& controller, uint8_t device_id, float duty, uint8_t pid_slot,
                                          int16_t arbitrary_feedforward, uint8_t arbitrary_feedforward_units)
            {
                return send(controller, build_duty_cycle(device_id, duty, pid_slot, arbitrary_feedforward,
                                                         arbitrary_feedforward_units));
            }

            MCP2515::ERROR set_position(MCP2515& controller, uint8_t device_id, float position, uint8_t pid_slot,
                                        int16_t arbitrary_feedforward, uint8_t arbitrary_feedforward_units)
            {
                return send(controller, build_position(device_id, position, pid_slot, arbitrary_feedforward,
                                                       arbitrary_feedforward_units));
            }

            MCP2515::ERROR set_velocity(MCP2515& controller, uint8_t device_id, float velocity, uint8_t pid_slot,
                                        int16_t arbitrary_feedforward, uint8_t arbitrary_feedforward_units)
            {
                return send(controller, build_velocity(device_id, velocity, pid_slot, arbitrary_feedforward,
                                                       arbitrary_feedforward_units));
            }

            MCP2515::ERROR reset_safe_parameters(MCP2515& controller, uint8_t device_id)
            {
                return send(controller, build_reset_safe_parameters(device_id));
            }

            MCP2515::ERROR set_primary_encoder_position(MCP2515& controller, uint8_t device_id, float position,
                                                        uint8_t data_type)
            {
                return send(controller, build_primary_encoder_position(device_id, position, data_type));
            }

            MCP2515::ERROR stop(MCP2515& controller, uint8_t device_id)
            {
                return set_duty_cycle(controller, device_id, 0.0f);
            }

            Frame build_parameter(uint8_t device_id, uint8_t parameter_id, uint32_t raw_value)
            {
                return LowLevel::SparkMax::build_parameter_frame(device_id, parameter_id, raw_value);
            }

            MCP2515::ERROR set_parameter(MCP2515& controller, uint8_t device_id, uint8_t parameter_id, uint32_t value)
            {
                return send(controller, build_parameter(device_id, parameter_id, value));
            }
            MCP2515::ERROR set_parameter(MCP2515& controller, uint8_t device_id, uint8_t parameter_id, int32_t value)
            {
                return set_parameter(controller, device_id, parameter_id, static_cast<uint32_t>(value));
            }
            MCP2515::ERROR set_parameter(MCP2515& controller, uint8_t device_id, uint8_t parameter_id, float value)
            {
                uint32_t bits;
                static_assert(sizeof(bits) == sizeof(value), "Spark parameters require 32-bit float");
                memcpy(&bits, &value, sizeof(bits));
                return set_parameter(controller, device_id, parameter_id, bits);
            }
            MCP2515::ERROR set_parameter(MCP2515& controller, uint8_t device_id, uint8_t parameter_id, bool value)
            {
                return set_parameter(controller, device_id, parameter_id, uint32_t(value ? 1 : 0));
            }

            static MCP2515::ERROR set_pid(MCP2515& controller, uint8_t device_id, uint8_t base, float value,
                                          uint8_t slot)
            {
                if (slot > 3)
                    return MCP2515::ERROR_FAIL;
                return set_parameter(controller, device_id, base + slot * 8, value);
            }
            MCP2515::ERROR set_pid_p(MCP2515& controller, uint8_t device_id, float value, uint8_t slot)
            {
                return set_pid(controller, device_id, 13, value, slot);
            }
            MCP2515::ERROR set_pid_i(MCP2515& controller, uint8_t device_id, float value, uint8_t slot)
            {
                return set_pid(controller, device_id, 14, value, slot);
            }
            MCP2515::ERROR set_pid_d(MCP2515& controller, uint8_t device_id, float value, uint8_t slot)
            {
                return set_pid(controller, device_id, 15, value, slot);
            }
            MCP2515::ERROR set_pid_f(MCP2515& controller, uint8_t device_id, float value, uint8_t slot)
            {
                return set_pid(controller, device_id, 16, value, slot);
            }

        } // namespace SparkMax
        namespace TalonSrx
        {
            Frame build_percent_output(uint8_t device_id, float output)
            {
                return LowLevel::TalonSrx::talon_build_percent_output(device_id, output);
            }
            MCP2515::ERROR set_percent_output(MCP2515& controller, uint8_t device_id, float output)
            {
                return send(controller, build_percent_output(device_id, output));
            }
        } // namespace TalonSrx
        namespace VictorSpx
        {
            Frame build_percent_output(uint8_t device_id, float output)
            {
                return LowLevel::TalonSrx::victor_build_percent_output(device_id, output);
            }
            MCP2515::ERROR set_percent_output(MCP2515& controller, uint8_t device_id, float output)
            {
                return send(controller, build_percent_output(device_id, output));
            }
        } // namespace VictorSpx

    } // namespace Commands
} // namespace CanControl
