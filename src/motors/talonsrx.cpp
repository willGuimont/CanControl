#include "motors/talonsrx.h"

namespace CanControl
{
    using namespace LowLevel;
    using namespace LowLevel::TalonSrx;

    /**
     * @brief Construct a new Talon Srx Motor object
     *
     * @param controller Reference to the MCP2515 controller
     * @param device_id CAN ID of the motor controller (0-63)
     */
    TalonSrxMotor::TalonSrxMotor(MCP2515& controller, uint8_t device_id)
        : controller_(&controller), device_id_(device_id)
    {
    }

    void TalonSrxMotor::set_controller(MCP2515& controller)
    {
        controller_ = &controller;
    }

    void TalonSrxMotor::set_device_id(uint8_t device_id)
    {
        device_id_ = device_id;
    }

    MCP2515* TalonSrxMotor::controller() const
    {
        return controller_;
    }

    uint8_t TalonSrxMotor::device_id() const
    {
        return device_id_;
    }

    /**
     * @brief Sets the percent output of the motor.
     *
     * @param percent_output The duty cycle to set, from -1.0 to 1.0.
     *                       Values outside this range will be clamped by the controller (or should be clamped here).
     * @return MCP2515::ERROR Status of the CAN transmission.
     */
    MCP2515::ERROR TalonSrxMotor::set_percent_output(float percent_output)
    {
        if (controller_ == nullptr)
        {
            return MCP2515::ERROR_FAILINIT;
        }

        talon_can_frame low = talon_build_percent_output(device_id_, percent_output);

        can_frame hw{};
        basic_to_can_frame(low, &hw);

        return controller_->sendMessage(&hw);
    }

    /**
     * @brief Sends the Global Enable frame required for CTRE motors (Talon SRX / Victor SPX) to operate.
     *
     * @param controller Reference to the MCP2515 controller.
     * @param enable True to enable the motors, false to disable.
     * @return MCP2515::ERROR Status of the CAN transmission.
     */
    MCP2515::ERROR TalonSrxMotor::send_global_enable(MCP2515& controller, bool enable)
    {
        talon_can_frame low = build_global_enable(enable);

        can_frame hw{};
        basic_to_can_frame(low, &hw);
        return controller.sendMessage(&hw);
    }

} // namespace CanControl
