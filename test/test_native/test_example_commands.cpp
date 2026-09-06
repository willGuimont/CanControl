#include <example_commands.h>
#include <unity.h>

using namespace CanControl;

static void test_command_tagged_union_properties()
{
    Command cmd;
    TEST_ASSERT_FALSE(cmd.is_valid());
    TEST_ASSERT_EQUAL(static_cast<int>(Command::Type::Invalid), static_cast<int>(cmd.type));
    TEST_ASSERT_EQUAL_UINT8(0, cmd.target_id);
    TEST_ASSERT_EQUAL_FLOAT(0.0f, cmd.value);

    // Speed and DutyCycle are identical
    TEST_ASSERT_EQUAL(static_cast<int>(Command::Type::DutyCycle), static_cast<int>(Command::Type::Speed));

    // Payloads in union map to the same memory
    cmd.type       = Command::Type::DutyCycle;
    cmd.duty_cycle = 0.75f;
    TEST_ASSERT_EQUAL_FLOAT(0.75f, cmd.value);
    TEST_ASSERT_EQUAL_FLOAT(0.75f, cmd.speed);
    TEST_ASSERT_EQUAL_FLOAT(0.75f, cmd.duty_cycle);
    TEST_ASSERT_EQUAL_FLOAT(0.75f, cmd.position);

    cmd.position = -42.5f;
    TEST_ASSERT_EQUAL_FLOAT(-42.5f, cmd.value);
    TEST_ASSERT_EQUAL_FLOAT(-42.5f, cmd.position);
}

static void test_parse_help_and_stop_and_homing()
{
    // Help
    Command cmd = parse_command("h", false);
    TEST_ASSERT_TRUE(cmd.is_valid());
    TEST_ASSERT_EQUAL(static_cast<int>(Command::Type::Help), static_cast<int>(cmd.type));
    TEST_ASSERT_EQUAL_UINT8(0, cmd.target_id);

    // Stop (all motors)
    cmd = parse_command("x", false);
    TEST_ASSERT_TRUE(cmd.is_valid());
    TEST_ASSERT_EQUAL(static_cast<int>(Command::Type::Stop), static_cast<int>(cmd.type));
    TEST_ASSERT_EQUAL_UINT8(0, cmd.target_id);
    TEST_ASSERT_EQUAL_FLOAT(0.0f, cmd.value);

    // Stop with motor id
    cmd = parse_command("3x", false);
    TEST_ASSERT_TRUE(cmd.is_valid());
    TEST_ASSERT_EQUAL(static_cast<int>(Command::Type::Stop), static_cast<int>(cmd.type));
    TEST_ASSERT_EQUAL_UINT8(3, cmd.target_id);

    // Homing start
    cmd = parse_command("z", false);
    TEST_ASSERT_TRUE(cmd.is_valid());
    TEST_ASSERT_EQUAL(static_cast<int>(Command::Type::HomingStart), static_cast<int>(cmd.type));

    // Homing cancel
    cmd = parse_command("c", false);
    TEST_ASSERT_TRUE(cmd.is_valid());
    TEST_ASSERT_EQUAL(static_cast<int>(Command::Type::HomingCancel), static_cast<int>(cmd.type));
}

static void test_parse_duty_cycle_and_speed()
{
    // Duty cycle without motor ID
    Command cmd = parse_command("s0.25", false);
    TEST_ASSERT_TRUE(cmd.is_valid());
    TEST_ASSERT_EQUAL(static_cast<int>(Command::Type::DutyCycle), static_cast<int>(cmd.type));
    TEST_ASSERT_EQUAL_UINT8(0, cmd.target_id);
    TEST_ASSERT_EQUAL_FLOAT(0.25f, cmd.speed);

    // Negative duty cycle
    cmd = parse_command("s-0.5", false);
    TEST_ASSERT_TRUE(cmd.is_valid());
    TEST_ASSERT_EQUAL_FLOAT(-0.5f, cmd.duty_cycle);

    // Clamping to [-1.0, 1.0]
    cmd = parse_command("s2.5", false);
    TEST_ASSERT_TRUE(cmd.is_valid());
    TEST_ASSERT_EQUAL_FLOAT(1.0f, cmd.duty_cycle);

    cmd = parse_command("s-3.0", false);
    TEST_ASSERT_TRUE(cmd.is_valid());
    TEST_ASSERT_EQUAL_FLOAT(-1.0f, cmd.duty_cycle);

    // Leading motor ID
    cmd = parse_command("2s0.8", false);
    TEST_ASSERT_TRUE(cmd.is_valid());
    TEST_ASSERT_EQUAL_UINT8(2, cmd.target_id);
    TEST_ASSERT_EQUAL_FLOAT(0.8f, cmd.duty_cycle);

    // Spacing
    cmd = parse_command("  4  s  -0.125  ", false);
    TEST_ASSERT_TRUE(cmd.is_valid());
    TEST_ASSERT_EQUAL_UINT8(4, cmd.target_id);
    TEST_ASSERT_EQUAL_FLOAT(-0.125f, cmd.duty_cycle);
}

static void test_parse_position()
{
    // Position without motor ID
    Command cmd = parse_command("p12.5", false);
    TEST_ASSERT_TRUE(cmd.is_valid());
    TEST_ASSERT_EQUAL(static_cast<int>(Command::Type::Position), static_cast<int>(cmd.type));
    TEST_ASSERT_EQUAL_UINT8(0, cmd.target_id);
    TEST_ASSERT_EQUAL_FLOAT(12.5f, cmd.position);

    // Position with motor ID and negative value
    cmd = parse_command("3p-100.25", false);
    TEST_ASSERT_TRUE(cmd.is_valid());
    TEST_ASSERT_EQUAL_UINT8(3, cmd.target_id);
    TEST_ASSERT_EQUAL_FLOAT(-100.25f, cmd.position);
}

static void test_parse_invalid_inputs()
{
    // Null pointer
    Command cmd = parse_command(nullptr, false);
    TEST_ASSERT_FALSE(cmd.is_valid());

    // Empty string
    cmd = parse_command("", false);
    TEST_ASSERT_FALSE(cmd.is_valid());

    // Whitespace only
    cmd = parse_command("   \t  ", false);
    TEST_ASSERT_FALSE(cmd.is_valid());

    // Unknown command
    cmd = parse_command("hello", false);
    TEST_ASSERT_FALSE(cmd.is_valid());

    // Missing number
    cmd = parse_command("s", false);
    TEST_ASSERT_FALSE(cmd.is_valid());

    cmd = parse_command("p", false);
    TEST_ASSERT_FALSE(cmd.is_valid());

    // Non-numeric
    cmd = parse_command("sabc", false);
    TEST_ASSERT_FALSE(cmd.is_valid());

    // Trailing non-numeric garbage
    cmd = parse_command("s0.5xyz", false);
    TEST_ASSERT_FALSE(cmd.is_valid());
}

void run_example_commands_tests()
{
    RUN_TEST(test_command_tagged_union_properties);
    RUN_TEST(test_parse_help_and_stop_and_homing);
    RUN_TEST(test_parse_duty_cycle_and_speed);
    RUN_TEST(test_parse_position);
    RUN_TEST(test_parse_invalid_inputs);
}
