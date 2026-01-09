// AUTO-GENERATED FILE. DO NOT EDIT. See gen.py
#include "low_level/low_sparkmax_params.h"
#include <string.h>

namespace CanControl::LowLevel::SparkMax {

MCP2515::ERROR write_parameter_raw(const SparkCanDevice& dev, uint8_t parameter_id, uint32_t value) {
    Spark_PARAMETER_WRITE_t pw{};
    pw.PARAMETER_ID = parameter_id;
    pw.VALUE = value;
    return dev.send_parameter_write(pw);
}

MCP2515::ERROR set_parameter_can_id(const SparkCanDevice& dev, uint32_t value) {
    return write_parameter_raw(dev, 0, value);
}

MCP2515::ERROR set_parameter_input_mode(const SparkCanDevice& dev, InputMode value) {
    return write_parameter_raw(dev, 1, static_cast<uint32_t>(value));
}

MCP2515::ERROR set_parameter_motor_type(const SparkCanDevice& dev, MotorType value) {
    return write_parameter_raw(dev, 2, static_cast<uint32_t>(value));
}

MCP2515::ERROR set_parameter_commutation_advance(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 3, conv.u);
}

MCP2515::ERROR set_parameter_control_type(const SparkCanDevice& dev, ControlType value) {
    return write_parameter_raw(dev, 5, static_cast<uint32_t>(value));
}

MCP2515::ERROR set_parameter_idle_mode(const SparkCanDevice& dev, IdleMode value) {
    return write_parameter_raw(dev, 6, static_cast<uint32_t>(value));
}

MCP2515::ERROR set_parameter_input_deadband(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 7, conv.u);
}

MCP2515::ERROR set_parameter_closed_loop_control_sensor(const SparkCanDevice& dev, Sensor value) {
    return write_parameter_raw(dev, 9, static_cast<uint32_t>(value));
}

MCP2515::ERROR set_parameter_pole_pairs(const SparkCanDevice& dev, uint32_t value) {
    return write_parameter_raw(dev, 10, value);
}

MCP2515::ERROR set_parameter_current_chop(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 11, conv.u);
}

MCP2515::ERROR set_parameter_current_chop_cycles(const SparkCanDevice& dev, uint32_t value) {
    return write_parameter_raw(dev, 12, value);
}

MCP2515::ERROR set_parameter_p_0(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 13, conv.u);
}

MCP2515::ERROR set_parameter_i_0(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 14, conv.u);
}

MCP2515::ERROR set_parameter_d_0(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 15, conv.u);
}

MCP2515::ERROR set_parameter_f_0(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 16, conv.u);
}

MCP2515::ERROR set_parameter_izone_0(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 17, conv.u);
}

MCP2515::ERROR set_parameter_d_filter_0(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 18, conv.u);
}

MCP2515::ERROR set_parameter_output_min_0(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 19, conv.u);
}

MCP2515::ERROR set_parameter_output_max_0(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 20, conv.u);
}

MCP2515::ERROR set_parameter_p_1(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 21, conv.u);
}

MCP2515::ERROR set_parameter_i_1(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 22, conv.u);
}

MCP2515::ERROR set_parameter_d_1(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 23, conv.u);
}

MCP2515::ERROR set_parameter_f_1(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 24, conv.u);
}

MCP2515::ERROR set_parameter_izone_1(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 25, conv.u);
}

MCP2515::ERROR set_parameter_d_filter_1(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 26, conv.u);
}

MCP2515::ERROR set_parameter_output_min_1(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 27, conv.u);
}

MCP2515::ERROR set_parameter_output_max_1(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 28, conv.u);
}

MCP2515::ERROR set_parameter_p_2(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 29, conv.u);
}

MCP2515::ERROR set_parameter_i_2(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 30, conv.u);
}

MCP2515::ERROR set_parameter_d_2(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 31, conv.u);
}

MCP2515::ERROR set_parameter_f_2(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 32, conv.u);
}

