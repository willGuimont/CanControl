#include <unity.h>
#include "spark_can.h"
extern "C"
{
#include "../../src/spark_can.c"
}

void test_velocity_setpoint_roundtrip()
{
    Spark_VELOCITY_SETPOINT_t vals{};
    vals.SETPOINT = 1234.5f;
    vals.ARBITRARY_FEEDFORWARD = -123;
    vals.PID_SLOT = 2;
    vals.ARBITRARY_FEEDFORWARD_UNITS = 1;

    SparkCanFrame frame{};
    spark_build_VELOCITY_SETPOINT(7, &vals, &frame);

    TEST_ASSERT_EQUAL_UINT32((uint32_t)SPARK_ARB_VELOCITY_SETPOINT | 7u, frame.id);
    TEST_ASSERT_EQUAL_UINT8(8, frame.dlc);
    TEST_ASSERT_FALSE(frame.is_rtr);

    Spark_VELOCITY_SETPOINT_t out{};
    TEST_ASSERT_TRUE(spark_decode_VELOCITY_SETPOINT(frame.data, frame.dlc, &out));
    TEST_ASSERT_FLOAT_WITHIN(0.0001f, vals.SETPOINT, out.SETPOINT);
    TEST_ASSERT_EQUAL_INT16(vals.ARBITRARY_FEEDFORWARD, (int16_t)out.ARBITRARY_FEEDFORWARD);
    TEST_ASSERT_EQUAL_UINT32(vals.PID_SLOT, (uint32_t)out.PID_SLOT);
    TEST_ASSERT_EQUAL_UINT32(vals.ARBITRARY_FEEDFORWARD_UNITS, (uint32_t)out.ARBITRARY_FEEDFORWARD_UNITS);
}

void test_get_firmware_version_decode_big_endian()
{
    uint8_t buf[8] = {
        25,         // MAJOR
        1,          // MINOR
        0x12, 0x34, // BUILD (big endian)
        0xAA,       // DEBUG_BUILD
        0xBB,       // HW_REV
        0xCC, 0xDD  // RESERVED
    };
    Spark_GET_FIRMWARE_VERSION_t ver{};
    TEST_ASSERT_TRUE(spark_decode_GET_FIRMWARE_VERSION(buf, 8, &ver));
    TEST_ASSERT_EQUAL_UINT32(25, (uint32_t)ver.MAJOR);
    TEST_ASSERT_EQUAL_UINT32(1, (uint32_t)ver.MINOR);
    TEST_ASSERT_EQUAL_UINT32(0x1234, (uint32_t)ver.BUILD);
    TEST_ASSERT_EQUAL_UINT32(0xAA, (uint32_t)ver.DEBUG_BUILD);
    TEST_ASSERT_EQUAL_UINT32(0xBB, (uint32_t)ver.HW_REV);
}

void test_match_macro_device_id_mask()
{
    uint32_t id = (uint32_t)SPARK_ARB_STATUS_0 | 0x3Fu; // any device id 0..63
    TEST_ASSERT_TRUE(SPARK_MATCH_STATUS_0(id));
}
