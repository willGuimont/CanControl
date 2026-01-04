#include "sparkmax.h"
#include "talonsrx.h"
#include "victorspx.h"

#include <SPI.h>
#include <frc_can.h>
#include <frc_can_utils.h>
#include <low_sparkmax.h>
#include <mcp2515.h>

using namespace CanControl;

// Configuration for the FRC can protocol
static constexpr CAN_SPEED MCP2515_SPEED = CAN_1000KBPS;
static constexpr CAN_CLOCK MCP2515_OSC   = MCP_8MHZ;

#ifndef MCP2515_CS_PIN
#if defined(ARDUINO_AVR_MEGA2560) || defined(__AVR_ATmega2560__) || defined(ARDUINO_AVR_MEGA)
static constexpr uint8_t mcp2515_cs_pin = 53;
#elif defined(ARDUINO_AVR_UNO) || defined(__AVR_ATmega328P__) || defined(ARDUINO_AVR_NANO)
static constexpr uint8_t mcp2515_cs_pin = 10;
#else
#warning "Unknown board: defaulting mcp2515_cs_pin to 10. Define MCP2515_CS_PIN via build_flags to override."
static constexpr uint8_t mcp2515_cs_pin = 10;
#endif
#else
// MCP2515_CS_PIN provided by build system
static constexpr uint8_t mcp2515_cs_pin = MCP2515_CS_PIN;
#endif

// Controller to the MCP2515 chip, be sure to specify the correct CS pin
static MCP2515 mcp2515(mcp2515_cs_pin);

// Creating the motor
static constexpr uint8_t spark_motor_id = 11;
static SparkMax          spark(mcp2515, spark_motor_id);
static constexpr uint8_t talon_motor_id = 30;
static TalonSrxMotor     talon(mcp2515, talon_motor_id);

// Utility to show MCP2515 errors as strings
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

// You need to send a heartbeat periodically for the motors to be enabled.
// This mirrors the frame the RoboRIO would send.
// See https://docs.wpilib.org/en/stable/docs/software/can-devices/can-addressing.html#universal-heartbeat for more
// details.
static const unsigned long heartbeat_interval_ms = 150;
heartbeat::RobotState      robot_state(120,   // matchTimeSeconds
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
can_frame                  heartbeat_frame = to_can_frame(heartbeat::to_frc_can_frame(robot_state));
static const unsigned long talon_interval_ms = 0;

void print_help()
{
    Serial.println("Available commands: ");
    Serial.println("\t- Start with `s` to set speed (float)");
    Serial.println("\t- Start with `p` to set position (float)");
    Serial.println("\t- `h` for help");
    Serial.println("Ready to accept commands...");
    Serial.println();
}

void setup()
{

    // Initialize serial
    Serial.begin(115200);
    while (!Serial)
        ;

    // Initialize MCP2515
    {
        Serial.print("Starting CanControl on pin ");
        Serial.println(mcp2515_cs_pin);

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
        MCP2515::ERROR resetErr = spark.reset_safe_parameters();
        Serial.print("SparkMax reset_safe_parameters: ");
        Serial.println(mcpErrorToString(resetErr));
        Serial.println();
    }

    print_help();
}

void loop()
{
    static float speed = 0;

    // Send heartbeat every heartbeat_interval_ms
    unsigned long        now                 = millis();
    static unsigned long heartbeat_last_sent = 0;
    if (now - heartbeat_last_sent >= heartbeat_interval_ms)
    {
        // Heartbeat for the spark
        // mcp2515.sendMessage(&heartbeat_frame);
        // Heartbeat for the talon
        TalonSrxMotor::send_global_enable(mcp2515, true);
        heartbeat_last_sent = now;
    }

    // TalonSRX needs to be constantly fed the speed
    static unsigned long speed_last_sent = 0;
    if (now - speed_last_sent >= talon_interval_ms)
    {
        talon.set_percent_output(speed);
        speed_last_sent = now;
    }

    // Read and parse incoming Spark Status 0 frames only
    // TODO move that to SparkMax class
    // {
    //     can_frame      rxFrame;
    //     MCP2515::ERROR readErr;

    //     if ((readErr = mcp2515.readMessage(&rxFrame)) == MCP2515::ERROR_OK)
    //     {
    //         // Only handle extended Spark Status 0 frames
    //         uint32_t arbId = rxFrame.can_id & 0x1FFFFFFFu;
    //         if (SPARK_MATCH_STATUS_0(arbId))
    //         {
    //             CanControl::LowLevel::SparkMax::Spark_STATUS_0_t status{};
    //             if (CanControl::LowLevel::SparkMax::spark_decode_STATUS_0(rxFrame.data, rxFrame.can_dlc, &status))
    //             {
    //                 uint8_t deviceId = (uint8_t)(arbId & SPARK_DEVICE_ID_MASK);

    //                 Serial.print("Status0 spark_id=");
    //                 Serial.print(deviceId);
    //                 Serial.print(" arb=0x");
    //                 Serial.print(arbId, HEX);
    //                 Serial.print(" applied=");
    //                 Serial.print(status.APPLIED_OUTPUT);
    //                 Serial.print(" voltage_raw=");
    //                 Serial.print(status.VOLTAGE);
    //                 Serial.print(" current_raw=");
    //                 Serial.print(status.CURRENT);
    //                 Serial.print(" temp=");
    //                 Serial.print(status.MOTOR_TEMPERATURE);
    //                 Serial.print(" HF=");
    //                 Serial.print(status.HARD_FORWARD_LIMIT_REACHED);
    //                 Serial.print(" HR=");
    //                 Serial.print(status.HARD_REVERSE_LIMIT_REACHED);
    //                 Serial.print(" SF=");
    //                 Serial.print(status.SOFT_FORWARD_LIMIT_REACHED);
    //                 Serial.print(" SR=");
    //                 Serial.print(status.SOFT_REVERSE_LIMIT_REACHED);
    //                 Serial.print(" inv=");
    //                 Serial.print(status.INVERTED);
    //                 Serial.print(" phb=");
    //                 Serial.println(status.PRIMARY_HEARTBEAT_LOCK);
    //             }
    //         }
    //     }
    // }

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
                    speed = (inBuf.substring(1)).toFloat();
                    if (speed > 1.0f)
                        speed = 1.0f;
                    if (speed < -1.0f)
                        speed = -1.0f;
                    Serial.print("Set speed: ");
                    Serial.println(speed);

                    // Send speed command via high-level SparkMax wrapper
                    // Be sure to only send the command on change
                    // Otherwise it will put too much stress on the MCP2515
                    spark.set_duty_cycle(speed);
                }
                else if (inBuf[0] == 'p')
                {
                    // Position
                    float position = (inBuf.substring(1)).toFloat();
                    Serial.print("Set position: ");
                    Serial.println(position);

                    // Send position command via high-level SparkMax wrapper
                    spark.set_position(position);
                }
                else if (inBuf[0] == 'h')
                {
                    print_help();
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
