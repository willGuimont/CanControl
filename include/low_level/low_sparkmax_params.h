// AUTO-GENERATED FILE. DO NOT EDIT. See gen.py
#pragma once
#include <stdint.h>
#include "low_level/low_sparkmax.h"
#include <mcp2515.h>

namespace CanControl::LowLevel::SparkMax {

// Enum InputMode
enum class InputMode : uint32_t {
    INPUTMODE_PWM = 0,
    INPUTMODE_CAN = 1,
    INPUTMODE_USB = 2,
};

// Enum MotorType
enum class MotorType : uint32_t {
    MOTORTYPE_BRUSHED = 0,
    MOTORTYPE_BRUSHLESS = 1,
};

// Enum IdleMode
enum class IdleMode : uint32_t {
    IDLEMODE_COAST = 0,
    IDLEMODE_BRAKE = 1,
};

// Enum Sensor
enum class Sensor : uint32_t {
    SENSOR_NONE = 0,
    SENSOR_MAIN_ENCODER = 1,
    SENSOR_ANALOG = 2,
    SENSOR_ALT_ENCODER = 3,
    SENSOR_DUTY_CYCLE = 4,
};

// Enum ControlType
enum class ControlType : uint32_t {
    CONTROLTYPE_DUTY_CYCLE = 0,
    CONTROLTYPE_VELOCITY = 1,
    CONTROLTYPE_VOLTAGE = 2,
    CONTROLTYPE_POSITION = 3,
    CONTROLTYPE_SMARTMOTION = 4,
    CONTROLTYPE_SMARTVELOCITY = 5,
    CONTROLTYPE_MAXMOTION_POSITION = 6,
    CONTROLTYPE_MAXMOTION_VELOCITY = 7,
};

// Enum VoltageCompMode
enum class VoltageCompMode : uint32_t {
    VOLTAGECOMPMODE_NO_VOLTAGE_COMP = 0,
    VOLTAGECOMPMODE_CLOSED_LOOP_VOLTAGE_OUTPUT = 1,
    VOLTAGECOMPMODE_NOMINAL_VOLTAGE_COMP = 2,
};

// Enum AccelerationStrategy
enum class AccelerationStrategy : uint32_t {
    ACCELERATIONSTRATEGY_TRAPEZOIDAL = 0,
    ACCELERATIONSTRATEGY_SCURVE = 1,
};

// Enum AnalogMode
enum class AnalogMode : uint32_t {
    ANALOGMODE_ABSOLUTE = 0,
    ANALOGMODE_RELATIVE = 1,
};

// Enum CompatibilityPort
enum class CompatibilityPort : uint32_t {
    COMPATIBILITYPORT_DEFAULT = 0,
    COMPATIBILITYPORT_ALTERNATE_ENCODER = 1,
};

// Enum DutyCycleMode
enum class DutyCycleMode : uint32_t {
    DUTYCYCLEMODE_ABSOLUTE = 0,
    DUTYCYCLEMODE_RELATIVE = 1,
    DUTYCYCLEMODE_RELATIVE_STARTING_OFFSET = 2,
};

// Enum MAXMotionPositionMode
enum class MAXMotionPositionMode : uint32_t {
    MAXMOTIONPOSITIONMODE_TRAPEZOIDAL = 0,
};

// Generic parameter write helper
MCP2515::ERROR write_parameter_raw(const SparkCanDevice& dev, uint8_t parameter_id, uint32_t value);

// CAN ID (ID 0) -- CAN ID for this SPARK device
MCP2515::ERROR set_parameter_can_id(const SparkCanDevice& dev, uint32_t value);

// Input Mode (ID 1) -- Current input mode for this SPARK device
MCP2515::ERROR set_parameter_input_mode(const SparkCanDevice& dev, InputMode value);

// Motor Type (ID 2) -- The current Motor Type. Represented by the MotorType enum
MCP2515::ERROR set_parameter_motor_type(const SparkCanDevice& dev, MotorType value);

// Commutation Advance (ID 3) -- Advance Commutation by a given angle
MCP2515::ERROR set_parameter_commutation_advance(const SparkCanDevice& dev, float value);

// Control Type (ID 5) -- The currently active Control Type. Represented by the ControlType enum
MCP2515::ERROR set_parameter_control_type(const SparkCanDevice& dev, ControlType value);

// Idle Mode (ID 6) -- Whether to brake or coast when the setpoint is 0. Represented by the IdleMode enum
MCP2515::ERROR set_parameter_idle_mode(const SparkCanDevice& dev, IdleMode value);

// Input Deadband (ID 7) -- PWM input deadband
MCP2515::ERROR set_parameter_input_deadband(const SparkCanDevice& dev, float value);

// Closed Loop Control Sensor (ID 9) -- Sensor for PID operation
MCP2515::ERROR set_parameter_closed_loop_control_sensor(const SparkCanDevice& dev, Sensor value);

// Pole Pairs (ID 10) -- Number of pole pairs in the motor
MCP2515::ERROR set_parameter_pole_pairs(const SparkCanDevice& dev, uint32_t value);

// Current Chop (ID 11) -- Start current chopping when we reach this current level
MCP2515::ERROR set_parameter_current_chop(const SparkCanDevice& dev, float value);

// Current Chop Cycles (ID 12) -- Number of cycles before current chopping is triggered
MCP2515::ERROR set_parameter_current_chop_cycles(const SparkCanDevice& dev, uint32_t value);

// P 0 (ID 13) -- Proportional gain for PID controller (index 0)
MCP2515::ERROR set_parameter_p_0(const SparkCanDevice& dev, float value);

// I 0 (ID 14) -- Integral gain for PID controller (index 0)
MCP2515::ERROR set_parameter_i_0(const SparkCanDevice& dev, float value);

// D 0 (ID 15) -- Derivative gain for PID controller (index 0)
MCP2515::ERROR set_parameter_d_0(const SparkCanDevice& dev, float value);

// F 0 (ID 16) -- Feedforward gain for PID controller (index 0)
MCP2515::ERROR set_parameter_f_0(const SparkCanDevice& dev, float value);

// IZone 0 (ID 17) -- Integral zone for PID controller (index 0)
MCP2515::ERROR set_parameter_izone_0(const SparkCanDevice& dev, float value);

// D Filter 0 (ID 18) -- Derivative filter coefficient for PID controller (index 0)
MCP2515::ERROR set_parameter_d_filter_0(const SparkCanDevice& dev, float value);

// Output Min 0 (ID 19) -- Minimum output limit for PID controller (index 0)
MCP2515::ERROR set_parameter_output_min_0(const SparkCanDevice& dev, float value);

// Output Max 0 (ID 20) -- Maximum output limit for PID controller (index 0)
MCP2515::ERROR set_parameter_output_max_0(const SparkCanDevice& dev, float value);

// P 1 (ID 21) -- Proportional gain for PID controller (index 1)
MCP2515::ERROR set_parameter_p_1(const SparkCanDevice& dev, float value);

// I 1 (ID 22) -- Integral gain for PID controller (index 1)
MCP2515::ERROR set_parameter_i_1(const SparkCanDevice& dev, float value);

// D 1 (ID 23) -- Derivative gain for PID controller (index 1)
MCP2515::ERROR set_parameter_d_1(const SparkCanDevice& dev, float value);

// F 1 (ID 24) -- Feedforward gain for PID controller (index 1)
MCP2515::ERROR set_parameter_f_1(const SparkCanDevice& dev, float value);

// IZone 1 (ID 25) -- Integral zone for PID controller (index 1)
MCP2515::ERROR set_parameter_izone_1(const SparkCanDevice& dev, float value);

// D Filter 1 (ID 26) -- Derivative filter coefficient for PID controller (index 1)
MCP2515::ERROR set_parameter_d_filter_1(const SparkCanDevice& dev, float value);

// Output Min 1 (ID 27) -- Minimum output limit for PID controller (index 1)
MCP2515::ERROR set_parameter_output_min_1(const SparkCanDevice& dev, float value);

// Output Max 1 (ID 28) -- Maximum output limit for PID controller (index 1)
MCP2515::ERROR set_parameter_output_max_1(const SparkCanDevice& dev, float value);

// P 2 (ID 29) -- Proportional gain for PID controller (index 2)
MCP2515::ERROR set_parameter_p_2(const SparkCanDevice& dev, float value);

// I 2 (ID 30) -- Integral gain for PID controller (index 2)
MCP2515::ERROR set_parameter_i_2(const SparkCanDevice& dev, float value);

// D 2 (ID 31) -- Derivative gain for PID controller (index 2)
MCP2515::ERROR set_parameter_d_2(const SparkCanDevice& dev, float value);

// F 2 (ID 32) -- Feedforward gain for PID controller (index 2)
MCP2515::ERROR set_parameter_f_2(const SparkCanDevice& dev, float value);

// IZone 2 (ID 33) -- Integral zone for PID controller (index 2)
MCP2515::ERROR set_parameter_izone_2(const SparkCanDevice& dev, float value);

// D Filter 2 (ID 34) -- Derivative filter coefficient for PID controller (index 2)
MCP2515::ERROR set_parameter_d_filter_2(const SparkCanDevice& dev, float value);

// Output Min 2 (ID 35) -- Minimum output limit for PID controller (index 2)
MCP2515::ERROR set_parameter_output_min_2(const SparkCanDevice& dev, float value);

// Output Max 2 (ID 36) -- Maximum output limit for PID controller (index 2)
MCP2515::ERROR set_parameter_output_max_2(const SparkCanDevice& dev, float value);

// P 3 (ID 37) -- Proportional gain for PID controller (index 3)
MCP2515::ERROR set_parameter_p_3(const SparkCanDevice& dev, float value);

// I 3 (ID 38) -- Integral gain for PID controller (index 3)
MCP2515::ERROR set_parameter_i_3(const SparkCanDevice& dev, float value);

// D 3 (ID 39) -- Derivative gain for PID controller (index 3)
MCP2515::ERROR set_parameter_d_3(const SparkCanDevice& dev, float value);

// F 3 (ID 40) -- Feedforward gain for PID controller (index 3)
MCP2515::ERROR set_parameter_f_3(const SparkCanDevice& dev, float value);

// IZone 3 (ID 41) -- Integral zone for PID controller (index 3)
MCP2515::ERROR set_parameter_izone_3(const SparkCanDevice& dev, float value);

// D Filter 3 (ID 42) -- Derivative filter coefficient for PID controller (index 3)
MCP2515::ERROR set_parameter_d_filter_3(const SparkCanDevice& dev, float value);

// Output Min 3 (ID 43) -- Minimum output limit for PID controller (index 3)
MCP2515::ERROR set_parameter_output_min_3(const SparkCanDevice& dev, float value);

// Output Max 3 (ID 44) -- Maximum output limit for PID controller (index 3)
MCP2515::ERROR set_parameter_output_max_3(const SparkCanDevice& dev, float value);

// Inverted (ID 45) -- Whether to invert the motor
MCP2515::ERROR set_parameter_inverted(const SparkCanDevice& dev, bool value);

// Limit Switch Fwd Polarity (ID 50) -- Forward limit switch polarity setting
MCP2515::ERROR set_parameter_limit_switch_fwd_polarity(const SparkCanDevice& dev, bool value);

// Limit Switch Rev Polarity (ID 51) -- Reverse limit switch polarity setting
MCP2515::ERROR set_parameter_limit_switch_rev_polarity(const SparkCanDevice& dev, bool value);

// Hard Limit Fwd En (ID 52) -- Enable forward hard limit switch
MCP2515::ERROR set_parameter_hard_limit_fwd_en(const SparkCanDevice& dev, bool value);

// Hard Limit Rev En (ID 53) -- Enable reverse hard limit switch
MCP2515::ERROR set_parameter_hard_limit_rev_en(const SparkCanDevice& dev, bool value);

// Soft Limit Fwd En (ID 54) -- Enable forward soft limit
MCP2515::ERROR set_parameter_soft_limit_fwd_en(const SparkCanDevice& dev, bool value);

// Soft Limit Rev En (ID 55) -- Enable reverse soft limit
MCP2515::ERROR set_parameter_soft_limit_rev_en(const SparkCanDevice& dev, bool value);

// Open Loop Ramp Rate (ID 56) -- Ramp rate for open-loop control
MCP2515::ERROR set_parameter_open_loop_ramp_rate(const SparkCanDevice& dev, float value);

// Follower ID (ID 57) -- Legacy follower arbitration ID
MCP2515::ERROR set_parameter_follower_id(const SparkCanDevice& dev, uint32_t value);

// Follower Config (ID 58) -- Legacy follower configuration
MCP2515::ERROR set_parameter_follower_config(const SparkCanDevice& dev, uint32_t value);

// Smart Current Stall Limit (ID 59) -- Current limit for stall conditions in smart current mode
MCP2515::ERROR set_parameter_smart_current_stall_limit(const SparkCanDevice& dev, uint32_t value);

// Smart Current Free Limit (ID 60) -- Current limit for free running in smart current mode
MCP2515::ERROR set_parameter_smart_current_free_limit(const SparkCanDevice& dev, uint32_t value);

// Smart Current Config (ID 61) -- Configuration parameter for smart current mode
MCP2515::ERROR set_parameter_smart_current_config(const SparkCanDevice& dev, uint32_t value);

// Smart Current Reserved (ID 62) -- Reserved parameter for smart current mode
MCP2515::ERROR set_parameter_smart_current_reserved(const SparkCanDevice& dev, uint32_t value);

// Motor Kv (ID 63) -- Motor velocity constant (Kv)
MCP2515::ERROR set_parameter_motor_kv(const SparkCanDevice& dev, uint32_t value);

// Encoder Counts Per Rev (ID 69) -- Number of encoder counts per revolution
MCP2515::ERROR set_parameter_encoder_counts_per_rev(const SparkCanDevice& dev, uint32_t value);

// Encoder Average Depth (ID 70) -- Depth of encoder averaging filter
MCP2515::ERROR set_parameter_encoder_average_depth(const SparkCanDevice& dev, uint32_t value);

// Encoder Sample Delta (ID 71) -- Time delta between encoder samples
MCP2515::ERROR set_parameter_encoder_sample_delta(const SparkCanDevice& dev, uint32_t value);

// Encoder Inverted (ID 72) -- Invert encoder direction
MCP2515::ERROR set_parameter_encoder_inverted(const SparkCanDevice& dev, bool value);

// Voltage Compensation Mode (ID 74) -- How voltage compensation should be handled. Represented by the VoltageCompMode enum
MCP2515::ERROR set_parameter_voltage_compensation_mode(const SparkCanDevice& dev, VoltageCompMode value);

// Compensated Nominal Voltage (ID 75) -- Input Voltage to use for voltage compensation
MCP2515::ERROR set_parameter_compensated_nominal_voltage(const SparkCanDevice& dev, float value);

// SmartMotion Max Velocity 0 (ID 76) -- Max Velocity for Smart Motion slot 0
MCP2515::ERROR set_parameter_smartmotion_max_velocity_0(const SparkCanDevice& dev, float value);

// SmartMotion Max Accel 0 (ID 77) -- Max Acceleration for Smart Motion slot 0
MCP2515::ERROR set_parameter_smartmotion_max_accel_0(const SparkCanDevice& dev, float value);

// SmartMotion Min Vel Output 0 (ID 78) -- Min Velocity for Smart Motion slot 0
MCP2515::ERROR set_parameter_smartmotion_min_vel_output_0(const SparkCanDevice& dev, float value);

// SmartMotion Allowed Closed Loop Error 0 (ID 79) -- Allowed error in native units for Smart Motion slot 0
MCP2515::ERROR set_parameter_smartmotion_allowed_closed_loop_error_0(const SparkCanDevice& dev, float value);

// SmartMotion Accel Strategy 0 (ID 80) -- Acceleration Strategy for Smart Motion slot 0
MCP2515::ERROR set_parameter_smartmotion_accel_strategy_0(const SparkCanDevice& dev, AccelerationStrategy value);

// SmartMotion Max Velocity 1 (ID 81) -- Max Velocity for Smart Motion slot 1
MCP2515::ERROR set_parameter_smartmotion_max_velocity_1(const SparkCanDevice& dev, float value);

// SmartMotion Max Accel 1 (ID 82) -- Max Acceleration for Smart Motion slot 1
MCP2515::ERROR set_parameter_smartmotion_max_accel_1(const SparkCanDevice& dev, float value);

// SmartMotion Min Vel Output 1 (ID 83) -- Min Velocity for Smart Motion slot 1
MCP2515::ERROR set_parameter_smartmotion_min_vel_output_1(const SparkCanDevice& dev, float value);

// SmartMotion Allowed Closed Loop Error 1 (ID 84) -- Allowed error in native units for Smart Motion slot 1
MCP2515::ERROR set_parameter_smartmotion_allowed_closed_loop_error_1(const SparkCanDevice& dev, float value);

// SmartMotion Accel Strategy 1 (ID 85) -- Acceleration Strategy for Smart Motion slot 1
MCP2515::ERROR set_parameter_smartmotion_accel_strategy_1(const SparkCanDevice& dev, AccelerationStrategy value);

// SmartMotion Max Velocity 2 (ID 86) -- Max Velocity for Smart Motion slot 2
MCP2515::ERROR set_parameter_smartmotion_max_velocity_2(const SparkCanDevice& dev, float value);

// SmartMotion Max Accel 2 (ID 87) -- Max Acceleration for Smart Motion slot 2
MCP2515::ERROR set_parameter_smartmotion_max_accel_2(const SparkCanDevice& dev, float value);

// SmartMotion Min Vel Output 2 (ID 88) -- Minimum velocity output for smart motion slot 2
MCP2515::ERROR set_parameter_smartmotion_min_vel_output_2(const SparkCanDevice& dev, float value);

// SmartMotion Allowed Closed Loop Error 2 (ID 89) -- Allowed closed-loop error for smart motion slot 2
MCP2515::ERROR set_parameter_smartmotion_allowed_closed_loop_error_2(const SparkCanDevice& dev, float value);

// SmartMotion Accel Strategy 2 (ID 90) -- Acceleration strategy for smart motion slot 2
MCP2515::ERROR set_parameter_smartmotion_accel_strategy_2(const SparkCanDevice& dev, AccelerationStrategy value);

// SmartMotion Max Velocity 3 (ID 91) -- Maximum velocity for smart motion slot 3
MCP2515::ERROR set_parameter_smartmotion_max_velocity_3(const SparkCanDevice& dev, float value);

// SmartMotion Max Accel 3 (ID 92) -- Maximum acceleration for smart motion slot 3
MCP2515::ERROR set_parameter_smartmotion_max_accel_3(const SparkCanDevice& dev, float value);

// SmartMotion Min Vel Output 3 (ID 93) -- Minimum velocity output for smart motion slot 3
MCP2515::ERROR set_parameter_smartmotion_min_vel_output_3(const SparkCanDevice& dev, float value);

// SmartMotion Allowed Closed Loop Error 3 (ID 94) -- Allowed closed-loop error for smart motion slot 3
MCP2515::ERROR set_parameter_smartmotion_allowed_closed_loop_error_3(const SparkCanDevice& dev, float value);

// SmartMotion Accel Strategy 3 (ID 95) -- Acceleration strategy for smart motion slot 3
MCP2515::ERROR set_parameter_smartmotion_accel_strategy_3(const SparkCanDevice& dev, AccelerationStrategy value);

// I Max Accum 0 (ID 96) -- Maximum accumulator value for I control (slot 0)
MCP2515::ERROR set_parameter_i_max_accum_0(const SparkCanDevice& dev, float value);

// I Max Accum 1 (ID 100) -- Maximum accumulator value for I control (slot 1)
MCP2515::ERROR set_parameter_i_max_accum_1(const SparkCanDevice& dev, float value);

// I Max Accum 2 (ID 104) -- Maximum accumulator value for I control (slot 2)
MCP2515::ERROR set_parameter_i_max_accum_2(const SparkCanDevice& dev, float value);

// I Max Accum 3 (ID 108) -- Maximum accumulator value for I control (slot 3)
MCP2515::ERROR set_parameter_i_max_accum_3(const SparkCanDevice& dev, float value);

// Position Conversion Factor (ID 112) -- Factor to convert encoder counts or other position units to the desired position units.
MCP2515::ERROR set_parameter_position_conversion_factor(const SparkCanDevice& dev, float value);

// Velocity Conversion Factor (ID 113) -- Factor to convert encoder counts or other velocity units to the desired velocity units.
MCP2515::ERROR set_parameter_velocity_conversion_factor(const SparkCanDevice& dev, float value);

// Closed Loop Ramp Rate (ID 114) -- Ramp rate for closed-loop control, in DC per second
MCP2515::ERROR set_parameter_closed_loop_ramp_rate(const SparkCanDevice& dev, float value);

// Soft Limit Forward (ID 115) -- Forward soft limit value
MCP2515::ERROR set_parameter_soft_limit_forward(const SparkCanDevice& dev, float value);

// Soft Limit Reverse (ID 116) -- Reverse soft limit value
MCP2515::ERROR set_parameter_soft_limit_reverse(const SparkCanDevice& dev, float value);

// Analog Position Conversion (ID 119) -- Conversion factor for position from analog sensor. This value is multiplied by the voltage to give an output value
MCP2515::ERROR set_parameter_analog_position_conversion(const SparkCanDevice& dev, float value);

// Analog Velocity Conversion (ID 120) -- Conversion factor for velocity from analog sensor. This value is multiplied by the voltage to give an output value
MCP2515::ERROR set_parameter_analog_velocity_conversion(const SparkCanDevice& dev, float value);

// Analog Average Depth (ID 121) -- Number of samples to average for velocity data based on analog encoder input. This value can be between 1 and 64
MCP2515::ERROR set_parameter_analog_average_depth(const SparkCanDevice& dev, uint32_t value);

// Analog Sensor Mode (ID 122) -- Absolute: In this mode the sensor position is always read as voltage * conversion factor and reads the absolute position of the sensor. In this mode setPosition() does not have an effect.\n 1 Relative: In this mode the voltage difference is summed to calculate a relative position.
MCP2515::ERROR set_parameter_analog_sensor_mode(const SparkCanDevice& dev, AnalogMode value);

// Analog Inverted (ID 123) -- When inverted, the voltage is calculated as (ADC Full Scale - ADC Reading). This means that for absolute mode, the sensor value is 3.3V - voltage. In relative mode the direction is reversed.
MCP2515::ERROR set_parameter_analog_inverted(const SparkCanDevice& dev, bool value);

// Analog Sample Delta (ID 124) -- Delta time between samples for velocity measurement.
MCP2515::ERROR set_parameter_analog_sample_delta(const SparkCanDevice& dev, uint32_t value);

// Compatibility Port Config (ID 127) -- DEFAULT: Default configuration using limit switches.\n ALTERNATE_ENCODER: Alternate Encoder Mode - limit switches are disabled and alternate encoder is enabled. Represented by the CompatibilityPort enum
MCP2515::ERROR set_parameter_compatibility_port_config(const SparkCanDevice& dev, CompatibilityPort value);

// Alt Encoder Counts Per Rev (ID 128) -- Number of encoder counts in a single revolution, counting every edge on the A and B lines of a quadrature encoder. (Note: This is different than the CPR spec of the encoder which is 'Cycles per revolution'. This value is 4 * CPR.)
MCP2515::ERROR set_parameter_alt_encoder_counts_per_rev(const SparkCanDevice& dev, uint32_t value);

// Alt Encoder Average Depth (ID 129) -- Number of samples to average for velocity data based on quadrature encoder input. This value can be between 1 and 64.
MCP2515::ERROR set_parameter_alt_encoder_average_depth(const SparkCanDevice& dev, uint32_t value);

// Alt Encoder Sample Delta (ID 130) -- Delta time value for encoder velocity measurement in 500μs increments. The velocity calculation will take delta the current sample, and the sample x * 500μs behind, and divide by this the sample delta time.
MCP2515::ERROR set_parameter_alt_encoder_sample_delta(const SparkCanDevice& dev, uint32_t value);

// Alt Encoder Inverted (ID 131) -- Invert the phase of the encoder sensor. This is useful when the motor direction is opposite of the motor direction.
MCP2515::ERROR set_parameter_alt_encoder_inverted(const SparkCanDevice& dev, bool value);

// Alt Encoder Position Conversion (ID 132) -- Value multiplied by the native units (rotations) of the encoder for position.
MCP2515::ERROR set_parameter_alt_encoder_position_conversion(const SparkCanDevice& dev, float value);

// Alt Encoder Velocity Conversion (ID 133) -- Value multiplied by the native units (rotations) of the encoder for velocity.
MCP2515::ERROR set_parameter_alt_encoder_velocity_conversion(const SparkCanDevice& dev, float value);

// Uvw Sensor Sample Rate (ID 136) -- Sample period for UVW sensor
MCP2515::ERROR set_parameter_uvw_sensor_sample_rate(const SparkCanDevice& dev, float value);

// Uvw Sensor Average Depth (ID 137) -- Number of samples to average for velocity data based on UVW encoder input.
MCP2515::ERROR set_parameter_uvw_sensor_average_depth(const SparkCanDevice& dev, uint32_t value);

// Num Parameters (ID 138) -- Number of parameters in the table, including unused values in the middle of the table.
MCP2515::ERROR set_parameter_num_parameters(const SparkCanDevice& dev, uint32_t value);

// Duty Cycle Position Factor (ID 139) -- Value multiplied by the native units (rotations) of the encoder for position.
MCP2515::ERROR set_parameter_duty_cycle_position_factor(const SparkCanDevice& dev, float value);

// Duty Cycle Velocity Factor (ID 140) -- Value multiplied by the native units (rotations) of the encoder for velocity.
MCP2515::ERROR set_parameter_duty_cycle_velocity_factor(const SparkCanDevice& dev, float value);

// Duty Cycle Inverted (ID 141) -- Invert the phase of the duty cycle sensor. This is useful when the motor direction is opposite of the encoder direction
MCP2515::ERROR set_parameter_duty_cycle_inverted(const SparkCanDevice& dev, bool value);

// Duty Cycle Sensor Mode (ID 142) -- Mode for the duty cycle sensor. Represented by the DutyCycleMode enum
MCP2515::ERROR set_parameter_duty_cycle_sensor_mode(const SparkCanDevice& dev, DutyCycleMode value);

// Duty Cycle Average Depth (ID 143) -- Log base 2 of the number of samples to average for velocity data based on duty cycle encoder input
MCP2515::ERROR set_parameter_duty_cycle_average_depth(const SparkCanDevice& dev, uint32_t value);

// Duty Cycle Offset Legacy (ID 145) -- Legacy method of setting duty cycle offset. This parameter sets the offset after inversion is accounted for.
MCP2515::ERROR set_parameter_duty_cycle_offset_legacy(const SparkCanDevice& dev, float value);

// Position PID Wrap Enable (ID 149) -- Allow PID controller to wrap around
MCP2515::ERROR set_parameter_position_pid_wrap_enable(const SparkCanDevice& dev, bool value);

// Position PID Min Input (ID 150) -- Lower value for PID wrapping
MCP2515::ERROR set_parameter_position_pid_min_input(const SparkCanDevice& dev, float value);

// Position PID Max Input (ID 151) -- Upper value for PID wrapping
MCP2515::ERROR set_parameter_position_pid_max_input(const SparkCanDevice& dev, float value);

// Duty Cycle Zero Centered (ID 152) -- Center Duty Cycle readings at 0
MCP2515::ERROR set_parameter_duty_cycle_zero_centered(const SparkCanDevice& dev, bool value);

// Duty Cycle Sensor Prescaler (ID 153) -- The Duty Cycle Sensor will set its time base to the device clock divided by (value + 1). For Flex, the device clock is 170MHz, and for MAX, the device clock is 72MHz
MCP2515::ERROR set_parameter_duty_cycle_sensor_prescaler(const SparkCanDevice& dev, uint32_t value);

// Duty Cycle Offset (ID 154) -- Offset Duty Cycle encoder readings by a fixed value (0 to 1)
MCP2515::ERROR set_parameter_duty_cycle_offset(const SparkCanDevice& dev, float value);

// Product Id (ID 155) -- Read-only view of the REV Product Number of the device.
MCP2515::ERROR set_parameter_product_id(const SparkCanDevice& dev, uint32_t value);

// Device Major Version (ID 156) -- Major revision of the device
MCP2515::ERROR set_parameter_device_major_version(const SparkCanDevice& dev, uint32_t value);

// Device Minor Version (ID 157) -- Minor revision of the device
MCP2515::ERROR set_parameter_device_minor_version(const SparkCanDevice& dev, uint32_t value);

// Status 0 Period (ID 158) -- Status frame 0 period, in μs
MCP2515::ERROR set_parameter_status_0_period(const SparkCanDevice& dev, uint32_t value);

// Status 1 Period (ID 159) -- Status frame 1 period, in μs
MCP2515::ERROR set_parameter_status_1_period(const SparkCanDevice& dev, uint32_t value);

// Status 2 Period (ID 160) -- Status frame 2 period, in μs
MCP2515::ERROR set_parameter_status_2_period(const SparkCanDevice& dev, uint32_t value);

// Status 3 Period (ID 161) -- Status frame 3 period, in μs
MCP2515::ERROR set_parameter_status_3_period(const SparkCanDevice& dev, uint32_t value);

// Status 4 Period (ID 162) -- Status frame 4 period, in μs
MCP2515::ERROR set_parameter_status_4_period(const SparkCanDevice& dev, uint32_t value);

// Status 5 Period (ID 163) -- Status frame 5 period, in μs
MCP2515::ERROR set_parameter_status_5_period(const SparkCanDevice& dev, uint32_t value);

// Status 6 Period (ID 164) -- Status frame 6 period, in μs
MCP2515::ERROR set_parameter_status_6_period(const SparkCanDevice& dev, uint32_t value);

// Status 7 Period (ID 165) -- Status frame 7 period, in μs
MCP2515::ERROR set_parameter_status_7_period(const SparkCanDevice& dev, uint32_t value);

// MAXMotion Max Velocity 0 (ID 166) -- Maximum Velocity MAXMotion will reach in position mode for slot 0
MCP2515::ERROR set_parameter_maxmotion_max_velocity_0(const SparkCanDevice& dev, float value);

// MAXMotion Max Accel 0 (ID 167) -- Maximum Acceleration MAXMotion will reach in position mode or velocity mode for slot 0
MCP2515::ERROR set_parameter_maxmotion_max_accel_0(const SparkCanDevice& dev, float value);

// MAXMotion Max Jerk 0 (ID 168) -- Not currently implemented
MCP2515::ERROR set_parameter_maxmotion_max_jerk_0(const SparkCanDevice& dev, float value);

// MAXMotion Allowed Closed Loop Error 0 (ID 169) -- Maximum allowed closed loop error for slot 0
MCP2515::ERROR set_parameter_maxmotion_allowed_closed_loop_error_0(const SparkCanDevice& dev, float value);

// MAXMotion Position Mode 0 (ID 170) -- Position mode for slot 0. Represented by the MAXMotionPositionMode enum
MCP2515::ERROR set_parameter_maxmotion_position_mode_0(const SparkCanDevice& dev, MAXMotionPositionMode value);

// MAXMotion Max Velocity 1 (ID 171) -- Maximum Velocity MAXMotion will reach in position mode for slot 1
MCP2515::ERROR set_parameter_maxmotion_max_velocity_1(const SparkCanDevice& dev, float value);

// MAXMotion Max Accel 1 (ID 172) -- Maximum Acceleration MAXMotion will reach in position mode or velocity mode for slot 1
MCP2515::ERROR set_parameter_maxmotion_max_accel_1(const SparkCanDevice& dev, float value);

// MAXMotion Max Jerk 1 (ID 173) -- Not currently implemented
MCP2515::ERROR set_parameter_maxmotion_max_jerk_1(const SparkCanDevice& dev, float value);

// MAXMotion Allowed Closed Loop Error 1 (ID 174) -- Maximum allowed closed loop error for slot 1
MCP2515::ERROR set_parameter_maxmotion_allowed_closed_loop_error_1(const SparkCanDevice& dev, float value);

// MAXMotion Position Mode 1 (ID 175) -- Position mode for slot 1. Represented by the MAXMotionPositionMode enum
MCP2515::ERROR set_parameter_maxmotion_position_mode_1(const SparkCanDevice& dev, MAXMotionPositionMode value);

// MAXMotion Max Velocity 2 (ID 176) -- Maximum Velocity MAXMotion will reach in position mode for slot 2
MCP2515::ERROR set_parameter_maxmotion_max_velocity_2(const SparkCanDevice& dev, float value);

// MAXMotion Max Accel 2 (ID 177) -- Maximum Acceleration MAXMotion will reach in position mode or velocity mode for slot 2
MCP2515::ERROR set_parameter_maxmotion_max_accel_2(const SparkCanDevice& dev, float value);

// MAXMotion Max Jerk 2 (ID 178) -- Not currently implemented
MCP2515::ERROR set_parameter_maxmotion_max_jerk_2(const SparkCanDevice& dev, float value);

// MAXMotion Allowed Closed Loop Error 2 (ID 179) -- Maximum allowed closed loop error for slot 2
MCP2515::ERROR set_parameter_maxmotion_allowed_closed_loop_error_2(const SparkCanDevice& dev, float value);

// MAXMotion Position Mode 2 (ID 180) -- Position mode for slot 1. Represented by the MAXMotionPositionMode enum
MCP2515::ERROR set_parameter_maxmotion_position_mode_2(const SparkCanDevice& dev, MAXMotionPositionMode value);

// MAXMotion Max Velocity 3 (ID 181) -- Maximum Velocity MAXMotion will reach in position mode for slot 3
MCP2515::ERROR set_parameter_maxmotion_max_velocity_3(const SparkCanDevice& dev, float value);

// MAXMotion Max Accel 3 (ID 182) -- Maximum Acceleration MAXMotion will reach in position mode or velocity mode for slot 3
MCP2515::ERROR set_parameter_maxmotion_max_accel_3(const SparkCanDevice& dev, float value);

// MAXMotion Max Jerk 3 (ID 183) -- Not currently implemented
MCP2515::ERROR set_parameter_maxmotion_max_jerk_3(const SparkCanDevice& dev, float value);

// MAXMotion Allowed Closed Loop Error 3 (ID 184) -- Maximum allowed closed loop error for slot 3
MCP2515::ERROR set_parameter_maxmotion_allowed_closed_loop_error_3(const SparkCanDevice& dev, float value);

// MAXMotion Position Mode 3 (ID 185) -- Position mode for slot 3. Represented by the MAXMotionPositionMode enum
MCP2515::ERROR set_parameter_maxmotion_position_mode_3(const SparkCanDevice& dev, MAXMotionPositionMode value);

// Force Enable Status 0 (ID 186) -- Force Status Frame 0 to be enabled
MCP2515::ERROR set_parameter_force_enable_status_0(const SparkCanDevice& dev, bool value);

// Force Enable Status 1 (ID 187) -- Force Status Frame 1 to be enabled
MCP2515::ERROR set_parameter_force_enable_status_1(const SparkCanDevice& dev, bool value);

// Force Enable Status 2 (ID 188) -- Force Status Frame 2 to be enabled
MCP2515::ERROR set_parameter_force_enable_status_2(const SparkCanDevice& dev, bool value);

// Force Enable Status 3 (ID 189) -- Force Status Frame 3 to be enabled
MCP2515::ERROR set_parameter_force_enable_status_3(const SparkCanDevice& dev, bool value);

// Force Enable Status 4 (ID 190) -- Force Status Frame 4 to be enabled
MCP2515::ERROR set_parameter_force_enable_status_4(const SparkCanDevice& dev, bool value);

// Force Enable Status 5 (ID 191) -- Force Status Frame 5 to be enabled
MCP2515::ERROR set_parameter_force_enable_status_5(const SparkCanDevice& dev, bool value);

// Force Enable Status 6 (ID 192) -- Force Status Frame 6 to be enabled
MCP2515::ERROR set_parameter_force_enable_status_6(const SparkCanDevice& dev, bool value);

// Force Enable Status 7 (ID 193) -- Force Status Frame 7 to be enabled
MCP2515::ERROR set_parameter_force_enable_status_7(const SparkCanDevice& dev, bool value);

// Follower Mode Leader Id (ID 194) -- CAN ID of a SPARK device to follow
MCP2515::ERROR set_parameter_follower_mode_leader_id(const SparkCanDevice& dev, uint32_t value);

// Follower Mode Is Inverted (ID 195) -- Invert the setpoint when following. This is useful if this motor must spin opposite the leader
MCP2515::ERROR set_parameter_follower_mode_is_inverted(const SparkCanDevice& dev, bool value);

// Duty Cycle Encoder Start Pulse Us (ID 196) -- Tells this SPARK that the duty cycle sensor will always output a start (high) pulse of the given microseconds
MCP2515::ERROR set_parameter_duty_cycle_encoder_start_pulse_us(const SparkCanDevice& dev, float value);

// Duty Cycle Encoder End Pulse Us (ID 197) -- Tells this SPARK that the duty cycle sensor will always output an end (low) pulse of the given microseconds
MCP2515::ERROR set_parameter_duty_cycle_encoder_end_pulse_us(const SparkCanDevice& dev, float value);

// Param Table Version (ID 198) -- Hardware Client Parameter Table Version
MCP2515::ERROR set_parameter_param_table_version(const SparkCanDevice& dev, uint32_t value);

} // namespace CanControl::LowLevel::SparkMax

