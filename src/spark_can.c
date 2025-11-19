// AUTO-GENERATED FILE. DO NOT EDIT. See gen.py
#include "spark_can.h"
#include <string.h>

static inline void _set_bit(uint8_t* buf, uint32_t bit_index, uint8_t bit) {
    uint32_t byte_index = bit_index >> 3;
    uint8_t bit_offset = bit_index & 7u;
    if (bit) buf[byte_index] |= (uint8_t)(1u << bit_offset); else buf[byte_index] &= (uint8_t)~(1u << bit_offset);
}

static void _pack_field(uint8_t* buf, uint32_t bit_pos, uint32_t bit_len, uint64_t raw, bool big_endian) {
    for (uint32_t i = 0; i < bit_len; ++i) {
        uint32_t src_bit = big_endian ? (bit_len - 1u - i) : i;
        uint8_t b = (uint8_t)((raw >> src_bit) & 1u);
        _set_bit(buf, bit_pos + i, b);
    }
}

void spark_build_VELOCITY_SETPOINT(uint8_t device_id, const Spark_VELOCITY_SETPOINT_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33882112u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    union { float f; uint32_t u; } _SETPOINT = { .f = values ? values->SETPOINT : 0.0f };
    _pack_field(out->data, 0u, 32u, (uint64_t)_SETPOINT.u, false);
    int64_t _ARBITRARY_FEEDFORWARD_s = values ? (int64_t)values->ARBITRARY_FEEDFORWARD : 0;
    uint64_t _ARBITRARY_FEEDFORWARD = (uint64_t)_ARBITRARY_FEEDFORWARD_s & (((1ull<<16)-1ull));
    _pack_field(out->data, 32u, 16u, _ARBITRARY_FEEDFORWARD, false);
    uint64_t _PID_SLOT = values ? (uint64_t)values->PID_SLOT : 0ull;
    _pack_field(out->data, 48u, 2u, _PID_SLOT, false);
    uint64_t _ARBITRARY_FEEDFORWARD_UNITS = values ? (uint64_t)values->ARBITRARY_FEEDFORWARD_UNITS : 0ull;
    _pack_field(out->data, 50u, 1u, _ARBITRARY_FEEDFORWARD_UNITS, false);
}

void spark_build_DUTY_CYCLE_SETPOINT(uint8_t device_id, const Spark_DUTY_CYCLE_SETPOINT_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33882240u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    union { float f; uint32_t u; } _SETPOINT = { .f = values ? values->SETPOINT : 0.0f };
    _pack_field(out->data, 0u, 32u, (uint64_t)_SETPOINT.u, false);
    int64_t _ARBITRARY_FEEDFORWARD_s = values ? (int64_t)values->ARBITRARY_FEEDFORWARD : 0;
    uint64_t _ARBITRARY_FEEDFORWARD = (uint64_t)_ARBITRARY_FEEDFORWARD_s & (((1ull<<16)-1ull));
    _pack_field(out->data, 32u, 16u, _ARBITRARY_FEEDFORWARD, false);
    uint64_t _PID_SLOT = values ? (uint64_t)values->PID_SLOT : 0ull;
    _pack_field(out->data, 48u, 2u, _PID_SLOT, false);
    uint64_t _ARBITRARY_FEEDFORWARD_UNITS = values ? (uint64_t)values->ARBITRARY_FEEDFORWARD_UNITS : 0ull;
    _pack_field(out->data, 50u, 1u, _ARBITRARY_FEEDFORWARD_UNITS, false);
}

void spark_build_SMART_VELOCITY_SETPOINT(uint8_t device_id, const Spark_SMART_VELOCITY_SETPOINT_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33882304u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    union { float f; uint32_t u; } _SETPOINT = { .f = values ? values->SETPOINT : 0.0f };
    _pack_field(out->data, 0u, 32u, (uint64_t)_SETPOINT.u, false);
    int64_t _ARBITRARY_FEEDFORWARD_s = values ? (int64_t)values->ARBITRARY_FEEDFORWARD : 0;
    uint64_t _ARBITRARY_FEEDFORWARD = (uint64_t)_ARBITRARY_FEEDFORWARD_s & (((1ull<<16)-1ull));
    _pack_field(out->data, 32u, 16u, _ARBITRARY_FEEDFORWARD, false);
    uint64_t _PID_SLOT = values ? (uint64_t)values->PID_SLOT : 0ull;
    _pack_field(out->data, 48u, 2u, _PID_SLOT, false);
    uint64_t _ARBITRARY_FEEDFORWARD_UNITS = values ? (uint64_t)values->ARBITRARY_FEEDFORWARD_UNITS : 0ull;
    _pack_field(out->data, 50u, 1u, _ARBITRARY_FEEDFORWARD_UNITS, false);
}

void spark_build_POSITION_SETPOINT(uint8_t device_id, const Spark_POSITION_SETPOINT_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33882368u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    union { float f; uint32_t u; } _SETPOINT = { .f = values ? values->SETPOINT : 0.0f };
    _pack_field(out->data, 0u, 32u, (uint64_t)_SETPOINT.u, false);
    int64_t _ARBITRARY_FEEDFORWARD_s = values ? (int64_t)values->ARBITRARY_FEEDFORWARD : 0;
    uint64_t _ARBITRARY_FEEDFORWARD = (uint64_t)_ARBITRARY_FEEDFORWARD_s & (((1ull<<16)-1ull));
    _pack_field(out->data, 32u, 16u, _ARBITRARY_FEEDFORWARD, false);
    uint64_t _PID_SLOT = values ? (uint64_t)values->PID_SLOT : 0ull;
    _pack_field(out->data, 48u, 2u, _PID_SLOT, false);
    uint64_t _ARBITRARY_FEEDFORWARD_UNITS = values ? (uint64_t)values->ARBITRARY_FEEDFORWARD_UNITS : 0ull;
    _pack_field(out->data, 50u, 1u, _ARBITRARY_FEEDFORWARD_UNITS, false);
}

void spark_build_VOLTAGE_SETPOINT(uint8_t device_id, const Spark_VOLTAGE_SETPOINT_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33882432u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    union { float f; uint32_t u; } _SETPOINT = { .f = values ? values->SETPOINT : 0.0f };
    _pack_field(out->data, 0u, 32u, (uint64_t)_SETPOINT.u, false);
    int64_t _ARBITRARY_FEEDFORWARD_s = values ? (int64_t)values->ARBITRARY_FEEDFORWARD : 0;
    uint64_t _ARBITRARY_FEEDFORWARD = (uint64_t)_ARBITRARY_FEEDFORWARD_s & (((1ull<<16)-1ull));
    _pack_field(out->data, 32u, 16u, _ARBITRARY_FEEDFORWARD, false);
    uint64_t _PID_SLOT = values ? (uint64_t)values->PID_SLOT : 0ull;
    _pack_field(out->data, 48u, 2u, _PID_SLOT, false);
    uint64_t _ARBITRARY_FEEDFORWARD_UNITS = values ? (uint64_t)values->ARBITRARY_FEEDFORWARD_UNITS : 0ull;
    _pack_field(out->data, 50u, 1u, _ARBITRARY_FEEDFORWARD_UNITS, false);
}

