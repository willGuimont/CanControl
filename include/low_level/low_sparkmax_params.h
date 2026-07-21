// AUTO-GENERATED FILE. DO NOT EDIT. See gen.py
#pragma once
#include "low_level/low_sparkmax.h"

#include <stdint.h>

namespace CanControl::LowLevel::SparkMax
{

    // Enum InputMode
    enum class InputMode : uint32_t
    {
        INPUTMODE_PWM = 0,
        INPUTMODE_CAN = 1,
        INPUTMODE_USB = 2,
    };

    // Enum MotorType
    enum class MotorType : uint32_t
    {
        MOTORTYPE_BRUSHED   = 0,
        MOTORTYPE_BRUSHLESS = 1,
    };

    // Enum IdleMode
    enum class IdleMode : uint32_t
    {
        IDLEMODE_COAST = 0,
        IDLEMODE_BRAKE = 1,
    };

    // Enum Sensor
    enum class Sensor : uint32_t
    {
        SENSOR_NONE         = 0,
        SENSOR_MAIN_ENCODER = 1,
        SENSOR_ANALOG       = 2,
        SENSOR_ALT_ENCODER  = 3,
        SENSOR_DUTY_CYCLE   = 4,
    };

    // Enum ControlType
    enum class ControlType : uint32_t
    {
        CONTROLTYPE_DUTY_CYCLE         = 0,
        CONTROLTYPE_VELOCITY           = 1,
        CONTROLTYPE_VOLTAGE            = 2,
        CONTROLTYPE_POSITION           = 3,
        CONTROLTYPE_SMARTMOTION        = 4,
        CONTROLTYPE_SMARTVELOCITY      = 5,
        CONTROLTYPE_MAXMOTION_POSITION = 6,
        CONTROLTYPE_MAXMOTION_VELOCITY = 7,
    };

    // Enum VoltageCompMode
    enum class VoltageCompMode : uint32_t
    {
        VOLTAGECOMPMODE_NO_VOLTAGE_COMP            = 0,
        VOLTAGECOMPMODE_CLOSED_LOOP_VOLTAGE_OUTPUT = 1,
        VOLTAGECOMPMODE_NOMINAL_VOLTAGE_COMP       = 2,
    };

    // Enum AccelerationStrategy
    enum class AccelerationStrategy : uint32_t
    {
        ACCELERATIONSTRATEGY_TRAPEZOIDAL = 0,
        ACCELERATIONSTRATEGY_SCURVE      = 1,
    };

    // Enum AnalogMode
    enum class AnalogMode : uint32_t
    {
        ANALOGMODE_ABSOLUTE = 0,
        ANALOGMODE_RELATIVE = 1,
    };

    // Enum CompatibilityPort
    enum class CompatibilityPort : uint32_t
    {
        COMPATIBILITYPORT_DEFAULT           = 0,
        COMPATIBILITYPORT_ALTERNATE_ENCODER = 1,
    };

    // Enum DutyCycleMode
    enum class DutyCycleMode : uint32_t
    {
        DUTYCYCLEMODE_ABSOLUTE                 = 0,
        DUTYCYCLEMODE_RELATIVE                 = 1,
        DUTYCYCLEMODE_RELATIVE_STARTING_OFFSET = 2,
    };

    // Enum MAXMotionPositionMode
    enum class MAXMotionPositionMode : uint32_t
    {
        MAXMOTIONPOSITIONMODE_TRAPEZOIDAL = 0,
    };

    // Generic parameter write helper
    int write_parameter_raw(MCP2515& controller, uint8_t device_id, uint8_t parameter_id, uint32_t value);

    // Build a parameter frame without sending it
    spark_can_frame build_parameter_frame(uint8_t device_id, uint8_t parameter_id, uint32_t value);

    // Generic set_parameter overloads
    int set_parameter(MCP2515& controller, uint8_t device_id, uint8_t param_id, float value);
    int set_parameter(MCP2515& controller, uint8_t device_id, uint8_t param_id, uint32_t value);
    int set_parameter(MCP2515& controller, uint8_t device_id, uint8_t param_id, int32_t value);
    int set_parameter(MCP2515& controller, uint8_t device_id, uint8_t param_id, bool value);

