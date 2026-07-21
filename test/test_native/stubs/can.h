#pragma once

#include <stdint.h>

struct can_frame
{
    uint32_t can_id;
    uint8_t  can_dlc;
    alignas(8) uint8_t data[8];
};
