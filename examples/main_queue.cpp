/**
 * CanControl example - William Guimont-Martin 2025-2026 (https://github.com/willGuimont/CanControl)
 * Example showing how to setup and use FRC CAN motors using Arduino chips with the queued CanController.
 *
 * See README.md for wiring.
 */
#include "CanControl.h"
#include "can_controller.h"
#include "example_commands.h"
#include "motors_queued/sparkmax_queued.h"

#include <SPI.h>
#include <math.h>
#include <mcp2515.h>
#include <stdlib.h>
#include <string.h>

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
#ifdef CANCONTROL_MCP2515_CS_PIN
static constexpr uint8_t MCP2515_CS_PIN = CANCONTROL_MCP2515_CS_PIN;
#else
#if defined(ARDUINO_AVR_MEGA2560) || defined(__AVR_ATmega2560__) || defined(ARDUINO_AVR_MEGA)
static constexpr uint8_t MCP2515_CS_PIN = 53;
#elif defined(ARDUINO_AVR_UNO) || defined(__AVR_ATmega328P__) || defined(ARDUINO_AVR_NANO)
static constexpr uint8_t MCP2515_CS_PIN = 10;
#else
#warning "Unknown board: defaulting MCP2515_CS_PIN to 10. Define CANCONTROL_MCP2515_CS_PIN to override."
static constexpr uint8_t MCP2515_CS_PIN = 10;
#endif
#endif

// Controller to the MCP2515 chip
static MCP2515 mcp2515(MCP2515_CS_PIN, SPI_CLOCK_SPEED);

// The CanController handles queuing frames and sending heartbeats
static CanController can_controller(mcp2515);

// Creating the motors array (IDs 1..4), bound to the CanController
static SparkMaxQueued motors[4] = {{can_controller, 1}, {can_controller, 2}, {can_controller, 3}, {can_controller, 4}};

enum class MotorCommandMode : uint8_t
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

static void print_help();

static void apply_command(const Command& cmd)
{
    switch (cmd.type)
    {
    case Command::Type::Help:
        print_help();
        break;

    case Command::Type::Stop:
    case Command::Type::DutyCycle:
    case Command::Type::Position:
    {
        const MotorCommandMode mode =
            (cmd.type == Command::Type::Position) ? MotorCommandMode::Position : MotorCommandMode::Speed;
        const float val = (cmd.type == Command::Type::Stop) ? 0.0f : cmd.value;

        if (cmd.target_id >= 1 && cmd.target_id <= 4)
        {
            const uint8_t idx = cmd.target_id - 1;
            motor_mode[idx]   = mode;
            if (mode == MotorCommandMode::Speed)
            {
                motor_speeds[idx] = val;
            }
            else
            {
                motor_positions[idx] = val;
            }
            Serial.print(F("Set motor "));
            Serial.print(cmd.target_id);
        }
        else
        {
            for (int i = 0; i < 4; ++i)
            {
                motor_mode[i] = mode;
                if (mode == MotorCommandMode::Speed)
                {
                    motor_speeds[i] = val;
                }
                else
                {
                    motor_positions[i] = val;
                }
            }
            Serial.print(F("Set ALL motors "));
        }
        Serial.print(mode == MotorCommandMode::Speed ? F("speed: ") : F("position: "));
        Serial.println(val);
        break;
    }

    default:
        break;
    }
}

static void read_commands()
{
    static char    line[24];
    static uint8_t length   = 0;
    static bool    overflow = false;

    for (uint8_t count = 0; count < sizeof(line) && Serial.available(); ++count)
    {
        const char c = Serial.read();
        if (c == '\n' || c == '\r')
        {
            line[length] = '\0';
            if (overflow)
            {
                Serial.println(F("Command too long."));
            }
            else if (length != 0)
            {
                const Command cmd = parse_command(line);
                if (cmd.is_valid())
                {
                    apply_command(cmd);
                }
            }
            length   = 0;
            overflow = false;
        }
        else if (length < sizeof(line) - 1 && !overflow)
        {
            line[length++] = c;
        }
        else
        {
            overflow = true;
        }
    }
}

// Utility to show MCP2515 errors as strings
static const String mcpErrorToString(MCP2515::ERROR e)
{
    switch (e)
    {
    case MCP2515::ERROR_OK:
        return F("OK");
    case MCP2515::ERROR_FAIL:
        return F("ERROR_FAIL");
    case MCP2515::ERROR_ALLTXBUSY:
        return F("ERROR_ALLTXBUSY");
    case MCP2515::ERROR_FAILINIT:
        return F("ERROR_FAILINIT");
    case MCP2515::ERROR_FAILTX:
        return F("ERROR_FAILTX");
    case MCP2515::ERROR_NOMSG:
        return F("ERROR_NOMSG");
    default:
        return F("ERROR_UNKNOWN");
    }
}

