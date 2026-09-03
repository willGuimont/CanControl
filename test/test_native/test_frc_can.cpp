#include <CanControl.h>
#include <can_controller.h>
#include <low_level/frc_can.h>
#include <low_level/frc_can_utils.h>
#include <low_level/low_sparkmax.h>
#include <motors_queued/sparkmax_queued.h>
#include <motors_queued/talonsrx_queued.h>
#include <motors_queued/victorspx_queued.h>
#include <unity.h>
#include <vector>

using namespace CanControl;

class FakeClock : public CanController::Clock
{
  public:
    unsigned long now_ms() const override
    {
        return now;
    }

    void delay_ms(unsigned long duration_ms) override
    {
        now += duration_ms;
    }

    unsigned long now = 0;
};

class FakeTransport : public CanController::Transport
{
  public:
    MCP2515::ERROR reset() override
    {
        return MCP2515::ERROR_OK;
    }

    MCP2515::ERROR set_bitrate(CAN_SPEED, CAN_CLOCK) override
    {
        return MCP2515::ERROR_OK;
    }

    MCP2515::ERROR set_normal_one_shot_mode() override
    {
        return MCP2515::ERROR_OK;
    }

    MCP2515::ERROR send(const can_frame& frame) override
    {
        ++send_attempts;
        if (always_fail || failures_remaining > 0)
        {
            if (failures_remaining > 0)
                --failures_remaining;
            return MCP2515::ERROR_FAILTX;
        }
        sent.push_back(frame);
        return MCP2515::ERROR_OK;
    }

    std::vector<can_frame> sent;
    int                    send_attempts      = 0;
    int                    failures_remaining = 0;
    bool                   always_fail        = false;
};

class DummyPeriodicSender : public CanController::PeriodicSender
{
  public:
    bool get_periodic_frame(can_frame&, unsigned long) override
    {
        return false;
    }
};

static void configure_controller(CanController& controller)
{
    controller.set_heartbeat(false);
    controller.set_send_interval(0);
}

static void assert_frame_equal(const can_frame& expected, const can_frame& actual)
{
    TEST_ASSERT_EQUAL_UINT32(expected.can_id, actual.can_id);
    TEST_ASSERT_EQUAL_UINT8(expected.can_dlc, actual.can_dlc);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(expected.data, actual.data, expected.can_dlc);
}

static constexpr uint32_t device_type       = 2;
static constexpr uint32_t manufacturer_code = 8;
static constexpr uint32_t api_class         = 1;
static constexpr uint32_t api_index         = 0;
static constexpr uint32_t device_number     = 3;

