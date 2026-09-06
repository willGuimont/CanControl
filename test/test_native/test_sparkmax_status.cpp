#include <commands.h>
#include <motors/sparkmax.h>
#include <unity.h>

using namespace CanControl;
using namespace CanControl::LowLevel::SparkMax;

static can_frame status_frame(uint8_t index, uint8_t device = 3)
{
    can_frame frame{};
    frame.can_id  = (SPARK_ARB_STATUS_0 + uint32_t(index) * 64u + device) | EFF_FLAG;
    frame.can_dlc = 8;
    return frame;
}

static void test_compact_status_preserves_all_receipt_getters()
{
    using HasStatus           = bool (SparkMax::*)() const;
    const HasStatus getters[] = {&SparkMax::has_status0, &SparkMax::has_status1, &SparkMax::has_status2,
                                 &SparkMax::has_status3, &SparkMax::has_status4, &SparkMax::has_status5,
                                 &SparkMax::has_status6, &SparkMax::has_status7, &SparkMax::has_status8,
                                 &SparkMax::has_status9};
    MCP2515         mcp;
    SparkMax        motor(mcp, 3);
    SparkMaxStatus  status{};
    for (auto getter : getters)
        TEST_ASSERT_FALSE((motor.*getter)());
    TEST_ASSERT_FALSE(motor.hard_forward_limit_reached());
    TEST_ASSERT_FALSE(motor.hard_reverse_limit_reached());
    TEST_ASSERT_EQUAL_FLOAT(0, motor.last_applied_output());
    TEST_ASSERT_EQUAL_FLOAT(0, motor.last_position());
    TEST_ASSERT_EQUAL_FLOAT(0, motor.get_encoder_position());

    for (uint8_t i = 0; i < 10; ++i)
    {
        const can_frame frame = status_frame(i);
        TEST_ASSERT_TRUE(update_sparkmax_status(status, 3, frame));
        motor.handle_received_frame(frame);
        TEST_ASSERT_EQUAL_UINT16((1u << (i + 1)) - 1, status.received_mask);
        for (uint8_t j = 0; j < 10; ++j)
            TEST_ASSERT_EQUAL(j <= i, (motor.*getters[j])());
    }
}

static void test_compact_status_keeps_values_across_other_statuses()
{
    MCP2515        mcp;
    SparkMax       motor(mcp, 3);
    SparkMaxStatus status{};
    can_frame      frame = status_frame(0);
    frame.data[0]        = 0x01; // -32767, little endian.
    frame.data[1]        = 0x80;
    frame.data[6]        = 0x01; // Forward limit only.
    TEST_ASSERT_TRUE(update_sparkmax_status(status, 3, frame));
    motor.handle_received_frame(frame);
    TEST_ASSERT_EQUAL_INT16(-32767, status.applied_output);
    TEST_ASSERT_EQUAL_FLOAT(-1.0f, motor.last_applied_output());
    TEST_ASSERT_TRUE(motor.hard_forward_limit_reached());
    TEST_ASSERT_FALSE(motor.hard_reverse_limit_reached());

    frame         = status_frame(2);
    frame.data[6] = 0x48; // Position 12.5f = 0x41480000 at bytes 4..7.
    frame.data[7] = 0x41;
    TEST_ASSERT_TRUE(update_sparkmax_status(status, 3, frame));
    motor.handle_received_frame(frame);
    TEST_ASSERT_EQUAL_FLOAT(12.5f, status.position);
    TEST_ASSERT_EQUAL_FLOAT(12.5f, motor.last_position());
    TEST_ASSERT_EQUAL_FLOAT(12.5f, motor.get_encoder_position());

    for (uint8_t i = 1; i < 10; ++i)
    {
        if (i == 2)
            continue;
        frame = status_frame(i);
        TEST_ASSERT_TRUE(update_sparkmax_status(status, 3, frame));
        motor.handle_received_frame(frame);
    }
    TEST_ASSERT_EQUAL_FLOAT(-1.0f, motor.last_applied_output());
    TEST_ASSERT_TRUE(motor.hard_forward_limit_reached());
    TEST_ASSERT_EQUAL_FLOAT(12.5f, motor.last_position());
    frame         = status_frame(0);
    frame.data[0] = 0xff;
    frame.data[1] = 0x7f;
    frame.data[6] = 0x02; // Reverse limit only; forward must clear.
    TEST_ASSERT_TRUE(update_sparkmax_status(status, 3, frame));
    motor.handle_received_frame(frame);
    TEST_ASSERT_EQUAL_FLOAT(1.0f, motor.last_applied_output());
    TEST_ASSERT_FALSE(motor.hard_forward_limit_reached());
    TEST_ASSERT_TRUE(motor.hard_reverse_limit_reached());
    TEST_ASSERT_EQUAL_FLOAT(12.5f, motor.last_position());
}

static void test_compact_status_rejects_unrelated_and_short_frames()
{
    MCP2515        mcp;
    SparkMax       motor(mcp, 3);
    SparkMaxStatus status{};
    for (uint8_t i = 0; i < 10; ++i)
    {
        can_frame frame = status_frame(i, 4); // Different motor.
        TEST_ASSERT_FALSE(update_sparkmax_status(status, 3, frame));
        motor.handle_received_frame(frame);
        frame = status_frame(i);
        for (uint8_t dlc = 0; dlc < 8; ++dlc)
        {
            frame.can_dlc = dlc;
            TEST_ASSERT_FALSE(update_sparkmax_status(status, 3, frame));
            motor.handle_received_frame(frame);
        }
    }
    can_frame frame = status_frame(10); // Unknown status.
    TEST_ASSERT_FALSE(update_sparkmax_status(status, 3, frame));
    motor.handle_received_frame(frame);
    TEST_ASSERT_EQUAL_UINT16(0, status.received_mask);
    TEST_ASSERT_FALSE(motor.has_status0());
    TEST_ASSERT_FALSE(motor.has_status9());
    TEST_ASSERT_EQUAL_FLOAT(0, motor.last_position());

    frame         = status_frame(2);
    frame.data[6] = 0x48;
    frame.data[7] = 0x41;
    TEST_ASSERT_TRUE(update_sparkmax_status(status, 3, frame));
    motor.handle_received_frame(frame);
    frame         = status_frame(2);
    frame.can_dlc = 7;
    TEST_ASSERT_FALSE(update_sparkmax_status(status, 3, frame));
    motor.handle_received_frame(frame);
    TEST_ASSERT_EQUAL_FLOAT(12.5f, status.position);
    TEST_ASSERT_EQUAL_FLOAT(12.5f, motor.last_position());
}

void run_sparkmax_status_tests()
{
    RUN_TEST(test_compact_status_preserves_all_receipt_getters);
    RUN_TEST(test_compact_status_keeps_values_across_other_statuses);
    RUN_TEST(test_compact_status_rejects_unrelated_and_short_frames);
}