MCP2515::ERROR set_parameter_izone_2(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 33, conv.u);
}

MCP2515::ERROR set_parameter_d_filter_2(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 34, conv.u);
}

MCP2515::ERROR set_parameter_output_min_2(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 35, conv.u);
}

MCP2515::ERROR set_parameter_output_max_2(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 36, conv.u);
}

MCP2515::ERROR set_parameter_p_3(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 37, conv.u);
}

MCP2515::ERROR set_parameter_i_3(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 38, conv.u);
}

MCP2515::ERROR set_parameter_d_3(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 39, conv.u);
}

MCP2515::ERROR set_parameter_f_3(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 40, conv.u);
}

MCP2515::ERROR set_parameter_izone_3(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 41, conv.u);
}

MCP2515::ERROR set_parameter_d_filter_3(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 42, conv.u);
}

MCP2515::ERROR set_parameter_output_min_3(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 43, conv.u);
}

MCP2515::ERROR set_parameter_output_max_3(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 44, conv.u);
}

MCP2515::ERROR set_parameter_inverted(const SparkCanDevice& dev, bool value) {
    return write_parameter_raw(dev, 45, value ? 1u : 0u);
}

MCP2515::ERROR set_parameter_limit_switch_fwd_polarity(const SparkCanDevice& dev, bool value) {
    return write_parameter_raw(dev, 50, value ? 1u : 0u);
}

MCP2515::ERROR set_parameter_limit_switch_rev_polarity(const SparkCanDevice& dev, bool value) {
    return write_parameter_raw(dev, 51, value ? 1u : 0u);
}

MCP2515::ERROR set_parameter_hard_limit_fwd_en(const SparkCanDevice& dev, bool value) {
    return write_parameter_raw(dev, 52, value ? 1u : 0u);
}

MCP2515::ERROR set_parameter_hard_limit_rev_en(const SparkCanDevice& dev, bool value) {
    return write_parameter_raw(dev, 53, value ? 1u : 0u);
}

MCP2515::ERROR set_parameter_soft_limit_fwd_en(const SparkCanDevice& dev, bool value) {
    return write_parameter_raw(dev, 54, value ? 1u : 0u);
}

MCP2515::ERROR set_parameter_soft_limit_rev_en(const SparkCanDevice& dev, bool value) {
    return write_parameter_raw(dev, 55, value ? 1u : 0u);
}

MCP2515::ERROR set_parameter_open_loop_ramp_rate(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 56, conv.u);
}

MCP2515::ERROR set_parameter_follower_id(const SparkCanDevice& dev, uint32_t value) {
    return write_parameter_raw(dev, 57, value);
}

MCP2515::ERROR set_parameter_follower_config(const SparkCanDevice& dev, uint32_t value) {
    return write_parameter_raw(dev, 58, value);
}

MCP2515::ERROR set_parameter_smart_current_stall_limit(const SparkCanDevice& dev, uint32_t value) {
    return write_parameter_raw(dev, 59, value);
}

MCP2515::ERROR set_parameter_smart_current_free_limit(const SparkCanDevice& dev, uint32_t value) {
    return write_parameter_raw(dev, 60, value);
}

MCP2515::ERROR set_parameter_smart_current_config(const SparkCanDevice& dev, uint32_t value) {
    return write_parameter_raw(dev, 61, value);
}

MCP2515::ERROR set_parameter_smart_current_reserved(const SparkCanDevice& dev, uint32_t value) {
    return write_parameter_raw(dev, 62, value);
}

MCP2515::ERROR set_parameter_motor_kv(const SparkCanDevice& dev, uint32_t value) {
    return write_parameter_raw(dev, 63, value);
}

MCP2515::ERROR set_parameter_encoder_counts_per_rev(const SparkCanDevice& dev, uint32_t value) {
    return write_parameter_raw(dev, 69, value);
}

