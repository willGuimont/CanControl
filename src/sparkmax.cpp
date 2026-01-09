#include "motors/sparkmax.h"

#include "low_level/low_sparkmax_params.h"

namespace CanControl
{
    using LowLevel::SparkMax::Spark_DUTY_CYCLE_SETPOINT_t;
    using LowLevel::SparkMax::Spark_POSITION_SETPOINT_t;
    using LowLevel::SparkMax::Spark_RESET_SAFE_PARAMETERS_t;
    using LowLevel::SparkMax::Spark_VELOCITY_SETPOINT_t;
    using LowLevel::SparkMax::SparkCanDevice;

    SparkMax::SparkMax(MCP2515& controller, uint8_t device_id) : device_(controller, device_id) {}

    void SparkMax::set_controller(MCP2515& controller)
    {
        device_.set_controller(controller);
    }

    void SparkMax::set_device_id(uint8_t device_id)
    {
        device_.set_device_id(device_id);
    }

    MCP2515* SparkMax::controller() const
    {
        return device_.controller();
    }

    uint8_t SparkMax::device_id() const
    {
        return device_.device_id();
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

        return device_.set_duty_cycle_setpoint(frame);
    }

    MCP2515::ERROR SparkMax::set_position(float position, uint8_t pid_slot, int16_t arbitrary_feedforward,
                                          uint8_t arbitrary_feedforward_units)
    {
        Spark_POSITION_SETPOINT_t frame{};
        frame.SETPOINT                    = position;
        frame.ARBITRARY_FEEDFORWARD       = arbitrary_feedforward;
        frame.PID_SLOT                    = pid_slot;
        frame.ARBITRARY_FEEDFORWARD_UNITS = arbitrary_feedforward_units;

        return device_.set_position_setpoint(frame);
    }

    MCP2515::ERROR SparkMax::set_velocity(float velocity, uint8_t pid_slot, int16_t arbitrary_feedforward,
                                          uint8_t arbitrary_feedforward_units)
    {
        Spark_VELOCITY_SETPOINT_t frame{};
        frame.SETPOINT                    = velocity;
        frame.ARBITRARY_FEEDFORWARD       = arbitrary_feedforward;
        frame.PID_SLOT                    = pid_slot;
        frame.ARBITRARY_FEEDFORWARD_UNITS = arbitrary_feedforward_units;

        return device_.set_velocity_setpoint(frame);
    }

    MCP2515::ERROR SparkMax::stop()
    {
        return set_duty_cycle(0.0f);
    }

    MCP2515::ERROR SparkMax::reset_safe_parameters()
    {
        Spark_RESET_SAFE_PARAMETERS_t frame{};
        frame.MAGIC_NUMBER = 36292u;
        return device_.send_reset_safe_parameters(frame);
    }

    MCP2515::ERROR SparkMax::set_pid_p(float p, uint8_t slot)
    {
        using namespace LowLevel::SparkMax;
        switch (slot)
        {
        case 0:
            return set_parameter_p_0(device_, p);
        case 1:
            return set_parameter_p_1(device_, p);
        case 2:
            return set_parameter_p_2(device_, p);
        case 3:
            return set_parameter_p_3(device_, p);
        default:
            return MCP2515::ERROR_FAIL;
        }
    }

    MCP2515::ERROR SparkMax::set_pid_i(float i, uint8_t slot)
    {
        using namespace LowLevel::SparkMax;
        switch (slot)
        {
        case 0:
            return set_parameter_i_0(device_, i);
        case 1:
            return set_parameter_i_1(device_, i);
        case 2:
            return set_parameter_i_2(device_, i);
        case 3:
            return set_parameter_i_3(device_, i);
        default:
            return MCP2515::ERROR_FAIL;
        }
    }

    MCP2515::ERROR SparkMax::set_pid_d(float d, uint8_t slot)
    {
        using namespace LowLevel::SparkMax;
        switch (slot)
        {
        case 0:
            return set_parameter_d_0(device_, d);
        case 1:
            return set_parameter_d_1(device_, d);
        case 2:
            return set_parameter_d_2(device_, d);
        case 3:
            return set_parameter_d_3(device_, d);
        default:
            return MCP2515::ERROR_FAIL;
        }
    }

    MCP2515::ERROR SparkMax::set_pid_f(float f, uint8_t slot)
    {
        using namespace LowLevel::SparkMax;
        switch (slot)
        {
        case 0:
            return set_parameter_f_0(device_, f);
        case 1:
            return set_parameter_f_1(device_, f);
        case 2:
            return set_parameter_f_2(device_, f);
        case 3:
            return set_parameter_f_3(device_, f);
        default:
            return MCP2515::ERROR_FAIL;
        }
    }

    MCP2515::ERROR SparkMax::set_motor_type(LowLevel::SparkMax::MotorType t)
    {
        using namespace LowLevel::SparkMax;
        return set_parameter_motor_type(device_, t);
    }