static uint32_t make_raw_id()
{
    return ((device_type & 0x1F) << 24) | ((manufacturer_code & 0xFF) << 16) | ((api_class & 0x3F) << 10) |
           ((api_index & 0x0F) << 6) | ((device_number & 0x3F) << 0);
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

void test_can_id_example()
{
    frc_can_id id{};
    id.raw = (2u << 24) | (2u << 16) | (1u << 10) | (1u << 6) | 4u;

    TEST_ASSERT_EQUAL_UINT32(2, id.device_type());
    TEST_ASSERT_EQUAL_UINT32(2, id.manufacturer_code());
    TEST_ASSERT_EQUAL_UINT32(1, id.api_class());
    TEST_ASSERT_EQUAL_UINT32(1, id.api_index());
    TEST_ASSERT_EQUAL_UINT32(4, id.device_number());
}

void test_can_frame_conversion_clamps_dlc()
{
    frc_can_frame frame{};
    frame.dlc = 15;
    for (uint8_t i = 0; i < CLASSIC_CAN_MAX_DLC; ++i)
        frame.data[i] = i;

    can_frame raw = to_can_frame(frame);
    TEST_ASSERT_EQUAL_UINT8(CLASSIC_CAN_MAX_DLC, raw.can_dlc);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(frame.data, raw.data, CLASSIC_CAN_MAX_DLC);

    raw.can_dlc             = 15;
    frc_can_frame converted = from_can_frame(raw);
    TEST_ASSERT_EQUAL_UINT8(CLASSIC_CAN_MAX_DLC, converted.dlc);
}

void test_can_frame_conversion_preserves_flags_and_clears_data()
{
    heartbeat::RobotState state = default_heartbeat();
    frc_can_frame         frame = heartbeat::to_frc_can_frame(state);

    can_frame     raw  = to_can_frame(frame);
    frc_can_frame back = from_can_frame(raw);

    TEST_ASSERT_TRUE(back.id.flag_eff());
    TEST_ASSERT_TRUE(heartbeat::is_heartbeat(back));

    heartbeat::RobotState decoded{};
    TEST_ASSERT_TRUE(heartbeat::from_frc_can_frame(back, decoded));
    TEST_ASSERT_TRUE(decoded.enabled());

    can_frame short_raw{};
    short_raw.can_id  = 0x123 | EFF_FLAG;
    short_raw.can_dlc = 3;
    short_raw.data[0] = 0xAA;
    short_raw.data[1] = 0xBB;
    short_raw.data[2] = 0xCC;
    short_raw.data[3] = 0xDD;

    frc_can_frame converted = from_can_frame(short_raw);
    TEST_ASSERT_EQUAL_UINT8(3, converted.dlc);
    TEST_ASSERT_EQUAL_UINT8(0xAA, converted.data[0]);
    TEST_ASSERT_EQUAL_UINT8(0xBB, converted.data[1]);
    TEST_ASSERT_EQUAL_UINT8(0xCC, converted.data[2]);
    TEST_ASSERT_EQUAL_UINT8(0x00, converted.data[3]);
}

void test_controller_retries_queue_head_in_fifo_order()
{
    FakeTransport transport;
    FakeClock     clock;
    CanController controller(transport, clock);
    configure_controller(controller);

    can_frame first{};
    first.can_id = 1;
    can_frame second{};
    second.can_id = 2;
    TEST_ASSERT_TRUE(controller.queue_frame(first));
    TEST_ASSERT_TRUE(controller.queue_frame(second));

    transport.failures_remaining = 1;
    controller.update(0);
    TEST_ASSERT_TRUE(controller.has_pending_frames());
    TEST_ASSERT_EQUAL_size_t(0, transport.sent.size());

    controller.update(0);
    controller.update(0);
    TEST_ASSERT_FALSE(controller.has_pending_frames());
    TEST_ASSERT_EQUAL_size_t(2, transport.sent.size());
    TEST_ASSERT_EQUAL_UINT32(1, transport.sent[0].can_id);
    TEST_ASSERT_EQUAL_UINT32(2, transport.sent[1].can_id);
}

void test_flush_times_out_when_transport_fails()
{
    FakeTransport transport;
    FakeClock     clock;
    CanController controller(transport, clock);
    configure_controller(controller);
    can_frame frame{};

    transport.always_fail = true;
    TEST_ASSERT_TRUE(controller.queue_frame(frame));
    TEST_ASSERT_FALSE(controller.flush(10, 30));
    TEST_ASSERT_TRUE(controller.has_pending_frames());
    TEST_ASSERT_EQUAL_UINT32(30, clock.now);
    TEST_ASSERT_EQUAL_INT(3, transport.send_attempts);
}

void test_spark_queued_sends_control_and_configuration_frames()
{
    FakeTransport transport;
    FakeClock     clock;
    CanController controller(transport, clock);
    configure_controller(controller);
    SparkMaxQueued spark(controller, 3);

    TEST_ASSERT_EQUAL(MCP2515::ERROR_OK, spark.set_pid_p(0.25f));
    TEST_ASSERT_TRUE(controller.flush(1, 10));

    TEST_ASSERT_EQUAL(MCP2515::ERROR_OK, spark.set_duty_cycle(0.5f));
    controller.update(0);
    TEST_ASSERT_EQUAL_size_t(2, transport.sent.size());

    LowLevel::SparkMax::Spark_DUTY_CYCLE_SETPOINT_t values{};
    values.SETPOINT                    = 0.5f;
    values.PID_SLOT                    = 0;
    values.ARBITRARY_FEEDFORWARD       = 0;
    values.ARBITRARY_FEEDFORWARD_UNITS = 1;
    can_frame expected{};
    LowLevel::basic_to_can_frame(LowLevel::SparkMax::spark_build_DUTY_CYCLE_SETPOINT(3, &values), &expected);
    assert_frame_equal(expected, transport.sent[1]);
}

void test_ctre_queued_sends_talon_and_victor_frames()
{
    FakeTransport transport;
    FakeClock     clock;
    CanController controller(transport, clock);
    configure_controller(controller);
    TalonSrxQueued  talon(controller, 4);
    VictorSpxQueued victor(controller, 5);

    TEST_ASSERT_EQUAL(MCP2515::ERROR_OK, talon.set_percent_output(0.25f));
    TEST_ASSERT_EQUAL(MCP2515::ERROR_OK, victor.set_percent_output(-0.5f));
    controller.update(0);
    controller.update(0);

    TEST_ASSERT_EQUAL_size_t(2, transport.sent.size());
    can_frame expected_talon{};
    can_frame expected_victor{};
    LowLevel::basic_to_can_frame(LowLevel::TalonSrx::talon_build_percent_output(4, 0.25f), &expected_talon);
    LowLevel::basic_to_can_frame(LowLevel::TalonSrx::victor_build_percent_output(5, -0.5f), &expected_victor);
    assert_frame_equal(expected_talon, transport.sent[0]);
    assert_frame_equal(expected_victor, transport.sent[1]);
}

void test_destroyed_periodic_sender_is_unregistered()
{
    FakeTransport transport;
    FakeClock     clock;
    CanController controller(transport, clock);
    configure_controller(controller);

    {
        SparkMaxQueued spark(controller, 1);
        TEST_ASSERT_EQUAL(MCP2515::ERROR_OK, spark.set_duty_cycle(0.5f));
    }

    controller.update(0);
    TEST_ASSERT_EQUAL_size_t(0, transport.sent.size());
}

void test_unregistered_queued_motor_reports_failure()
{
    FakeTransport       transport;
    FakeClock           clock;
    CanController       controller(transport, clock);
    DummyPeriodicSender senders[8];
    configure_controller(controller);

    for (DummyPeriodicSender& sender : senders)
        TEST_ASSERT_TRUE(controller.add_periodic_sender(&sender));

    SparkMaxQueued spark(controller, 1);
    TEST_ASSERT_EQUAL(MCP2515::ERROR_FAILINIT, spark.set_duty_cycle(0.5f));
    controller.update(0);
    TEST_ASSERT_EQUAL_size_t(0, transport.sent.size());
}

int main(int argc, char** argv)
{
    UNITY_BEGIN();

    RUN_TEST(test_frc_can_id_fields_from_raw);
    RUN_TEST(test_frc_can_id_flags);
    RUN_TEST(test_can_id_example);
    RUN_TEST(test_can_frame_conversion_clamps_dlc);
    RUN_TEST(test_can_frame_conversion_preserves_flags_and_clears_data);
    RUN_TEST(test_controller_retries_queue_head_in_fifo_order);
    RUN_TEST(test_flush_times_out_when_transport_fails);
    RUN_TEST(test_spark_queued_sends_control_and_configuration_frames);
    RUN_TEST(test_ctre_queued_sends_talon_and_victor_frames);
    RUN_TEST(test_destroyed_periodic_sender_is_unregistered);
    RUN_TEST(test_unregistered_queued_motor_reports_failure);

    return UNITY_END();
}
