#include <Arduino.h>
#include <unity.h>
#include "spark_can.h"

static void test_velocity_roundtrip_embedded() {
    Spark_VELOCITY_SETPOINT_t in{};
    in.SETPOINT = -321.25f;
    in.ARBITRARY_FEEDFORWARD = 42;
    in.PID_SLOT = 3;
    in.ARBITRARY_FEEDFORWARD_UNITS = 0;
    SparkCanFrame fr{};
    spark_build_VELOCITY_SETPOINT(5, &in, &fr);
    Spark_VELOCITY_SETPOINT_t out{};
    TEST_ASSERT_TRUE(spark_decode_VELOCITY_SETPOINT(fr.data, fr.dlc, &out));
    TEST_ASSERT_FLOAT_WITHIN(0.0001f, in.SETPOINT, out.SETPOINT);
    TEST_ASSERT_EQUAL_INT16(in.ARBITRARY_FEEDFORWARD, (int16_t)out.ARBITRARY_FEEDFORWARD);
}

void setUp() {}
void tearDown() {}

void setup() {
    delay(2000);
    UNITY_BEGIN();
    RUN_TEST(test_velocity_roundtrip_embedded);
    UNITY_END();
}

void loop() {}
