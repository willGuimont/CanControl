#include "motors/victorspx.h"

namespace CanControl
{
    using namespace LowLevel;
    using namespace LowLevel::TalonSrx;

    VictorSpx::VictorSpx(MCP2515& controller, uint8_t device_id) : controller_(&controller), device_id_(device_id) {}

    uint8_t VictorSpx::get_device_id() const
    {
        return device_id_;
    }

    MCP2515::ERROR VictorSpx::set_percent_output(float percent_output)
    {
        talon_can_frame low = victor_build_percent_output(device_id_, percent_output);

        can_frame hw{};
        basic_to_can_frame(low, &hw);

        return dispatch_frame(hw, true);
    }

    MCP2515::ERROR VictorSpx::dispatch_frame(const can_frame& frame, bool periodic)
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
    MCP2515::ERROR VictorSpx::send_global_enable(MCP2515& controller, bool enable)
    {
        talon_can_frame low = build_global_enable(enable);

        can_frame hw{};
        basic_to_can_frame(low, &hw);
        return controller.sendMessage(&hw);
    }
} // namespace CanControl