// Controller operations use their own scoped error type; motor and MCP2515 calls
// retain MCP2515::ERROR. Keep both formatters here so this sketch is self-contained.
static const __FlashStringHelper* controllerErrorToString(CanController::Error error)
{
    switch (error)
    {
    case CanController::Error::Ok:
        return F("Ok");
    case CanController::Error::TransportFailure:
        return F("TransportFailure");
    case CanController::Error::TransmitBusy:
        return F("TransmitBusy");
    case CanController::Error::InitializationFailed:
        return F("InitializationFailed");
    case CanController::Error::TransmitFailed:
        return F("TransmitFailed");
    case CanController::Error::NoMessage:
        return F("NoMessage");
    case CanController::Error::QueueFull:
        return F("QueueFull");
    case CanController::Error::InvalidArgument:
        return F("InvalidArgument");
    case CanController::Error::SenderLimitReached:
        return F("SenderLimitReached");
    case CanController::Error::AlreadyRegistered:
        return F("AlreadyRegistered");
    case CanController::Error::NotRegistered:
        return F("NotRegistered");
    case CanController::Error::Timeout:
        return F("Timeout");
    default:
        return F("Unknown");
    }
}

static constexpr unsigned long heartbeat_interval_ms = 19;
static constexpr unsigned long update_interval_ms    = 5;

void print_help()
{
    Serial.println(F("Available commands: "));
    Serial.println(F("\t- Optional leading motor id: e.g. '1s0.5' sets motor 1 speed to 0.5"));
    Serial.println(F("\t- Omit id to affect all: 's0.5' sets all motors speed to 0.5"));
    Serial.println(F("\t- Use 'p' similarly for position, e.g. '2p12.5' or 'p12.5'"));
    Serial.println(F("\t- Use 'x' to stop: e.g. '1x' or 'x'"));
    Serial.println(F("\t- `h` for help"));
    Serial.println(F("Ready to accept commands..."));
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
        Serial.print(F("Starting CanControl on pin "));
        Serial.println(MCP2515_CS_PIN);

        // Initialize MCP2515 hardware
        CanController::Error setupErr = can_controller.setup(MCP2515_SPEED, MCP2515_OSC);
        Serial.print(F("CanController setup: "));
        Serial.println(controllerErrorToString(setupErr));
        Serial.println();

        // Quick MCP2515 loopback self-test to verify SPI/MCP functionality
        Serial.println(F("Running MCP2515 loopback self-test..."));
        {
            MCP2515::ERROR e = mcp2515.setLoopbackMode();
            Serial.print(F("setLoopbackMode: "));
            Serial.println(mcpErrorToString(e));

            struct can_frame tf{};
            tf.can_id  = 0x123;
            tf.can_dlc = 1;
            tf.data[0] = 0x42;

            MCP2515::ERROR sres = mcp2515.sendMessage(&tf);
            Serial.print(F("loopback sendMessage: "));
            Serial.println(mcpErrorToString(sres));

            struct can_frame rf{};
            MCP2515::ERROR   rres = mcp2515.readMessage(&rf);
            Serial.print(F("loopback readMessage: "));
            Serial.println(mcpErrorToString(rres));
            if (rres == MCP2515::ERROR_OK)
            {
                Serial.print(F("Loopback received id=0x"));
                Serial.print(rf.can_id, HEX);
                Serial.print(F(" data[0]="));
                Serial.println(rf.data[0], HEX);
            }

            // Restore normal one-shot mode for operation
            mcp2515.setNormalOneShotMode();
        }

        // Configure CanController
        // Enable automatic heartbeats
        can_controller.set_heartbeat(true);
        can_controller.set_heartbeat_period(heartbeat_interval_ms);

        // Reset and configure all motors. All calls go through the CanController
        // queue, so reset is guaranteed to arrive before PID on every motor.
        Serial.println(F("Queuing reset and PID parameters"));
        for (int i = 0; i < 4; ++i)
        {
            MCP2515::ERROR reset_error = motors[i].reset_safe_parameters();

            MCP2515::ERROR e1 = motors[i].set_pid_p(spark_p);
            MCP2515::ERROR e2 = motors[i].set_pid_i(spark_i);
            MCP2515::ERROR e3 = motors[i].set_pid_d(spark_d);
            MCP2515::ERROR e4 = motors[i].set_pid_f(spark_f);

            if (reset_error != MCP2515::ERROR_OK || e1 != MCP2515::ERROR_OK || e2 != MCP2515::ERROR_OK ||
                e3 != MCP2515::ERROR_OK || e4 != MCP2515::ERROR_OK)
            {
                Serial.print(F("Error queuing configuration for motor "));
                Serial.println(i + 1);
            }
            // Drain each motor's five configuration frames before adding the next
            // motor, so the Uno's eight-frame queue does not overflow.
            const CanController::Error flush_error = can_controller.flush();
            if (flush_error != CanController::Error::Ok)
            {
                Serial.print(F("Configuration flush: "));
                Serial.println(controllerErrorToString(flush_error));
                return;
            }
        }

        Serial.println(F("Configuration flushed."));
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

    const CanController::Error update_error = can_controller.update(dt);
    // Report changes only, avoiding repeated serial output during a persistent fault.
    static CanController::Error previous_error = CanController::Error::Ok;
    if (update_error != previous_error)
    {
        Serial.print(F("CanController update: "));
        Serial.println(controllerErrorToString(update_error));
        previous_error = update_error;
    }

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

    read_commands();
}