MCP2515::ERROR set_parameter_encoder_average_depth(const SparkCanDevice& dev, uint32_t value) {
    return write_parameter_raw(dev, 70, value);
}

MCP2515::ERROR set_parameter_encoder_sample_delta(const SparkCanDevice& dev, uint32_t value) {
    return write_parameter_raw(dev, 71, value);
}

MCP2515::ERROR set_parameter_encoder_inverted(const SparkCanDevice& dev, bool value) {
    return write_parameter_raw(dev, 72, value ? 1u : 0u);
}

MCP2515::ERROR set_parameter_voltage_compensation_mode(const SparkCanDevice& dev, VoltageCompMode value) {
    return write_parameter_raw(dev, 74, static_cast<uint32_t>(value));
}

MCP2515::ERROR set_parameter_compensated_nominal_voltage(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 75, conv.u);
}

MCP2515::ERROR set_parameter_smartmotion_max_velocity_0(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 76, conv.u);
}

MCP2515::ERROR set_parameter_smartmotion_max_accel_0(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 77, conv.u);
}

MCP2515::ERROR set_parameter_smartmotion_min_vel_output_0(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 78, conv.u);
}

MCP2515::ERROR set_parameter_smartmotion_allowed_closed_loop_error_0(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 79, conv.u);
}

MCP2515::ERROR set_parameter_smartmotion_accel_strategy_0(const SparkCanDevice& dev, AccelerationStrategy value) {
    return write_parameter_raw(dev, 80, static_cast<uint32_t>(value));
}

MCP2515::ERROR set_parameter_smartmotion_max_velocity_1(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 81, conv.u);
}

MCP2515::ERROR set_parameter_smartmotion_max_accel_1(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 82, conv.u);
}

MCP2515::ERROR set_parameter_smartmotion_min_vel_output_1(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 83, conv.u);
}

MCP2515::ERROR set_parameter_smartmotion_allowed_closed_loop_error_1(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 84, conv.u);
}

MCP2515::ERROR set_parameter_smartmotion_accel_strategy_1(const SparkCanDevice& dev, AccelerationStrategy value) {
    return write_parameter_raw(dev, 85, static_cast<uint32_t>(value));
}

MCP2515::ERROR set_parameter_smartmotion_max_velocity_2(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 86, conv.u);
}

MCP2515::ERROR set_parameter_smartmotion_max_accel_2(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 87, conv.u);
}

MCP2515::ERROR set_parameter_smartmotion_min_vel_output_2(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 88, conv.u);
}

MCP2515::ERROR set_parameter_smartmotion_allowed_closed_loop_error_2(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 89, conv.u);
}

MCP2515::ERROR set_parameter_smartmotion_accel_strategy_2(const SparkCanDevice& dev, AccelerationStrategy value) {
    return write_parameter_raw(dev, 90, static_cast<uint32_t>(value));
}

MCP2515::ERROR set_parameter_smartmotion_max_velocity_3(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 91, conv.u);
}

MCP2515::ERROR set_parameter_smartmotion_max_accel_3(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 92, conv.u);
}

MCP2515::ERROR set_parameter_smartmotion_min_vel_output_3(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 93, conv.u);
}

MCP2515::ERROR set_parameter_smartmotion_allowed_closed_loop_error_3(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 94, conv.u);
}

MCP2515::ERROR set_parameter_smartmotion_accel_strategy_3(const SparkCanDevice& dev, AccelerationStrategy value) {
    return write_parameter_raw(dev, 95, static_cast<uint32_t>(value));
}

MCP2515::ERROR set_parameter_i_max_accum_0(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 96, conv.u);
}

MCP2515::ERROR set_parameter_i_max_accum_1(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 100, conv.u);
}

MCP2515::ERROR set_parameter_i_max_accum_2(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 104, conv.u);
}

MCP2515::ERROR set_parameter_i_max_accum_3(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 108, conv.u);
}

MCP2515::ERROR set_parameter_position_conversion_factor(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 112, conv.u);
}

