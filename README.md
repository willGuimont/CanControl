# CanControl

**CanControl** is a library for controlling CAN-based motor controllers (REV Spark MAX, CTRE Talon SRX, and CTRE Victor SPX) from **Arduino** boards using an **MCP2515 CAN controller**.
CanControl currently supports:

- [REV Robotics Spark MAX](https://www.revrobotics.com/rev-11-2158/) (generated low-level protocol coverage with selected high-level controls)
- [CTRE Talon SRX](https://store.ctr-electronics.com/products/talon-srx) (PercentOutput only)
- [CTRE Victor SPX](https://store.ctr-electronics.com/products/victor-spx) (PercentOutput only)

It provides high-level motor wrappers plus scheduling for the heartbeat and enable frames required to operate these controllers without a roboRIO.

## Features

- High-level C++ wrappers:
  - `CanControl::SparkMax`
  - `CanControl::TalonSrx`
  - `CanControl::VictorSpx`
  - Queued variants of all three wrappers
- [Universal heartbeat](https://docs.wpilib.org/en/stable/docs/software/can-devices/can-addressing.html#universal-heartbeat) support for Spark MAX controllers.
- CTRE global enable scheduling for Talon SRX and Victor SPX controllers.
- Low-level Spark MAX CAN protocol generated from REV's specification (see `gen.py` and `third_party/REV-Specs/`).
- CTRE percent/duty-cycle control
  - CTRE integration is implemented from [the only available public example for percent output](https://github.com/CrossTheRoadElec/Phoenix5-Examples/blob/master/HERO%20C%23/HERO%20Low%20Level%20Percent%20Output%20Example/Program.cs); no further official CAN protocol docs were provided by CTRE.

---

## Hardware

1. **Arduino Board**: tested with **Arduino Uno** and **Arduino Mega 2560**.
2. **MCP2515 CAN Module**: Standard SPI-based CAN controller board (often labeled "TJA1050 + MCP2515").
3. **CAN Motor Controller**: REV Spark MAX, CTRE Talon SRX, or Victor SPX.
4. **Two 120Ω Termination Resistors**: one connected between CAN-H and CAN-L at each physical end of the bus.

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

Override the default CS pin with the `CANCONTROL_MCP2515_CS_PIN` build flag, for example `-DCANCONTROL_MCP2515_CS_PIN=9`.

#### CAN Bus Wiring

1. **CAN High (H)**: Connect MCP2515 `H` to Motor Controller `Yellow` wire.
2. **CAN Low (L)**: Connect MCP2515 `L` to Motor Controller `Green` wire.
3. **Termination**: Connect one **120Ω resistor** between `H` and `L` at each physical end of the bus. Most MCP2515 modules include a jumper that enables an onboard 120Ω resistor, which can provide termination at one end. Check that the jumper is present and enabled, and provide a separate 120Ω resistor at the other physical end.

> **Note**: Spark MAX controllers do **not** have built-in termination. You must add the resistor yourself if it's the last device in the chain.

#### MCP2515 Oscillator

The oscillator configured in software must match the crystal installed on the MCP2515 module.
The examples default to `MCP_8MHZ`; many modules instead use a 16 MHz crystal.
Set `MCP2515_OSC` to `MCP_8MHZ`, `MCP_16MHZ`, or `MCP_20MHZ` as appropriate.
A mismatched oscillator usually results in no usable CAN traffic even though SPI initialization succeeds.

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

### Public Headers

For direct motor control, include the aggregate header:

```cpp
#include <CanControl.h>
```

For direct Talon SRX or Victor SPX control, send the CTRE global enable frame approximately every 20 ms in addition to refreshing the motor command:

```cpp
CanControl::TalonSrx::send_global_enable(mcp2515, true);
```

Queued control currently uses explicit headers:

```cpp
#include <can_controller.h>
#include <motors_queued/sparkmax_queued.h>
#include <motors_queued/talonsrx_queued.h>
#include <motors_queued/victorspx_queued.h>
```

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

| Approach | Transmission | Best suited for |
| :--- | :--- | :--- |
| Direct wrappers | Commands are sent immediately through `MCP2515` | One motor, simple experiments, or applications with their own scheduler |
| Queued wrappers | Configuration is queued; the latest control command is scheduled periodically | Multiple motors and applications that want centralized rate limiting and heartbeat scheduling |

#### 1. Basic Example (`examples/main.cpp`)

Simple example that shows how to use the device wrappers (`SparkMax`, `TalonSrx`) directly with an `MCP2515` instance.
You'll see how the MCP2515 is initialized and how to control a motor.
Be mindful that if you want to use multiple motors, you will need to manually send heartbeats and manage timing in your main loop.
Notably, you need to avoid sending too many frames too quickly, as this can cause the bus to become saturated.
A simple solution is to implement a round-robin system where every update interval, you send the command to one motor at a time.
See `examples/main_queue.cpp` for an example of this using the `CanController` class that manages a command queue and handles the timing for you.

Run using the `env:mega` or `env:uno` environments.

Minimal direct-control structure:

```cpp
#include <CanControl.h>
#include <SPI.h>
#include <mcp2515.h>

MCP2515 mcp2515(10, 4000000UL);
CanControl::SparkMax motor(mcp2515, 1);

void setup()
{
    mcp2515.reset();
    mcp2515.setBitrate(CAN_1000KBPS, MCP_8MHZ); // Must match the module crystal.
    mcp2515.setNormalOneShotMode();
}

void loop()
{
    static unsigned long last_heartbeat = 0;
    unsigned long now = millis();
    if (now - last_heartbeat >= 20)
    {
        CanControl::send_heartbeat(mcp2515, CanControl::default_heartbeat());
        last_heartbeat = now;
    }

    motor.set_duty_cycle(0.25f);
    delay(5);
}
```

#### 2. Queued Example (`examples/main_queue.cpp`)

This example uses `CanController` to rate-limit CAN traffic, send heartbeats, retry queued configuration frames, and schedule the latest motor commands in round-robin order.
The queued wrappers support Spark MAX, Talon SRX, and Victor SPX controllers.

The queued approach is useful when controlling multiple motors.
With the direct wrappers, every call attempts to write to the MCP2515 immediately, so the application must implement its own timing and round-robin scheduler.
Sending several motor commands and heartbeat frames back-to-back can fill the MCP2515 transmit buffers faster than frames leave the CAN bus, causing failed transmissions and uneven command updates.
`CanController` serializes this traffic, prioritizes required heartbeat and enable frames, preserves the order of configuration commands, and gives each motor a turn to send its latest control command without flooding the bus.

Minimal queued-control structure:

```cpp
#include <SPI.h>
#include <can_controller.h>
#include <motors_queued/sparkmax_queued.h>
#include <mcp2515.h>

MCP2515 mcp2515(10, 4000000UL);
CanControl::CanController can_controller(mcp2515);
CanControl::SparkMaxQueued left_motor(can_controller, 1);
CanControl::SparkMaxQueued right_motor(can_controller, 2);

void setup()
{
    can_controller.setup(CAN_1000KBPS, MCP_8MHZ); // Must match the module crystal.
    can_controller.set_heartbeat(true);
}

void loop()
{
    static unsigned long previous = 0;
    unsigned long now = millis();
    can_controller.update(now - previous);
    previous = now;

    // CanController sends these latest commands in round-robin order.
    // Refreshing them also refreshes each motor's safety timeout.
    left_motor.set_duty_cycle(0.25f);
    right_motor.set_duty_cycle(0.25f);
}
```

For queued Talon SRX or Victor SPX control, enable the CTRE-specific global frame during setup:

```cpp
can_controller.set_ctre_global_enable(true);
```

The default queue holds 64 frames.
Override `CANCONTROL_QUEUE_SIZE` in your build flags when SRAM is constrained.
The `uno_queue` environment uses eight frames while `mega_queue` keeps the default of 64.

The four-motor example produces a 20-frame initialization burst (reset plus four PID values per motor), which does not fit in the Uno's eight-frame queue.
An Uno application must flush configuration in smaller batches and check every queueing result.
Increasing the queue to hold the complete burst consumes more SRAM and is not recommended on an Uno.

`CanController::flush()` waits up to five seconds by default and returns `false` if queued frames cannot be sent.
Treat a timeout as an initialization failure and check the CAN wiring, termination, and oscillator setting.

The four-motor queued example is close to the Uno's 2 KB SRAM limit even with the smaller queue.
It may not leave enough stack and heap space for reliable operation.
Prefer a Mega for the four-motor example or reduce the application memory usage before deploying it to an Uno.

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

**Serial Commands Available in Both Examples:**

- `s0.5`: Set Speed to 50%
- `s-0.5`: Set Speed to -50%
- `s0`: Stop Motor

The basic example also accepts position and homing commands.
The queued example accepts position commands and an optional leading motor ID, such as `2s0.5` or `3p12.5`.
Both examples print their complete command list when they start.

---

## CTRE Talon SRX & Victor SPX

Set the device CAN ID using CTRE Phoenix Tuner while the controller is connected to a roboRIO.

Using CTRE devices requires that they be "FRC unlocked" to accept non-FRC
frames.
The FRC lock will be enabled by default and be persistent across power cycles if the
device was ever connected to an FRC roboRIO.
To unlock the device, you need to disconnect it from the roboRIO and power it while
holding the reset button for about 5 seconds until the LED blinks green.

---

## Generated Spark MAX Low-Level API

The low-level Spark MAX protocol bindings are generated from
`third_party/REV-Specs/can-frames/spark-frames-2.1.0` (from [REVrobotics/REV-Specs](https://github.com/REVrobotics/REV-Specs)) by `gen.py` and live in:

- `include/low_level/low_sparkmax.h`
- `src/low_level/low_sparkmax.cpp`
- `include/low_level/low_sparkmax_params.h`
- `src/low_level/low_sparkmax_params.cpp`

These files are **auto-generated** (see the header comment) and should not be
edited by hand. Instead, update the JSON spec or generator and re-run `gen.py`.

The generated identifiers are typed constants and functions inside `CanControl::LowLevel::SparkMax`, for example:

```cpp
auto parameter = CanControl::LowLevel::SparkMax::SPARK_PARAM_CAN_ID_UINT;
```

The high-level `SparkMax` class in `include/motors/sparkmax.h` wraps these generated structures to provide a user-friendly C++ API.

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
The native suite uses a fake CAN transport and clock to test queue ordering, retries, timeouts, sender lifecycle, and generated motor frames without an Arduino.

Run tests on your host (native):

```bash
pio test -e native -v
```

Run embedded tests on the board (e.g. Mega 2560):

```bash
pio test -e mega -v
```

The current embedded test target is a harness for hardware-dependent tests; most behavioral coverage is in the native suite.

The native tests live under `test/test_native`, and embedded tests under
`test/test_embedded`.

---

## Troubleshooting

- **"Sticky Fault for CAN Bus Error"**: This usually means **missing termination**. Add a 120Ω resistor between Green/Yellow wires.
- **Motor LEDs Flashing Orange/Green**: The motor is seeing *some* valid frames but timing out frequently. Check wiring and termination or heartbeat frequency.
- **No CAN traffic or no motor response**: Confirm that `MCP2515_OSC` matches the module's crystal and that the bus is configured for 1 Mbps.
- **Spark MAX does not enable**: Confirm that the universal heartbeat is being sent at approximately 20 ms intervals.
- **Talon SRX or Victor SPX does not enable**: Confirm that CTRE global enable scheduling is active.
- **CTRE Motors**: Must be **Factory Defaulted** or not "FRC Locked". If they were used on a roboRIO, hold the B/C button on boot to factory reset.

---
