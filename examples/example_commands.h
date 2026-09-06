#pragma once

#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#if defined(ARDUINO)
#include <Arduino.h>
#endif

namespace CanControl
{
    /**
     * @brief Tagged union representing a command parsed from serial input.
     */
    struct Command
    {
        enum class Type : uint8_t
        {
            Invalid = 0,
            Help,
            Stop,
            DutyCycle,
            Speed = DutyCycle,
            Position,
            HomingStart,
            HomingCancel,
        };

        static constexpr Type Speed = Type::DutyCycle;

        Type    type;
        uint8_t target_id; // 0 = all motors or default single motor, 1..N = specific motor

        union
        {
            float value;
            float duty_cycle;
            float speed;
            float position;
        };

        Command() : type(Type::Invalid), target_id(0), value(0.0f) {}

        explicit Command(Type t, uint8_t id = 0, float val = 0.0f) : type(t), target_id(id), value(val) {}

        bool is_valid() const
        {
            return type != Type::Invalid;
        }
    };

    /**
     * @brief Parses a text line into a Command tagged union.
     *        Syntax:
     *        - 'h': help
     *        - 'x' or '<id>x': stop
     *        - 's<val>' or '<id>s<val>': set duty cycle/speed (clamped to [-1.0, 1.0])
     *        - 'p<val>' or '<id>p<val>': set position
     *        - 'z': homing start
     *        - 'c': homing cancel
     *
     * @param line Null-terminated input string (e.g. from 24-byte line buffer).
     * @param print_errors Whether to print errors to Serial on Arduino.
     * @return Command The parsed tagged union command.
     */
    inline Command parse_command(const char* line, bool print_errors = true)
    {
        if (line == nullptr)
        {
            return Command();
        }

        const char* cursor = line;
        while (*cursor == ' ' || *cursor == '\t')
        {
            ++cursor;
        }

        if (*cursor == '\0')
        {
            return Command();
        }

        // Optional leading target motor ID (e.g. "1s0.5" -> target_id = 1, "s0.5" -> target_id = 0)
        uint8_t target_id = 0;
        while (*cursor >= '0' && *cursor <= '9')
        {
            target_id = static_cast<uint8_t>(target_id * 10 + (*cursor - '0'));
            ++cursor;
        }

        while (*cursor == ' ' || *cursor == '\t')
        {
            ++cursor;
        }

        const char c = *cursor;

        if (c == 'h' && cursor[1] == '\0')
        {
            return Command(Command::Type::Help, target_id);
        }

        if (c == 'x' && cursor[1] == '\0')
        {
            return Command(Command::Type::Stop, target_id, 0.0f);
        }

        if (c == 'z' && cursor[1] == '\0')
        {
            return Command(Command::Type::HomingStart, target_id);
        }

        if (c == 'c' && cursor[1] == '\0')
        {
            return Command(Command::Type::HomingCancel, target_id);
        }

        if (c != 's' && c != 'p')
        {
#if defined(ARDUINO)
            if (print_errors)
            {
                Serial.println(F("Unknown command; use h for help."));
            }
#else
            (void)print_errors;
#endif
            return Command();
        }

        ++cursor;
        while (*cursor == ' ' || *cursor == '\t')
        {
            ++cursor;
        }

        char* end   = nullptr;
        float value = static_cast<float>(strtod(cursor, &end));
        while (end != nullptr && (*end == ' ' || *end == '\t'))
        {
            ++end;
        }

        if (end == cursor || (end != nullptr && *end != '\0') || !isfinite(value))
        {
#if defined(ARDUINO)
            if (print_errors)
            {
                Serial.println(F("Invalid number."));
            }
#endif
            return Command();
        }

        if (c == 's')
        {
            if (value < -1.0f)
            {
                value = -1.0f;
            }
            else if (value > 1.0f)
            {
                value = 1.0f;
            }
            return Command(Command::Type::DutyCycle, target_id, value);
        }
        else
        {
            return Command(Command::Type::Position, target_id, value);
        }
    }

} // namespace CanControl
