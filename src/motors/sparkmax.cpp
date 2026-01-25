#include "motors/sparkmax.h"

#include "low_level/low_sparkmax_params.h"

namespace CanControl
{
    using LowLevel::SparkMax::Spark_DUTY_CYCLE_SETPOINT_t;
    using LowLevel::SparkMax::Spark_POSITION_SETPOINT_t;
    using LowLevel::SparkMax::Spark_RESET_SAFE_PARAMETERS_t;
    using LowLevel::SparkMax::Spark_VELOCITY_SETPOINT_t;

    SparkMax::SparkMax(MCP2515& controller, uint8_t device_id)
        : controller_(&controller), device_id_(device_id)
    {
    }

    MCP2515::ERROR SparkMax::dispatch_frame(const LowLevel::SparkMax::spark_can_frame& frame, bool periodic)
    {
        struct can_frame out{};
        LowLevel::basic_to_can_frame(frame, &out);
        return controller_->sendMessage(&out);
    }

    MCP2515::ERROR SparkMax::set_duty_cycle(float duty, uint8_t pid_slot, int16_t arbitrary_feedforward,
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

        return dispatch_frame(LowLevel::SparkMax::spark_build_DUTY_CYCLE_SETPOINT(device_id_, &frame), true);
    }

    MCP2515::ERROR SparkMax::set_position(float position, uint8_t pid_slot, int16_t arbitrary_feedforward,
                                          uint8_t arbitrary_feedforward_units)
    {
        Spark_POSITION_SETPOINT_t frame{};
        frame.SETPOINT                    = position;
        frame.ARBITRARY_FEEDFORWARD       = arbitrary_feedforward;
        frame.PID_SLOT                    = pid_slot;
        frame.ARBITRARY_FEEDFORWARD_UNITS = arbitrary_feedforward_units;

        return dispatch_frame(LowLevel::SparkMax::spark_build_POSITION_SETPOINT(device_id_, &frame), true);
    }

    MCP2515::ERROR SparkMax::set_velocity(float velocity, uint8_t pid_slot, int16_t arbitrary_feedforward,
                                          uint8_t arbitrary_feedforward_units)
    {
        Spark_VELOCITY_SETPOINT_t frame{};
        frame.SETPOINT                    = velocity;
        frame.ARBITRARY_FEEDFORWARD       = arbitrary_feedforward;
        frame.PID_SLOT                    = pid_slot;
        frame.ARBITRARY_FEEDFORWARD_UNITS = arbitrary_feedforward_units;

        return dispatch_frame(LowLevel::SparkMax::spark_build_VELOCITY_SETPOINT(device_id_, &frame), true);
    }

    MCP2515::ERROR SparkMax::stop()
    {
        return set_duty_cycle(0.0f);
    }

    MCP2515::ERROR SparkMax::reset_safe_parameters()
    {
        Spark_RESET_SAFE_PARAMETERS_t frame{};
        frame.MAGIC_NUMBER = 36292u;
        return dispatch_frame(LowLevel::SparkMax::spark_build_RESET_SAFE_PARAMETERS(device_id_, &frame));
    }

    static MCP2515::ERROR write_float_param(MCP2515* controller, uint8_t device_id, uint8_t base_id, uint8_t slot,
                                            float value)
    {
        if (slot > 3)
            return MCP2515::ERROR_FAIL;
        union
        {
            float    f;
            uint32_t u;
        } conv = {.f = value};
        return (MCP2515::ERROR)LowLevel::SparkMax::write_parameter_raw(*controller, device_id, base_id + slot * 8,
                                                                       conv.u);
    }

    MCP2515::ERROR SparkMax::set_pid_p(float p, uint8_t slot)
    {
        return write_float_param(controller_, device_id_, 13, slot, p);
    }

    MCP2515::ERROR SparkMax::set_pid_i(float i, uint8_t slot)
    {
        return write_float_param(controller_, device_id_, 14, slot, i);
    }

    MCP2515::ERROR SparkMax::set_pid_d(float d, uint8_t slot)
    {
        return write_float_param(controller_, device_id_, 15, slot, d);
    }

    MCP2515::ERROR SparkMax::set_pid_f(float f, uint8_t slot)
    {
        return write_float_param(controller_, device_id_, 16, slot, f);
    }

    MCP2515::ERROR SparkMax::set_motor_type(LowLevel::SparkMax::MotorType t)
    {
        using namespace LowLevel::SparkMax;
        return (MCP2515::ERROR)set_parameter(*controller_, device_id_, SPARK_PARAM_MOTOR_TYPE_UINT, (uint32_t)t);
    }

    MCP2515::ERROR SparkMax::set_idle_mode(LowLevel::SparkMax::IdleMode m)
    {
        using namespace LowLevel::SparkMax;
        return (MCP2515::ERROR)set_parameter(*controller_, device_id_, SPARK_PARAM_IDLE_MODE_UINT, (uint32_t)m);
    }

