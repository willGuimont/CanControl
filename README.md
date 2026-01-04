# CanControl

Control CAN-based motor controllers from Arduino boards using a cheap MCP2515
CAN shield. CanControl currently supports:

- [REV Robotics Spark MAX](https://www.revrobotics.com/rev-11-2158/) (FRC brushless/brushed motor controller)
- [CTRE Talon SRX](https://store.ctr-electronics.com/products/talon-srx) (PercentOutput)
- [CTRE Victor SPX](https://store.ctr-electronics.com/products/victor-spx) (PercentOutput)

All communication goes through an MCP2515 controller on the Arduino SPI bus,
so you do not need a native CAN-capable MCU.

---

## Features

- High-level C++ wrappers:
  - `CanControl::SparkMax`
  - `CanControl::TalonSrxMotor`
  - `CanControl::VictorSpxMotor`
- Auto-generated low-level Spark MAX CAN protocol based on [REV's published
  - JSON spec](https://github.com/REVrobotics/REV-Specs) (see `doc/spark-frames-2.0.0-dev.11.json` and `gen.py`).
- Simple FRC-style heartbeat frame generator.
- CTRE interfacing based on [the only available public documentation of their CAN protocol](https://github.com/CrossTheRoadElec/Phoenix5-Examples/blob/master/HERO%20C%23/HERO%20Low%20Level%20Percent%20Output%20Example/Program.cs)
- Works on Arduino Mega 2560 and Uno (via MCP2515 breakout).

---

## Hardware & Requirements

- Arduino compatible board
  - Tested with: **Arduino Mega 2560** (`env:mega`)
  - Also configured for: **Arduino Uno** (`env:uno`)
- MCP2515 CAN controller breakout (e.g. "TJA1050 + MCP2515" boards)
  - SPI connected to the Arduino (SCK/MOSI/MISO)
  - `CS` pin configurable via `MCP2515_CS_PIN` (defaults to 53 on Mega, 10 on Uno)
- CAN motor controllers on the same CAN bus:
  - Spark MAX (REV Robotics)
  - Talon SRX / Victor SPX (Cross The Road Electronics) (**Needs to be FRC unlocked, see instructions below**)

Wiring is the usual MCP2515+CAN transceiver wiring (CANH/CANL twisted pair,
proper termination at the ends of the bus).

---

## Getting Started (PlatformIO)

This repo is a PlatformIO project. You can use it directly, or add it as a
dependency to another PlatformIO project.

### Cloning and building this repo

```bash
git clone https://github.com/willGuimont/CanControl.git
cd CanControl

# Build for Arduino Mega 2560
pio run -e mega

# (Optional) Upload depending on your upload_port
pio run -e mega -t upload
```

The main example sketch is in `src/main.cpp`. It:

- Configures the MCP2515.
- Creates a single `SparkMax` instance.
- Sends a one-shot "reset safe parameters" to the Spark.
- Listens for Spark Status 0 frames and prints them over serial.
- Lets you type commands over USB serial to change speed/position.

### Using as a library in your own PIO project

In your own `platformio.ini`:

```ini
[env:mega]
platform = atmelavr
framework = arduino
board = megaatmega2560

lib_deps =
    https://github.com/willGuimont/CanControl.git
```

Then in your code:

```cpp
#include "sparkmax.h"

static MCP2515 mcp2515(53);          // CS pin
static constexpr uint8_t kMotorId = 11;
static CanControl::SparkMax motor(mcp2515, kMotorId);

mcp2515.reset();
mcp2515.setBitrate(CAN_1000KBPS, MCP_8MHZ);
mcp2515.setNormalMode();

// Optional: reset user-configurable parameters on the Spark MAX
motor.reset_safe_parameters();

// Run the motor at 25% duty cycle
motor.set_duty_cycle(0.25f);
```

---

## CTRE Talon SRX & Victor SPX

Using CTRE devices requires that they be "FRC unlocked" to accept non-FRC
frames.
The FRC lock will be enabled by default and be persistent across power cycles if the
device was ever connected to an FRC roboRIO.
To unlock the device, you need to disconnect it from the roboRIO and power it while
holding the reset button for about 5 seconds until the LED blinks green.

For CTRE devices there are two layers:

- Low-level helpers in `include/low_level/low_ctrelectronics.h`
- High-level wrappers:
  - `CanControl::TalonSrxMotor` in `include/talonsrx.h`
  - `CanControl::VictorSpxMotor` in `include/victorspx.h`

Example:

```cpp
#include "talonsrx.h"

MCP2515 mcp2515(53);
CanControl::TalonSrxMotor talon(mcp2515, 3);   // CAN ID 3

// MCP2515 init...

// Send CTRE "global enable" (non-FRC frame)
CanControl::TalonSrxMotor::send_global_enable(mcp2515, true);

// 50% PercentOutput
talon.set_percent_output(0.5f);
```

`VictorSpxMotor` works the same way but internally calls a different builder
for the Victor SPX arbitration ID.

---

## Generated Spark MAX Low-Level API

The low-level Spark MAX protocol bindings are generated from
`doc/spark-frames-2.0.0-dev.11.json` (available from [REVrobotics/REV-Specs](https://github.com/REVrobotics/REV-Specs)) by `gen.py` and live in:

- `include/low_level/low_sparkmax.h`
- `src/low_level/low_sparkmax.cpp`

These files are **auto-generated** (see the header comment) and should not be
edited by hand. Instead, update the JSON spec or generator and re-run `gen.py`.

The high-level `SparkMax` class in `include/sparkmax.h` wraps the generated
`SparkCanDevice` and provides friendly methods:

- `set_duty_cycle(float duty)`
- `set_position(float position)`
- `set_velocity(float velocity)`
- `reset_safe_parameters()`
- `stop()`

---

## Testing

This project uses PlatformIO's Unity-based test framework.

Run tests on your host (native):

```bash
pio test -e native -v
```

Run embedded tests on the board (e.g. Mega 2560):

```bash
pio test -e mega -v
```

The native tests live under `test/test_native`, and embedded tests under
`test/test_embedded`.

---

## License

MIT. See the `LICENSE` file for details.