void spark_build_CURRENT_SETPOINT(uint8_t device_id, const Spark_CURRENT_SETPOINT_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33882496u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    union { float f; uint32_t u; } _SETPOINT = { .f = values ? values->SETPOINT : 0.0f };
    _pack_field(out->data, 0u, 32u, (uint64_t)_SETPOINT.u, false);
    int64_t _ARBITRARY_FEEDFORWARD_s = values ? (int64_t)values->ARBITRARY_FEEDFORWARD : 0;
    uint64_t _ARBITRARY_FEEDFORWARD = (uint64_t)_ARBITRARY_FEEDFORWARD_s & (((1ull<<16)-1ull));
    _pack_field(out->data, 32u, 16u, _ARBITRARY_FEEDFORWARD, false);
    uint64_t _PID_SLOT = values ? (uint64_t)values->PID_SLOT : 0ull;
    _pack_field(out->data, 48u, 2u, _PID_SLOT, false);
    uint64_t _ARBITRARY_FEEDFORWARD_UNITS = values ? (uint64_t)values->ARBITRARY_FEEDFORWARD_UNITS : 0ull;
    _pack_field(out->data, 50u, 1u, _ARBITRARY_FEEDFORWARD_UNITS, false);
}

void spark_build_SMART_MOTION_SETPOINT(uint8_t device_id, const Spark_SMART_MOTION_SETPOINT_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33882560u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    union { float f; uint32_t u; } _SETPOINT = { .f = values ? values->SETPOINT : 0.0f };
    _pack_field(out->data, 0u, 32u, (uint64_t)_SETPOINT.u, false);
    int64_t _ARBITRARY_FEEDFORWARD_s = values ? (int64_t)values->ARBITRARY_FEEDFORWARD : 0;
    uint64_t _ARBITRARY_FEEDFORWARD = (uint64_t)_ARBITRARY_FEEDFORWARD_s & (((1ull<<16)-1ull));
    _pack_field(out->data, 32u, 16u, _ARBITRARY_FEEDFORWARD, false);
    uint64_t _PID_SLOT = values ? (uint64_t)values->PID_SLOT : 0ull;
    _pack_field(out->data, 48u, 2u, _PID_SLOT, false);
    uint64_t _ARBITRARY_FEEDFORWARD_UNITS = values ? (uint64_t)values->ARBITRARY_FEEDFORWARD_UNITS : 0ull;
    _pack_field(out->data, 50u, 1u, _ARBITRARY_FEEDFORWARD_UNITS, false);
}

void spark_build_MAXMOTION_POSITION_SETPOINT(uint8_t device_id, const Spark_MAXMOTION_POSITION_SETPOINT_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33882624u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    union { float f; uint32_t u; } _SETPOINT = { .f = values ? values->SETPOINT : 0.0f };
    _pack_field(out->data, 0u, 32u, (uint64_t)_SETPOINT.u, false);
    int64_t _ARBITRARY_FEEDFORWARD_s = values ? (int64_t)values->ARBITRARY_FEEDFORWARD : 0;
    uint64_t _ARBITRARY_FEEDFORWARD = (uint64_t)_ARBITRARY_FEEDFORWARD_s & (((1ull<<16)-1ull));
    _pack_field(out->data, 32u, 16u, _ARBITRARY_FEEDFORWARD, false);
    uint64_t _PID_SLOT = values ? (uint64_t)values->PID_SLOT : 0ull;
    _pack_field(out->data, 48u, 2u, _PID_SLOT, false);
    uint64_t _ARBITRARY_FEEDFORWARD_UNITS = values ? (uint64_t)values->ARBITRARY_FEEDFORWARD_UNITS : 0ull;
    _pack_field(out->data, 50u, 1u, _ARBITRARY_FEEDFORWARD_UNITS, false);
}

void spark_build_MAXMOTION_VELOCITY_SETPOINT(uint8_t device_id, const Spark_MAXMOTION_VELOCITY_SETPOINT_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33882688u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    union { float f; uint32_t u; } _SETPOINT = { .f = values ? values->SETPOINT : 0.0f };
    _pack_field(out->data, 0u, 32u, (uint64_t)_SETPOINT.u, false);
    int64_t _ARBITRARY_FEEDFORWARD_s = values ? (int64_t)values->ARBITRARY_FEEDFORWARD : 0;
    uint64_t _ARBITRARY_FEEDFORWARD = (uint64_t)_ARBITRARY_FEEDFORWARD_s & (((1ull<<16)-1ull));
    _pack_field(out->data, 32u, 16u, _ARBITRARY_FEEDFORWARD, false);
    uint64_t _PID_SLOT = values ? (uint64_t)values->PID_SLOT : 0ull;
    _pack_field(out->data, 48u, 2u, _PID_SLOT, false);
    uint64_t _ARBITRARY_FEEDFORWARD_UNITS = values ? (uint64_t)values->ARBITRARY_FEEDFORWARD_UNITS : 0ull;
    _pack_field(out->data, 50u, 1u, _ARBITRARY_FEEDFORWARD_UNITS, false);
}

void spark_build_SET_STATUSES_ENABLED(uint8_t device_id, const Spark_SET_STATUSES_ENABLED_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33883136u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 4u;
    out->is_rtr = false;
    memset(out->data, 0, 4);
    uint64_t _MASK = values ? (uint64_t)values->MASK : 0ull;
    _pack_field(out->data, 0u, 16u, _MASK, false);
    uint64_t _ENABLED_BITFIELD = values ? (uint64_t)values->ENABLED_BITFIELD : 0ull;
    _pack_field(out->data, 16u, 16u, _ENABLED_BITFIELD, false);
}

void spark_build_SET_STATUSES_ENABLED_RESPONSE(uint8_t device_id, const Spark_SET_STATUSES_ENABLED_RESPONSE_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33883200u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 5u;
    out->is_rtr = false;
    memset(out->data, 0, 5);
    uint64_t _RESULT_CODE = values ? (uint64_t)values->RESULT_CODE : 0ull;
    _pack_field(out->data, 0u, 8u, _RESULT_CODE, false);
    uint64_t _SPECIFIED_MASK = values ? (uint64_t)values->SPECIFIED_MASK : 0ull;
    _pack_field(out->data, 8u, 16u, _SPECIFIED_MASK, false);
    uint64_t _ENABLED_BITFIELD = values ? (uint64_t)values->ENABLED_BITFIELD : 0ull;
    _pack_field(out->data, 24u, 16u, _ENABLED_BITFIELD, false);
}

void spark_build_PERSIST_PARAMETERS_RESPONSE(uint8_t device_id, const Spark_PERSIST_PARAMETERS_RESPONSE_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33883392u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 1u;
    out->is_rtr = false;
    memset(out->data, 0, 1);
    uint64_t _RESULT_CODE = values ? (uint64_t)values->RESULT_CODE : 0ull;
    _pack_field(out->data, 0u, 8u, _RESULT_CODE, false);
}

void spark_build_RESET_SAFE_PARAMETERS(uint8_t device_id, const Spark_RESET_SAFE_PARAMETERS_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33883456u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 2u;
    out->is_rtr = false;
    memset(out->data, 0, 2);
    uint64_t _MAGIC_NUMBER = values ? (uint64_t)values->MAGIC_NUMBER : 0ull;
    _pack_field(out->data, 0u, 16u, _MAGIC_NUMBER, false);
}