MCP2515::ERROR set_parameter_velocity_conversion_factor(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 113, conv.u);
}

MCP2515::ERROR set_parameter_closed_loop_ramp_rate(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 114, conv.u);
}

MCP2515::ERROR set_parameter_soft_limit_forward(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 115, conv.u);
}

MCP2515::ERROR set_parameter_soft_limit_reverse(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 116, conv.u);
}

MCP2515::ERROR set_parameter_analog_position_conversion(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 119, conv.u);
}

MCP2515::ERROR set_parameter_analog_velocity_conversion(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 120, conv.u);
}

MCP2515::ERROR set_parameter_analog_average_depth(const SparkCanDevice& dev, uint32_t value) {
    return write_parameter_raw(dev, 121, value);
}

MCP2515::ERROR set_parameter_analog_sensor_mode(const SparkCanDevice& dev, AnalogMode value) {
    return write_parameter_raw(dev, 122, static_cast<uint32_t>(value));
}

MCP2515::ERROR set_parameter_analog_inverted(const SparkCanDevice& dev, bool value) {
    return write_parameter_raw(dev, 123, value ? 1u : 0u);
}

MCP2515::ERROR set_parameter_analog_sample_delta(const SparkCanDevice& dev, uint32_t value) {
    return write_parameter_raw(dev, 124, value);
}

MCP2515::ERROR set_parameter_compatibility_port_config(const SparkCanDevice& dev, CompatibilityPort value) {
    return write_parameter_raw(dev, 127, static_cast<uint32_t>(value));
}

MCP2515::ERROR set_parameter_alt_encoder_counts_per_rev(const SparkCanDevice& dev, uint32_t value) {
    return write_parameter_raw(dev, 128, value);
}

MCP2515::ERROR set_parameter_alt_encoder_average_depth(const SparkCanDevice& dev, uint32_t value) {
    return write_parameter_raw(dev, 129, value);
}

MCP2515::ERROR set_parameter_alt_encoder_sample_delta(const SparkCanDevice& dev, uint32_t value) {
    return write_parameter_raw(dev, 130, value);
}

MCP2515::ERROR set_parameter_alt_encoder_inverted(const SparkCanDevice& dev, bool value) {
    return write_parameter_raw(dev, 131, value ? 1u : 0u);
}

MCP2515::ERROR set_parameter_alt_encoder_position_conversion(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 132, conv.u);
}

MCP2515::ERROR set_parameter_alt_encoder_velocity_conversion(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 133, conv.u);
}

MCP2515::ERROR set_parameter_uvw_sensor_sample_rate(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 136, conv.u);
}

MCP2515::ERROR set_parameter_uvw_sensor_average_depth(const SparkCanDevice& dev, uint32_t value) {
    return write_parameter_raw(dev, 137, value);
}

MCP2515::ERROR set_parameter_num_parameters(const SparkCanDevice& dev, uint32_t value) {
    return write_parameter_raw(dev, 138, value);
}

MCP2515::ERROR set_parameter_duty_cycle_position_factor(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 139, conv.u);
}

MCP2515::ERROR set_parameter_duty_cycle_velocity_factor(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 140, conv.u);
}

MCP2515::ERROR set_parameter_duty_cycle_inverted(const SparkCanDevice& dev, bool value) {
    return write_parameter_raw(dev, 141, value ? 1u : 0u);
}

MCP2515::ERROR set_parameter_duty_cycle_sensor_mode(const SparkCanDevice& dev, DutyCycleMode value) {
    return write_parameter_raw(dev, 142, static_cast<uint32_t>(value));
}

MCP2515::ERROR set_parameter_duty_cycle_average_depth(const SparkCanDevice& dev, uint32_t value) {
    return write_parameter_raw(dev, 143, value);
}

MCP2515::ERROR set_parameter_duty_cycle_offset_legacy(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 145, conv.u);
}

