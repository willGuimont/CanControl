#include <commands.h>
#include <initializer_list>
#include <motors/sparkmax.h>
#include <motors/talonsrx.h>
#include <motors/victorspx.h>
#include <unity.h>

using namespace CanControl;
namespace SparkCommands = CanControl::Commands::SparkMax;

static void equal_frame(const can_frame& expected, const can_frame& actual)
{
    TEST_ASSERT_EQUAL_UINT32(expected.can_id, actual.can_id);
    TEST_ASSERT_EQUAL_UINT8(expected.can_dlc, actual.can_dlc);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(expected.data, actual.data, expected.can_dlc);
}

static void test_commands_match_spark_class()
{
    MCP2515  direct;
    MCP2515  object;
    SparkMax motor(object, 3);
    TEST_ASSERT_EQUAL(MCP2515::ERROR_OK, SparkCommands::set_duty_cycle(direct, 3, -0.25f, 2, -123, 1));
    TEST_ASSERT_EQUAL(MCP2515::ERROR_OK, motor.set_duty_cycle(-0.25f, 2, -123, 1));
    equal_frame(object.last_frame, direct.last_frame);
    TEST_ASSERT_EQUAL(MCP2515::ERROR_OK, SparkCommands::set_position(direct, 3, 12.5f, 1, 17, 0));
    TEST_ASSERT_EQUAL(MCP2515::ERROR_OK, motor.set_position(12.5f, 1, 17, 0));
    equal_frame(object.last_frame, direct.last_frame);
    TEST_ASSERT_EQUAL(MCP2515::ERROR_OK, SparkCommands::set_velocity(direct, 3, -2400.0f, 3, 23, 1));
    TEST_ASSERT_EQUAL(MCP2515::ERROR_OK, motor.set_velocity(-2400.0f, 3, 23, 1));
    equal_frame(object.last_frame, direct.last_frame);
    TEST_ASSERT_EQUAL(MCP2515::ERROR_OK, SparkCommands::stop(direct, 3));
    TEST_ASSERT_EQUAL(MCP2515::ERROR_OK, motor.stop());
    equal_frame(object.last_frame, direct.last_frame);
    TEST_ASSERT_EQUAL(MCP2515::ERROR_OK, SparkCommands::reset_safe_parameters(direct, 3));
    TEST_ASSERT_EQUAL(MCP2515::ERROR_OK, motor.reset_safe_parameters());
    equal_frame(object.last_frame, direct.last_frame);
    TEST_ASSERT_EQUAL(MCP2515::ERROR_OK, SparkCommands::set_primary_encoder_position(direct, 3, -12.5f));
    TEST_ASSERT_EQUAL(MCP2515::ERROR_OK, motor.set_primary_encoder_position(-12.5f));
    equal_frame(object.last_frame, direct.last_frame);
}

static void test_commands_encode_setpoint_defaults_and_clamping()
{
    using namespace LowLevel::SparkMax;
    MCP2515 mcp;
    for (float value : {-2.0f, -0.25f, 0.0f, 0.5f, 2.0f})
    {
        TEST_ASSERT_EQUAL(MCP2515::ERROR_OK, SparkCommands::set_duty_cycle(mcp, 7, value));
        const float                 clamped = value < -1 ? -1 : value > 1 ? 1 : value;
        Spark_DUTY_CYCLE_SETPOINT_t expected{};
        expected.SETPOINT                    = clamped;
        expected.ARBITRARY_FEEDFORWARD_UNITS = 1;
        equal_frame(Commands::to_can_frame(spark_build_DUTY_CYCLE_SETPOINT(7, &expected)), mcp.last_frame);
    }
    Spark_POSITION_SETPOINT_t position{};
    position.SETPOINT = 42.5f;
    TEST_ASSERT_EQUAL(MCP2515::ERROR_OK, SparkCommands::set_position(mcp, 7, 42.5f));
    equal_frame(Commands::to_can_frame(spark_build_POSITION_SETPOINT(7, &position)), mcp.last_frame);
    Spark_VELOCITY_SETPOINT_t velocity{};
    velocity.SETPOINT = -100.0f;
    TEST_ASSERT_EQUAL(MCP2515::ERROR_OK, SparkCommands::set_velocity(mcp, 7, -100.0f));
    equal_frame(Commands::to_can_frame(spark_build_VELOCITY_SETPOINT(7, &velocity)), mcp.last_frame);
}