void spark_build_RESET_SAFE_PARAMETERS_RESPONSE(uint8_t device_id, const Spark_RESET_SAFE_PARAMETERS_RESPONSE_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33883520u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 1u;
    out->is_rtr = false;
    memset(out->data, 0, 1);
    uint64_t _RESULT_CODE = values ? (uint64_t)values->RESULT_CODE : 0ull;
    _pack_field(out->data, 0u, 8u, _RESULT_CODE, false);
}

void spark_build_COMPLETE_FACTORY_RESET(uint8_t device_id, const Spark_COMPLETE_FACTORY_RESET_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33883584u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 2u;
    out->is_rtr = false;
    memset(out->data, 0, 2);
    uint64_t _MAGIC_NUMBER = values ? (uint64_t)values->MAGIC_NUMBER : 0ull;
    _pack_field(out->data, 0u, 16u, _MAGIC_NUMBER, false);
}

void spark_build_COMPLETE_FACTORY_RESET_RESPONSE(uint8_t device_id, const Spark_COMPLETE_FACTORY_RESET_RESPONSE_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33883648u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 1u;
    out->is_rtr = false;
    memset(out->data, 0, 1);
    uint64_t _RESULT_CODE = values ? (uint64_t)values->RESULT_CODE : 0ull;
    _pack_field(out->data, 0u, 8u, _RESULT_CODE, false);
}

void spark_build_CLEAR_FAULTS(uint8_t device_id, const Spark_CLEAR_FAULTS_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33889152u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 0u;
    out->is_rtr = false;
}

void spark_build_IDENTIFY_UNIQUE_SPARK(uint8_t device_id, const Spark_IDENTIFY_UNIQUE_SPARK_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33889664u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 4u;
    out->is_rtr = false;
    memset(out->data, 0, 4);
    uint64_t _UNIQUE_ID = values ? (uint64_t)values->UNIQUE_ID : 0ull;
    _pack_field(out->data, 0u, 32u, _UNIQUE_ID, false);
}

void spark_build_IDENTIFY(uint8_t device_id, const Spark_IDENTIFY_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33889728u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 0u;
    out->is_rtr = false;
}

void spark_build_NACK(uint8_t device_id, const Spark_NACK_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33890304u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 0u;
    out->is_rtr = false;
}

void spark_build_ACK(uint8_t device_id, const Spark_ACK_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33890368u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 0u;
    out->is_rtr = false;
}

void spark_build_LED_SYNC(uint8_t device_id, const Spark_LED_SYNC_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33891520u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 0u;
    out->is_rtr = false;
}

void spark_build_SET_CAN_ID(uint8_t device_id, const Spark_SET_CAN_ID_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33891648u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 5u;
    out->is_rtr = false;
    memset(out->data, 0, 5);
    uint64_t _UNIQUE_ID = values ? (uint64_t)values->UNIQUE_ID : 0ull;
    _pack_field(out->data, 0u, 32u, _UNIQUE_ID, false);
    uint64_t _CAN_ID = values ? (uint64_t)values->CAN_ID : 0ull;
    _pack_field(out->data, 32u, 8u, _CAN_ID, false);
}

