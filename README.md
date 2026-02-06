# CanControl

**CanControl** is a library for controlling CAN-based motor controllers (REV Spark MAX, CTRE Talon SRX, Victor SPX) from **Arduino** boards using an **MCP2515 CAN Shield**.
CanControl currently supports:

- [REV Robotics Spark MAX](https://www.revrobotics.com/rev-11-2158/) (full support)
- [CTRE Talon SRX](https://store.ctr-electronics.com/products/talon-srx) (PercentOutput only)
- [CTRE Victor SPX](https://store.ctr-electronics.com/products/victor-spx) (PercentOutput only)

It handles the necessary FRC-style "Heartbeat" frames and providing high-level wrappers, so you can control FRC motor controllers without a roboRIO.

## Features

- High-level C++ wrappers:
  - `CanControl::SparkMax`
  - `CanControl::TalonSrx`
  - `CanControl::VictorSpxMotor`
- [Universal heartbeat](https://docs.wpilib.org/en/stable/docs/software/can-devices/can-addressing.html#universal-heartbeat) frames to keep FRC motor controllers enabled.
- Full features from the SparkMax
  - Low-level Spark MAX CAN protocol is auto-generated from REV's JSON spec (see `gen.py` and `third_party/REV-Specs/`).
- CTRE (Talon SRX / Victor SPX) support — percent/duty-cycle only
  - CTRE integration is implemented from [the only available public example for percent output](https://github.com/CrossTheRoadElec/Phoenix5-Examples/blob/master/HERO%20C%23/HERO%20Low%20Level%20Percent%20Output%20Example/Program.cs); no further official CAN protocol docs were provided by CTRE.

---

## Hardware

1. **Arduino Board**: tested with **Arduino Uno** and **Arduino Mega 2560**.
2. **MCP2515 CAN Module**: Standard SPI-based CAN controller board (often labeled "TJA1050 + MCP2515").
3. **CAN Motor Controller**: REV Spark MAX, CTRE Talon SRX, or Victor SPX.
4. **120Ω Termination Resistor**: **CRITICAL**. You MUST have a 120Ω resistor connected between CAN-H and CAN-L at the ends of your bus to prevent signal reflection.

### Wiring Instructions

#### MCP2515 Connections

The MCP2515 communicates via **SPI**. Connect it to your Arduino as follows:

| Pin Name | Arduino Uno Pin | Arduino Mega Pin | Description |
| :--- | :--- | :--- | :--- |
| **VCC** | 5V | 5V | Power |
| **GND** | GND | GND | Ground |
| **CS** | **10** | **53** | Chip Select (Configurable in `main.cpp`) |
| **SO / MISO** | 12 | 50 | Master In Slave Out |
| **SI / MOSI** | 11 | 51 | Master Out Slave In |
| **SCK** | 13 | 52 | SPI Clock |
| **INT** | 2 (Optional) | 2 (Optional) | Interrupt (not strictly required for basic TX) |

#### CAN Bus Wiring

1. **CAN High (H)**: Connect MCP2515 `H` to Motor Controller `Yellow` wire.
2. **CAN Low (L)**: Connect MCP2515 `L` to Motor Controller `Green` wire.
3. **Termination**: Ensure a **120Ω resistor** connects `H` and `L` at the furthers point of the bus (often the MCP2515 itself has a jumper for this, check your module). In any case, you must have a resistor on both ends of the bus.

> **Note**: Spark MAX controllers do **not** have built-in termination. You must add the resistor yourself if it's the last device in the chain.

---

## Installation & Usage

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

### Using with Arduino IDE

Coming soon...

### Cloning and Building (Development)

```bash
git clone https://github.com/willGuimont/CanControl.git
cd CanControl
git submodule update --init --recursive
```

### Build and Upload (PlatformIO)

Open the project in VS Code with PlatformIO.

**For Arduino Uno:**

```bash
pio run -e uno -t upload
```

**For Arduino Mega:**

```bash
pio run -e mega -t upload
```

### Examples

This library provides two main examples to help you get started:

#### 1. Basic Example (`examples/main.cpp`)

Simple example that shows how to use the device wrappers (`SparkMax`, `TalonSrx`) directly with an `MCP2515` instance.
You'll see how the MCP2515 is initialized and how to control a motor.
Be mindful that if you want to use multiple motors, you will need to manually send heartbeats and manage timing in your main loop.
Notably, you need to avoid sending too many frames too quickly, as this can cause the bus to become saturated.
A simple solution is to implement a round-robin system where every update interval, you send the command to one motor at a time.
See `examples/main_queue.cpp` for an example of this using the `CanController` class that manages a command queue and handles the timing for you.

Run using the `env:mega` or `env:uno` environments.

#### 2. Queued Example (`examples/main_queue.cpp`)

> **NOTE:** This example is a work in progress and may not be fully functional yet. It demonstrates the intended usage of the `CanController` class, but some features may still be under development.

A more complex example that shows how to use the `CanController` class to manage the CAN bus.
`CanController` can setup the MCP2515, manage the CAN bus, and handle the timing for you.
They use the queued device wrappers (`SparkMaxQueued`, `TalonSrxQueued`) to control the motors.

Run using the `env:mega_queue` or `env:uno_queue` environments.

### Running the Examples

The example sketch uses the Serial Monitor (Baud Rate: **115200**) to accept commands.

**To run the Basic example on a Mega:**

```bash
pio run -e mega -t upload
```

**To run the Queued example on a Mega:**

```bash
pio run -e mega_queue -t upload
```

**Serial Commands (Both Examples):**

- `s0.5`: Set Speed to 50%
- `s-0.5`: Set Speed to -50%
- `s0`: Stop Motor
- `h`: Help menu

---

## CTRE Talon SRX & Victor SPX

Using CTRE devices requires that they be "FRC unlocked" to accept non-FRC
frames.
The FRC lock will be enabled by default and be persistent across power cycles if the
device was ever connected to an FRC roboRIO.
To unlock the device, you need to disconnect it from the roboRIO and power it while
holding the reset button for about 5 seconds until the LED blinks green.

---

## Generated Spark MAX Low-Level API

The low-level Spark MAX protocol bindings are generated from
`doc/spark-frames-2.1.0.json` (available from [REVrobotics/REV-Specs](https://github.com/REVrobotics/REV-Specs)) by `gen.py` and live in:

- `include/low_level/low_sparkmax.h`
- `src/low_level/low_sparkmax.cpp`

These files are **auto-generated** (see the header comment) and should not be
edited by hand. Instead, update the JSON spec or generator and re-run `gen.py`.

The high-level `SparkMax` class in `include/sparkmax.h` wraps these generated structures to provide a user-friendly C++ API.

---

## Analysis Tools

Located in the `tools/` directory (install requirements with `pip install pyserial`):

- **`can_monitor.py`**: Live monitor that talks to the Arduino sketch to print/log CAN traffic.

    ```bash
    python tools/can_monitor.py --port COM3 --output log.csv
    ```

- **`compare_logs.py`**: Compare two CSV logs to find timing differences or missing messages.

    ```bash
    python tools/compare_logs.py good_log.csv bad_log.csv
    ```

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

## Troubleshooting

- **"Sticky Fault for CAN Bus Error"**: This usually means **missing termination**. Add a 120Ω resistor between Green/Yellow wires.
- **Motor LEDs Flashing Orange/Green**: The motor is seeing *some* valid frames but timing out frequently. Check wiring and termination or heartbeat frequency.
- **CTRE Motors**: Must be **Factory Defaulted** or not "FRC Locked". If they were used on a roboRIO, hold the B/C button on boot to factory reset.

---
