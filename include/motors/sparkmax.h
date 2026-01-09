#pragma once

#include "low_level/low_sparkmax.h"
#include "low_level/low_sparkmax_params.h"

#include <mcp2515.h>

namespace CanControl
{
    // High-level wrapper around the low-level SparkMax CAN API.
    // The motor also needs to receive a heartbeat signal (see main.cpp for an example)
    class SparkMax
    {
      public:
        // Construct a motor wrapper bound to a specific MCP2515 controller
        // and Spark device ID.
        SparkMax(MCP2515& controller, uint8_t device_id);

        // Change the bound controller or device id after construction.
        void set_controller(MCP2515& controller);
        void set_device_id(uint8_t device_id);

        MCP2515* controller() const;
        uint8_t  device_id() const;

        // Set duty-cycle output in the range [-1, 1].
        MCP2515::ERROR set_duty_cycle(float duty, uint8_t pid_slot = 0, int16_t arbitrary_feedforward = 0,
                                      uint8_t arbitrary_feedforward_units = 1u);

        // Set position setpoint (units are whatever the Spark is configured for).
        MCP2515::ERROR set_position(float position, uint8_t pid_slot = 0, int16_t arbitrary_feedforward = 0,
                                    uint8_t arbitrary_feedforward_units = 0u);

        // Set velocity setpoint (units are whatever the Spark is configured for).
        MCP2515::ERROR set_velocity(float velocity, uint8_t pid_slot = 0, int16_t arbitrary_feedforward = 0,
                                    uint8_t arbitrary_feedforward_units = 0u);

        // Set individual PID coefficients for specified PID slot (slot 0..3)
        MCP2515::ERROR set_pid_p(float p, uint8_t slot = 0);
        MCP2515::ERROR set_pid_i(float i, uint8_t slot = 0);
        MCP2515::ERROR set_pid_d(float d, uint8_t slot = 0);
        MCP2515::ERROR set_pid_f(float f, uint8_t slot = 0);

        // Motor configuration parameters
        MCP2515::ERROR set_motor_type(LowLevel::SparkMax::MotorType t);
        MCP2515::ERROR set_closed_loop_control_sensor(LowLevel::SparkMax::Sensor s);
        MCP2515::ERROR set_inverted(bool inverted);

        // PID helper parameters (per-slot)
        MCP2515::ERROR set_izone(uint8_t slot, float izone);
        MCP2515::ERROR set_d_filter(uint8_t slot, float dfilter);
        MCP2515::ERROR set_output_min(uint8_t slot, float v);
        MCP2515::ERROR set_output_max(uint8_t slot, float v);

        // PID wrap settings
        MCP2515::ERROR set_position_pid_wrap_enable(bool en);
        MCP2515::ERROR set_position_pid_min_input(float v);
        MCP2515::ERROR set_position_pid_max_input(float v);

        // Limit switches
        MCP2515::ERROR set_limit_switch_fwd_polarity(bool polarity);
        MCP2515::ERROR set_limit_switch_rev_polarity(bool polarity);
        MCP2515::ERROR enable_hard_limit_fwd(bool en);
        MCP2515::ERROR enable_hard_limit_rev(bool en);
        MCP2515::ERROR enable_soft_limit_fwd(bool en);
        MCP2515::ERROR enable_soft_limit_rev(bool en);

        // Encoder settings
        MCP2515::ERROR set_encoder_counts_per_rev(uint32_t counts);
        MCP2515::ERROR set_encoder_inverted(bool inv);

        // Convenience helper to stop the motor (zero duty cycle).
        MCP2515::ERROR stop();

        // Reset most writable parameters to their default values, preserving
        // CAN ID, motor type, idle mode, PWM deadband, and duty-cycle offset.
        MCP2515::ERROR reset_safe_parameters();

      private:
        CanControl::LowLevel::SparkMax::SparkCanDevice device_;
    };
} // namespace CanControl
