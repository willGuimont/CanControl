import serial
import time
import argparse
import csv
import sys
import re

"""
can_monitor.py

A simple tool to monitor CAN bus traffic via a serial connection to an Arduino CAN sniffer (see examples/can_sniffer).
It parses the serial output, prints formatted messages to the console, and optionally logs
traffic to a CSV file.

Usage:
    python tools/can_monitor.py --port COM3 --baud 115200 --output log.csv
"""


def parse_line(line):
    """
    Parses a single line of output from the Arduino CAN sniffer.

    Expected format:
        "CANID : <id> Device ID : <dev_id> <byte0_bin> <byte1_bin> ..."

    Args:
        line (str): The raw serial line string.

    Returns:
        dict: A dictionary containing 'timestamp', 'can_id', 'data_len', 'data' (list of ints),
              and 'raw_line', or None if parsing failed.
    """
    try:
        line = line.strip()
        if not line.startswith("CANID :"):
            return None

        parts = line.split()
        # parts[0] -> "CANID"
        # parts[1] -> ":"
        # parts[2] -> ID
        # parts[3] -> "Device"
        # parts[4] -> "ID"
        # parts[5] -> ":"
        # parts[6] -> DevID
        # parts[7:] -> data bytes in binary

        if len(parts) < 7:
            return None

        can_id = int(parts[2])
        # dev_id = int(parts[6]) # Optional to store

        data_bytes = []
        for b_str in parts[7:]:
            # Clean up any potential non-binary chars if sniffer format changes, but mostly it's 8 bits
            if re.match(r"^[01]{8}$", b_str):
                data_bytes.append(int(b_str, 2))

        return {
            "timestamp": time.time(),
            "can_id": can_id,
            "data_len": len(data_bytes),
            "data": data_bytes,
            "raw_line": line,
        }
    except ValueError:
        return None
    except Exception as e:
        print(f"Error parsing line: {line} -> {e}")
        return None


def main():
    """
    Main entry point for the CAN monitor tool.
    Handles command line arguments, serial connection, and logging loop.
    """
    parser = argparse.ArgumentParser(description="Monitor CAN bus via Arduino Sniffer")
    parser.add_argument("--port", default="COM3", help="Serial port (default: COM3)")
    parser.add_argument(
        "--baud", type=int, default=115200, help="Baud rate (default: 115200)"
    )
    parser.add_argument("--output", help="Output CSV file connection")

    args = parser.parse_args()

    csv_file = None
    csv_writer = None

    if args.output:
        csv_file = open(args.output, "w", newline="")
        csv_writer = csv.writer(csv_file)
        csv_writer.writerow(["Timestamp", "CAN_ID", "DLC", "DataBytes"])
        print(f"Logging to {args.output}")

    try:
        print(f"Connecting to {args.port} at {args.baud}...")
        ser = serial.Serial(args.port, args.baud, timeout=1)
        print("Connected. Listening for CAN messages...")

        while True:
            try:
                line_bytes = ser.readline()
                if not line_bytes:
                    continue

                line = line_bytes.decode("utf-8", errors="replace").strip()
                if not line:
                    continue

                parsed = parse_line(line)
                if parsed:
                    # Hex data for display
                    hex_data = " ".join([f"{b:02X}" for b in parsed["data"]])
                    print(
                        f"[{parsed['timestamp']:.3f}] ID: {parsed['can_id']:8} | {hex_data}"
                    )

                    if csv_writer:
                        # Log as hex string for data bytes
                        csv_writer.writerow(
                            [
                                parsed["timestamp"],
                                parsed["can_id"],
                                parsed["data_len"],
                                hex_data,
                            ]
                        )
                        csv_file.flush()
                else:
                    # Print unparsed lines just in case (debug info etc)
                    print(f"[RAW] {line}")

            except UnicodeDecodeError:
                pass

    except serial.SerialException as e:
        print(f"Serial Error: {e}")
    except KeyboardInterrupt:
        print("\nStopping...")
    finally:
        if csv_file:
            csv_file.close()


if __name__ == "__main__":
    main()
