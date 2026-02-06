#include "motors/sparkmax.h"

#include "low_level/low_sparkmax_params.h"

namespace CanControl
{
    using LowLevel::SparkMax::Spark_DUTY_CYCLE_SETPOINT_t;
    using LowLevel::SparkMax::Spark_POSITION_SETPOINT_t;
    using LowLevel::SparkMax::Spark_RESET_SAFE_PARAMETERS_t;
    using LowLevel::SparkMax::Spark_VELOCITY_SETPOINT_t;

    SparkMax::SparkMax(MCP2515& controller, uint8_t device_id) : controller_(&controller), device_id_(device_id) {}

    uint8_t SparkMax::get_device_id() const
    {
        return device_id_;
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

    void SparkMax::handle_received_frame(const struct can_frame& frame)
    {
        using namespace CanControl::LowLevel::SparkMax;
        using CanControl::LowLevel::basic_can_frame;

        basic_can_frame bf{};
        // Mask off MCP2515 flags and extract 29-bit id
        bf.id     = (uint32_t)(frame.can_id & CanControl::frc_can_id::MASK_frc_id);
        bf.dlc    = frame.can_dlc;
        bf.is_rtr = (frame.can_id & RTR_FLAG) != 0;
        if (bf.dlc > 0)
            memcpy(bf.data, frame.data, bf.dlc);

        // Ensure this message is for our device id by checking the device id field
        uint8_t msg_device = (uint8_t)(bf.id & SPARK_DEVICE_ID_MASK);
        if (msg_device != device_id_)
            return;

        // Now match and decode known status frames
        if (SPARK_MATCH_STATUS_0(bf.id))
        {
            Spark_STATUS_0_t st{};
            if (spark_decode_STATUS_0_frame(bf, &st))
            {
                last_status0_ = st;
                has_status0_  = true;
            }
        }
        if (SPARK_MATCH_STATUS_1(bf.id))
        {
            Spark_STATUS_1_t st1{};
            if (spark_decode_STATUS_1_frame(bf, &st1))
            {
                last_status1_ = st1;
                has_status1_  = true;
            }
        }

        if (SPARK_MATCH_STATUS_2(bf.id))
        {
            Spark_STATUS_2_t st2{};
            if (spark_decode_STATUS_2_frame(bf, &st2))
            {
                last_status2_ = st2;
                has_status2_  = true;
            }
        }

        if (SPARK_MATCH_STATUS_3(bf.id))
        {
            Spark_STATUS_3_t st3{};
            if (spark_decode_STATUS_3_frame(bf, &st3))
            {
                last_status3_ = st3;
                has_status3_  = true;
            }
        }

        if (SPARK_MATCH_STATUS_4(bf.id))
        {
            Spark_STATUS_4_t st4{};
            if (spark_decode_STATUS_4_frame(bf, &st4))
            {
                last_status4_ = st4;
                has_status4_  = true;
            }
        }

        if (SPARK_MATCH_STATUS_5(bf.id))
        {
            Spark_STATUS_5_t st5{};
            if (spark_decode_STATUS_5_frame(bf, &st5))
            {
                last_status5_ = st5;
                has_status5_  = true;
            }
        }

        if (SPARK_MATCH_STATUS_6(bf.id))
        {
            Spark_STATUS_6_t st6{};
            if (spark_decode_STATUS_6_frame(bf, &st6))
            {
                last_status6_ = st6;
                has_status6_  = true;
            }
        }

        if (SPARK_MATCH_STATUS_7(bf.id))
        {
            Spark_STATUS_7_t st7{};
            if (spark_decode_STATUS_7_frame(bf, &st7))
            {
                last_status7_ = st7;
                has_status7_  = true;
            }
        }

        if (SPARK_MATCH_STATUS_8(bf.id))
        {
            Spark_STATUS_8_t st8{};
            if (spark_decode_STATUS_8_frame(bf, &st8))
            {
                last_status8_ = st8;
                has_status8_  = true;
            }
        }

        if (SPARK_MATCH_STATUS_9(bf.id))
        {
            Spark_STATUS_9_t st9{};
            if (spark_decode_STATUS_9_frame(bf, &st9))
            {
                last_status9_ = st9;
                has_status9_  = true;
            }
        }
    }

    bool SparkMax::has_status0() const
    {
        return has_status0_;
    }

    bool SparkMax::has_status1() const
    {
        return has_status1_;
    }

    bool SparkMax::has_status2() const
    {
        return has_status2_;
    }

    bool SparkMax::has_status3() const
    {
        return has_status3_;
    }

    bool SparkMax::has_status4() const
    {
        return has_status4_;
    }

    bool SparkMax::has_status5() const
    {
        return has_status5_;
    }

    bool SparkMax::has_status6() const
    {
        return has_status6_;
    }

    bool SparkMax::has_status7() const
    {
        return has_status7_;
    }

    bool SparkMax::has_status8() const
    {
        return has_status8_;
    }

    bool SparkMax::has_status9() const
    {
        return has_status9_;
    }

    bool SparkMax::hard_forward_limit_reached() const
    {
        return has_status0_ ? last_status0_.HARD_FORWARD_LIMIT_REACHED : false;
    }

    bool SparkMax::hard_reverse_limit_reached() const
    {
        return has_status0_ ? last_status0_.HARD_REVERSE_LIMIT_REACHED : false;
    }

    float SparkMax::last_applied_output() const
    {
        return has_status0_ ? (float)last_status0_.APPLIED_OUTPUT / 32767.0f : 0.0f;
    }

    float SparkMax::last_position() const
    {
        return has_status2_ ? last_status2_.PRIMARY_ENCODER_POSITION : 0.0f;
    }
} // namespace CanControl