    MCP2515::ERROR SparkMax::set_closed_loop_control_sensor(LowLevel::SparkMax::Sensor s)
    {
        using namespace LowLevel::SparkMax;
        return (MCP2515::ERROR)set_parameter(*controller_, device_id_, SPARK_PARAM_CLOSED_LOOP_CONTROL_SENSOR_UINT,
                                             (uint32_t)s);
    }

    MCP2515::ERROR SparkMax::set_inverted(bool inverted)
    {
        using namespace LowLevel::SparkMax;
        return (MCP2515::ERROR)set_parameter(*controller_, device_id_, SPARK_PARAM_INVERTED_BOOL, inverted);
    }

    MCP2515::ERROR SparkMax::set_izone(uint8_t slot, float izone)
    {
        return write_float_param(controller_, device_id_, 17, slot, izone);
    }

    MCP2515::ERROR SparkMax::set_d_filter(uint8_t slot, float dfilter)
    {
        return write_float_param(controller_, device_id_, 18, slot, dfilter);
    }

    MCP2515::ERROR SparkMax::set_output_min(uint8_t slot, float v)
    {
        return write_float_param(controller_, device_id_, 19, slot, v);
    }

    MCP2515::ERROR SparkMax::set_output_max(uint8_t slot, float v)
    {
        return write_float_param(controller_, device_id_, 20, slot, v);
    }

    MCP2515::ERROR SparkMax::set_position_pid_wrap_enable(bool en)
    {
        using namespace LowLevel::SparkMax;
        return (MCP2515::ERROR)set_parameter(*controller_, device_id_, SPARK_PARAM_POSITION_PID_WRAP_ENABLE_BOOL, en);
    }

    MCP2515::ERROR SparkMax::set_position_pid_min_input(float v)
    {
        using namespace LowLevel::SparkMax;
        return (MCP2515::ERROR)set_parameter(*controller_, device_id_, SPARK_PARAM_POSITION_PID_MIN_INPUT_FLOAT, v);
    }

    MCP2515::ERROR SparkMax::set_position_pid_max_input(float v)
    {
        using namespace LowLevel::SparkMax;
        return (MCP2515::ERROR)set_parameter(*controller_, device_id_, SPARK_PARAM_POSITION_PID_MAX_INPUT_FLOAT, v);
    }

    MCP2515::ERROR SparkMax::set_limit_switch_fwd_polarity(bool polarity)
    {
        using namespace LowLevel::SparkMax;
        return (MCP2515::ERROR)set_parameter(*controller_, device_id_, SPARK_PARAM_LIMIT_SWITCH_FWD_POLARITY_BOOL,
                                             polarity);
    }

    MCP2515::ERROR SparkMax::set_limit_switch_rev_polarity(bool polarity)
    {
        using namespace LowLevel::SparkMax;
        return (MCP2515::ERROR)set_parameter(*controller_, device_id_, SPARK_PARAM_LIMIT_SWITCH_REV_POLARITY_BOOL,
                                             polarity);
    }

    MCP2515::ERROR SparkMax::enable_hard_limit_fwd(bool en)
    {
        using namespace LowLevel::SparkMax;
        return (MCP2515::ERROR)set_parameter(*controller_, device_id_, SPARK_PARAM_HARD_LIMIT_FWD_EN_BOOL, en);
    }

    MCP2515::ERROR SparkMax::enable_hard_limit_rev(bool en)
    {
        using namespace LowLevel::SparkMax;
        return (MCP2515::ERROR)set_parameter(*controller_, device_id_, SPARK_PARAM_HARD_LIMIT_REV_EN_BOOL, en);
    }

    MCP2515::ERROR SparkMax::enable_soft_limit_fwd(bool en)
    {
        using namespace LowLevel::SparkMax;
        return (MCP2515::ERROR)set_parameter(*controller_, device_id_, SPARK_PARAM_SOFT_LIMIT_FWD_EN_BOOL, en);
    }

    MCP2515::ERROR SparkMax::enable_soft_limit_rev(bool en)
    {
        using namespace LowLevel::SparkMax;
        return (MCP2515::ERROR)set_parameter(*controller_, device_id_, SPARK_PARAM_SOFT_LIMIT_REV_EN_BOOL, en);
    }

    MCP2515::ERROR SparkMax::set_encoder_counts_per_rev(uint32_t counts)
    {
        using namespace LowLevel::SparkMax;
        return (MCP2515::ERROR)set_parameter(*controller_, device_id_, SPARK_PARAM_ENCODER_COUNTS_PER_REV_UINT, counts);
    }

    MCP2515::ERROR SparkMax::set_encoder_inverted(bool inv)
    {
        using namespace LowLevel::SparkMax;
        return (MCP2515::ERROR)set_parameter(*controller_, device_id_, SPARK_PARAM_ENCODER_INVERTED_BOOL, inv);
    }
} // namespace CanControl
