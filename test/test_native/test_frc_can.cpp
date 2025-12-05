#include <unity.h>
#include <frc_can.h>

using namespace CanControl;

static const uint32_t device_type = 2;
static const uint32_t manufacturer_code = 8;
static const uint32_t api_class = 1;
static const uint32_t api_index = 0;
static const uint32_t device_number = 3;

static uint32_t make_raw_id()
{
    return ((device_type & 0x1F) << 24) |
           ((manufacturer_code & 0xFF) << 16) |
           ((api_class & 0x3F) << 10) |
           ((api_index & 0x0F) << 6) |
           ((device_number & 0x3F) << 0);
}

void test_frc_can_id_fields_from_raw()
{
    uint32_t raw = make_raw_id();

    frc_can_id id{};
    id.raw = raw;

    TEST_ASSERT_EQUAL_UINT32(raw & 0x1FFFFFFFu, id.frc_id());
    TEST_ASSERT_EQUAL_UINT32(device_number, id.device_number());
    TEST_ASSERT_EQUAL_UINT32(api_index, id.api_index());
    TEST_ASSERT_EQUAL_UINT32(api_class, id.api_class());
    TEST_ASSERT_EQUAL_UINT32(manufacturer_code, id.manufacturer_code());
    TEST_ASSERT_EQUAL_UINT32(device_type, id.device_type());

    TEST_ASSERT_FALSE(id.flag_err());
    TEST_ASSERT_FALSE(id.flag_rtr());
    TEST_ASSERT_FALSE(id.flag_eff());
}

void test_frc_can_id_flags()
{
    uint32_t base = make_raw_id();

    frc_can_id id_err{};
    id_err.raw = base | ERR_FLAG;

    frc_can_id id_rtr{};
    id_rtr.raw = base | RTR_FLAG;

    frc_can_id id_eff{};
    id_eff.raw = base | EFF_FLAG;

    TEST_ASSERT_TRUE(id_err.flag_err());
    TEST_ASSERT_FALSE(id_err.flag_rtr());
    TEST_ASSERT_FALSE(id_err.flag_eff());

    TEST_ASSERT_FALSE(id_rtr.flag_err());
    TEST_ASSERT_TRUE(id_rtr.flag_rtr());
    TEST_ASSERT_FALSE(id_rtr.flag_eff());

    TEST_ASSERT_FALSE(id_eff.flag_err());
    TEST_ASSERT_FALSE(id_eff.flag_rtr());
    TEST_ASSERT_TRUE(id_eff.flag_eff());
}

void test_can_id_example() {
    frc_can_id id{};
    id.raw = 0b00010000000100000010000000100;

    TEST_ASSERT_EQUAL_UINT32(2, id.device_type());
    TEST_ASSERT_EQUAL_UINT32(2, id.manufacturer_code());
    TEST_ASSERT_EQUAL_UINT32(1, id.api_class());
    TEST_ASSERT_EQUAL_UINT32(1, id.api_index());
    TEST_ASSERT_EQUAL_UINT32(4, id.device_number());
}

int main(int argc, char **argv)
{
    UNITY_BEGIN();

    RUN_TEST(test_frc_can_id_fields_from_raw);
    RUN_TEST(test_frc_can_id_flags);

    return UNITY_END();
}
