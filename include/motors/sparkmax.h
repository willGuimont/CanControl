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
        /**
         * @brief Construct a new Spark Max object.
         *
         * @param controller Reference to the MCP2515 controller.
         * @param device_id CAN ID of the motor controller (0-63).
         */
        SparkMax(MCP2515& controller, uint8_t device_id);
        virtual ~SparkMax() = default;

        /**
         * @brief Set duty-cycle output in the range [-1, 1].
         *
         * @param duty Duty cycle value.
         * @param pid_slot PID slot index (0-3).
         * @param arbitrary_feedforward Arbitrary feedforward value.
         * @param arbitrary_feedforward_units Units for arbitrary feedforward.
         * @return MCP2515::ERROR Status of the transmission.
         */
        MCP2515::ERROR set_duty_cycle(float duty, uint8_t pid_slot = 0, int16_t arbitrary_feedforward = 0,
                                      uint8_t arbitrary_feedforward_units = 1u);

        /**
         * @brief Set position setpoint.
         *
         * @param position Target position.
         * @param pid_slot PID slot index (0-3).
         * @param arbitrary_feedforward Arbitrary feedforward value.
         * @param arbitrary_feedforward_units Units for arbitrary feedforward.
         * @return MCP2515::ERROR Status of the transmission.
         */
        MCP2515::ERROR set_position(float position, uint8_t pid_slot = 0, int16_t arbitrary_feedforward = 0,
                                    uint8_t arbitrary_feedforward_units = 0u);

        /**
         * @brief Set velocity setpoint.
         *
         * @param velocity Target velocity.
         * @param pid_slot PID slot index (0-3).
         * @param arbitrary_feedforward Arbitrary feedforward value.
         * @param arbitrary_feedforward_units Units for arbitrary feedforward.
         * @return MCP2515::ERROR Status of the transmission.
         */
        MCP2515::ERROR set_velocity(float velocity, uint8_t pid_slot = 0, int16_t arbitrary_feedforward = 0,
                                    uint8_t arbitrary_feedforward_units = 0u);

        /**
         * @brief Set Proportional Gain (P) for a PID slot.
         * @param p Gain value.
         * @param slot Slot index (0-3).
         */
        MCP2515::ERROR set_pid_p(float p, uint8_t slot = 0);

        /**
         * @brief Set Integral Gain (I) for a PID slot.
         * @param i Gain value.
         * @param slot Slot index (0-3).
         */
        MCP2515::ERROR set_pid_i(float i, uint8_t slot = 0);

        /**
         * @brief Set Derivative Gain (D) for a PID slot.
         * @param d Gain value.
         * @param slot Slot index (0-3).
         */
        MCP2515::ERROR set_pid_d(float d, uint8_t slot = 0);

        /**
         * @brief Set Feedforward Gain (F) for a PID slot.
         * @param f Gain value.
         * @param slot Slot index (0-3).
         */
        MCP2515::ERROR set_pid_f(float f, uint8_t slot = 0);

        // Motor configuration parameters

        /**
         * @brief Set the motor type.
         * @param t Motor type (Brushed/Brushless).
         */
        MCP2515::ERROR set_motor_type(LowLevel::SparkMax::MotorType t);

        /**
         * @brief Set the idle mode.
         * @param m Idle mode (Coast/Brake).
         */
        MCP2515::ERROR set_idle_mode(LowLevel::SparkMax::IdleMode m);

        /**
         * @brief Configures sensor for closed loop control.
         * @param s Sensor type.
         */
        MCP2515::ERROR set_closed_loop_control_sensor(LowLevel::SparkMax::Sensor s);

        /**
         * @brief Invert motor direction.
         * @param inverted True to invert.
         */
        MCP2515::ERROR set_inverted(bool inverted);

        // PID helper parameters (per-slot)

        /**
         * @brief Set Integral Zone (IZone).
         * @param slot Slot index (0-3).
         * @param izone IZone value.
         */
        MCP2515::ERROR set_izone(uint8_t slot, float izone);

        /**
         * @brief Set Derivative Filter (DFilter).
         * @param slot Slot index (0-3).
         * @param dfilter Filter value.
         */
        MCP2515::ERROR set_d_filter(uint8_t slot, float dfilter);

        /**
         * @brief Set minimum output power.
         * @param slot Slot index (0-3).
         * @param v Minimum output [-1, 1].
         */
        MCP2515::ERROR set_output_min(uint8_t slot, float v);

        /**
         * @brief Set maximum output power.
         * @param slot Slot index (0-3).
         * @param v Maximum output [-1, 1].
         */
        MCP2515::ERROR set_output_max(uint8_t slot, float v);

        // PID wrap settings

        /**
         * @brief Enable position PID wrapping.
         * @param en True to enable.
         */
        MCP2515::ERROR set_position_pid_wrap_enable(bool en);

        /**
         * @brief Set min input for position PID wrap.
         * @param v Min input value.
         */
        MCP2515::ERROR set_position_pid_min_input(float v);

        /**
         * @brief Set max input for position PID wrap.
         * @param v Max input value.
         */
        MCP2515::ERROR set_position_pid_max_input(float v);

        // Limit switches

        /**
         * @brief Set forward limit switch polarity.
         * @param polarity True for Normally Open (typically).
         */
        MCP2515::ERROR set_limit_switch_fwd_polarity(bool polarity);

        /**
         * @brief Set reverse limit switch polarity.
         * @param polarity True for Normally Open (typically).
         */
        MCP2515::ERROR set_limit_switch_rev_polarity(bool polarity);

        /**
         * @brief Enable/Disable forward hard limit switch.
         * @param en True to enable.
         */
        MCP2515::ERROR enable_hard_limit_fwd(bool en);

        /**
         * @brief Enable/Disable reverse hard limit switch.
         * @param en True to enable.
         */
        MCP2515::ERROR enable_hard_limit_rev(bool en);

        /**
         * @brief Enable/Disable forward soft limit.
         * @param en True to enable.
         */
        MCP2515::ERROR enable_soft_limit_fwd(bool en);

        /**
         * @brief Enable/Disable reverse soft limit.
         * @param en True to enable.
         */
        MCP2515::ERROR enable_soft_limit_rev(bool en);

        // Encoder settings

        /**
         * @brief Set encoder counts per revolution (CPR).
         * @param counts CPR value.
         */
        MCP2515::ERROR set_encoder_counts_per_rev(uint32_t counts);

        /**
         * @brief Invert encoder direction.
         * @param inv True to invert.
         */
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

      protected:
      protected:
        virtual MCP2515::ERROR dispatch_frame(const LowLevel::SparkMax::spark_can_frame& frame, bool periodic = false);

        MCP2515* controller_;
        uint8_t  device_id_;
    };
} // namespace CanControl
