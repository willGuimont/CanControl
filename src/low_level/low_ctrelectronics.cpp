#include "low_level/low_ctrelectronics.h"

namespace CanControl::LowLevel::TalonSrx
{
    namespace
    {
        constexpr int16_t TALON_OUTPUT_MAX = 1023;

        inline int32_t clamp_output(float percent_output)
        {
            if (percent_output > 1.0f)
            {
                percent_output = 1.0f;
            }
            else if (percent_output < -1.0f)
            {
                percent_output = -1.0f;
            }

            float   scaled = percent_output * static_cast<float>(TALON_OUTPUT_MAX);
            int32_t value  = static_cast<int32_t>(scaled);

            if (value > TALON_OUTPUT_MAX)
            {
                value = TALON_OUTPUT_MAX;
            }
            else if (value < -TALON_OUTPUT_MAX)
            {
                value = -TALON_OUTPUT_MAX;
            }

            return value;
        }

        inline talon_can_frame build_percent_output_common(uint8_t device_number, float percent_output,
                                                           uint32_t base_id)
        {
            const int32_t output_int = clamp_output(percent_output);

            const uint8_t first_byte  = static_cast<uint8_t>((output_int >> 16) & 0xFF);
            const uint8_t second_byte = static_cast<uint8_t>((output_int >> 8) & 0xFF);
            const uint8_t third_byte  = static_cast<uint8_t>(output_int & 0xFF);

            talon_can_frame frame{};
            frame.id     = base_id | TALON_CONTROL_ARBITRATION_ID | (static_cast<uint32_t>(device_number) & 0x3Fu);
            frame.dlc    = 8u;
            frame.is_rtr = false;

            // First three bytes are the signed 24-bit demand value, remaining bytes are zero.
            for (int i = 0; i < 8; ++i)
            {
                frame.data[i] = 0u;
            }
            frame.data[0] = first_byte;
            frame.data[1] = second_byte;
            frame.data[2] = third_byte;

            return frame;
        }
    } // namespace

    talon_can_frame talon_build_percent_output(uint8_t device_number, float percent_output)
    {
        return build_percent_output_common(device_number, percent_output, TALON_SRX_BASE_ID);
    }

    talon_can_frame victor_build_percent_output(uint8_t device_number, float percent_output)
    {
        return build_percent_output_common(device_number, percent_output, VICTOR_SPX_BASE_ID);
    }

    talon_can_frame build_global_enable(bool enable)
    {
        talon_can_frame frame{};
        frame.id     = CTRE_GLOBAL_ENABLE_ARB_ID;
        frame.dlc    = 8u;
        frame.is_rtr = false;

        for (int i = 0; i < 8; ++i)
        {
            frame.data[i] = 0u;
        }

        frame.data[0] = enable ? 1u : 0u;
        return frame;
    }
} // namespace CanControl::LowLevel::TalonSrx
