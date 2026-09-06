# CanControl

[![CI](https://github.com/willGuimont/CanControl/actions/workflows/ci.yml/badge.svg)](https://github.com/willGuimont/CanControl/actions/workflows/ci.yml)

**CanControl** is an Arduino library for controlling FRC CAN motor controllers using an SPI-based **MCP2515 CAN module**—no roboRIO required.

### Supported Controllers

- [REV Robotics Spark MAX](https://www.revrobotics.com/rev-11-2158/) (Full protocol support thanks to open protocol specification in [REV-Specs](https://github.com/REVrobotics/REV-Specs))
- [CTRE Talon SRX](https://store.ctr-electronics.com/products/talon-srx) (PercentOutput only)
- [CTRE Victor SPX](https://store.ctr-electronics.com/products/victor-spx) (PercentOutput only)

> **Protocol Notes**:
> - **REV Spark MAX**: Complete low-level protocol coverage is generated from REV's open [REV-Specs](https://github.com/REVrobotics/REV-Specs) repository.
> - **CTRE Controllers**: Talon SRX and Victor SPX integration is implemented for PercentOutput using CTRE's public [HERO Low Level Percent Output Example](https://github.com/CrossTheRoadElec/Phoenix5-Examples/blob/master/HERO%20C%23/HERO%20Low%20Level%20Percent%20Output%20Example/Program.cs). No further official low-level CAN protocol documentation was provided by CTRE.

---

## Features

- **High-Level C++ Wrappers**: `SparkMax`, `TalonSrx`, and `VictorSpx` for direct control.
- **Queued & Rate-Limited Architecture**: `CanController` prevents bus saturation, manages SPI transmission queues, and periodic round-robin updates for multi-motor setups.
- **Heartbeat & Enable Scheduling**: Native WPILib universal heartbeat and CTRE global enable generation.
- **Protocol Generation**: Generated low-level protocol bindings from official [REV Specifications](https://github.com/REVrobotics/REV-Specs).

---

## Quick Start

### 1. Add Dependency (`platformio.ini`)

```ini
[env:mega]
platform = atmelavr
framework = arduino
board = megaatmega2560

lib_deps =
    https://github.com/willGuimont/CanControl.git
```

### 2. Code Examples

CanControl offers three ways to send commands:

| Approach | Header | Description | Recommended For |
| :--- | :--- | :--- | :--- |
| **Commands** | `<commands.h>` | Stateless functions; caller manages timing | Uno, small applications, custom scheduling |
| **Direct** | `<CanControl.h>` | Immediate execution via `MCP2515` | Single motor, simple sketches |
| **Queued** | `<can_controller.h>` + `<motors_queued/...>` | Rate-limited, round-robin scheduler | Multi-motor setups, background heartbeats |

#### How to Choose the Best API for Your Project

- **Direct OOP (`<CanControl.h>`)**: Simple and intuitive with dedicated motor objects (`SparkMax`, `TalonSrx`, `VictorSpx`). Ideal for single-motor setups, but in multi-motor setups you must manually manage round-robin spacing and timing in your sketch to avoid filling the MCP2515 transmit buffers too quickly.
- **Queued OOP (`<can_controller.h>` + `<motors_queued/...>`)**: The easiest and most robust choice for multi-motor setups. It automatically handles round-robin scheduling, frame queuing, bus rate limiting, and background heartbeats so you don't have to write timing loops, though it takes more memory (SRAM for the frame queue and periodic sender registrations, see table below).
- **Stateless Commands (`<commands.h>`)**: Extremely lightweight with the lowest possible memory footprint (no motor objects, no status caches, no heap allocation). However, it requires the most manual management: you own all timing, retries, and error handling, AND you must manage the round-robin scheduling between motors and heartbeats yourself.

#### Option A: Direct Control

```cpp
#include <CanControl.h>
#include <SPI.h>
#include <mcp2515.h>

MCP2515 mcp2515(10, 4000000UL); // CS pin 10, 4 MHz SPI
CanControl::SparkMax motor(mcp2515, 1);
// For CTRE motors (Talon SRX / Victor SPX):
// CanControl::TalonSrx talon(mcp2515, 30);

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
        // For CTRE motors, also send global enable every ~20ms:
        // CanControl::TalonSrx::send_global_enable(mcp2515, true);
        last_heartbeat = millis();
    }

    motor.set_duty_cycle(0.25f);
    // For CTRE motor:
    // talon.set_percent_output(0.25f);

    delay(5);
}
```

> **Direct Control Note**: Sending multiple motor commands or heartbeats back-to-back with direct control can fill the MCP2515 transmit buffers faster than frames leave the bus, causing failed transmissions and CAN bus saturation. For multi-motor setups, you must implement round-robin timing manually, or use **Option B (Queued Control)** which manages bus rate limiting and round-robin updates automatically.

#### Option B: Queued Control (Multi-Motor)

```cpp
#include <SPI.h>
#include <can_controller.h>
#include <motors_queued/sparkmax_queued.h>
// For CTRE queued motor headers:
// #include <motors_queued/talonsrx_queued.h>
// #include <motors_queued/victorspx_queued.h>
#include <mcp2515.h>

MCP2515 mcp2515(10, 4000000UL);
CanControl::CanController can_controller(mcp2515);
CanControl::SparkMaxQueued left_motor(can_controller, 1);
CanControl::SparkMaxQueued right_motor(can_controller, 2);
// For CTRE queued motor:
// CanControl::TalonSrxQueued talon_motor(can_controller, 30);

void setup()
{
    can_controller.setup(CAN_1000KBPS, MCP_8MHZ); // Match module oscillator
    can_controller.set_heartbeat(true);
    // For CTRE motors, enable automatic periodic global enable:
    // can_controller.set_ctre_global_enable(true);
}

void loop()
{
    static unsigned long previous = 0;
    unsigned long now = millis();
    can_controller.update(now - previous);
    previous = now;

    left_motor.set_duty_cycle(0.25f);
    right_motor.set_duty_cycle(0.25f);
    // For CTRE queued motor:
    // talon_motor.set_percent_output(0.25f);
}
```

> **CTRE Note**: For Talon SRX or Victor SPX in queued mode, call `can_controller.set_ctre_global_enable(true);` during `setup()`.

#### Option C: Stateless Commands (Smallest Footprint)

Include `<commands.h>` and pass the `MCP2515` instance and device ID directly to each call. There are no motor objects, background schedulers, or heap allocations—giving you the smallest possible flash and SRAM footprint.

```cpp
#include <SPI.h>
#include <commands.h>
#include <mcp2515.h>

MCP2515 mcp2515(10, 4000000UL); // CS pin 10, 4 MHz SPI
namespace SparkCommands = CanControl::Commands::SparkMax;

void setup()
{
    mcp2515.reset();
    mcp2515.setBitrate(CAN_1000KBPS, MCP_8MHZ); // Match module oscillator
    mcp2515.setNormalOneShotMode();
}

void loop()
{
    static unsigned long last_heartbeat = 0;
    static unsigned long last_send      = 0;
    unsigned long        now            = millis();

    // Prioritize periodic heartbeat (~20ms)
    if (now - last_heartbeat >= 20)
    {
        CanControl::send_heartbeat(mcp2515, CanControl::default_heartbeat());
        // For CTRE motors, also send global enable every ~20ms:
        // CanControl::Commands::send_ctre_global_enable(mcp2515, true);
        last_heartbeat = now;
    }
    // Space motor transmissions (>= 5ms) to avoid MCP2515 TX buffer exhaustion
    else if (now - last_send >= 5)
    {
        SparkCommands::set_duty_cycle(mcp2515, 1, 0.25f);
        // For CTRE motor:
        // CanControl::Commands::TalonSrx::set_percent_output(mcp2515, 30, 0.25f);
        last_send = now;
    }
}
```

> [!IMPORTANT]
> **Timing is your responsibility**: Commands attempt a single transmission and return `MCP2515::ERROR` immediately without automatic retries. You must send periodic heartbeats (~20 ms) and space out motor transmissions (e.g., 5 ms) to prevent MCP2515 transmit buffer exhaustion.

See [`examples/main_commands.cpp`](examples/main_commands.cpp) for a complete 4-motor sketch using manual round-robin scheduling.

```bash
pio run -e uno_commands -t upload
# Or:
pio run -e mega_commands -t upload
```

### Serial Command Interface (`examples/example_commands.h`)

All example sketches share a serial command abstraction in
[`examples/example_commands.h`](examples/example_commands.h):

- **Tagged Union (`Command`)**: Represents parsed commands with a type discriminator enum
  (`Help`, `Stop`, `DutyCycle` / `Speed`, `Position`, `HomingStart`, `HomingCancel`),
  an optional `target_id` (0 for all/default motor, 1..N for specific motor), and an
  anonymous union payload for setpoint values (`value`, `duty_cycle`, `speed`, `position`).
- **Parsing (`parse_command`)**: Parses raw serial input strings (e.g. from a 24-byte line
  buffer) into the `Command` tagged union without heap allocation. Validates numbers with
  `strtod`, checks `isfinite()`, and clamps duty cycles to `[-1.0, 1.0]`.
- **Applying Commands (`apply_command`)**: Each example implements its own `apply_command(cmd)`
  locally in the `.cpp` file to match its specific interface (single motor, queued array,
  or stateless round-robin) directly without pointer overhead.
- **Line Buffer**: Sketches use a fixed 24-byte line buffer reading bounded bytes per loop
  to avoid starving CAN communication.

| Command | Syntax | Example | Description |
| :--- | :--- | :--- | :--- |
| **Speed / Duty Cycle** | `[<id>]s<float>` | `s0.25` or `1s0.5` | Set duty cycle / speed [-1.0, 1.0] |
| **Position** | `[<id>]p<float>` | `p12.5` or `2p-5.0` | Set position setpoint |
| **Stop** | `[<id>]x` | `x` or `1x` | Stop motor(s) |
| **Help** | `h` | `h` | Print available commands |
| **Homing Start** | `z` | `z` | Start homing (main.cpp) |
| **Homing Cancel** | `c` | `c` | Cancel homing and stop (main.cpp) |

#### Example Memory Comparison

The table shows static SRAM and flash usage from the compiled examples,
with percentages of each PlatformIO target's available capacity.

| Example | Board | Motors | PlatformIO environment | SRAM used / available | Flash used / available |
| :--- | :--- | ---: | :--- | ---: | ---: |
| Basic OOP | Uno | 1 | `uno` | 977 / 2,048 B (47.7%) | 12,992 / 32,256 B (40.3%) |
| Queued OOP | Uno | 4 | `uno_queue` | 774 / 2,048 B (37.8%) | 14,496 / 32,256 B (44.9%) |
| Stateless commands | Uno | 4 | `uno_commands` | 267 / 2,048 B (13.0%) | 7,902 / 32,256 B (24.5%) |
| Basic OOP | Mega 2560 | 1 | `mega` | 977 / 8,192 B (11.9%) | 13,694 / 253,952 B (5.4%) |
| Queued OOP | Mega 2560 | 4 | `mega_queue` | 1,670 / 8,192 B (20.4%) | 15,248 / 253,952 B (6.0%) |
| Stateless commands | Mega 2560 | 4 | `mega_commands` | 267 / 8,192 B (3.3%) | 8,540 / 253,952 B (3.4%) |

- **Basic OOP** ([`examples/main.cpp`](examples/main.cpp)): one Spark MAX, serial
  commands, position control, and homing with received telemetry.
- **Queued OOP** ([`examples/main_queue.cpp`](examples/main_queue.cpp)): four
  Spark MAX motors, per-motor commands, and automatic scheduling. The Uno build
  uses an eight-frame queue (`-DCANCONTROL_QUEUE_SIZE=8`); the Mega build uses the default 64 frames.
- **Stateless commands** ([`examples/main_commands.cpp`](examples/main_commands.cpp)):
  four Spark MAX motors sharing a setpoint, manual round-robin scheduling, and a
  fixed serial input buffer. No motor objects or configuration queue.

These examples have different features, so their totals illustrate practical
memory use rather than comparing identical workloads. The standalone CAN sniffer
is not included because it has no configured PlatformIO build environment.

---

## Hardware & Wiring

### MCP2515 Pinout

| Pin | Arduino Uno | Arduino Mega | Description |
| :--- | :--- | :--- | :--- |
| **VCC** | 5V | 5V | Power |
| **GND** | GND | GND | Ground |
| **CS** | **10** | **53** | Chip Select (Override with `-DCANCONTROL_MCP2515_CS_PIN=...`) |
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

---

## Development & Tooling

### Building & Running Examples

```bash
# Clone repository
git clone https://github.com/willGuimont/CanControl.git
cd CanControl
git submodule update --init --recursive

# Upload basic example to Arduino Mega
pio run -e mega -t upload

# Upload queued example to Arduino Mega
pio run -e mega_queue -t upload
```

### Running Tests

```bash
# Run native host unit tests
pio test -e native -v
```

### Code Generator & Tools

- **`gen.py`**: Reads `third_party/REV-Specs/can-frames/spark-frames-2.1.0`
  and `third_party/REV-Specs/parameters/SparkParameters-v0.1.2.md`.
  Generates `low_sparkmax.h/.cpp` and `low_sparkmax_params.h/.cpp` under
  `include/low_level/` and `src/low_level/`. Update the generator or specifications
  instead of editing these generated files by hand:
  ```bash
  python gen.py
  ```
- **`tools/can_monitor.py`**: Serial CAN bus monitor and CSV logger:
  ```bash
  python tools/can_monitor.py --port COM3 --output log.csv
  ```
- **`tools/compare_logs.py`**: Compares two CSV traffic logs to analyze frame timing differences or missing messages:
  ```bash
  python tools/compare_logs.py good_log.csv bad_log.csv
  ```

### Publishing to PlatformIO Registry

1. Bump `"version"` in [`library.json`](library.json).
2. Run tests:
   ```bash
   pio test -e native
   ```
3. Log in (first time only):
   ```bash
   pio account login
   ```
4. Publish:
   ```bash
   pio pkg publish
   ```
   *(Or with token in CI: `export PLATFORMIO_AUTH_TOKEN="<token>" && pio pkg publish --no-interactive`)*

---

## Troubleshooting

| Symptom | Cause | Solution |
| :--- | :--- | :--- |
| **Sticky Fault / Bus Error** | Missing bus termination | Add 120Ω resistor between CAN-H and CAN-L at bus ends |
| **Flashing Orange/Green LEDs** | Intermittent frame reception | Check heartbeat frequency (~20ms) and wiring connections |
| **No response / No traffic** | Mismatched crystal clock | Verify if your MCP2515 uses an 8 MHz or 16 MHz crystal |
| **Motor does not enable** | Heartbeat or enable missing | Ensure `send_heartbeat()` or `set_ctre_global_enable()` is running |

---

## License

Distributed under the MIT License. See `LICENSE` for more information.
