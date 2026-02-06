#pragma once

#include "low_level/low_sparkmax.h"
#include "low_level/low_sparkmax_params.h"

#include <mcp2515.h>

namespace CanControl
{
    /**
     * @brief High-level wrapper around the low-level SparkMax CAN API.
     * The motor also needs to receive a heartbeat signal (see main.cpp for an example)
     */
    class SparkMax
    {
      public:
        SparkMax(MCP2515& controller, uint8_t device_id);
        virtual ~SparkMax() = default;

        uint8_t get_device_id() const;

        /**
         * @param duty Duty cycle value.
         * @param pid_slot PID slot index (0-3).
         * @param arbitrary_feedforward Arbitrary feedforward value.
         * @param arbitrary_feedforward_units Units for arbitrary feedforward.
         * @return MCP2515::ERROR Status of the transmission.
         */
        MCP2515::ERROR set_duty_cycle(float duty, uint8_t pid_slot = 0, int16_t arbitrary_feedforward = 0,
                                      uint8_t arbitrary_feedforward_units = 1u);

        /**
         * @param position Target position.
         * @param pid_slot PID slot index (0-3).
         * @param arbitrary_feedforward Arbitrary feedforward value.
         * @param arbitrary_feedforward_units Units for arbitrary feedforward.
         * @return MCP2515::ERROR Status of the transmission.
         */
        MCP2515::ERROR set_position(float position, uint8_t pid_slot = 0, int16_t arbitrary_feedforward = 0,
                                    uint8_t arbitrary_feedforward_units = 0u);

        /**
         * @param velocity Target velocity.
         * @param pid_slot PID slot index (0-3).
         * @param arbitrary_feedforward Arbitrary feedforward value.
         * @param arbitrary_feedforward_units Units for arbitrary feedforward.
         * @return MCP2515::ERROR Status of the transmission.
         */
        MCP2515::ERROR set_velocity(float velocity, uint8_t pid_slot = 0, int16_t arbitrary_feedforward = 0,
                                    uint8_t arbitrary_feedforward_units = 0u);

        /**
         * @param slot Slot index (0-3).
         */
        MCP2515::ERROR set_pid_p(float p, uint8_t slot = 0);

        /**
         * @param slot Slot index (0-3).
         */
        MCP2515::ERROR set_pid_i(float i, uint8_t slot = 0);

        /**
         * @param slot Slot index (0-3).
         */
        MCP2515::ERROR set_pid_d(float d, uint8_t slot = 0);

        /**
         * @param slot Slot index (0-3).
         */
        MCP2515::ERROR set_pid_f(float f, uint8_t slot = 0);

        // Motor configuration parameters

        /**
         * @param t Motor type (Brushed/Brushless).
         */
        MCP2515::ERROR set_motor_type(LowLevel::SparkMax::MotorType t);

        /**
         * @param m Idle mode (Coast/Brake).
         */
        MCP2515::ERROR set_idle_mode(LowLevel::SparkMax::IdleMode m);

        MCP2515::ERROR set_closed_loop_control_sensor(LowLevel::SparkMax::Sensor s);

        /**
         * @param inverted True to invert.
         */
        MCP2515::ERROR set_inverted(bool inverted);

        // PID helper parameters (per-slot)

        /**
         * @param slot Slot index (0-3).
         */
        MCP2515::ERROR set_izone(uint8_t slot, float izone);

        /**
         * @param slot Slot index (0-3).
         */
        MCP2515::ERROR set_d_filter(uint8_t slot, float dfilter);

        /**
         * @param slot Slot index (0-3).
         * @param v Minimum output [-1, 1].
         */
        MCP2515::ERROR set_output_min(uint8_t slot, float v);

        /**
         * @param slot Slot index (0-3).
         * @param v Maximum output [-1, 1].
         */
        MCP2515::ERROR set_output_max(uint8_t slot, float v);

        // PID wrap settings

        MCP2515::ERROR set_position_pid_wrap_enable(bool en);
        MCP2515::ERROR set_position_pid_min_input(float v);
        MCP2515::ERROR set_position_pid_max_input(float v);

        // Limit switches

        /**
         * @param polarity True for Normally Open (typically).
         */
        MCP2515::ERROR set_limit_switch_fwd_polarity(bool polarity);

        /**
         * @param polarity True for Normally Open (typically).
         */
        MCP2515::ERROR set_limit_switch_rev_polarity(bool polarity);

        MCP2515::ERROR enable_hard_limit_fwd(bool en);
        MCP2515::ERROR enable_hard_limit_rev(bool en);
        MCP2515::ERROR enable_soft_limit_fwd(bool en);
        MCP2515::ERROR enable_soft_limit_rev(bool en);

        // Encoder settings

        MCP2515::ERROR set_encoder_counts_per_rev(uint32_t counts);
        MCP2515::ERROR set_encoder_inverted(bool inv);

        /**
         * @brief Convenience helper to stop the motor (zero duty cycle).
         * @return MCP2515::ERROR Status of the transmission.
         */
        MCP2515::ERROR stop();

        /**
         * @brief Reset most writable parameters to their default values, preserving
         * CAN ID, motor type, idle mode, PWM deadband, and duty-cycle offset.
         * @return MCP2515::ERROR Status of the transmission.
         */
        MCP2515::ERROR reset_safe_parameters();

        /**
         * @brief Process an incoming raw CAN frame and update internal state if it matches this Spark's device id.
         * This will decode any periodic Status frames and cache values for user queries.
         */
        void handle_received_frame(const struct can_frame& frame);

        // State accessors (return cached values; only valid if corresponding has_*() returns true)
        bool has_status0() const;
        bool has_status1() const;
        bool has_status2() const;
        bool has_status3() const;
        bool has_status4() const;
        bool has_status5() const;
        bool has_status6() const;
        bool has_status7() const;
        bool has_status8() const;
        bool has_status9() const;

        // Common convenience accessors
        bool  hard_forward_limit_reached() const;
        bool  hard_reverse_limit_reached() const;
        float last_applied_output() const;
        float last_position() const;

      protected:
        virtual MCP2515::ERROR dispatch_frame(const LowLevel::SparkMax::spark_can_frame& frame, bool periodic = false);

        MCP2515* controller_;
        uint8_t  device_id_;

        // Cached state from incoming periodic frames (Status 0..9)
        LowLevel::SparkMax::Spark_STATUS_0_t last_status0_;
        bool                                 has_status0_ = false;
        LowLevel::SparkMax::Spark_STATUS_1_t last_status1_;
        bool                                 has_status1_ = false;
        LowLevel::SparkMax::Spark_STATUS_2_t last_status2_;
        bool                                 has_status2_ = false;
        LowLevel::SparkMax::Spark_STATUS_3_t last_status3_;
        bool                                 has_status3_ = false;
        LowLevel::SparkMax::Spark_STATUS_4_t last_status4_;
        bool                                 has_status4_ = false;
        LowLevel::SparkMax::Spark_STATUS_5_t last_status5_;
        bool                                 has_status5_ = false;
        LowLevel::SparkMax::Spark_STATUS_6_t last_status6_;
        bool                                 has_status6_ = false;
        LowLevel::SparkMax::Spark_STATUS_7_t last_status7_;
        bool                                 has_status7_ = false;
        LowLevel::SparkMax::Spark_STATUS_8_t last_status8_;
        bool                                 has_status8_ = false;
        LowLevel::SparkMax::Spark_STATUS_9_t last_status9_;
        bool                                 has_status9_ = false;
    };
} // namespace CanControl
