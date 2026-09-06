#include "motors/sparkmax.h"

#include "commands.h"
#include "low_level/low_sparkmax_params.h"

namespace CanControl
{
    SparkMax::SparkMax(MCP2515& controller, uint8_t device_id) : controller_(&controller), device_id_(device_id) {}

    SparkMax::SparkMax(uint8_t device_id) : controller_(nullptr), device_id_(device_id) {}

    uint8_t SparkMax::get_device_id() const
    {
        return device_id_;
    }

    MCP2515::ERROR SparkMax::dispatch_frame(const LowLevel::SparkMax::spark_can_frame& frame, bool periodic)
    {
        if (controller_ == nullptr)
            return MCP2515::ERROR_FAILINIT;
        struct can_frame out{};
        LowLevel::basic_to_can_frame(frame, &out);
        return controller_->sendMessage(&out);
    }

    MCP2515::ERROR SparkMax::set_duty_cycle(float duty, uint8_t pid_slot, int16_t arbitrary_feedforward,
                                            uint8_t arbitrary_feedforward_units)
    {
        return dispatch_frame(Commands::SparkMax::build_duty_cycle(device_id_, duty, pid_slot, arbitrary_feedforward,
                                                                   arbitrary_feedforward_units),
                              true);
    }

    MCP2515::ERROR SparkMax::set_position(float position, uint8_t pid_slot, int16_t arbitrary_feedforward,
                                          uint8_t arbitrary_feedforward_units)
    {
        return dispatch_frame(Commands::SparkMax::build_position(device_id_, position, pid_slot, arbitrary_feedforward,
                                                                 arbitrary_feedforward_units),
                              true);
    }

    MCP2515::ERROR SparkMax::set_velocity(float velocity, uint8_t pid_slot, int16_t arbitrary_feedforward,
                                          uint8_t arbitrary_feedforward_units)
    {
        return dispatch_frame(Commands::SparkMax::build_velocity(device_id_, velocity, pid_slot, arbitrary_feedforward,
                                                                 arbitrary_feedforward_units),
                              true);
    }

    MCP2515::ERROR SparkMax::stop()
    {
        return set_duty_cycle(0.0f);
    }

    MCP2515::ERROR SparkMax::reset_safe_parameters()
    {
        return dispatch_frame(Commands::SparkMax::build_reset_safe_parameters(device_id_));
    }

    MCP2515::ERROR SparkMax::set_primary_encoder_position(float position, uint8_t data_type)
    {
        return dispatch_frame(Commands::SparkMax::build_primary_encoder_position(device_id_, position, data_type));
    }

    MCP2515::ERROR SparkMax::dispatch_param(uint8_t param_id, uint32_t raw_value)
    {
        return dispatch_frame(LowLevel::SparkMax::build_parameter_frame(device_id_, param_id, raw_value));
    }

    MCP2515::ERROR SparkMax::dispatch_float_param(uint8_t base_id, uint8_t slot, float value)
    {
        if (slot > 3)
            return MCP2515::ERROR_FAIL;
        union
        {
            float    f;
            uint32_t u;
        } conv = {.f = value};
        return dispatch_param(base_id + slot * 8, conv.u);
    }

    MCP2515::ERROR SparkMax::set_pid_p(float p, uint8_t slot)
    {
        return dispatch_float_param(13, slot, p);
    }

    MCP2515::ERROR SparkMax::set_pid_i(float i, uint8_t slot)
    {
        return dispatch_float_param(14, slot, i);
    }

    MCP2515::ERROR SparkMax::set_pid_d(float d, uint8_t slot)
    {
        return dispatch_float_param(15, slot, d);
    }

    MCP2515::ERROR SparkMax::set_pid_f(float f, uint8_t slot)
    {
        return dispatch_float_param(16, slot, f);
    }

    MCP2515::ERROR SparkMax::set_motor_type(LowLevel::SparkMax::MotorType t)
    {
        return dispatch_param(LowLevel::SparkMax::SPARK_PARAM_MOTOR_TYPE_UINT, (uint32_t)t);
    }

    MCP2515::ERROR SparkMax::set_idle_mode(LowLevel::SparkMax::IdleMode m)
    {
        return dispatch_param(LowLevel::SparkMax::SPARK_PARAM_IDLE_MODE_UINT, (uint32_t)m);
    }

    MCP2515::ERROR SparkMax::set_closed_loop_control_sensor(LowLevel::SparkMax::Sensor s)
    {
        return dispatch_param(LowLevel::SparkMax::SPARK_PARAM_CLOSED_LOOP_CONTROL_SENSOR_UINT, (uint32_t)s);
    }

    MCP2515::ERROR SparkMax::set_inverted(bool inverted)
    {
        return dispatch_param(LowLevel::SparkMax::SPARK_PARAM_INVERTED_BOOL, inverted ? 1u : 0u);
    }

    MCP2515::ERROR SparkMax::set_izone(uint8_t slot, float izone)
    {
        return dispatch_float_param(17, slot, izone);
    }

    MCP2515::ERROR SparkMax::set_d_filter(uint8_t slot, float dfilter)
    {
        return dispatch_float_param(18, slot, dfilter);
    }

    MCP2515::ERROR SparkMax::set_output_min(uint8_t slot, float v)
    {
        return dispatch_float_param(19, slot, v);
    }