    MCP2515::ERROR SparkMax::set_closed_loop_control_sensor(LowLevel::SparkMax::Sensor s)
    {
        using namespace LowLevel::SparkMax;
        return set_parameter_closed_loop_control_sensor(device_, s);
    }

    MCP2515::ERROR SparkMax::set_inverted(bool inverted)
    {
        using namespace LowLevel::SparkMax;
        return set_parameter_inverted(device_, inverted);
    }

    MCP2515::ERROR SparkMax::set_izone(uint8_t slot, float izone)
    {
        using namespace LowLevel::SparkMax;
        switch (slot)
        {
        case 0:
            return set_parameter_izone_0(device_, izone);
        case 1:
            return set_parameter_izone_1(device_, izone);
        case 2:
            return set_parameter_izone_2(device_, izone);
        case 3:
            return set_parameter_izone_3(device_, izone);
        default:
            return MCP2515::ERROR_FAIL;
        }
    }

    MCP2515::ERROR SparkMax::set_d_filter(uint8_t slot, float dfilter)
    {
        using namespace LowLevel::SparkMax;
        switch (slot)
        {
        case 0:
            return set_parameter_d_filter_0(device_, dfilter);
        case 1:
            return set_parameter_d_filter_1(device_, dfilter);
        case 2:
            return set_parameter_d_filter_2(device_, dfilter);
        case 3:
            return set_parameter_d_filter_3(device_, dfilter);
        default:
            return MCP2515::ERROR_FAIL;
        }
    }

    MCP2515::ERROR SparkMax::set_output_min(uint8_t slot, float v)
    {
        using namespace LowLevel::SparkMax;
        switch (slot)
        {
        case 0:
            return set_parameter_output_min_0(device_, v);
        case 1:
            return set_parameter_output_min_1(device_, v);
        case 2:
            return set_parameter_output_min_2(device_, v);
        case 3:
            return set_parameter_output_min_3(device_, v);
        default:
            return MCP2515::ERROR_FAIL;
        }
    }

    MCP2515::ERROR SparkMax::set_output_max(uint8_t slot, float v)
    {
        using namespace LowLevel::SparkMax;
        switch (slot)
        {
        case 0:
            return set_parameter_output_max_0(device_, v);
        case 1:
            return set_parameter_output_max_1(device_, v);
        case 2:
            return set_parameter_output_max_2(device_, v);
        case 3:
            return set_parameter_output_max_3(device_, v);
        default:
            return MCP2515::ERROR_FAIL;
        }
    }

    MCP2515::ERROR SparkMax::set_position_pid_wrap_enable(bool en)
    {
        using namespace LowLevel::SparkMax;
        return set_parameter_position_pid_wrap_enable(device_, en);
    }

    MCP2515::ERROR SparkMax::set_position_pid_min_input(float v)
    {
        using namespace LowLevel::SparkMax;
        return set_parameter_position_pid_min_input(device_, v);
    }

    MCP2515::ERROR SparkMax::set_position_pid_max_input(float v)
    {
        using namespace LowLevel::SparkMax;
        return set_parameter_position_pid_max_input(device_, v);
    }

    MCP2515::ERROR SparkMax::set_limit_switch_fwd_polarity(bool polarity)
    {
        using namespace LowLevel::SparkMax;
        return set_parameter_limit_switch_fwd_polarity(device_, polarity);
    }

    MCP2515::ERROR SparkMax::set_limit_switch_rev_polarity(bool polarity)
    {
        using namespace LowLevel::SparkMax;
        return set_parameter_limit_switch_rev_polarity(device_, polarity);
    }

    MCP2515::ERROR SparkMax::enable_hard_limit_fwd(bool en)
    {
        using namespace LowLevel::SparkMax;
        return set_parameter_hard_limit_fwd_en(device_, en);
    }

    MCP2515::ERROR SparkMax::enable_hard_limit_rev(bool en)
    {
        using namespace LowLevel::SparkMax;
        return set_parameter_hard_limit_rev_en(device_, en);
    }

    MCP2515::ERROR SparkMax::enable_soft_limit_fwd(bool en)
    {
        using namespace LowLevel::SparkMax;
        return set_parameter_soft_limit_fwd_en(device_, en);
    }

    MCP2515::ERROR SparkMax::enable_soft_limit_rev(bool en)
    {
        using namespace LowLevel::SparkMax;
        return set_parameter_soft_limit_rev_en(device_, en);
    }

    MCP2515::ERROR SparkMax::set_encoder_counts_per_rev(uint32_t counts)
    {
        using namespace LowLevel::SparkMax;
        return set_parameter_encoder_counts_per_rev(device_, counts);
    }

    MCP2515::ERROR SparkMax::set_encoder_inverted(bool inv)
    {
        using namespace LowLevel::SparkMax;
        return set_parameter_encoder_inverted(device_, inv);
    }
} // namespace CanControl
