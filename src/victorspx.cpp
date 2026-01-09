#include "motors/victorspx.h"

namespace CanControl
{
    using namespace LowLevel;
    using namespace LowLevel::TalonSrx;

    VictorSpxMotor::VictorSpxMotor(MCP2515& controller, uint8_t device_id)
        : controller_(&controller), device_id_(device_id)
    {
    }

    void VictorSpxMotor::set_controller(MCP2515& controller)
    {
        controller_ = &controller;
    }

    void VictorSpxMotor::set_device_id(uint8_t device_id)
    {
        device_id_ = device_id;
    }

    MCP2515* VictorSpxMotor::controller() const
    {
        return controller_;
    }

    uint8_t VictorSpxMotor::device_id() const
    {
        return device_id_;
    }

    MCP2515::ERROR VictorSpxMotor::set_percent_output(float percent_output)
    {
        if (controller_ == nullptr)
        {
            return MCP2515::ERROR_FAILINIT;
        }

        talon_can_frame low = victor_build_percent_output(device_id_, percent_output);

        can_frame hw{};
        basic_to_can_frame(low, &hw);

        return controller_->sendMessage(&hw);
    }

    MCP2515::ERROR VictorSpxMotor::send_global_enable(MCP2515& controller, bool enable)
    {
        talon_can_frame low = build_global_enable(enable);

        can_frame hw{};
        basic_to_can_frame(low, &hw);
        return controller.sendMessage(&hw);
    }
} // namespace CanControl
