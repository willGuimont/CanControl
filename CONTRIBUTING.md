# Contributing

Clone the repository and initialize the protocol specifications:

```bash
git clone https://github.com/willGuimont/CanControl.git
cd CanControl
git submodule update --init --recursive
```

See [examples](examples/README.md) for build and upload commands and the
[README](README.md#hardware-and-wiring) for wiring.

## Running Tests

```bash
# Run native host unit tests
pio test -e native -v
```

## Code Generator & Tools

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

## Publishing to PlatformIO Registry

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

