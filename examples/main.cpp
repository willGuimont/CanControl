/**
 * CanControl example - William Guimont-Martin 2025-2026 (https://github.com/willGuimont/CanControl)
 * Example showing how to setup and use FRC CAN motors using Arduino chips.
 *
 * See README.md for wiring.
 */
#include "CanControl.h"

#include <SPI.h>
#include <mcp2515.h>

using namespace CanControl;

// Configuration for the FRC can protocol
static constexpr CAN_SPEED MCP2515_SPEED = CAN_1000KBPS;
// Check the oscillator on your MCP2515
static constexpr CAN_CLOCK MCP2515_OSC = MCP_8MHZ;
// With an 8 MHz MCP2515 oscillator the SPI SCK must be kept below.
// Use 10 MHz only when the MCP2515 module has a 16/20 MHz oscillator.
static constexpr uint32_t SPI_CLOCK_SPEED = (MCP2515_OSC == MCP_8MHZ) ? 4000000UL : 10000000UL;

// Prevent accidental misconfiguration at compile-time
static_assert(!(MCP2515_OSC == MCP_8MHZ && SPI_CLOCK_SPEED > 4000000UL),
              "SPI_CLOCK_SPEED too high for MCP_8MHZ; must be <= 4000000UL");

// The Chip Select (CS) pin varies depending on the board used. See README.md for wiring.
// Homing state: when true we drive positively until the forward hard limit is seen
static bool            homing_active     = false;
static bool            homing_prev_limit = false;
static constexpr float homing_speed      = 0.20f;
#ifndef MCP2515_CS_PIN
#if defined(ARDUINO_AVR_MEGA2560) || defined(__AVR_ATmega2560__) || defined(ARDUINO_AVR_MEGA)
static constexpr uint8_t MCP2515_CS_PIN = 53;
#elif defined(ARDUINO_AVR_UNO) || defined(__AVR_ATmega328P__) || defined(ARDUINO_AVR_NANO)
static constexpr uint8_t MCP2515_CS_PIN = 10;
#else
#warning "Unknown board: defaulting MCP2515_CS_PIN to 10. Define MCP2515_CS_PIN via build_flags to override."
static constexpr uint8_t MCP2515_CS_PIN = 10;
#endif
#else
// MCP2515_CS_PIN provided by build system
static constexpr uint8_t MCP2515_CS_PIN = MCP2515_CS_PIN;
#endif

// Controller to the MCP2515 chip, be sure to specify the correct CS pin
static MCP2515 mcp2515(MCP2515_CS_PIN, SPI_CLOCK_SPEED);

// Creating the motor, specify the device ID set in the REV Hardware Client
static constexpr uint8_t spark_motor_id = 1;
static SparkMax          spark(mcp2515, spark_motor_id);
// Same for TalonSRX
// static constexpr uint8_t talon_motor_id = 30;
// static TalonSrx     talon(mcp2515, talon_motor_id);

// PID constants to show how to set parameters on SparkMax
static constexpr float spark_p = 0.1;
static constexpr float spark_i = 0.0;
static constexpr float spark_d = 0.0;
static constexpr float spark_f = 0.0;

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
// Heartbeat must be sent quickly enough to avoid the motor to stop, but not too quickly for the MCP2515's buffers
// filled
static constexpr unsigned long heartbeat_interval_ms = 19;
// Sending updates to the motor can be done less frequently. For SparkMax, a command can be sent only once and it will
// continue at that speed as long as the heartbeat is present
static constexpr unsigned long update_interval_ms = 5;

// Create a default robot state
// The important part is that the robot state has the `enabled` and `systemWatchdog` fields set to `true`
static const heartbeat::RobotState robot_state = default_heartbeat();

// Information about the small serial interface used to control the motor
void print_help()
{
    Serial.println("Available commands: ");
    Serial.println("\t- Start with `s` to set speed (float)");
    Serial.println("\t- Start with `p` to set position (float)");
    Serial.println("\t- `z` to start homing (drive positive until forward limit), `c` to cancel");
    Serial.println("\t- `h` for help");
    Serial.println("Ready to accept commands...");
    Serial.println();
}

enum CommandMode
{
    Speed,
    Position,
};

