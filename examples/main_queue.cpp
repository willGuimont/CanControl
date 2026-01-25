/**
 * CanControl example - William Guimont-Martin 2025-2026 (https://github.com/willGuimont/CanControl)
 * Example showing how to setup and use FRC CAN motors using Arduino chips with the queued CanController.
 *
 * See README.md for wiring.
 */
#include "CanControl.h"
#include "can_controller.h"
#include "motors_queued/sparkmax_queued.h"

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

// Controller to the MCP2515 chip
static MCP2515 mcp2515(MCP2515_CS_PIN, SPI_CLOCK_SPEED);

// The CanController handles queuing frames and sending heartbeats
static CanController can_controller(mcp2515);

// Creating the motor, bound to the CanController
static constexpr uint8_t spark_motor_id = 11;
static SparkMaxQueued    spark(can_controller, spark_motor_id);

// PID constants
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

static constexpr unsigned long heartbeat_interval_ms = 19;
static constexpr unsigned long update_inteval_ms     = 5;

void print_help()
{
    Serial.println("Available commands: ");
    Serial.println("\t- Start with `s` to set speed (float)");
    Serial.println("\t- Start with `p` to set position (float)");
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

        // Initialize MCP2515 hardware
        MCP2515::ERROR setupErr = can_controller.setup(MCP2515_SPEED, MCP2515_OSC);
        Serial.print("CanController setup: ");
        Serial.println(mcpErrorToString(setupErr));
        Serial.println();

        // Configure CanController
        // Enable automatic heartbeats
        can_controller.set_heartbeat(true);
        can_controller.set_heartbeat_period(heartbeat_interval_ms);

        // Reset motor parameter
        Serial.println("Resetting all motor parameters");
        MCP2515::ERROR reset_err = spark.reset_safe_parameters();
        delay(10);
        Serial.print("SparkMaxQueued reset_safe_parameters: ");
        Serial.println(mcpErrorToString(reset_err));

        // Set motor PID parameter for position control mode
        Serial.println("Setting PID parameters");
        int pid_err = spark.set_pid_p(spark_p);
        pid_err |= spark.set_pid_i(spark_i);
        pid_err |= spark.set_pid_d(spark_d);
        pid_err |= spark.set_pid_f(spark_f);
        if (pid_err != MCP2515::ERROR_OK)
        {
            Serial.println("Error queuing PID parameters");
        }
        else
        {
            Serial.println("PID parameters queued");
        }

        // Flush the queue to ensure all parameters are sent
        Serial.println("Flushing configuration to motor...");
        while (can_controller.has_pending_frames())
        {
            // Sending the queued frames
            can_controller.update(10);
            delay(10);
        }
        Serial.println("Configuration flushed.");
    }

    print_help();
}

void loop()
{
    static float       speed        = 0;
    static float       position     = 0;
    static CommandMode command_mode = Speed;

    // Update the CanController
    // This handles sending the heartbeat and processing the frame queue
    static unsigned long last_update_time = 0;
    unsigned long        now              = millis();
    unsigned long        dt               = now - last_update_time;
    last_update_time                      = now;

    can_controller.update(dt);

    // Send updates to the motor
    static unsigned long speed_last_sent = 0;
    if (now - speed_last_sent >= update_inteval_ms)
    {
        switch (command_mode)
        {
        case Speed:
            spark.set_duty_cycle(speed);
            break;
        case Position:
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
