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

// Creating the motors array (IDs 1..4), bound to the CanController
static SparkMaxQueued motors[4] = {{can_controller, 1}, {can_controller, 2}, {can_controller, 3}, {can_controller, 4}};

// Command mode enum (used by per-motor state)
enum class MotorCommandMode
{
    Speed,
    Position,
};

// Per-motor state
static float            motor_speeds[4]    = {0, 0, 0, 0};
static float            motor_positions[4] = {0, 0, 0, 0};
static MotorCommandMode motor_mode[4]      = {MotorCommandMode::Speed, MotorCommandMode::Speed, MotorCommandMode::Speed,
                                              MotorCommandMode::Speed};

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
static constexpr unsigned long update_interval_ms    = 5;

void print_help()
{
    Serial.println("Available commands: ");
    Serial.println("\t- Optional leading motor id: e.g. '1s0.5' sets motor 1 speed to 0.5");
    Serial.println("\t- Omit id to affect all: 's0.5' sets all motors speed to 0.5");
    Serial.println("\t- Use 'p' similarly for position, e.g. '2p12.5' or 'p12.5'");
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
        Serial.println(MCP2515_CS_PIN);

        // Initialize MCP2515 hardware
        MCP2515::ERROR setupErr = can_controller.setup(MCP2515_SPEED, MCP2515_OSC);
        Serial.print("CanController setup: ");
        Serial.println(mcpErrorToString(setupErr));
        Serial.println();

        // Quick MCP2515 loopback self-test to verify SPI/MCP functionality
        Serial.println("Running MCP2515 loopback self-test...");
        {
            MCP2515::ERROR e = mcp2515.setLoopbackMode();
            Serial.print("setLoopbackMode: ");
            Serial.println(mcpErrorToString(e));

            struct can_frame tf{};
            tf.can_id  = 0x123;
            tf.can_dlc = 1;
            tf.data[0] = 0x42;

            MCP2515::ERROR sres = mcp2515.sendMessage(&tf);
            Serial.print("loopback sendMessage: ");
            Serial.println(mcpErrorToString(sres));

            struct can_frame rf{};
            MCP2515::ERROR   rres = mcp2515.readMessage(&rf);
            Serial.print("loopback readMessage: ");
            Serial.println(mcpErrorToString(rres));
            if (rres == MCP2515::ERROR_OK)
            {
                Serial.print("Loopback received id=0x");
                Serial.print(rf.can_id, HEX);
                Serial.print(" data[0]=");
                Serial.println(rf.data[0], HEX);
            }

            // Restore normal one-shot mode for operation
            mcp2515.setNormalOneShotMode();
        }

        // Configure CanController
        // Enable automatic heartbeats
        can_controller.set_heartbeat(true);
        can_controller.set_heartbeat_period(heartbeat_interval_ms);

        // Reset motor parameters for all motors
        Serial.println("Resetting all motor parameters");
        for (int i = 0; i < 4; ++i)
        {
            MCP2515::ERROR reset_err = motors[i].reset_safe_parameters();
            delay(10);
            Serial.print("Motor ");
            Serial.print(i + 1);
            Serial.print(" reset_safe_parameters: ");
            Serial.println(mcpErrorToString(reset_err));
        }

        // Set motor PID parameters for position control mode on all motors
        Serial.println("Setting PID parameters");
        for (int i = 0; i < 4; ++i)
        {
            MCP2515::ERROR e1 = motors[i].set_pid_p(spark_p);
            MCP2515::ERROR e2 = motors[i].set_pid_i(spark_i);
            MCP2515::ERROR e3 = motors[i].set_pid_d(spark_d);
            MCP2515::ERROR e4 = motors[i].set_pid_f(spark_f);

            if (e1 != MCP2515::ERROR_OK || e2 != MCP2515::ERROR_OK || e3 != MCP2515::ERROR_OK ||
                e4 != MCP2515::ERROR_OK)
            {
                Serial.print("Error queuing PID parameters for motor ");
                Serial.println(i + 1);
            }
            else
            {
                Serial.print("PID parameters queued for motor ");
                Serial.println(i + 1);
            }
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
    // Per-motor state arrays are declared globally; we use them here.

    // Update the CanController
    // This handles sending the heartbeat and processing the frame queue
    static unsigned long last_update_time = 0;
    unsigned long        now              = millis();
    unsigned long        dt               = now - last_update_time;
    last_update_time                      = now;

    can_controller.update(dt);

    // Send updates to motors (periodic send)
    static unsigned long last_sent = 0;
    if (now - last_sent >= update_interval_ms)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (motor_mode[i] == MotorCommandMode::Speed)
            {
                motors[i].set_duty_cycle(motor_speeds[i]);
            }
            else if (motor_mode[i] == MotorCommandMode::Position)
            {
                motors[i].set_position(motor_positions[i]);
            }
        }
        last_sent = now;
    }

    // Small serial interface to control motors
    static String inBuf = "";
    while (Serial.available())
    {
        char c = Serial.read();
        if (c == '\n' || c == '\r')
        {
            if (inBuf.length() >= 1)
            {
                String cmd = inBuf;
                int    p   = 0;
                int    len = cmd.length();

                // Parse optional leading motor id (digits). If none, target all motors.
                int targetId = 0; // 0 == all motors
                while (p < len && isDigit(cmd[p]))
                {
                    targetId = targetId * 10 + (cmd[p] - '0');
                    p++;
                }

                // skip spaces
                while (p < len && isSpace(cmd[p]))
                    p++;

                if (p < len)
                {
                    char   action = cmd[p];
                    String arg    = cmd.substring(p + 1);
                    arg.trim();

                    if (action == 's')
                    {
                        float val = arg.toFloat();
                        if (val > 1.0f)
                            val = 1.0f;
                        if (val < -1.0f)
                            val = -1.0f;

                        if (targetId >= 1 && targetId <= 4)
                        {
                            motor_speeds[targetId - 1] = val;
                            motor_mode[targetId - 1]   = MotorCommandMode::Speed;
                            Serial.print("Set motor ");
                            Serial.print(targetId);
                            Serial.print(" speed: ");
                            Serial.println(val);
                        }
                        else
                        {
                            for (int i = 0; i < 4; ++i)
                            {
                                motor_speeds[i] = val;
                                motor_mode[i]   = MotorCommandMode::Speed;
                            }
                            Serial.print("Set ALL motors speed: ");
                            Serial.println(val);
                        }
                    }
                    else if (action == 'p')
                    {
                        float val = arg.toFloat();

                        if (targetId >= 1 && targetId <= 4)
                        {
                            motor_positions[targetId - 1] = val;
                            motor_mode[targetId - 1]      = MotorCommandMode::Position;
                            Serial.print("Set motor ");
                            Serial.print(targetId);
                            Serial.print(" position: ");
                            Serial.println(val);
                        }
                        else
                        {
                            for (int i = 0; i < 4; ++i)
                            {
                                motor_positions[i] = val;
                                motor_mode[i]      = MotorCommandMode::Position;
                            }
                            Serial.print("Set ALL motors position: ");
                            Serial.println(val);
                        }
                    }
                    else if (action == 'h')
                    {
                        print_help();
                    }
                }

                inBuf = "";
            }
        }
        else
        {
            inBuf += c;
        }
    }
}