void setup()
{

    // Initialize serial
    Serial.begin(115200);
    while (!Serial)
        ;

    // Initialize MCP2515
    {
        Serial.print("Starting CanControl on pin ");
        Serial.println(MCP2515_CS_PIN);
        Serial.print("MCP2515 oscillator: ");
        if (MCP2515_OSC == MCP_8MHZ)
        {
            Serial.println("8 MHz");
        }
        else if (MCP2515_OSC == MCP_16MHZ)
        {
            Serial.println("16 MHz");
        }
        else if (MCP2515_OSC == MCP_20MHZ)
        {
            Serial.println("20 MHz");
        }
        else
        {
            Serial.println("unknown");
        }
        Serial.print("SPI clock (Hz): ");
        Serial.println(SPI_CLOCK_SPEED);

        // Must reset before use
        MCP2515::ERROR setupErr;
        setupErr = mcp2515.reset();
        delay(10);
        Serial.print("MCP2515 reset: ");
        Serial.println(mcpErrorToString(setupErr));

        // Set speed
        setupErr = mcp2515.setBitrate(MCP2515_SPEED, MCP2515_OSC);
        delay(10);
        Serial.print("MCP2515 setBitrate: ");
        Serial.println(mcpErrorToString(setupErr));
        Serial.println();

        // Necessary for the mcp2515 to not wait for an ACK
        setupErr = mcp2515.setNormalOneShotMode();
        delay(10);
        Serial.print("MCP2515 setNormalOneShotMode: ");
        Serial.println(mcpErrorToString(setupErr));
        Serial.println();

        // Best practice, reset motor parameter to avoid lingering configs that might behave unexpectly
        // Set the parameters when initializing the motor
        Serial.println("Resetting all motor parameters");
        MCP2515::ERROR reset_err = spark.reset_safe_parameters();
        delay(10);
        Serial.print("SparkMax reset_safe_parameters: ");
        Serial.println(mcpErrorToString(reset_err));
        Serial.println();

        // Set motor PID parameter for position control mode
        Serial.println("Setting PID parameters");
        int pid_err = spark.set_pid_p(spark_p);
        pid_err |= spark.set_pid_i(spark_i);
        delay(10);
        pid_err |= spark.set_pid_d(spark_d);
        delay(10);
        pid_err |= spark.set_pid_f(spark_f);
        delay(10);
        if (pid_err != MCP2515::ERROR_OK)
        {
            Serial.println("Error setting PID parameters");
        }
        else
        {
            Serial.println("PID parameters set");
        }
    }

    print_help();
}

void loop()
{
    static float       speed        = 0;
    static float       position     = 0;
    static CommandMode command_mode = Speed;

    // Send heartbeat every heartbeat_interval_ms milliseconds
    unsigned long        now                 = millis();
    static unsigned long heartbeat_last_sent = 0;
    if (now - heartbeat_last_sent >= heartbeat_interval_ms)
    {
        // Heartbeat for the spark (FRC-style) and CTRE global-enable
        // IMPORTANT: If control is lost (for example a joystick disconnect),
        // stop sending the heartbeat - all motors will stop.
        send_heartbeat(mcp2515, robot_state);
        // TalonSRX and VictorSPX need a global enable
        // TalonSrx::send_global_enable(mcp2515, true);
        heartbeat_last_sent = now;
    }

    // SparkMax can be sent speed only on change
    // TalonSRX needs to be constantly fed the speed
    // Since in robotics applications (e.g., controlling a motor from a joystick) the speed rarely stays constant, we
    // send it repeatively here
    now                                  = millis();
    static unsigned long speed_last_sent = 0;
    if (now - speed_last_sent >= update_interval_ms)
    {
        switch (command_mode)
        {
        case Speed:
            // SparkMax
            if (homing_active)
            {
                spark.set_duty_cycle(homing_speed);
            }
            else
            {
                spark.set_duty_cycle(speed);
            }
            // TalonSRX
            // talon.set_percent_output(speed);
            break;
        case Position:
            // Use the position sensor (e.g., encoder, potentiometer) and use a PID to achieve that position
            spark.set_position(position);
            break;
        default:
            break;
        }

        speed_last_sent = now;
    }

    // Small serial interface to control the motor
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
                    command_mode = Speed;
                    Serial.print("Set speed: ");
                    Serial.println(speed);
                }
                else if (inBuf[0] == 'p')
                {
                    // Position
                    position     = (inBuf.substring(1)).toFloat();
                    command_mode = Position;
                    Serial.print("Set position: ");
                    Serial.println(position);
                }
                else if (inBuf[0] == 'h')
                {
                    print_help();
                }
                else if (inBuf[0] == 'z')
                {
                    homing_active = true;
                    command_mode  = Speed;
                    speed         = homing_speed;
                    Serial.println("Starting homing (driving positive)");
                }
                else if (inBuf[0] == 'c')
                {
                    homing_active = false;
                    spark.stop();
                    Serial.println("Homing cancelled");
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

    // Read incoming CAN frames and update motor state objects.
    struct can_frame rf;
    while (mcp2515.readMessage(&rf) == MCP2515::ERROR_OK)
    {
        // Single-spark example: let the `spark` instance process the frame.
        spark.handle_received_frame(rf);
    }

    // If homing is active and we just saw the forward hard-limit edge, zero encoder
    if (homing_active && spark.hard_forward_limit_reached() && !homing_prev_limit)
    {
        spark.stop();

        MCP2515::ERROR setpos_err = spark.set_primary_encoder_position(0.0f);
        Serial.print("Sent encoder-zero SET_PRIMARY_ENCODER_POSITION: ");
        Serial.println(mcpErrorToString(setpos_err));

        homing_active = false;
    }

    homing_prev_limit = spark.hard_forward_limit_reached();
}
