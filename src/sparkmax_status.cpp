#include "sparkmax_status.h"

#include "low_level/low_sparkmax.h"

namespace CanControl
{
    bool update_sparkmax_status(SparkMaxStatus& status, uint8_t device_id, const can_frame& frame)
    {
        using namespace CanControl::LowLevel::SparkMax;
        using CanControl::LowLevel::basic_can_frame;

        basic_can_frame bf{};
        // Mask off MCP2515 flags and extract 29-bit id
        bf.id     = (uint32_t)(frame.can_id & CanControl::frc_can_id::MASK_frc_id);
        bf.dlc    = frame.can_dlc > CLASSIC_CAN_MAX_DLC ? CLASSIC_CAN_MAX_DLC : frame.can_dlc;
        bf.is_rtr = (frame.can_id & RTR_FLAG) != 0;
        if (bf.dlc > 0)
            memcpy(bf.data, frame.data, bf.dlc);

        // Ensure this message is for our device id by checking the device id field
        uint8_t msg_device = (uint8_t)(bf.id & SPARK_DEVICE_ID_MASK);
        if (msg_device != device_id)
            return false;

        // Now match and decode known status frames
        if (SPARK_MATCH_STATUS_0(bf.id))
        {
            Spark_STATUS_0_t st{};
            if (spark_decode_STATUS_0_frame(bf, &st))
            {
                status.applied_output     = st.APPLIED_OUTPUT;
                status.hard_forward_limit = st.HARD_FORWARD_LIMIT_REACHED;
                status.hard_reverse_limit = st.HARD_REVERSE_LIMIT_REACHED;
                status.received_mask |= uint16_t(1u << 0);
                return true;
            }
        }
        if (SPARK_MATCH_STATUS_1(bf.id))
        {
            Spark_STATUS_1_t st1{};
            if (spark_decode_STATUS_1_frame(bf, &st1))
            {
                status.received_mask |= uint16_t(1u << 1);
                return true;
            }
        }

        if (SPARK_MATCH_STATUS_2(bf.id))
        {
            Spark_STATUS_2_t st2{};
            if (spark_decode_STATUS_2_frame(bf, &st2))
            {
                status.position = st2.PRIMARY_ENCODER_POSITION;
                status.received_mask |= uint16_t(1u << 2);
                return true;
            }
        }

        if (SPARK_MATCH_STATUS_3(bf.id))
        {
            Spark_STATUS_3_t st3{};
            if (spark_decode_STATUS_3_frame(bf, &st3))
            {
                status.received_mask |= uint16_t(1u << 3);
                return true;
            }
        }

        if (SPARK_MATCH_STATUS_4(bf.id))
        {
            Spark_STATUS_4_t st4{};
            if (spark_decode_STATUS_4_frame(bf, &st4))
            {
                status.received_mask |= uint16_t(1u << 4);
                return true;
            }
        }

        if (SPARK_MATCH_STATUS_5(bf.id))
        {
            Spark_STATUS_5_t st5{};
            if (spark_decode_STATUS_5_frame(bf, &st5))
            {
                status.received_mask |= uint16_t(1u << 5);
                return true;
            }
        }

        if (SPARK_MATCH_STATUS_6(bf.id))
        {
            Spark_STATUS_6_t st6{};
            if (spark_decode_STATUS_6_frame(bf, &st6))
            {
                status.received_mask |= uint16_t(1u << 6);
                return true;
            }
        }

        if (SPARK_MATCH_STATUS_7(bf.id))
        {
            Spark_STATUS_7_t st7{};
            if (spark_decode_STATUS_7_frame(bf, &st7))
            {
                status.received_mask |= uint16_t(1u << 7);
                return true;
            }
        }

        if (SPARK_MATCH_STATUS_8(bf.id))
        {
            Spark_STATUS_8_t st8{};
            if (spark_decode_STATUS_8_frame(bf, &st8))
            {
                status.received_mask |= uint16_t(1u << 8);
                return true;
            }
        }

        if (SPARK_MATCH_STATUS_9(bf.id))
        {
            Spark_STATUS_9_t st9{};
            if (spark_decode_STATUS_9_frame(bf, &st9))
            {
                status.received_mask |= uint16_t(1u << 9);
                return true;
            }
        }
        return false;
    }
} // namespace CanControl
