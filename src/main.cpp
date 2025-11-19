// Minimal example sending a SPARK frame via MCP2515
#include <Arduino.h>
#include <SPI.h>
#include <mcp2515.h>
#include "spark_can.h"

// Adjust these to your wiring and bus configuration
#ifndef MCP2515_CS_PIN
#define MCP2515_CS_PIN 10
#endif

#ifndef MCP2515_OSC
// Common modules use 8 MHz crystal; change to MCP_16MHZ if needed
#define MCP2515_OSC MCP_8MHZ
#endif

#ifndef MCP2515_SPEED
// Change to your bus speed (e.g., CAN_500KBPS, CAN_250KBPS, CAN_1000KBPS)
#define MCP2515_SPEED CAN_500KBPS
#endif

static MCP2515 mcp2515(MCP2515_CS_PIN);

static void send_velocity_example() {
	Spark_VELOCITY_SETPOINT_t vals = {
			.SETPOINT = 1500.0f,                // raw encoded per spec (float)
			.ARBITRARY_FEEDFORWARD = 0,         // int16 raw
			.PID_SLOT = 0,                      // uint2
			.ARBITRARY_FEEDFORWARD_UNITS = 0    // 0: Voltage, 1: Duty Cycle
	};

	SparkCanFrame s;
	spark_build_VELOCITY_SETPOINT(3 /* device id 0-63 */, &vals, &s);

	struct can_frame f = {};
	// Extended ID frame
	f.can_id = (s.id & 0x1FFFFFFFUL) | CAN_EFF_FLAG;
	if (s.is_rtr) {
		f.can_id |= CAN_RTR_FLAG;
	}
	f.can_dlc = s.dlc;
	for (uint8_t i = 0; i < s.dlc && i < sizeof(f.data); ++i) {
		f.data[i] = s.data[i];
	}

	mcp2515.sendMessage(&f);
}

void setup() {
	SPI.begin();
	mcp2515.reset();
	mcp2515.setBitrate(MCP2515_SPEED, MCP2515_OSC);
	mcp2515.setNormalMode();

	// Send once at boot
	send_velocity_example();
}

void loop() {
	// Optionally, send periodically
	static unsigned long last = 0;
	if (millis() - last > 1000) {
		send_velocity_example();
		last = millis();
	}
}
