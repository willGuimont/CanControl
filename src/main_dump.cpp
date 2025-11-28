#ifdef DUMP
// Frame dump and comparison utility
#include <Arduino.h>
#include <SPI.h>
#include <mcp2515.h>
#include "spark_can.h"

#ifndef MCP2515_CS_PIN
#define MCP2515_CS_PIN 53
#endif
#ifndef MCP2515_OSC
#define MCP2515_OSC MCP_8MHZ
#endif
#ifndef MCP2515_SPEED
#define MCP2515_SPEED CAN_500KBPS
#endif

static MCP2515 mcp2515(MCP2515_CS_PIN);

static SparkCanFrame expected = {};
static bool has_expected = false;
static bool raw_enabled = true;
static uint32_t id_filter = 0; // 0 means disabled

static void print_help() {
	Serial.println(F("Commands:"));
	Serial.println(F("help                Show this help"));
	Serial.println(F("raw on|off          Toggle raw frame hex dump"));
	Serial.println(F("filter <hexid>|off  Set extended ID filter (no 0x prefix)"));
	Serial.println(F("exp vel <id> <setpoint> [ff pid units]  Set expected VELOCITY_SETPOINT"));
	Serial.println(F("exp temps <id>      Set expected GET_TEMPERATURES RTR"));
	Serial.println(F("clearexp            Clear expected frame"));
	Serial.println(F("send vel <id> <setpoint> [ff pid units]  Send VELOCITY_SETPOINT"));
	Serial.println(F("send temps <id>     Send GET_TEMPERATURES RTR"));
}

static void build_velocity(uint8_t dev, float setpoint, int16_t ff, uint8_t pid, uint8_t units, SparkCanFrame &out) {
	Spark_VELOCITY_SETPOINT_t v = { setpoint, ff, pid, units };
	spark_build_VELOCITY_SETPOINT(dev, &v, &out);
}

static void build_get_temps(uint8_t dev, SparkCanFrame &out) {
	spark_build_GET_TEMPERATURES(dev, nullptr, &out);
}

static void diff_bytes(const SparkCanFrame &exp, const struct can_frame &in) {
	Serial.print(F("    compare: "));
	for (uint8_t i=0;i<in.can_dlc;i++) {
		uint8_t e = (i < exp.dlc) ? exp.data[i] : 0xFF;
		uint8_t a = in.data[i];
		if (e == a) {
			Serial.print(F(" "));
			if (e < 16) Serial.print('0');
			Serial.print(e, HEX);
		} else {
			Serial.print(F(" ["));
			if (e < 16) Serial.print('0');
			Serial.print(e, HEX);
			Serial.print(F("!="));
			if (a < 16) Serial.print('0');
			Serial.print(a, HEX);
			Serial.print(F("]"));
		}
	}
	Serial.println();
}

static void decode_known(uint32_t id, const struct can_frame &f) {
	if (SPARK_MATCH_STATUS_0(id)) {
		Spark_STATUS_0_t s0; if (spark_decode_STATUS_0(f.data, f.can_dlc, &s0)) {
			Serial.print(F(" STATUS_0 applied=")); Serial.print(s0.APPLIED_OUTPUT);
			Serial.print(F(" V=")); Serial.print(s0.VOLTAGE);
			Serial.print(F(" A=")); Serial.print(s0.CURRENT);
			Serial.print(F(" Tm=")); Serial.print(s0.MOTOR_TEMPERATURE);
			Serial.print(F(" limits[F/R/softF/softR]="));
			Serial.print(s0.HARD_FORWARD_LIMIT_REACHED); Serial.print('/');
			Serial.print(s0.HARD_REVERSE_LIMIT_REACHED); Serial.print('/');
			Serial.print(s0.SOFT_FORWARD_LIMIT_REACHED); Serial.print('/');
			Serial.print(s0.SOFT_REVERSE_LIMIT_REACHED);
			Serial.print(F(" inv=")); Serial.print(s0.INVERTED);
			Serial.print(F(" hb_lock=")); Serial.print(s0.PRIMARY_HEARTBEAT_LOCK);
		}
	} else if (SPARK_MATCH_GET_TEMPERATURES(id)) {
		Spark_GET_TEMPERATURES_t t; if (spark_decode_GET_TEMPERATURES(f.data, f.can_dlc, &t)) {
			Serial.print(F(" TEMPS mtr=")); Serial.print(t.MOTOR_TEMPERATURE);
			Serial.print(F(" mcu=")); Serial.print(t.MICROCONTROLLER_TEMPERATURE);
			Serial.print(F(" fet=")); Serial.print(t.FET_TEMPERATURE);
			Serial.print(F(" mtr2=")); Serial.print(t.MOTOR_TEMPERATURE_2);
			Serial.print(F(" dock=")); Serial.print(t.DOCK_TEMPERATURE);
			Serial.print(F(" mask=0x")); Serial.print(t.VALID_TEMPERATURES_BITMASK, HEX);
		}
	} else if (SPARK_MATCH_VELOCITY_SETPOINT(id)) {
		Spark_VELOCITY_SETPOINT_t v; if (spark_decode_VELOCITY_SETPOINT(f.data, f.can_dlc, &v)) {
			Serial.print(F(" VELOCITY sp=")); Serial.print(v.SETPOINT);
			Serial.print(F(" ff=")); Serial.print(v.ARBITRARY_FEEDFORWARD);
			Serial.print(F(" pid=")); Serial.print(v.PID_SLOT);
			Serial.print(F(" units=")); Serial.print(v.ARBITRARY_FEEDFORWARD_UNITS);
		}
	}
}

