#include <Arduino.h>
#include <unity.h>

void test_trivial() {
    TEST_ASSERT_TRUE(1 == 1);
}

void setUp() {}
void tearDown() {}

void setup() {
    delay(2000);
    UNITY_BEGIN();
    RUN_TEST(test_trivial);
    UNITY_END();
}

void loop() {}
