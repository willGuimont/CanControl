#include "motors/talonsrx.h"

namespace CanControl
{
    /**
     * @brief Construct a new Talon Srx Motor object
     *
     * @param controller Reference to the MCP2515 controller
     * @param device_id CAN ID of the motor controller (0-63)
     */
    TalonSrx::TalonSrx(MCP2515& controller, uint8_t device_id) : controller_(&controller), device_id_(device_id) {}

    /**
     * @brief Sets the percent output of the motor.
     *
     * @param percent_output The duty cycle to set, from -1.0 to 1.0.
     *                       Values outside this range will be clamped by the controller (or should be clamped here).
     * @return MCP2515::ERROR Status of the CAN transmission.
     */
    MCP2515::ERROR TalonSrx::set_percent_output(float percent_output)
    {
        LowLevel::TalonSrx::talon_can_frame low =
            LowLevel::TalonSrx::talon_build_percent_output(device_id_, percent_output);

        can_frame hw{};
        LowLevel::basic_to_can_frame(low, &hw);

        return dispatch_frame(hw, true);
    }

    MCP2515::ERROR TalonSrx::dispatch_frame(const can_frame& frame, bool periodic)
    {
        if (controller_ == nullptr)
        {
            return MCP2515::ERROR_FAILINIT;
        }
        return controller_->sendMessage(&frame);
    }

    /**
     * @brief Sends the Global Enable frame required for CTRE motors (Talon SRX / Victor SPX) to operate.
     *
     * @param controller Reference to the MCP2515 controller.
     * @param enable True to enable the motors, false to disable.
     * @return MCP2515::ERROR Status of the CAN transmission.
     */
    MCP2515::ERROR TalonSrx::send_global_enable(MCP2515& controller, bool enable)
    {
        LowLevel::TalonSrx::talon_can_frame low = LowLevel::TalonSrx::build_global_enable(enable);

        can_frame hw{};
        LowLevel::basic_to_can_frame(low, &hw);
        return controller.sendMessage(&hw);
    }

} // namespace CanControl