MCP2515::ERROR set_parameter_position_pid_wrap_enable(const SparkCanDevice& dev, bool value) {
    return write_parameter_raw(dev, 149, value ? 1u : 0u);
}

MCP2515::ERROR set_parameter_position_pid_min_input(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 150, conv.u);
}

MCP2515::ERROR set_parameter_position_pid_max_input(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 151, conv.u);
}

MCP2515::ERROR set_parameter_duty_cycle_zero_centered(const SparkCanDevice& dev, bool value) {
    return write_parameter_raw(dev, 152, value ? 1u : 0u);
}

MCP2515::ERROR set_parameter_duty_cycle_sensor_prescaler(const SparkCanDevice& dev, uint32_t value) {
    return write_parameter_raw(dev, 153, value);
}

MCP2515::ERROR set_parameter_duty_cycle_offset(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 154, conv.u);
}

MCP2515::ERROR set_parameter_product_id(const SparkCanDevice& dev, uint32_t value) {
    return write_parameter_raw(dev, 155, value);
}

MCP2515::ERROR set_parameter_device_major_version(const SparkCanDevice& dev, uint32_t value) {
    return write_parameter_raw(dev, 156, value);
}

MCP2515::ERROR set_parameter_device_minor_version(const SparkCanDevice& dev, uint32_t value) {
    return write_parameter_raw(dev, 157, value);
}

MCP2515::ERROR set_parameter_status_0_period(const SparkCanDevice& dev, uint32_t value) {
    return write_parameter_raw(dev, 158, value);
}

MCP2515::ERROR set_parameter_status_1_period(const SparkCanDevice& dev, uint32_t value) {
    return write_parameter_raw(dev, 159, value);
}

MCP2515::ERROR set_parameter_status_2_period(const SparkCanDevice& dev, uint32_t value) {
    return write_parameter_raw(dev, 160, value);
}

MCP2515::ERROR set_parameter_status_3_period(const SparkCanDevice& dev, uint32_t value) {
    return write_parameter_raw(dev, 161, value);
}

MCP2515::ERROR set_parameter_status_4_period(const SparkCanDevice& dev, uint32_t value) {
    return write_parameter_raw(dev, 162, value);
}

MCP2515::ERROR set_parameter_status_5_period(const SparkCanDevice& dev, uint32_t value) {
    return write_parameter_raw(dev, 163, value);
}

MCP2515::ERROR set_parameter_status_6_period(const SparkCanDevice& dev, uint32_t value) {
    return write_parameter_raw(dev, 164, value);
}

MCP2515::ERROR set_parameter_status_7_period(const SparkCanDevice& dev, uint32_t value) {
    return write_parameter_raw(dev, 165, value);
}

MCP2515::ERROR set_parameter_maxmotion_max_velocity_0(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 166, conv.u);
}

MCP2515::ERROR set_parameter_maxmotion_max_accel_0(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 167, conv.u);
}

MCP2515::ERROR set_parameter_maxmotion_max_jerk_0(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 168, conv.u);
}

MCP2515::ERROR set_parameter_maxmotion_allowed_closed_loop_error_0(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 169, conv.u);
}

MCP2515::ERROR set_parameter_maxmotion_position_mode_0(const SparkCanDevice& dev, MAXMotionPositionMode value) {
    return write_parameter_raw(dev, 170, static_cast<uint32_t>(value));
}

MCP2515::ERROR set_parameter_maxmotion_max_velocity_1(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 171, conv.u);
}

MCP2515::ERROR set_parameter_maxmotion_max_accel_1(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 172, conv.u);
}

MCP2515::ERROR set_parameter_maxmotion_max_jerk_1(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 173, conv.u);
}

MCP2515::ERROR set_parameter_maxmotion_allowed_closed_loop_error_1(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 174, conv.u);
}

MCP2515::ERROR set_parameter_maxmotion_position_mode_1(const SparkCanDevice& dev, MAXMotionPositionMode value) {
    return write_parameter_raw(dev, 175, static_cast<uint32_t>(value));
}

