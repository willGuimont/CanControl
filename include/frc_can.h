#pragma once
#include <stdint.h>
#include <string.h>

static const uint32_t EFF_FLAG = 0x80000000UL;
static const uint32_t RTR_FLAG = 0x40000000UL;
static const uint32_t ERR_FLAG = 0x20000000UL;

namespace CanControl
{
    // FRC/WPILib 29-bit CAN ID layout (LSB to MSB):
    // bits  0-5  : device_number    (6 bits)
    // bits  6-9  : api_index        (4 bits)
    // bits 10-15 : api_class        (6 bits)
    // bits 16-23 : manufacturerCode (8 bits)
    // bits 24-28 : device_type      (5 bits)
    // bits 29    : can ERR flag     (1 bit )
    // bits 30    : can RTR flag     (1 bit )
    // bits 31    : can EFF flag     (1 bit )

    struct frc_can_id
    {
        uint32_t raw{0};

        uint32_t frc_id() const { return raw & 0x1FFFFFFFu; }
        uint32_t device_number() const { return (raw >> 0) & 0x3Fu; }
        uint32_t api_index() const { return (raw >> 6) & 0x0Fu; }
        uint32_t api_class() const { return (raw >> 10) & 0x3Fu; }
        uint32_t manufacturer_code() const { return (raw >> 16) & 0xFFu; }
        uint32_t device_type() const { return (raw >> 24) & 0x1Fu; }
        bool flag_err() const { return (raw & ERR_FLAG) != 0; }
        bool flag_rtr() const { return (raw & RTR_FLAG) != 0; }
        bool flag_eff() const { return (raw & EFF_FLAG) != 0; }
    };

    typedef struct
    {
        frc_can_id id;
        uint8_t dlc;
        uint8_t data[8];
    } frc_can_frame;
}
