# CanControl

[![CI](https://github.com/willGuimont/CanControl/actions/workflows/ci.yml/badge.svg)](https://github.com/willGuimont/CanControl/actions/workflows/ci.yml)
[![PlatformIO Registry](https://badges.registry.platformio.org/packages/willguimont/library/CanControl.svg)](https://registry.platformio.org/libraries/willguimont/CanControl)

**CanControl** is an Arduino library for controlling FRC CAN motor controllers using an SPI-based **MCP2515 CAN module**, no roboRIO required.

[Project homepage](https://willguimont.com/projects/cancontrol/).

## Supported controllers

| Controller | Support |
| :--- | :--- |
| REV Spark MAX | High-level control and generated low-level bindings from [REV-Specs](https://github.com/REVrobotics/REV-Specs) |
| CTRE Talon SRX / Victor SPX | PercentOutput only, based on CTRE's public [HERO example](https://github.com/CrossTheRoadElec/Phoenix5-Examples/blob/master/HERO%20C%23/HERO%20Low%20Level%20Percent%20Output%20Example/Program.cs) |

## Hardware and wiring

You need an Arduino Uno or Mega, an MCP2515 CAN module, and a supported motor controller.
The quick start below uses a **Mega, Spark MAX with CAN ID 1, and an 8 MHz MCP2515 module**.

### MCP2515 Pinout

| Pin | Arduino Uno | Arduino Mega | Description |
| :--- | :--- | :--- | :--- |
| **VCC** | 5V | 5V | Power |
| **GND** | GND | GND | Ground |
| **CS** | **10** | **53** | Chip Select |
| **SO (MISO)** | 12 | 50 | SPI Data Out |
| **SI (MOSI)** | 11 | 51 | SPI Data In |
| **SCK** | 13 | 52 | SPI Clock |

### CAN Bus Wiring

1. **CAN-H**: MCP2515 `H` -> Motor Controller **Yellow** wire.
2. **CAN-L**: MCP2515 `L` -> Motor Controller **Green** wire.
3. **Bus Termination**: Place a **120Ω resistor** across CAN-H and CAN-L at each physical end of the bus (MCP2515 boards usually have an onboard jumper for one end).
4. **Oscillator Frequency**: Set `MCP_8MHZ`, `MCP_16MHZ`, or `MCP_20MHZ` to match the physical crystal on your MCP2515 board.

> [!NOTE]
> **REV Spark MAX Configuration**:
> Configure device CAN IDs, motor type (Brushed/Brushless), idle mode, and firmware using the [REV Hardware Client](https://docs.revrobotics.com/rev-hardware-client/ion/spark-max) over a direct USB-C connection to your PC.

> [!IMPORTANT]
> **CTRE Configuration & FRC Lock**:
> - **CAN ID Setup**: Set the device CAN ID using [CTRE Phoenix Tuner](https://v6.docs.ctr-electronics.com/en/stable/docs/tuner/index.html), typically while connected to a roboRIO or CTRE CAN interface.
> - **FRC Lock & Unlocking**: Whenever a CTRE motor controller operates on an FRC network with a roboRIO, it automatically becomes **FRC locked** and persists this state across power cycles, causing it to ignore non-FRC control frames. To use it with CanControl, disconnect it from the roboRIO, then power on the controller while holding the reset (B/C) button for ~5 seconds until the LED blinks green to unlock the device.

## Quick start

### 1. Install

Add CanControl to your project's `platformio.ini`:

```ini
[env:mega]
platform = atmelavr
framework = arduino
board = megaatmega2560
lib_deps =
    willguimont/CanControl@^1.3.2
```

### 2. Run one motor

Put this sketch in `src/main.cpp`. It commands 25% duty cycle while sending
periodic heartbeats. Match the CS pin and oscillator to your wiring; for Uno,
use `board = uno` above and CS pin `10` below.

```cpp
#include <CanControl.h>
#include <SPI.h>
#include <mcp2515.h>

MCP2515 mcp2515(53, 4000000UL); // Mega CS pin 53, 4 MHz SPI
CanControl::SparkMax motor(mcp2515, 1);

void setup()
{
    mcp2515.reset();
    mcp2515.setBitrate(CAN_1000KBPS, MCP_8MHZ); // Match module oscillator
    mcp2515.setNormalOneShotMode();
}

void loop()
{
    static unsigned long last_heartbeat = 0;
    if (millis() - last_heartbeat >= 20)
    {
        CanControl::send_heartbeat(mcp2515, CanControl::default_heartbeat());
        last_heartbeat = millis();
    }

    motor.set_duty_cycle(0.25f);

    delay(5);
}
```

Upload with `pio run -e mega -t upload`.
This minimal sketch omits error reporting; the [full example](examples/main.cpp)
includes initialization checks and serial diagnostics.

## Other APIs and examples

| API | Header | Use when |
| :--- | :--- | :--- |
| Direct | `<CanControl.h>` | Controlling one motor with a simple sketch, as above |
| Queued | `<can_controller.h>` + `<motors_queued/...>` | Controlling multiple motors with automatic scheduling |
| Stateless commands | `<commands.h>` | Minimizing memory use and managing scheduling yourself |

Direct and stateless calls require you to schedule heartbeats and space commands
to avoid filling the MCP2515 transmit buffers. Queued control handles this when
you call `can_controller.update(dt_ms)` regularly from `loop()`; it does not run
in the background.

For CTRE motors, periodic global enable is also required. See
[examples](examples/README.md) for CTRE calls, complete sketches, serial commands,
and memory measurements.

## Troubleshooting

| Symptom | What to check |
| :--- | :--- |
| Bus errors | CAN-H/CAN-L wiring and 120Ω termination at each end |
| No traffic | CS pin, SPI wiring, and oscillator setting (`MCP_8MHZ`, `MCP_16MHZ`, or `MCP_20MHZ`) |
| Motor does not enable | Configured CAN ID, periodic heartbeat, and CTRE global enable / FRC lock where applicable |
| Intermittent operation | Heartbeat timing, command spacing, and regular `update()` calls in queued mode |

## Development

See [CONTRIBUTING.md](CONTRIBUTING.md) for tests, protocol generation, CAN logging
tools, and publishing instructions.

## License

[GNU General Public License v3.0 only](LICENSE) (`GPL-3.0-only`).