static void test_commands_configuration_and_pid_slots()
{
    MCP2515  direct;
    MCP2515  object;
    SparkMax motor(object, 4);
    for (uint8_t slot = 0; slot < 4; ++slot)
    {
        TEST_ASSERT_EQUAL(MCP2515::ERROR_OK, SparkCommands::set_pid_p(direct, 4, 0.125f, slot));
        TEST_ASSERT_EQUAL(MCP2515::ERROR_OK, motor.set_pid_p(0.125f, slot));
        equal_frame(object.last_frame, direct.last_frame);
        TEST_ASSERT_EQUAL(MCP2515::ERROR_OK, SparkCommands::set_pid_i(direct, 4, 0.25f, slot));
        TEST_ASSERT_EQUAL(MCP2515::ERROR_OK, motor.set_pid_i(0.25f, slot));
        equal_frame(object.last_frame, direct.last_frame);
        TEST_ASSERT_EQUAL(MCP2515::ERROR_OK, SparkCommands::set_pid_d(direct, 4, 0.5f, slot));
        TEST_ASSERT_EQUAL(MCP2515::ERROR_OK, motor.set_pid_d(0.5f, slot));
        equal_frame(object.last_frame, direct.last_frame);
        TEST_ASSERT_EQUAL(MCP2515::ERROR_OK, SparkCommands::set_pid_f(direct, 4, -1.0f, slot));
        TEST_ASSERT_EQUAL(MCP2515::ERROR_OK, motor.set_pid_f(-1.0f, slot));
        equal_frame(object.last_frame, direct.last_frame);
    }
    const unsigned attempts = direct.send_attempts;
    TEST_ASSERT_EQUAL(MCP2515::ERROR_FAIL, SparkCommands::set_pid_p(direct, 4, 1.0f, 4));
    TEST_ASSERT_EQUAL(MCP2515::ERROR_FAIL, SparkCommands::set_pid_i(direct, 4, 1.0f, 255));
    TEST_ASSERT_EQUAL(MCP2515::ERROR_FAIL, SparkCommands::set_pid_d(direct, 4, 1.0f, 4));
    TEST_ASSERT_EQUAL(MCP2515::ERROR_FAIL, SparkCommands::set_pid_f(direct, 4, 1.0f, 255));
    TEST_ASSERT_EQUAL_UINT(attempts, direct.send_attempts);

    TEST_ASSERT_EQUAL(MCP2515::ERROR_OK, SparkCommands::set_parameter(direct, 4, 45, uint32_t(123456)));
    equal_frame(Commands::to_can_frame(SparkCommands::build_parameter(4, 45, 123456)), direct.last_frame);
    TEST_ASSERT_EQUAL(MCP2515::ERROR_OK, SparkCommands::set_parameter(direct, 4, 45, int32_t(-1)));
    equal_frame(Commands::to_can_frame(SparkCommands::build_parameter(4, 45, 0xffffffffUL)), direct.last_frame);
    TEST_ASSERT_EQUAL(MCP2515::ERROR_OK, SparkCommands::set_parameter(direct, 4, 45, 1.0f));
    equal_frame(Commands::to_can_frame(SparkCommands::build_parameter(4, 45, 0x3f800000UL)), direct.last_frame);
    TEST_ASSERT_EQUAL(MCP2515::ERROR_OK, SparkCommands::set_parameter(direct, 4, 45, true));
    equal_frame(Commands::to_can_frame(SparkCommands::build_parameter(4, 45, 1)), direct.last_frame);
    TEST_ASSERT_EQUAL(MCP2515::ERROR_OK, SparkCommands::set_parameter(direct, 4, 45, false));
    equal_frame(Commands::to_can_frame(SparkCommands::build_parameter(4, 45, 0)), direct.last_frame);
}

static void test_commands_ctre_and_error_propagation()
{
    MCP2515   direct;
    MCP2515   object;
    TalonSrx  talon(object, 2);
    VictorSpx victor(object, 5);
    TEST_ASSERT_EQUAL(MCP2515::ERROR_OK, Commands::TalonSrx::set_percent_output(direct, 2, -0.75f));
    TEST_ASSERT_EQUAL(MCP2515::ERROR_OK, talon.set_percent_output(-0.75f));
    equal_frame(object.last_frame, direct.last_frame);
    TEST_ASSERT_EQUAL(MCP2515::ERROR_OK, Commands::VictorSpx::set_percent_output(direct, 5, 0.25f));
    TEST_ASSERT_EQUAL(MCP2515::ERROR_OK, victor.set_percent_output(0.25f));
    equal_frame(object.last_frame, direct.last_frame);
    for (bool enabled : {false, true})
    {
        TEST_ASSERT_EQUAL(MCP2515::ERROR_OK, Commands::send_ctre_global_enable(direct, enabled));
        TEST_ASSERT_EQUAL(MCP2515::ERROR_OK, TalonSrx::send_global_enable(object, enabled));
        equal_frame(object.last_frame, direct.last_frame);
    }
    direct.send_result      = MCP2515::ERROR_ALLTXBUSY;
    const unsigned attempts = direct.send_attempts;
    TEST_ASSERT_EQUAL(MCP2515::ERROR_ALLTXBUSY, SparkCommands::set_duty_cycle(direct, 1, 0.5f));
    TEST_ASSERT_EQUAL(MCP2515::ERROR_ALLTXBUSY, SparkCommands::set_pid_p(direct, 1, 0.5f));
    TEST_ASSERT_EQUAL(MCP2515::ERROR_ALLTXBUSY, Commands::TalonSrx::set_percent_output(direct, 2, 0.5f));
    TEST_ASSERT_EQUAL(MCP2515::ERROR_ALLTXBUSY, Commands::VictorSpx::set_percent_output(direct, 5, 0.5f));
    TEST_ASSERT_EQUAL(MCP2515::ERROR_ALLTXBUSY, Commands::send_ctre_global_enable(direct, true));
    TEST_ASSERT_EQUAL_UINT(attempts + 5, direct.send_attempts); // No hidden retries.
}

void run_commands_tests()
{
    RUN_TEST(test_commands_match_spark_class);
    RUN_TEST(test_commands_encode_setpoint_defaults_and_clamping);
    RUN_TEST(test_commands_configuration_and_pid_slots);
    RUN_TEST(test_commands_ctre_and_error_propagation);
}
