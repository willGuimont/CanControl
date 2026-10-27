# Examples

See the [hardware setup](../README.md#hardware-and-wiring) before uploading.
Run these commands from the repository root after [cloning](../CONTRIBUTING.md).

## Choose an example

| Example | Source | Uno environment | Mega environment |
| :--- | :--- | :--- | :--- |
| One Spark MAX, position control, homing, and telemetry | [main.cpp](main.cpp) | `uno` | `mega` |
| Four Spark MAX motors with automatic scheduling | [main_queue.cpp](main_queue.cpp) | `uno_queue` | `mega_queue` |
| Four Spark MAX motors with manual scheduling | [main_commands.cpp](main_commands.cpp) | `uno_commands` | `mega_commands` |

For example, upload the queued sketch to a Mega and open its serial monitor:

```bash
pio run -e mega_queue -t upload
pio device monitor -b 115200
```

Replace `mega_queue` with another environment from the table as needed.
The examples default to CS pin 10 on Uno and 53 on Mega. To override it, append
`-DCANCONTROL_MCP2515_CS_PIN=<pin>` to the environment's existing `build_flags`.
Match the oscillator setting in the sketch to your MCP2515 module.

## Scheduling and CTRE motors

Direct and stateless APIs attempt each transmission once and return
`MCP2515::ERROR`; the caller handles errors, retries, and timing. Send heartbeats
about every 20 ms and space motor commands (the examples use about 5 ms).
For multiple motors, use round-robin updates to avoid exhausting transmit buffers.

The queued API handles scheduling and retries when you call
`can_controller.update(dt_ms)` regularly from `loop()`, passing elapsed milliseconds.
It does not run in a background thread. Avoid blocking the loop.

For Talon SRX or Victor SPX, send CTRE global enable about every 20 ms:

- Direct: `CanControl::TalonSrx::send_global_enable(mcp2515, true)`.
- Stateless: `CanControl::Commands::send_ctre_global_enable(mcp2515, true)`.
- Queued: call `can_controller.set_ctre_global_enable(true)` during setup;
  use `<motors_queued/talonsrx_queued.h>` or `<motors_queued/victorspx_queued.h>`.

## Serial commands

Send commands at **115200 baud**, ending each line with a newline.
Omit the ID (or use 0) to target all/default motors. The basic sketch accepts its
configured motor ID; the queued and stateless sketches accept IDs 1–4.
Unsupported IDs are rejected without changing motor commands.

| Command | Syntax | Example | Description |
| :--- | :--- | :--- | :--- |
| **Speed / Duty Cycle** | `[<id>]s<float>` | `s0.25` or `1s0.5` | Set duty cycle / speed [-1.0, 1.0] |
| **Position** | `[<id>]p<float>` | `p12.5` or `2p-5.0` | Set position setpoint |
| **Stop** | `[<id>]x` | `x` or `1x` | Stop motor(s) |
| **Help** | `h` | `h` | Print available commands |
| **Homing Start** | `z` | `z` | Start homing (main.cpp) |
| **Homing Cancel** | `c` | `c` | Cancel homing and stop (main.cpp) |

## Memory use

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

- **Basic OOP** ([`examples/main.cpp`](main.cpp)): one Spark MAX, serial
  commands, position control, and homing with received telemetry.
- **Queued OOP** ([`examples/main_queue.cpp`](main_queue.cpp)): four
  Spark MAX motors, per-motor commands, and automatic scheduling. The Uno build
  uses an eight-frame queue (`-DCANCONTROL_QUEUE_SIZE=8`); the Mega build uses the default 64 frames.
- **Stateless commands** ([`examples/main_commands.cpp`](main_commands.cpp)):
  four Spark MAX motors with per-motor setpoints, manual round-robin scheduling, and a
  fixed serial input buffer. No motor objects or configuration queue.

These examples have different features, so their totals illustrate practical
memory use rather than comparing identical workloads. The standalone CAN sniffer
is not included because it has no configured PlatformIO build environment.

