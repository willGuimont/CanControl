#include <unity.h>

void test_velocity_setpoint_roundtrip();
void test_get_firmware_version_decode_big_endian();
void test_match_macro_device_id_mask();

int main(int, char**) {
    UNITY_BEGIN();
    RUN_TEST(test_velocity_setpoint_roundtrip);
    RUN_TEST(test_get_firmware_version_decode_big_endian);
    RUN_TEST(test_match_macro_device_id_mask);
    return UNITY_END();
}
