#include <Arduino.h>
#include <SPI.h>
#include <mcp2515.h>

#include <frc_can.h>
#include <frc_can_utils.h>

#define MCP2515_CS_PIN 53
#define MCP2515_OSC 
#define MCP2515_SPEED CAN_1000KBPS

using namespace CanControl;

static MCP2515 mcp2515(MCP2515_CS_PIN);

void setup()
{
    SPI.begin();
    mcp2515.reset();
    mcp2515.setBitrate(MCP2515_SPEED, MCP2515_OSC);
    mcp2515.setNormalMode();
    Serial.begin(2000000);
}

void show_frame(const can_frame &f)
{
    Serial.print("ID: 0x");
    Serial.println(f.can_id, HEX);
    Serial.print("\tDLC: ");
    Serial.println(f.can_dlc);
    Serial.print("\tData: ");
    for (uint8_t i = 0; i < f.can_dlc; ++i)
    {
        Serial.print(f.data[i], HEX);
        Serial.print(" ");
    }
    Serial.println();
}

void show_frc_frame(const frc_can_frame &f)
{
    const frc_can_id &id = f.id;
    Serial.println("FRC CAN ID:");
    Serial.print("\tRaw: 0x");
    Serial.println(id.raw, HEX);
    Serial.print("\tRaw: 0b");
    Serial.println(id.raw, BIN);
    Serial.print("\tDevice Number: ");
    Serial.println(id.device_number());
    Serial.print("\tAPI Index: ");
    Serial.println(id.api_index());
    Serial.print("\tAPI Class: ");
    Serial.println(id.api_class());
    Serial.print("\tManufacturer Code: ");
    Serial.println(id.manufacturer_code());
    Serial.print("\tDevice Type: ");
    Serial.println(id.device_type());
}

void loop()
{
    can_frame f;
    if (mcp2515.readMessage(&f) != MCP2515::ERROR_OK)
    {
        return;
    }
    if (f.can_id == 0)
    {
        return;
    }
    show_frame(f);
    frc_can_frame frc = from_can_frame(f);
    show_frc_frame(frc);
}
