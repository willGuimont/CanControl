#include <SPI.h>
#include <mcp2515.h>

#include <frc_can.h>
#include <frc_can_utils.h>

using namespace CanControl;

static const CAN_SPEED MCP2515_SPEED = CAN_1000KBPS;
static const CAN_CLOCK MCP2515_OSC = MCP_8MHZ;

#ifndef MCP2515_CS_PIN
#if defined(ARDUINO_AVR_MEGA2560) || defined(__AVR_ATmega2560__) || defined(ARDUINO_AVR_MEGA)
static const uint8_t MCP2515_CS_PIN = 53;
#elif defined(ARDUINO_AVR_UNO) || defined(__AVR_ATmega328P__) || defined(ARDUINO_AVR_NANO)
static const uint8_t MCP2515_CS_PIN = 10;
#else
#warning "Unknown board: defaulting MCP2515_CS_PIN to 10. Define MCP2515_CS_PIN via build_flags to override."
static const uint8_t MCP2515_CS_PIN = 10;
#endif
#else
// MCP2515_CS_PIN provided by build system
static const uint8_t MCP2515_CS_PIN = MCP2515_CS_PIN;
#endif

static MCP2515 mcp2515(MCP2515_CS_PIN);

heartbeat::RobotState robot_state;
can_frame heartbeat_frame;

void setup()
{
    Serial.begin(115200);
    while (!Serial)
        ;
    Serial.println("Starting CanControl");

    robot_state.set_matchTimeSeconds(120);
    robot_state.set_matchNumber(1);
    robot_state.set_replayNumber(0);
    robot_state.set_redAlliance(false);
    robot_state.set_enabled(true);
    robot_state.set_autonomous(true);
    robot_state.set_testMode(false);
    robot_state.set_systemWatchdog(true); 
    robot_state.set_tournamentType(0);
    robot_state.set_timeOfDay_yr(25);
    robot_state.set_timeOfDay_month(1);
    robot_state.set_timeOfDay_day(1);
    robot_state.set_timeOfDay_hr(12);
    robot_state.set_timeOfDay_min(0);
    robot_state.set_timeOfDay_sec(0);

    heartbeat_frame = to_can_frame(heartbeat::to_frc_can_frame(robot_state));

    mcp2515.reset();
    mcp2515.setBitrate(MCP2515_SPEED, MCP2515_OSC);
    mcp2515.setNormalMode();
}

void loop()
{
    Serial.print("Sending heartbeat: ");
    Serial.println(mcp2515.sendMessage(MCP2515::TXB1, &heartbeat_frame));
}