    static constexpr uint8_t SPARK_PARAM_CAN_ID_UINT                                   = 0u;
    static constexpr uint8_t SPARK_PARAM_INPUT_MODE_UINT                               = 1u;
    static constexpr uint8_t SPARK_PARAM_MOTOR_TYPE_UINT                               = 2u;
    static constexpr uint8_t SPARK_PARAM_COMMUTATION_ADVANCE_FLOAT                     = 3u;
    static constexpr uint8_t SPARK_PARAM_CONTROL_TYPE_UINT                             = 5u;
    static constexpr uint8_t SPARK_PARAM_IDLE_MODE_UINT                                = 6u;
    static constexpr uint8_t SPARK_PARAM_INPUT_DEADBAND_FLOAT                          = 7u;
    static constexpr uint8_t SPARK_PARAM_CLOSED_LOOP_CONTROL_SENSOR_UINT               = 9u;
    static constexpr uint8_t SPARK_PARAM_POLE_PAIRS_UINT                               = 10u;
    static constexpr uint8_t SPARK_PARAM_CURRENT_CHOP_FLOAT                            = 11u;
    static constexpr uint8_t SPARK_PARAM_CURRENT_CHOP_CYCLES_UINT                      = 12u;
    static constexpr uint8_t SPARK_PARAM_P_0_FLOAT                                     = 13u;
    static constexpr uint8_t SPARK_PARAM_I_0_FLOAT                                     = 14u;
    static constexpr uint8_t SPARK_PARAM_D_0_FLOAT                                     = 15u;
    static constexpr uint8_t SPARK_PARAM_F_0_FLOAT                                     = 16u;
    static constexpr uint8_t SPARK_PARAM_IZONE_0_FLOAT                                 = 17u;
    static constexpr uint8_t SPARK_PARAM_D_FILTER_0_FLOAT                              = 18u;
    static constexpr uint8_t SPARK_PARAM_OUTPUT_MIN_0_FLOAT                            = 19u;
    static constexpr uint8_t SPARK_PARAM_OUTPUT_MAX_0_FLOAT                            = 20u;
    static constexpr uint8_t SPARK_PARAM_P_1_FLOAT                                     = 21u;
    static constexpr uint8_t SPARK_PARAM_I_1_FLOAT                                     = 22u;
    static constexpr uint8_t SPARK_PARAM_D_1_FLOAT                                     = 23u;
    static constexpr uint8_t SPARK_PARAM_F_1_FLOAT                                     = 24u;
    static constexpr uint8_t SPARK_PARAM_IZONE_1_FLOAT                                 = 25u;
    static constexpr uint8_t SPARK_PARAM_D_FILTER_1_FLOAT                              = 26u;
    static constexpr uint8_t SPARK_PARAM_OUTPUT_MIN_1_FLOAT                            = 27u;
    static constexpr uint8_t SPARK_PARAM_OUTPUT_MAX_1_FLOAT                            = 28u;
    static constexpr uint8_t SPARK_PARAM_P_2_FLOAT                                     = 29u;
    static constexpr uint8_t SPARK_PARAM_I_2_FLOAT                                     = 30u;
    static constexpr uint8_t SPARK_PARAM_D_2_FLOAT                                     = 31u;
    static constexpr uint8_t SPARK_PARAM_F_2_FLOAT                                     = 32u;
    static constexpr uint8_t SPARK_PARAM_IZONE_2_FLOAT                                 = 33u;
    static constexpr uint8_t SPARK_PARAM_D_FILTER_2_FLOAT                              = 34u;
    static constexpr uint8_t SPARK_PARAM_OUTPUT_MIN_2_FLOAT                            = 35u;
    static constexpr uint8_t SPARK_PARAM_OUTPUT_MAX_2_FLOAT                            = 36u;
    static constexpr uint8_t SPARK_PARAM_P_3_FLOAT                                     = 37u;
    static constexpr uint8_t SPARK_PARAM_I_3_FLOAT                                     = 38u;
    static constexpr uint8_t SPARK_PARAM_D_3_FLOAT                                     = 39u;
    static constexpr uint8_t SPARK_PARAM_F_3_FLOAT                                     = 40u;
    static constexpr uint8_t SPARK_PARAM_IZONE_3_FLOAT                                 = 41u;
    static constexpr uint8_t SPARK_PARAM_D_FILTER_3_FLOAT                              = 42u;
    static constexpr uint8_t SPARK_PARAM_OUTPUT_MIN_3_FLOAT                            = 43u;
    static constexpr uint8_t SPARK_PARAM_OUTPUT_MAX_3_FLOAT                            = 44u;
    static constexpr uint8_t SPARK_PARAM_INVERTED_BOOL                                 = 45u;
    static constexpr uint8_t SPARK_PARAM_LIMIT_SWITCH_FWD_POLARITY_BOOL                = 50u;
    static constexpr uint8_t SPARK_PARAM_LIMIT_SWITCH_REV_POLARITY_BOOL                = 51u;
    static constexpr uint8_t SPARK_PARAM_HARD_LIMIT_FWD_EN_BOOL                        = 52u;
    static constexpr uint8_t SPARK_PARAM_HARD_LIMIT_REV_EN_BOOL                        = 53u;
    static constexpr uint8_t SPARK_PARAM_SOFT_LIMIT_FWD_EN_BOOL                        = 54u;
    static constexpr uint8_t SPARK_PARAM_SOFT_LIMIT_REV_EN_BOOL                        = 55u;
    static constexpr uint8_t SPARK_PARAM_OPEN_LOOP_RAMP_RATE_FLOAT                     = 56u;
    static constexpr uint8_t SPARK_PARAM_FOLLOWER_ID_UINT                              = 57u;
    static constexpr uint8_t SPARK_PARAM_FOLLOWER_CONFIG_UINT                          = 58u;
    static constexpr uint8_t SPARK_PARAM_SMART_CURRENT_STALL_LIMIT_UINT                = 59u;
    static constexpr uint8_t SPARK_PARAM_SMART_CURRENT_FREE_LIMIT_UINT                 = 60u;
    static constexpr uint8_t SPARK_PARAM_SMART_CURRENT_CONFIG_UINT                     = 61u;
    static constexpr uint8_t SPARK_PARAM_SMART_CURRENT_RESERVED_UINT                   = 62u;
    static constexpr uint8_t SPARK_PARAM_MOTOR_KV_UINT                                 = 63u;
    static constexpr uint8_t SPARK_PARAM_ENCODER_COUNTS_PER_REV_UINT                   = 69u;
    static constexpr uint8_t SPARK_PARAM_ENCODER_AVERAGE_DEPTH_UINT                    = 70u;
    static constexpr uint8_t SPARK_PARAM_ENCODER_SAMPLE_DELTA_UINT                     = 71u;
    static constexpr uint8_t SPARK_PARAM_ENCODER_INVERTED_BOOL                         = 72u;
    static constexpr uint8_t SPARK_PARAM_VOLTAGE_COMPENSATION_MODE_UINT                = 74u;
    static constexpr uint8_t SPARK_PARAM_COMPENSATED_NOMINAL_VOLTAGE_FLOAT             = 75u;
    static constexpr uint8_t SPARK_PARAM_SMARTMOTION_MAX_VELOCITY_0_FLOAT              = 76u;
    static constexpr uint8_t SPARK_PARAM_SMARTMOTION_MAX_ACCEL_0_FLOAT                 = 77u;
    static constexpr uint8_t SPARK_PARAM_SMARTMOTION_MIN_VEL_OUTPUT_0_FLOAT            = 78u;
    static constexpr uint8_t SPARK_PARAM_SMARTMOTION_ALLOWED_CLOSED_LOOP_ERROR_0_FLOAT = 79u;
    static constexpr uint8_t SPARK_PARAM_SMARTMOTION_ACCEL_STRATEGY_0_UINT             = 80u;
    static constexpr uint8_t SPARK_PARAM_SMARTMOTION_MAX_VELOCITY_1_FLOAT              = 81u;
    static constexpr uint8_t SPARK_PARAM_SMARTMOTION_MAX_ACCEL_1_FLOAT                 = 82u;
    static constexpr uint8_t SPARK_PARAM_SMARTMOTION_MIN_VEL_OUTPUT_1_FLOAT            = 83u;
    static constexpr uint8_t SPARK_PARAM_SMARTMOTION_ALLOWED_CLOSED_LOOP_ERROR_1_FLOAT = 84u;
    static constexpr uint8_t SPARK_PARAM_SMARTMOTION_ACCEL_STRATEGY_1_UINT             = 85u;
    static constexpr uint8_t SPARK_PARAM_SMARTMOTION_MAX_VELOCITY_2_FLOAT              = 86u;
    static constexpr uint8_t SPARK_PARAM_SMARTMOTION_MAX_ACCEL_2_FLOAT                 = 87u;
    static constexpr uint8_t SPARK_PARAM_SMARTMOTION_MIN_VEL_OUTPUT_2_FLOAT            = 88u;
    static constexpr uint8_t SPARK_PARAM_SMARTMOTION_ALLOWED_CLOSED_LOOP_ERROR_2_FLOAT = 89u;
    static constexpr uint8_t SPARK_PARAM_SMARTMOTION_ACCEL_STRATEGY_2_UINT             = 90u;
    static constexpr uint8_t SPARK_PARAM_SMARTMOTION_MAX_VELOCITY_3_FLOAT              = 91u;
    static constexpr uint8_t SPARK_PARAM_SMARTMOTION_MAX_ACCEL_3_FLOAT                 = 92u;
    static constexpr uint8_t SPARK_PARAM_SMARTMOTION_MIN_VEL_OUTPUT_3_FLOAT            = 93u;
    static constexpr uint8_t SPARK_PARAM_SMARTMOTION_ALLOWED_CLOSED_LOOP_ERROR_3_FLOAT = 94u;
    static constexpr uint8_t SPARK_PARAM_SMARTMOTION_ACCEL_STRATEGY_3_UINT             = 95u;
    static constexpr uint8_t SPARK_PARAM_I_MAX_ACCUM_0_FLOAT                           = 96u;
    static constexpr uint8_t SPARK_PARAM_I_MAX_ACCUM_1_FLOAT                           = 100u;
    static constexpr uint8_t SPARK_PARAM_I_MAX_ACCUM_2_FLOAT                           = 104u;
    static constexpr uint8_t SPARK_PARAM_I_MAX_ACCUM_3_FLOAT                           = 108u;
    static constexpr uint8_t SPARK_PARAM_POSITION_CONVERSION_FACTOR_FLOAT              = 112u;
    static constexpr uint8_t SPARK_PARAM_VELOCITY_CONVERSION_FACTOR_FLOAT              = 113u;
    static constexpr uint8_t SPARK_PARAM_CLOSED_LOOP_RAMP_RATE_FLOAT                   = 114u;
    static constexpr uint8_t SPARK_PARAM_SOFT_LIMIT_FORWARD_FLOAT                      = 115u;
    static constexpr uint8_t SPARK_PARAM_SOFT_LIMIT_REVERSE_FLOAT                      = 116u;
    static constexpr uint8_t SPARK_PARAM_ANALOG_POSITION_CONVERSION_FLOAT              = 119u;
    static constexpr uint8_t SPARK_PARAM_ANALOG_VELOCITY_CONVERSION_FLOAT              = 120u;
    static constexpr uint8_t SPARK_PARAM_ANALOG_AVERAGE_DEPTH_UINT                     = 121u;
    static constexpr uint8_t SPARK_PARAM_ANALOG_SENSOR_MODE_UINT                       = 122u;
    static constexpr uint8_t SPARK_PARAM_ANALOG_INVERTED_BOOL                          = 123u;
    static constexpr uint8_t SPARK_PARAM_ANALOG_SAMPLE_DELTA_UINT                      = 124u;
    static constexpr uint8_t SPARK_PARAM_COMPATIBILITY_PORT_CONFIG_UINT                = 127u;
    static constexpr uint8_t SPARK_PARAM_ALT_ENCODER_COUNTS_PER_REV_UINT               = 128u;
    static constexpr uint8_t SPARK_PARAM_ALT_ENCODER_AVERAGE_DEPTH_UINT                = 129u;
    static constexpr uint8_t SPARK_PARAM_ALT_ENCODER_SAMPLE_DELTA_UINT                 = 130u;
    static constexpr uint8_t SPARK_PARAM_ALT_ENCODER_INVERTED_BOOL                     = 131u;
    static constexpr uint8_t SPARK_PARAM_ALT_ENCODER_POSITION_CONVERSION_FLOAT         = 132u;
    static constexpr uint8_t SPARK_PARAM_ALT_ENCODER_VELOCITY_CONVERSION_FLOAT         = 133u;
    static constexpr uint8_t SPARK_PARAM_UVW_SENSOR_SAMPLE_RATE_FLOAT                  = 136u;
    static constexpr uint8_t SPARK_PARAM_UVW_SENSOR_AVERAGE_DEPTH_UINT                 = 137u;
    static constexpr uint8_t SPARK_PARAM_NUM_PARAMETERS_UINT                           = 138u;
    static constexpr uint8_t SPARK_PARAM_DUTY_CYCLE_POSITION_FACTOR_FLOAT              = 139u;
    static constexpr uint8_t SPARK_PARAM_DUTY_CYCLE_VELOCITY_FACTOR_FLOAT              = 140u;
    static constexpr uint8_t SPARK_PARAM_DUTY_CYCLE_INVERTED_BOOL                      = 141u;
    static constexpr uint8_t SPARK_PARAM_DUTY_CYCLE_SENSOR_MODE_UINT                   = 142u;
    static constexpr uint8_t SPARK_PARAM_DUTY_CYCLE_AVERAGE_DEPTH_UINT                 = 143u;
    static constexpr uint8_t SPARK_PARAM_DUTY_CYCLE_OFFSET_LEGACY_FLOAT                = 145u;
    static constexpr uint8_t SPARK_PARAM_POSITION_PID_WRAP_ENABLE_BOOL                 = 149u;
    static constexpr uint8_t SPARK_PARAM_POSITION_PID_MIN_INPUT_FLOAT                  = 150u;
    static constexpr uint8_t SPARK_PARAM_POSITION_PID_MAX_INPUT_FLOAT                  = 151u;
    static constexpr uint8_t SPARK_PARAM_DUTY_CYCLE_ZERO_CENTERED_BOOL                 = 152u;
    static constexpr uint8_t SPARK_PARAM_DUTY_CYCLE_SENSOR_PRESCALER_UINT              = 153u;
    static constexpr uint8_t SPARK_PARAM_DUTY_CYCLE_OFFSET_FLOAT                       = 154u;
    static constexpr uint8_t SPARK_PARAM_PRODUCT_ID_UINT                               = 155u;
    static constexpr uint8_t SPARK_PARAM_DEVICE_MAJOR_VERSION_UINT                     = 156u;
    static constexpr uint8_t SPARK_PARAM_DEVICE_MINOR_VERSION_UINT                     = 157u;
    static constexpr uint8_t SPARK_PARAM_STATUS_0_PERIOD_UINT                          = 158u;
    static constexpr uint8_t SPARK_PARAM_STATUS_1_PERIOD_UINT                          = 159u;
    static constexpr uint8_t SPARK_PARAM_STATUS_2_PERIOD_UINT                          = 160u;
    static constexpr uint8_t SPARK_PARAM_STATUS_3_PERIOD_UINT                          = 161u;
    static constexpr uint8_t SPARK_PARAM_STATUS_4_PERIOD_UINT                          = 162u;
    static constexpr uint8_t SPARK_PARAM_STATUS_5_PERIOD_UINT                          = 163u;
    static constexpr uint8_t SPARK_PARAM_STATUS_6_PERIOD_UINT                          = 164u;
    static constexpr uint8_t SPARK_PARAM_STATUS_7_PERIOD_UINT                          = 165u;
    static constexpr uint8_t SPARK_PARAM_MAXMOTION_MAX_VELOCITY_0_FLOAT                = 166u;
    static constexpr uint8_t SPARK_PARAM_MAXMOTION_MAX_ACCEL_0_FLOAT                   = 167u;
    static constexpr uint8_t SPARK_PARAM_MAXMOTION_MAX_JERK_0_FLOAT                    = 168u;
    static constexpr uint8_t SPARK_PARAM_MAXMOTION_ALLOWED_CLOSED_LOOP_ERROR_0_FLOAT   = 169u;
    static constexpr uint8_t SPARK_PARAM_MAXMOTION_POSITION_MODE_0_UINT                = 170u;
    static constexpr uint8_t SPARK_PARAM_MAXMOTION_MAX_VELOCITY_1_FLOAT                = 171u;
    static constexpr uint8_t SPARK_PARAM_MAXMOTION_MAX_ACCEL_1_FLOAT                   = 172u;
    static constexpr uint8_t SPARK_PARAM_MAXMOTION_MAX_JERK_1_FLOAT                    = 173u;
    static constexpr uint8_t SPARK_PARAM_MAXMOTION_ALLOWED_CLOSED_LOOP_ERROR_1_FLOAT   = 174u;
    static constexpr uint8_t SPARK_PARAM_MAXMOTION_POSITION_MODE_1_UINT                = 175u;
    static constexpr uint8_t SPARK_PARAM_MAXMOTION_MAX_VELOCITY_2_FLOAT                = 176u;
    static constexpr uint8_t SPARK_PARAM_MAXMOTION_MAX_ACCEL_2_FLOAT                   = 177u;
    static constexpr uint8_t SPARK_PARAM_MAXMOTION_MAX_JERK_2_FLOAT                    = 178u;
    static constexpr uint8_t SPARK_PARAM_MAXMOTION_ALLOWED_CLOSED_LOOP_ERROR_2_FLOAT   = 179u;
    static constexpr uint8_t SPARK_PARAM_MAXMOTION_POSITION_MODE_2_UINT                = 180u;
    static constexpr uint8_t SPARK_PARAM_MAXMOTION_MAX_VELOCITY_3_FLOAT                = 181u;
    static constexpr uint8_t SPARK_PARAM_MAXMOTION_MAX_ACCEL_3_FLOAT                   = 182u;
    static constexpr uint8_t SPARK_PARAM_MAXMOTION_MAX_JERK_3_FLOAT                    = 183u;
    static constexpr uint8_t SPARK_PARAM_MAXMOTION_ALLOWED_CLOSED_LOOP_ERROR_3_FLOAT   = 184u;
    static constexpr uint8_t SPARK_PARAM_MAXMOTION_POSITION_MODE_3_UINT                = 185u;
    static constexpr uint8_t SPARK_PARAM_FORCE_ENABLE_STATUS_0_BOOL                    = 186u;
    static constexpr uint8_t SPARK_PARAM_FORCE_ENABLE_STATUS_1_BOOL                    = 187u;
    static constexpr uint8_t SPARK_PARAM_FORCE_ENABLE_STATUS_2_BOOL                    = 188u;
    static constexpr uint8_t SPARK_PARAM_FORCE_ENABLE_STATUS_3_BOOL                    = 189u;
    static constexpr uint8_t SPARK_PARAM_FORCE_ENABLE_STATUS_4_BOOL                    = 190u;
    static constexpr uint8_t SPARK_PARAM_FORCE_ENABLE_STATUS_5_BOOL                    = 191u;
    static constexpr uint8_t SPARK_PARAM_FORCE_ENABLE_STATUS_6_BOOL                    = 192u;
    static constexpr uint8_t SPARK_PARAM_FORCE_ENABLE_STATUS_7_BOOL                    = 193u;
    static constexpr uint8_t SPARK_PARAM_FOLLOWER_MODE_LEADER_ID_UINT                  = 194u;
    static constexpr uint8_t SPARK_PARAM_FOLLOWER_MODE_IS_INVERTED_BOOL                = 195u;
    static constexpr uint8_t SPARK_PARAM_DUTY_CYCLE_ENCODER_START_PULSE_US_FLOAT       = 196u;
    static constexpr uint8_t SPARK_PARAM_DUTY_CYCLE_ENCODER_END_PULSE_US_FLOAT         = 197u;
    static constexpr uint8_t SPARK_PARAM_PARAM_TABLE_VERSION_UINT                      = 198u;

} // namespace CanControl::LowLevel::SparkMax
