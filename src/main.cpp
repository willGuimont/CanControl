#include <SPI.h>

#define CS_PIN 10

void setup() {
  Serial.begin(115200);
  while (!Serial);

  SPI.begin();
  pinMode(CS_PIN, OUTPUT);
  digitalWrite(CS_PIN, HIGH);

  Serial.println("Reading MCP2515 Status Register...");

  digitalWrite(CS_PIN, LOW);
  SPI.transfer(0xA0);  // READ STATUS command
  byte status = SPI.transfer(0x00);
  digitalWrite(CS_PIN, HIGH);

  Serial.print("MCP2515 Status: 0x");
  Serial.println(status, HEX);
}

void loop() {}
// // Mega MCP2515 CAN send/Receive Example 
// //
// // Mega <> MCP2515 connections
// // MCP2515 INT to Mega  GPIO22
// // MCP2515 SCK to Mega  GPIO52 CLK
// // MCP2515  SI to Mega  GPIO51 MOSI
// // MCP2515  SO to Mega  GPIO50 MISO
// // MCP2515  CS to Mega  GPIO53  CS
// // MCP2515 GND to Mega  GND
// // MCP2515 VCC to Mega  5V

// #include <mcp_can.h>
// #include <SPI.h>

// long unsigned int rxId;
// unsigned char len = 0;
// unsigned char rxBuf[8];
// char msgString[128];  // Array to store serial string

// #define CAN0_INT 22  // for Mega 
// MCP_CAN CAN0(53);   // 

// void setup() {
//   Serial.begin(115200);
//   delay(2000);
//   Serial.println("\n\nMega- CAN MCP2515 shield Send/Receive test - MCP2515 Initialize");
//     Serial.print("MOSI: ");
//   Serial.println(MOSI);
//   Serial.print("MISO: ");
//   Serial.println(MISO);
//   Serial.print("SCK: ");
//   Serial.println(SCK);
//   Serial.print("SS: ");
//   Serial.println(SS);  

//   // Initialize MCP2515 baudrate of 250kb/s and the masks and filters disabled.
//   //  check crystal frequency!! e.g. Canbus shield is 16MHz MCP2515 is 8MHz
//   if (CAN0.begin(MCP_ANY, CAN_125KBPS, MCP_8MHZ) == CAN_OK)
//     Serial.println("CAN Receive - MCP2515 Initialized Successfully!");
//   else
//     Serial.println("Error Initializing MCP2515...");
//   CAN0.setMode(MCP_NORMAL);         // Set operation mode to normal so the MCP2515 sends acks to received data.
//   pinMode(CAN0_INT, INPUT_PULLUP);  // Configuring pin for /INT input *** added PULLUP ***
//   Serial.println("MCP2515 Library CAN Send/Receive Example\n enter space to send a frame");
// }

// void loop() {
//   // check for data received
//   if (!digitalRead(CAN0_INT))  // If CAN0_INT pin is low, read receive buffer
//   {
//     CAN0.readMsgBuf(&rxId, &len, rxBuf);    // Read data: len = data length, buf = data byte(s)
//     if ((rxId & 0x80000000) == 0x80000000)  // Determine if ID is standard (11 bits) or extended (29 bits)
//       sprintf(msgString, "Extended ID: 0x%.8lX  DLC: %1d  Data:", (rxId & 0x1FFFFFFF), len);
//     else
//       sprintf(msgString, "Standard ID: 0x%.3lX       DLC: %1d  Data:", rxId, len);
//     Serial.print(msgString);
//     if ((rxId & 0x40000000) == 0x40000000) {  // Determine if message is a remote request frame.
//       sprintf(msgString, " REMOTE REQUEST FRAME");
//       Serial.print(msgString);
//     } else {
//       for (byte i = 0; i < len; i++) {
//         sprintf(msgString, " 0x%.2X", rxBuf[i]);
//         Serial.print(msgString);
//       }
//     }
//     Serial.println();
//   }
//   // transmit data when space entered on keyboard
//   if(Serial.available()){
//     if (Serial.read() != ' ') return;
//     static byte data[8] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07 };
//        for (byte i = 0; i < 8; i++) {
//         sprintf(msgString, " 0x%.2X", data[i]);
//         Serial.print(msgString);
//       }
 
