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

CanControl offers two control paradigms:

| Approach | Header | Description | Recommended For |
| :--- | :--- | :--- | :--- |
| **Direct** | `<CanControl.h>` | Immediate execution via `MCP2515` | Single motor, simple sketches |
| **Queued** | `<can_controller.h>` + `<motors_queued/...>` | Rate-limited, round-robin scheduler | Multi-motor setups, background heartbeats |

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

> [!NOTE]
> **RAM Limits on Arduino Uno**: The default 64-frame queue uses ~1 KB of SRAM. On ATmega328P (Uno), set `-DCANCONTROL_QUEUE_SIZE=8` in `platformio.ini` or use an Arduino Mega 2560 for multi-motor applications.

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

- **`gen.py`**: Auto-generates low-level protocol wrappers from REV JSON specifications:
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
