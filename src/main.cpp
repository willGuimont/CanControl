#include <SPI.h>
#include <mcp2515.h>

#include <frc_can.h>
#include <frc_can_utils.h>
#include <spark_can.h>

using namespace CanControl;
using namespace CanControl::SparkMax;

static const CAN_SPEED MCP2515_SPEED = CAN_1000KBPS;
static const CAN_CLOCK MCP2515_OSC = MCP_8MHZ;
static const unsigned long HEARTBEAT_INTERVAL_MS = 20;
static const unsigned long MOTOR_SETPOINT_INTERVAL_MS = 10;

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
static constexpr uint8_t kSparkDeviceId = 11;
static SparkCanDevice motor(mcp2515, kSparkDeviceId);

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

void setup()
{

    Serial.begin(115200);
    while (!Serial)
        ;
    Serial.print("Starting CanControl on pin ");
    Serial.println(MCP2515_CS_PIN);

    {
        MCP2515::ERROR setupErr;
        setupErr = mcp2515.reset();
        Serial.print("MCP2515 reset: ");
        Serial.println(mcpErrorToString(setupErr));

        setupErr = mcp2515.setBitrate(MCP2515_SPEED, MCP2515_OSC);
        Serial.print("MCP2515 setBitrate: ");
        Serial.println(mcpErrorToString(setupErr));

        setupErr = mcp2515.setNormalMode();
        Serial.print("MCP2515 setNormalMode: ");
        Serial.println(mcpErrorToString(setupErr));
    }
}

void loop()
{
    static unsigned long lastHeartbeatMs = 0;
    static unsigned long lastStatusMs = 0;
    unsigned long now = millis();

    // Heartbeat
    static MCP2515::ERROR lastHeartbeatError = MCP2515::ERROR_OK;
    static MCP2515::ERROR lastDutyError = MCP2515::ERROR_OK;
    if (now - lastHeartbeatMs >= HEARTBEAT_INTERVAL_MS)
    {
        lastHeartbeatError = mcp2515.sendMessage(&heartbeat_frame);
        lastHeartbeatMs = now;
    }

    static float currentSpeed = 0.00f;
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

    static unsigned long lastDutyMs = 0;
    if (now - lastDutyMs >= MOTOR_SETPOINT_INTERVAL_MS)
    {
        Spark_DUTY_CYCLE_SETPOINT_t duty{
            .SETPOINT = currentSpeed,
            .ARBITRARY_FEEDFORWARD = 0,
            .PID_SLOT = 0,
            .ARBITRARY_FEEDFORWARD_UNITS = 1u,
        };
        lastDutyError = motor.set_duty_cycle_setpoint(duty);
        lastDutyMs = now;
    }

    // if (now - lastStatusMs >= 1000)
    // {
    //     Serial.print("Heartbeat last sent ms: ");
    //     Serial.println(lastHeartbeatMs);
    //     Serial.print("Heartbeat last error: ");
    //     Serial.println(mcpErrorToString(lastHeartbeatError));
    //     Serial.print("Duty last error: ");
    //     Serial.println(mcpErrorToString(lastDutyError));
    //     lastStatusMs = now;
    // }
}