    MCP2515::ERROR SparkMax::set_output_max(uint8_t slot, float v)
    {
        return dispatch_float_param(20, slot, v);
    }

    MCP2515::ERROR SparkMax::set_position_pid_wrap_enable(bool en)
    {
        return dispatch_param(LowLevel::SparkMax::SPARK_PARAM_POSITION_PID_WRAP_ENABLE_BOOL, en ? 1u : 0u);
    }

    MCP2515::ERROR SparkMax::set_position_pid_min_input(float v)
    {
        union
        {
            float    f;
            uint32_t u;
        } conv = {.f = v};
        return dispatch_param(LowLevel::SparkMax::SPARK_PARAM_POSITION_PID_MIN_INPUT_FLOAT, conv.u);
    }

    MCP2515::ERROR SparkMax::set_position_pid_max_input(float v)
    {
        union
        {
            float    f;
            uint32_t u;
        } conv = {.f = v};
        return dispatch_param(LowLevel::SparkMax::SPARK_PARAM_POSITION_PID_MAX_INPUT_FLOAT, conv.u);
    }

    MCP2515::ERROR SparkMax::set_limit_switch_fwd_polarity(bool polarity)
    {
        return dispatch_param(LowLevel::SparkMax::SPARK_PARAM_LIMIT_SWITCH_FWD_POLARITY_BOOL, polarity ? 1u : 0u);
    }

    MCP2515::ERROR SparkMax::set_limit_switch_rev_polarity(bool polarity)
    {
        return dispatch_param(LowLevel::SparkMax::SPARK_PARAM_LIMIT_SWITCH_REV_POLARITY_BOOL, polarity ? 1u : 0u);
    }

    MCP2515::ERROR SparkMax::enable_hard_limit_fwd(bool en)
    {
        return dispatch_param(LowLevel::SparkMax::SPARK_PARAM_HARD_LIMIT_FWD_EN_BOOL, en ? 1u : 0u);
    }

    MCP2515::ERROR SparkMax::enable_hard_limit_rev(bool en)
    {
        return dispatch_param(LowLevel::SparkMax::SPARK_PARAM_HARD_LIMIT_REV_EN_BOOL, en ? 1u : 0u);
    }

    MCP2515::ERROR SparkMax::enable_soft_limit_fwd(bool en)
    {
        return dispatch_param(LowLevel::SparkMax::SPARK_PARAM_SOFT_LIMIT_FWD_EN_BOOL, en ? 1u : 0u);
    }

    MCP2515::ERROR SparkMax::enable_soft_limit_rev(bool en)
    {
        return dispatch_param(LowLevel::SparkMax::SPARK_PARAM_SOFT_LIMIT_REV_EN_BOOL, en ? 1u : 0u);
    }

    MCP2515::ERROR SparkMax::set_encoder_counts_per_rev(uint32_t counts)
    {
        return dispatch_param(LowLevel::SparkMax::SPARK_PARAM_ENCODER_COUNTS_PER_REV_UINT, counts);
    }

    MCP2515::ERROR SparkMax::set_encoder_inverted(bool inv)
    {
        return dispatch_param(LowLevel::SparkMax::SPARK_PARAM_ENCODER_INVERTED_BOOL, inv ? 1u : 0u);
    }

    void SparkMax::handle_received_frame(const struct can_frame& frame)
    {
        update_sparkmax_status(status_, device_id_, frame);
    }

    bool SparkMax::has_status0() const
    {
        return (status_.received_mask & uint16_t(1u << 0)) != 0;
    }

    bool SparkMax::has_status1() const
    {
        return (status_.received_mask & uint16_t(1u << 1)) != 0;
    }

    bool SparkMax::has_status2() const
    {
        return (status_.received_mask & uint16_t(1u << 2)) != 0;
    }

    bool SparkMax::has_status3() const
    {
        return (status_.received_mask & uint16_t(1u << 3)) != 0;
    }

    bool SparkMax::has_status4() const
    {
        return (status_.received_mask & uint16_t(1u << 4)) != 0;
    }

    bool SparkMax::has_status5() const
    {
        return (status_.received_mask & uint16_t(1u << 5)) != 0;
    }

    bool SparkMax::has_status6() const
    {
        return (status_.received_mask & uint16_t(1u << 6)) != 0;
    }

    bool SparkMax::has_status7() const
    {
        return (status_.received_mask & uint16_t(1u << 7)) != 0;
    }

    bool SparkMax::has_status8() const
    {
        return (status_.received_mask & uint16_t(1u << 8)) != 0;
    }

    bool SparkMax::has_status9() const
    {
        return (status_.received_mask & uint16_t(1u << 9)) != 0;
    }

    bool SparkMax::hard_forward_limit_reached() const
    {
        return has_status0() ? status_.hard_forward_limit : false;
    }

    bool SparkMax::hard_reverse_limit_reached() const
    {
        return has_status0() ? status_.hard_reverse_limit : false;
    }

    float SparkMax::last_applied_output() const
    {
        return has_status0() ? (float)status_.applied_output / 32767.0f : 0.0f;
    }

    float SparkMax::last_position() const
    {
        return has_status2() ? status_.position : 0.0f;
    }

    float SparkMax::get_encoder_position() const
    {
        return last_position();
    }
} // namespace CanControl
