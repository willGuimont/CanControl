#ifndef DUMP
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

static void send_get_temperatures(uint8_t device_id) {
	// Build an RTR request for temperatures
	SparkCanFrame s;
	// Values pointer can be NULL for RTR frames
	spark_build_GET_TEMPERATURES(device_id, nullptr, &s);

	struct can_frame f = {};
	f.can_id = (s.id & 0x1FFFFFFFUL) | CAN_EFF_FLAG | CAN_RTR_FLAG;
	f.can_dlc = s.dlc; // expected 8
	mcp2515.sendMessage(&f);
}

static void handle_frame(const struct can_frame &f) {
	const uint32_t id = f.can_id & 0x1FFFFFFFUL;
	// STATUS_0 sample decode
	if (SPARK_MATCH_STATUS_0(id)) {
		Spark_STATUS_0_t s0;
		if (spark_decode_STATUS_0(f.data, f.can_dlc, &s0)) {
			Serial.print(F("STATUS_0: applied="));
			Serial.print(s0.APPLIED_OUTPUT, 6);
			Serial.print(F(" V="));
			Serial.print(s0.VOLTAGE);
			Serial.print(F(" A="));
			Serial.println(s0.CURRENT);
		}
		return;
	}
	// Temperatures sample decode
	if (SPARK_MATCH_GET_TEMPERATURES(id)) {
		Spark_GET_TEMPERATURES_t temps;
		if (spark_decode_GET_TEMPERATURES(f.data, f.can_dlc, &temps)) {
			Serial.print(F("TEMPS: motor="));
			Serial.print(temps.MOTOR_TEMPERATURE);
			Serial.print(F(" mcu="));
			Serial.print(temps.MICROCONTROLLER_TEMPERATURE);
			Serial.print(F(" fet="));
			Serial.println(temps.FET_TEMPERATURE);
		}
		return;
	}
}

static void poll_can() {
	struct can_frame f;
	// Read up to a few frames per loop to keep responsiveness
	for (int i = 0; i < 5; ++i) {
		if (mcp2515.readMessage(&f) == MCP2515::ERROR_OK) {
			handle_frame(f);
		} else {
			break;
		}
	}
}
#endif

#ifndef UNIT_TEST
void setup() {
	SPI.begin();
	mcp2515.reset();
	mcp2515.setBitrate(MCP2515_SPEED, MCP2515_OSC);
	mcp2515.setNormalMode();
	Serial.begin(115200);

	// Send once at boot
	send_velocity_example();
	send_get_temperatures(3);
}

void loop() {
	// Optionally, send periodically
	static unsigned long last = 0;
	if (millis() - last > 1000) {
		send_velocity_example();
		send_get_temperatures(3);
		last = millis();
	}
	// Continuously poll and decode incoming frames
	poll_can();
}
#endif