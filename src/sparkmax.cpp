#include "sparkmax.h"

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
} // namespace CanControl