void spark_build_GET_FIRMWARE_VERSION(uint8_t device_id, const Spark_GET_FIRMWARE_VERSION_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33891840u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_SWDL_DATA(uint8_t device_id, const Spark_SWDL_DATA_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33892096u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _DATA = values ? (uint64_t)values->DATA : 0ull;
    _pack_field(out->data, 0u, 64u, _DATA, false);
}

void spark_build_SWDL_CHECKSUM(uint8_t device_id, const Spark_SWDL_CHECKSUM_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33892160u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _CHECKSUM = values ? (uint64_t)values->CHECKSUM : 0ull;
    _pack_field(out->data, 0u, 64u, _CHECKSUM, false);
}

void spark_build_SWDL_RETRANSMIT(uint8_t device_id, const Spark_SWDL_RETRANSMIT_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33892224u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 0u;
    out->is_rtr = false;
}

void spark_build_SET_PRIMARY_ENCODER_POSITION(uint8_t device_id, const Spark_SET_PRIMARY_ENCODER_POSITION_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33892352u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 5u;
    out->is_rtr = false;
    memset(out->data, 0, 5);
    union { float f; uint32_t u; } _POSITION = { .f = values ? values->POSITION : 0.0f };
    _pack_field(out->data, 0u, 32u, (uint64_t)_POSITION.u, false);
    uint64_t _DATA_TYPE = values ? (uint64_t)values->DATA_TYPE : 0ull;
    _pack_field(out->data, 32u, 8u, _DATA_TYPE, false);
}

void spark_build_SET_I_ACCUMULATION(uint8_t device_id, const Spark_SET_I_ACCUMULATION_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33892480u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 5u;
    out->is_rtr = false;
    memset(out->data, 0, 5);
    union { float f; uint32_t u; } _I_ACCUMULATION = { .f = values ? values->I_ACCUMULATION : 0.0f };
    _pack_field(out->data, 0u, 32u, (uint64_t)_I_ACCUMULATION.u, false);
    uint64_t _DATA_TYPE = values ? (uint64_t)values->DATA_TYPE : 0ull;
    _pack_field(out->data, 32u, 8u, _DATA_TYPE, false);
}

void spark_build_SET_ANALOG_POSITION(uint8_t device_id, const Spark_SET_ANALOG_POSITION_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33892544u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 5u;
    out->is_rtr = false;
    memset(out->data, 0, 5);
    union { float f; uint32_t u; } _POSITION = { .f = values ? values->POSITION : 0.0f };
    _pack_field(out->data, 0u, 32u, (uint64_t)_POSITION.u, false);
    uint64_t _DATA_TYPE = values ? (uint64_t)values->DATA_TYPE : 0ull;
    _pack_field(out->data, 32u, 8u, _DATA_TYPE, false);
}

void spark_build_SET_EXT_OR_ALT_ENCODER_POSITION(uint8_t device_id, const Spark_SET_EXT_OR_ALT_ENCODER_POSITION_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33892608u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 5u;
    out->is_rtr = false;
    memset(out->data, 0, 5);
    union { float f; uint32_t u; } _POSITION = { .f = values ? values->POSITION : 0.0f };
    _pack_field(out->data, 0u, 32u, (uint64_t)_POSITION.u, false);
    uint64_t _DATA_TYPE = values ? (uint64_t)values->DATA_TYPE : 0ull;
    _pack_field(out->data, 32u, 8u, _DATA_TYPE, false);
}

void spark_build_SET_DUTY_CYCLE_POSITION(uint8_t device_id, const Spark_SET_DUTY_CYCLE_POSITION_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33892672u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 5u;
    out->is_rtr = false;
    memset(out->data, 0, 5);
    union { float f; uint32_t u; } _POSITION = { .f = values ? values->POSITION : 0.0f };
    _pack_field(out->data, 0u, 32u, (uint64_t)_POSITION.u, false);
    uint64_t _DATA_TYPE = values ? (uint64_t)values->DATA_TYPE : 0ull;
    _pack_field(out->data, 32u, 8u, _DATA_TYPE, false);
}

void spark_build_SECONDARY_HEARTBEAT(uint8_t device_id, const Spark_SECONDARY_HEARTBEAT_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33893504u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _ENABLED_SPARKS_BITFIELD = values ? (uint64_t)values->ENABLED_SPARKS_BITFIELD : 0ull;
    _pack_field(out->data, 0u, 64u, _ENABLED_SPARKS_BITFIELD, false);
}

void spark_build_USB_ONLY_IDENTIFY(uint8_t device_id, const Spark_USB_ONLY_IDENTIFY_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33893568u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 0u;
    out->is_rtr = true;
}

void spark_build_USB_ONLY_ENTER_DFU_BOOTLOADER(uint8_t device_id, const Spark_USB_ONLY_ENTER_DFU_BOOTLOADER_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33893632u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 2u;
    out->is_rtr = false;
    memset(out->data, 0, 2);
    uint64_t _MAGIC_NUMBER = values ? (uint64_t)values->MAGIC_NUMBER : 0ull;
    _pack_field(out->data, 0u, 16u, _MAGIC_NUMBER, false);
}

void spark_build_GET_TEMPERATURES(uint8_t device_id, const Spark_GET_TEMPERATURES_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33894400u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_GET_MOTOR_INTERFACE(uint8_t device_id, const Spark_GET_MOTOR_INTERFACE_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33894720u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 3u;
    out->is_rtr = true;
    memset(out->data, 0, 3);
}

void spark_build_GET_PARAMETER_0_TO_15_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_0_TO_15_TYPES_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33895424u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_GET_PARAMETER_16_TO_31_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_16_TO_31_TYPES_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33895488u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_GET_PARAMETER_32_TO_47_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_32_TO_47_TYPES_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33895552u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_GET_PARAMETER_48_TO_63_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_48_TO_63_TYPES_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33895616u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_GET_PARAMETER_64_TO_79_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_64_TO_79_TYPES_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33895680u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_GET_PARAMETER_80_TO_95_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_80_TO_95_TYPES_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33895744u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_GET_PARAMETER_96_TO_111_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_96_TO_111_TYPES_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33895808u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_GET_PARAMETER_112_TO_127_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_112_TO_127_TYPES_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33895872u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_GET_PARAMETER_128_TO_143_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_128_TO_143_TYPES_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33895936u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_GET_PARAMETER_144_TO_159_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_144_TO_159_TYPES_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33896000u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_GET_PARAMETER_160_TO_175_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_160_TO_175_TYPES_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33896064u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_GET_PARAMETER_176_TO_191_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_176_TO_191_TYPES_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33896128u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_GET_PARAMETER_192_TO_207_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_192_TO_207_TYPES_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33896192u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_GET_PARAMETER_208_TO_223_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_208_TO_223_TYPES_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33896256u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_GET_PARAMETER_224_TO_239_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_224_TO_239_TYPES_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33896320u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_GET_PARAMETER_240_TO_255_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_240_TO_255_TYPES_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33896384u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_PARAMETER_WRITE(uint8_t device_id, const Spark_PARAMETER_WRITE_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33896448u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 5u;
    out->is_rtr = false;
    memset(out->data, 0, 5);
    uint64_t _PARAMETER_ID = values ? (uint64_t)values->PARAMETER_ID : 0ull;
    _pack_field(out->data, 0u, 8u, _PARAMETER_ID, false);
    uint64_t _VALUE = values ? (uint64_t)values->VALUE : 0ull;
    _pack_field(out->data, 8u, 32u, _VALUE, false);
}

void spark_build_PARAMETER_WRITE_RESPONSE(uint8_t device_id, const Spark_PARAMETER_WRITE_RESPONSE_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33896512u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 7u;
    out->is_rtr = false;
    memset(out->data, 0, 7);
    uint64_t _PARAMETER_ID = values ? (uint64_t)values->PARAMETER_ID : 0ull;
    _pack_field(out->data, 0u, 8u, _PARAMETER_ID, false);
    uint64_t _PARAMETER_TYPE = values ? (uint64_t)values->PARAMETER_TYPE : 0ull;
    _pack_field(out->data, 8u, 8u, _PARAMETER_TYPE, false);
    uint64_t _VALUE = values ? (uint64_t)values->VALUE : 0ull;
    _pack_field(out->data, 16u, 32u, _VALUE, false);
    uint64_t _RESULT_CODE = values ? (uint64_t)values->RESULT_CODE : 0ull;
    _pack_field(out->data, 48u, 8u, _RESULT_CODE, false);
}

void spark_build_READ_PARAMETER_0_AND_1(uint8_t device_id, const Spark_READ_PARAMETER_0_AND_1_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33897472u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_2_AND_3(uint8_t device_id, const Spark_READ_PARAMETER_2_AND_3_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33897536u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_4_AND_5(uint8_t device_id, const Spark_READ_PARAMETER_4_AND_5_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33897600u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_6_AND_7(uint8_t device_id, const Spark_READ_PARAMETER_6_AND_7_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33897664u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_8_AND_9(uint8_t device_id, const Spark_READ_PARAMETER_8_AND_9_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33897728u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_10_AND_11(uint8_t device_id, const Spark_READ_PARAMETER_10_AND_11_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33897792u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_12_AND_13(uint8_t device_id, const Spark_READ_PARAMETER_12_AND_13_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33897856u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_14_AND_15(uint8_t device_id, const Spark_READ_PARAMETER_14_AND_15_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33897920u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_16_AND_17(uint8_t device_id, const Spark_READ_PARAMETER_16_AND_17_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33897984u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_18_AND_19(uint8_t device_id, const Spark_READ_PARAMETER_18_AND_19_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33898048u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_20_AND_21(uint8_t device_id, const Spark_READ_PARAMETER_20_AND_21_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33898112u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_22_AND_23(uint8_t device_id, const Spark_READ_PARAMETER_22_AND_23_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33898176u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_24_AND_25(uint8_t device_id, const Spark_READ_PARAMETER_24_AND_25_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33898240u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_26_AND_27(uint8_t device_id, const Spark_READ_PARAMETER_26_AND_27_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33898304u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_28_AND_29(uint8_t device_id, const Spark_READ_PARAMETER_28_AND_29_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33898368u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_30_AND_31(uint8_t device_id, const Spark_READ_PARAMETER_30_AND_31_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33898432u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_32_AND_33(uint8_t device_id, const Spark_READ_PARAMETER_32_AND_33_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33898496u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_34_AND_35(uint8_t device_id, const Spark_READ_PARAMETER_34_AND_35_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33898560u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_36_AND_37(uint8_t device_id, const Spark_READ_PARAMETER_36_AND_37_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33898624u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_38_AND_39(uint8_t device_id, const Spark_READ_PARAMETER_38_AND_39_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33898688u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_40_AND_41(uint8_t device_id, const Spark_READ_PARAMETER_40_AND_41_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33898752u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_42_AND_43(uint8_t device_id, const Spark_READ_PARAMETER_42_AND_43_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33898816u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_44_AND_45(uint8_t device_id, const Spark_READ_PARAMETER_44_AND_45_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33898880u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_46_AND_47(uint8_t device_id, const Spark_READ_PARAMETER_46_AND_47_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33898944u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_48_AND_49(uint8_t device_id, const Spark_READ_PARAMETER_48_AND_49_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33899008u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_50_AND_51(uint8_t device_id, const Spark_READ_PARAMETER_50_AND_51_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33899072u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_52_AND_53(uint8_t device_id, const Spark_READ_PARAMETER_52_AND_53_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33899136u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_54_AND_55(uint8_t device_id, const Spark_READ_PARAMETER_54_AND_55_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33899200u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_56_AND_57(uint8_t device_id, const Spark_READ_PARAMETER_56_AND_57_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33899264u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_58_AND_59(uint8_t device_id, const Spark_READ_PARAMETER_58_AND_59_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33899328u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_60_AND_61(uint8_t device_id, const Spark_READ_PARAMETER_60_AND_61_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33899392u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_62_AND_63(uint8_t device_id, const Spark_READ_PARAMETER_62_AND_63_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33899456u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_64_AND_65(uint8_t device_id, const Spark_READ_PARAMETER_64_AND_65_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33899520u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_66_AND_67(uint8_t device_id, const Spark_READ_PARAMETER_66_AND_67_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33899584u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_68_AND_69(uint8_t device_id, const Spark_READ_PARAMETER_68_AND_69_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33899648u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_70_AND_71(uint8_t device_id, const Spark_READ_PARAMETER_70_AND_71_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33899712u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_72_AND_73(uint8_t device_id, const Spark_READ_PARAMETER_72_AND_73_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33899776u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_74_AND_75(uint8_t device_id, const Spark_READ_PARAMETER_74_AND_75_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33899840u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_76_AND_77(uint8_t device_id, const Spark_READ_PARAMETER_76_AND_77_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33899904u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_78_AND_79(uint8_t device_id, const Spark_READ_PARAMETER_78_AND_79_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33899968u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_80_AND_81(uint8_t device_id, const Spark_READ_PARAMETER_80_AND_81_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33900032u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_82_AND_83(uint8_t device_id, const Spark_READ_PARAMETER_82_AND_83_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33900096u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_84_AND_85(uint8_t device_id, const Spark_READ_PARAMETER_84_AND_85_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33900160u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_86_AND_87(uint8_t device_id, const Spark_READ_PARAMETER_86_AND_87_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33900224u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_88_AND_89(uint8_t device_id, const Spark_READ_PARAMETER_88_AND_89_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33900288u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_90_AND_91(uint8_t device_id, const Spark_READ_PARAMETER_90_AND_91_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33900352u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_92_AND_93(uint8_t device_id, const Spark_READ_PARAMETER_92_AND_93_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33900416u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_94_AND_95(uint8_t device_id, const Spark_READ_PARAMETER_94_AND_95_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33900480u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_96_AND_97(uint8_t device_id, const Spark_READ_PARAMETER_96_AND_97_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33900544u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_98_AND_99(uint8_t device_id, const Spark_READ_PARAMETER_98_AND_99_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33900608u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_100_AND_101(uint8_t device_id, const Spark_READ_PARAMETER_100_AND_101_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33900672u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_102_AND_103(uint8_t device_id, const Spark_READ_PARAMETER_102_AND_103_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33900736u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_104_AND_105(uint8_t device_id, const Spark_READ_PARAMETER_104_AND_105_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33900800u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_106_AND_107(uint8_t device_id, const Spark_READ_PARAMETER_106_AND_107_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33900864u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_108_AND_109(uint8_t device_id, const Spark_READ_PARAMETER_108_AND_109_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33900928u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_110_AND_111(uint8_t device_id, const Spark_READ_PARAMETER_110_AND_111_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33900992u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_112_AND_113(uint8_t device_id, const Spark_READ_PARAMETER_112_AND_113_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33901056u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_114_AND_115(uint8_t device_id, const Spark_READ_PARAMETER_114_AND_115_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33901120u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_116_AND_117(uint8_t device_id, const Spark_READ_PARAMETER_116_AND_117_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33901184u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_118_AND_119(uint8_t device_id, const Spark_READ_PARAMETER_118_AND_119_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33901248u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_120_AND_121(uint8_t device_id, const Spark_READ_PARAMETER_120_AND_121_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33901312u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_122_AND_123(uint8_t device_id, const Spark_READ_PARAMETER_122_AND_123_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33901376u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_124_AND_125(uint8_t device_id, const Spark_READ_PARAMETER_124_AND_125_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33901440u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_126_AND_127(uint8_t device_id, const Spark_READ_PARAMETER_126_AND_127_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33901504u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_128_AND_129(uint8_t device_id, const Spark_READ_PARAMETER_128_AND_129_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33901568u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_130_AND_131(uint8_t device_id, const Spark_READ_PARAMETER_130_AND_131_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33901632u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_132_AND_133(uint8_t device_id, const Spark_READ_PARAMETER_132_AND_133_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33901696u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_134_AND_135(uint8_t device_id, const Spark_READ_PARAMETER_134_AND_135_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33901760u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_136_AND_137(uint8_t device_id, const Spark_READ_PARAMETER_136_AND_137_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33901824u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_138_AND_139(uint8_t device_id, const Spark_READ_PARAMETER_138_AND_139_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33901888u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_140_AND_141(uint8_t device_id, const Spark_READ_PARAMETER_140_AND_141_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33901952u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_142_AND_143(uint8_t device_id, const Spark_READ_PARAMETER_142_AND_143_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33902016u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_144_AND_145(uint8_t device_id, const Spark_READ_PARAMETER_144_AND_145_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33902080u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_146_AND_147(uint8_t device_id, const Spark_READ_PARAMETER_146_AND_147_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33902144u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_148_AND_149(uint8_t device_id, const Spark_READ_PARAMETER_148_AND_149_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33902208u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_150_AND_151(uint8_t device_id, const Spark_READ_PARAMETER_150_AND_151_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33902272u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_152_AND_153(uint8_t device_id, const Spark_READ_PARAMETER_152_AND_153_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33902336u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_154_AND_155(uint8_t device_id, const Spark_READ_PARAMETER_154_AND_155_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33902400u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_156_AND_157(uint8_t device_id, const Spark_READ_PARAMETER_156_AND_157_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33902464u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_158_AND_159(uint8_t device_id, const Spark_READ_PARAMETER_158_AND_159_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33902528u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_160_AND_161(uint8_t device_id, const Spark_READ_PARAMETER_160_AND_161_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33902592u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_162_AND_163(uint8_t device_id, const Spark_READ_PARAMETER_162_AND_163_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33902656u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_164_AND_165(uint8_t device_id, const Spark_READ_PARAMETER_164_AND_165_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33902720u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_166_AND_167(uint8_t device_id, const Spark_READ_PARAMETER_166_AND_167_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33902784u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_168_AND_169(uint8_t device_id, const Spark_READ_PARAMETER_168_AND_169_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33902848u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_170_AND_171(uint8_t device_id, const Spark_READ_PARAMETER_170_AND_171_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33902912u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_172_AND_173(uint8_t device_id, const Spark_READ_PARAMETER_172_AND_173_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33902976u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_174_AND_175(uint8_t device_id, const Spark_READ_PARAMETER_174_AND_175_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33903040u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_176_AND_177(uint8_t device_id, const Spark_READ_PARAMETER_176_AND_177_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33903104u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_178_AND_179(uint8_t device_id, const Spark_READ_PARAMETER_178_AND_179_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33903168u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_180_AND_181(uint8_t device_id, const Spark_READ_PARAMETER_180_AND_181_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33903232u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_182_AND_183(uint8_t device_id, const Spark_READ_PARAMETER_182_AND_183_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33903296u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_184_AND_185(uint8_t device_id, const Spark_READ_PARAMETER_184_AND_185_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33903360u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_186_AND_187(uint8_t device_id, const Spark_READ_PARAMETER_186_AND_187_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33903424u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_188_AND_189(uint8_t device_id, const Spark_READ_PARAMETER_188_AND_189_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33903488u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_190_AND_191(uint8_t device_id, const Spark_READ_PARAMETER_190_AND_191_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33903552u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_192_AND_193(uint8_t device_id, const Spark_READ_PARAMETER_192_AND_193_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33903616u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_194_AND_195(uint8_t device_id, const Spark_READ_PARAMETER_194_AND_195_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33903680u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_196_AND_197(uint8_t device_id, const Spark_READ_PARAMETER_196_AND_197_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33903744u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_198_AND_199(uint8_t device_id, const Spark_READ_PARAMETER_198_AND_199_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33903808u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_200_AND_201(uint8_t device_id, const Spark_READ_PARAMETER_200_AND_201_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33903872u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_202_AND_203(uint8_t device_id, const Spark_READ_PARAMETER_202_AND_203_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33903936u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_204_AND_205(uint8_t device_id, const Spark_READ_PARAMETER_204_AND_205_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33904000u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_206_AND_207(uint8_t device_id, const Spark_READ_PARAMETER_206_AND_207_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33904064u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_208_AND_209(uint8_t device_id, const Spark_READ_PARAMETER_208_AND_209_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33904128u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_210_AND_211(uint8_t device_id, const Spark_READ_PARAMETER_210_AND_211_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33904192u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_212_AND_213(uint8_t device_id, const Spark_READ_PARAMETER_212_AND_213_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33904256u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_214_AND_215(uint8_t device_id, const Spark_READ_PARAMETER_214_AND_215_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33904320u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_216_AND_217(uint8_t device_id, const Spark_READ_PARAMETER_216_AND_217_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33904384u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_218_AND_219(uint8_t device_id, const Spark_READ_PARAMETER_218_AND_219_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33904448u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_220_AND_221(uint8_t device_id, const Spark_READ_PARAMETER_220_AND_221_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33904512u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_222_AND_223(uint8_t device_id, const Spark_READ_PARAMETER_222_AND_223_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33904576u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_224_AND_225(uint8_t device_id, const Spark_READ_PARAMETER_224_AND_225_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33904640u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_226_AND_227(uint8_t device_id, const Spark_READ_PARAMETER_226_AND_227_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33904704u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_228_AND_229(uint8_t device_id, const Spark_READ_PARAMETER_228_AND_229_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33904768u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_230_AND_231(uint8_t device_id, const Spark_READ_PARAMETER_230_AND_231_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33904832u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_232_AND_233(uint8_t device_id, const Spark_READ_PARAMETER_232_AND_233_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33904896u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_234_AND_235(uint8_t device_id, const Spark_READ_PARAMETER_234_AND_235_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33904960u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_236_AND_237(uint8_t device_id, const Spark_READ_PARAMETER_236_AND_237_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33905024u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_238_AND_239(uint8_t device_id, const Spark_READ_PARAMETER_238_AND_239_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33905088u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_240_AND_241(uint8_t device_id, const Spark_READ_PARAMETER_240_AND_241_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33905152u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_242_AND_243(uint8_t device_id, const Spark_READ_PARAMETER_242_AND_243_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33905216u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_244_AND_245(uint8_t device_id, const Spark_READ_PARAMETER_244_AND_245_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33905280u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_246_AND_247(uint8_t device_id, const Spark_READ_PARAMETER_246_AND_247_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33905344u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_248_AND_249(uint8_t device_id, const Spark_READ_PARAMETER_248_AND_249_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33905408u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_250_AND_251(uint8_t device_id, const Spark_READ_PARAMETER_250_AND_251_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33905472u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_252_AND_253(uint8_t device_id, const Spark_READ_PARAMETER_252_AND_253_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33905536u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_READ_PARAMETER_254_AND_255(uint8_t device_id, const Spark_READ_PARAMETER_254_AND_255_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33905600u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = true;
    memset(out->data, 0, 8);
}

void spark_build_WRITE_PARAMETER_0_AND_1(uint8_t device_id, const Spark_WRITE_PARAMETER_0_AND_1_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33905664u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_2_AND_3(uint8_t device_id, const Spark_WRITE_PARAMETER_2_AND_3_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33905728u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_4_AND_5(uint8_t device_id, const Spark_WRITE_PARAMETER_4_AND_5_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33905792u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_6_AND_7(uint8_t device_id, const Spark_WRITE_PARAMETER_6_AND_7_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33905856u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_8_AND_9(uint8_t device_id, const Spark_WRITE_PARAMETER_8_AND_9_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33905920u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_10_AND_11(uint8_t device_id, const Spark_WRITE_PARAMETER_10_AND_11_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33905984u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_12_AND_13(uint8_t device_id, const Spark_WRITE_PARAMETER_12_AND_13_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33906048u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_14_AND_15(uint8_t device_id, const Spark_WRITE_PARAMETER_14_AND_15_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33906112u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_16_AND_17(uint8_t device_id, const Spark_WRITE_PARAMETER_16_AND_17_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33906176u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_18_AND_19(uint8_t device_id, const Spark_WRITE_PARAMETER_18_AND_19_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33906240u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_20_AND_21(uint8_t device_id, const Spark_WRITE_PARAMETER_20_AND_21_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33906304u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_22_AND_23(uint8_t device_id, const Spark_WRITE_PARAMETER_22_AND_23_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33906368u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_24_AND_25(uint8_t device_id, const Spark_WRITE_PARAMETER_24_AND_25_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33906432u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_26_AND_27(uint8_t device_id, const Spark_WRITE_PARAMETER_26_AND_27_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33906496u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_28_AND_29(uint8_t device_id, const Spark_WRITE_PARAMETER_28_AND_29_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33906560u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_30_AND_31(uint8_t device_id, const Spark_WRITE_PARAMETER_30_AND_31_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33906624u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_32_AND_33(uint8_t device_id, const Spark_WRITE_PARAMETER_32_AND_33_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33906688u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_34_AND_35(uint8_t device_id, const Spark_WRITE_PARAMETER_34_AND_35_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33906752u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_36_AND_37(uint8_t device_id, const Spark_WRITE_PARAMETER_36_AND_37_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33906816u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_38_AND_39(uint8_t device_id, const Spark_WRITE_PARAMETER_38_AND_39_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33906880u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_40_AND_41(uint8_t device_id, const Spark_WRITE_PARAMETER_40_AND_41_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33906944u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_42_AND_43(uint8_t device_id, const Spark_WRITE_PARAMETER_42_AND_43_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33907008u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_44_AND_45(uint8_t device_id, const Spark_WRITE_PARAMETER_44_AND_45_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33907072u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_46_AND_47(uint8_t device_id, const Spark_WRITE_PARAMETER_46_AND_47_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33907136u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_48_AND_49(uint8_t device_id, const Spark_WRITE_PARAMETER_48_AND_49_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33907200u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_50_AND_51(uint8_t device_id, const Spark_WRITE_PARAMETER_50_AND_51_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33907264u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_52_AND_53(uint8_t device_id, const Spark_WRITE_PARAMETER_52_AND_53_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33907328u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_54_AND_55(uint8_t device_id, const Spark_WRITE_PARAMETER_54_AND_55_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33907392u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_56_AND_57(uint8_t device_id, const Spark_WRITE_PARAMETER_56_AND_57_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33907456u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_58_AND_59(uint8_t device_id, const Spark_WRITE_PARAMETER_58_AND_59_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33907520u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_60_AND_61(uint8_t device_id, const Spark_WRITE_PARAMETER_60_AND_61_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33907584u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_62_AND_63(uint8_t device_id, const Spark_WRITE_PARAMETER_62_AND_63_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33907648u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_64_AND_65(uint8_t device_id, const Spark_WRITE_PARAMETER_64_AND_65_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33907712u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_66_AND_67(uint8_t device_id, const Spark_WRITE_PARAMETER_66_AND_67_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33907776u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_68_AND_69(uint8_t device_id, const Spark_WRITE_PARAMETER_68_AND_69_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33907840u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_70_AND_71(uint8_t device_id, const Spark_WRITE_PARAMETER_70_AND_71_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33907904u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_72_AND_73(uint8_t device_id, const Spark_WRITE_PARAMETER_72_AND_73_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33907968u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_74_AND_75(uint8_t device_id, const Spark_WRITE_PARAMETER_74_AND_75_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33908032u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_76_AND_77(uint8_t device_id, const Spark_WRITE_PARAMETER_76_AND_77_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33908096u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_78_AND_79(uint8_t device_id, const Spark_WRITE_PARAMETER_78_AND_79_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33908160u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_80_AND_81(uint8_t device_id, const Spark_WRITE_PARAMETER_80_AND_81_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33908224u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_82_AND_83(uint8_t device_id, const Spark_WRITE_PARAMETER_82_AND_83_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33908288u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_84_AND_85(uint8_t device_id, const Spark_WRITE_PARAMETER_84_AND_85_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33908352u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_86_AND_87(uint8_t device_id, const Spark_WRITE_PARAMETER_86_AND_87_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33908416u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_88_AND_89(uint8_t device_id, const Spark_WRITE_PARAMETER_88_AND_89_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33908480u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_90_AND_91(uint8_t device_id, const Spark_WRITE_PARAMETER_90_AND_91_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33908544u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_92_AND_93(uint8_t device_id, const Spark_WRITE_PARAMETER_92_AND_93_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33908608u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_94_AND_95(uint8_t device_id, const Spark_WRITE_PARAMETER_94_AND_95_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33908672u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_96_AND_97(uint8_t device_id, const Spark_WRITE_PARAMETER_96_AND_97_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33908736u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_98_AND_99(uint8_t device_id, const Spark_WRITE_PARAMETER_98_AND_99_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33908800u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_100_AND_101(uint8_t device_id, const Spark_WRITE_PARAMETER_100_AND_101_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33908864u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_102_AND_103(uint8_t device_id, const Spark_WRITE_PARAMETER_102_AND_103_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33908928u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_104_AND_105(uint8_t device_id, const Spark_WRITE_PARAMETER_104_AND_105_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33908992u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_106_AND_107(uint8_t device_id, const Spark_WRITE_PARAMETER_106_AND_107_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33909056u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_108_AND_109(uint8_t device_id, const Spark_WRITE_PARAMETER_108_AND_109_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33909120u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_110_AND_111(uint8_t device_id, const Spark_WRITE_PARAMETER_110_AND_111_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33909184u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_112_AND_113(uint8_t device_id, const Spark_WRITE_PARAMETER_112_AND_113_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33909248u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_114_AND_115(uint8_t device_id, const Spark_WRITE_PARAMETER_114_AND_115_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33909312u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_116_AND_117(uint8_t device_id, const Spark_WRITE_PARAMETER_116_AND_117_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33909376u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_118_AND_119(uint8_t device_id, const Spark_WRITE_PARAMETER_118_AND_119_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33909440u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_120_AND_121(uint8_t device_id, const Spark_WRITE_PARAMETER_120_AND_121_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33909504u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_122_AND_123(uint8_t device_id, const Spark_WRITE_PARAMETER_122_AND_123_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33909568u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_124_AND_125(uint8_t device_id, const Spark_WRITE_PARAMETER_124_AND_125_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33909632u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_126_AND_127(uint8_t device_id, const Spark_WRITE_PARAMETER_126_AND_127_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33909696u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_128_AND_129(uint8_t device_id, const Spark_WRITE_PARAMETER_128_AND_129_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33909760u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_130_AND_131(uint8_t device_id, const Spark_WRITE_PARAMETER_130_AND_131_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33909824u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_132_AND_133(uint8_t device_id, const Spark_WRITE_PARAMETER_132_AND_133_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33909888u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_134_AND_135(uint8_t device_id, const Spark_WRITE_PARAMETER_134_AND_135_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33909952u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_136_AND_137(uint8_t device_id, const Spark_WRITE_PARAMETER_136_AND_137_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33910016u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_138_AND_139(uint8_t device_id, const Spark_WRITE_PARAMETER_138_AND_139_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33910080u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_140_AND_141(uint8_t device_id, const Spark_WRITE_PARAMETER_140_AND_141_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33910144u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_142_AND_143(uint8_t device_id, const Spark_WRITE_PARAMETER_142_AND_143_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33910208u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_144_AND_145(uint8_t device_id, const Spark_WRITE_PARAMETER_144_AND_145_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33910272u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_146_AND_147(uint8_t device_id, const Spark_WRITE_PARAMETER_146_AND_147_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33910336u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_148_AND_149(uint8_t device_id, const Spark_WRITE_PARAMETER_148_AND_149_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33910400u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_150_AND_151(uint8_t device_id, const Spark_WRITE_PARAMETER_150_AND_151_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33910464u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_152_AND_153(uint8_t device_id, const Spark_WRITE_PARAMETER_152_AND_153_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33910528u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_154_AND_155(uint8_t device_id, const Spark_WRITE_PARAMETER_154_AND_155_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33910592u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_156_AND_157(uint8_t device_id, const Spark_WRITE_PARAMETER_156_AND_157_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33910656u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_158_AND_159(uint8_t device_id, const Spark_WRITE_PARAMETER_158_AND_159_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33910720u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_160_AND_161(uint8_t device_id, const Spark_WRITE_PARAMETER_160_AND_161_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33910784u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_162_AND_163(uint8_t device_id, const Spark_WRITE_PARAMETER_162_AND_163_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33910848u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_164_AND_165(uint8_t device_id, const Spark_WRITE_PARAMETER_164_AND_165_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33910912u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_166_AND_167(uint8_t device_id, const Spark_WRITE_PARAMETER_166_AND_167_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33910976u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_168_AND_169(uint8_t device_id, const Spark_WRITE_PARAMETER_168_AND_169_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33911040u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_170_AND_171(uint8_t device_id, const Spark_WRITE_PARAMETER_170_AND_171_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33911104u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_172_AND_173(uint8_t device_id, const Spark_WRITE_PARAMETER_172_AND_173_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33911168u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_174_AND_175(uint8_t device_id, const Spark_WRITE_PARAMETER_174_AND_175_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33911232u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_176_AND_177(uint8_t device_id, const Spark_WRITE_PARAMETER_176_AND_177_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33911296u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_178_AND_179(uint8_t device_id, const Spark_WRITE_PARAMETER_178_AND_179_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33911360u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_180_AND_181(uint8_t device_id, const Spark_WRITE_PARAMETER_180_AND_181_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33911424u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_182_AND_183(uint8_t device_id, const Spark_WRITE_PARAMETER_182_AND_183_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33911488u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_184_AND_185(uint8_t device_id, const Spark_WRITE_PARAMETER_184_AND_185_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33911552u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_186_AND_187(uint8_t device_id, const Spark_WRITE_PARAMETER_186_AND_187_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33911616u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_188_AND_189(uint8_t device_id, const Spark_WRITE_PARAMETER_188_AND_189_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33911680u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_190_AND_191(uint8_t device_id, const Spark_WRITE_PARAMETER_190_AND_191_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33911744u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_192_AND_193(uint8_t device_id, const Spark_WRITE_PARAMETER_192_AND_193_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33911808u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_194_AND_195(uint8_t device_id, const Spark_WRITE_PARAMETER_194_AND_195_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33911872u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_196_AND_197(uint8_t device_id, const Spark_WRITE_PARAMETER_196_AND_197_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33911936u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_198_AND_199(uint8_t device_id, const Spark_WRITE_PARAMETER_198_AND_199_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33912000u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_200_AND_201(uint8_t device_id, const Spark_WRITE_PARAMETER_200_AND_201_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33912064u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_202_AND_203(uint8_t device_id, const Spark_WRITE_PARAMETER_202_AND_203_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33912128u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_204_AND_205(uint8_t device_id, const Spark_WRITE_PARAMETER_204_AND_205_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33912192u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_206_AND_207(uint8_t device_id, const Spark_WRITE_PARAMETER_206_AND_207_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33912256u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_208_AND_209(uint8_t device_id, const Spark_WRITE_PARAMETER_208_AND_209_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33912320u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_210_AND_211(uint8_t device_id, const Spark_WRITE_PARAMETER_210_AND_211_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33912384u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_212_AND_213(uint8_t device_id, const Spark_WRITE_PARAMETER_212_AND_213_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33912448u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_214_AND_215(uint8_t device_id, const Spark_WRITE_PARAMETER_214_AND_215_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33912512u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_216_AND_217(uint8_t device_id, const Spark_WRITE_PARAMETER_216_AND_217_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33912576u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_218_AND_219(uint8_t device_id, const Spark_WRITE_PARAMETER_218_AND_219_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33912640u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_220_AND_221(uint8_t device_id, const Spark_WRITE_PARAMETER_220_AND_221_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33912704u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_222_AND_223(uint8_t device_id, const Spark_WRITE_PARAMETER_222_AND_223_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33912768u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_224_AND_225(uint8_t device_id, const Spark_WRITE_PARAMETER_224_AND_225_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33912832u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_226_AND_227(uint8_t device_id, const Spark_WRITE_PARAMETER_226_AND_227_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33912896u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_228_AND_229(uint8_t device_id, const Spark_WRITE_PARAMETER_228_AND_229_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33912960u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_230_AND_231(uint8_t device_id, const Spark_WRITE_PARAMETER_230_AND_231_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33913024u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_232_AND_233(uint8_t device_id, const Spark_WRITE_PARAMETER_232_AND_233_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33913088u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_234_AND_235(uint8_t device_id, const Spark_WRITE_PARAMETER_234_AND_235_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33913152u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_236_AND_237(uint8_t device_id, const Spark_WRITE_PARAMETER_236_AND_237_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33913216u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_238_AND_239(uint8_t device_id, const Spark_WRITE_PARAMETER_238_AND_239_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33913280u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_240_AND_241(uint8_t device_id, const Spark_WRITE_PARAMETER_240_AND_241_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33913344u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_242_AND_243(uint8_t device_id, const Spark_WRITE_PARAMETER_242_AND_243_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33913408u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_244_AND_245(uint8_t device_id, const Spark_WRITE_PARAMETER_244_AND_245_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33913472u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_246_AND_247(uint8_t device_id, const Spark_WRITE_PARAMETER_246_AND_247_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33913536u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_248_AND_249(uint8_t device_id, const Spark_WRITE_PARAMETER_248_AND_249_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33913600u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_250_AND_251(uint8_t device_id, const Spark_WRITE_PARAMETER_250_AND_251_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33913664u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_252_AND_253(uint8_t device_id, const Spark_WRITE_PARAMETER_252_AND_253_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33913728u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_WRITE_PARAMETER_254_AND_255(uint8_t device_id, const Spark_WRITE_PARAMETER_254_AND_255_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33913792u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 8u;
    out->is_rtr = false;
    memset(out->data, 0, 8);
    uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
    uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
    _pack_field(out->data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
}

void spark_build_START_FOLLOWER_MODE(uint8_t device_id, const Spark_START_FOLLOWER_MODE_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33913856u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 0u;
    out->is_rtr = false;
}

void spark_build_START_FOLLOWER_MODE_RESPONSE(uint8_t device_id, const Spark_START_FOLLOWER_MODE_RESPONSE_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33913920u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 1u;
    out->is_rtr = false;
    memset(out->data, 0, 1);
    uint64_t _STATUS = values ? (uint64_t)values->STATUS : 0ull;
    _pack_field(out->data, 0u, 8u, _STATUS, false);
}

void spark_build_STOP_FOLLOWER_MODE(uint8_t device_id, const Spark_STOP_FOLLOWER_MODE_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33913984u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 0u;
    out->is_rtr = false;
}

void spark_build_STOP_FOLLOWER_MODE_RESPONSE(uint8_t device_id, const Spark_STOP_FOLLOWER_MODE_RESPONSE_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33914048u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 0u;
    out->is_rtr = false;
}

void spark_build_ENTER_SWDL_CAN_BOOTLOADER(uint8_t device_id, const Spark_ENTER_SWDL_CAN_BOOTLOADER_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33914816u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 0u;
    out->is_rtr = false;
}

void spark_build_PERSIST_PARAMETERS(uint8_t device_id, const Spark_PERSIST_PARAMETERS_t* values, SparkCanFrame* out) {
    if (!out) return;
    out->id = (uint32_t)(33947584u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
    out->dlc = 2u;
    out->is_rtr = false;
    memset(out->data, 0, 2);
    uint64_t _MAGIC_NUMBER = values ? (uint64_t)values->MAGIC_NUMBER : 0ull;
    _pack_field(out->data, 0u, 16u, _MAGIC_NUMBER, false);
}

