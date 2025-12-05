// AUTO-GENERATED FILE. DO NOT EDIT. See gen.py
#include "spark_can.h"
#include <string.h>

namespace CanControl::SparkMax {

static inline uint8_t get_bit(const uint8_t* buf, uint32_t bit_index) {
    uint32_t byte_index = bit_index >> 3;
    uint8_t bit_offset = bit_index & 7u;
    return (uint8_t)((buf[byte_index] >> bit_offset) & 1u);
}

static uint64_t unpack_field(const uint8_t* buf, uint32_t bit_pos, uint32_t bit_len, bool big_endian) {
    if (big_endian && (bit_pos % 8u == 0u) && (bit_len % 8u == 0u)) {
        uint32_t byte_pos = bit_pos / 8u;
        uint32_t num_bytes = bit_len / 8u;
        uint64_t val = 0;
        for (uint32_t i = 0; i < num_bytes; ++i) {
            val = (val << 8) | (uint64_t)buf[byte_pos + i];
        }
        return val;
    }

    uint64_t val = 0;
    for (uint32_t i = 0; i < bit_len; ++i) {
        uint8_t b = get_bit(buf, bit_pos + i);
        val |= ((uint64_t)b) << i;
    }
    return val;
}

static inline void set_bit(uint8_t* buf, uint32_t bit_index, uint8_t bit) {
    uint32_t byte_index = bit_index >> 3;
    uint8_t bit_offset = bit_index & 7u;
    if (bit) buf[byte_index] |= (uint8_t)(1u << bit_offset); else buf[byte_index] &= (uint8_t)~(1u << bit_offset);
}

static void pack_field(uint8_t* buf, uint32_t bit_pos, uint32_t bit_len, uint64_t raw, bool big_endian) {
    if (big_endian && (bit_pos % 8u == 0u) && (bit_len % 8u == 0u)) {
        uint32_t byte_pos = bit_pos / 8u;
        uint32_t num_bytes = bit_len / 8u;
        for (uint32_t i = 0; i < num_bytes; ++i) {
            uint32_t shift = 8u * (num_bytes - 1u - i);
            buf[byte_pos + i] = (uint8_t)((raw >> shift) & 0xFFu);
        }
        return;
    }

    for (uint32_t i = 0; i < bit_len; ++i) {
        uint8_t b = (uint8_t)((raw >> i) & 1u);
        set_bit(buf, bit_pos + i, b);
    }
}

static inline void spark_frame_to_can_frame(const spark_can_frame& in, struct can_frame* out) {
    out->can_id = (uint32_t)(in.id & 0x1FFFFFFFu) | EFF_FLAG;
    if (in.is_rtr) out->can_id |= RTR_FLAG;
    out->can_dlc = in.dlc;
    memset(out->data, 0, sizeof(out->data));
    if (in.dlc > 0u) {
        memcpy(out->data, in.data, in.dlc);
    }
}

spark_can_frame spark_build_VELOCITY_SETPOINT(uint8_t device_id, const Spark_VELOCITY_SETPOINT_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33882112u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    union { float f; uint32_t u; } _SETPOINT = { .f = values ? values->SETPOINT : 0.0f };
    pack_field(out.data, 0u, 32u, (uint64_t)_SETPOINT.u, false);
    int64_t _ARBITRARY_FEEDFORWARD_s = values ? (int64_t)values->ARBITRARY_FEEDFORWARD : 0;
    uint64_t _ARBITRARY_FEEDFORWARD = (uint64_t)_ARBITRARY_FEEDFORWARD_s & (((1ull<<16)-1ull));
    pack_field(out.data, 32u, 16u, _ARBITRARY_FEEDFORWARD, false);
    uint64_t _PID_SLOT = values ? (uint64_t)values->PID_SLOT : 0ull;
    pack_field(out.data, 48u, 2u, _PID_SLOT, false);
    uint64_t _ARBITRARY_FEEDFORWARD_UNITS = values ? (uint64_t)values->ARBITRARY_FEEDFORWARD_UNITS : 0ull;
    pack_field(out.data, 50u, 1u, _ARBITRARY_FEEDFORWARD_UNITS, false);
    return out;
}

spark_can_frame spark_build_DUTY_CYCLE_SETPOINT(uint8_t device_id, const Spark_DUTY_CYCLE_SETPOINT_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33882240u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    union { float f; uint32_t u; } _SETPOINT = { .f = values ? values->SETPOINT : 0.0f };
    pack_field(out.data, 0u, 32u, (uint64_t)_SETPOINT.u, false);
    int64_t _ARBITRARY_FEEDFORWARD_s = values ? (int64_t)values->ARBITRARY_FEEDFORWARD : 0;
    uint64_t _ARBITRARY_FEEDFORWARD = (uint64_t)_ARBITRARY_FEEDFORWARD_s & (((1ull<<16)-1ull));
    pack_field(out.data, 32u, 16u, _ARBITRARY_FEEDFORWARD, false);
    uint64_t _PID_SLOT = values ? (uint64_t)values->PID_SLOT : 0ull;
    pack_field(out.data, 48u, 2u, _PID_SLOT, false);
    uint64_t _ARBITRARY_FEEDFORWARD_UNITS = values ? (uint64_t)values->ARBITRARY_FEEDFORWARD_UNITS : 0ull;
    pack_field(out.data, 50u, 1u, _ARBITRARY_FEEDFORWARD_UNITS, false);
    return out;
}

spark_can_frame spark_build_SMART_VELOCITY_SETPOINT(uint8_t device_id, const Spark_SMART_VELOCITY_SETPOINT_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33882304u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    union { float f; uint32_t u; } _SETPOINT = { .f = values ? values->SETPOINT : 0.0f };
    pack_field(out.data, 0u, 32u, (uint64_t)_SETPOINT.u, false);
    int64_t _ARBITRARY_FEEDFORWARD_s = values ? (int64_t)values->ARBITRARY_FEEDFORWARD : 0;
    uint64_t _ARBITRARY_FEEDFORWARD = (uint64_t)_ARBITRARY_FEEDFORWARD_s & (((1ull<<16)-1ull));
    pack_field(out.data, 32u, 16u, _ARBITRARY_FEEDFORWARD, false);
    uint64_t _PID_SLOT = values ? (uint64_t)values->PID_SLOT : 0ull;
    pack_field(out.data, 48u, 2u, _PID_SLOT, false);
    uint64_t _ARBITRARY_FEEDFORWARD_UNITS = values ? (uint64_t)values->ARBITRARY_FEEDFORWARD_UNITS : 0ull;
    pack_field(out.data, 50u, 1u, _ARBITRARY_FEEDFORWARD_UNITS, false);
    return out;
}

spark_can_frame spark_build_POSITION_SETPOINT(uint8_t device_id, const Spark_POSITION_SETPOINT_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33882368u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    union { float f; uint32_t u; } _SETPOINT = { .f = values ? values->SETPOINT : 0.0f };
    pack_field(out.data, 0u, 32u, (uint64_t)_SETPOINT.u, false);
    int64_t _ARBITRARY_FEEDFORWARD_s = values ? (int64_t)values->ARBITRARY_FEEDFORWARD : 0;
    uint64_t _ARBITRARY_FEEDFORWARD = (uint64_t)_ARBITRARY_FEEDFORWARD_s & (((1ull<<16)-1ull));
    pack_field(out.data, 32u, 16u, _ARBITRARY_FEEDFORWARD, false);
    uint64_t _PID_SLOT = values ? (uint64_t)values->PID_SLOT : 0ull;
    pack_field(out.data, 48u, 2u, _PID_SLOT, false);
    uint64_t _ARBITRARY_FEEDFORWARD_UNITS = values ? (uint64_t)values->ARBITRARY_FEEDFORWARD_UNITS : 0ull;
    pack_field(out.data, 50u, 1u, _ARBITRARY_FEEDFORWARD_UNITS, false);
    return out;
}

spark_can_frame spark_build_VOLTAGE_SETPOINT(uint8_t device_id, const Spark_VOLTAGE_SETPOINT_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33882432u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    union { float f; uint32_t u; } _SETPOINT = { .f = values ? values->SETPOINT : 0.0f };
    pack_field(out.data, 0u, 32u, (uint64_t)_SETPOINT.u, false);
    int64_t _ARBITRARY_FEEDFORWARD_s = values ? (int64_t)values->ARBITRARY_FEEDFORWARD : 0;
    uint64_t _ARBITRARY_FEEDFORWARD = (uint64_t)_ARBITRARY_FEEDFORWARD_s & (((1ull<<16)-1ull));
    pack_field(out.data, 32u, 16u, _ARBITRARY_FEEDFORWARD, false);
    uint64_t _PID_SLOT = values ? (uint64_t)values->PID_SLOT : 0ull;
    pack_field(out.data, 48u, 2u, _PID_SLOT, false);
    uint64_t _ARBITRARY_FEEDFORWARD_UNITS = values ? (uint64_t)values->ARBITRARY_FEEDFORWARD_UNITS : 0ull;
    pack_field(out.data, 50u, 1u, _ARBITRARY_FEEDFORWARD_UNITS, false);
    return out;
}

spark_can_frame spark_build_CURRENT_SETPOINT(uint8_t device_id, const Spark_CURRENT_SETPOINT_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33882496u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    union { float f; uint32_t u; } _SETPOINT = { .f = values ? values->SETPOINT : 0.0f };
    pack_field(out.data, 0u, 32u, (uint64_t)_SETPOINT.u, false);
    int64_t _ARBITRARY_FEEDFORWARD_s = values ? (int64_t)values->ARBITRARY_FEEDFORWARD : 0;
    uint64_t _ARBITRARY_FEEDFORWARD = (uint64_t)_ARBITRARY_FEEDFORWARD_s & (((1ull<<16)-1ull));
    pack_field(out.data, 32u, 16u, _ARBITRARY_FEEDFORWARD, false);
    uint64_t _PID_SLOT = values ? (uint64_t)values->PID_SLOT : 0ull;
    pack_field(out.data, 48u, 2u, _PID_SLOT, false);
    uint64_t _ARBITRARY_FEEDFORWARD_UNITS = values ? (uint64_t)values->ARBITRARY_FEEDFORWARD_UNITS : 0ull;
    pack_field(out.data, 50u, 1u, _ARBITRARY_FEEDFORWARD_UNITS, false);
    return out;
}

spark_can_frame spark_build_SMART_MOTION_SETPOINT(uint8_t device_id, const Spark_SMART_MOTION_SETPOINT_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33882560u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    union { float f; uint32_t u; } _SETPOINT = { .f = values ? values->SETPOINT : 0.0f };
    pack_field(out.data, 0u, 32u, (uint64_t)_SETPOINT.u, false);
    int64_t _ARBITRARY_FEEDFORWARD_s = values ? (int64_t)values->ARBITRARY_FEEDFORWARD : 0;
    uint64_t _ARBITRARY_FEEDFORWARD = (uint64_t)_ARBITRARY_FEEDFORWARD_s & (((1ull<<16)-1ull));
    pack_field(out.data, 32u, 16u, _ARBITRARY_FEEDFORWARD, false);
    uint64_t _PID_SLOT = values ? (uint64_t)values->PID_SLOT : 0ull;
    pack_field(out.data, 48u, 2u, _PID_SLOT, false);
    uint64_t _ARBITRARY_FEEDFORWARD_UNITS = values ? (uint64_t)values->ARBITRARY_FEEDFORWARD_UNITS : 0ull;
    pack_field(out.data, 50u, 1u, _ARBITRARY_FEEDFORWARD_UNITS, false);
    return out;
}

spark_can_frame spark_build_MAXMOTION_POSITION_SETPOINT(uint8_t device_id, const Spark_MAXMOTION_POSITION_SETPOINT_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33882624u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    union { float f; uint32_t u; } _SETPOINT = { .f = values ? values->SETPOINT : 0.0f };
    pack_field(out.data, 0u, 32u, (uint64_t)_SETPOINT.u, false);
    int64_t _ARBITRARY_FEEDFORWARD_s = values ? (int64_t)values->ARBITRARY_FEEDFORWARD : 0;
    uint64_t _ARBITRARY_FEEDFORWARD = (uint64_t)_ARBITRARY_FEEDFORWARD_s & (((1ull<<16)-1ull));
    pack_field(out.data, 32u, 16u, _ARBITRARY_FEEDFORWARD, false);
    uint64_t _PID_SLOT = values ? (uint64_t)values->PID_SLOT : 0ull;
    pack_field(out.data, 48u, 2u, _PID_SLOT, false);
    uint64_t _ARBITRARY_FEEDFORWARD_UNITS = values ? (uint64_t)values->ARBITRARY_FEEDFORWARD_UNITS : 0ull;
    pack_field(out.data, 50u, 1u, _ARBITRARY_FEEDFORWARD_UNITS, false);
    return out;
}

spark_can_frame spark_build_MAXMOTION_VELOCITY_SETPOINT(uint8_t device_id, const Spark_MAXMOTION_VELOCITY_SETPOINT_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33882688u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    union { float f; uint32_t u; } _SETPOINT = { .f = values ? values->SETPOINT : 0.0f };
    pack_field(out.data, 0u, 32u, (uint64_t)_SETPOINT.u, false);
    int64_t _ARBITRARY_FEEDFORWARD_s = values ? (int64_t)values->ARBITRARY_FEEDFORWARD : 0;
    uint64_t _ARBITRARY_FEEDFORWARD = (uint64_t)_ARBITRARY_FEEDFORWARD_s & (((1ull<<16)-1ull));
    pack_field(out.data, 32u, 16u, _ARBITRARY_FEEDFORWARD, false);
    uint64_t _PID_SLOT = values ? (uint64_t)values->PID_SLOT : 0ull;
    pack_field(out.data, 48u, 2u, _PID_SLOT, false);
    uint64_t _ARBITRARY_FEEDFORWARD_UNITS = values ? (uint64_t)values->ARBITRARY_FEEDFORWARD_UNITS : 0ull;
    pack_field(out.data, 50u, 1u, _ARBITRARY_FEEDFORWARD_UNITS, false);
    return out;
}

spark_can_frame spark_build_SET_STATUSES_ENABLED(uint8_t device_id, const Spark_SET_STATUSES_ENABLED_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33883136u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 4u;
    out.is_rtr = false;
    memset(out.data, 0, 4);
    uint64_t _MASK = values ? (uint64_t)values->MASK : 0ull;
    pack_field(out.data, 0u, 16u, _MASK, false);
    uint64_t _ENABLED_BITFIELD = values ? (uint64_t)values->ENABLED_BITFIELD : 0ull;
    pack_field(out.data, 16u, 16u, _ENABLED_BITFIELD, false);
    return out;
}

spark_can_frame spark_build_SET_STATUSES_ENABLED_RESPONSE(uint8_t device_id, const Spark_SET_STATUSES_ENABLED_RESPONSE_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33883200u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 5u;
    out.is_rtr = false;
    memset(out.data, 0, 5);
    uint64_t _RESULT_CODE = values ? (uint64_t)values->RESULT_CODE : 0ull;
    pack_field(out.data, 0u, 8u, _RESULT_CODE, false);
    uint64_t _SPECIFIED_MASK = values ? (uint64_t)values->SPECIFIED_MASK : 0ull;
    pack_field(out.data, 8u, 16u, _SPECIFIED_MASK, false);
    uint64_t _ENABLED_BITFIELD = values ? (uint64_t)values->ENABLED_BITFIELD : 0ull;
    pack_field(out.data, 24u, 16u, _ENABLED_BITFIELD, false);
    return out;
}

spark_can_frame spark_build_PERSIST_PARAMETERS_RESPONSE(uint8_t device_id, const Spark_PERSIST_PARAMETERS_RESPONSE_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33883392u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 1u;
    out.is_rtr = false;
    memset(out.data, 0, 1);
    uint64_t _RESULT_CODE = values ? (uint64_t)values->RESULT_CODE : 0ull;
    pack_field(out.data, 0u, 8u, _RESULT_CODE, false);
    return out;
}

spark_can_frame spark_build_RESET_SAFE_PARAMETERS(uint8_t device_id, const Spark_RESET_SAFE_PARAMETERS_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33883456u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 2u;
    out.is_rtr = false;
    memset(out.data, 0, 2);
    uint64_t _MAGIC_NUMBER = values ? (uint64_t)values->MAGIC_NUMBER : 0ull;
    pack_field(out.data, 0u, 16u, _MAGIC_NUMBER, false);
    return out;
}

spark_can_frame spark_build_RESET_SAFE_PARAMETERS_RESPONSE(uint8_t device_id, const Spark_RESET_SAFE_PARAMETERS_RESPONSE_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33883520u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 1u;
    out.is_rtr = false;
    memset(out.data, 0, 1);
    uint64_t _RESULT_CODE = values ? (uint64_t)values->RESULT_CODE : 0ull;
    pack_field(out.data, 0u, 8u, _RESULT_CODE, false);
    return out;
}

spark_can_frame spark_build_COMPLETE_FACTORY_RESET(uint8_t device_id, const Spark_COMPLETE_FACTORY_RESET_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33883584u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 2u;
    out.is_rtr = false;
    memset(out.data, 0, 2);
    uint64_t _MAGIC_NUMBER = values ? (uint64_t)values->MAGIC_NUMBER : 0ull;
    pack_field(out.data, 0u, 16u, _MAGIC_NUMBER, false);
    return out;
}

spark_can_frame spark_build_COMPLETE_FACTORY_RESET_RESPONSE(uint8_t device_id, const Spark_COMPLETE_FACTORY_RESET_RESPONSE_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33883648u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 1u;
    out.is_rtr = false;
    memset(out.data, 0, 1);
    uint64_t _RESULT_CODE = values ? (uint64_t)values->RESULT_CODE : 0ull;
    pack_field(out.data, 0u, 8u, _RESULT_CODE, false);
    return out;
}

spark_can_frame spark_build_CLEAR_FAULTS(uint8_t device_id, const Spark_CLEAR_FAULTS_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33889152u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 0u;
    out.is_rtr = false;
    return out;
}

spark_can_frame spark_build_IDENTIFY_UNIQUE_SPARK(uint8_t device_id, const Spark_IDENTIFY_UNIQUE_SPARK_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33889664u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 4u;
    out.is_rtr = false;
    memset(out.data, 0, 4);
    uint64_t _UNIQUE_ID = values ? (uint64_t)values->UNIQUE_ID : 0ull;
    pack_field(out.data, 0u, 32u, _UNIQUE_ID, false);
    return out;
}

spark_can_frame spark_build_IDENTIFY(uint8_t device_id, const Spark_IDENTIFY_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33889728u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 0u;
    out.is_rtr = false;
    return out;
}

spark_can_frame spark_build_NACK(uint8_t device_id, const Spark_NACK_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33890304u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 0u;
    out.is_rtr = false;
    return out;
}

spark_can_frame spark_build_ACK(uint8_t device_id, const Spark_ACK_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33890368u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 0u;
    out.is_rtr = false;
    return out;
}

spark_can_frame spark_build_LED_SYNC(uint8_t device_id, const Spark_LED_SYNC_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33891520u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 0u;
    out.is_rtr = false;
    return out;
}

spark_can_frame spark_build_SET_CAN_ID(uint8_t device_id, const Spark_SET_CAN_ID_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33891648u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 5u;
    out.is_rtr = false;
    memset(out.data, 0, 5);
    uint64_t _UNIQUE_ID = values ? (uint64_t)values->UNIQUE_ID : 0ull;
    pack_field(out.data, 0u, 32u, _UNIQUE_ID, false);
    uint64_t _CAN_ID = values ? (uint64_t)values->CAN_ID : 0ull;
    pack_field(out.data, 32u, 8u, _CAN_ID, false);
    return out;
}

spark_can_frame spark_build_GET_FIRMWARE_VERSION(uint8_t device_id, const Spark_GET_FIRMWARE_VERSION_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33891840u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_SWDL_DATA(uint8_t device_id, const Spark_SWDL_DATA_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33892096u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _DATA = values ? (uint64_t)values->DATA : 0ull;
    pack_field(out.data, 0u, 64u, _DATA, false);
    return out;
}

spark_can_frame spark_build_SWDL_CHECKSUM(uint8_t device_id, const Spark_SWDL_CHECKSUM_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33892160u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _CHECKSUM = values ? (uint64_t)values->CHECKSUM : 0ull;
    pack_field(out.data, 0u, 64u, _CHECKSUM, false);
    return out;
}

spark_can_frame spark_build_SWDL_RETRANSMIT(uint8_t device_id, const Spark_SWDL_RETRANSMIT_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33892224u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 0u;
    out.is_rtr = false;
    return out;
}

spark_can_frame spark_build_SET_PRIMARY_ENCODER_POSITION(uint8_t device_id, const Spark_SET_PRIMARY_ENCODER_POSITION_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33892352u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 5u;
    out.is_rtr = false;
    memset(out.data, 0, 5);
    union { float f; uint32_t u; } _POSITION = { .f = values ? values->POSITION : 0.0f };
    pack_field(out.data, 0u, 32u, (uint64_t)_POSITION.u, false);
    uint64_t _DATA_TYPE = values ? (uint64_t)values->DATA_TYPE : 0ull;
    pack_field(out.data, 32u, 8u, _DATA_TYPE, false);
    return out;
}

spark_can_frame spark_build_SET_I_ACCUMULATION(uint8_t device_id, const Spark_SET_I_ACCUMULATION_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33892480u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 5u;
    out.is_rtr = false;
    memset(out.data, 0, 5);
    union { float f; uint32_t u; } _I_ACCUMULATION = { .f = values ? values->I_ACCUMULATION : 0.0f };
    pack_field(out.data, 0u, 32u, (uint64_t)_I_ACCUMULATION.u, false);
    uint64_t _DATA_TYPE = values ? (uint64_t)values->DATA_TYPE : 0ull;
    pack_field(out.data, 32u, 8u, _DATA_TYPE, false);
    return out;
}

spark_can_frame spark_build_SET_ANALOG_POSITION(uint8_t device_id, const Spark_SET_ANALOG_POSITION_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33892544u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 5u;
    out.is_rtr = false;
    memset(out.data, 0, 5);
    union { float f; uint32_t u; } _POSITION = { .f = values ? values->POSITION : 0.0f };
    pack_field(out.data, 0u, 32u, (uint64_t)_POSITION.u, false);
    uint64_t _DATA_TYPE = values ? (uint64_t)values->DATA_TYPE : 0ull;
    pack_field(out.data, 32u, 8u, _DATA_TYPE, false);
    return out;
}

spark_can_frame spark_build_SET_EXT_OR_ALT_ENCODER_POSITION(uint8_t device_id, const Spark_SET_EXT_OR_ALT_ENCODER_POSITION_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33892608u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 5u;
    out.is_rtr = false;
    memset(out.data, 0, 5);
    union { float f; uint32_t u; } _POSITION = { .f = values ? values->POSITION : 0.0f };
    pack_field(out.data, 0u, 32u, (uint64_t)_POSITION.u, false);
    uint64_t _DATA_TYPE = values ? (uint64_t)values->DATA_TYPE : 0ull;
    pack_field(out.data, 32u, 8u, _DATA_TYPE, false);
    return out;
}

spark_can_frame spark_build_SET_DUTY_CYCLE_POSITION(uint8_t device_id, const Spark_SET_DUTY_CYCLE_POSITION_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33892672u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 5u;
    out.is_rtr = false;
    memset(out.data, 0, 5);
    union { float f; uint32_t u; } _POSITION = { .f = values ? values->POSITION : 0.0f };
    pack_field(out.data, 0u, 32u, (uint64_t)_POSITION.u, false);
    uint64_t _DATA_TYPE = values ? (uint64_t)values->DATA_TYPE : 0ull;
    pack_field(out.data, 32u, 8u, _DATA_TYPE, false);
    return out;
}

spark_can_frame spark_build_SECONDARY_HEARTBEAT(uint8_t device_id, const Spark_SECONDARY_HEARTBEAT_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33893504u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _ENABLED_SPARKS_BITFIELD = values ? (uint64_t)values->ENABLED_SPARKS_BITFIELD : 0ull;
    pack_field(out.data, 0u, 64u, _ENABLED_SPARKS_BITFIELD, false);
    return out;
}

spark_can_frame spark_build_USB_ONLY_IDENTIFY(uint8_t device_id, const Spark_USB_ONLY_IDENTIFY_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33893568u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 0u;
    out.is_rtr = true;
    return out;
}

spark_can_frame spark_build_USB_ONLY_ENTER_DFU_BOOTLOADER(uint8_t device_id, const Spark_USB_ONLY_ENTER_DFU_BOOTLOADER_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33893632u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 2u;
    out.is_rtr = false;
    memset(out.data, 0, 2);
    uint64_t _MAGIC_NUMBER = values ? (uint64_t)values->MAGIC_NUMBER : 0ull;
    pack_field(out.data, 0u, 16u, _MAGIC_NUMBER, false);
    return out;
}

spark_can_frame spark_build_GET_TEMPERATURES(uint8_t device_id, const Spark_GET_TEMPERATURES_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33894400u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_GET_MOTOR_INTERFACE(uint8_t device_id, const Spark_GET_MOTOR_INTERFACE_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33894720u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 3u;
    out.is_rtr = true;
    memset(out.data, 0, 3);
    return out;
}

spark_can_frame spark_build_GET_PARAMETER_0_TO_15_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_0_TO_15_TYPES_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33895424u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_GET_PARAMETER_16_TO_31_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_16_TO_31_TYPES_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33895488u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_GET_PARAMETER_32_TO_47_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_32_TO_47_TYPES_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33895552u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_GET_PARAMETER_48_TO_63_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_48_TO_63_TYPES_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33895616u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_GET_PARAMETER_64_TO_79_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_64_TO_79_TYPES_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33895680u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_GET_PARAMETER_80_TO_95_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_80_TO_95_TYPES_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33895744u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_GET_PARAMETER_96_TO_111_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_96_TO_111_TYPES_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33895808u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_GET_PARAMETER_112_TO_127_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_112_TO_127_TYPES_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33895872u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_GET_PARAMETER_128_TO_143_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_128_TO_143_TYPES_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33895936u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_GET_PARAMETER_144_TO_159_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_144_TO_159_TYPES_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33896000u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_GET_PARAMETER_160_TO_175_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_160_TO_175_TYPES_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33896064u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_GET_PARAMETER_176_TO_191_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_176_TO_191_TYPES_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33896128u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_GET_PARAMETER_192_TO_207_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_192_TO_207_TYPES_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33896192u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_GET_PARAMETER_208_TO_223_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_208_TO_223_TYPES_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33896256u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_GET_PARAMETER_224_TO_239_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_224_TO_239_TYPES_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33896320u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_GET_PARAMETER_240_TO_255_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_240_TO_255_TYPES_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33896384u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_PARAMETER_WRITE(uint8_t device_id, const Spark_PARAMETER_WRITE_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33896448u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 5u;
    out.is_rtr = false;
    memset(out.data, 0, 5);
    uint64_t _PARAMETER_ID = values ? (uint64_t)values->PARAMETER_ID : 0ull;
    pack_field(out.data, 0u, 8u, _PARAMETER_ID, false);
    uint64_t _VALUE = values ? (uint64_t)values->VALUE : 0ull;
    pack_field(out.data, 8u, 32u, _VALUE, false);
    return out;
}

spark_can_frame spark_build_PARAMETER_WRITE_RESPONSE(uint8_t device_id, const Spark_PARAMETER_WRITE_RESPONSE_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33896512u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 7u;
    out.is_rtr = false;
    memset(out.data, 0, 7);
    uint64_t _PARAMETER_ID = values ? (uint64_t)values->PARAMETER_ID : 0ull;
    pack_field(out.data, 0u, 8u, _PARAMETER_ID, false);
    uint64_t _PARAMETER_TYPE = values ? (uint64_t)values->PARAMETER_TYPE : 0ull;
    pack_field(out.data, 8u, 8u, _PARAMETER_TYPE, false);
    uint64_t _VALUE = values ? (uint64_t)values->VALUE : 0ull;
    pack_field(out.data, 16u, 32u, _VALUE, false);
    uint64_t _RESULT_CODE = values ? (uint64_t)values->RESULT_CODE : 0ull;
    pack_field(out.data, 48u, 8u, _RESULT_CODE, false);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_0_AND_1(uint8_t device_id, const Spark_READ_PARAMETER_0_AND_1_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33897472u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_2_AND_3(uint8_t device_id, const Spark_READ_PARAMETER_2_AND_3_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33897536u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_4_AND_5(uint8_t device_id, const Spark_READ_PARAMETER_4_AND_5_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33897600u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_6_AND_7(uint8_t device_id, const Spark_READ_PARAMETER_6_AND_7_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33897664u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_8_AND_9(uint8_t device_id, const Spark_READ_PARAMETER_8_AND_9_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33897728u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_10_AND_11(uint8_t device_id, const Spark_READ_PARAMETER_10_AND_11_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33897792u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_12_AND_13(uint8_t device_id, const Spark_READ_PARAMETER_12_AND_13_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33897856u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_14_AND_15(uint8_t device_id, const Spark_READ_PARAMETER_14_AND_15_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33897920u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_16_AND_17(uint8_t device_id, const Spark_READ_PARAMETER_16_AND_17_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33897984u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_18_AND_19(uint8_t device_id, const Spark_READ_PARAMETER_18_AND_19_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33898048u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_20_AND_21(uint8_t device_id, const Spark_READ_PARAMETER_20_AND_21_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33898112u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_22_AND_23(uint8_t device_id, const Spark_READ_PARAMETER_22_AND_23_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33898176u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_24_AND_25(uint8_t device_id, const Spark_READ_PARAMETER_24_AND_25_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33898240u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_26_AND_27(uint8_t device_id, const Spark_READ_PARAMETER_26_AND_27_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33898304u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_28_AND_29(uint8_t device_id, const Spark_READ_PARAMETER_28_AND_29_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33898368u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_30_AND_31(uint8_t device_id, const Spark_READ_PARAMETER_30_AND_31_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33898432u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_32_AND_33(uint8_t device_id, const Spark_READ_PARAMETER_32_AND_33_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33898496u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_34_AND_35(uint8_t device_id, const Spark_READ_PARAMETER_34_AND_35_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33898560u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_36_AND_37(uint8_t device_id, const Spark_READ_PARAMETER_36_AND_37_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33898624u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_38_AND_39(uint8_t device_id, const Spark_READ_PARAMETER_38_AND_39_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33898688u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_40_AND_41(uint8_t device_id, const Spark_READ_PARAMETER_40_AND_41_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33898752u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_42_AND_43(uint8_t device_id, const Spark_READ_PARAMETER_42_AND_43_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33898816u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_44_AND_45(uint8_t device_id, const Spark_READ_PARAMETER_44_AND_45_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33898880u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_46_AND_47(uint8_t device_id, const Spark_READ_PARAMETER_46_AND_47_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33898944u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_48_AND_49(uint8_t device_id, const Spark_READ_PARAMETER_48_AND_49_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33899008u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_50_AND_51(uint8_t device_id, const Spark_READ_PARAMETER_50_AND_51_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33899072u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_52_AND_53(uint8_t device_id, const Spark_READ_PARAMETER_52_AND_53_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33899136u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_54_AND_55(uint8_t device_id, const Spark_READ_PARAMETER_54_AND_55_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33899200u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_56_AND_57(uint8_t device_id, const Spark_READ_PARAMETER_56_AND_57_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33899264u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_58_AND_59(uint8_t device_id, const Spark_READ_PARAMETER_58_AND_59_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33899328u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_60_AND_61(uint8_t device_id, const Spark_READ_PARAMETER_60_AND_61_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33899392u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_62_AND_63(uint8_t device_id, const Spark_READ_PARAMETER_62_AND_63_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33899456u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_64_AND_65(uint8_t device_id, const Spark_READ_PARAMETER_64_AND_65_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33899520u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_66_AND_67(uint8_t device_id, const Spark_READ_PARAMETER_66_AND_67_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33899584u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_68_AND_69(uint8_t device_id, const Spark_READ_PARAMETER_68_AND_69_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33899648u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_70_AND_71(uint8_t device_id, const Spark_READ_PARAMETER_70_AND_71_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33899712u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_72_AND_73(uint8_t device_id, const Spark_READ_PARAMETER_72_AND_73_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33899776u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_74_AND_75(uint8_t device_id, const Spark_READ_PARAMETER_74_AND_75_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33899840u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_76_AND_77(uint8_t device_id, const Spark_READ_PARAMETER_76_AND_77_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33899904u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_78_AND_79(uint8_t device_id, const Spark_READ_PARAMETER_78_AND_79_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33899968u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_80_AND_81(uint8_t device_id, const Spark_READ_PARAMETER_80_AND_81_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33900032u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_82_AND_83(uint8_t device_id, const Spark_READ_PARAMETER_82_AND_83_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33900096u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_84_AND_85(uint8_t device_id, const Spark_READ_PARAMETER_84_AND_85_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33900160u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_86_AND_87(uint8_t device_id, const Spark_READ_PARAMETER_86_AND_87_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33900224u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_88_AND_89(uint8_t device_id, const Spark_READ_PARAMETER_88_AND_89_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33900288u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_90_AND_91(uint8_t device_id, const Spark_READ_PARAMETER_90_AND_91_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33900352u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_92_AND_93(uint8_t device_id, const Spark_READ_PARAMETER_92_AND_93_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33900416u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_94_AND_95(uint8_t device_id, const Spark_READ_PARAMETER_94_AND_95_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33900480u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_96_AND_97(uint8_t device_id, const Spark_READ_PARAMETER_96_AND_97_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33900544u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_98_AND_99(uint8_t device_id, const Spark_READ_PARAMETER_98_AND_99_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33900608u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_100_AND_101(uint8_t device_id, const Spark_READ_PARAMETER_100_AND_101_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33900672u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_102_AND_103(uint8_t device_id, const Spark_READ_PARAMETER_102_AND_103_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33900736u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_104_AND_105(uint8_t device_id, const Spark_READ_PARAMETER_104_AND_105_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33900800u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_106_AND_107(uint8_t device_id, const Spark_READ_PARAMETER_106_AND_107_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33900864u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_108_AND_109(uint8_t device_id, const Spark_READ_PARAMETER_108_AND_109_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33900928u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_110_AND_111(uint8_t device_id, const Spark_READ_PARAMETER_110_AND_111_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33900992u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_112_AND_113(uint8_t device_id, const Spark_READ_PARAMETER_112_AND_113_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33901056u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_114_AND_115(uint8_t device_id, const Spark_READ_PARAMETER_114_AND_115_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33901120u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_116_AND_117(uint8_t device_id, const Spark_READ_PARAMETER_116_AND_117_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33901184u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_118_AND_119(uint8_t device_id, const Spark_READ_PARAMETER_118_AND_119_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33901248u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_120_AND_121(uint8_t device_id, const Spark_READ_PARAMETER_120_AND_121_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33901312u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_122_AND_123(uint8_t device_id, const Spark_READ_PARAMETER_122_AND_123_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33901376u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_124_AND_125(uint8_t device_id, const Spark_READ_PARAMETER_124_AND_125_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33901440u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_126_AND_127(uint8_t device_id, const Spark_READ_PARAMETER_126_AND_127_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33901504u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_128_AND_129(uint8_t device_id, const Spark_READ_PARAMETER_128_AND_129_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33901568u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_130_AND_131(uint8_t device_id, const Spark_READ_PARAMETER_130_AND_131_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33901632u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_132_AND_133(uint8_t device_id, const Spark_READ_PARAMETER_132_AND_133_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33901696u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_134_AND_135(uint8_t device_id, const Spark_READ_PARAMETER_134_AND_135_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33901760u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_136_AND_137(uint8_t device_id, const Spark_READ_PARAMETER_136_AND_137_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33901824u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_138_AND_139(uint8_t device_id, const Spark_READ_PARAMETER_138_AND_139_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33901888u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_140_AND_141(uint8_t device_id, const Spark_READ_PARAMETER_140_AND_141_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33901952u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_142_AND_143(uint8_t device_id, const Spark_READ_PARAMETER_142_AND_143_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33902016u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_144_AND_145(uint8_t device_id, const Spark_READ_PARAMETER_144_AND_145_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33902080u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_146_AND_147(uint8_t device_id, const Spark_READ_PARAMETER_146_AND_147_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33902144u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_148_AND_149(uint8_t device_id, const Spark_READ_PARAMETER_148_AND_149_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33902208u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_150_AND_151(uint8_t device_id, const Spark_READ_PARAMETER_150_AND_151_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33902272u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_152_AND_153(uint8_t device_id, const Spark_READ_PARAMETER_152_AND_153_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33902336u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_154_AND_155(uint8_t device_id, const Spark_READ_PARAMETER_154_AND_155_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33902400u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_156_AND_157(uint8_t device_id, const Spark_READ_PARAMETER_156_AND_157_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33902464u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_158_AND_159(uint8_t device_id, const Spark_READ_PARAMETER_158_AND_159_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33902528u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_160_AND_161(uint8_t device_id, const Spark_READ_PARAMETER_160_AND_161_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33902592u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_162_AND_163(uint8_t device_id, const Spark_READ_PARAMETER_162_AND_163_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33902656u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_164_AND_165(uint8_t device_id, const Spark_READ_PARAMETER_164_AND_165_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33902720u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_166_AND_167(uint8_t device_id, const Spark_READ_PARAMETER_166_AND_167_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33902784u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_168_AND_169(uint8_t device_id, const Spark_READ_PARAMETER_168_AND_169_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33902848u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_170_AND_171(uint8_t device_id, const Spark_READ_PARAMETER_170_AND_171_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33902912u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_172_AND_173(uint8_t device_id, const Spark_READ_PARAMETER_172_AND_173_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33902976u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_174_AND_175(uint8_t device_id, const Spark_READ_PARAMETER_174_AND_175_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33903040u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_176_AND_177(uint8_t device_id, const Spark_READ_PARAMETER_176_AND_177_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33903104u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_178_AND_179(uint8_t device_id, const Spark_READ_PARAMETER_178_AND_179_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33903168u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_180_AND_181(uint8_t device_id, const Spark_READ_PARAMETER_180_AND_181_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33903232u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_182_AND_183(uint8_t device_id, const Spark_READ_PARAMETER_182_AND_183_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33903296u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_184_AND_185(uint8_t device_id, const Spark_READ_PARAMETER_184_AND_185_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33903360u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_186_AND_187(uint8_t device_id, const Spark_READ_PARAMETER_186_AND_187_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33903424u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_188_AND_189(uint8_t device_id, const Spark_READ_PARAMETER_188_AND_189_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33903488u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_190_AND_191(uint8_t device_id, const Spark_READ_PARAMETER_190_AND_191_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33903552u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_192_AND_193(uint8_t device_id, const Spark_READ_PARAMETER_192_AND_193_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33903616u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_194_AND_195(uint8_t device_id, const Spark_READ_PARAMETER_194_AND_195_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33903680u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_196_AND_197(uint8_t device_id, const Spark_READ_PARAMETER_196_AND_197_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33903744u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_198_AND_199(uint8_t device_id, const Spark_READ_PARAMETER_198_AND_199_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33903808u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_200_AND_201(uint8_t device_id, const Spark_READ_PARAMETER_200_AND_201_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33903872u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_202_AND_203(uint8_t device_id, const Spark_READ_PARAMETER_202_AND_203_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33903936u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_204_AND_205(uint8_t device_id, const Spark_READ_PARAMETER_204_AND_205_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33904000u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_206_AND_207(uint8_t device_id, const Spark_READ_PARAMETER_206_AND_207_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33904064u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_208_AND_209(uint8_t device_id, const Spark_READ_PARAMETER_208_AND_209_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33904128u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_210_AND_211(uint8_t device_id, const Spark_READ_PARAMETER_210_AND_211_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33904192u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_212_AND_213(uint8_t device_id, const Spark_READ_PARAMETER_212_AND_213_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33904256u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_214_AND_215(uint8_t device_id, const Spark_READ_PARAMETER_214_AND_215_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33904320u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_216_AND_217(uint8_t device_id, const Spark_READ_PARAMETER_216_AND_217_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33904384u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_218_AND_219(uint8_t device_id, const Spark_READ_PARAMETER_218_AND_219_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33904448u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_220_AND_221(uint8_t device_id, const Spark_READ_PARAMETER_220_AND_221_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33904512u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_222_AND_223(uint8_t device_id, const Spark_READ_PARAMETER_222_AND_223_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33904576u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_224_AND_225(uint8_t device_id, const Spark_READ_PARAMETER_224_AND_225_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33904640u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_226_AND_227(uint8_t device_id, const Spark_READ_PARAMETER_226_AND_227_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33904704u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_228_AND_229(uint8_t device_id, const Spark_READ_PARAMETER_228_AND_229_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33904768u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_230_AND_231(uint8_t device_id, const Spark_READ_PARAMETER_230_AND_231_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33904832u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_232_AND_233(uint8_t device_id, const Spark_READ_PARAMETER_232_AND_233_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33904896u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_234_AND_235(uint8_t device_id, const Spark_READ_PARAMETER_234_AND_235_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33904960u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_236_AND_237(uint8_t device_id, const Spark_READ_PARAMETER_236_AND_237_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33905024u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_238_AND_239(uint8_t device_id, const Spark_READ_PARAMETER_238_AND_239_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33905088u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_240_AND_241(uint8_t device_id, const Spark_READ_PARAMETER_240_AND_241_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33905152u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_242_AND_243(uint8_t device_id, const Spark_READ_PARAMETER_242_AND_243_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33905216u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_244_AND_245(uint8_t device_id, const Spark_READ_PARAMETER_244_AND_245_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33905280u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_246_AND_247(uint8_t device_id, const Spark_READ_PARAMETER_246_AND_247_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33905344u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_248_AND_249(uint8_t device_id, const Spark_READ_PARAMETER_248_AND_249_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33905408u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_250_AND_251(uint8_t device_id, const Spark_READ_PARAMETER_250_AND_251_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33905472u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_252_AND_253(uint8_t device_id, const Spark_READ_PARAMETER_252_AND_253_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33905536u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_READ_PARAMETER_254_AND_255(uint8_t device_id, const Spark_READ_PARAMETER_254_AND_255_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33905600u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = true;
    memset(out.data, 0, 8);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_0_AND_1(uint8_t device_id, const Spark_WRITE_PARAMETER_0_AND_1_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33905664u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_2_AND_3(uint8_t device_id, const Spark_WRITE_PARAMETER_2_AND_3_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33905728u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_4_AND_5(uint8_t device_id, const Spark_WRITE_PARAMETER_4_AND_5_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33905792u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_6_AND_7(uint8_t device_id, const Spark_WRITE_PARAMETER_6_AND_7_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33905856u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_8_AND_9(uint8_t device_id, const Spark_WRITE_PARAMETER_8_AND_9_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33905920u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_10_AND_11(uint8_t device_id, const Spark_WRITE_PARAMETER_10_AND_11_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33905984u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_12_AND_13(uint8_t device_id, const Spark_WRITE_PARAMETER_12_AND_13_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33906048u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_14_AND_15(uint8_t device_id, const Spark_WRITE_PARAMETER_14_AND_15_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33906112u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_16_AND_17(uint8_t device_id, const Spark_WRITE_PARAMETER_16_AND_17_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33906176u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_18_AND_19(uint8_t device_id, const Spark_WRITE_PARAMETER_18_AND_19_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33906240u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_20_AND_21(uint8_t device_id, const Spark_WRITE_PARAMETER_20_AND_21_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33906304u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_22_AND_23(uint8_t device_id, const Spark_WRITE_PARAMETER_22_AND_23_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33906368u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_24_AND_25(uint8_t device_id, const Spark_WRITE_PARAMETER_24_AND_25_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33906432u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_26_AND_27(uint8_t device_id, const Spark_WRITE_PARAMETER_26_AND_27_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33906496u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_28_AND_29(uint8_t device_id, const Spark_WRITE_PARAMETER_28_AND_29_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33906560u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_30_AND_31(uint8_t device_id, const Spark_WRITE_PARAMETER_30_AND_31_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33906624u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_32_AND_33(uint8_t device_id, const Spark_WRITE_PARAMETER_32_AND_33_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33906688u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_34_AND_35(uint8_t device_id, const Spark_WRITE_PARAMETER_34_AND_35_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33906752u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_36_AND_37(uint8_t device_id, const Spark_WRITE_PARAMETER_36_AND_37_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33906816u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_38_AND_39(uint8_t device_id, const Spark_WRITE_PARAMETER_38_AND_39_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33906880u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_40_AND_41(uint8_t device_id, const Spark_WRITE_PARAMETER_40_AND_41_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33906944u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_42_AND_43(uint8_t device_id, const Spark_WRITE_PARAMETER_42_AND_43_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33907008u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_44_AND_45(uint8_t device_id, const Spark_WRITE_PARAMETER_44_AND_45_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33907072u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_46_AND_47(uint8_t device_id, const Spark_WRITE_PARAMETER_46_AND_47_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33907136u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_48_AND_49(uint8_t device_id, const Spark_WRITE_PARAMETER_48_AND_49_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33907200u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_50_AND_51(uint8_t device_id, const Spark_WRITE_PARAMETER_50_AND_51_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33907264u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_52_AND_53(uint8_t device_id, const Spark_WRITE_PARAMETER_52_AND_53_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33907328u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_54_AND_55(uint8_t device_id, const Spark_WRITE_PARAMETER_54_AND_55_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33907392u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_56_AND_57(uint8_t device_id, const Spark_WRITE_PARAMETER_56_AND_57_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33907456u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_58_AND_59(uint8_t device_id, const Spark_WRITE_PARAMETER_58_AND_59_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33907520u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_60_AND_61(uint8_t device_id, const Spark_WRITE_PARAMETER_60_AND_61_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33907584u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_62_AND_63(uint8_t device_id, const Spark_WRITE_PARAMETER_62_AND_63_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33907648u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_64_AND_65(uint8_t device_id, const Spark_WRITE_PARAMETER_64_AND_65_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33907712u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_66_AND_67(uint8_t device_id, const Spark_WRITE_PARAMETER_66_AND_67_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33907776u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_68_AND_69(uint8_t device_id, const Spark_WRITE_PARAMETER_68_AND_69_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33907840u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_70_AND_71(uint8_t device_id, const Spark_WRITE_PARAMETER_70_AND_71_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33907904u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_72_AND_73(uint8_t device_id, const Spark_WRITE_PARAMETER_72_AND_73_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33907968u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_74_AND_75(uint8_t device_id, const Spark_WRITE_PARAMETER_74_AND_75_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33908032u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_76_AND_77(uint8_t device_id, const Spark_WRITE_PARAMETER_76_AND_77_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33908096u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_78_AND_79(uint8_t device_id, const Spark_WRITE_PARAMETER_78_AND_79_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33908160u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_80_AND_81(uint8_t device_id, const Spark_WRITE_PARAMETER_80_AND_81_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33908224u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_82_AND_83(uint8_t device_id, const Spark_WRITE_PARAMETER_82_AND_83_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33908288u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_84_AND_85(uint8_t device_id, const Spark_WRITE_PARAMETER_84_AND_85_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33908352u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_86_AND_87(uint8_t device_id, const Spark_WRITE_PARAMETER_86_AND_87_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33908416u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_88_AND_89(uint8_t device_id, const Spark_WRITE_PARAMETER_88_AND_89_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33908480u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_90_AND_91(uint8_t device_id, const Spark_WRITE_PARAMETER_90_AND_91_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33908544u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_92_AND_93(uint8_t device_id, const Spark_WRITE_PARAMETER_92_AND_93_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33908608u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_94_AND_95(uint8_t device_id, const Spark_WRITE_PARAMETER_94_AND_95_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33908672u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_96_AND_97(uint8_t device_id, const Spark_WRITE_PARAMETER_96_AND_97_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33908736u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_98_AND_99(uint8_t device_id, const Spark_WRITE_PARAMETER_98_AND_99_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33908800u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_100_AND_101(uint8_t device_id, const Spark_WRITE_PARAMETER_100_AND_101_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33908864u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_102_AND_103(uint8_t device_id, const Spark_WRITE_PARAMETER_102_AND_103_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33908928u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_104_AND_105(uint8_t device_id, const Spark_WRITE_PARAMETER_104_AND_105_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33908992u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_106_AND_107(uint8_t device_id, const Spark_WRITE_PARAMETER_106_AND_107_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33909056u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_108_AND_109(uint8_t device_id, const Spark_WRITE_PARAMETER_108_AND_109_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33909120u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_110_AND_111(uint8_t device_id, const Spark_WRITE_PARAMETER_110_AND_111_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33909184u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_112_AND_113(uint8_t device_id, const Spark_WRITE_PARAMETER_112_AND_113_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33909248u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_114_AND_115(uint8_t device_id, const Spark_WRITE_PARAMETER_114_AND_115_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33909312u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_116_AND_117(uint8_t device_id, const Spark_WRITE_PARAMETER_116_AND_117_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33909376u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_118_AND_119(uint8_t device_id, const Spark_WRITE_PARAMETER_118_AND_119_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33909440u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_120_AND_121(uint8_t device_id, const Spark_WRITE_PARAMETER_120_AND_121_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33909504u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_122_AND_123(uint8_t device_id, const Spark_WRITE_PARAMETER_122_AND_123_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33909568u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_124_AND_125(uint8_t device_id, const Spark_WRITE_PARAMETER_124_AND_125_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33909632u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_126_AND_127(uint8_t device_id, const Spark_WRITE_PARAMETER_126_AND_127_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33909696u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_128_AND_129(uint8_t device_id, const Spark_WRITE_PARAMETER_128_AND_129_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33909760u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_130_AND_131(uint8_t device_id, const Spark_WRITE_PARAMETER_130_AND_131_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33909824u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_132_AND_133(uint8_t device_id, const Spark_WRITE_PARAMETER_132_AND_133_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33909888u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_134_AND_135(uint8_t device_id, const Spark_WRITE_PARAMETER_134_AND_135_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33909952u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_136_AND_137(uint8_t device_id, const Spark_WRITE_PARAMETER_136_AND_137_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33910016u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_138_AND_139(uint8_t device_id, const Spark_WRITE_PARAMETER_138_AND_139_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33910080u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_140_AND_141(uint8_t device_id, const Spark_WRITE_PARAMETER_140_AND_141_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33910144u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_142_AND_143(uint8_t device_id, const Spark_WRITE_PARAMETER_142_AND_143_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33910208u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_144_AND_145(uint8_t device_id, const Spark_WRITE_PARAMETER_144_AND_145_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33910272u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_146_AND_147(uint8_t device_id, const Spark_WRITE_PARAMETER_146_AND_147_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33910336u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_148_AND_149(uint8_t device_id, const Spark_WRITE_PARAMETER_148_AND_149_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33910400u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_150_AND_151(uint8_t device_id, const Spark_WRITE_PARAMETER_150_AND_151_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33910464u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_152_AND_153(uint8_t device_id, const Spark_WRITE_PARAMETER_152_AND_153_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33910528u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_154_AND_155(uint8_t device_id, const Spark_WRITE_PARAMETER_154_AND_155_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33910592u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_156_AND_157(uint8_t device_id, const Spark_WRITE_PARAMETER_156_AND_157_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33910656u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_158_AND_159(uint8_t device_id, const Spark_WRITE_PARAMETER_158_AND_159_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33910720u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_160_AND_161(uint8_t device_id, const Spark_WRITE_PARAMETER_160_AND_161_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33910784u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_162_AND_163(uint8_t device_id, const Spark_WRITE_PARAMETER_162_AND_163_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33910848u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_164_AND_165(uint8_t device_id, const Spark_WRITE_PARAMETER_164_AND_165_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33910912u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_166_AND_167(uint8_t device_id, const Spark_WRITE_PARAMETER_166_AND_167_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33910976u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_168_AND_169(uint8_t device_id, const Spark_WRITE_PARAMETER_168_AND_169_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33911040u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_170_AND_171(uint8_t device_id, const Spark_WRITE_PARAMETER_170_AND_171_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33911104u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_172_AND_173(uint8_t device_id, const Spark_WRITE_PARAMETER_172_AND_173_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33911168u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_174_AND_175(uint8_t device_id, const Spark_WRITE_PARAMETER_174_AND_175_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33911232u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_176_AND_177(uint8_t device_id, const Spark_WRITE_PARAMETER_176_AND_177_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33911296u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_178_AND_179(uint8_t device_id, const Spark_WRITE_PARAMETER_178_AND_179_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33911360u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_180_AND_181(uint8_t device_id, const Spark_WRITE_PARAMETER_180_AND_181_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33911424u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_182_AND_183(uint8_t device_id, const Spark_WRITE_PARAMETER_182_AND_183_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33911488u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_184_AND_185(uint8_t device_id, const Spark_WRITE_PARAMETER_184_AND_185_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33911552u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_186_AND_187(uint8_t device_id, const Spark_WRITE_PARAMETER_186_AND_187_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33911616u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_188_AND_189(uint8_t device_id, const Spark_WRITE_PARAMETER_188_AND_189_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33911680u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_190_AND_191(uint8_t device_id, const Spark_WRITE_PARAMETER_190_AND_191_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33911744u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_192_AND_193(uint8_t device_id, const Spark_WRITE_PARAMETER_192_AND_193_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33911808u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_194_AND_195(uint8_t device_id, const Spark_WRITE_PARAMETER_194_AND_195_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33911872u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_196_AND_197(uint8_t device_id, const Spark_WRITE_PARAMETER_196_AND_197_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33911936u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_198_AND_199(uint8_t device_id, const Spark_WRITE_PARAMETER_198_AND_199_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33912000u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_200_AND_201(uint8_t device_id, const Spark_WRITE_PARAMETER_200_AND_201_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33912064u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_202_AND_203(uint8_t device_id, const Spark_WRITE_PARAMETER_202_AND_203_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33912128u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_204_AND_205(uint8_t device_id, const Spark_WRITE_PARAMETER_204_AND_205_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33912192u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_206_AND_207(uint8_t device_id, const Spark_WRITE_PARAMETER_206_AND_207_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33912256u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_208_AND_209(uint8_t device_id, const Spark_WRITE_PARAMETER_208_AND_209_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33912320u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_210_AND_211(uint8_t device_id, const Spark_WRITE_PARAMETER_210_AND_211_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33912384u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_212_AND_213(uint8_t device_id, const Spark_WRITE_PARAMETER_212_AND_213_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33912448u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_214_AND_215(uint8_t device_id, const Spark_WRITE_PARAMETER_214_AND_215_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33912512u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_216_AND_217(uint8_t device_id, const Spark_WRITE_PARAMETER_216_AND_217_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33912576u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_218_AND_219(uint8_t device_id, const Spark_WRITE_PARAMETER_218_AND_219_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33912640u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_220_AND_221(uint8_t device_id, const Spark_WRITE_PARAMETER_220_AND_221_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33912704u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_222_AND_223(uint8_t device_id, const Spark_WRITE_PARAMETER_222_AND_223_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33912768u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_224_AND_225(uint8_t device_id, const Spark_WRITE_PARAMETER_224_AND_225_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33912832u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_226_AND_227(uint8_t device_id, const Spark_WRITE_PARAMETER_226_AND_227_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33912896u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_228_AND_229(uint8_t device_id, const Spark_WRITE_PARAMETER_228_AND_229_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33912960u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_230_AND_231(uint8_t device_id, const Spark_WRITE_PARAMETER_230_AND_231_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33913024u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_232_AND_233(uint8_t device_id, const Spark_WRITE_PARAMETER_232_AND_233_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33913088u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_234_AND_235(uint8_t device_id, const Spark_WRITE_PARAMETER_234_AND_235_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33913152u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_236_AND_237(uint8_t device_id, const Spark_WRITE_PARAMETER_236_AND_237_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33913216u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_238_AND_239(uint8_t device_id, const Spark_WRITE_PARAMETER_238_AND_239_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33913280u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_240_AND_241(uint8_t device_id, const Spark_WRITE_PARAMETER_240_AND_241_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33913344u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_242_AND_243(uint8_t device_id, const Spark_WRITE_PARAMETER_242_AND_243_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33913408u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_244_AND_245(uint8_t device_id, const Spark_WRITE_PARAMETER_244_AND_245_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33913472u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_246_AND_247(uint8_t device_id, const Spark_WRITE_PARAMETER_246_AND_247_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33913536u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_248_AND_249(uint8_t device_id, const Spark_WRITE_PARAMETER_248_AND_249_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33913600u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_250_AND_251(uint8_t device_id, const Spark_WRITE_PARAMETER_250_AND_251_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33913664u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_252_AND_253(uint8_t device_id, const Spark_WRITE_PARAMETER_252_AND_253_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33913728u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_WRITE_PARAMETER_254_AND_255(uint8_t device_id, const Spark_WRITE_PARAMETER_254_AND_255_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33913792u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 8u;
    out.is_rtr = false;
    memset(out.data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
    return out;
}

spark_can_frame spark_build_START_FOLLOWER_MODE(uint8_t device_id, const Spark_START_FOLLOWER_MODE_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33913856u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 0u;
    out.is_rtr = false;
    return out;
}

spark_can_frame spark_build_START_FOLLOWER_MODE_RESPONSE(uint8_t device_id, const Spark_START_FOLLOWER_MODE_RESPONSE_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33913920u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 1u;
    out.is_rtr = false;
    memset(out.data, 0, 1);
    uint64_t _STATUS = values ? (uint64_t)values->STATUS : 0ull;
    pack_field(out.data, 0u, 8u, _STATUS, false);
    return out;
}

spark_can_frame spark_build_STOP_FOLLOWER_MODE(uint8_t device_id, const Spark_STOP_FOLLOWER_MODE_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33913984u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 0u;
    out.is_rtr = false;
    return out;
}

spark_can_frame spark_build_STOP_FOLLOWER_MODE_RESPONSE(uint8_t device_id, const Spark_STOP_FOLLOWER_MODE_RESPONSE_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33914048u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 0u;
    out.is_rtr = false;
    return out;
}

spark_can_frame spark_build_ENTER_SWDL_CAN_BOOTLOADER(uint8_t device_id, const Spark_ENTER_SWDL_CAN_BOOTLOADER_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33914816u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 0u;
    out.is_rtr = false;
    return out;
}

spark_can_frame spark_build_PERSIST_PARAMETERS(uint8_t device_id, const Spark_PERSIST_PARAMETERS_t* values) {
    spark_can_frame out{};
    out.id = (uint32_t)(33947584u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out.dlc = 2u;
    out.is_rtr = false;
    memset(out.data, 0, 2);
    uint64_t _MAGIC_NUMBER = values ? (uint64_t)values->MAGIC_NUMBER : 0ull;
    pack_field(out.data, 0u, 16u, _MAGIC_NUMBER, false);
    return out;
}

SparkCanDevice::SparkCanDevice(uint8_t device_id) : device_id_(device_id & SPARK_DEVICE_ID_MASK), controller_(nullptr) {}

SparkCanDevice::SparkCanDevice(MCP2515& controller, uint8_t device_id) : device_id_(device_id & SPARK_DEVICE_ID_MASK), controller_(&controller) {}

void SparkCanDevice::set_controller(MCP2515& controller) {
    controller_ = &controller;
}

MCP2515* SparkCanDevice::controller() const {
    return controller_;
}

bool SparkCanDevice::has_controller() const {
    return controller_ != nullptr;
}

void SparkCanDevice::set_device_id(uint8_t device_id) {
    device_id_ = device_id & SPARK_DEVICE_ID_MASK;
}

uint8_t SparkCanDevice::device_id() const {
    return device_id_;
}

MCP2515::ERROR SparkCanDevice::dispatch_frame(const spark_can_frame& frame) const {
    if (!controller_) {
        return MCP2515::ERROR_FAIL;
    }
    struct can_frame out{};
    spark_frame_to_can_frame(frame, &out);
    return controller_->sendMessage(&out);
}

spark_can_frame SparkCanDevice::build_VELOCITY_SETPOINT(const Spark_VELOCITY_SETPOINT_t* values) const {
    return spark_build_VELOCITY_SETPOINT(device_id_, values);
}

spark_can_frame SparkCanDevice::build_DUTY_CYCLE_SETPOINT(const Spark_DUTY_CYCLE_SETPOINT_t* values) const {
    return spark_build_DUTY_CYCLE_SETPOINT(device_id_, values);
}

spark_can_frame SparkCanDevice::build_SMART_VELOCITY_SETPOINT(const Spark_SMART_VELOCITY_SETPOINT_t* values) const {
    return spark_build_SMART_VELOCITY_SETPOINT(device_id_, values);
}

spark_can_frame SparkCanDevice::build_POSITION_SETPOINT(const Spark_POSITION_SETPOINT_t* values) const {
    return spark_build_POSITION_SETPOINT(device_id_, values);
}

spark_can_frame SparkCanDevice::build_VOLTAGE_SETPOINT(const Spark_VOLTAGE_SETPOINT_t* values) const {
    return spark_build_VOLTAGE_SETPOINT(device_id_, values);
}

spark_can_frame SparkCanDevice::build_CURRENT_SETPOINT(const Spark_CURRENT_SETPOINT_t* values) const {
    return spark_build_CURRENT_SETPOINT(device_id_, values);
}

spark_can_frame SparkCanDevice::build_SMART_MOTION_SETPOINT(const Spark_SMART_MOTION_SETPOINT_t* values) const {
    return spark_build_SMART_MOTION_SETPOINT(device_id_, values);
}

spark_can_frame SparkCanDevice::build_MAXMOTION_POSITION_SETPOINT(const Spark_MAXMOTION_POSITION_SETPOINT_t* values) const {
    return spark_build_MAXMOTION_POSITION_SETPOINT(device_id_, values);
}

spark_can_frame SparkCanDevice::build_MAXMOTION_VELOCITY_SETPOINT(const Spark_MAXMOTION_VELOCITY_SETPOINT_t* values) const {
    return spark_build_MAXMOTION_VELOCITY_SETPOINT(device_id_, values);
}

spark_can_frame SparkCanDevice::build_SET_STATUSES_ENABLED(const Spark_SET_STATUSES_ENABLED_t* values) const {
    return spark_build_SET_STATUSES_ENABLED(device_id_, values);
}

spark_can_frame SparkCanDevice::build_SET_STATUSES_ENABLED_RESPONSE(const Spark_SET_STATUSES_ENABLED_RESPONSE_t* values) const {
    return spark_build_SET_STATUSES_ENABLED_RESPONSE(device_id_, values);
}

spark_can_frame SparkCanDevice::build_PERSIST_PARAMETERS_RESPONSE(const Spark_PERSIST_PARAMETERS_RESPONSE_t* values) const {
    return spark_build_PERSIST_PARAMETERS_RESPONSE(device_id_, values);
}

spark_can_frame SparkCanDevice::build_RESET_SAFE_PARAMETERS(const Spark_RESET_SAFE_PARAMETERS_t* values) const {
    return spark_build_RESET_SAFE_PARAMETERS(device_id_, values);
}

spark_can_frame SparkCanDevice::build_RESET_SAFE_PARAMETERS_RESPONSE(const Spark_RESET_SAFE_PARAMETERS_RESPONSE_t* values) const {
    return spark_build_RESET_SAFE_PARAMETERS_RESPONSE(device_id_, values);
}

spark_can_frame SparkCanDevice::build_COMPLETE_FACTORY_RESET(const Spark_COMPLETE_FACTORY_RESET_t* values) const {
    return spark_build_COMPLETE_FACTORY_RESET(device_id_, values);
}

spark_can_frame SparkCanDevice::build_COMPLETE_FACTORY_RESET_RESPONSE(const Spark_COMPLETE_FACTORY_RESET_RESPONSE_t* values) const {
    return spark_build_COMPLETE_FACTORY_RESET_RESPONSE(device_id_, values);
}

spark_can_frame SparkCanDevice::build_CLEAR_FAULTS(const Spark_CLEAR_FAULTS_t* values) const {
    return spark_build_CLEAR_FAULTS(device_id_, values);
}

spark_can_frame SparkCanDevice::build_IDENTIFY_UNIQUE_SPARK(const Spark_IDENTIFY_UNIQUE_SPARK_t* values) const {
    return spark_build_IDENTIFY_UNIQUE_SPARK(device_id_, values);
}

spark_can_frame SparkCanDevice::build_IDENTIFY(const Spark_IDENTIFY_t* values) const {
    return spark_build_IDENTIFY(device_id_, values);
}

spark_can_frame SparkCanDevice::build_NACK(const Spark_NACK_t* values) const {
    return spark_build_NACK(device_id_, values);
}

spark_can_frame SparkCanDevice::build_ACK(const Spark_ACK_t* values) const {
    return spark_build_ACK(device_id_, values);
}

spark_can_frame SparkCanDevice::build_LED_SYNC(const Spark_LED_SYNC_t* values) const {
    return spark_build_LED_SYNC(device_id_, values);
}

spark_can_frame SparkCanDevice::build_SET_CAN_ID(const Spark_SET_CAN_ID_t* values) const {
    return spark_build_SET_CAN_ID(device_id_, values);
}

spark_can_frame SparkCanDevice::build_GET_FIRMWARE_VERSION(const Spark_GET_FIRMWARE_VERSION_t* values) const {
    return spark_build_GET_FIRMWARE_VERSION(device_id_, values);
}

spark_can_frame SparkCanDevice::build_SWDL_DATA(const Spark_SWDL_DATA_t* values) const {
    return spark_build_SWDL_DATA(device_id_, values);
}

spark_can_frame SparkCanDevice::build_SWDL_CHECKSUM(const Spark_SWDL_CHECKSUM_t* values) const {
    return spark_build_SWDL_CHECKSUM(device_id_, values);
}

spark_can_frame SparkCanDevice::build_SWDL_RETRANSMIT(const Spark_SWDL_RETRANSMIT_t* values) const {
    return spark_build_SWDL_RETRANSMIT(device_id_, values);
}

spark_can_frame SparkCanDevice::build_SET_PRIMARY_ENCODER_POSITION(const Spark_SET_PRIMARY_ENCODER_POSITION_t* values) const {
    return spark_build_SET_PRIMARY_ENCODER_POSITION(device_id_, values);
}

spark_can_frame SparkCanDevice::build_SET_I_ACCUMULATION(const Spark_SET_I_ACCUMULATION_t* values) const {
    return spark_build_SET_I_ACCUMULATION(device_id_, values);
}

spark_can_frame SparkCanDevice::build_SET_ANALOG_POSITION(const Spark_SET_ANALOG_POSITION_t* values) const {
    return spark_build_SET_ANALOG_POSITION(device_id_, values);
}

spark_can_frame SparkCanDevice::build_SET_EXT_OR_ALT_ENCODER_POSITION(const Spark_SET_EXT_OR_ALT_ENCODER_POSITION_t* values) const {
    return spark_build_SET_EXT_OR_ALT_ENCODER_POSITION(device_id_, values);
}

spark_can_frame SparkCanDevice::build_SET_DUTY_CYCLE_POSITION(const Spark_SET_DUTY_CYCLE_POSITION_t* values) const {
    return spark_build_SET_DUTY_CYCLE_POSITION(device_id_, values);
}

spark_can_frame SparkCanDevice::build_SECONDARY_HEARTBEAT(const Spark_SECONDARY_HEARTBEAT_t* values) const {
    return spark_build_SECONDARY_HEARTBEAT(device_id_, values);
}

spark_can_frame SparkCanDevice::build_USB_ONLY_IDENTIFY(const Spark_USB_ONLY_IDENTIFY_t* values) const {
    return spark_build_USB_ONLY_IDENTIFY(device_id_, values);
}

spark_can_frame SparkCanDevice::build_USB_ONLY_ENTER_DFU_BOOTLOADER(const Spark_USB_ONLY_ENTER_DFU_BOOTLOADER_t* values) const {
    return spark_build_USB_ONLY_ENTER_DFU_BOOTLOADER(device_id_, values);
}

spark_can_frame SparkCanDevice::build_GET_TEMPERATURES(const Spark_GET_TEMPERATURES_t* values) const {
    return spark_build_GET_TEMPERATURES(device_id_, values);
}

spark_can_frame SparkCanDevice::build_GET_MOTOR_INTERFACE(const Spark_GET_MOTOR_INTERFACE_t* values) const {
    return spark_build_GET_MOTOR_INTERFACE(device_id_, values);
}

spark_can_frame SparkCanDevice::build_GET_PARAMETER_0_TO_15_TYPES(const Spark_GET_PARAMETER_0_TO_15_TYPES_t* values) const {
    return spark_build_GET_PARAMETER_0_TO_15_TYPES(device_id_, values);
}

spark_can_frame SparkCanDevice::build_GET_PARAMETER_16_TO_31_TYPES(const Spark_GET_PARAMETER_16_TO_31_TYPES_t* values) const {
    return spark_build_GET_PARAMETER_16_TO_31_TYPES(device_id_, values);
}

spark_can_frame SparkCanDevice::build_GET_PARAMETER_32_TO_47_TYPES(const Spark_GET_PARAMETER_32_TO_47_TYPES_t* values) const {
    return spark_build_GET_PARAMETER_32_TO_47_TYPES(device_id_, values);
}

spark_can_frame SparkCanDevice::build_GET_PARAMETER_48_TO_63_TYPES(const Spark_GET_PARAMETER_48_TO_63_TYPES_t* values) const {
    return spark_build_GET_PARAMETER_48_TO_63_TYPES(device_id_, values);
}

spark_can_frame SparkCanDevice::build_GET_PARAMETER_64_TO_79_TYPES(const Spark_GET_PARAMETER_64_TO_79_TYPES_t* values) const {
    return spark_build_GET_PARAMETER_64_TO_79_TYPES(device_id_, values);
}

spark_can_frame SparkCanDevice::build_GET_PARAMETER_80_TO_95_TYPES(const Spark_GET_PARAMETER_80_TO_95_TYPES_t* values) const {
    return spark_build_GET_PARAMETER_80_TO_95_TYPES(device_id_, values);
}

spark_can_frame SparkCanDevice::build_GET_PARAMETER_96_TO_111_TYPES(const Spark_GET_PARAMETER_96_TO_111_TYPES_t* values) const {
    return spark_build_GET_PARAMETER_96_TO_111_TYPES(device_id_, values);
}

spark_can_frame SparkCanDevice::build_GET_PARAMETER_112_TO_127_TYPES(const Spark_GET_PARAMETER_112_TO_127_TYPES_t* values) const {
    return spark_build_GET_PARAMETER_112_TO_127_TYPES(device_id_, values);
}

spark_can_frame SparkCanDevice::build_GET_PARAMETER_128_TO_143_TYPES(const Spark_GET_PARAMETER_128_TO_143_TYPES_t* values) const {
    return spark_build_GET_PARAMETER_128_TO_143_TYPES(device_id_, values);
}

spark_can_frame SparkCanDevice::build_GET_PARAMETER_144_TO_159_TYPES(const Spark_GET_PARAMETER_144_TO_159_TYPES_t* values) const {
    return spark_build_GET_PARAMETER_144_TO_159_TYPES(device_id_, values);
}

spark_can_frame SparkCanDevice::build_GET_PARAMETER_160_TO_175_TYPES(const Spark_GET_PARAMETER_160_TO_175_TYPES_t* values) const {
    return spark_build_GET_PARAMETER_160_TO_175_TYPES(device_id_, values);
}

spark_can_frame SparkCanDevice::build_GET_PARAMETER_176_TO_191_TYPES(const Spark_GET_PARAMETER_176_TO_191_TYPES_t* values) const {
    return spark_build_GET_PARAMETER_176_TO_191_TYPES(device_id_, values);
}

spark_can_frame SparkCanDevice::build_GET_PARAMETER_192_TO_207_TYPES(const Spark_GET_PARAMETER_192_TO_207_TYPES_t* values) const {
    return spark_build_GET_PARAMETER_192_TO_207_TYPES(device_id_, values);
}

spark_can_frame SparkCanDevice::build_GET_PARAMETER_208_TO_223_TYPES(const Spark_GET_PARAMETER_208_TO_223_TYPES_t* values) const {
    return spark_build_GET_PARAMETER_208_TO_223_TYPES(device_id_, values);
}

spark_can_frame SparkCanDevice::build_GET_PARAMETER_224_TO_239_TYPES(const Spark_GET_PARAMETER_224_TO_239_TYPES_t* values) const {
    return spark_build_GET_PARAMETER_224_TO_239_TYPES(device_id_, values);
}

spark_can_frame SparkCanDevice::build_GET_PARAMETER_240_TO_255_TYPES(const Spark_GET_PARAMETER_240_TO_255_TYPES_t* values) const {
    return spark_build_GET_PARAMETER_240_TO_255_TYPES(device_id_, values);
}

spark_can_frame SparkCanDevice::build_PARAMETER_WRITE(const Spark_PARAMETER_WRITE_t* values) const {
    return spark_build_PARAMETER_WRITE(device_id_, values);
}

spark_can_frame SparkCanDevice::build_PARAMETER_WRITE_RESPONSE(const Spark_PARAMETER_WRITE_RESPONSE_t* values) const {
    return spark_build_PARAMETER_WRITE_RESPONSE(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_0_AND_1(const Spark_READ_PARAMETER_0_AND_1_t* values) const {
    return spark_build_READ_PARAMETER_0_AND_1(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_2_AND_3(const Spark_READ_PARAMETER_2_AND_3_t* values) const {
    return spark_build_READ_PARAMETER_2_AND_3(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_4_AND_5(const Spark_READ_PARAMETER_4_AND_5_t* values) const {
    return spark_build_READ_PARAMETER_4_AND_5(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_6_AND_7(const Spark_READ_PARAMETER_6_AND_7_t* values) const {
    return spark_build_READ_PARAMETER_6_AND_7(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_8_AND_9(const Spark_READ_PARAMETER_8_AND_9_t* values) const {
    return spark_build_READ_PARAMETER_8_AND_9(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_10_AND_11(const Spark_READ_PARAMETER_10_AND_11_t* values) const {
    return spark_build_READ_PARAMETER_10_AND_11(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_12_AND_13(const Spark_READ_PARAMETER_12_AND_13_t* values) const {
    return spark_build_READ_PARAMETER_12_AND_13(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_14_AND_15(const Spark_READ_PARAMETER_14_AND_15_t* values) const {
    return spark_build_READ_PARAMETER_14_AND_15(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_16_AND_17(const Spark_READ_PARAMETER_16_AND_17_t* values) const {
    return spark_build_READ_PARAMETER_16_AND_17(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_18_AND_19(const Spark_READ_PARAMETER_18_AND_19_t* values) const {
    return spark_build_READ_PARAMETER_18_AND_19(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_20_AND_21(const Spark_READ_PARAMETER_20_AND_21_t* values) const {
    return spark_build_READ_PARAMETER_20_AND_21(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_22_AND_23(const Spark_READ_PARAMETER_22_AND_23_t* values) const {
    return spark_build_READ_PARAMETER_22_AND_23(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_24_AND_25(const Spark_READ_PARAMETER_24_AND_25_t* values) const {
    return spark_build_READ_PARAMETER_24_AND_25(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_26_AND_27(const Spark_READ_PARAMETER_26_AND_27_t* values) const {
    return spark_build_READ_PARAMETER_26_AND_27(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_28_AND_29(const Spark_READ_PARAMETER_28_AND_29_t* values) const {
    return spark_build_READ_PARAMETER_28_AND_29(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_30_AND_31(const Spark_READ_PARAMETER_30_AND_31_t* values) const {
    return spark_build_READ_PARAMETER_30_AND_31(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_32_AND_33(const Spark_READ_PARAMETER_32_AND_33_t* values) const {
    return spark_build_READ_PARAMETER_32_AND_33(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_34_AND_35(const Spark_READ_PARAMETER_34_AND_35_t* values) const {
    return spark_build_READ_PARAMETER_34_AND_35(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_36_AND_37(const Spark_READ_PARAMETER_36_AND_37_t* values) const {
    return spark_build_READ_PARAMETER_36_AND_37(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_38_AND_39(const Spark_READ_PARAMETER_38_AND_39_t* values) const {
    return spark_build_READ_PARAMETER_38_AND_39(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_40_AND_41(const Spark_READ_PARAMETER_40_AND_41_t* values) const {
    return spark_build_READ_PARAMETER_40_AND_41(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_42_AND_43(const Spark_READ_PARAMETER_42_AND_43_t* values) const {
    return spark_build_READ_PARAMETER_42_AND_43(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_44_AND_45(const Spark_READ_PARAMETER_44_AND_45_t* values) const {
    return spark_build_READ_PARAMETER_44_AND_45(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_46_AND_47(const Spark_READ_PARAMETER_46_AND_47_t* values) const {
    return spark_build_READ_PARAMETER_46_AND_47(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_48_AND_49(const Spark_READ_PARAMETER_48_AND_49_t* values) const {
    return spark_build_READ_PARAMETER_48_AND_49(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_50_AND_51(const Spark_READ_PARAMETER_50_AND_51_t* values) const {
    return spark_build_READ_PARAMETER_50_AND_51(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_52_AND_53(const Spark_READ_PARAMETER_52_AND_53_t* values) const {
    return spark_build_READ_PARAMETER_52_AND_53(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_54_AND_55(const Spark_READ_PARAMETER_54_AND_55_t* values) const {
    return spark_build_READ_PARAMETER_54_AND_55(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_56_AND_57(const Spark_READ_PARAMETER_56_AND_57_t* values) const {
    return spark_build_READ_PARAMETER_56_AND_57(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_58_AND_59(const Spark_READ_PARAMETER_58_AND_59_t* values) const {
    return spark_build_READ_PARAMETER_58_AND_59(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_60_AND_61(const Spark_READ_PARAMETER_60_AND_61_t* values) const {
    return spark_build_READ_PARAMETER_60_AND_61(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_62_AND_63(const Spark_READ_PARAMETER_62_AND_63_t* values) const {
    return spark_build_READ_PARAMETER_62_AND_63(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_64_AND_65(const Spark_READ_PARAMETER_64_AND_65_t* values) const {
    return spark_build_READ_PARAMETER_64_AND_65(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_66_AND_67(const Spark_READ_PARAMETER_66_AND_67_t* values) const {
    return spark_build_READ_PARAMETER_66_AND_67(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_68_AND_69(const Spark_READ_PARAMETER_68_AND_69_t* values) const {
    return spark_build_READ_PARAMETER_68_AND_69(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_70_AND_71(const Spark_READ_PARAMETER_70_AND_71_t* values) const {
    return spark_build_READ_PARAMETER_70_AND_71(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_72_AND_73(const Spark_READ_PARAMETER_72_AND_73_t* values) const {
    return spark_build_READ_PARAMETER_72_AND_73(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_74_AND_75(const Spark_READ_PARAMETER_74_AND_75_t* values) const {
    return spark_build_READ_PARAMETER_74_AND_75(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_76_AND_77(const Spark_READ_PARAMETER_76_AND_77_t* values) const {
    return spark_build_READ_PARAMETER_76_AND_77(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_78_AND_79(const Spark_READ_PARAMETER_78_AND_79_t* values) const {
    return spark_build_READ_PARAMETER_78_AND_79(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_80_AND_81(const Spark_READ_PARAMETER_80_AND_81_t* values) const {
    return spark_build_READ_PARAMETER_80_AND_81(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_82_AND_83(const Spark_READ_PARAMETER_82_AND_83_t* values) const {
    return spark_build_READ_PARAMETER_82_AND_83(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_84_AND_85(const Spark_READ_PARAMETER_84_AND_85_t* values) const {
    return spark_build_READ_PARAMETER_84_AND_85(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_86_AND_87(const Spark_READ_PARAMETER_86_AND_87_t* values) const {
    return spark_build_READ_PARAMETER_86_AND_87(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_88_AND_89(const Spark_READ_PARAMETER_88_AND_89_t* values) const {
    return spark_build_READ_PARAMETER_88_AND_89(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_90_AND_91(const Spark_READ_PARAMETER_90_AND_91_t* values) const {
    return spark_build_READ_PARAMETER_90_AND_91(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_92_AND_93(const Spark_READ_PARAMETER_92_AND_93_t* values) const {
    return spark_build_READ_PARAMETER_92_AND_93(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_94_AND_95(const Spark_READ_PARAMETER_94_AND_95_t* values) const {
    return spark_build_READ_PARAMETER_94_AND_95(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_96_AND_97(const Spark_READ_PARAMETER_96_AND_97_t* values) const {
    return spark_build_READ_PARAMETER_96_AND_97(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_98_AND_99(const Spark_READ_PARAMETER_98_AND_99_t* values) const {
    return spark_build_READ_PARAMETER_98_AND_99(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_100_AND_101(const Spark_READ_PARAMETER_100_AND_101_t* values) const {
    return spark_build_READ_PARAMETER_100_AND_101(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_102_AND_103(const Spark_READ_PARAMETER_102_AND_103_t* values) const {
    return spark_build_READ_PARAMETER_102_AND_103(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_104_AND_105(const Spark_READ_PARAMETER_104_AND_105_t* values) const {
    return spark_build_READ_PARAMETER_104_AND_105(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_106_AND_107(const Spark_READ_PARAMETER_106_AND_107_t* values) const {
    return spark_build_READ_PARAMETER_106_AND_107(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_108_AND_109(const Spark_READ_PARAMETER_108_AND_109_t* values) const {
    return spark_build_READ_PARAMETER_108_AND_109(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_110_AND_111(const Spark_READ_PARAMETER_110_AND_111_t* values) const {
    return spark_build_READ_PARAMETER_110_AND_111(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_112_AND_113(const Spark_READ_PARAMETER_112_AND_113_t* values) const {
    return spark_build_READ_PARAMETER_112_AND_113(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_114_AND_115(const Spark_READ_PARAMETER_114_AND_115_t* values) const {
    return spark_build_READ_PARAMETER_114_AND_115(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_116_AND_117(const Spark_READ_PARAMETER_116_AND_117_t* values) const {
    return spark_build_READ_PARAMETER_116_AND_117(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_118_AND_119(const Spark_READ_PARAMETER_118_AND_119_t* values) const {
    return spark_build_READ_PARAMETER_118_AND_119(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_120_AND_121(const Spark_READ_PARAMETER_120_AND_121_t* values) const {
    return spark_build_READ_PARAMETER_120_AND_121(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_122_AND_123(const Spark_READ_PARAMETER_122_AND_123_t* values) const {
    return spark_build_READ_PARAMETER_122_AND_123(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_124_AND_125(const Spark_READ_PARAMETER_124_AND_125_t* values) const {
    return spark_build_READ_PARAMETER_124_AND_125(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_126_AND_127(const Spark_READ_PARAMETER_126_AND_127_t* values) const {
    return spark_build_READ_PARAMETER_126_AND_127(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_128_AND_129(const Spark_READ_PARAMETER_128_AND_129_t* values) const {
    return spark_build_READ_PARAMETER_128_AND_129(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_130_AND_131(const Spark_READ_PARAMETER_130_AND_131_t* values) const {
    return spark_build_READ_PARAMETER_130_AND_131(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_132_AND_133(const Spark_READ_PARAMETER_132_AND_133_t* values) const {
    return spark_build_READ_PARAMETER_132_AND_133(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_134_AND_135(const Spark_READ_PARAMETER_134_AND_135_t* values) const {
    return spark_build_READ_PARAMETER_134_AND_135(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_136_AND_137(const Spark_READ_PARAMETER_136_AND_137_t* values) const {
    return spark_build_READ_PARAMETER_136_AND_137(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_138_AND_139(const Spark_READ_PARAMETER_138_AND_139_t* values) const {
    return spark_build_READ_PARAMETER_138_AND_139(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_140_AND_141(const Spark_READ_PARAMETER_140_AND_141_t* values) const {
    return spark_build_READ_PARAMETER_140_AND_141(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_142_AND_143(const Spark_READ_PARAMETER_142_AND_143_t* values) const {
    return spark_build_READ_PARAMETER_142_AND_143(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_144_AND_145(const Spark_READ_PARAMETER_144_AND_145_t* values) const {
    return spark_build_READ_PARAMETER_144_AND_145(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_146_AND_147(const Spark_READ_PARAMETER_146_AND_147_t* values) const {
    return spark_build_READ_PARAMETER_146_AND_147(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_148_AND_149(const Spark_READ_PARAMETER_148_AND_149_t* values) const {
    return spark_build_READ_PARAMETER_148_AND_149(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_150_AND_151(const Spark_READ_PARAMETER_150_AND_151_t* values) const {
    return spark_build_READ_PARAMETER_150_AND_151(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_152_AND_153(const Spark_READ_PARAMETER_152_AND_153_t* values) const {
    return spark_build_READ_PARAMETER_152_AND_153(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_154_AND_155(const Spark_READ_PARAMETER_154_AND_155_t* values) const {
    return spark_build_READ_PARAMETER_154_AND_155(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_156_AND_157(const Spark_READ_PARAMETER_156_AND_157_t* values) const {
    return spark_build_READ_PARAMETER_156_AND_157(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_158_AND_159(const Spark_READ_PARAMETER_158_AND_159_t* values) const {
    return spark_build_READ_PARAMETER_158_AND_159(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_160_AND_161(const Spark_READ_PARAMETER_160_AND_161_t* values) const {
    return spark_build_READ_PARAMETER_160_AND_161(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_162_AND_163(const Spark_READ_PARAMETER_162_AND_163_t* values) const {
    return spark_build_READ_PARAMETER_162_AND_163(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_164_AND_165(const Spark_READ_PARAMETER_164_AND_165_t* values) const {
    return spark_build_READ_PARAMETER_164_AND_165(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_166_AND_167(const Spark_READ_PARAMETER_166_AND_167_t* values) const {
    return spark_build_READ_PARAMETER_166_AND_167(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_168_AND_169(const Spark_READ_PARAMETER_168_AND_169_t* values) const {
    return spark_build_READ_PARAMETER_168_AND_169(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_170_AND_171(const Spark_READ_PARAMETER_170_AND_171_t* values) const {
    return spark_build_READ_PARAMETER_170_AND_171(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_172_AND_173(const Spark_READ_PARAMETER_172_AND_173_t* values) const {
    return spark_build_READ_PARAMETER_172_AND_173(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_174_AND_175(const Spark_READ_PARAMETER_174_AND_175_t* values) const {
    return spark_build_READ_PARAMETER_174_AND_175(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_176_AND_177(const Spark_READ_PARAMETER_176_AND_177_t* values) const {
    return spark_build_READ_PARAMETER_176_AND_177(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_178_AND_179(const Spark_READ_PARAMETER_178_AND_179_t* values) const {
    return spark_build_READ_PARAMETER_178_AND_179(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_180_AND_181(const Spark_READ_PARAMETER_180_AND_181_t* values) const {
    return spark_build_READ_PARAMETER_180_AND_181(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_182_AND_183(const Spark_READ_PARAMETER_182_AND_183_t* values) const {
    return spark_build_READ_PARAMETER_182_AND_183(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_184_AND_185(const Spark_READ_PARAMETER_184_AND_185_t* values) const {
    return spark_build_READ_PARAMETER_184_AND_185(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_186_AND_187(const Spark_READ_PARAMETER_186_AND_187_t* values) const {
    return spark_build_READ_PARAMETER_186_AND_187(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_188_AND_189(const Spark_READ_PARAMETER_188_AND_189_t* values) const {
    return spark_build_READ_PARAMETER_188_AND_189(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_190_AND_191(const Spark_READ_PARAMETER_190_AND_191_t* values) const {
    return spark_build_READ_PARAMETER_190_AND_191(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_192_AND_193(const Spark_READ_PARAMETER_192_AND_193_t* values) const {
    return spark_build_READ_PARAMETER_192_AND_193(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_194_AND_195(const Spark_READ_PARAMETER_194_AND_195_t* values) const {
    return spark_build_READ_PARAMETER_194_AND_195(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_196_AND_197(const Spark_READ_PARAMETER_196_AND_197_t* values) const {
    return spark_build_READ_PARAMETER_196_AND_197(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_198_AND_199(const Spark_READ_PARAMETER_198_AND_199_t* values) const {
    return spark_build_READ_PARAMETER_198_AND_199(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_200_AND_201(const Spark_READ_PARAMETER_200_AND_201_t* values) const {
    return spark_build_READ_PARAMETER_200_AND_201(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_202_AND_203(const Spark_READ_PARAMETER_202_AND_203_t* values) const {
    return spark_build_READ_PARAMETER_202_AND_203(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_204_AND_205(const Spark_READ_PARAMETER_204_AND_205_t* values) const {
    return spark_build_READ_PARAMETER_204_AND_205(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_206_AND_207(const Spark_READ_PARAMETER_206_AND_207_t* values) const {
    return spark_build_READ_PARAMETER_206_AND_207(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_208_AND_209(const Spark_READ_PARAMETER_208_AND_209_t* values) const {
    return spark_build_READ_PARAMETER_208_AND_209(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_210_AND_211(const Spark_READ_PARAMETER_210_AND_211_t* values) const {
    return spark_build_READ_PARAMETER_210_AND_211(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_212_AND_213(const Spark_READ_PARAMETER_212_AND_213_t* values) const {
    return spark_build_READ_PARAMETER_212_AND_213(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_214_AND_215(const Spark_READ_PARAMETER_214_AND_215_t* values) const {
    return spark_build_READ_PARAMETER_214_AND_215(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_216_AND_217(const Spark_READ_PARAMETER_216_AND_217_t* values) const {
    return spark_build_READ_PARAMETER_216_AND_217(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_218_AND_219(const Spark_READ_PARAMETER_218_AND_219_t* values) const {
    return spark_build_READ_PARAMETER_218_AND_219(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_220_AND_221(const Spark_READ_PARAMETER_220_AND_221_t* values) const {
    return spark_build_READ_PARAMETER_220_AND_221(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_222_AND_223(const Spark_READ_PARAMETER_222_AND_223_t* values) const {
    return spark_build_READ_PARAMETER_222_AND_223(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_224_AND_225(const Spark_READ_PARAMETER_224_AND_225_t* values) const {
    return spark_build_READ_PARAMETER_224_AND_225(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_226_AND_227(const Spark_READ_PARAMETER_226_AND_227_t* values) const {
    return spark_build_READ_PARAMETER_226_AND_227(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_228_AND_229(const Spark_READ_PARAMETER_228_AND_229_t* values) const {
    return spark_build_READ_PARAMETER_228_AND_229(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_230_AND_231(const Spark_READ_PARAMETER_230_AND_231_t* values) const {
    return spark_build_READ_PARAMETER_230_AND_231(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_232_AND_233(const Spark_READ_PARAMETER_232_AND_233_t* values) const {
    return spark_build_READ_PARAMETER_232_AND_233(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_234_AND_235(const Spark_READ_PARAMETER_234_AND_235_t* values) const {
    return spark_build_READ_PARAMETER_234_AND_235(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_236_AND_237(const Spark_READ_PARAMETER_236_AND_237_t* values) const {
    return spark_build_READ_PARAMETER_236_AND_237(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_238_AND_239(const Spark_READ_PARAMETER_238_AND_239_t* values) const {
    return spark_build_READ_PARAMETER_238_AND_239(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_240_AND_241(const Spark_READ_PARAMETER_240_AND_241_t* values) const {
    return spark_build_READ_PARAMETER_240_AND_241(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_242_AND_243(const Spark_READ_PARAMETER_242_AND_243_t* values) const {
    return spark_build_READ_PARAMETER_242_AND_243(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_244_AND_245(const Spark_READ_PARAMETER_244_AND_245_t* values) const {
    return spark_build_READ_PARAMETER_244_AND_245(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_246_AND_247(const Spark_READ_PARAMETER_246_AND_247_t* values) const {
    return spark_build_READ_PARAMETER_246_AND_247(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_248_AND_249(const Spark_READ_PARAMETER_248_AND_249_t* values) const {
    return spark_build_READ_PARAMETER_248_AND_249(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_250_AND_251(const Spark_READ_PARAMETER_250_AND_251_t* values) const {
    return spark_build_READ_PARAMETER_250_AND_251(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_252_AND_253(const Spark_READ_PARAMETER_252_AND_253_t* values) const {
    return spark_build_READ_PARAMETER_252_AND_253(device_id_, values);
}

spark_can_frame SparkCanDevice::build_READ_PARAMETER_254_AND_255(const Spark_READ_PARAMETER_254_AND_255_t* values) const {
    return spark_build_READ_PARAMETER_254_AND_255(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_0_AND_1(const Spark_WRITE_PARAMETER_0_AND_1_t* values) const {
    return spark_build_WRITE_PARAMETER_0_AND_1(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_2_AND_3(const Spark_WRITE_PARAMETER_2_AND_3_t* values) const {
    return spark_build_WRITE_PARAMETER_2_AND_3(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_4_AND_5(const Spark_WRITE_PARAMETER_4_AND_5_t* values) const {
    return spark_build_WRITE_PARAMETER_4_AND_5(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_6_AND_7(const Spark_WRITE_PARAMETER_6_AND_7_t* values) const {
    return spark_build_WRITE_PARAMETER_6_AND_7(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_8_AND_9(const Spark_WRITE_PARAMETER_8_AND_9_t* values) const {
    return spark_build_WRITE_PARAMETER_8_AND_9(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_10_AND_11(const Spark_WRITE_PARAMETER_10_AND_11_t* values) const {
    return spark_build_WRITE_PARAMETER_10_AND_11(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_12_AND_13(const Spark_WRITE_PARAMETER_12_AND_13_t* values) const {
    return spark_build_WRITE_PARAMETER_12_AND_13(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_14_AND_15(const Spark_WRITE_PARAMETER_14_AND_15_t* values) const {
    return spark_build_WRITE_PARAMETER_14_AND_15(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_16_AND_17(const Spark_WRITE_PARAMETER_16_AND_17_t* values) const {
    return spark_build_WRITE_PARAMETER_16_AND_17(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_18_AND_19(const Spark_WRITE_PARAMETER_18_AND_19_t* values) const {
    return spark_build_WRITE_PARAMETER_18_AND_19(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_20_AND_21(const Spark_WRITE_PARAMETER_20_AND_21_t* values) const {
    return spark_build_WRITE_PARAMETER_20_AND_21(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_22_AND_23(const Spark_WRITE_PARAMETER_22_AND_23_t* values) const {
    return spark_build_WRITE_PARAMETER_22_AND_23(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_24_AND_25(const Spark_WRITE_PARAMETER_24_AND_25_t* values) const {
    return spark_build_WRITE_PARAMETER_24_AND_25(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_26_AND_27(const Spark_WRITE_PARAMETER_26_AND_27_t* values) const {
    return spark_build_WRITE_PARAMETER_26_AND_27(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_28_AND_29(const Spark_WRITE_PARAMETER_28_AND_29_t* values) const {
    return spark_build_WRITE_PARAMETER_28_AND_29(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_30_AND_31(const Spark_WRITE_PARAMETER_30_AND_31_t* values) const {
    return spark_build_WRITE_PARAMETER_30_AND_31(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_32_AND_33(const Spark_WRITE_PARAMETER_32_AND_33_t* values) const {
    return spark_build_WRITE_PARAMETER_32_AND_33(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_34_AND_35(const Spark_WRITE_PARAMETER_34_AND_35_t* values) const {
    return spark_build_WRITE_PARAMETER_34_AND_35(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_36_AND_37(const Spark_WRITE_PARAMETER_36_AND_37_t* values) const {
    return spark_build_WRITE_PARAMETER_36_AND_37(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_38_AND_39(const Spark_WRITE_PARAMETER_38_AND_39_t* values) const {
    return spark_build_WRITE_PARAMETER_38_AND_39(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_40_AND_41(const Spark_WRITE_PARAMETER_40_AND_41_t* values) const {
    return spark_build_WRITE_PARAMETER_40_AND_41(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_42_AND_43(const Spark_WRITE_PARAMETER_42_AND_43_t* values) const {
    return spark_build_WRITE_PARAMETER_42_AND_43(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_44_AND_45(const Spark_WRITE_PARAMETER_44_AND_45_t* values) const {
    return spark_build_WRITE_PARAMETER_44_AND_45(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_46_AND_47(const Spark_WRITE_PARAMETER_46_AND_47_t* values) const {
    return spark_build_WRITE_PARAMETER_46_AND_47(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_48_AND_49(const Spark_WRITE_PARAMETER_48_AND_49_t* values) const {
    return spark_build_WRITE_PARAMETER_48_AND_49(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_50_AND_51(const Spark_WRITE_PARAMETER_50_AND_51_t* values) const {
    return spark_build_WRITE_PARAMETER_50_AND_51(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_52_AND_53(const Spark_WRITE_PARAMETER_52_AND_53_t* values) const {
    return spark_build_WRITE_PARAMETER_52_AND_53(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_54_AND_55(const Spark_WRITE_PARAMETER_54_AND_55_t* values) const {
    return spark_build_WRITE_PARAMETER_54_AND_55(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_56_AND_57(const Spark_WRITE_PARAMETER_56_AND_57_t* values) const {
    return spark_build_WRITE_PARAMETER_56_AND_57(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_58_AND_59(const Spark_WRITE_PARAMETER_58_AND_59_t* values) const {
    return spark_build_WRITE_PARAMETER_58_AND_59(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_60_AND_61(const Spark_WRITE_PARAMETER_60_AND_61_t* values) const {
    return spark_build_WRITE_PARAMETER_60_AND_61(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_62_AND_63(const Spark_WRITE_PARAMETER_62_AND_63_t* values) const {
    return spark_build_WRITE_PARAMETER_62_AND_63(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_64_AND_65(const Spark_WRITE_PARAMETER_64_AND_65_t* values) const {
    return spark_build_WRITE_PARAMETER_64_AND_65(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_66_AND_67(const Spark_WRITE_PARAMETER_66_AND_67_t* values) const {
    return spark_build_WRITE_PARAMETER_66_AND_67(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_68_AND_69(const Spark_WRITE_PARAMETER_68_AND_69_t* values) const {
    return spark_build_WRITE_PARAMETER_68_AND_69(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_70_AND_71(const Spark_WRITE_PARAMETER_70_AND_71_t* values) const {
    return spark_build_WRITE_PARAMETER_70_AND_71(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_72_AND_73(const Spark_WRITE_PARAMETER_72_AND_73_t* values) const {
    return spark_build_WRITE_PARAMETER_72_AND_73(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_74_AND_75(const Spark_WRITE_PARAMETER_74_AND_75_t* values) const {
    return spark_build_WRITE_PARAMETER_74_AND_75(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_76_AND_77(const Spark_WRITE_PARAMETER_76_AND_77_t* values) const {
    return spark_build_WRITE_PARAMETER_76_AND_77(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_78_AND_79(const Spark_WRITE_PARAMETER_78_AND_79_t* values) const {
    return spark_build_WRITE_PARAMETER_78_AND_79(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_80_AND_81(const Spark_WRITE_PARAMETER_80_AND_81_t* values) const {
    return spark_build_WRITE_PARAMETER_80_AND_81(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_82_AND_83(const Spark_WRITE_PARAMETER_82_AND_83_t* values) const {
    return spark_build_WRITE_PARAMETER_82_AND_83(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_84_AND_85(const Spark_WRITE_PARAMETER_84_AND_85_t* values) const {
    return spark_build_WRITE_PARAMETER_84_AND_85(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_86_AND_87(const Spark_WRITE_PARAMETER_86_AND_87_t* values) const {
    return spark_build_WRITE_PARAMETER_86_AND_87(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_88_AND_89(const Spark_WRITE_PARAMETER_88_AND_89_t* values) const {
    return spark_build_WRITE_PARAMETER_88_AND_89(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_90_AND_91(const Spark_WRITE_PARAMETER_90_AND_91_t* values) const {
    return spark_build_WRITE_PARAMETER_90_AND_91(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_92_AND_93(const Spark_WRITE_PARAMETER_92_AND_93_t* values) const {
    return spark_build_WRITE_PARAMETER_92_AND_93(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_94_AND_95(const Spark_WRITE_PARAMETER_94_AND_95_t* values) const {
    return spark_build_WRITE_PARAMETER_94_AND_95(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_96_AND_97(const Spark_WRITE_PARAMETER_96_AND_97_t* values) const {
    return spark_build_WRITE_PARAMETER_96_AND_97(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_98_AND_99(const Spark_WRITE_PARAMETER_98_AND_99_t* values) const {
    return spark_build_WRITE_PARAMETER_98_AND_99(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_100_AND_101(const Spark_WRITE_PARAMETER_100_AND_101_t* values) const {
    return spark_build_WRITE_PARAMETER_100_AND_101(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_102_AND_103(const Spark_WRITE_PARAMETER_102_AND_103_t* values) const {
    return spark_build_WRITE_PARAMETER_102_AND_103(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_104_AND_105(const Spark_WRITE_PARAMETER_104_AND_105_t* values) const {
    return spark_build_WRITE_PARAMETER_104_AND_105(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_106_AND_107(const Spark_WRITE_PARAMETER_106_AND_107_t* values) const {
    return spark_build_WRITE_PARAMETER_106_AND_107(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_108_AND_109(const Spark_WRITE_PARAMETER_108_AND_109_t* values) const {
    return spark_build_WRITE_PARAMETER_108_AND_109(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_110_AND_111(const Spark_WRITE_PARAMETER_110_AND_111_t* values) const {
    return spark_build_WRITE_PARAMETER_110_AND_111(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_112_AND_113(const Spark_WRITE_PARAMETER_112_AND_113_t* values) const {
    return spark_build_WRITE_PARAMETER_112_AND_113(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_114_AND_115(const Spark_WRITE_PARAMETER_114_AND_115_t* values) const {
    return spark_build_WRITE_PARAMETER_114_AND_115(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_116_AND_117(const Spark_WRITE_PARAMETER_116_AND_117_t* values) const {
    return spark_build_WRITE_PARAMETER_116_AND_117(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_118_AND_119(const Spark_WRITE_PARAMETER_118_AND_119_t* values) const {
    return spark_build_WRITE_PARAMETER_118_AND_119(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_120_AND_121(const Spark_WRITE_PARAMETER_120_AND_121_t* values) const {
    return spark_build_WRITE_PARAMETER_120_AND_121(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_122_AND_123(const Spark_WRITE_PARAMETER_122_AND_123_t* values) const {
    return spark_build_WRITE_PARAMETER_122_AND_123(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_124_AND_125(const Spark_WRITE_PARAMETER_124_AND_125_t* values) const {
    return spark_build_WRITE_PARAMETER_124_AND_125(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_126_AND_127(const Spark_WRITE_PARAMETER_126_AND_127_t* values) const {
    return spark_build_WRITE_PARAMETER_126_AND_127(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_128_AND_129(const Spark_WRITE_PARAMETER_128_AND_129_t* values) const {
    return spark_build_WRITE_PARAMETER_128_AND_129(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_130_AND_131(const Spark_WRITE_PARAMETER_130_AND_131_t* values) const {
    return spark_build_WRITE_PARAMETER_130_AND_131(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_132_AND_133(const Spark_WRITE_PARAMETER_132_AND_133_t* values) const {
    return spark_build_WRITE_PARAMETER_132_AND_133(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_134_AND_135(const Spark_WRITE_PARAMETER_134_AND_135_t* values) const {
    return spark_build_WRITE_PARAMETER_134_AND_135(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_136_AND_137(const Spark_WRITE_PARAMETER_136_AND_137_t* values) const {
    return spark_build_WRITE_PARAMETER_136_AND_137(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_138_AND_139(const Spark_WRITE_PARAMETER_138_AND_139_t* values) const {
    return spark_build_WRITE_PARAMETER_138_AND_139(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_140_AND_141(const Spark_WRITE_PARAMETER_140_AND_141_t* values) const {
    return spark_build_WRITE_PARAMETER_140_AND_141(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_142_AND_143(const Spark_WRITE_PARAMETER_142_AND_143_t* values) const {
    return spark_build_WRITE_PARAMETER_142_AND_143(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_144_AND_145(const Spark_WRITE_PARAMETER_144_AND_145_t* values) const {
    return spark_build_WRITE_PARAMETER_144_AND_145(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_146_AND_147(const Spark_WRITE_PARAMETER_146_AND_147_t* values) const {
    return spark_build_WRITE_PARAMETER_146_AND_147(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_148_AND_149(const Spark_WRITE_PARAMETER_148_AND_149_t* values) const {
    return spark_build_WRITE_PARAMETER_148_AND_149(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_150_AND_151(const Spark_WRITE_PARAMETER_150_AND_151_t* values) const {
    return spark_build_WRITE_PARAMETER_150_AND_151(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_152_AND_153(const Spark_WRITE_PARAMETER_152_AND_153_t* values) const {
    return spark_build_WRITE_PARAMETER_152_AND_153(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_154_AND_155(const Spark_WRITE_PARAMETER_154_AND_155_t* values) const {
    return spark_build_WRITE_PARAMETER_154_AND_155(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_156_AND_157(const Spark_WRITE_PARAMETER_156_AND_157_t* values) const {
    return spark_build_WRITE_PARAMETER_156_AND_157(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_158_AND_159(const Spark_WRITE_PARAMETER_158_AND_159_t* values) const {
    return spark_build_WRITE_PARAMETER_158_AND_159(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_160_AND_161(const Spark_WRITE_PARAMETER_160_AND_161_t* values) const {
    return spark_build_WRITE_PARAMETER_160_AND_161(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_162_AND_163(const Spark_WRITE_PARAMETER_162_AND_163_t* values) const {
    return spark_build_WRITE_PARAMETER_162_AND_163(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_164_AND_165(const Spark_WRITE_PARAMETER_164_AND_165_t* values) const {
    return spark_build_WRITE_PARAMETER_164_AND_165(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_166_AND_167(const Spark_WRITE_PARAMETER_166_AND_167_t* values) const {
    return spark_build_WRITE_PARAMETER_166_AND_167(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_168_AND_169(const Spark_WRITE_PARAMETER_168_AND_169_t* values) const {
    return spark_build_WRITE_PARAMETER_168_AND_169(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_170_AND_171(const Spark_WRITE_PARAMETER_170_AND_171_t* values) const {
    return spark_build_WRITE_PARAMETER_170_AND_171(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_172_AND_173(const Spark_WRITE_PARAMETER_172_AND_173_t* values) const {
    return spark_build_WRITE_PARAMETER_172_AND_173(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_174_AND_175(const Spark_WRITE_PARAMETER_174_AND_175_t* values) const {
    return spark_build_WRITE_PARAMETER_174_AND_175(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_176_AND_177(const Spark_WRITE_PARAMETER_176_AND_177_t* values) const {
    return spark_build_WRITE_PARAMETER_176_AND_177(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_178_AND_179(const Spark_WRITE_PARAMETER_178_AND_179_t* values) const {
    return spark_build_WRITE_PARAMETER_178_AND_179(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_180_AND_181(const Spark_WRITE_PARAMETER_180_AND_181_t* values) const {
    return spark_build_WRITE_PARAMETER_180_AND_181(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_182_AND_183(const Spark_WRITE_PARAMETER_182_AND_183_t* values) const {
    return spark_build_WRITE_PARAMETER_182_AND_183(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_184_AND_185(const Spark_WRITE_PARAMETER_184_AND_185_t* values) const {
    return spark_build_WRITE_PARAMETER_184_AND_185(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_186_AND_187(const Spark_WRITE_PARAMETER_186_AND_187_t* values) const {
    return spark_build_WRITE_PARAMETER_186_AND_187(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_188_AND_189(const Spark_WRITE_PARAMETER_188_AND_189_t* values) const {
    return spark_build_WRITE_PARAMETER_188_AND_189(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_190_AND_191(const Spark_WRITE_PARAMETER_190_AND_191_t* values) const {
    return spark_build_WRITE_PARAMETER_190_AND_191(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_192_AND_193(const Spark_WRITE_PARAMETER_192_AND_193_t* values) const {
    return spark_build_WRITE_PARAMETER_192_AND_193(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_194_AND_195(const Spark_WRITE_PARAMETER_194_AND_195_t* values) const {
    return spark_build_WRITE_PARAMETER_194_AND_195(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_196_AND_197(const Spark_WRITE_PARAMETER_196_AND_197_t* values) const {
    return spark_build_WRITE_PARAMETER_196_AND_197(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_198_AND_199(const Spark_WRITE_PARAMETER_198_AND_199_t* values) const {
    return spark_build_WRITE_PARAMETER_198_AND_199(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_200_AND_201(const Spark_WRITE_PARAMETER_200_AND_201_t* values) const {
    return spark_build_WRITE_PARAMETER_200_AND_201(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_202_AND_203(const Spark_WRITE_PARAMETER_202_AND_203_t* values) const {
    return spark_build_WRITE_PARAMETER_202_AND_203(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_204_AND_205(const Spark_WRITE_PARAMETER_204_AND_205_t* values) const {
    return spark_build_WRITE_PARAMETER_204_AND_205(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_206_AND_207(const Spark_WRITE_PARAMETER_206_AND_207_t* values) const {
    return spark_build_WRITE_PARAMETER_206_AND_207(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_208_AND_209(const Spark_WRITE_PARAMETER_208_AND_209_t* values) const {
    return spark_build_WRITE_PARAMETER_208_AND_209(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_210_AND_211(const Spark_WRITE_PARAMETER_210_AND_211_t* values) const {
    return spark_build_WRITE_PARAMETER_210_AND_211(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_212_AND_213(const Spark_WRITE_PARAMETER_212_AND_213_t* values) const {
    return spark_build_WRITE_PARAMETER_212_AND_213(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_214_AND_215(const Spark_WRITE_PARAMETER_214_AND_215_t* values) const {
    return spark_build_WRITE_PARAMETER_214_AND_215(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_216_AND_217(const Spark_WRITE_PARAMETER_216_AND_217_t* values) const {
    return spark_build_WRITE_PARAMETER_216_AND_217(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_218_AND_219(const Spark_WRITE_PARAMETER_218_AND_219_t* values) const {
    return spark_build_WRITE_PARAMETER_218_AND_219(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_220_AND_221(const Spark_WRITE_PARAMETER_220_AND_221_t* values) const {
    return spark_build_WRITE_PARAMETER_220_AND_221(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_222_AND_223(const Spark_WRITE_PARAMETER_222_AND_223_t* values) const {
    return spark_build_WRITE_PARAMETER_222_AND_223(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_224_AND_225(const Spark_WRITE_PARAMETER_224_AND_225_t* values) const {
    return spark_build_WRITE_PARAMETER_224_AND_225(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_226_AND_227(const Spark_WRITE_PARAMETER_226_AND_227_t* values) const {
    return spark_build_WRITE_PARAMETER_226_AND_227(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_228_AND_229(const Spark_WRITE_PARAMETER_228_AND_229_t* values) const {
    return spark_build_WRITE_PARAMETER_228_AND_229(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_230_AND_231(const Spark_WRITE_PARAMETER_230_AND_231_t* values) const {
    return spark_build_WRITE_PARAMETER_230_AND_231(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_232_AND_233(const Spark_WRITE_PARAMETER_232_AND_233_t* values) const {
    return spark_build_WRITE_PARAMETER_232_AND_233(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_234_AND_235(const Spark_WRITE_PARAMETER_234_AND_235_t* values) const {
    return spark_build_WRITE_PARAMETER_234_AND_235(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_236_AND_237(const Spark_WRITE_PARAMETER_236_AND_237_t* values) const {
    return spark_build_WRITE_PARAMETER_236_AND_237(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_238_AND_239(const Spark_WRITE_PARAMETER_238_AND_239_t* values) const {
    return spark_build_WRITE_PARAMETER_238_AND_239(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_240_AND_241(const Spark_WRITE_PARAMETER_240_AND_241_t* values) const {
    return spark_build_WRITE_PARAMETER_240_AND_241(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_242_AND_243(const Spark_WRITE_PARAMETER_242_AND_243_t* values) const {
    return spark_build_WRITE_PARAMETER_242_AND_243(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_244_AND_245(const Spark_WRITE_PARAMETER_244_AND_245_t* values) const {
    return spark_build_WRITE_PARAMETER_244_AND_245(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_246_AND_247(const Spark_WRITE_PARAMETER_246_AND_247_t* values) const {
    return spark_build_WRITE_PARAMETER_246_AND_247(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_248_AND_249(const Spark_WRITE_PARAMETER_248_AND_249_t* values) const {
    return spark_build_WRITE_PARAMETER_248_AND_249(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_250_AND_251(const Spark_WRITE_PARAMETER_250_AND_251_t* values) const {
    return spark_build_WRITE_PARAMETER_250_AND_251(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_252_AND_253(const Spark_WRITE_PARAMETER_252_AND_253_t* values) const {
    return spark_build_WRITE_PARAMETER_252_AND_253(device_id_, values);
}

spark_can_frame SparkCanDevice::build_WRITE_PARAMETER_254_AND_255(const Spark_WRITE_PARAMETER_254_AND_255_t* values) const {
    return spark_build_WRITE_PARAMETER_254_AND_255(device_id_, values);
}

spark_can_frame SparkCanDevice::build_START_FOLLOWER_MODE(const Spark_START_FOLLOWER_MODE_t* values) const {
    return spark_build_START_FOLLOWER_MODE(device_id_, values);
}

spark_can_frame SparkCanDevice::build_START_FOLLOWER_MODE_RESPONSE(const Spark_START_FOLLOWER_MODE_RESPONSE_t* values) const {
    return spark_build_START_FOLLOWER_MODE_RESPONSE(device_id_, values);
}

spark_can_frame SparkCanDevice::build_STOP_FOLLOWER_MODE(const Spark_STOP_FOLLOWER_MODE_t* values) const {
    return spark_build_STOP_FOLLOWER_MODE(device_id_, values);
}

spark_can_frame SparkCanDevice::build_STOP_FOLLOWER_MODE_RESPONSE(const Spark_STOP_FOLLOWER_MODE_RESPONSE_t* values) const {
    return spark_build_STOP_FOLLOWER_MODE_RESPONSE(device_id_, values);
}

spark_can_frame SparkCanDevice::build_ENTER_SWDL_CAN_BOOTLOADER(const Spark_ENTER_SWDL_CAN_BOOTLOADER_t* values) const {
    return spark_build_ENTER_SWDL_CAN_BOOTLOADER(device_id_, values);
}

spark_can_frame SparkCanDevice::build_PERSIST_PARAMETERS(const Spark_PERSIST_PARAMETERS_t* values) const {
    return spark_build_PERSIST_PARAMETERS(device_id_, values);
}

MCP2515::ERROR SparkCanDevice::send_velocity_setpoint(const Spark_VELOCITY_SETPOINT_t* values) const {
    return dispatch_frame(spark_build_VELOCITY_SETPOINT(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_duty_cycle_setpoint(const Spark_DUTY_CYCLE_SETPOINT_t* values) const {
    return dispatch_frame(spark_build_DUTY_CYCLE_SETPOINT(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_smart_velocity_setpoint(const Spark_SMART_VELOCITY_SETPOINT_t* values) const {
    return dispatch_frame(spark_build_SMART_VELOCITY_SETPOINT(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_position_setpoint(const Spark_POSITION_SETPOINT_t* values) const {
    return dispatch_frame(spark_build_POSITION_SETPOINT(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_voltage_setpoint(const Spark_VOLTAGE_SETPOINT_t* values) const {
    return dispatch_frame(spark_build_VOLTAGE_SETPOINT(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_current_setpoint(const Spark_CURRENT_SETPOINT_t* values) const {
    return dispatch_frame(spark_build_CURRENT_SETPOINT(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_smart_motion_setpoint(const Spark_SMART_MOTION_SETPOINT_t* values) const {
    return dispatch_frame(spark_build_SMART_MOTION_SETPOINT(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_maxmotion_position_setpoint(const Spark_MAXMOTION_POSITION_SETPOINT_t* values) const {
    return dispatch_frame(spark_build_MAXMOTION_POSITION_SETPOINT(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_maxmotion_velocity_setpoint(const Spark_MAXMOTION_VELOCITY_SETPOINT_t* values) const {
    return dispatch_frame(spark_build_MAXMOTION_VELOCITY_SETPOINT(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_set_statuses_enabled(const Spark_SET_STATUSES_ENABLED_t* values) const {
    return dispatch_frame(spark_build_SET_STATUSES_ENABLED(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_set_statuses_enabled_response(const Spark_SET_STATUSES_ENABLED_RESPONSE_t* values) const {
    return dispatch_frame(spark_build_SET_STATUSES_ENABLED_RESPONSE(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_persist_parameters_response(const Spark_PERSIST_PARAMETERS_RESPONSE_t* values) const {
    return dispatch_frame(spark_build_PERSIST_PARAMETERS_RESPONSE(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_reset_safe_parameters(const Spark_RESET_SAFE_PARAMETERS_t* values) const {
    return dispatch_frame(spark_build_RESET_SAFE_PARAMETERS(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_reset_safe_parameters_response(const Spark_RESET_SAFE_PARAMETERS_RESPONSE_t* values) const {
    return dispatch_frame(spark_build_RESET_SAFE_PARAMETERS_RESPONSE(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_complete_factory_reset(const Spark_COMPLETE_FACTORY_RESET_t* values) const {
    return dispatch_frame(spark_build_COMPLETE_FACTORY_RESET(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_complete_factory_reset_response(const Spark_COMPLETE_FACTORY_RESET_RESPONSE_t* values) const {
    return dispatch_frame(spark_build_COMPLETE_FACTORY_RESET_RESPONSE(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_clear_faults(const Spark_CLEAR_FAULTS_t* values) const {
    return dispatch_frame(spark_build_CLEAR_FAULTS(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_identify_unique_spark(const Spark_IDENTIFY_UNIQUE_SPARK_t* values) const {
    return dispatch_frame(spark_build_IDENTIFY_UNIQUE_SPARK(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_identify(const Spark_IDENTIFY_t* values) const {
    return dispatch_frame(spark_build_IDENTIFY(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_nack(const Spark_NACK_t* values) const {
    return dispatch_frame(spark_build_NACK(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_ack(const Spark_ACK_t* values) const {
    return dispatch_frame(spark_build_ACK(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_led_sync(const Spark_LED_SYNC_t* values) const {
    return dispatch_frame(spark_build_LED_SYNC(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_set_can_id(const Spark_SET_CAN_ID_t* values) const {
    return dispatch_frame(spark_build_SET_CAN_ID(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_get_firmware_version(const Spark_GET_FIRMWARE_VERSION_t* values) const {
    return dispatch_frame(spark_build_GET_FIRMWARE_VERSION(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_swdl_data(const Spark_SWDL_DATA_t* values) const {
    return dispatch_frame(spark_build_SWDL_DATA(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_swdl_checksum(const Spark_SWDL_CHECKSUM_t* values) const {
    return dispatch_frame(spark_build_SWDL_CHECKSUM(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_swdl_retransmit(const Spark_SWDL_RETRANSMIT_t* values) const {
    return dispatch_frame(spark_build_SWDL_RETRANSMIT(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_set_primary_encoder_position(const Spark_SET_PRIMARY_ENCODER_POSITION_t* values) const {
    return dispatch_frame(spark_build_SET_PRIMARY_ENCODER_POSITION(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_set_i_accumulation(const Spark_SET_I_ACCUMULATION_t* values) const {
    return dispatch_frame(spark_build_SET_I_ACCUMULATION(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_set_analog_position(const Spark_SET_ANALOG_POSITION_t* values) const {
    return dispatch_frame(spark_build_SET_ANALOG_POSITION(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_set_ext_or_alt_encoder_position(const Spark_SET_EXT_OR_ALT_ENCODER_POSITION_t* values) const {
    return dispatch_frame(spark_build_SET_EXT_OR_ALT_ENCODER_POSITION(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_set_duty_cycle_position(const Spark_SET_DUTY_CYCLE_POSITION_t* values) const {
    return dispatch_frame(spark_build_SET_DUTY_CYCLE_POSITION(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_secondary_heartbeat(const Spark_SECONDARY_HEARTBEAT_t* values) const {
    return dispatch_frame(spark_build_SECONDARY_HEARTBEAT(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_usb_only_identify(const Spark_USB_ONLY_IDENTIFY_t* values) const {
    return dispatch_frame(spark_build_USB_ONLY_IDENTIFY(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_usb_only_enter_dfu_bootloader(const Spark_USB_ONLY_ENTER_DFU_BOOTLOADER_t* values) const {
    return dispatch_frame(spark_build_USB_ONLY_ENTER_DFU_BOOTLOADER(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_get_temperatures(const Spark_GET_TEMPERATURES_t* values) const {
    return dispatch_frame(spark_build_GET_TEMPERATURES(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_get_motor_interface(const Spark_GET_MOTOR_INTERFACE_t* values) const {
    return dispatch_frame(spark_build_GET_MOTOR_INTERFACE(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_get_parameter_0_to_15_types(const Spark_GET_PARAMETER_0_TO_15_TYPES_t* values) const {
    return dispatch_frame(spark_build_GET_PARAMETER_0_TO_15_TYPES(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_get_parameter_16_to_31_types(const Spark_GET_PARAMETER_16_TO_31_TYPES_t* values) const {
    return dispatch_frame(spark_build_GET_PARAMETER_16_TO_31_TYPES(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_get_parameter_32_to_47_types(const Spark_GET_PARAMETER_32_TO_47_TYPES_t* values) const {
    return dispatch_frame(spark_build_GET_PARAMETER_32_TO_47_TYPES(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_get_parameter_48_to_63_types(const Spark_GET_PARAMETER_48_TO_63_TYPES_t* values) const {
    return dispatch_frame(spark_build_GET_PARAMETER_48_TO_63_TYPES(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_get_parameter_64_to_79_types(const Spark_GET_PARAMETER_64_TO_79_TYPES_t* values) const {
    return dispatch_frame(spark_build_GET_PARAMETER_64_TO_79_TYPES(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_get_parameter_80_to_95_types(const Spark_GET_PARAMETER_80_TO_95_TYPES_t* values) const {
    return dispatch_frame(spark_build_GET_PARAMETER_80_TO_95_TYPES(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_get_parameter_96_to_111_types(const Spark_GET_PARAMETER_96_TO_111_TYPES_t* values) const {
    return dispatch_frame(spark_build_GET_PARAMETER_96_TO_111_TYPES(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_get_parameter_112_to_127_types(const Spark_GET_PARAMETER_112_TO_127_TYPES_t* values) const {
    return dispatch_frame(spark_build_GET_PARAMETER_112_TO_127_TYPES(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_get_parameter_128_to_143_types(const Spark_GET_PARAMETER_128_TO_143_TYPES_t* values) const {
    return dispatch_frame(spark_build_GET_PARAMETER_128_TO_143_TYPES(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_get_parameter_144_to_159_types(const Spark_GET_PARAMETER_144_TO_159_TYPES_t* values) const {
    return dispatch_frame(spark_build_GET_PARAMETER_144_TO_159_TYPES(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_get_parameter_160_to_175_types(const Spark_GET_PARAMETER_160_TO_175_TYPES_t* values) const {
    return dispatch_frame(spark_build_GET_PARAMETER_160_TO_175_TYPES(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_get_parameter_176_to_191_types(const Spark_GET_PARAMETER_176_TO_191_TYPES_t* values) const {
    return dispatch_frame(spark_build_GET_PARAMETER_176_TO_191_TYPES(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_get_parameter_192_to_207_types(const Spark_GET_PARAMETER_192_TO_207_TYPES_t* values) const {
    return dispatch_frame(spark_build_GET_PARAMETER_192_TO_207_TYPES(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_get_parameter_208_to_223_types(const Spark_GET_PARAMETER_208_TO_223_TYPES_t* values) const {
    return dispatch_frame(spark_build_GET_PARAMETER_208_TO_223_TYPES(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_get_parameter_224_to_239_types(const Spark_GET_PARAMETER_224_TO_239_TYPES_t* values) const {
    return dispatch_frame(spark_build_GET_PARAMETER_224_TO_239_TYPES(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_get_parameter_240_to_255_types(const Spark_GET_PARAMETER_240_TO_255_TYPES_t* values) const {
    return dispatch_frame(spark_build_GET_PARAMETER_240_TO_255_TYPES(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_parameter_write(const Spark_PARAMETER_WRITE_t* values) const {
    return dispatch_frame(spark_build_PARAMETER_WRITE(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_parameter_write_response(const Spark_PARAMETER_WRITE_RESPONSE_t* values) const {
    return dispatch_frame(spark_build_PARAMETER_WRITE_RESPONSE(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_0_and_1(const Spark_READ_PARAMETER_0_AND_1_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_0_AND_1(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_2_and_3(const Spark_READ_PARAMETER_2_AND_3_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_2_AND_3(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_4_and_5(const Spark_READ_PARAMETER_4_AND_5_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_4_AND_5(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_6_and_7(const Spark_READ_PARAMETER_6_AND_7_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_6_AND_7(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_8_and_9(const Spark_READ_PARAMETER_8_AND_9_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_8_AND_9(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_10_and_11(const Spark_READ_PARAMETER_10_AND_11_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_10_AND_11(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_12_and_13(const Spark_READ_PARAMETER_12_AND_13_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_12_AND_13(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_14_and_15(const Spark_READ_PARAMETER_14_AND_15_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_14_AND_15(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_16_and_17(const Spark_READ_PARAMETER_16_AND_17_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_16_AND_17(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_18_and_19(const Spark_READ_PARAMETER_18_AND_19_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_18_AND_19(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_20_and_21(const Spark_READ_PARAMETER_20_AND_21_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_20_AND_21(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_22_and_23(const Spark_READ_PARAMETER_22_AND_23_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_22_AND_23(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_24_and_25(const Spark_READ_PARAMETER_24_AND_25_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_24_AND_25(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_26_and_27(const Spark_READ_PARAMETER_26_AND_27_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_26_AND_27(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_28_and_29(const Spark_READ_PARAMETER_28_AND_29_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_28_AND_29(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_30_and_31(const Spark_READ_PARAMETER_30_AND_31_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_30_AND_31(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_32_and_33(const Spark_READ_PARAMETER_32_AND_33_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_32_AND_33(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_34_and_35(const Spark_READ_PARAMETER_34_AND_35_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_34_AND_35(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_36_and_37(const Spark_READ_PARAMETER_36_AND_37_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_36_AND_37(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_38_and_39(const Spark_READ_PARAMETER_38_AND_39_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_38_AND_39(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_40_and_41(const Spark_READ_PARAMETER_40_AND_41_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_40_AND_41(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_42_and_43(const Spark_READ_PARAMETER_42_AND_43_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_42_AND_43(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_44_and_45(const Spark_READ_PARAMETER_44_AND_45_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_44_AND_45(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_46_and_47(const Spark_READ_PARAMETER_46_AND_47_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_46_AND_47(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_48_and_49(const Spark_READ_PARAMETER_48_AND_49_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_48_AND_49(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_50_and_51(const Spark_READ_PARAMETER_50_AND_51_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_50_AND_51(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_52_and_53(const Spark_READ_PARAMETER_52_AND_53_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_52_AND_53(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_54_and_55(const Spark_READ_PARAMETER_54_AND_55_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_54_AND_55(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_56_and_57(const Spark_READ_PARAMETER_56_AND_57_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_56_AND_57(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_58_and_59(const Spark_READ_PARAMETER_58_AND_59_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_58_AND_59(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_60_and_61(const Spark_READ_PARAMETER_60_AND_61_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_60_AND_61(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_62_and_63(const Spark_READ_PARAMETER_62_AND_63_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_62_AND_63(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_64_and_65(const Spark_READ_PARAMETER_64_AND_65_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_64_AND_65(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_66_and_67(const Spark_READ_PARAMETER_66_AND_67_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_66_AND_67(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_68_and_69(const Spark_READ_PARAMETER_68_AND_69_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_68_AND_69(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_70_and_71(const Spark_READ_PARAMETER_70_AND_71_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_70_AND_71(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_72_and_73(const Spark_READ_PARAMETER_72_AND_73_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_72_AND_73(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_74_and_75(const Spark_READ_PARAMETER_74_AND_75_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_74_AND_75(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_76_and_77(const Spark_READ_PARAMETER_76_AND_77_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_76_AND_77(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_78_and_79(const Spark_READ_PARAMETER_78_AND_79_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_78_AND_79(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_80_and_81(const Spark_READ_PARAMETER_80_AND_81_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_80_AND_81(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_82_and_83(const Spark_READ_PARAMETER_82_AND_83_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_82_AND_83(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_84_and_85(const Spark_READ_PARAMETER_84_AND_85_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_84_AND_85(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_86_and_87(const Spark_READ_PARAMETER_86_AND_87_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_86_AND_87(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_88_and_89(const Spark_READ_PARAMETER_88_AND_89_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_88_AND_89(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_90_and_91(const Spark_READ_PARAMETER_90_AND_91_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_90_AND_91(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_92_and_93(const Spark_READ_PARAMETER_92_AND_93_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_92_AND_93(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_94_and_95(const Spark_READ_PARAMETER_94_AND_95_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_94_AND_95(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_96_and_97(const Spark_READ_PARAMETER_96_AND_97_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_96_AND_97(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_98_and_99(const Spark_READ_PARAMETER_98_AND_99_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_98_AND_99(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_100_and_101(const Spark_READ_PARAMETER_100_AND_101_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_100_AND_101(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_102_and_103(const Spark_READ_PARAMETER_102_AND_103_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_102_AND_103(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_104_and_105(const Spark_READ_PARAMETER_104_AND_105_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_104_AND_105(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_106_and_107(const Spark_READ_PARAMETER_106_AND_107_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_106_AND_107(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_108_and_109(const Spark_READ_PARAMETER_108_AND_109_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_108_AND_109(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_110_and_111(const Spark_READ_PARAMETER_110_AND_111_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_110_AND_111(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_112_and_113(const Spark_READ_PARAMETER_112_AND_113_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_112_AND_113(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_114_and_115(const Spark_READ_PARAMETER_114_AND_115_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_114_AND_115(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_116_and_117(const Spark_READ_PARAMETER_116_AND_117_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_116_AND_117(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_118_and_119(const Spark_READ_PARAMETER_118_AND_119_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_118_AND_119(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_120_and_121(const Spark_READ_PARAMETER_120_AND_121_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_120_AND_121(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_122_and_123(const Spark_READ_PARAMETER_122_AND_123_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_122_AND_123(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_124_and_125(const Spark_READ_PARAMETER_124_AND_125_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_124_AND_125(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_126_and_127(const Spark_READ_PARAMETER_126_AND_127_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_126_AND_127(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_128_and_129(const Spark_READ_PARAMETER_128_AND_129_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_128_AND_129(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_130_and_131(const Spark_READ_PARAMETER_130_AND_131_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_130_AND_131(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_132_and_133(const Spark_READ_PARAMETER_132_AND_133_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_132_AND_133(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_134_and_135(const Spark_READ_PARAMETER_134_AND_135_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_134_AND_135(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_136_and_137(const Spark_READ_PARAMETER_136_AND_137_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_136_AND_137(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_138_and_139(const Spark_READ_PARAMETER_138_AND_139_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_138_AND_139(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_140_and_141(const Spark_READ_PARAMETER_140_AND_141_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_140_AND_141(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_142_and_143(const Spark_READ_PARAMETER_142_AND_143_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_142_AND_143(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_144_and_145(const Spark_READ_PARAMETER_144_AND_145_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_144_AND_145(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_146_and_147(const Spark_READ_PARAMETER_146_AND_147_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_146_AND_147(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_148_and_149(const Spark_READ_PARAMETER_148_AND_149_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_148_AND_149(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_150_and_151(const Spark_READ_PARAMETER_150_AND_151_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_150_AND_151(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_152_and_153(const Spark_READ_PARAMETER_152_AND_153_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_152_AND_153(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_154_and_155(const Spark_READ_PARAMETER_154_AND_155_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_154_AND_155(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_156_and_157(const Spark_READ_PARAMETER_156_AND_157_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_156_AND_157(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_158_and_159(const Spark_READ_PARAMETER_158_AND_159_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_158_AND_159(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_160_and_161(const Spark_READ_PARAMETER_160_AND_161_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_160_AND_161(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_162_and_163(const Spark_READ_PARAMETER_162_AND_163_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_162_AND_163(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_164_and_165(const Spark_READ_PARAMETER_164_AND_165_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_164_AND_165(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_166_and_167(const Spark_READ_PARAMETER_166_AND_167_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_166_AND_167(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_168_and_169(const Spark_READ_PARAMETER_168_AND_169_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_168_AND_169(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_170_and_171(const Spark_READ_PARAMETER_170_AND_171_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_170_AND_171(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_172_and_173(const Spark_READ_PARAMETER_172_AND_173_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_172_AND_173(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_174_and_175(const Spark_READ_PARAMETER_174_AND_175_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_174_AND_175(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_176_and_177(const Spark_READ_PARAMETER_176_AND_177_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_176_AND_177(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_178_and_179(const Spark_READ_PARAMETER_178_AND_179_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_178_AND_179(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_180_and_181(const Spark_READ_PARAMETER_180_AND_181_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_180_AND_181(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_182_and_183(const Spark_READ_PARAMETER_182_AND_183_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_182_AND_183(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_184_and_185(const Spark_READ_PARAMETER_184_AND_185_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_184_AND_185(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_186_and_187(const Spark_READ_PARAMETER_186_AND_187_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_186_AND_187(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_188_and_189(const Spark_READ_PARAMETER_188_AND_189_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_188_AND_189(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_190_and_191(const Spark_READ_PARAMETER_190_AND_191_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_190_AND_191(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_192_and_193(const Spark_READ_PARAMETER_192_AND_193_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_192_AND_193(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_194_and_195(const Spark_READ_PARAMETER_194_AND_195_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_194_AND_195(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_196_and_197(const Spark_READ_PARAMETER_196_AND_197_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_196_AND_197(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_198_and_199(const Spark_READ_PARAMETER_198_AND_199_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_198_AND_199(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_200_and_201(const Spark_READ_PARAMETER_200_AND_201_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_200_AND_201(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_202_and_203(const Spark_READ_PARAMETER_202_AND_203_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_202_AND_203(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_204_and_205(const Spark_READ_PARAMETER_204_AND_205_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_204_AND_205(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_206_and_207(const Spark_READ_PARAMETER_206_AND_207_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_206_AND_207(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_208_and_209(const Spark_READ_PARAMETER_208_AND_209_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_208_AND_209(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_210_and_211(const Spark_READ_PARAMETER_210_AND_211_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_210_AND_211(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_212_and_213(const Spark_READ_PARAMETER_212_AND_213_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_212_AND_213(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_214_and_215(const Spark_READ_PARAMETER_214_AND_215_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_214_AND_215(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_216_and_217(const Spark_READ_PARAMETER_216_AND_217_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_216_AND_217(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_218_and_219(const Spark_READ_PARAMETER_218_AND_219_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_218_AND_219(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_220_and_221(const Spark_READ_PARAMETER_220_AND_221_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_220_AND_221(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_222_and_223(const Spark_READ_PARAMETER_222_AND_223_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_222_AND_223(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_224_and_225(const Spark_READ_PARAMETER_224_AND_225_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_224_AND_225(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_226_and_227(const Spark_READ_PARAMETER_226_AND_227_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_226_AND_227(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_228_and_229(const Spark_READ_PARAMETER_228_AND_229_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_228_AND_229(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_230_and_231(const Spark_READ_PARAMETER_230_AND_231_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_230_AND_231(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_232_and_233(const Spark_READ_PARAMETER_232_AND_233_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_232_AND_233(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_234_and_235(const Spark_READ_PARAMETER_234_AND_235_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_234_AND_235(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_236_and_237(const Spark_READ_PARAMETER_236_AND_237_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_236_AND_237(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_238_and_239(const Spark_READ_PARAMETER_238_AND_239_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_238_AND_239(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_240_and_241(const Spark_READ_PARAMETER_240_AND_241_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_240_AND_241(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_242_and_243(const Spark_READ_PARAMETER_242_AND_243_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_242_AND_243(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_244_and_245(const Spark_READ_PARAMETER_244_AND_245_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_244_AND_245(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_246_and_247(const Spark_READ_PARAMETER_246_AND_247_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_246_AND_247(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_248_and_249(const Spark_READ_PARAMETER_248_AND_249_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_248_AND_249(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_250_and_251(const Spark_READ_PARAMETER_250_AND_251_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_250_AND_251(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_252_and_253(const Spark_READ_PARAMETER_252_AND_253_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_252_AND_253(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_read_parameter_254_and_255(const Spark_READ_PARAMETER_254_AND_255_t* values) const {
    return dispatch_frame(spark_build_READ_PARAMETER_254_AND_255(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_0_and_1(const Spark_WRITE_PARAMETER_0_AND_1_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_0_AND_1(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_2_and_3(const Spark_WRITE_PARAMETER_2_AND_3_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_2_AND_3(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_4_and_5(const Spark_WRITE_PARAMETER_4_AND_5_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_4_AND_5(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_6_and_7(const Spark_WRITE_PARAMETER_6_AND_7_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_6_AND_7(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_8_and_9(const Spark_WRITE_PARAMETER_8_AND_9_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_8_AND_9(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_10_and_11(const Spark_WRITE_PARAMETER_10_AND_11_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_10_AND_11(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_12_and_13(const Spark_WRITE_PARAMETER_12_AND_13_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_12_AND_13(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_14_and_15(const Spark_WRITE_PARAMETER_14_AND_15_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_14_AND_15(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_16_and_17(const Spark_WRITE_PARAMETER_16_AND_17_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_16_AND_17(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_18_and_19(const Spark_WRITE_PARAMETER_18_AND_19_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_18_AND_19(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_20_and_21(const Spark_WRITE_PARAMETER_20_AND_21_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_20_AND_21(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_22_and_23(const Spark_WRITE_PARAMETER_22_AND_23_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_22_AND_23(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_24_and_25(const Spark_WRITE_PARAMETER_24_AND_25_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_24_AND_25(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_26_and_27(const Spark_WRITE_PARAMETER_26_AND_27_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_26_AND_27(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_28_and_29(const Spark_WRITE_PARAMETER_28_AND_29_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_28_AND_29(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_30_and_31(const Spark_WRITE_PARAMETER_30_AND_31_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_30_AND_31(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_32_and_33(const Spark_WRITE_PARAMETER_32_AND_33_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_32_AND_33(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_34_and_35(const Spark_WRITE_PARAMETER_34_AND_35_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_34_AND_35(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_36_and_37(const Spark_WRITE_PARAMETER_36_AND_37_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_36_AND_37(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_38_and_39(const Spark_WRITE_PARAMETER_38_AND_39_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_38_AND_39(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_40_and_41(const Spark_WRITE_PARAMETER_40_AND_41_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_40_AND_41(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_42_and_43(const Spark_WRITE_PARAMETER_42_AND_43_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_42_AND_43(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_44_and_45(const Spark_WRITE_PARAMETER_44_AND_45_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_44_AND_45(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_46_and_47(const Spark_WRITE_PARAMETER_46_AND_47_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_46_AND_47(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_48_and_49(const Spark_WRITE_PARAMETER_48_AND_49_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_48_AND_49(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_50_and_51(const Spark_WRITE_PARAMETER_50_AND_51_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_50_AND_51(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_52_and_53(const Spark_WRITE_PARAMETER_52_AND_53_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_52_AND_53(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_54_and_55(const Spark_WRITE_PARAMETER_54_AND_55_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_54_AND_55(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_56_and_57(const Spark_WRITE_PARAMETER_56_AND_57_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_56_AND_57(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_58_and_59(const Spark_WRITE_PARAMETER_58_AND_59_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_58_AND_59(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_60_and_61(const Spark_WRITE_PARAMETER_60_AND_61_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_60_AND_61(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_62_and_63(const Spark_WRITE_PARAMETER_62_AND_63_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_62_AND_63(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_64_and_65(const Spark_WRITE_PARAMETER_64_AND_65_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_64_AND_65(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_66_and_67(const Spark_WRITE_PARAMETER_66_AND_67_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_66_AND_67(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_68_and_69(const Spark_WRITE_PARAMETER_68_AND_69_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_68_AND_69(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_70_and_71(const Spark_WRITE_PARAMETER_70_AND_71_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_70_AND_71(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_72_and_73(const Spark_WRITE_PARAMETER_72_AND_73_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_72_AND_73(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_74_and_75(const Spark_WRITE_PARAMETER_74_AND_75_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_74_AND_75(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_76_and_77(const Spark_WRITE_PARAMETER_76_AND_77_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_76_AND_77(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_78_and_79(const Spark_WRITE_PARAMETER_78_AND_79_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_78_AND_79(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_80_and_81(const Spark_WRITE_PARAMETER_80_AND_81_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_80_AND_81(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_82_and_83(const Spark_WRITE_PARAMETER_82_AND_83_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_82_AND_83(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_84_and_85(const Spark_WRITE_PARAMETER_84_AND_85_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_84_AND_85(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_86_and_87(const Spark_WRITE_PARAMETER_86_AND_87_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_86_AND_87(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_88_and_89(const Spark_WRITE_PARAMETER_88_AND_89_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_88_AND_89(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_90_and_91(const Spark_WRITE_PARAMETER_90_AND_91_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_90_AND_91(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_92_and_93(const Spark_WRITE_PARAMETER_92_AND_93_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_92_AND_93(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_94_and_95(const Spark_WRITE_PARAMETER_94_AND_95_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_94_AND_95(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_96_and_97(const Spark_WRITE_PARAMETER_96_AND_97_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_96_AND_97(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_98_and_99(const Spark_WRITE_PARAMETER_98_AND_99_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_98_AND_99(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_100_and_101(const Spark_WRITE_PARAMETER_100_AND_101_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_100_AND_101(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_102_and_103(const Spark_WRITE_PARAMETER_102_AND_103_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_102_AND_103(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_104_and_105(const Spark_WRITE_PARAMETER_104_AND_105_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_104_AND_105(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_106_and_107(const Spark_WRITE_PARAMETER_106_AND_107_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_106_AND_107(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_108_and_109(const Spark_WRITE_PARAMETER_108_AND_109_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_108_AND_109(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_110_and_111(const Spark_WRITE_PARAMETER_110_AND_111_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_110_AND_111(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_112_and_113(const Spark_WRITE_PARAMETER_112_AND_113_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_112_AND_113(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_114_and_115(const Spark_WRITE_PARAMETER_114_AND_115_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_114_AND_115(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_116_and_117(const Spark_WRITE_PARAMETER_116_AND_117_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_116_AND_117(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_118_and_119(const Spark_WRITE_PARAMETER_118_AND_119_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_118_AND_119(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_120_and_121(const Spark_WRITE_PARAMETER_120_AND_121_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_120_AND_121(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_122_and_123(const Spark_WRITE_PARAMETER_122_AND_123_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_122_AND_123(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_124_and_125(const Spark_WRITE_PARAMETER_124_AND_125_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_124_AND_125(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_126_and_127(const Spark_WRITE_PARAMETER_126_AND_127_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_126_AND_127(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_128_and_129(const Spark_WRITE_PARAMETER_128_AND_129_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_128_AND_129(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_130_and_131(const Spark_WRITE_PARAMETER_130_AND_131_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_130_AND_131(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_132_and_133(const Spark_WRITE_PARAMETER_132_AND_133_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_132_AND_133(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_134_and_135(const Spark_WRITE_PARAMETER_134_AND_135_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_134_AND_135(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_136_and_137(const Spark_WRITE_PARAMETER_136_AND_137_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_136_AND_137(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_138_and_139(const Spark_WRITE_PARAMETER_138_AND_139_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_138_AND_139(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_140_and_141(const Spark_WRITE_PARAMETER_140_AND_141_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_140_AND_141(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_142_and_143(const Spark_WRITE_PARAMETER_142_AND_143_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_142_AND_143(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_144_and_145(const Spark_WRITE_PARAMETER_144_AND_145_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_144_AND_145(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_146_and_147(const Spark_WRITE_PARAMETER_146_AND_147_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_146_AND_147(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_148_and_149(const Spark_WRITE_PARAMETER_148_AND_149_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_148_AND_149(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_150_and_151(const Spark_WRITE_PARAMETER_150_AND_151_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_150_AND_151(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_152_and_153(const Spark_WRITE_PARAMETER_152_AND_153_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_152_AND_153(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_154_and_155(const Spark_WRITE_PARAMETER_154_AND_155_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_154_AND_155(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_156_and_157(const Spark_WRITE_PARAMETER_156_AND_157_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_156_AND_157(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_158_and_159(const Spark_WRITE_PARAMETER_158_AND_159_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_158_AND_159(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_160_and_161(const Spark_WRITE_PARAMETER_160_AND_161_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_160_AND_161(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_162_and_163(const Spark_WRITE_PARAMETER_162_AND_163_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_162_AND_163(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_164_and_165(const Spark_WRITE_PARAMETER_164_AND_165_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_164_AND_165(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_166_and_167(const Spark_WRITE_PARAMETER_166_AND_167_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_166_AND_167(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_168_and_169(const Spark_WRITE_PARAMETER_168_AND_169_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_168_AND_169(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_170_and_171(const Spark_WRITE_PARAMETER_170_AND_171_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_170_AND_171(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_172_and_173(const Spark_WRITE_PARAMETER_172_AND_173_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_172_AND_173(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_174_and_175(const Spark_WRITE_PARAMETER_174_AND_175_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_174_AND_175(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_176_and_177(const Spark_WRITE_PARAMETER_176_AND_177_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_176_AND_177(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_178_and_179(const Spark_WRITE_PARAMETER_178_AND_179_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_178_AND_179(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_180_and_181(const Spark_WRITE_PARAMETER_180_AND_181_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_180_AND_181(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_182_and_183(const Spark_WRITE_PARAMETER_182_AND_183_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_182_AND_183(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_184_and_185(const Spark_WRITE_PARAMETER_184_AND_185_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_184_AND_185(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_186_and_187(const Spark_WRITE_PARAMETER_186_AND_187_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_186_AND_187(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_188_and_189(const Spark_WRITE_PARAMETER_188_AND_189_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_188_AND_189(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_190_and_191(const Spark_WRITE_PARAMETER_190_AND_191_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_190_AND_191(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_192_and_193(const Spark_WRITE_PARAMETER_192_AND_193_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_192_AND_193(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_194_and_195(const Spark_WRITE_PARAMETER_194_AND_195_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_194_AND_195(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_196_and_197(const Spark_WRITE_PARAMETER_196_AND_197_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_196_AND_197(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_198_and_199(const Spark_WRITE_PARAMETER_198_AND_199_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_198_AND_199(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_200_and_201(const Spark_WRITE_PARAMETER_200_AND_201_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_200_AND_201(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_202_and_203(const Spark_WRITE_PARAMETER_202_AND_203_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_202_AND_203(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_204_and_205(const Spark_WRITE_PARAMETER_204_AND_205_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_204_AND_205(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_206_and_207(const Spark_WRITE_PARAMETER_206_AND_207_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_206_AND_207(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_208_and_209(const Spark_WRITE_PARAMETER_208_AND_209_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_208_AND_209(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_210_and_211(const Spark_WRITE_PARAMETER_210_AND_211_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_210_AND_211(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_212_and_213(const Spark_WRITE_PARAMETER_212_AND_213_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_212_AND_213(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_214_and_215(const Spark_WRITE_PARAMETER_214_AND_215_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_214_AND_215(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_216_and_217(const Spark_WRITE_PARAMETER_216_AND_217_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_216_AND_217(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_218_and_219(const Spark_WRITE_PARAMETER_218_AND_219_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_218_AND_219(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_220_and_221(const Spark_WRITE_PARAMETER_220_AND_221_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_220_AND_221(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_222_and_223(const Spark_WRITE_PARAMETER_222_AND_223_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_222_AND_223(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_224_and_225(const Spark_WRITE_PARAMETER_224_AND_225_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_224_AND_225(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_226_and_227(const Spark_WRITE_PARAMETER_226_AND_227_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_226_AND_227(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_228_and_229(const Spark_WRITE_PARAMETER_228_AND_229_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_228_AND_229(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_230_and_231(const Spark_WRITE_PARAMETER_230_AND_231_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_230_AND_231(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_232_and_233(const Spark_WRITE_PARAMETER_232_AND_233_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_232_AND_233(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_234_and_235(const Spark_WRITE_PARAMETER_234_AND_235_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_234_AND_235(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_236_and_237(const Spark_WRITE_PARAMETER_236_AND_237_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_236_AND_237(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_238_and_239(const Spark_WRITE_PARAMETER_238_AND_239_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_238_AND_239(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_240_and_241(const Spark_WRITE_PARAMETER_240_AND_241_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_240_AND_241(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_242_and_243(const Spark_WRITE_PARAMETER_242_AND_243_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_242_AND_243(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_244_and_245(const Spark_WRITE_PARAMETER_244_AND_245_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_244_AND_245(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_246_and_247(const Spark_WRITE_PARAMETER_246_AND_247_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_246_AND_247(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_248_and_249(const Spark_WRITE_PARAMETER_248_AND_249_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_248_AND_249(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_250_and_251(const Spark_WRITE_PARAMETER_250_AND_251_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_250_AND_251(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_252_and_253(const Spark_WRITE_PARAMETER_252_AND_253_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_252_AND_253(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_write_parameter_254_and_255(const Spark_WRITE_PARAMETER_254_AND_255_t* values) const {
    return dispatch_frame(spark_build_WRITE_PARAMETER_254_AND_255(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_start_follower_mode(const Spark_START_FOLLOWER_MODE_t* values) const {
    return dispatch_frame(spark_build_START_FOLLOWER_MODE(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_start_follower_mode_response(const Spark_START_FOLLOWER_MODE_RESPONSE_t* values) const {
    return dispatch_frame(spark_build_START_FOLLOWER_MODE_RESPONSE(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_stop_follower_mode(const Spark_STOP_FOLLOWER_MODE_t* values) const {
    return dispatch_frame(spark_build_STOP_FOLLOWER_MODE(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_stop_follower_mode_response(const Spark_STOP_FOLLOWER_MODE_RESPONSE_t* values) const {
    return dispatch_frame(spark_build_STOP_FOLLOWER_MODE_RESPONSE(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_enter_swdl_can_bootloader(const Spark_ENTER_SWDL_CAN_BOOTLOADER_t* values) const {
    return dispatch_frame(spark_build_ENTER_SWDL_CAN_BOOTLOADER(device_id_, values));
}

MCP2515::ERROR SparkCanDevice::send_persist_parameters(const Spark_PERSIST_PARAMETERS_t* values) const {
    return dispatch_frame(spark_build_PERSIST_PARAMETERS(device_id_, values));
}

bool spark_decode_LEGACY_STATUS_0(const uint8_t* data, uint8_t dlc, Spark_LEGACY_STATUS_0_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->APPLIED_OUTPUT = unpack_field(data, 0u, 16u, false);
    out->FAULTS_AND_STICKY_FAULTS = unpack_field(data, 16u, 32u, false);
    out->OTHER_SIGNALS = unpack_field(data, 48u, 16u, false);
    return true;
}

bool spark_decode_STATUS_0(const uint8_t* data, uint8_t dlc, Spark_STATUS_0_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    uint64_t _APPLIED_OUTPUT_u = unpack_field(data, 0u, 16u, false);
    if (16u < 64u && (_APPLIED_OUTPUT_u & (1ull << (16u - 1u)))) { _APPLIED_OUTPUT_u |= ~((1ull<<16)-1ull); }
    out->APPLIED_OUTPUT = (int64_t)_APPLIED_OUTPUT_u;
    out->VOLTAGE = unpack_field(data, 16u, 12u, false);
    out->CURRENT = unpack_field(data, 28u, 12u, false);
    out->MOTOR_TEMPERATURE = unpack_field(data, 40u, 8u, false);
    out->HARD_FORWARD_LIMIT_REACHED = unpack_field(data, 48u, 1u, false) ? true : false;
    out->HARD_REVERSE_LIMIT_REACHED = unpack_field(data, 49u, 1u, false) ? true : false;
    out->SOFT_FORWARD_LIMIT_REACHED = unpack_field(data, 50u, 1u, false) ? true : false;
    out->SOFT_REVERSE_LIMIT_REACHED = unpack_field(data, 51u, 1u, false) ? true : false;
    out->INVERTED = unpack_field(data, 52u, 1u, false) ? true : false;
    out->PRIMARY_HEARTBEAT_LOCK = unpack_field(data, 53u, 1u, false) ? true : false;
    return true;
}

bool spark_decode_STATUS_1(const uint8_t* data, uint8_t dlc, Spark_STATUS_1_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->OTHER_FAULT = unpack_field(data, 0u, 1u, false) ? true : false;
    out->MOTOR_TYPE_FAULT = unpack_field(data, 1u, 1u, false) ? true : false;
    out->SENSOR_FAULT = unpack_field(data, 2u, 1u, false) ? true : false;
    out->CAN_FAULT = unpack_field(data, 3u, 1u, false) ? true : false;
    out->TEMPERATURE_FAULT = unpack_field(data, 4u, 1u, false) ? true : false;
    out->DRV_FAULT = unpack_field(data, 5u, 1u, false) ? true : false;
    out->ESC_EEPROM_FAULT = unpack_field(data, 6u, 1u, false) ? true : false;
    out->FIRMWARE_FAULT = unpack_field(data, 7u, 1u, false) ? true : false;
    out->BROWNOUT_WARNING = unpack_field(data, 16u, 1u, false) ? true : false;
    out->OVERCURRENT_WARNING = unpack_field(data, 17u, 1u, false) ? true : false;
    out->ESC_EEPROM_WARNING = unpack_field(data, 18u, 1u, false) ? true : false;
    out->EXT_EEPROM_WARNING = unpack_field(data, 19u, 1u, false) ? true : false;
    out->SENSOR_WARNING = unpack_field(data, 20u, 1u, false) ? true : false;
    out->STALL_WARNING = unpack_field(data, 21u, 1u, false) ? true : false;
    out->HAS_RESET_WARNING = unpack_field(data, 22u, 1u, false) ? true : false;
    out->OTHER_WARNING = unpack_field(data, 23u, 1u, false) ? true : false;
    out->OTHER_STICKY_FAULT = unpack_field(data, 24u, 1u, false) ? true : false;
    out->MOTOR_TYPE_STICKY_FAULT = unpack_field(data, 25u, 1u, false) ? true : false;
    out->SENSOR_STICKY_FAULT = unpack_field(data, 26u, 1u, false) ? true : false;
    out->CAN_STICKY_FAULT = unpack_field(data, 27u, 1u, false) ? true : false;
    out->TEMPERATURE_STICKY_FAULT = unpack_field(data, 28u, 1u, false) ? true : false;
    out->DRV_STICKY_FAULT = unpack_field(data, 29u, 1u, false) ? true : false;
    out->ESC_EEPROM_STICKY_FAULT = unpack_field(data, 30u, 1u, false) ? true : false;
    out->FIRMWARE_STICKY_FAULT = unpack_field(data, 31u, 1u, false) ? true : false;
    out->BROWNOUT_STICKY_WARNING = unpack_field(data, 40u, 1u, false) ? true : false;
    out->OVERCURRENT_STICKY_WARNING = unpack_field(data, 41u, 1u, false) ? true : false;
    out->ESC_EEPROM_STICKY_WARNING = unpack_field(data, 42u, 1u, false) ? true : false;
    out->EXT_EEPROM_STICKY_WARNING = unpack_field(data, 43u, 1u, false) ? true : false;
    out->SENSOR_STICKY_WARNING = unpack_field(data, 44u, 1u, false) ? true : false;
    out->STALL_STICKY_WARNING = unpack_field(data, 45u, 1u, false) ? true : false;
    out->HAS_RESET_STICKY_WARNING = unpack_field(data, 46u, 1u, false) ? true : false;
    out->OTHER_STICKY_WARNING = unpack_field(data, 47u, 1u, false) ? true : false;
    out->IS_FOLLOWER = unpack_field(data, 48u, 1u, false) ? true : false;
    return true;
}

bool spark_decode_STATUS_2(const uint8_t* data, uint8_t dlc, Spark_STATUS_2_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    uint32_t _PRIMARY_ENCODER_VELOCITY_u = (uint32_t)unpack_field(data, 0u, 32u, false);
    union { uint32_t u; float f; } _PRIMARY_ENCODER_VELOCITY = { .u = _PRIMARY_ENCODER_VELOCITY_u };
    out->PRIMARY_ENCODER_VELOCITY = _PRIMARY_ENCODER_VELOCITY.f;
    uint32_t _PRIMARY_ENCODER_POSITION_u = (uint32_t)unpack_field(data, 32u, 32u, false);
    union { uint32_t u; float f; } _PRIMARY_ENCODER_POSITION = { .u = _PRIMARY_ENCODER_POSITION_u };
    out->PRIMARY_ENCODER_POSITION = _PRIMARY_ENCODER_POSITION.f;
    return true;
}

bool spark_decode_STATUS_3(const uint8_t* data, uint8_t dlc, Spark_STATUS_3_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->ANALOG_VOLTAGE = unpack_field(data, 0u, 10u, false);
    uint64_t _ANALOG_VELOCITY_u = unpack_field(data, 10u, 22u, false);
    if (22u < 64u && (_ANALOG_VELOCITY_u & (1ull << (22u - 1u)))) { _ANALOG_VELOCITY_u |= ~((1ull<<22)-1ull); }
    out->ANALOG_VELOCITY = (int64_t)_ANALOG_VELOCITY_u;
    uint32_t _ANALOG_POSITION_u = (uint32_t)unpack_field(data, 32u, 32u, false);
    union { uint32_t u; float f; } _ANALOG_POSITION = { .u = _ANALOG_POSITION_u };
    out->ANALOG_POSITION = _ANALOG_POSITION.f;
    return true;
}

bool spark_decode_STATUS_4(const uint8_t* data, uint8_t dlc, Spark_STATUS_4_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    uint32_t _EXTERNAL_OR_ALT_ENCODER_VELOCITY_u = (uint32_t)unpack_field(data, 0u, 32u, false);
    union { uint32_t u; float f; } _EXTERNAL_OR_ALT_ENCODER_VELOCITY = { .u = _EXTERNAL_OR_ALT_ENCODER_VELOCITY_u };
    out->EXTERNAL_OR_ALT_ENCODER_VELOCITY = _EXTERNAL_OR_ALT_ENCODER_VELOCITY.f;
    uint32_t _EXTERNAL_OR_ALT_ENCODER_POSITION_u = (uint32_t)unpack_field(data, 32u, 32u, false);
    union { uint32_t u; float f; } _EXTERNAL_OR_ALT_ENCODER_POSITION = { .u = _EXTERNAL_OR_ALT_ENCODER_POSITION_u };
    out->EXTERNAL_OR_ALT_ENCODER_POSITION = _EXTERNAL_OR_ALT_ENCODER_POSITION.f;
    return true;
}

bool spark_decode_STATUS_5(const uint8_t* data, uint8_t dlc, Spark_STATUS_5_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    uint32_t _DUTY_CYCLE_ENCODER_VELOCITY_u = (uint32_t)unpack_field(data, 0u, 32u, false);
    union { uint32_t u; float f; } _DUTY_CYCLE_ENCODER_VELOCITY = { .u = _DUTY_CYCLE_ENCODER_VELOCITY_u };
    out->DUTY_CYCLE_ENCODER_VELOCITY = _DUTY_CYCLE_ENCODER_VELOCITY.f;
    uint32_t _DUTY_CYCLE_ENCODER_POSITION_u = (uint32_t)unpack_field(data, 32u, 32u, false);
    union { uint32_t u; float f; } _DUTY_CYCLE_ENCODER_POSITION = { .u = _DUTY_CYCLE_ENCODER_POSITION_u };
    out->DUTY_CYCLE_ENCODER_POSITION = _DUTY_CYCLE_ENCODER_POSITION.f;
    return true;
}

bool spark_decode_STATUS_6(const uint8_t* data, uint8_t dlc, Spark_STATUS_6_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->UNADJUSTED_DUTY_CYCLE = unpack_field(data, 0u, 16u, false);
    out->DUTY_CYCLE_PERIOD = unpack_field(data, 16u, 16u, false);
    out->DUTY_CYCLE_NO_SIGNAL = unpack_field(data, 32u, 1u, false) ? true : false;
    return true;
}

bool spark_decode_STATUS_7(const uint8_t* data, uint8_t dlc, Spark_STATUS_7_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    uint32_t _I_ACCUMULATION_u = (uint32_t)unpack_field(data, 0u, 32u, false);
    union { uint32_t u; float f; } _I_ACCUMULATION = { .u = _I_ACCUMULATION_u };
    out->I_ACCUMULATION = _I_ACCUMULATION.f;
    return true;
}

bool spark_decode_UNIQUE_ID_BROADCAST(const uint8_t* data, uint8_t dlc, Spark_UNIQUE_ID_BROADCAST_t* out) {
    if (!data || !out) return false;
    if (dlc < 4u) return false;
    out->UNIQUE_ID = unpack_field(data, 0u, 32u, false);
    return true;
}

bool spark_decode_VELOCITY_SETPOINT(const uint8_t* data, uint8_t dlc, Spark_VELOCITY_SETPOINT_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    uint32_t _SETPOINT_u = (uint32_t)unpack_field(data, 0u, 32u, false);
    union { uint32_t u; float f; } _SETPOINT = { .u = _SETPOINT_u };
    out->SETPOINT = _SETPOINT.f;
    uint64_t _ARBITRARY_FEEDFORWARD_u = unpack_field(data, 32u, 16u, false);
    if (16u < 64u && (_ARBITRARY_FEEDFORWARD_u & (1ull << (16u - 1u)))) { _ARBITRARY_FEEDFORWARD_u |= ~((1ull<<16)-1ull); }
    out->ARBITRARY_FEEDFORWARD = (int64_t)_ARBITRARY_FEEDFORWARD_u;
    out->PID_SLOT = unpack_field(data, 48u, 2u, false);
    out->ARBITRARY_FEEDFORWARD_UNITS = unpack_field(data, 50u, 1u, false);
    return true;
}

bool spark_decode_DUTY_CYCLE_SETPOINT(const uint8_t* data, uint8_t dlc, Spark_DUTY_CYCLE_SETPOINT_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    uint32_t _SETPOINT_u = (uint32_t)unpack_field(data, 0u, 32u, false);
    union { uint32_t u; float f; } _SETPOINT = { .u = _SETPOINT_u };
    out->SETPOINT = _SETPOINT.f;
    uint64_t _ARBITRARY_FEEDFORWARD_u = unpack_field(data, 32u, 16u, false);
    if (16u < 64u && (_ARBITRARY_FEEDFORWARD_u & (1ull << (16u - 1u)))) { _ARBITRARY_FEEDFORWARD_u |= ~((1ull<<16)-1ull); }
    out->ARBITRARY_FEEDFORWARD = (int64_t)_ARBITRARY_FEEDFORWARD_u;
    out->PID_SLOT = unpack_field(data, 48u, 2u, false);
    out->ARBITRARY_FEEDFORWARD_UNITS = unpack_field(data, 50u, 1u, false);
    return true;
}

bool spark_decode_SMART_VELOCITY_SETPOINT(const uint8_t* data, uint8_t dlc, Spark_SMART_VELOCITY_SETPOINT_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    uint32_t _SETPOINT_u = (uint32_t)unpack_field(data, 0u, 32u, false);
    union { uint32_t u; float f; } _SETPOINT = { .u = _SETPOINT_u };
    out->SETPOINT = _SETPOINT.f;
    uint64_t _ARBITRARY_FEEDFORWARD_u = unpack_field(data, 32u, 16u, false);
    if (16u < 64u && (_ARBITRARY_FEEDFORWARD_u & (1ull << (16u - 1u)))) { _ARBITRARY_FEEDFORWARD_u |= ~((1ull<<16)-1ull); }
    out->ARBITRARY_FEEDFORWARD = (int64_t)_ARBITRARY_FEEDFORWARD_u;
    out->PID_SLOT = unpack_field(data, 48u, 2u, false);
    out->ARBITRARY_FEEDFORWARD_UNITS = unpack_field(data, 50u, 1u, false);
    return true;
}

bool spark_decode_POSITION_SETPOINT(const uint8_t* data, uint8_t dlc, Spark_POSITION_SETPOINT_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    uint32_t _SETPOINT_u = (uint32_t)unpack_field(data, 0u, 32u, false);
    union { uint32_t u; float f; } _SETPOINT = { .u = _SETPOINT_u };
    out->SETPOINT = _SETPOINT.f;
    uint64_t _ARBITRARY_FEEDFORWARD_u = unpack_field(data, 32u, 16u, false);
    if (16u < 64u && (_ARBITRARY_FEEDFORWARD_u & (1ull << (16u - 1u)))) { _ARBITRARY_FEEDFORWARD_u |= ~((1ull<<16)-1ull); }
    out->ARBITRARY_FEEDFORWARD = (int64_t)_ARBITRARY_FEEDFORWARD_u;
    out->PID_SLOT = unpack_field(data, 48u, 2u, false);
    out->ARBITRARY_FEEDFORWARD_UNITS = unpack_field(data, 50u, 1u, false);
    return true;
}

bool spark_decode_VOLTAGE_SETPOINT(const uint8_t* data, uint8_t dlc, Spark_VOLTAGE_SETPOINT_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    uint32_t _SETPOINT_u = (uint32_t)unpack_field(data, 0u, 32u, false);
    union { uint32_t u; float f; } _SETPOINT = { .u = _SETPOINT_u };
    out->SETPOINT = _SETPOINT.f;
    uint64_t _ARBITRARY_FEEDFORWARD_u = unpack_field(data, 32u, 16u, false);
    if (16u < 64u && (_ARBITRARY_FEEDFORWARD_u & (1ull << (16u - 1u)))) { _ARBITRARY_FEEDFORWARD_u |= ~((1ull<<16)-1ull); }
    out->ARBITRARY_FEEDFORWARD = (int64_t)_ARBITRARY_FEEDFORWARD_u;
    out->PID_SLOT = unpack_field(data, 48u, 2u, false);
    out->ARBITRARY_FEEDFORWARD_UNITS = unpack_field(data, 50u, 1u, false);
    return true;
}

bool spark_decode_CURRENT_SETPOINT(const uint8_t* data, uint8_t dlc, Spark_CURRENT_SETPOINT_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    uint32_t _SETPOINT_u = (uint32_t)unpack_field(data, 0u, 32u, false);
    union { uint32_t u; float f; } _SETPOINT = { .u = _SETPOINT_u };
    out->SETPOINT = _SETPOINT.f;
    uint64_t _ARBITRARY_FEEDFORWARD_u = unpack_field(data, 32u, 16u, false);
    if (16u < 64u && (_ARBITRARY_FEEDFORWARD_u & (1ull << (16u - 1u)))) { _ARBITRARY_FEEDFORWARD_u |= ~((1ull<<16)-1ull); }
    out->ARBITRARY_FEEDFORWARD = (int64_t)_ARBITRARY_FEEDFORWARD_u;
    out->PID_SLOT = unpack_field(data, 48u, 2u, false);
    out->ARBITRARY_FEEDFORWARD_UNITS = unpack_field(data, 50u, 1u, false);
    return true;
}

bool spark_decode_SMART_MOTION_SETPOINT(const uint8_t* data, uint8_t dlc, Spark_SMART_MOTION_SETPOINT_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    uint32_t _SETPOINT_u = (uint32_t)unpack_field(data, 0u, 32u, false);
    union { uint32_t u; float f; } _SETPOINT = { .u = _SETPOINT_u };
    out->SETPOINT = _SETPOINT.f;
    uint64_t _ARBITRARY_FEEDFORWARD_u = unpack_field(data, 32u, 16u, false);
    if (16u < 64u && (_ARBITRARY_FEEDFORWARD_u & (1ull << (16u - 1u)))) { _ARBITRARY_FEEDFORWARD_u |= ~((1ull<<16)-1ull); }
    out->ARBITRARY_FEEDFORWARD = (int64_t)_ARBITRARY_FEEDFORWARD_u;
    out->PID_SLOT = unpack_field(data, 48u, 2u, false);
    out->ARBITRARY_FEEDFORWARD_UNITS = unpack_field(data, 50u, 1u, false);
    return true;
}

bool spark_decode_MAXMOTION_POSITION_SETPOINT(const uint8_t* data, uint8_t dlc, Spark_MAXMOTION_POSITION_SETPOINT_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    uint32_t _SETPOINT_u = (uint32_t)unpack_field(data, 0u, 32u, false);
    union { uint32_t u; float f; } _SETPOINT = { .u = _SETPOINT_u };
    out->SETPOINT = _SETPOINT.f;
    uint64_t _ARBITRARY_FEEDFORWARD_u = unpack_field(data, 32u, 16u, false);
    if (16u < 64u && (_ARBITRARY_FEEDFORWARD_u & (1ull << (16u - 1u)))) { _ARBITRARY_FEEDFORWARD_u |= ~((1ull<<16)-1ull); }
    out->ARBITRARY_FEEDFORWARD = (int64_t)_ARBITRARY_FEEDFORWARD_u;
    out->PID_SLOT = unpack_field(data, 48u, 2u, false);
    out->ARBITRARY_FEEDFORWARD_UNITS = unpack_field(data, 50u, 1u, false);
    return true;
}

bool spark_decode_MAXMOTION_VELOCITY_SETPOINT(const uint8_t* data, uint8_t dlc, Spark_MAXMOTION_VELOCITY_SETPOINT_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    uint32_t _SETPOINT_u = (uint32_t)unpack_field(data, 0u, 32u, false);
    union { uint32_t u; float f; } _SETPOINT = { .u = _SETPOINT_u };
    out->SETPOINT = _SETPOINT.f;
    uint64_t _ARBITRARY_FEEDFORWARD_u = unpack_field(data, 32u, 16u, false);
    if (16u < 64u && (_ARBITRARY_FEEDFORWARD_u & (1ull << (16u - 1u)))) { _ARBITRARY_FEEDFORWARD_u |= ~((1ull<<16)-1ull); }
    out->ARBITRARY_FEEDFORWARD = (int64_t)_ARBITRARY_FEEDFORWARD_u;
    out->PID_SLOT = unpack_field(data, 48u, 2u, false);
    out->ARBITRARY_FEEDFORWARD_UNITS = unpack_field(data, 50u, 1u, false);
    return true;
}

bool spark_decode_SET_STATUSES_ENABLED(const uint8_t* data, uint8_t dlc, Spark_SET_STATUSES_ENABLED_t* out) {
    if (!data || !out) return false;
    if (dlc < 4u) return false;
    out->MASK = unpack_field(data, 0u, 16u, false);
    out->ENABLED_BITFIELD = unpack_field(data, 16u, 16u, false);
    return true;
}

bool spark_decode_SET_STATUSES_ENABLED_RESPONSE(const uint8_t* data, uint8_t dlc, Spark_SET_STATUSES_ENABLED_RESPONSE_t* out) {
    if (!data || !out) return false;
    if (dlc < 5u) return false;
    out->RESULT_CODE = unpack_field(data, 0u, 8u, false);
    out->SPECIFIED_MASK = unpack_field(data, 8u, 16u, false);
    out->ENABLED_BITFIELD = unpack_field(data, 24u, 16u, false);
    return true;
}

bool spark_decode_PERSIST_PARAMETERS_RESPONSE(const uint8_t* data, uint8_t dlc, Spark_PERSIST_PARAMETERS_RESPONSE_t* out) {
    if (!data || !out) return false;
    if (dlc < 1u) return false;
    out->RESULT_CODE = unpack_field(data, 0u, 8u, false);
    return true;
}

bool spark_decode_RESET_SAFE_PARAMETERS(const uint8_t* data, uint8_t dlc, Spark_RESET_SAFE_PARAMETERS_t* out) {
    if (!data || !out) return false;
    if (dlc < 2u) return false;
    out->MAGIC_NUMBER = unpack_field(data, 0u, 16u, false);
    return true;
}

bool spark_decode_RESET_SAFE_PARAMETERS_RESPONSE(const uint8_t* data, uint8_t dlc, Spark_RESET_SAFE_PARAMETERS_RESPONSE_t* out) {
    if (!data || !out) return false;
    if (dlc < 1u) return false;
    out->RESULT_CODE = unpack_field(data, 0u, 8u, false);
    return true;
}

bool spark_decode_COMPLETE_FACTORY_RESET(const uint8_t* data, uint8_t dlc, Spark_COMPLETE_FACTORY_RESET_t* out) {
    if (!data || !out) return false;
    if (dlc < 2u) return false;
    out->MAGIC_NUMBER = unpack_field(data, 0u, 16u, false);
    return true;
}

bool spark_decode_COMPLETE_FACTORY_RESET_RESPONSE(const uint8_t* data, uint8_t dlc, Spark_COMPLETE_FACTORY_RESET_RESPONSE_t* out) {
    if (!data || !out) return false;
    if (dlc < 1u) return false;
    out->RESULT_CODE = unpack_field(data, 0u, 8u, false);
    return true;
}

bool spark_decode_IDENTIFY_UNIQUE_SPARK(const uint8_t* data, uint8_t dlc, Spark_IDENTIFY_UNIQUE_SPARK_t* out) {
    if (!data || !out) return false;
    if (dlc < 4u) return false;
    out->UNIQUE_ID = unpack_field(data, 0u, 32u, false);
    return true;
}

bool spark_decode_SET_CAN_ID(const uint8_t* data, uint8_t dlc, Spark_SET_CAN_ID_t* out) {
    if (!data || !out) return false;
    if (dlc < 5u) return false;
    out->UNIQUE_ID = unpack_field(data, 0u, 32u, false);
    out->CAN_ID = unpack_field(data, 32u, 8u, false);
    return true;
}

bool spark_decode_GET_FIRMWARE_VERSION(const uint8_t* data, uint8_t dlc, Spark_GET_FIRMWARE_VERSION_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->MAJOR = unpack_field(data, 0u, 8u, false);
    out->MINOR = unpack_field(data, 8u, 8u, false);
    out->BUILD = unpack_field(data, 16u, 16u, true);
    out->DEBUG_BUILD = unpack_field(data, 32u, 8u, false);
    out->HW_REV = unpack_field(data, 40u, 8u, false);
    return true;
}

bool spark_decode_SWDL_DATA(const uint8_t* data, uint8_t dlc, Spark_SWDL_DATA_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->DATA = unpack_field(data, 0u, 64u, false);
    return true;
}

bool spark_decode_SWDL_CHECKSUM(const uint8_t* data, uint8_t dlc, Spark_SWDL_CHECKSUM_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->CHECKSUM = unpack_field(data, 0u, 64u, false);
    return true;
}

bool spark_decode_SET_PRIMARY_ENCODER_POSITION(const uint8_t* data, uint8_t dlc, Spark_SET_PRIMARY_ENCODER_POSITION_t* out) {
    if (!data || !out) return false;
    if (dlc < 5u) return false;
    uint32_t _POSITION_u = (uint32_t)unpack_field(data, 0u, 32u, false);
    union { uint32_t u; float f; } _POSITION = { .u = _POSITION_u };
    out->POSITION = _POSITION.f;
    out->DATA_TYPE = unpack_field(data, 32u, 8u, false);
    return true;
}

bool spark_decode_SET_I_ACCUMULATION(const uint8_t* data, uint8_t dlc, Spark_SET_I_ACCUMULATION_t* out) {
    if (!data || !out) return false;
    if (dlc < 5u) return false;
    uint32_t _I_ACCUMULATION_u = (uint32_t)unpack_field(data, 0u, 32u, false);
    union { uint32_t u; float f; } _I_ACCUMULATION = { .u = _I_ACCUMULATION_u };
    out->I_ACCUMULATION = _I_ACCUMULATION.f;
    out->DATA_TYPE = unpack_field(data, 32u, 8u, false);
    return true;
}

bool spark_decode_SET_ANALOG_POSITION(const uint8_t* data, uint8_t dlc, Spark_SET_ANALOG_POSITION_t* out) {
    if (!data || !out) return false;
    if (dlc < 5u) return false;
    uint32_t _POSITION_u = (uint32_t)unpack_field(data, 0u, 32u, false);
    union { uint32_t u; float f; } _POSITION = { .u = _POSITION_u };
    out->POSITION = _POSITION.f;
    out->DATA_TYPE = unpack_field(data, 32u, 8u, false);
    return true;
}

bool spark_decode_SET_EXT_OR_ALT_ENCODER_POSITION(const uint8_t* data, uint8_t dlc, Spark_SET_EXT_OR_ALT_ENCODER_POSITION_t* out) {
    if (!data || !out) return false;
    if (dlc < 5u) return false;
    uint32_t _POSITION_u = (uint32_t)unpack_field(data, 0u, 32u, false);
    union { uint32_t u; float f; } _POSITION = { .u = _POSITION_u };
    out->POSITION = _POSITION.f;
    out->DATA_TYPE = unpack_field(data, 32u, 8u, false);
    return true;
}

bool spark_decode_SET_DUTY_CYCLE_POSITION(const uint8_t* data, uint8_t dlc, Spark_SET_DUTY_CYCLE_POSITION_t* out) {
    if (!data || !out) return false;
    if (dlc < 5u) return false;
    uint32_t _POSITION_u = (uint32_t)unpack_field(data, 0u, 32u, false);
    union { uint32_t u; float f; } _POSITION = { .u = _POSITION_u };
    out->POSITION = _POSITION.f;
    out->DATA_TYPE = unpack_field(data, 32u, 8u, false);
    return true;
}

bool spark_decode_SECONDARY_HEARTBEAT(const uint8_t* data, uint8_t dlc, Spark_SECONDARY_HEARTBEAT_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->ENABLED_SPARKS_BITFIELD = unpack_field(data, 0u, 64u, false);
    return true;
}

bool spark_decode_USB_ONLY_ENTER_DFU_BOOTLOADER(const uint8_t* data, uint8_t dlc, Spark_USB_ONLY_ENTER_DFU_BOOTLOADER_t* out) {
    if (!data || !out) return false;
    if (dlc < 2u) return false;
    out->MAGIC_NUMBER = unpack_field(data, 0u, 16u, false);
    return true;
}

bool spark_decode_GET_TEMPERATURES(const uint8_t* data, uint8_t dlc, Spark_GET_TEMPERATURES_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->MOTOR_TEMPERATURE = unpack_field(data, 0u, 8u, false);
    out->MICROCONTROLLER_TEMPERATURE = unpack_field(data, 8u, 8u, false);
    out->FET_TEMPERATURE = unpack_field(data, 16u, 8u, false);
    out->MOTOR_TEMPERATURE_2 = unpack_field(data, 24u, 8u, false);
    out->DOCK_TEMPERATURE = unpack_field(data, 32u, 8u, false);
    out->VALID_TEMPERATURES_BITMASK = unpack_field(data, 56u, 7u, false);
    out->UNUSED = unpack_field(data, 63u, 1u, false);
    return true;
}

bool spark_decode_GET_MOTOR_INTERFACE(const uint8_t* data, uint8_t dlc, Spark_GET_MOTOR_INTERFACE_t* out) {
    if (!data || !out) return false;
    if (dlc < 3u) return false;
    out->MOTOR_INTERFACE = unpack_field(data, 0u, 16u, false);
    out->PRIMARY_SENSOR_TYPE = unpack_field(data, 16u, 8u, false);
    return true;
}

bool spark_decode_GET_PARAMETER_0_TO_15_TYPES(const uint8_t* data, uint8_t dlc, Spark_GET_PARAMETER_0_TO_15_TYPES_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->TYPE_0 = unpack_field(data, 0u, 4u, false);
    out->TYPE_1 = unpack_field(data, 4u, 4u, false);
    out->TYPE_2 = unpack_field(data, 8u, 4u, false);
    out->TYPE_3 = unpack_field(data, 12u, 4u, false);
    out->TYPE_4 = unpack_field(data, 16u, 4u, false);
    out->TYPE_5 = unpack_field(data, 20u, 4u, false);
    out->TYPE_6 = unpack_field(data, 24u, 4u, false);
    out->TYPE_7 = unpack_field(data, 28u, 4u, false);
    out->TYPE_8 = unpack_field(data, 32u, 4u, false);
    out->TYPE_9 = unpack_field(data, 36u, 4u, false);
    out->TYPE_10 = unpack_field(data, 40u, 4u, false);
    out->TYPE_11 = unpack_field(data, 44u, 4u, false);
    out->TYPE_12 = unpack_field(data, 48u, 4u, false);
    out->TYPE_13 = unpack_field(data, 52u, 4u, false);
    out->TYPE_14 = unpack_field(data, 56u, 4u, false);
    out->TYPE_15 = unpack_field(data, 60u, 4u, false);
    return true;
}

bool spark_decode_GET_PARAMETER_16_TO_31_TYPES(const uint8_t* data, uint8_t dlc, Spark_GET_PARAMETER_16_TO_31_TYPES_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->TYPE_0 = unpack_field(data, 0u, 4u, false);
    out->TYPE_1 = unpack_field(data, 4u, 4u, false);
    out->TYPE_2 = unpack_field(data, 8u, 4u, false);
    out->TYPE_3 = unpack_field(data, 12u, 4u, false);
    out->TYPE_4 = unpack_field(data, 16u, 4u, false);
    out->TYPE_5 = unpack_field(data, 20u, 4u, false);
    out->TYPE_6 = unpack_field(data, 24u, 4u, false);
    out->TYPE_7 = unpack_field(data, 28u, 4u, false);
    out->TYPE_8 = unpack_field(data, 32u, 4u, false);
    out->TYPE_9 = unpack_field(data, 36u, 4u, false);
    out->TYPE_10 = unpack_field(data, 40u, 4u, false);
    out->TYPE_11 = unpack_field(data, 44u, 4u, false);
    out->TYPE_12 = unpack_field(data, 48u, 4u, false);
    out->TYPE_13 = unpack_field(data, 52u, 4u, false);
    out->TYPE_14 = unpack_field(data, 56u, 4u, false);
    out->TYPE_15 = unpack_field(data, 60u, 4u, false);
    return true;
}

bool spark_decode_GET_PARAMETER_32_TO_47_TYPES(const uint8_t* data, uint8_t dlc, Spark_GET_PARAMETER_32_TO_47_TYPES_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->TYPE_0 = unpack_field(data, 0u, 4u, false);
    out->TYPE_1 = unpack_field(data, 4u, 4u, false);
    out->TYPE_2 = unpack_field(data, 8u, 4u, false);
    out->TYPE_3 = unpack_field(data, 12u, 4u, false);
    out->TYPE_4 = unpack_field(data, 16u, 4u, false);
    out->TYPE_5 = unpack_field(data, 20u, 4u, false);
    out->TYPE_6 = unpack_field(data, 24u, 4u, false);
    out->TYPE_7 = unpack_field(data, 28u, 4u, false);
    out->TYPE_8 = unpack_field(data, 32u, 4u, false);
    out->TYPE_9 = unpack_field(data, 36u, 4u, false);
    out->TYPE_10 = unpack_field(data, 40u, 4u, false);
    out->TYPE_11 = unpack_field(data, 44u, 4u, false);
    out->TYPE_12 = unpack_field(data, 48u, 4u, false);
    out->TYPE_13 = unpack_field(data, 52u, 4u, false);
    out->TYPE_14 = unpack_field(data, 56u, 4u, false);
    out->TYPE_15 = unpack_field(data, 60u, 4u, false);
    return true;
}

bool spark_decode_GET_PARAMETER_48_TO_63_TYPES(const uint8_t* data, uint8_t dlc, Spark_GET_PARAMETER_48_TO_63_TYPES_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->TYPE_0 = unpack_field(data, 0u, 4u, false);
    out->TYPE_1 = unpack_field(data, 4u, 4u, false);
    out->TYPE_2 = unpack_field(data, 8u, 4u, false);
    out->TYPE_3 = unpack_field(data, 12u, 4u, false);
    out->TYPE_4 = unpack_field(data, 16u, 4u, false);
    out->TYPE_5 = unpack_field(data, 20u, 4u, false);
    out->TYPE_6 = unpack_field(data, 24u, 4u, false);
    out->TYPE_7 = unpack_field(data, 28u, 4u, false);
    out->TYPE_8 = unpack_field(data, 32u, 4u, false);
    out->TYPE_9 = unpack_field(data, 36u, 4u, false);
    out->TYPE_10 = unpack_field(data, 40u, 4u, false);
    out->TYPE_11 = unpack_field(data, 44u, 4u, false);
    out->TYPE_12 = unpack_field(data, 48u, 4u, false);
    out->TYPE_13 = unpack_field(data, 52u, 4u, false);
    out->TYPE_14 = unpack_field(data, 56u, 4u, false);
    out->TYPE_15 = unpack_field(data, 60u, 4u, false);
    return true;
}

bool spark_decode_GET_PARAMETER_64_TO_79_TYPES(const uint8_t* data, uint8_t dlc, Spark_GET_PARAMETER_64_TO_79_TYPES_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->TYPE_0 = unpack_field(data, 0u, 4u, false);
    out->TYPE_1 = unpack_field(data, 4u, 4u, false);
    out->TYPE_2 = unpack_field(data, 8u, 4u, false);
    out->TYPE_3 = unpack_field(data, 12u, 4u, false);
    out->TYPE_4 = unpack_field(data, 16u, 4u, false);
    out->TYPE_5 = unpack_field(data, 20u, 4u, false);
    out->TYPE_6 = unpack_field(data, 24u, 4u, false);
    out->TYPE_7 = unpack_field(data, 28u, 4u, false);
    out->TYPE_8 = unpack_field(data, 32u, 4u, false);
    out->TYPE_9 = unpack_field(data, 36u, 4u, false);
    out->TYPE_10 = unpack_field(data, 40u, 4u, false);
    out->TYPE_11 = unpack_field(data, 44u, 4u, false);
    out->TYPE_12 = unpack_field(data, 48u, 4u, false);
    out->TYPE_13 = unpack_field(data, 52u, 4u, false);
    out->TYPE_14 = unpack_field(data, 56u, 4u, false);
    out->TYPE_15 = unpack_field(data, 60u, 4u, false);
    return true;
}

bool spark_decode_GET_PARAMETER_80_TO_95_TYPES(const uint8_t* data, uint8_t dlc, Spark_GET_PARAMETER_80_TO_95_TYPES_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->TYPE_0 = unpack_field(data, 0u, 4u, false);
    out->TYPE_1 = unpack_field(data, 4u, 4u, false);
    out->TYPE_2 = unpack_field(data, 8u, 4u, false);
    out->TYPE_3 = unpack_field(data, 12u, 4u, false);
    out->TYPE_4 = unpack_field(data, 16u, 4u, false);
    out->TYPE_5 = unpack_field(data, 20u, 4u, false);
    out->TYPE_6 = unpack_field(data, 24u, 4u, false);
    out->TYPE_7 = unpack_field(data, 28u, 4u, false);
    out->TYPE_8 = unpack_field(data, 32u, 4u, false);
    out->TYPE_9 = unpack_field(data, 36u, 4u, false);
    out->TYPE_10 = unpack_field(data, 40u, 4u, false);
    out->TYPE_11 = unpack_field(data, 44u, 4u, false);
    out->TYPE_12 = unpack_field(data, 48u, 4u, false);
    out->TYPE_13 = unpack_field(data, 52u, 4u, false);
    out->TYPE_14 = unpack_field(data, 56u, 4u, false);
    out->TYPE_15 = unpack_field(data, 60u, 4u, false);
    return true;
}

bool spark_decode_GET_PARAMETER_96_TO_111_TYPES(const uint8_t* data, uint8_t dlc, Spark_GET_PARAMETER_96_TO_111_TYPES_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->TYPE_0 = unpack_field(data, 0u, 4u, false);
    out->TYPE_1 = unpack_field(data, 4u, 4u, false);
    out->TYPE_2 = unpack_field(data, 8u, 4u, false);
    out->TYPE_3 = unpack_field(data, 12u, 4u, false);
    out->TYPE_4 = unpack_field(data, 16u, 4u, false);
    out->TYPE_5 = unpack_field(data, 20u, 4u, false);
    out->TYPE_6 = unpack_field(data, 24u, 4u, false);
    out->TYPE_7 = unpack_field(data, 28u, 4u, false);
    out->TYPE_8 = unpack_field(data, 32u, 4u, false);
    out->TYPE_9 = unpack_field(data, 36u, 4u, false);
    out->TYPE_10 = unpack_field(data, 40u, 4u, false);
    out->TYPE_11 = unpack_field(data, 44u, 4u, false);
    out->TYPE_12 = unpack_field(data, 48u, 4u, false);
    out->TYPE_13 = unpack_field(data, 52u, 4u, false);
    out->TYPE_14 = unpack_field(data, 56u, 4u, false);
    out->TYPE_15 = unpack_field(data, 60u, 4u, false);
    return true;
}

bool spark_decode_GET_PARAMETER_112_TO_127_TYPES(const uint8_t* data, uint8_t dlc, Spark_GET_PARAMETER_112_TO_127_TYPES_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->TYPE_0 = unpack_field(data, 0u, 4u, false);
    out->TYPE_1 = unpack_field(data, 4u, 4u, false);
    out->TYPE_2 = unpack_field(data, 8u, 4u, false);
    out->TYPE_3 = unpack_field(data, 12u, 4u, false);
    out->TYPE_4 = unpack_field(data, 16u, 4u, false);
    out->TYPE_5 = unpack_field(data, 20u, 4u, false);
    out->TYPE_6 = unpack_field(data, 24u, 4u, false);
    out->TYPE_7 = unpack_field(data, 28u, 4u, false);
    out->TYPE_8 = unpack_field(data, 32u, 4u, false);
    out->TYPE_9 = unpack_field(data, 36u, 4u, false);
    out->TYPE_10 = unpack_field(data, 40u, 4u, false);
    out->TYPE_11 = unpack_field(data, 44u, 4u, false);
    out->TYPE_12 = unpack_field(data, 48u, 4u, false);
    out->TYPE_13 = unpack_field(data, 52u, 4u, false);
    out->TYPE_14 = unpack_field(data, 56u, 4u, false);
    out->TYPE_15 = unpack_field(data, 60u, 4u, false);
    return true;
}

bool spark_decode_GET_PARAMETER_128_TO_143_TYPES(const uint8_t* data, uint8_t dlc, Spark_GET_PARAMETER_128_TO_143_TYPES_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->TYPE_0 = unpack_field(data, 0u, 4u, false);
    out->TYPE_1 = unpack_field(data, 4u, 4u, false);
    out->TYPE_2 = unpack_field(data, 8u, 4u, false);
    out->TYPE_3 = unpack_field(data, 12u, 4u, false);
    out->TYPE_4 = unpack_field(data, 16u, 4u, false);
    out->TYPE_5 = unpack_field(data, 20u, 4u, false);
    out->TYPE_6 = unpack_field(data, 24u, 4u, false);
    out->TYPE_7 = unpack_field(data, 28u, 4u, false);
    out->TYPE_8 = unpack_field(data, 32u, 4u, false);
    out->TYPE_9 = unpack_field(data, 36u, 4u, false);
    out->TYPE_10 = unpack_field(data, 40u, 4u, false);
    out->TYPE_11 = unpack_field(data, 44u, 4u, false);
    out->TYPE_12 = unpack_field(data, 48u, 4u, false);
    out->TYPE_13 = unpack_field(data, 52u, 4u, false);
    out->TYPE_14 = unpack_field(data, 56u, 4u, false);
    out->TYPE_15 = unpack_field(data, 60u, 4u, false);
    return true;
}

bool spark_decode_GET_PARAMETER_144_TO_159_TYPES(const uint8_t* data, uint8_t dlc, Spark_GET_PARAMETER_144_TO_159_TYPES_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->TYPE_0 = unpack_field(data, 0u, 4u, false);
    out->TYPE_1 = unpack_field(data, 4u, 4u, false);
    out->TYPE_2 = unpack_field(data, 8u, 4u, false);
    out->TYPE_3 = unpack_field(data, 12u, 4u, false);
    out->TYPE_4 = unpack_field(data, 16u, 4u, false);
    out->TYPE_5 = unpack_field(data, 20u, 4u, false);
    out->TYPE_6 = unpack_field(data, 24u, 4u, false);
    out->TYPE_7 = unpack_field(data, 28u, 4u, false);
    out->TYPE_8 = unpack_field(data, 32u, 4u, false);
    out->TYPE_9 = unpack_field(data, 36u, 4u, false);
    out->TYPE_10 = unpack_field(data, 40u, 4u, false);
    out->TYPE_11 = unpack_field(data, 44u, 4u, false);
    out->TYPE_12 = unpack_field(data, 48u, 4u, false);
    out->TYPE_13 = unpack_field(data, 52u, 4u, false);
    out->TYPE_14 = unpack_field(data, 56u, 4u, false);
    out->TYPE_15 = unpack_field(data, 60u, 4u, false);
    return true;
}

bool spark_decode_GET_PARAMETER_160_TO_175_TYPES(const uint8_t* data, uint8_t dlc, Spark_GET_PARAMETER_160_TO_175_TYPES_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->TYPE_0 = unpack_field(data, 0u, 4u, false);
    out->TYPE_1 = unpack_field(data, 4u, 4u, false);
    out->TYPE_2 = unpack_field(data, 8u, 4u, false);
    out->TYPE_3 = unpack_field(data, 12u, 4u, false);
    out->TYPE_4 = unpack_field(data, 16u, 4u, false);
    out->TYPE_5 = unpack_field(data, 20u, 4u, false);
    out->TYPE_6 = unpack_field(data, 24u, 4u, false);
    out->TYPE_7 = unpack_field(data, 28u, 4u, false);
    out->TYPE_8 = unpack_field(data, 32u, 4u, false);
    out->TYPE_9 = unpack_field(data, 36u, 4u, false);
    out->TYPE_10 = unpack_field(data, 40u, 4u, false);
    out->TYPE_11 = unpack_field(data, 44u, 4u, false);
    out->TYPE_12 = unpack_field(data, 48u, 4u, false);
    out->TYPE_13 = unpack_field(data, 52u, 4u, false);
    out->TYPE_14 = unpack_field(data, 56u, 4u, false);
    out->TYPE_15 = unpack_field(data, 60u, 4u, false);
    return true;
}

bool spark_decode_GET_PARAMETER_176_TO_191_TYPES(const uint8_t* data, uint8_t dlc, Spark_GET_PARAMETER_176_TO_191_TYPES_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->TYPE_0 = unpack_field(data, 0u, 4u, false);
    out->TYPE_1 = unpack_field(data, 4u, 4u, false);
    out->TYPE_2 = unpack_field(data, 8u, 4u, false);
    out->TYPE_3 = unpack_field(data, 12u, 4u, false);
    out->TYPE_4 = unpack_field(data, 16u, 4u, false);
    out->TYPE_5 = unpack_field(data, 20u, 4u, false);
    out->TYPE_6 = unpack_field(data, 24u, 4u, false);
    out->TYPE_7 = unpack_field(data, 28u, 4u, false);
    out->TYPE_8 = unpack_field(data, 32u, 4u, false);
    out->TYPE_9 = unpack_field(data, 36u, 4u, false);
    out->TYPE_10 = unpack_field(data, 40u, 4u, false);
    out->TYPE_11 = unpack_field(data, 44u, 4u, false);
    out->TYPE_12 = unpack_field(data, 48u, 4u, false);
    out->TYPE_13 = unpack_field(data, 52u, 4u, false);
    out->TYPE_14 = unpack_field(data, 56u, 4u, false);
    out->TYPE_15 = unpack_field(data, 60u, 4u, false);
    return true;
}

bool spark_decode_GET_PARAMETER_192_TO_207_TYPES(const uint8_t* data, uint8_t dlc, Spark_GET_PARAMETER_192_TO_207_TYPES_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->TYPE_0 = unpack_field(data, 0u, 4u, false);
    out->TYPE_1 = unpack_field(data, 4u, 4u, false);
    out->TYPE_2 = unpack_field(data, 8u, 4u, false);
    out->TYPE_3 = unpack_field(data, 12u, 4u, false);
    out->TYPE_4 = unpack_field(data, 16u, 4u, false);
    out->TYPE_5 = unpack_field(data, 20u, 4u, false);
    out->TYPE_6 = unpack_field(data, 24u, 4u, false);
    out->TYPE_7 = unpack_field(data, 28u, 4u, false);
    out->TYPE_8 = unpack_field(data, 32u, 4u, false);
    out->TYPE_9 = unpack_field(data, 36u, 4u, false);
    out->TYPE_10 = unpack_field(data, 40u, 4u, false);
    out->TYPE_11 = unpack_field(data, 44u, 4u, false);
    out->TYPE_12 = unpack_field(data, 48u, 4u, false);
    out->TYPE_13 = unpack_field(data, 52u, 4u, false);
    out->TYPE_14 = unpack_field(data, 56u, 4u, false);
    out->TYPE_15 = unpack_field(data, 60u, 4u, false);
    return true;
}

bool spark_decode_GET_PARAMETER_208_TO_223_TYPES(const uint8_t* data, uint8_t dlc, Spark_GET_PARAMETER_208_TO_223_TYPES_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->TYPE_0 = unpack_field(data, 0u, 4u, false);
    out->TYPE_1 = unpack_field(data, 4u, 4u, false);
    out->TYPE_2 = unpack_field(data, 8u, 4u, false);
    out->TYPE_3 = unpack_field(data, 12u, 4u, false);
    out->TYPE_4 = unpack_field(data, 16u, 4u, false);
    out->TYPE_5 = unpack_field(data, 20u, 4u, false);
    out->TYPE_6 = unpack_field(data, 24u, 4u, false);
    out->TYPE_7 = unpack_field(data, 28u, 4u, false);
    out->TYPE_8 = unpack_field(data, 32u, 4u, false);
    out->TYPE_9 = unpack_field(data, 36u, 4u, false);
    out->TYPE_10 = unpack_field(data, 40u, 4u, false);
    out->TYPE_11 = unpack_field(data, 44u, 4u, false);
    out->TYPE_12 = unpack_field(data, 48u, 4u, false);
    out->TYPE_13 = unpack_field(data, 52u, 4u, false);
    out->TYPE_14 = unpack_field(data, 56u, 4u, false);
    out->TYPE_15 = unpack_field(data, 60u, 4u, false);
    return true;
}

bool spark_decode_GET_PARAMETER_224_TO_239_TYPES(const uint8_t* data, uint8_t dlc, Spark_GET_PARAMETER_224_TO_239_TYPES_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->TYPE_0 = unpack_field(data, 0u, 4u, false);
    out->TYPE_1 = unpack_field(data, 4u, 4u, false);
    out->TYPE_2 = unpack_field(data, 8u, 4u, false);
    out->TYPE_3 = unpack_field(data, 12u, 4u, false);
    out->TYPE_4 = unpack_field(data, 16u, 4u, false);
    out->TYPE_5 = unpack_field(data, 20u, 4u, false);
    out->TYPE_6 = unpack_field(data, 24u, 4u, false);
    out->TYPE_7 = unpack_field(data, 28u, 4u, false);
    out->TYPE_8 = unpack_field(data, 32u, 4u, false);
    out->TYPE_9 = unpack_field(data, 36u, 4u, false);
    out->TYPE_10 = unpack_field(data, 40u, 4u, false);
    out->TYPE_11 = unpack_field(data, 44u, 4u, false);
    out->TYPE_12 = unpack_field(data, 48u, 4u, false);
    out->TYPE_13 = unpack_field(data, 52u, 4u, false);
    out->TYPE_14 = unpack_field(data, 56u, 4u, false);
    out->TYPE_15 = unpack_field(data, 60u, 4u, false);
    return true;
}

bool spark_decode_GET_PARAMETER_240_TO_255_TYPES(const uint8_t* data, uint8_t dlc, Spark_GET_PARAMETER_240_TO_255_TYPES_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->TYPE_0 = unpack_field(data, 0u, 4u, false);
    out->TYPE_1 = unpack_field(data, 4u, 4u, false);
    out->TYPE_2 = unpack_field(data, 8u, 4u, false);
    out->TYPE_3 = unpack_field(data, 12u, 4u, false);
    out->TYPE_4 = unpack_field(data, 16u, 4u, false);
    out->TYPE_5 = unpack_field(data, 20u, 4u, false);
    out->TYPE_6 = unpack_field(data, 24u, 4u, false);
    out->TYPE_7 = unpack_field(data, 28u, 4u, false);
    out->TYPE_8 = unpack_field(data, 32u, 4u, false);
    out->TYPE_9 = unpack_field(data, 36u, 4u, false);
    out->TYPE_10 = unpack_field(data, 40u, 4u, false);
    out->TYPE_11 = unpack_field(data, 44u, 4u, false);
    out->TYPE_12 = unpack_field(data, 48u, 4u, false);
    out->TYPE_13 = unpack_field(data, 52u, 4u, false);
    out->TYPE_14 = unpack_field(data, 56u, 4u, false);
    out->TYPE_15 = unpack_field(data, 60u, 4u, false);
    return true;
}

bool spark_decode_PARAMETER_WRITE(const uint8_t* data, uint8_t dlc, Spark_PARAMETER_WRITE_t* out) {
    if (!data || !out) return false;
    if (dlc < 5u) return false;
    out->PARAMETER_ID = unpack_field(data, 0u, 8u, false);
    out->VALUE = unpack_field(data, 8u, 32u, false);
    return true;
}

bool spark_decode_PARAMETER_WRITE_RESPONSE(const uint8_t* data, uint8_t dlc, Spark_PARAMETER_WRITE_RESPONSE_t* out) {
    if (!data || !out) return false;
    if (dlc < 7u) return false;
    out->PARAMETER_ID = unpack_field(data, 0u, 8u, false);
    out->PARAMETER_TYPE = unpack_field(data, 8u, 8u, false);
    out->VALUE = unpack_field(data, 16u, 32u, false);
    out->RESULT_CODE = unpack_field(data, 48u, 8u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_0_AND_1(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_0_AND_1_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_2_AND_3(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_2_AND_3_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_4_AND_5(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_4_AND_5_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_6_AND_7(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_6_AND_7_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_8_AND_9(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_8_AND_9_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_10_AND_11(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_10_AND_11_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_12_AND_13(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_12_AND_13_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_14_AND_15(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_14_AND_15_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_16_AND_17(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_16_AND_17_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_18_AND_19(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_18_AND_19_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_20_AND_21(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_20_AND_21_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_22_AND_23(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_22_AND_23_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_24_AND_25(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_24_AND_25_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_26_AND_27(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_26_AND_27_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_28_AND_29(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_28_AND_29_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_30_AND_31(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_30_AND_31_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_32_AND_33(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_32_AND_33_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_34_AND_35(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_34_AND_35_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_36_AND_37(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_36_AND_37_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_38_AND_39(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_38_AND_39_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_40_AND_41(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_40_AND_41_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_42_AND_43(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_42_AND_43_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_44_AND_45(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_44_AND_45_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_46_AND_47(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_46_AND_47_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_48_AND_49(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_48_AND_49_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_50_AND_51(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_50_AND_51_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_52_AND_53(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_52_AND_53_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_54_AND_55(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_54_AND_55_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_56_AND_57(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_56_AND_57_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_58_AND_59(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_58_AND_59_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_60_AND_61(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_60_AND_61_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_62_AND_63(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_62_AND_63_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_64_AND_65(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_64_AND_65_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_66_AND_67(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_66_AND_67_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_68_AND_69(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_68_AND_69_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_70_AND_71(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_70_AND_71_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_72_AND_73(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_72_AND_73_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_74_AND_75(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_74_AND_75_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_76_AND_77(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_76_AND_77_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_78_AND_79(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_78_AND_79_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_80_AND_81(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_80_AND_81_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_82_AND_83(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_82_AND_83_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_84_AND_85(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_84_AND_85_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_86_AND_87(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_86_AND_87_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_88_AND_89(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_88_AND_89_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_90_AND_91(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_90_AND_91_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_92_AND_93(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_92_AND_93_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_94_AND_95(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_94_AND_95_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_96_AND_97(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_96_AND_97_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_98_AND_99(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_98_AND_99_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_100_AND_101(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_100_AND_101_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_102_AND_103(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_102_AND_103_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_104_AND_105(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_104_AND_105_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_106_AND_107(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_106_AND_107_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_108_AND_109(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_108_AND_109_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_110_AND_111(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_110_AND_111_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_112_AND_113(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_112_AND_113_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_114_AND_115(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_114_AND_115_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_116_AND_117(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_116_AND_117_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_118_AND_119(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_118_AND_119_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_120_AND_121(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_120_AND_121_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_122_AND_123(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_122_AND_123_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_124_AND_125(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_124_AND_125_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_126_AND_127(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_126_AND_127_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_128_AND_129(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_128_AND_129_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_130_AND_131(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_130_AND_131_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_132_AND_133(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_132_AND_133_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_134_AND_135(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_134_AND_135_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_136_AND_137(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_136_AND_137_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_138_AND_139(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_138_AND_139_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_140_AND_141(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_140_AND_141_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_142_AND_143(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_142_AND_143_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_144_AND_145(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_144_AND_145_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_146_AND_147(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_146_AND_147_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_148_AND_149(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_148_AND_149_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_150_AND_151(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_150_AND_151_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_152_AND_153(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_152_AND_153_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_154_AND_155(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_154_AND_155_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_156_AND_157(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_156_AND_157_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_158_AND_159(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_158_AND_159_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_160_AND_161(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_160_AND_161_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_162_AND_163(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_162_AND_163_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_164_AND_165(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_164_AND_165_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_166_AND_167(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_166_AND_167_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_168_AND_169(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_168_AND_169_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_170_AND_171(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_170_AND_171_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_172_AND_173(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_172_AND_173_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_174_AND_175(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_174_AND_175_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_176_AND_177(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_176_AND_177_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_178_AND_179(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_178_AND_179_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_180_AND_181(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_180_AND_181_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_182_AND_183(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_182_AND_183_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_184_AND_185(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_184_AND_185_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_186_AND_187(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_186_AND_187_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_188_AND_189(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_188_AND_189_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_190_AND_191(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_190_AND_191_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_192_AND_193(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_192_AND_193_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_194_AND_195(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_194_AND_195_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_196_AND_197(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_196_AND_197_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_198_AND_199(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_198_AND_199_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_200_AND_201(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_200_AND_201_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_202_AND_203(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_202_AND_203_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_204_AND_205(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_204_AND_205_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_206_AND_207(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_206_AND_207_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_208_AND_209(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_208_AND_209_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_210_AND_211(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_210_AND_211_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_212_AND_213(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_212_AND_213_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_214_AND_215(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_214_AND_215_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_216_AND_217(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_216_AND_217_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_218_AND_219(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_218_AND_219_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_220_AND_221(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_220_AND_221_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_222_AND_223(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_222_AND_223_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_224_AND_225(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_224_AND_225_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_226_AND_227(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_226_AND_227_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_228_AND_229(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_228_AND_229_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_230_AND_231(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_230_AND_231_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_232_AND_233(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_232_AND_233_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_234_AND_235(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_234_AND_235_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_236_AND_237(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_236_AND_237_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_238_AND_239(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_238_AND_239_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_240_AND_241(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_240_AND_241_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_242_AND_243(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_242_AND_243_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_244_AND_245(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_244_AND_245_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_246_AND_247(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_246_AND_247_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_248_AND_249(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_248_AND_249_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_250_AND_251(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_250_AND_251_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_252_AND_253(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_252_AND_253_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_READ_PARAMETER_254_AND_255(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_254_AND_255_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_0_AND_1(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_0_AND_1_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_2_AND_3(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_2_AND_3_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_4_AND_5(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_4_AND_5_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_6_AND_7(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_6_AND_7_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_8_AND_9(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_8_AND_9_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_10_AND_11(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_10_AND_11_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_12_AND_13(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_12_AND_13_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_14_AND_15(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_14_AND_15_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_16_AND_17(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_16_AND_17_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_18_AND_19(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_18_AND_19_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_20_AND_21(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_20_AND_21_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_22_AND_23(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_22_AND_23_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_24_AND_25(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_24_AND_25_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_26_AND_27(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_26_AND_27_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_28_AND_29(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_28_AND_29_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_30_AND_31(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_30_AND_31_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_32_AND_33(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_32_AND_33_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_34_AND_35(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_34_AND_35_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_36_AND_37(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_36_AND_37_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_38_AND_39(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_38_AND_39_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_40_AND_41(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_40_AND_41_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_42_AND_43(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_42_AND_43_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_44_AND_45(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_44_AND_45_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_46_AND_47(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_46_AND_47_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_48_AND_49(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_48_AND_49_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_50_AND_51(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_50_AND_51_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_52_AND_53(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_52_AND_53_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_54_AND_55(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_54_AND_55_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_56_AND_57(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_56_AND_57_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_58_AND_59(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_58_AND_59_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_60_AND_61(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_60_AND_61_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_62_AND_63(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_62_AND_63_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_64_AND_65(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_64_AND_65_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_66_AND_67(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_66_AND_67_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_68_AND_69(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_68_AND_69_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_70_AND_71(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_70_AND_71_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_72_AND_73(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_72_AND_73_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_74_AND_75(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_74_AND_75_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_76_AND_77(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_76_AND_77_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_78_AND_79(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_78_AND_79_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_80_AND_81(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_80_AND_81_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_82_AND_83(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_82_AND_83_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_84_AND_85(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_84_AND_85_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_86_AND_87(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_86_AND_87_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_88_AND_89(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_88_AND_89_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_90_AND_91(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_90_AND_91_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_92_AND_93(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_92_AND_93_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_94_AND_95(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_94_AND_95_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_96_AND_97(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_96_AND_97_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_98_AND_99(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_98_AND_99_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_100_AND_101(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_100_AND_101_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_102_AND_103(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_102_AND_103_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_104_AND_105(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_104_AND_105_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_106_AND_107(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_106_AND_107_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_108_AND_109(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_108_AND_109_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_110_AND_111(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_110_AND_111_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_112_AND_113(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_112_AND_113_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_114_AND_115(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_114_AND_115_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_116_AND_117(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_116_AND_117_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_118_AND_119(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_118_AND_119_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_120_AND_121(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_120_AND_121_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_122_AND_123(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_122_AND_123_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_124_AND_125(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_124_AND_125_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_126_AND_127(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_126_AND_127_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_128_AND_129(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_128_AND_129_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_130_AND_131(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_130_AND_131_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_132_AND_133(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_132_AND_133_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_134_AND_135(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_134_AND_135_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_136_AND_137(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_136_AND_137_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_138_AND_139(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_138_AND_139_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_140_AND_141(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_140_AND_141_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_142_AND_143(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_142_AND_143_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_144_AND_145(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_144_AND_145_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_146_AND_147(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_146_AND_147_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_148_AND_149(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_148_AND_149_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_150_AND_151(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_150_AND_151_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_152_AND_153(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_152_AND_153_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_154_AND_155(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_154_AND_155_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_156_AND_157(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_156_AND_157_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_158_AND_159(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_158_AND_159_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_160_AND_161(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_160_AND_161_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_162_AND_163(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_162_AND_163_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_164_AND_165(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_164_AND_165_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_166_AND_167(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_166_AND_167_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_168_AND_169(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_168_AND_169_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_170_AND_171(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_170_AND_171_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_172_AND_173(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_172_AND_173_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_174_AND_175(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_174_AND_175_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_176_AND_177(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_176_AND_177_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_178_AND_179(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_178_AND_179_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_180_AND_181(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_180_AND_181_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_182_AND_183(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_182_AND_183_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_184_AND_185(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_184_AND_185_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_186_AND_187(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_186_AND_187_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_188_AND_189(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_188_AND_189_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_190_AND_191(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_190_AND_191_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_192_AND_193(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_192_AND_193_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_194_AND_195(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_194_AND_195_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_196_AND_197(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_196_AND_197_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_198_AND_199(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_198_AND_199_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_200_AND_201(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_200_AND_201_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_202_AND_203(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_202_AND_203_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_204_AND_205(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_204_AND_205_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_206_AND_207(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_206_AND_207_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_208_AND_209(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_208_AND_209_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_210_AND_211(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_210_AND_211_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_212_AND_213(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_212_AND_213_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_214_AND_215(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_214_AND_215_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_216_AND_217(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_216_AND_217_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_218_AND_219(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_218_AND_219_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_220_AND_221(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_220_AND_221_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_222_AND_223(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_222_AND_223_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_224_AND_225(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_224_AND_225_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_226_AND_227(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_226_AND_227_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_228_AND_229(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_228_AND_229_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_230_AND_231(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_230_AND_231_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_232_AND_233(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_232_AND_233_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_234_AND_235(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_234_AND_235_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_236_AND_237(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_236_AND_237_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_238_AND_239(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_238_AND_239_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_240_AND_241(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_240_AND_241_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_242_AND_243(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_242_AND_243_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_244_AND_245(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_244_AND_245_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_246_AND_247(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_246_AND_247_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_248_AND_249(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_248_AND_249_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_250_AND_251(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_250_AND_251_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_252_AND_253(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_252_AND_253_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_WRITE_PARAMETER_254_AND_255(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_254_AND_255_t* out) {
    if (!data || !out) return false;
    if (dlc < 8u) return false;
    out->FIRST_PARAMETER_VALUE = unpack_field(data, 0u, 32u, false);
    out->SECOND_PARAMETER_VALUE = unpack_field(data, 32u, 32u, false);
    return true;
}

bool spark_decode_START_FOLLOWER_MODE_RESPONSE(const uint8_t* data, uint8_t dlc, Spark_START_FOLLOWER_MODE_RESPONSE_t* out) {
    if (!data || !out) return false;
    if (dlc < 1u) return false;
    out->STATUS = unpack_field(data, 0u, 8u, false);
    return true;
}

bool spark_decode_PERSIST_PARAMETERS(const uint8_t* data, uint8_t dlc, Spark_PERSIST_PARAMETERS_t* out) {
    if (!data || !out) return false;
    if (dlc < 2u) return false;
    out->MAGIC_NUMBER = unpack_field(data, 0u, 16u, false);
    return true;
}

} // namespace CanControl::SparkMax

