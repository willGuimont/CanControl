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

static const String mcpErrorToString(MCP2515::ERROR e)
{
    switch (e)
    {
    case MCP2515::ERROR_OK:
        return "OK";
    case MCP2515::ERROR_FAIL:
        return "ERROR_FAIL";
    case MCP2515::ERROR_ALLTXBUSY:
        return "ERROR_ALLTXBUSY";
    case MCP2515::ERROR_FAILINIT:
        return "ERROR_FAILINIT";
    case MCP2515::ERROR_FAILTX:
        return "ERROR_FAILTX";
    case MCP2515::ERROR_NOMSG:
        return "ERROR_NOMSG";
    default:
        return "ERROR_UNKNOWN";
    }
}

heartbeat::RobotState robot_state(
    120,   // matchTimeSeconds
    1,     // matchNumber
    0,     // replayNumber
    false, // redAlliance
    true,  // enabled
    true,  // autonomous
    false, // testMode
    true,  // systemWatchdog
    0,     // tournamentType
    25,    // timeOfDay_yr
    1,     // timeOfDay_month
    1,     // timeOfDay_day
    12,    // timeOfDay_hr
    0,     // timeOfDay_min
    0      // timeOfDay_sec
);
can_frame heartbeat_frame = to_can_frame(heartbeat::to_frc_can_frame(robot_state));

// Build a Duty Cycle Setpoint using frc_can_frame and convert to can_frame
static inline can_frame makeDutyCycleSetpointFrc(uint8_t device_number,
                                                 float duty,
                                                 int16_t arbFeedforward = 0,
                                                 uint8_t pidSlot = 0,
                                                 bool ffUnitsIsDuty = true)
{
    CanControl::frc_can_frame f{};
    // apiIndex = 2 (Duty Cycle Setpoint), apiClass = 0
    f.id = CanControl::frc_can_id(device_number, 2u, 0u, 5u, 2u);
    f.dlc = 8;
    // float little-endian
    uint8_t *fp = reinterpret_cast<uint8_t *>(&duty);
    f.data[0] = fp[0];
    f.data[1] = fp[1];
    f.data[2] = fp[2];
    f.data[3] = fp[3];
    // int16 arbitrary feedforward little-endian
    f.data[4] = uint8_t(arbFeedforward & 0xFF);
    f.data[5] = uint8_t((arbFeedforward >> 8) & 0xFF);
    f.data[6] = (pidSlot & 0x03) | (uint8_t((ffUnitsIsDuty ? 1 : 0) << 2));
    f.data[7] = 0;
    return CanControl::to_can_frame(f);
}

void setup()
{
    Serial.begin(115200);
    while (!Serial)
        ;
    Serial.print("Starting CanControl on pin ");
    Serial.println(MCP2515_CS_PIN);

    mcp2515.reset();
    mcp2515.setBitrate(MCP2515_SPEED, MCP2515_OSC);
    mcp2515.setNormalMode();
}

void loop()
{
    static unsigned long lastHeartbeatMs = 0;
    static unsigned long lastStatusMs = 0;
    unsigned long now = millis();

    // Send heartbeat on TXB0 to avoid clobbering duty-cycle TX buffer
    static MCP2515::ERROR lastHeartbeatError = MCP2515::ERROR_OK;
    static MCP2515::ERROR lastDutyError = MCP2515::ERROR_OK;
    lastHeartbeatError = mcp2515.sendMessage(&heartbeat_frame);
    lastHeartbeatMs = now;

    // Always send duty-cycle setpoint on TXB1
    static float currentSpeed = 0.0f; // range -1..1
    static String inBuf = "";
    while (Serial.available())
    {
        char c = Serial.read();
        if (c == '\n' || c == '\r')
        {
            if (inBuf.length() > 0)
            {
                float v = inBuf.toFloat();
                if (v > 1.0f)
                    v = 1.0f;
                if (v < -1.0f)
                    v = -1.0f;
                currentSpeed = v;
                Serial.print("Set speed: ");
                Serial.println(currentSpeed);
                inBuf = "";
            }
        }
        else
        {
            inBuf += c;
        }
    }


    can_frame duty = makeDutyCycleSetpointFrc(11, currentSpeed, 0, 0, true);
    lastDutyError = mcp2515.sendMessage(&duty);

    // Throttle Serial prints to avoid blocking timing (print once per second)
    if (now - lastStatusMs >= 1000)
    {
        Serial.print("Heartbeat last sent ms: ");
        Serial.println(lastHeartbeatMs);
        Serial.print("Heartbeat last error: ");
        Serial.println(mcpErrorToString(lastHeartbeatError));
        Serial.print("Duty last error: ");
        Serial.println(mcpErrorToString(lastDutyError));
        lastStatusMs = now;
    }

    // delay(5);
}
