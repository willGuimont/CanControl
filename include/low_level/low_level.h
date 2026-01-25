#pragma once

#include "low_level/frc_can.h"

#include <mcp2515.h>
#include <stdint.h>
#include <string.h>

// Shared low-level helpers for packing/unpacking CAN payload bits and
// converting our internal frame representation to the mcp2515 can_frame.
//
// This header defines a small, generic CAN frame type and bitfield
// packing/unpacking helpers that are reused by all low-level device
// protocol layers (SparkMax, CTRE, etc.). Higher-level classes should
// not generally depend on it directly; instead they use the typed
// wrappers in low_sparkmax.h, low_ctrelectronics.h, etc.

namespace CanControl::LowLevel
{
    /**
     * @brief Generic 29-bit extended CAN frame used by higher-level device-specific code.
     *
     * This intermediate structure allows for easier manipulation of CAN data
     * before packing it into the hardware-specific `can_frame`.
     */
    struct basic_can_frame
    {
        uint32_t id;      /**< 29-bit extended ID (no flags) */
        uint8_t  dlc;     /**< Data length code (0-8) */
        uint8_t  data[8]; /**< Data payload */
        bool     is_rtr;  /**< Remote transmission request flag */
    };

    /**
     * @param buf The data buffer.
     * @param bit_index The index of the bit to read (0-indexed).
     * @return uint8_t The value of the bit (0 or 1).
     */
    inline uint8_t get_bit(const uint8_t* buf, uint32_t bit_index)
    {
        uint32_t byte_index = bit_index >> 3;
        uint8_t  bit_offset = bit_index & 7u;
        return (uint8_t)((buf[byte_index] >> bit_offset) & 1u);
    }

    /**
     * @param buf The data buffer to read from.
     * @param bit_pos The starting bit position.
     * @param bit_len The length of the field in bits.
     * @param big_endian True if the data is stored in big-endian format.
     * @return uint64_t The unpacked value.
     */
    inline uint64_t unpack_field(const uint8_t* buf, uint32_t bit_pos, uint32_t bit_len, bool big_endian)
    {
        if (big_endian && (bit_pos % 8u == 0u) && (bit_len % 8u == 0u))
        {
            uint32_t byte_pos  = bit_pos / 8u;
            uint32_t num_bytes = bit_len / 8u;
            uint64_t val       = 0;
            for (uint32_t i = 0; i < num_bytes; ++i)
            {
                val = (val << 8) | (uint64_t)buf[byte_pos + i];
            }
            return val;
        }

        uint64_t val = 0;
        for (uint32_t i = 0; i < bit_len; ++i)
        {
            uint8_t b = get_bit(buf, bit_pos + i);
            val |= ((uint64_t)b) << i;
        }
        return val;
    }

    /**
     * @param buf The data buffer to modify.
     * @param bit_index The index of the bit to set.
     * @param bit The value to write (non-zero for 1, 0 for 0).
     */
    inline void set_bit(uint8_t* buf, uint32_t bit_index, uint8_t bit)
    {
        uint32_t byte_index = bit_index >> 3;
        uint8_t  bit_offset = bit_index & 7u;
        if (bit)
            buf[byte_index] |= (uint8_t)(1u << bit_offset);
        else
            buf[byte_index] &= (uint8_t)~(1u << bit_offset);
    }

    /**
     * @param buf The data buffer to write to.
     * @param bit_pos The starting bit position.
     * @param bit_len The length of the field in bits.
     * @param raw The value to pack.
     * @param big_endian True if the data should be stored in big-endian format.
     */
    inline void pack_field(uint8_t* buf, uint32_t bit_pos, uint32_t bit_len, uint64_t raw, bool big_endian)
    {
        if (big_endian && (bit_pos % 8u == 0u) && (bit_len % 8u == 0u))
        {
            uint32_t byte_pos  = bit_pos / 8u;
            uint32_t num_bytes = bit_len / 8u;
            for (uint32_t i = 0; i < num_bytes; ++i)
            {
                uint32_t shift    = 8u * (num_bytes - 1u - i);
                buf[byte_pos + i] = (uint8_t)((raw >> shift) & 0xFFu);
            }
            return;
        }

        for (uint32_t i = 0; i < bit_len; ++i)
        {
            uint8_t b = (uint8_t)((raw >> i) & 1u);
            set_bit(buf, bit_pos + i, b);
        }
    }

    /**
     * @brief Adapts the 29-bit ID to the format expected by the MCP2515 library (setting EFF flags).
     *
     * @param in The input basic frame.
     * @param out Pointer to the output mcp2515 frame.
     */
    inline void basic_to_can_frame(const basic_can_frame& in, struct can_frame* out)
    {
        out->can_id = (uint32_t)(in.id & CanControl::frc_can_id::MASK_frc_id) | EFF_FLAG;
        if (in.is_rtr)
            out->can_id |= RTR_FLAG;
        out->can_dlc = in.dlc;
        memset(out->data, 0, sizeof(out->data));
        if (in.dlc > 0u)
        {
            memcpy(out->data, in.data, in.dlc);
        }
    }
} // namespace CanControl::LowLevel