MCP2515::ERROR set_parameter_maxmotion_max_velocity_2(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 176, conv.u);
}

MCP2515::ERROR set_parameter_maxmotion_max_accel_2(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 177, conv.u);
}

MCP2515::ERROR set_parameter_maxmotion_max_jerk_2(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 178, conv.u);
}

MCP2515::ERROR set_parameter_maxmotion_allowed_closed_loop_error_2(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 179, conv.u);
}

MCP2515::ERROR set_parameter_maxmotion_position_mode_2(const SparkCanDevice& dev, MAXMotionPositionMode value) {
    return write_parameter_raw(dev, 180, static_cast<uint32_t>(value));
}

MCP2515::ERROR set_parameter_maxmotion_max_velocity_3(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 181, conv.u);
}

MCP2515::ERROR set_parameter_maxmotion_max_accel_3(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 182, conv.u);
}

MCP2515::ERROR set_parameter_maxmotion_max_jerk_3(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 183, conv.u);
}

MCP2515::ERROR set_parameter_maxmotion_allowed_closed_loop_error_3(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 184, conv.u);
}

MCP2515::ERROR set_parameter_maxmotion_position_mode_3(const SparkCanDevice& dev, MAXMotionPositionMode value) {
    return write_parameter_raw(dev, 185, static_cast<uint32_t>(value));
}

MCP2515::ERROR set_parameter_force_enable_status_0(const SparkCanDevice& dev, bool value) {
    return write_parameter_raw(dev, 186, value ? 1u : 0u);
}

MCP2515::ERROR set_parameter_force_enable_status_1(const SparkCanDevice& dev, bool value) {
    return write_parameter_raw(dev, 187, value ? 1u : 0u);
}

MCP2515::ERROR set_parameter_force_enable_status_2(const SparkCanDevice& dev, bool value) {
    return write_parameter_raw(dev, 188, value ? 1u : 0u);
}

MCP2515::ERROR set_parameter_force_enable_status_3(const SparkCanDevice& dev, bool value) {
    return write_parameter_raw(dev, 189, value ? 1u : 0u);
}

MCP2515::ERROR set_parameter_force_enable_status_4(const SparkCanDevice& dev, bool value) {
    return write_parameter_raw(dev, 190, value ? 1u : 0u);
}

MCP2515::ERROR set_parameter_force_enable_status_5(const SparkCanDevice& dev, bool value) {
    return write_parameter_raw(dev, 191, value ? 1u : 0u);
}

MCP2515::ERROR set_parameter_force_enable_status_6(const SparkCanDevice& dev, bool value) {
    return write_parameter_raw(dev, 192, value ? 1u : 0u);
}

MCP2515::ERROR set_parameter_force_enable_status_7(const SparkCanDevice& dev, bool value) {
    return write_parameter_raw(dev, 193, value ? 1u : 0u);
}

MCP2515::ERROR set_parameter_follower_mode_leader_id(const SparkCanDevice& dev, uint32_t value) {
    return write_parameter_raw(dev, 194, value);
}

MCP2515::ERROR set_parameter_follower_mode_is_inverted(const SparkCanDevice& dev, bool value) {
    return write_parameter_raw(dev, 195, value ? 1u : 0u);
}

MCP2515::ERROR set_parameter_duty_cycle_encoder_start_pulse_us(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 196, conv.u);
}

MCP2515::ERROR set_parameter_duty_cycle_encoder_end_pulse_us(const SparkCanDevice& dev, float value) {
    union { float f; uint32_t u; } conv = { .f = value };
    return write_parameter_raw(dev, 197, conv.u);
}

MCP2515::ERROR set_parameter_param_table_version(const SparkCanDevice& dev, uint32_t value) {
    return write_parameter_raw(dev, 198, value);
}

} // namespace CanControl::LowLevel::SparkMax

