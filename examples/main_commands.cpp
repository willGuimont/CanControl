/**
 * Stateless commands example: four Spark MAX motors, no motor objects or queue.
 * Copy this file into an Arduino/PlatformIO sketch with CanControl installed.
 * Serial commands (115200 baud): s0.25 duty cycle, p12.5 position, x stop, h help.
 * Commands apply to all four motors. See README.md for wiring.
 */
#include "example_commands.h"

#include <SPI.h>
#include <commands.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

using namespace CanControl;
namespace SparkCommands = CanControl::Commands::SparkMax;

#ifdef CANCONTROL_MCP2515_CS_PIN
static constexpr uint8_t CS_PIN = CANCONTROL_MCP2515_CS_PIN;
#elif defined(__AVR_ATmega2560__)
static constexpr uint8_t CS_PIN = 53;
#else
static constexpr uint8_t CS_PIN = 10;
#endif

static MCP2515                 mcp(CS_PIN, 4000000UL);
static constexpr CAN_CLOCK     MCP_OSC               = MCP_8MHZ; // Match your module's crystal.
static constexpr uint8_t       MOTOR_COUNT           = 4;        // Device IDs 1..4.
static constexpr unsigned long SEND_INTERVAL_MS      = 5;
static constexpr unsigned long HEARTBEAT_INTERVAL_MS = 20;
static bool                    ready                 = false;
static bool                    position_mode         = false;
static float                   setpoint              = 0.0f;

static void print_help()
{
    Serial.println(F("s0.25 = duty, p12.5 = position, x = stop, h = help (all motors)"));
}

static bool check(MCP2515::ERROR error)
{
    if (error == MCP2515::ERROR_OK)
        return true;
    Serial.print(F("CAN error: "));
    Serial.println(static_cast<int>(error));
    return false;
}

// Configuration is sent synchronously, with spacing between frames. Abort on failure.
static bool configure_motors()
{
    for (uint8_t id = 1; id <= MOTOR_COUNT; ++id)
    {
        if (!check(SparkCommands::reset_safe_parameters(mcp, id)))
            return false;
        delay(10);
        if (!check(SparkCommands::set_pid_p(mcp, id, 0.1f)))
            return false;
        delay(10);
        if (!check(SparkCommands::set_pid_i(mcp, id, 0.0f)))
            return false;
        delay(10);
        if (!check(SparkCommands::set_pid_d(mcp, id, 0.0f)))
            return false;
        delay(10);
        if (!check(SparkCommands::set_pid_f(mcp, id, 0.0f)))
            return false;
        delay(10);
    }
    return true;
}

void setup()
{
    Serial.begin(115200);
    if (!check(mcp.reset()))
        return;
    delay(10);
    if (!check(mcp.setBitrate(CAN_1000KBPS, MCP_OSC)))
        return;
    delay(10);
    if (!check(mcp.setNormalOneShotMode()))
        return;
    delay(10);
    ready = configure_motors();
    if (ready)
        print_help();
}

static void apply_command(const Command& cmd)
{
    switch (cmd.type)
    {
    case Command::Type::Help:
        print_help();
        break;
    case Command::Type::Stop:
        setpoint      = 0.0f;
        position_mode = false;
        break;
    case Command::Type::DutyCycle:
        position_mode = false;
        setpoint      = cmd.duty_cycle;
        break;
    case Command::Type::Position:
        position_mode = true;
        setpoint      = cmd.position;
        break;
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

void loop()
{
    if (!ready)
        return;
    read_commands();

    // The stateless API does not schedule or retain commands. Send at most one
    // frame every 5 ms, prioritizing heartbeat, then round-robin motor commands.
    static unsigned long last_send      = 0;
    static unsigned long last_heartbeat = 0;
    static uint8_t       next_motor     = 1;
    const unsigned long  now            = millis();
    if (now - last_send < SEND_INTERVAL_MS)
        return;
    last_send = now; // Rate-limit failed attempts as well as successful sends.

    if (now - last_heartbeat >= HEARTBEAT_INTERVAL_MS)
    {
        if (send_heartbeat(mcp, default_heartbeat()) == MCP2515::ERROR_OK)
            last_heartbeat = now;
        return;
    }

    const MCP2515::ERROR result = position_mode ? SparkCommands::set_position(mcp, next_motor, setpoint)
                                                : SparkCommands::set_duty_cycle(mcp, next_motor, setpoint);
    // Retry the same motor on failure. The current setpoint is retained by this
    // example until another serial command changes it; there is no input timeout.
    if (result == MCP2515::ERROR_OK)
        next_motor = next_motor == MOTOR_COUNT ? 1 : next_motor + 1;

    // For CTRE controllers, use Commands::TalonSrx::set_percent_output() or
    // Commands::VictorSpx::set_percent_output(), and schedule
    // Commands::send_ctre_global_enable(mcp, true) every ~20 ms as well.
}
