/**
 * Can bus sniffer - William Guimont-Martin 2025-2026 (https://github.com/willGuimont/CanControl)
 *
 * Purpose:
 *  - Quickly inspect traffic on a CAN bus using an MCP2515-based adapter.
 *  - Print CAN ID, device id (FRC-specific masking), and raw data bits.
 *
 * This sketch is compatible with the python tools available in `tools/`.
 * See README.md for wiring.
 */
#include <SPI.h>
#include <mcp2515.h>

// MCP2515 SPI CS pin = 10, SPI clock chosen at 4 MHz (safe for 8 MHz oscillator)
MCP2515          mcp2515(10, 4000000ul);

// Frame buffer used by the MCP2515 wrapper
struct can_frame canMsg;

// Function Prototypes
void parse_status_frame_0(uint8_t* data);
void parse_status_frame_1(uint8_t* data, uint8_t size);
void parse_status_frame_2(uint8_t* data, uint8_t size);

float data_to_float(uint8_t* data, uint8_t size);

void setup()
{
    Serial.begin(115200);
    while (!Serial)
        ;

    Serial.println("CAN SNIFFER");

    // Setup for MCP 2515
    mcp2515.reset();
    // Configure for 1 Mbps CAN and 8 MHz MCP2515 oscillator.
    // If your MCP2515 uses 16/20 MHz oscillator, change the second arg accordingly.
    mcp2515.setBitrate(CAN_1000KBPS, MCP_8MHZ);

    // Must go after all MCP2515 configuration
    mcp2515.setNormalMode();
}

void loop()
{
    if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK)
    {
        // Print identifier and a protocol-specific "Device ID" used by FRC
        Serial.print("CANID : ");
        Serial.print(canMsg.can_id, DEC);
        Serial.print(" Device ID : ");
        // NOTE: masking with 0x3F is FRC-specific (low 6 bits map to device id)
        Serial.print(canMsg.can_id & 0x3F, DEC);
        Serial.print(" ");

        // Print each data byte as bits (MSB first). Consider also printing
        // hex (`Serial.print(canMsg.data[i], HEX)`) for compactness.
        for (int i = 0; i < canMsg.can_dlc; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                Serial.print(bitRead(canMsg.data[i], 7 - j));
            }
            Serial.print(" ");
        }
        // Optional: print a hex dump for easier reading (uncomment if desired)
        // Serial.print(" HEX: ");
        // for (int i = 0; i < canMsg.can_dlc; i++) { Serial.print(canMsg.data[i], HEX); Serial.print(' '); }
        Serial.println();
    }
    else
    {
        Serial.println("Error reading CAN message");
    }
}