static void print_frame(const struct can_frame &f) {
	uint32_t id = f.can_id & 0x1FFFFFFFUL;
	bool rtr = (f.can_id & CAN_RTR_FLAG) != 0;
	Serial.print(F("ID=0x")); Serial.print(id, HEX);
	Serial.print(F(" dlc=")); Serial.print(f.can_dlc);
	Serial.print(F(" rtr=")); Serial.print(rtr);
	if (raw_enabled && !rtr) {
		Serial.print(F(" data:"));
		for (uint8_t i=0;i<f.can_dlc;i++) { Serial.print(' '); if (f.data[i] < 16) Serial.print('0'); Serial.print(f.data[i], HEX); }
	}
	decode_known(id, f);
	if (has_expected) {
		uint32_t exp_id = expected.id & 0x1FFFFFFFUL;
		if (exp_id == id && !rtr) diff_bytes(expected, f);
	}
	Serial.println();
}

static void poll_can() {
	struct can_frame f;
	for (int i=0;i<10;i++) {
		if (mcp2515.readMessage(&f) == MCP2515::ERROR_OK) {
			uint32_t id = f.can_id & 0x1FFFFFFFUL;
			if (id_filter && id != id_filter) continue;
			print_frame(f);
		} else break;
	}
}

static void set_expected_velocity(uint8_t id, float sp, int16_t ff, uint8_t pid, uint8_t units) {
	build_velocity(id, sp, ff, pid, units, expected); has_expected = true; Serial.println(F("Expected VELOCITY_SETPOINT set."));
}
static void set_expected_temps(uint8_t id) {
	build_get_temps(id, expected); has_expected = true; Serial.println(F("Expected GET_TEMPERATURES set."));
}

static void send_velocity(uint8_t id, float sp, int16_t ff, uint8_t pid, uint8_t units) {
	SparkCanFrame s; build_velocity(id, sp, ff, pid, units, s);
	struct can_frame f = {};
	f.can_id = (s.id & 0x1FFFFFFFUL) | CAN_EFF_FLAG;
	f.can_dlc = s.dlc; memcpy(f.data, s.data, s.dlc);
	mcp2515.sendMessage(&f);
	Serial.println(F("Sent VELOCITY_SETPOINT."));
}
static void send_get_temps(uint8_t id) {
	SparkCanFrame s; build_get_temps(id, s);
	struct can_frame f = {};
	f.can_id = (s.id & 0x1FFFFFFFUL) | CAN_EFF_FLAG | CAN_RTR_FLAG;
	f.can_dlc = s.dlc;
	mcp2515.sendMessage(&f);
	Serial.println(F("Sent GET_TEMPERATURES RTR."));
}

static char linebuf[96];
static uint8_t linepos = 0;

static void process_line(char *ln) {
	while (*ln == ' ') ++ln; if (!*ln) return;
	if (!strcmp(ln, "help")) { print_help(); return; }
	if (!strncmp(ln, "raw ", 4)) {
		if (strstr(ln+4, "on")) raw_enabled = true; else if (strstr(ln+4, "off")) raw_enabled = false; Serial.print(F("raw=")); Serial.println(raw_enabled); return;
	}
	if (!strncmp(ln, "filter ", 7)) {
		if (strstr(ln+7, "off")) { id_filter = 0; Serial.println(F("Filter cleared")); return; }
		id_filter = strtoul(ln+7, nullptr, 16); Serial.print(F("Filter=0x")); Serial.println(id_filter, HEX); return;
	}
	if (!strncmp(ln, "clearexp", 8)) { has_expected = false; Serial.println(F("Expected cleared")); return; }
	if (!strncmp(ln, "exp ", 4)) {
		char *tok = ln+4; if (!strncmp(tok, "vel ", 4)) {
			tok += 4; uint8_t id = (uint8_t)strtoul(tok, &tok, 0);
			float sp = strtod(tok, &tok);
			int ff = 0; uint8_t pid = 0; uint8_t units = 0;
			if (*tok) ff = (int)strtol(tok, &tok, 0);
			if (*tok) pid = (uint8_t)strtoul(tok, &tok, 0);
			if (*tok) units = (uint8_t)strtoul(tok, &tok, 0);
			set_expected_velocity(id, sp, ff, pid, units); return;
		} else if (!strncmp(tok, "temps ", 6)) {
			tok += 6; uint8_t id = (uint8_t)strtoul(tok, nullptr, 0); set_expected_temps(id); return;
		}
	}
	if (!strncmp(ln, "send ", 5)) {
		char *tok = ln+5; if (!strncmp(tok, "vel ", 4)) {
			tok += 4; uint8_t id = (uint8_t)strtoul(tok, &tok, 0); float sp = strtod(tok, &tok);
			int ff = 0; uint8_t pid = 0; uint8_t units = 0;
			if (*tok) ff = (int)strtol(tok, &tok, 0);
			if (*tok) pid = (uint8_t)strtoul(tok, &tok, 0);
			if (*tok) units = (uint8_t)strtoul(tok, &tok, 0);
			send_velocity(id, sp, ff, pid, units); return;
		} else if (!strncmp(tok, "temps ", 6)) {
			tok += 6; uint8_t id = (uint8_t)strtoul(tok, nullptr, 0); send_get_temps(id); return;
		}
	}
	Serial.println(F("Unknown command. 'help' for list."));
}

void setup() {
	SPI.begin();
	mcp2515.reset();
	mcp2515.setBitrate(MCP2515_SPEED, MCP2515_OSC);
	mcp2515.setNormalMode();
	Serial.begin(2000000);
	print_help();
}

void loop() {
	poll_can();
	while (Serial.available()) {
		char c = (char)Serial.read();
		if (c == '\r') continue;
		if (c == '\n') { linebuf[linepos] = 0; process_line(linebuf); linepos = 0; }
		else if (linepos < sizeof(linebuf)-1) { linebuf[linepos++] = c; }
	}
}

#endif
