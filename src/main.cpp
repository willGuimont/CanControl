#include "sparkmax.h"
#include "talonsrx.h"
#include "victorspx.h"

#include <SPI.h>
#include <frc_can.h>
#include <frc_can_utils.h>
#include <low_sparkmax.h>
#include <mcp2515.h>

using namespace CanControl;
using namespace CanControl::LowLevel::SparkMax;

static const CAN_SPEED     MCP2515_SPEED         = CAN_1000KBPS;
static const CAN_CLOCK     MCP2515_OSC           = MCP_8MHZ;
static const unsigned long HEARTBEAT_INTERVAL_MS = 30;

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

static constexpr uint8_t motor_id_1 = 11;
static SparkCanDevice    motor_1(mcp2515, motor_id_1);

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

heartbeat::RobotState robot_state(120,   // matchTimeSeconds
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
can_frame             heartbeat_frame = to_can_frame(heartbeat::to_frc_can_frame(robot_state));

Spark_RESET_SAFE_PARAMETERS_t reset_frame{
    .MAGIC_NUMBER = 36292,
};

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
        Serial.println();

        setupErr = mcp2515.setNormalMode();
        Serial.print("MCP2515 setNormalMode: ");
        Serial.println(mcpErrorToString(setupErr));
        Serial.println();

        Serial.println("Resetting all motor parameters");
        motor_1.send_reset_safe_parameters(reset_frame);
        // motor_2.send_reset_safe_parameters(reset_frame);
        Serial.println();

        Serial.println("Available commands: ");
        Serial.println("\t- Start with `s` to set speed (float)");
        Serial.println("\t- Start with `p` to set position (float)");
        Serial.println("Ready to accept commands...");
        Serial.println();
    }
}

void loop()
{
    unsigned long now = millis();

    // Heartbeat
    static unsigned long lastHeartbeatMs = 0;
    if (now - lastHeartbeatMs >= HEARTBEAT_INTERVAL_MS)
    {
        lastHeartbeatMs = now;
    }

    // Read and parse incoming Spark Status 0 frames only
    {
        can_frame      rxFrame;
        MCP2515::ERROR readErr;

        if ((readErr = mcp2515.readMessage(&rxFrame)) == MCP2515::ERROR_OK)
        {
            // Only handle extended Spark Status 0 frames
            uint32_t arbId = rxFrame.can_id & 0x1FFFFFFFu;
            if (SPARK_MATCH_STATUS_0(arbId))
            {
                Spark_STATUS_0_t status{};
                if (spark_decode_STATUS_0(rxFrame.data, rxFrame.can_dlc, &status))
                {
                    uint8_t deviceId = (uint8_t)(arbId & SPARK_DEVICE_ID_MASK);

                    Serial.print("Status0 spark_id=");
                    Serial.print(deviceId);
                    Serial.print(" arb=0x");
                    Serial.print(arbId, HEX);
                    Serial.print(" applied=");
                    Serial.print(status.APPLIED_OUTPUT);
                    Serial.print(" voltage_raw=");
                    Serial.print(status.VOLTAGE);
                    Serial.print(" current_raw=");
                    Serial.print(status.CURRENT);
                    Serial.print(" temp=");
                    Serial.print(status.MOTOR_TEMPERATURE);
                    Serial.print(" HF=");
                    Serial.print(status.HARD_FORWARD_LIMIT_REACHED);
                    Serial.print(" HR=");
                    Serial.print(status.HARD_REVERSE_LIMIT_REACHED);
                    Serial.print(" SF=");
                    Serial.print(status.SOFT_FORWARD_LIMIT_REACHED);
                    Serial.print(" SR=");
                    Serial.print(status.SOFT_REVERSE_LIMIT_REACHED);
                    Serial.print(" inv=");
                    Serial.print(status.INVERTED);
                    Serial.print(" phb=");
                    Serial.println(status.PRIMARY_HEARTBEAT_LOCK);
                }
            }
        }
    }

    // Commands
    static String inBuf = "";
    while (Serial.available())
    {
        char c = Serial.read();
        if (c == '\n' || c == '\r')
        {
            // Command + at least one char of argument
            if (inBuf.length() >= 2)
            {
                if (inBuf[0] == 's')
                {
                    // Speed
                    float speed = (inBuf.substring(1)).toFloat();
                    if (speed > 1.0f)
                        speed = 1.0f;
                    if (speed < -1.0f)
                        speed = -1.0f;
                    Serial.print("Set speed: ");
                    Serial.println(speed);

                    Spark_DUTY_CYCLE_SETPOINT_t duty{
                        .SETPOINT                    = speed,
                        .ARBITRARY_FEEDFORWARD       = 0,
                        .PID_SLOT                    = 0,
                        .ARBITRARY_FEEDFORWARD_UNITS = 1u,
                    };

                    // Send speed only on change
                    motor_1.set_duty_cycle_setpoint(duty);
                }
                else if (inBuf[0] == 'p')
                {
                    // Position
                    float position = (inBuf.substring(1)).toFloat();
                    Serial.print("Set position: ");
                    Serial.println(position);

                    Spark_POSITION_SETPOINT_t sp{
                        .SETPOINT                    = position,
                        .ARBITRARY_FEEDFORWARD       = 0,
                        .PID_SLOT                    = 0,
                        .ARBITRARY_FEEDFORWARD_UNITS = 0,
                    };

                    // Send speed only on change
                    motor_1.set_position_setpoint(sp);
                }

                // Clear buffer
                inBuf = "";
            }
        }
        else
        {
            inBuf += c;
        }
    }
}
