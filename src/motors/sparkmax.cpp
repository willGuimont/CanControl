#include "motors/sparkmax.h"

#include "low_level/low_sparkmax_params.h"

namespace CanControl
{
    using LowLevel::SparkMax::Spark_DUTY_CYCLE_SETPOINT_t;
    using LowLevel::SparkMax::Spark_POSITION_SETPOINT_t;
    using LowLevel::SparkMax::Spark_RESET_SAFE_PARAMETERS_t;
    using LowLevel::SparkMax::Spark_VELOCITY_SETPOINT_t;

    /**
     * @brief Construct a new Spark Max object
     *
     * @param controller Reference to the MCP2515 controller.
     * @param device_id CAN ID of the motor controller (0-63).
     */
    SparkMax::SparkMax(MCP2515& controller, uint8_t device_id) : controller_(&controller), device_id_(device_id) {}

    void SparkMax::set_controller(MCP2515& controller)
    {
        controller_ = &controller;
    }

    void SparkMax::set_device_id(uint8_t device_id)
    {
        device_id_ = device_id;
    }

    MCP2515* SparkMax::controller() const
    {
        return controller_;
    }

    uint8_t SparkMax::device_id() const
    {
        return device_id_;
    }

    MCP2515::ERROR SparkMax::dispatch_frame(const LowLevel::SparkMax::spark_can_frame& frame) const
    {
        struct can_frame out{};
        LowLevel::basic_to_can_frame(frame, &out);
        return controller_->sendMessage(&out);
    }

    /**
     * @brief Sets the duty cycle (percent output) of the motor.
     *
     * @param duty The duty cycle to set, from -1.0 to 1.0.
     * @param pid_slot The PID slot to use (0-3).
     * @param arbitrary_feedforward Arbitrary feedforward value.
     * @param arbitrary_feedforward_units Units for arbitrary feedforward.
     * @return MCP2515::ERROR Status of the CAN transmission.
     */
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