//     // send data:  ID = 0x100, Standard CAN Frame, Data length = 8 bytes, 'data' = array of data bytes to send
//     byte sndStat = CAN0.sendMsgBuf(0x100, 0, 8, data);
//     if (sndStat == CAN_OK) {
//       Serial.println(" Message Sent Successfully!");
//     } else {
//       Serial.println(" Error Sending Message...");
//     }
//     data[0]++;    // increment first byte of data
//  }
// }

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/

// #include <Arduino.h>
// #include <SPI.h>
// #include <mcp2515.h>

// #include <frc_can.h>
// #include <frc_can_utils.h>

// using namespace CanControl;

// // static const CAN_SPEED MCP2515_SPEED = CAN_125KBPS;
// // static const CAN_CLOCK MCP2515_OSC = MCP_8MHZ;
// static const uint8_t MCP2515_CS_PIN = 53;

// static MCP2515 mcp2515(MCP2515_CS_PIN);

// void show_frame(const can_frame &f);
// void show_frc_frame(const frc_can_frame &f);

// void setup()
// {
//     Serial.begin(115200);

//     MCP2515::RXF filters[] = {MCP2515::RXF0, MCP2515::RXF1, MCP2515::RXF2, MCP2515::RXF3, MCP2515::RXF4, MCP2515::RXF5};
//     for (int i=0; i<6; i++) {
//         bool ext = (i == 1);
//         MCP2515::ERROR result = mcp2515.setFilter(filters[i], ext, 0);
//         if (result != MCP2515::ERROR_OK) {
//             Serial.print("ERROR setting filter no. ");
//             Serial.println(i);
//         }
//     }

//     auto r = mcp2515.reset();
//     Serial.print("MCP2515 reset result: ");
//     Serial.println((int)r);

//     // Check for success (0 is success)
//     if (r == 0)
//     {
//         Serial.println("MCP2515 Reset SUCCESS!");
//     }
//     else
//     {
//         Serial.println("MCP2515 Reset ERROR. Check CS pin definition and wiring.");
//     }
// }

// void show_frame(const can_frame &f)
// {
//     Serial.print("ID: 0x");
//     Serial.println(f.can_id, HEX);
//     Serial.print("\tDLC: ");
//     Serial.println(f.can_dlc);
//     Serial.print("\tData: ");
//     for (uint8_t i = 0; i < f.can_dlc; ++i)
//     {
//         Serial.print(f.data[i], HEX);
//         Serial.print(" ");
//     }
//     Serial.println();
// }

// void show_frc_frame(const frc_can_frame &f)
// {
//     const frc_can_id &id = f.id;
//     Serial.println("FRC CAN ID:");
//     Serial.print("\tRaw: 0x");
//     Serial.println(id.raw, HEX);
//     Serial.print("\tRaw: 0b");
//     Serial.println(id.raw, BIN);
//     Serial.print("\tDevice Number: ");
//     Serial.println(id.device_number());
//     Serial.print("\tAPI Index: ");
//     Serial.println(id.api_index());
//     Serial.print("\tAPI Class: ");
//     Serial.println(id.api_class());
//     Serial.print("\tManufacturer Code: ");
//     Serial.println(id.manufacturer_code());
//     Serial.print("\tDevice Type: ");
//     Serial.println(id.device_type());
//     Serial.print("\tERR: ");
//     Serial.println(id.flag_err());
//     Serial.print("\tEFF: ");
//     Serial.println(id.flag_eff());
//     Serial.print("\tRTR: ");
//     Serial.println(id.flag_rtr());
// }

// void loop()
// {
//     return;
//     can_frame f;
//     if (mcp2515.readMessage(&f) != MCP2515::ERROR_OK)
//     {
//         return;
//     }
//     if (f.can_id == 0)
//     {
//         return;
//     }
//     show_frame(f);
//     frc_can_frame frc = from_can_frame(f);
//     show_frc_frame(frc);
// }