        return dispatch_frame(LowLevel::SparkMax::spark_build_DUTY_CYCLE_SETPOINT(device_id_, &frame));
    }

    /**
     * @brief Sets the target position for the motor (requires PID configuration).
     *
     * @param position Target position in rotations.
     * @param pid_slot The PID slot to use (0-3).
     * @param arbitrary_feedforward Arbitrary feedforward value.
     * @param arbitrary_feedforward_units Units for arbitrary feedforward.
     * @return MCP2515::ERROR Status of the CAN transmission.
     */
    MCP2515::ERROR SparkMax::set_position(float position, uint8_t pid_slot, int16_t arbitrary_feedforward,
                                          uint8_t arbitrary_feedforward_units)
    {
        Spark_POSITION_SETPOINT_t frame{};
        frame.SETPOINT                    = position;
        frame.ARBITRARY_FEEDFORWARD       = arbitrary_feedforward;
        frame.PID_SLOT                    = pid_slot;
        frame.ARBITRARY_FEEDFORWARD_UNITS = arbitrary_feedforward_units;

        return dispatch_frame(LowLevel::SparkMax::spark_build_POSITION_SETPOINT(device_id_, &frame));
    }

    /**
     * @brief Sets the target velocity for the motor (requires PID configuration).
     *
     * @param velocity Target velocity in RPM.
     * @param pid_slot The PID slot to use (0-3).
     * @param arbitrary_feedforward Arbitrary feedforward value.
     * @param arbitrary_feedforward_units Units for arbitrary feedforward.
     * @return MCP2515::ERROR Status of the CAN transmission.
     */
    MCP2515::ERROR SparkMax::set_velocity(float velocity, uint8_t pid_slot, int16_t arbitrary_feedforward,
                                          uint8_t arbitrary_feedforward_units)
    {
        Spark_VELOCITY_SETPOINT_t frame{};
        frame.SETPOINT                    = velocity;
        frame.ARBITRARY_FEEDFORWARD       = arbitrary_feedforward;
        frame.PID_SLOT                    = pid_slot;
        frame.ARBITRARY_FEEDFORWARD_UNITS = arbitrary_feedforward_units;

        return dispatch_frame(LowLevel::SparkMax::spark_build_VELOCITY_SETPOINT(device_id_, &frame));
    }

    /**
     * @brief Stops the motor by setting duty cycle to 0.
     *
     * @return MCP2515::ERROR Status of the CAN transmission.
     */
    MCP2515::ERROR SparkMax::stop()
    {
        return set_duty_cycle(0.0f);
    }

    /**
     * @brief Resets the motor parameters to their factory defaults.
     *
     * @return MCP2515::ERROR Status of the CAN transmission.
     */
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

    /**
     * @brief Sets the Proportional (P) gain for the PID controller.
     *
     * @param p The P gain value.
     * @param slot The PID slot to update (0-3).
     * @return MCP2515::ERROR Status of the CAN transmission.
     */
    MCP2515::ERROR SparkMax::set_pid_p(float p, uint8_t slot)
    {
        return write_float_param(controller_, device_id_, 13, slot, p);
    }

    /**
     * @brief Sets the Integral (I) gain for the PID controller.
     *
     * @param i The I gain value.
     * @param slot The PID slot to update (0-3).
     * @return MCP2515::ERROR Status of the CAN transmission.
     */
    MCP2515::ERROR SparkMax::set_pid_i(float i, uint8_t slot)
    {
        return write_float_param(controller_, device_id_, 14, slot, i);
    }

    /**
     * @brief Sets the Derivative (D) gain for the PID controller.
     *
     * @param d The D gain value.
     * @param slot The PID slot to update (0-3).
     * @return MCP2515::ERROR Status of the CAN transmission.
     */
    MCP2515::ERROR SparkMax::set_pid_d(float d, uint8_t slot)
    {
        return write_float_param(controller_, device_id_, 15, slot, d);
    }

    /**
     * @brief Sets the Feedforward (F) gain for the PID controller.
     *
     * @param f The F gain value.
     * @param slot The PID slot to update (0-3).
     * @return MCP2515::ERROR Status of the CAN transmission.
     */
    MCP2515::ERROR SparkMax::set_pid_f(float f, uint8_t slot)
    {
        return write_float_param(controller_, device_id_, 16, slot, f);
    }

    /**
     * @brief Sets the motor type (Brushed or Brushless).
     *
     * @param t The motor type enum.
     * @return MCP2515::ERROR Status of the CAN transmission.
     */
    MCP2515::ERROR SparkMax::set_motor_type(LowLevel::SparkMax::MotorType t)
    {

        using namespace LowLevel::SparkMax;
        return (MCP2515::ERROR)set_parameter(*controller_, device_id_, SPARK_PARAM_MOTOR_TYPE_UINT, (uint32_t)t);
    }

    /**
     * @brief Configures the primary sensor for closed-loop control.
     *
     * @param s The sensor type (e.g., specific internal encoder or external sensor).
     * @return MCP2515::ERROR Status of the CAN transmission.
     */
    MCP2515::ERROR SparkMax::set_closed_loop_control_sensor(LowLevel::SparkMax::Sensor s)
    {

        using namespace LowLevel::SparkMax;
        return (MCP2515::ERROR)set_parameter(*controller_, device_id_, SPARK_PARAM_CLOSED_LOOP_CONTROL_SENSOR_UINT,
                                             (uint32_t)s);
    }

    /**
     * @brief Inverts the motor output direction.
     *
     * @param inverted True to invert, false otherwise.
     * @return MCP2515::ERROR Status of the CAN transmission.
     */
    MCP2515::ERROR SparkMax::set_inverted(bool inverted)
    {

        using namespace LowLevel::SparkMax;
        return (MCP2515::ERROR)set_parameter(*controller_, device_id_, SPARK_PARAM_INVERTED_BOOL, inverted);
    }

    /**
     * @brief Sets the Integral Zone (IZone) for the PID controller.
     *
     * @param slot The PID slot to update (0-3).
     * @param izone The IZone value.
     * @return MCP2515::ERROR Status of the CAN transmission.
     */
    MCP2515::ERROR SparkMax::set_izone(uint8_t slot, float izone)
    {
        return write_float_param(controller_, device_id_, 17, slot, izone);
    }

    /**
     * @brief Sets the Derivative Filter (DFilter) for the PID controller.
     *
     * @param slot The PID slot to update (0-3).
     * @param dfilter The filter value.
     * @return MCP2515::ERROR Status of the CAN transmission.
     */
    MCP2515::ERROR SparkMax::set_d_filter(uint8_t slot, float dfilter)
    {
        return write_float_param(controller_, device_id_, 18, slot, dfilter);
    }

    /**
     * @brief Sets the minimum output for the PID controller.
     *
     * @param slot The PID slot to update (0-3).
     * @param v The minimum output value.
     * @return MCP2515::ERROR Status of the CAN transmission.
     */
    MCP2515::ERROR SparkMax::set_output_min(uint8_t slot, float v)
    {
        return write_float_param(controller_, device_id_, 19, slot, v);
    }

    /**
     * @brief Sets the maximum output for the PID controller.
     *
     * @param slot The PID slot to update (0-3).
     * @param v The maximum output value.
     * @return MCP2515::ERROR Status of the CAN transmission.
     */
    MCP2515::ERROR SparkMax::set_output_max(uint8_t slot, float v)
    {
        return write_float_param(controller_, device_id_, 20, slot, v);
    }

    /**
     * @brief Enables or disables position PID wrapping (for continuous rotation mechanisms).
     *
     * @param en True to enable, false to disable.
     * @return MCP2515::ERROR Status of the CAN transmission.
     */
    MCP2515::ERROR SparkMax::set_position_pid_wrap_enable(bool en)
    {

        using namespace LowLevel::SparkMax;
        return (MCP2515::ERROR)set_parameter(*controller_, device_id_, SPARK_PARAM_POSITION_PID_WRAP_ENABLE_BOOL, en);
    }

    /**
     * @brief Sets the minimum input value for the position PID controller.
     *
     * @param v The minimum input value.
     * @return MCP2515::ERROR Status of the CAN transmission.
     */
    MCP2515::ERROR SparkMax::set_position_pid_min_input(float v)
    {

        using namespace LowLevel::SparkMax;
        return (MCP2515::ERROR)set_parameter(*controller_, device_id_, SPARK_PARAM_POSITION_PID_MIN_INPUT_FLOAT, v);
    }

    /**
     * @brief Sets the maximum input value for the position PID controller.
     *
     * @param v The maximum input value.
     * @return MCP2515::ERROR Status of the CAN transmission.
     */
    MCP2515::ERROR SparkMax::set_position_pid_max_input(float v)
    {

        using namespace LowLevel::SparkMax;
        return (MCP2515::ERROR)set_parameter(*controller_, device_id_, SPARK_PARAM_POSITION_PID_MAX_INPUT_FLOAT, v);
    }

    /**
     * @brief Sets the polarity of the forward limit switch.
     *
     * @param polarity True for normally open, false for normally closed (or vice versa, check datasheet).
     * @return MCP2515::ERROR Status of the CAN transmission.
     */
    MCP2515::ERROR SparkMax::set_limit_switch_fwd_polarity(bool polarity)
    {

        using namespace LowLevel::SparkMax;
        return (MCP2515::ERROR)set_parameter(*controller_, device_id_, SPARK_PARAM_LIMIT_SWITCH_FWD_POLARITY_BOOL,
                                             polarity);
    }

    /**
     * @brief Sets the polarity of the reverse limit switch.
     *
     * @param polarity True for normally open, false for normally closed (or vice versa, check datasheet).
     * @return MCP2515::ERROR Status of the CAN transmission.
     */
    MCP2515::ERROR SparkMax::set_limit_switch_rev_polarity(bool polarity)
    {

        using namespace LowLevel::SparkMax;
        return (MCP2515::ERROR)set_parameter(*controller_, device_id_, SPARK_PARAM_LIMIT_SWITCH_REV_POLARITY_BOOL,
                                             polarity);
    }

    /**
     * @brief Enables the forward hard limit switch.
     *
     * @param en True to enable, false to disable.
     * @return MCP2515::ERROR Status of the CAN transmission.
     */
    MCP2515::ERROR SparkMax::enable_hard_limit_fwd(bool en)
    {

        using namespace LowLevel::SparkMax;
        return (MCP2515::ERROR)set_parameter(*controller_, device_id_, SPARK_PARAM_HARD_LIMIT_FWD_EN_BOOL, en);
    }

    /**
     * @brief Enables the reverse hard limit switch.
     *
     * @param en True to enable, false to disable.
     * @return MCP2515::ERROR Status of the CAN transmission.
     */
    MCP2515::ERROR SparkMax::enable_hard_limit_rev(bool en)
    {

        using namespace LowLevel::SparkMax;
        return (MCP2515::ERROR)set_parameter(*controller_, device_id_, SPARK_PARAM_HARD_LIMIT_REV_EN_BOOL, en);
    }

    /**
     * @brief Enables the forward soft limit.
     *
     * @param en True to enable, false to disable.
     * @return MCP2515::ERROR Status of the CAN transmission.
     */
    MCP2515::ERROR SparkMax::enable_soft_limit_fwd(bool en)
    {

        using namespace LowLevel::SparkMax;
        return (MCP2515::ERROR)set_parameter(*controller_, device_id_, SPARK_PARAM_SOFT_LIMIT_FWD_EN_BOOL, en);
    }

    /**
     * @brief Enables the reverse soft limit.
     *
     * @param en True to enable, false to disable.
     * @return MCP2515::ERROR Status of the CAN transmission.
     */
    MCP2515::ERROR SparkMax::enable_soft_limit_rev(bool en)
    {

        using namespace LowLevel::SparkMax;
        return (MCP2515::ERROR)set_parameter(*controller_, device_id_, SPARK_PARAM_SOFT_LIMIT_REV_EN_BOOL, en);
    }

    /**
     * @brief Sets the encoder counts per revolution (CPR).
     *
     * @param counts The counts per revolution.
     * @return MCP2515::ERROR Status of the CAN transmission.
     */
    MCP2515::ERROR SparkMax::set_encoder_counts_per_rev(uint32_t counts)
    {

        using namespace LowLevel::SparkMax;
        return (MCP2515::ERROR)set_parameter(*controller_, device_id_, SPARK_PARAM_ENCODER_COUNTS_PER_REV_UINT, counts);
    }

    /**
     * @brief Inverts the encoder direction.
     *
     * @param inv True to invert, false otherwise.
     * @return MCP2515::ERROR Status of the CAN transmission.
     */
    MCP2515::ERROR SparkMax::set_encoder_inverted(bool inv)
    {

        using namespace LowLevel::SparkMax;
        return (MCP2515::ERROR)set_parameter(*controller_, device_id_, SPARK_PARAM_ENCODER_INVERTED_BOOL, inv);
    }
} // namespace CanControl
