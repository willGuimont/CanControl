// AUTO-GENERATED FILE. DO NOT EDIT. See gen.py
#include "low_level/low_sparkmax.h"

#include <string.h>

namespace CanControl::LowLevel::SparkMax
{

    // Build frame payload for Velocity Setpoint: Sets the Control Type to Velocity and sets the target velocity
    spark_can_frame spark_build_VELOCITY_SETPOINT(uint8_t device_id, const Spark_VELOCITY_SETPOINT_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33882112u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = false;
        union
        {
            float    f;
            uint32_t u;
        } _SETPOINT = {.f = values ? values->SETPOINT : 0.0f};
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, (uint64_t)_SETPOINT.u, false);
        int64_t  _ARBITRARY_FEEDFORWARD_s = values ? (int64_t)values->ARBITRARY_FEEDFORWARD : 0;
        uint64_t _ARBITRARY_FEEDFORWARD   = (uint64_t)_ARBITRARY_FEEDFORWARD_s & (((1ull << 16) - 1ull));
        ::CanControl::LowLevel::pack_field(out.data, 32u, 16u, _ARBITRARY_FEEDFORWARD, false);
        uint64_t _PID_SLOT = values ? (uint64_t)values->PID_SLOT : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 48u, 2u, _PID_SLOT, false);
        uint64_t _ARBITRARY_FEEDFORWARD_UNITS = values ? (uint64_t)values->ARBITRARY_FEEDFORWARD_UNITS : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 50u, 1u, _ARBITRARY_FEEDFORWARD_UNITS, false);
        return out;
    }

    // Build frame payload for Duty Cycle Setpoint: Sets the Control Type to Duty Cycle and sets the target duty cycle
    // (from -1 to 1)
    spark_can_frame spark_build_DUTY_CYCLE_SETPOINT(uint8_t device_id, const Spark_DUTY_CYCLE_SETPOINT_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33882240u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = false;
        union
        {
            float    f;
            uint32_t u;
        } _SETPOINT = {.f = values ? values->SETPOINT : 0.0f};
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, (uint64_t)_SETPOINT.u, false);
        int64_t  _ARBITRARY_FEEDFORWARD_s = values ? (int64_t)values->ARBITRARY_FEEDFORWARD : 0;
        uint64_t _ARBITRARY_FEEDFORWARD   = (uint64_t)_ARBITRARY_FEEDFORWARD_s & (((1ull << 16) - 1ull));
        ::CanControl::LowLevel::pack_field(out.data, 32u, 16u, _ARBITRARY_FEEDFORWARD, false);
        uint64_t _PID_SLOT = values ? (uint64_t)values->PID_SLOT : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 48u, 2u, _PID_SLOT, false);
        uint64_t _ARBITRARY_FEEDFORWARD_UNITS = values ? (uint64_t)values->ARBITRARY_FEEDFORWARD_UNITS : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 50u, 1u, _ARBITRARY_FEEDFORWARD_UNITS, false);
        return out;
    }

    // Build frame payload for Position Setpoint: Sets the Control Type to Position and sets the target position
    spark_can_frame spark_build_POSITION_SETPOINT(uint8_t device_id, const Spark_POSITION_SETPOINT_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33882368u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = false;
        union
        {
            float    f;
            uint32_t u;
        } _SETPOINT = {.f = values ? values->SETPOINT : 0.0f};
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, (uint64_t)_SETPOINT.u, false);
        int64_t  _ARBITRARY_FEEDFORWARD_s = values ? (int64_t)values->ARBITRARY_FEEDFORWARD : 0;
        uint64_t _ARBITRARY_FEEDFORWARD   = (uint64_t)_ARBITRARY_FEEDFORWARD_s & (((1ull << 16) - 1ull));
        ::CanControl::LowLevel::pack_field(out.data, 32u, 16u, _ARBITRARY_FEEDFORWARD, false);
        uint64_t _PID_SLOT = values ? (uint64_t)values->PID_SLOT : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 48u, 2u, _PID_SLOT, false);
        uint64_t _ARBITRARY_FEEDFORWARD_UNITS = values ? (uint64_t)values->ARBITRARY_FEEDFORWARD_UNITS : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 50u, 1u, _ARBITRARY_FEEDFORWARD_UNITS, false);
        return out;
    }

    // Build frame payload for Voltage Setpoint: Sets the Control Type to Voltage and sets the target voltage
    spark_can_frame spark_build_VOLTAGE_SETPOINT(uint8_t device_id, const Spark_VOLTAGE_SETPOINT_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33882432u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = false;
        union
        {
            float    f;
            uint32_t u;
        } _SETPOINT = {.f = values ? values->SETPOINT : 0.0f};
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, (uint64_t)_SETPOINT.u, false);
        int64_t  _ARBITRARY_FEEDFORWARD_s = values ? (int64_t)values->ARBITRARY_FEEDFORWARD : 0;
        uint64_t _ARBITRARY_FEEDFORWARD   = (uint64_t)_ARBITRARY_FEEDFORWARD_s & (((1ull << 16) - 1ull));
        ::CanControl::LowLevel::pack_field(out.data, 32u, 16u, _ARBITRARY_FEEDFORWARD, false);
        uint64_t _PID_SLOT = values ? (uint64_t)values->PID_SLOT : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 48u, 2u, _PID_SLOT, false);
        uint64_t _ARBITRARY_FEEDFORWARD_UNITS = values ? (uint64_t)values->ARBITRARY_FEEDFORWARD_UNITS : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 50u, 1u, _ARBITRARY_FEEDFORWARD_UNITS, false);
        return out;
    }

    // Build frame payload for Current Setpoint: Sets the Control Type to Current and sets the target current
    spark_can_frame spark_build_CURRENT_SETPOINT(uint8_t device_id, const Spark_CURRENT_SETPOINT_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33882496u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = false;
        union
        {
            float    f;
            uint32_t u;
        } _SETPOINT = {.f = values ? values->SETPOINT : 0.0f};
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, (uint64_t)_SETPOINT.u, false);
        int64_t  _ARBITRARY_FEEDFORWARD_s = values ? (int64_t)values->ARBITRARY_FEEDFORWARD : 0;
        uint64_t _ARBITRARY_FEEDFORWARD   = (uint64_t)_ARBITRARY_FEEDFORWARD_s & (((1ull << 16) - 1ull));
        ::CanControl::LowLevel::pack_field(out.data, 32u, 16u, _ARBITRARY_FEEDFORWARD, false);
        uint64_t _PID_SLOT = values ? (uint64_t)values->PID_SLOT : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 48u, 2u, _PID_SLOT, false);
        uint64_t _ARBITRARY_FEEDFORWARD_UNITS = values ? (uint64_t)values->ARBITRARY_FEEDFORWARD_UNITS : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 50u, 1u, _ARBITRARY_FEEDFORWARD_UNITS, false);
        return out;
    }

    // Build frame payload for MAXMotion Position Setpoint: Sets the Control Type to MAXMotion Position Control and sets
    // the target position
    spark_can_frame spark_build_MAXMOTION_POSITION_SETPOINT(uint8_t                                    device_id,
                                                            const Spark_MAXMOTION_POSITION_SETPOINT_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33882624u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = false;
        union
        {
            float    f;
            uint32_t u;
        } _SETPOINT = {.f = values ? values->SETPOINT : 0.0f};
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, (uint64_t)_SETPOINT.u, false);
        int64_t  _ARBITRARY_FEEDFORWARD_s = values ? (int64_t)values->ARBITRARY_FEEDFORWARD : 0;
        uint64_t _ARBITRARY_FEEDFORWARD   = (uint64_t)_ARBITRARY_FEEDFORWARD_s & (((1ull << 16) - 1ull));
        ::CanControl::LowLevel::pack_field(out.data, 32u, 16u, _ARBITRARY_FEEDFORWARD, false);
        uint64_t _PID_SLOT = values ? (uint64_t)values->PID_SLOT : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 48u, 2u, _PID_SLOT, false);
        uint64_t _ARBITRARY_FEEDFORWARD_UNITS = values ? (uint64_t)values->ARBITRARY_FEEDFORWARD_UNITS : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 50u, 1u, _ARBITRARY_FEEDFORWARD_UNITS, false);
        return out;
    }

    // Build frame payload for MAXMotion Velocity Setpoint: Sets the Control Type to MAXMotion Velocity Control and sets
    // the target velocity
    spark_can_frame spark_build_MAXMOTION_VELOCITY_SETPOINT(uint8_t                                    device_id,
                                                            const Spark_MAXMOTION_VELOCITY_SETPOINT_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33882688u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = false;
        union
        {
            float    f;
            uint32_t u;
        } _SETPOINT = {.f = values ? values->SETPOINT : 0.0f};
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, (uint64_t)_SETPOINT.u, false);
        int64_t  _ARBITRARY_FEEDFORWARD_s = values ? (int64_t)values->ARBITRARY_FEEDFORWARD : 0;
        uint64_t _ARBITRARY_FEEDFORWARD   = (uint64_t)_ARBITRARY_FEEDFORWARD_s & (((1ull << 16) - 1ull));
        ::CanControl::LowLevel::pack_field(out.data, 32u, 16u, _ARBITRARY_FEEDFORWARD, false);
        uint64_t _PID_SLOT = values ? (uint64_t)values->PID_SLOT : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 48u, 2u, _PID_SLOT, false);
        uint64_t _ARBITRARY_FEEDFORWARD_UNITS = values ? (uint64_t)values->ARBITRARY_FEEDFORWARD_UNITS : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 50u, 1u, _ARBITRARY_FEEDFORWARD_UNITS, false);
        return out;
    }

    // Build frame payload for Set Statuses Enabled: Enable or disable status frames. In response, a Set Statuses
    // Enabled Response frame will be sent.
    spark_can_frame spark_build_SET_STATUSES_ENABLED(uint8_t device_id, const Spark_SET_STATUSES_ENABLED_t* values)
    {
        spark_can_frame out{};
        out.id         = (uint32_t)(33883136u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc        = 4u;
        out.is_rtr     = false;
        uint64_t _MASK = values ? (uint64_t)values->MASK : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 16u, _MASK, false);
        uint64_t _ENABLED_BITFIELD = values ? (uint64_t)values->ENABLED_BITFIELD : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 16u, 16u, _ENABLED_BITFIELD, false);
        return out;
    }

    // Build frame payload for Set Statuses Enabled Response: Response for a Set Statuses Enabled command
    spark_can_frame spark_build_SET_STATUSES_ENABLED_RESPONSE(uint8_t                                      device_id,
                                                              const Spark_SET_STATUSES_ENABLED_RESPONSE_t* values)
    {
        spark_can_frame out{};
        out.id                = (uint32_t)(33883200u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc               = 5u;
        out.is_rtr            = false;
        uint64_t _RESULT_CODE = values ? (uint64_t)values->RESULT_CODE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 8u, _RESULT_CODE, false);
        uint64_t _SPECIFIED_MASK = values ? (uint64_t)values->SPECIFIED_MASK : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 8u, 16u, _SPECIFIED_MASK, false);
        uint64_t _ENABLED_BITFIELD = values ? (uint64_t)values->ENABLED_BITFIELD : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 24u, 16u, _ENABLED_BITFIELD, false);
        return out;
    }

    // Build frame payload for Persist Parameters Response
    spark_can_frame spark_build_PERSIST_PARAMETERS_RESPONSE(uint8_t                                    device_id,
                                                            const Spark_PERSIST_PARAMETERS_RESPONSE_t* values)
    {
        spark_can_frame out{};
        out.id                = (uint32_t)(33883392u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc               = 1u;
        out.is_rtr            = false;
        uint64_t _RESULT_CODE = values ? (uint64_t)values->RESULT_CODE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 8u, _RESULT_CODE, false);
        return out;
    }

    // Build frame payload for Reset Safe Parameters: Resets most writable parameters to their default values, except
    // CAN ID, Motor Type, Idle Mode, PWM Input Deadband, and Duty Cycle Offset. In response, a Reset Safe Parameters
    // Response frame is sent.
    spark_can_frame spark_build_RESET_SAFE_PARAMETERS(uint8_t device_id, const Spark_RESET_SAFE_PARAMETERS_t* values)
    {
        spark_can_frame out{};
        out.id                 = (uint32_t)(33883456u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                = 2u;
        out.is_rtr             = false;
        uint64_t _MAGIC_NUMBER = values ? (uint64_t)values->MAGIC_NUMBER : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 16u, _MAGIC_NUMBER, false);
        return out;
    }

    // Build frame payload for Reset Safe Parameters Response: Response for a Reset Safe Parameters command
    spark_can_frame spark_build_RESET_SAFE_PARAMETERS_RESPONSE(uint8_t                                       device_id,
                                                               const Spark_RESET_SAFE_PARAMETERS_RESPONSE_t* values)
    {
        spark_can_frame out{};
        out.id                = (uint32_t)(33883520u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc               = 1u;
        out.is_rtr            = false;
        uint64_t _RESULT_CODE = values ? (uint64_t)values->RESULT_CODE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 8u, _RESULT_CODE, false);
        return out;
    }

    // Build frame payload for Complete Factory Reset: Resets all writable parameters to default values, even CAN ID,
    // Motor Type, Idle Mode, PWM Input Deadband, and Duty Cycle Offset. In response, a Complete Factory Reset Response
    // frame is sent.
    spark_can_frame spark_build_COMPLETE_FACTORY_RESET(uint8_t device_id, const Spark_COMPLETE_FACTORY_RESET_t* values)
    {
        spark_can_frame out{};
        out.id                 = (uint32_t)(33883584u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                = 2u;
        out.is_rtr             = false;
        uint64_t _MAGIC_NUMBER = values ? (uint64_t)values->MAGIC_NUMBER : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 16u, _MAGIC_NUMBER, false);
        return out;
    }

    // Build frame payload for Complete Factory Reset Response: Response for a Complete Factory Reset command
    spark_can_frame spark_build_COMPLETE_FACTORY_RESET_RESPONSE(uint8_t device_id,
                                                                const Spark_COMPLETE_FACTORY_RESET_RESPONSE_t* values)
    {
        spark_can_frame out{};
        out.id                = (uint32_t)(33883648u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc               = 1u;
        out.is_rtr            = false;
        uint64_t _RESULT_CODE = values ? (uint64_t)values->RESULT_CODE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 8u, _RESULT_CODE, false);
        return out;
    }

    // Build frame payload for Clear Faults
    spark_can_frame spark_build_CLEAR_FAULTS(uint8_t device_id, const Spark_CLEAR_FAULTS_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33889152u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 0u;
        out.is_rtr = false;
        return out;
    }

    // Build frame payload for Identify Unique SPARK: Makes the specified, single SPARK (even if there are multiple
    // SPARKs that have the same CAN ID) temporarily perform a special blink pattern that will make it stand out
    spark_can_frame spark_build_IDENTIFY_UNIQUE_SPARK(uint8_t device_id, const Spark_IDENTIFY_UNIQUE_SPARK_t* values)
    {
        spark_can_frame out{};
        out.id              = (uint32_t)(33889664u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc             = 4u;
        out.is_rtr          = false;
        uint64_t _UNIQUE_ID = values ? (uint64_t)values->UNIQUE_ID : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _UNIQUE_ID, false);
        return out;
    }

    // Build frame payload for Identify: Makes the SPARK temporarily perform a special blink pattern that will make it
    // stand out. Use Identify Unique Device if there may be multiple SPARKs with the same CAN ID.
    spark_can_frame spark_build_IDENTIFY(uint8_t device_id, const Spark_IDENTIFY_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33889728u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 0u;
        out.is_rtr = false;
        return out;
    }

    // Build frame payload for Nack: As of SPARK MAX firmware 1.6.3, this is only used as a potential response to
    // setting the CAN ID
    spark_can_frame spark_build_NACK(uint8_t device_id, const Spark_NACK_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33890304u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 0u;
        out.is_rtr = false;
        return out;
    }

    // Build frame payload for Ack: As of SPARK MAX firmware 1.6.3, this is only used as a potential response to setting
    // the CAN ID
    spark_can_frame spark_build_ACK(uint8_t device_id, const Spark_ACK_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33890368u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 0u;
        out.is_rtr = false;
        return out;
    }

    // Build frame payload for LED Sync: Causes all SPARKs on the bus to synchronize their LED patterns
    spark_can_frame spark_build_LED_SYNC(uint8_t device_id, const Spark_LED_SYNC_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33891520u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 0u;
        out.is_rtr = false;
        return out;
    }

    // Build frame payload for Set CAN ID: Allows changing the CAN ID when multiple devices on the bus currently have
    // the same CAN ID. Under normal circumstances, the CAN ID parameter can be used.
    spark_can_frame spark_build_SET_CAN_ID(uint8_t device_id, const Spark_SET_CAN_ID_t* values)
    {
        spark_can_frame out{};
        out.id              = (uint32_t)(33891648u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc             = 5u;
        out.is_rtr          = false;
        uint64_t _UNIQUE_ID = values ? (uint64_t)values->UNIQUE_ID : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _UNIQUE_ID, false);
        uint64_t _CAN_ID = values ? (uint64_t)values->CAN_ID : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 8u, _CAN_ID, false);
        return out;
    }

    // Build frame payload for Get Firmware Version
    spark_can_frame spark_build_GET_FIRMWARE_VERSION(uint8_t device_id, const Spark_GET_FIRMWARE_VERSION_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33891840u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for SWDL Data: Broadcast from the host to all SPARKs in SWDL mode, containing a slice of
    // firmware data
    spark_can_frame spark_build_SWDL_DATA(uint8_t device_id, const Spark_SWDL_DATA_t* values)
    {
        spark_can_frame out{};
        out.id         = (uint32_t)(33892096u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc        = 8u;
        out.is_rtr     = false;
        uint64_t _DATA = values ? (uint64_t)values->DATA : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 64u, _DATA, false);
        return out;
    }

    // Build frame payload for SWDL Checksum: Broadcast from the host to all SPARKs in SWDL mode, containing the
    // checksum of the full firmware image that was just sent
    spark_can_frame spark_build_SWDL_CHECKSUM(uint8_t device_id, const Spark_SWDL_CHECKSUM_t* values)
    {
        spark_can_frame out{};
        out.id             = (uint32_t)(33892160u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc            = 8u;
        out.is_rtr         = false;
        uint64_t _CHECKSUM = values ? (uint64_t)values->CHECKSUM : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 64u, _CHECKSUM, false);
        return out;
    }

    // Build frame payload for SWDL Retransmit: Sent by SPARK devices in response to receiving an SWDL Checksum frame
    // that does not match the firmware data they received
    spark_can_frame spark_build_SWDL_RETRANSMIT(uint8_t device_id, const Spark_SWDL_RETRANSMIT_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33892224u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 0u;
        out.is_rtr = false;
        return out;
    }

    // Build frame payload for Set Primary Encoder Position
    spark_can_frame spark_build_SET_PRIMARY_ENCODER_POSITION(uint8_t                                     device_id,
                                                             const Spark_SET_PRIMARY_ENCODER_POSITION_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33892352u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 5u;
        out.is_rtr = false;
        union
        {
            float    f;
            uint32_t u;
        } _POSITION = {.f = values ? values->POSITION : 0.0f};
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, (uint64_t)_POSITION.u, false);
        uint64_t _DATA_TYPE = values ? (uint64_t)values->DATA_TYPE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 8u, _DATA_TYPE, false);
        return out;
    }

    // Build frame payload for Set I Accumulation
    spark_can_frame spark_build_SET_I_ACCUMULATION(uint8_t device_id, const Spark_SET_I_ACCUMULATION_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33892480u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 5u;
        out.is_rtr = false;
        union
        {
            float    f;
            uint32_t u;
        } _I_ACCUMULATION = {.f = values ? values->I_ACCUMULATION : 0.0f};
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, (uint64_t)_I_ACCUMULATION.u, false);
        uint64_t _DATA_TYPE = values ? (uint64_t)values->DATA_TYPE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 8u, _DATA_TYPE, false);
        return out;
    }

    // Build frame payload for Set Analog Position
    spark_can_frame spark_build_SET_ANALOG_POSITION(uint8_t device_id, const Spark_SET_ANALOG_POSITION_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33892544u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 5u;
        out.is_rtr = false;
        union
        {
            float    f;
            uint32_t u;
        } _POSITION = {.f = values ? values->POSITION : 0.0f};
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, (uint64_t)_POSITION.u, false);
        uint64_t _DATA_TYPE = values ? (uint64_t)values->DATA_TYPE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 8u, _DATA_TYPE, false);
        return out;
    }

    // Build frame payload for Set Ext or Alt Encoder Position
    spark_can_frame spark_build_SET_EXT_OR_ALT_ENCODER_POSITION(uint8_t device_id,
                                                                const Spark_SET_EXT_OR_ALT_ENCODER_POSITION_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33892608u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 5u;
        out.is_rtr = false;
        union
        {
            float    f;
            uint32_t u;
        } _POSITION = {.f = values ? values->POSITION : 0.0f};
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, (uint64_t)_POSITION.u, false);
        uint64_t _DATA_TYPE = values ? (uint64_t)values->DATA_TYPE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 8u, _DATA_TYPE, false);
        return out;
    }

    // Build frame payload for Set Duty Cycle Position
    spark_can_frame spark_build_SET_DUTY_CYCLE_POSITION(uint8_t                                device_id,
                                                        const Spark_SET_DUTY_CYCLE_POSITION_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33892672u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 5u;
        out.is_rtr = false;
        union
        {
            float    f;
            uint32_t u;
        } _POSITION = {.f = values ? values->POSITION : 0.0f};
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, (uint64_t)_POSITION.u, false);
        uint64_t _DATA_TYPE = values ? (uint64_t)values->DATA_TYPE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 8u, _DATA_TYPE, false);
        return out;
    }

    // Build frame payload for Secondary Heartbeat: Heartbeat that allows enabling only specific SPARKs, but only gets
    // respected when the SPARK is not locked to the Universal Heartbeat or Primary Heartbeat
    spark_can_frame spark_build_SECONDARY_HEARTBEAT(uint8_t device_id, const Spark_SECONDARY_HEARTBEAT_t* values)
    {
        spark_can_frame out{};
        out.id                            = (uint32_t)(33893504u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                           = 8u;
        out.is_rtr                        = false;
        uint64_t _ENABLED_SPARKS_BITFIELD = values ? (uint64_t)values->ENABLED_SPARKS_BITFIELD : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 64u, _ENABLED_SPARKS_BITFIELD, false);
        return out;
    }

    // Build frame payload for USB Only Identify: The response will only be sent if this command is received directly
    // via USB. This has no relation to the normal Identify command, which displays an LED pattern.
    spark_can_frame spark_build_USB_ONLY_IDENTIFY(uint8_t device_id, const Spark_USB_ONLY_IDENTIFY_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33893568u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 0u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for USB Only Enter DFU Bootloader: Causes the device to reboot into the DFU bootloader if
    // this command is received directly via USB
    spark_can_frame spark_build_USB_ONLY_ENTER_DFU_BOOTLOADER(uint8_t                                      device_id,
                                                              const Spark_USB_ONLY_ENTER_DFU_BOOTLOADER_t* values)
    {
        spark_can_frame out{};
        out.id                 = (uint32_t)(33893632u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                = 2u;
        out.is_rtr             = false;
        uint64_t _MAGIC_NUMBER = values ? (uint64_t)values->MAGIC_NUMBER : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 16u, _MAGIC_NUMBER, false);
        return out;
    }

    // Build frame payload for Get Temperatures
    spark_can_frame spark_build_GET_TEMPERATURES(uint8_t device_id, const Spark_GET_TEMPERATURES_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33894400u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Get Motor Interface
    spark_can_frame spark_build_GET_MOTOR_INTERFACE(uint8_t device_id, const Spark_GET_MOTOR_INTERFACE_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33894720u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 3u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Get Parameter 0 to 15 Types: Get types of parameters 0 to 15
    spark_can_frame spark_build_GET_PARAMETER_0_TO_15_TYPES(uint8_t                                    device_id,
                                                            const Spark_GET_PARAMETER_0_TO_15_TYPES_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33895424u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Get Parameter 16 to 31 Types: Get types of parameters 16 to 31
    spark_can_frame spark_build_GET_PARAMETER_16_TO_31_TYPES(uint8_t                                     device_id,
                                                             const Spark_GET_PARAMETER_16_TO_31_TYPES_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33895488u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Get Parameter 32 to 47 Types: Get types of parameters 32 to 47
    spark_can_frame spark_build_GET_PARAMETER_32_TO_47_TYPES(uint8_t                                     device_id,
                                                             const Spark_GET_PARAMETER_32_TO_47_TYPES_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33895552u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Get Parameter 48 to 63 Types: Get types of parameters 48 to 63
    spark_can_frame spark_build_GET_PARAMETER_48_TO_63_TYPES(uint8_t                                     device_id,
                                                             const Spark_GET_PARAMETER_48_TO_63_TYPES_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33895616u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Get Parameter 64 to 79 Types: Get types of parameters 64 to 79
    spark_can_frame spark_build_GET_PARAMETER_64_TO_79_TYPES(uint8_t                                     device_id,
                                                             const Spark_GET_PARAMETER_64_TO_79_TYPES_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33895680u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Get Parameter 80 to 95 Types: Get types of parameters 80 to 95
    spark_can_frame spark_build_GET_PARAMETER_80_TO_95_TYPES(uint8_t                                     device_id,
                                                             const Spark_GET_PARAMETER_80_TO_95_TYPES_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33895744u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Get Parameter 96 to 111 Types: Get types of parameters 96 to 111
    spark_can_frame spark_build_GET_PARAMETER_96_TO_111_TYPES(uint8_t                                      device_id,
                                                              const Spark_GET_PARAMETER_96_TO_111_TYPES_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33895808u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Get Parameter 112 to 127 Types: Get types of parameters 112 to 127
    spark_can_frame spark_build_GET_PARAMETER_112_TO_127_TYPES(uint8_t                                       device_id,
                                                               const Spark_GET_PARAMETER_112_TO_127_TYPES_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33895872u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Get Parameter 128 to 143 Types: Get types of parameters 128 to 143
    spark_can_frame spark_build_GET_PARAMETER_128_TO_143_TYPES(uint8_t                                       device_id,
                                                               const Spark_GET_PARAMETER_128_TO_143_TYPES_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33895936u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Get Parameter 144 to 159 Types: Get types of parameters 144 to 159
    spark_can_frame spark_build_GET_PARAMETER_144_TO_159_TYPES(uint8_t                                       device_id,
                                                               const Spark_GET_PARAMETER_144_TO_159_TYPES_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33896000u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Get Parameter 160 to 175 Types: Get types of parameters 160 to 175
    spark_can_frame spark_build_GET_PARAMETER_160_TO_175_TYPES(uint8_t                                       device_id,
                                                               const Spark_GET_PARAMETER_160_TO_175_TYPES_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33896064u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Get Parameter 176 to 191 Types: Get types of parameters 176 to 191
    spark_can_frame spark_build_GET_PARAMETER_176_TO_191_TYPES(uint8_t                                       device_id,
                                                               const Spark_GET_PARAMETER_176_TO_191_TYPES_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33896128u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Get Parameter 192 to 207 Types: Get types of parameters 192 to 207
    spark_can_frame spark_build_GET_PARAMETER_192_TO_207_TYPES(uint8_t                                       device_id,
                                                               const Spark_GET_PARAMETER_192_TO_207_TYPES_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33896192u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Get Parameter 208 to 223 Types: Get types of parameters 208 to 223
    spark_can_frame spark_build_GET_PARAMETER_208_TO_223_TYPES(uint8_t                                       device_id,
                                                               const Spark_GET_PARAMETER_208_TO_223_TYPES_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33896256u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Get Parameter 224 to 239 Types: Get types of parameters 224 to 239
    spark_can_frame spark_build_GET_PARAMETER_224_TO_239_TYPES(uint8_t                                       device_id,
                                                               const Spark_GET_PARAMETER_224_TO_239_TYPES_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33896320u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Get Parameter 240 to 255 Types: Get types of parameters 240 to 255
    spark_can_frame spark_build_GET_PARAMETER_240_TO_255_TYPES(uint8_t                                       device_id,
                                                               const Spark_GET_PARAMETER_240_TO_255_TYPES_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33896384u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Parameter Write: Write a single parameter value. In response, a Parameter Write Response
    // frame will be sent.
    spark_can_frame spark_build_PARAMETER_WRITE(uint8_t device_id, const Spark_PARAMETER_WRITE_t* values)
    {
        spark_can_frame out{};
        out.id                 = (uint32_t)(33896448u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                = 5u;
        out.is_rtr             = false;
        uint64_t _PARAMETER_ID = values ? (uint64_t)values->PARAMETER_ID : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 8u, _PARAMETER_ID, false);
        uint64_t _VALUE = values ? (uint64_t)values->VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 8u, 32u, _VALUE, false);
        return out;
    }

    // Build frame payload for Parameter Write Response: Response for a parameter write (including a write done as part
    // of a dual-write)
    spark_can_frame spark_build_PARAMETER_WRITE_RESPONSE(uint8_t                                 device_id,
                                                         const Spark_PARAMETER_WRITE_RESPONSE_t* values)
    {
        spark_can_frame out{};
        out.id                 = (uint32_t)(33896512u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                = 7u;
        out.is_rtr             = false;
        uint64_t _PARAMETER_ID = values ? (uint64_t)values->PARAMETER_ID : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 8u, _PARAMETER_ID, false);
        uint64_t _PARAMETER_TYPE = values ? (uint64_t)values->PARAMETER_TYPE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 8u, 8u, _PARAMETER_TYPE, false);
        uint64_t _VALUE = values ? (uint64_t)values->VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 16u, 32u, _VALUE, false);
        uint64_t _RESULT_CODE = values ? (uint64_t)values->RESULT_CODE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 48u, 8u, _RESULT_CODE, false);
        return out;
    }

    // Build frame payload for Read Parameter 0 and 1: Read parameter 0 and 1 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_0_AND_1(uint8_t device_id, const Spark_READ_PARAMETER_0_AND_1_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33897472u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 2 and 3: Read parameter 2 and 3 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_2_AND_3(uint8_t device_id, const Spark_READ_PARAMETER_2_AND_3_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33897536u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 4 and 5: Read parameter 4 and 5 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_4_AND_5(uint8_t device_id, const Spark_READ_PARAMETER_4_AND_5_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33897600u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 6 and 7: Read parameter 6 and 7 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_6_AND_7(uint8_t device_id, const Spark_READ_PARAMETER_6_AND_7_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33897664u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 8 and 9: Read parameter 8 and 9 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_8_AND_9(uint8_t device_id, const Spark_READ_PARAMETER_8_AND_9_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33897728u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 10 and 11: Read parameter 10 and 11 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_10_AND_11(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_10_AND_11_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33897792u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 12 and 13: Read parameter 12 and 13 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_12_AND_13(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_12_AND_13_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33897856u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 14 and 15: Read parameter 14 and 15 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_14_AND_15(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_14_AND_15_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33897920u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 16 and 17: Read parameter 16 and 17 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_16_AND_17(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_16_AND_17_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33897984u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 18 and 19: Read parameter 18 and 19 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_18_AND_19(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_18_AND_19_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33898048u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 20 and 21: Read parameter 20 and 21 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_20_AND_21(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_20_AND_21_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33898112u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 22 and 23: Read parameter 22 and 23 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_22_AND_23(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_22_AND_23_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33898176u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 24 and 25: Read parameter 24 and 25 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_24_AND_25(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_24_AND_25_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33898240u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 26 and 27: Read parameter 26 and 27 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_26_AND_27(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_26_AND_27_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33898304u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 28 and 29: Read parameter 28 and 29 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_28_AND_29(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_28_AND_29_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33898368u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 30 and 31: Read parameter 30 and 31 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_30_AND_31(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_30_AND_31_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33898432u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 32 and 33: Read parameter 32 and 33 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_32_AND_33(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_32_AND_33_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33898496u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 34 and 35: Read parameter 34 and 35 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_34_AND_35(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_34_AND_35_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33898560u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 36 and 37: Read parameter 36 and 37 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_36_AND_37(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_36_AND_37_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33898624u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 38 and 39: Read parameter 38 and 39 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_38_AND_39(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_38_AND_39_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33898688u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 40 and 41: Read parameter 40 and 41 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_40_AND_41(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_40_AND_41_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33898752u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 42 and 43: Read parameter 42 and 43 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_42_AND_43(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_42_AND_43_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33898816u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 44 and 45: Read parameter 44 and 45 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_44_AND_45(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_44_AND_45_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33898880u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 46 and 47: Read parameter 46 and 47 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_46_AND_47(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_46_AND_47_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33898944u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 48 and 49: Read parameter 48 and 49 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_48_AND_49(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_48_AND_49_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33899008u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 50 and 51: Read parameter 50 and 51 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_50_AND_51(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_50_AND_51_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33899072u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 52 and 53: Read parameter 52 and 53 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_52_AND_53(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_52_AND_53_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33899136u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 54 and 55: Read parameter 54 and 55 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_54_AND_55(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_54_AND_55_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33899200u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 56 and 57: Read parameter 56 and 57 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_56_AND_57(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_56_AND_57_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33899264u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 58 and 59: Read parameter 58 and 59 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_58_AND_59(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_58_AND_59_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33899328u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 60 and 61: Read parameter 60 and 61 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_60_AND_61(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_60_AND_61_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33899392u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 62 and 63: Read parameter 62 and 63 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_62_AND_63(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_62_AND_63_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33899456u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 64 and 65: Read parameter 64 and 65 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_64_AND_65(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_64_AND_65_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33899520u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 66 and 67: Read parameter 66 and 67 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_66_AND_67(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_66_AND_67_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33899584u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 68 and 69: Read parameter 68 and 69 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_68_AND_69(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_68_AND_69_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33899648u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 70 and 71: Read parameter 70 and 71 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_70_AND_71(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_70_AND_71_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33899712u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 72 and 73: Read parameter 72 and 73 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_72_AND_73(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_72_AND_73_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33899776u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 74 and 75: Read parameter 74 and 75 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_74_AND_75(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_74_AND_75_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33899840u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 76 and 77: Read parameter 76 and 77 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_76_AND_77(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_76_AND_77_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33899904u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 78 and 79: Read parameter 78 and 79 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_78_AND_79(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_78_AND_79_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33899968u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 80 and 81: Read parameter 80 and 81 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_80_AND_81(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_80_AND_81_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33900032u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 82 and 83: Read parameter 82 and 83 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_82_AND_83(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_82_AND_83_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33900096u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 84 and 85: Read parameter 84 and 85 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_84_AND_85(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_84_AND_85_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33900160u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 86 and 87: Read parameter 86 and 87 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_86_AND_87(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_86_AND_87_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33900224u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 88 and 89: Read parameter 88 and 89 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_88_AND_89(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_88_AND_89_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33900288u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 90 and 91: Read parameter 90 and 91 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_90_AND_91(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_90_AND_91_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33900352u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 92 and 93: Read parameter 92 and 93 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_92_AND_93(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_92_AND_93_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33900416u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 94 and 95: Read parameter 94 and 95 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_94_AND_95(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_94_AND_95_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33900480u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 96 and 97: Read parameter 96 and 97 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_96_AND_97(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_96_AND_97_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33900544u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 98 and 99: Read parameter 98 and 99 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_98_AND_99(uint8_t                                 device_id,
                                                         const Spark_READ_PARAMETER_98_AND_99_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33900608u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 100 and 101: Read parameter 100 and 101 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_100_AND_101(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_100_AND_101_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33900672u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 102 and 103: Read parameter 102 and 103 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_102_AND_103(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_102_AND_103_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33900736u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 104 and 105: Read parameter 104 and 105 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_104_AND_105(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_104_AND_105_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33900800u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 106 and 107: Read parameter 106 and 107 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_106_AND_107(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_106_AND_107_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33900864u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 108 and 109: Read parameter 108 and 109 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_108_AND_109(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_108_AND_109_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33900928u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 110 and 111: Read parameter 110 and 111 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_110_AND_111(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_110_AND_111_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33900992u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 112 and 113: Read parameter 112 and 113 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_112_AND_113(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_112_AND_113_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33901056u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 114 and 115: Read parameter 114 and 115 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_114_AND_115(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_114_AND_115_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33901120u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 116 and 117: Read parameter 116 and 117 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_116_AND_117(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_116_AND_117_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33901184u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 118 and 119: Read parameter 118 and 119 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_118_AND_119(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_118_AND_119_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33901248u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 120 and 121: Read parameter 120 and 121 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_120_AND_121(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_120_AND_121_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33901312u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 122 and 123: Read parameter 122 and 123 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_122_AND_123(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_122_AND_123_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33901376u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 124 and 125: Read parameter 124 and 125 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_124_AND_125(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_124_AND_125_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33901440u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 126 and 127: Read parameter 126 and 127 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_126_AND_127(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_126_AND_127_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33901504u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 128 and 129: Read parameter 128 and 129 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_128_AND_129(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_128_AND_129_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33901568u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 130 and 131: Read parameter 130 and 131 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_130_AND_131(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_130_AND_131_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33901632u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 132 and 133: Read parameter 132 and 133 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_132_AND_133(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_132_AND_133_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33901696u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 134 and 135: Read parameter 134 and 135 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_134_AND_135(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_134_AND_135_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33901760u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 136 and 137: Read parameter 136 and 137 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_136_AND_137(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_136_AND_137_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33901824u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 138 and 139: Read parameter 138 and 139 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_138_AND_139(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_138_AND_139_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33901888u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 140 and 141: Read parameter 140 and 141 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_140_AND_141(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_140_AND_141_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33901952u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 142 and 143: Read parameter 142 and 143 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_142_AND_143(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_142_AND_143_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33902016u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 144 and 145: Read parameter 144 and 145 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_144_AND_145(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_144_AND_145_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33902080u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 146 and 147: Read parameter 146 and 147 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_146_AND_147(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_146_AND_147_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33902144u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 148 and 149: Read parameter 148 and 149 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_148_AND_149(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_148_AND_149_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33902208u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 150 and 151: Read parameter 150 and 151 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_150_AND_151(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_150_AND_151_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33902272u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 152 and 153: Read parameter 152 and 153 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_152_AND_153(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_152_AND_153_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33902336u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 154 and 155: Read parameter 154 and 155 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_154_AND_155(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_154_AND_155_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33902400u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 156 and 157: Read parameter 156 and 157 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_156_AND_157(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_156_AND_157_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33902464u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 158 and 159: Read parameter 158 and 159 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_158_AND_159(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_158_AND_159_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33902528u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 160 and 161: Read parameter 160 and 161 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_160_AND_161(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_160_AND_161_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33902592u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 162 and 163: Read parameter 162 and 163 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_162_AND_163(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_162_AND_163_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33902656u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 164 and 165: Read parameter 164 and 165 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_164_AND_165(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_164_AND_165_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33902720u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 166 and 167: Read parameter 166 and 167 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_166_AND_167(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_166_AND_167_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33902784u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 168 and 169: Read parameter 168 and 169 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_168_AND_169(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_168_AND_169_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33902848u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 170 and 171: Read parameter 170 and 171 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_170_AND_171(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_170_AND_171_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33902912u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 172 and 173: Read parameter 172 and 173 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_172_AND_173(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_172_AND_173_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33902976u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 174 and 175: Read parameter 174 and 175 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_174_AND_175(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_174_AND_175_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33903040u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 176 and 177: Read parameter 176 and 177 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_176_AND_177(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_176_AND_177_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33903104u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 178 and 179: Read parameter 178 and 179 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_178_AND_179(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_178_AND_179_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33903168u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 180 and 181: Read parameter 180 and 181 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_180_AND_181(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_180_AND_181_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33903232u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 182 and 183: Read parameter 182 and 183 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_182_AND_183(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_182_AND_183_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33903296u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 184 and 185: Read parameter 184 and 185 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_184_AND_185(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_184_AND_185_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33903360u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 186 and 187: Read parameter 186 and 187 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_186_AND_187(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_186_AND_187_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33903424u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 188 and 189: Read parameter 188 and 189 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_188_AND_189(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_188_AND_189_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33903488u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 190 and 191: Read parameter 190 and 191 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_190_AND_191(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_190_AND_191_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33903552u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 192 and 193: Read parameter 192 and 193 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_192_AND_193(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_192_AND_193_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33903616u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 194 and 195: Read parameter 194 and 195 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_194_AND_195(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_194_AND_195_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33903680u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 196 and 197: Read parameter 196 and 197 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_196_AND_197(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_196_AND_197_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33903744u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 198 and 199: Read parameter 198 and 199 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_198_AND_199(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_198_AND_199_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33903808u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 200 and 201: Read parameter 200 and 201 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_200_AND_201(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_200_AND_201_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33903872u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 202 and 203: Read parameter 202 and 203 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_202_AND_203(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_202_AND_203_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33903936u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 204 and 205: Read parameter 204 and 205 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_204_AND_205(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_204_AND_205_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33904000u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 206 and 207: Read parameter 206 and 207 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_206_AND_207(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_206_AND_207_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33904064u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 208 and 209: Read parameter 208 and 209 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_208_AND_209(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_208_AND_209_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33904128u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 210 and 211: Read parameter 210 and 211 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_210_AND_211(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_210_AND_211_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33904192u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 212 and 213: Read parameter 212 and 213 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_212_AND_213(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_212_AND_213_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33904256u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 214 and 215: Read parameter 214 and 215 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_214_AND_215(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_214_AND_215_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33904320u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 216 and 217: Read parameter 216 and 217 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_216_AND_217(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_216_AND_217_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33904384u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 218 and 219: Read parameter 218 and 219 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_218_AND_219(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_218_AND_219_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33904448u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 220 and 221: Read parameter 220 and 221 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_220_AND_221(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_220_AND_221_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33904512u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 222 and 223: Read parameter 222 and 223 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_222_AND_223(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_222_AND_223_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33904576u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 224 and 225: Read parameter 224 and 225 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_224_AND_225(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_224_AND_225_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33904640u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 226 and 227: Read parameter 226 and 227 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_226_AND_227(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_226_AND_227_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33904704u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 228 and 229: Read parameter 228 and 229 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_228_AND_229(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_228_AND_229_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33904768u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 230 and 231: Read parameter 230 and 231 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_230_AND_231(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_230_AND_231_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33904832u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 232 and 233: Read parameter 232 and 233 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_232_AND_233(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_232_AND_233_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33904896u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 234 and 235: Read parameter 234 and 235 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_234_AND_235(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_234_AND_235_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33904960u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 236 and 237: Read parameter 236 and 237 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_236_AND_237(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_236_AND_237_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33905024u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 238 and 239: Read parameter 238 and 239 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_238_AND_239(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_238_AND_239_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33905088u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 240 and 241: Read parameter 240 and 241 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_240_AND_241(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_240_AND_241_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33905152u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 242 and 243: Read parameter 242 and 243 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_242_AND_243(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_242_AND_243_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33905216u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 244 and 245: Read parameter 244 and 245 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_244_AND_245(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_244_AND_245_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33905280u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 246 and 247: Read parameter 246 and 247 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_246_AND_247(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_246_AND_247_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33905344u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 248 and 249: Read parameter 248 and 249 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_248_AND_249(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_248_AND_249_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33905408u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 250 and 251: Read parameter 250 and 251 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_250_AND_251(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_250_AND_251_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33905472u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 252 and 253: Read parameter 252 and 253 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_252_AND_253(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_252_AND_253_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33905536u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Read Parameter 254 and 255: Read parameter 254 and 255 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    spark_can_frame spark_build_READ_PARAMETER_254_AND_255(uint8_t                                   device_id,
                                                           const Spark_READ_PARAMETER_254_AND_255_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33905600u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 8u;
        out.is_rtr = true;
        return out;
    }

    // Build frame payload for Write Parameter 0 and 1: Write Parameter 0 and 1 at the same time. Two Write Parameter
    // Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_0_AND_1(uint8_t                                device_id,
                                                        const Spark_WRITE_PARAMETER_0_AND_1_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33905664u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 2 and 3: Write Parameter 2 and 3 at the same time. Two Write Parameter
    // Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_2_AND_3(uint8_t                                device_id,
                                                        const Spark_WRITE_PARAMETER_2_AND_3_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33905728u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 4 and 5: Write Parameter 4 and 5 at the same time. Two Write Parameter
    // Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_4_AND_5(uint8_t                                device_id,
                                                        const Spark_WRITE_PARAMETER_4_AND_5_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33905792u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 6 and 7: Write Parameter 6 and 7 at the same time. Two Write Parameter
    // Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_6_AND_7(uint8_t                                device_id,
                                                        const Spark_WRITE_PARAMETER_6_AND_7_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33905856u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 8 and 9: Write Parameter 8 and 9 at the same time. Two Write Parameter
    // Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_8_AND_9(uint8_t                                device_id,
                                                        const Spark_WRITE_PARAMETER_8_AND_9_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33905920u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 10 and 11: Write Parameter 10 and 11 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_10_AND_11(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_10_AND_11_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33905984u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 12 and 13: Write Parameter 12 and 13 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_12_AND_13(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_12_AND_13_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33906048u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 14 and 15: Write Parameter 14 and 15 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_14_AND_15(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_14_AND_15_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33906112u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 16 and 17: Write Parameter 16 and 17 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_16_AND_17(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_16_AND_17_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33906176u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 18 and 19: Write Parameter 18 and 19 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_18_AND_19(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_18_AND_19_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33906240u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 20 and 21: Write Parameter 20 and 21 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_20_AND_21(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_20_AND_21_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33906304u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 22 and 23: Write Parameter 22 and 23 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_22_AND_23(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_22_AND_23_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33906368u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 24 and 25: Write Parameter 24 and 25 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_24_AND_25(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_24_AND_25_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33906432u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 26 and 27: Write Parameter 26 and 27 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_26_AND_27(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_26_AND_27_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33906496u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 28 and 29: Write Parameter 28 and 29 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_28_AND_29(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_28_AND_29_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33906560u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 30 and 31: Write Parameter 30 and 31 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_30_AND_31(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_30_AND_31_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33906624u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 32 and 33: Write Parameter 32 and 33 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_32_AND_33(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_32_AND_33_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33906688u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 34 and 35: Write Parameter 34 and 35 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_34_AND_35(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_34_AND_35_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33906752u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 36 and 37: Write Parameter 36 and 37 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_36_AND_37(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_36_AND_37_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33906816u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 38 and 39: Write Parameter 38 and 39 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_38_AND_39(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_38_AND_39_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33906880u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 40 and 41: Write Parameter 40 and 41 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_40_AND_41(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_40_AND_41_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33906944u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 42 and 43: Write Parameter 42 and 43 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_42_AND_43(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_42_AND_43_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33907008u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 44 and 45: Write Parameter 44 and 45 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_44_AND_45(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_44_AND_45_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33907072u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 46 and 47: Write Parameter 46 and 47 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_46_AND_47(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_46_AND_47_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33907136u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 48 and 49: Write Parameter 48 and 49 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_48_AND_49(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_48_AND_49_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33907200u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 50 and 51: Write Parameter 50 and 51 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_50_AND_51(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_50_AND_51_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33907264u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 52 and 53: Write Parameter 52 and 53 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_52_AND_53(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_52_AND_53_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33907328u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 54 and 55: Write Parameter 54 and 55 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_54_AND_55(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_54_AND_55_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33907392u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 56 and 57: Write Parameter 56 and 57 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_56_AND_57(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_56_AND_57_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33907456u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 58 and 59: Write Parameter 58 and 59 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_58_AND_59(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_58_AND_59_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33907520u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 60 and 61: Write Parameter 60 and 61 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_60_AND_61(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_60_AND_61_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33907584u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 62 and 63: Write Parameter 62 and 63 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_62_AND_63(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_62_AND_63_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33907648u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 64 and 65: Write Parameter 64 and 65 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_64_AND_65(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_64_AND_65_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33907712u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 66 and 67: Write Parameter 66 and 67 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_66_AND_67(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_66_AND_67_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33907776u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 68 and 69: Write Parameter 68 and 69 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_68_AND_69(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_68_AND_69_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33907840u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 70 and 71: Write Parameter 70 and 71 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_70_AND_71(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_70_AND_71_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33907904u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 72 and 73: Write Parameter 72 and 73 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_72_AND_73(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_72_AND_73_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33907968u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 74 and 75: Write Parameter 74 and 75 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_74_AND_75(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_74_AND_75_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33908032u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 76 and 77: Write Parameter 76 and 77 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_76_AND_77(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_76_AND_77_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33908096u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 78 and 79: Write Parameter 78 and 79 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_78_AND_79(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_78_AND_79_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33908160u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 80 and 81: Write Parameter 80 and 81 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_80_AND_81(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_80_AND_81_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33908224u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 82 and 83: Write Parameter 82 and 83 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_82_AND_83(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_82_AND_83_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33908288u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 84 and 85: Write Parameter 84 and 85 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_84_AND_85(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_84_AND_85_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33908352u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 86 and 87: Write Parameter 86 and 87 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_86_AND_87(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_86_AND_87_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33908416u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 88 and 89: Write Parameter 88 and 89 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_88_AND_89(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_88_AND_89_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33908480u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 90 and 91: Write Parameter 90 and 91 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_90_AND_91(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_90_AND_91_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33908544u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 92 and 93: Write Parameter 92 and 93 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_92_AND_93(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_92_AND_93_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33908608u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 94 and 95: Write Parameter 94 and 95 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_94_AND_95(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_94_AND_95_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33908672u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 96 and 97: Write Parameter 96 and 97 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_96_AND_97(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_96_AND_97_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33908736u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 98 and 99: Write Parameter 98 and 99 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_98_AND_99(uint8_t                                  device_id,
                                                          const Spark_WRITE_PARAMETER_98_AND_99_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33908800u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 100 and 101: Write Parameter 100 and 101 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_100_AND_101(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_100_AND_101_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33908864u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 102 and 103: Write Parameter 102 and 103 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_102_AND_103(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_102_AND_103_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33908928u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 104 and 105: Write Parameter 104 and 105 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_104_AND_105(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_104_AND_105_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33908992u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 106 and 107: Write Parameter 106 and 107 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_106_AND_107(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_106_AND_107_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33909056u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 108 and 109: Write Parameter 108 and 109 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_108_AND_109(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_108_AND_109_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33909120u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 110 and 111: Write Parameter 110 and 111 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_110_AND_111(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_110_AND_111_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33909184u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 112 and 113: Write Parameter 112 and 113 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_112_AND_113(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_112_AND_113_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33909248u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 114 and 115: Write Parameter 114 and 115 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_114_AND_115(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_114_AND_115_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33909312u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 116 and 117: Write Parameter 116 and 117 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_116_AND_117(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_116_AND_117_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33909376u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 118 and 119: Write Parameter 118 and 119 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_118_AND_119(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_118_AND_119_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33909440u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 120 and 121: Write Parameter 120 and 121 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_120_AND_121(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_120_AND_121_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33909504u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 122 and 123: Write Parameter 122 and 123 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_122_AND_123(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_122_AND_123_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33909568u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 124 and 125: Write Parameter 124 and 125 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_124_AND_125(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_124_AND_125_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33909632u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 126 and 127: Write Parameter 126 and 127 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_126_AND_127(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_126_AND_127_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33909696u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 128 and 129: Write Parameter 128 and 129 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_128_AND_129(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_128_AND_129_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33909760u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 130 and 131: Write Parameter 130 and 131 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_130_AND_131(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_130_AND_131_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33909824u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 132 and 133: Write Parameter 132 and 133 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_132_AND_133(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_132_AND_133_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33909888u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 134 and 135: Write Parameter 134 and 135 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_134_AND_135(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_134_AND_135_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33909952u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 136 and 137: Write Parameter 136 and 137 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_136_AND_137(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_136_AND_137_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33910016u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 138 and 139: Write Parameter 138 and 139 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_138_AND_139(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_138_AND_139_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33910080u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 140 and 141: Write Parameter 140 and 141 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_140_AND_141(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_140_AND_141_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33910144u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 142 and 143: Write Parameter 142 and 143 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_142_AND_143(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_142_AND_143_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33910208u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 144 and 145: Write Parameter 144 and 145 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_144_AND_145(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_144_AND_145_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33910272u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 146 and 147: Write Parameter 146 and 147 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_146_AND_147(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_146_AND_147_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33910336u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 148 and 149: Write Parameter 148 and 149 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_148_AND_149(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_148_AND_149_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33910400u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 150 and 151: Write Parameter 150 and 151 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_150_AND_151(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_150_AND_151_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33910464u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 152 and 153: Write Parameter 152 and 153 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_152_AND_153(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_152_AND_153_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33910528u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 154 and 155: Write Parameter 154 and 155 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_154_AND_155(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_154_AND_155_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33910592u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 156 and 157: Write Parameter 156 and 157 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_156_AND_157(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_156_AND_157_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33910656u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 158 and 159: Write Parameter 158 and 159 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_158_AND_159(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_158_AND_159_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33910720u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 160 and 161: Write Parameter 160 and 161 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_160_AND_161(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_160_AND_161_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33910784u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 162 and 163: Write Parameter 162 and 163 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_162_AND_163(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_162_AND_163_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33910848u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 164 and 165: Write Parameter 164 and 165 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_164_AND_165(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_164_AND_165_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33910912u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 166 and 167: Write Parameter 166 and 167 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_166_AND_167(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_166_AND_167_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33910976u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 168 and 169: Write Parameter 168 and 169 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_168_AND_169(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_168_AND_169_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33911040u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 170 and 171: Write Parameter 170 and 171 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_170_AND_171(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_170_AND_171_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33911104u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 172 and 173: Write Parameter 172 and 173 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_172_AND_173(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_172_AND_173_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33911168u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 174 and 175: Write Parameter 174 and 175 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_174_AND_175(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_174_AND_175_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33911232u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 176 and 177: Write Parameter 176 and 177 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_176_AND_177(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_176_AND_177_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33911296u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 178 and 179: Write Parameter 178 and 179 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_178_AND_179(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_178_AND_179_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33911360u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 180 and 181: Write Parameter 180 and 181 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_180_AND_181(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_180_AND_181_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33911424u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 182 and 183: Write Parameter 182 and 183 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_182_AND_183(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_182_AND_183_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33911488u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 184 and 185: Write Parameter 184 and 185 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_184_AND_185(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_184_AND_185_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33911552u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 186 and 187: Write Parameter 186 and 187 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_186_AND_187(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_186_AND_187_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33911616u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 188 and 189: Write Parameter 188 and 189 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_188_AND_189(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_188_AND_189_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33911680u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 190 and 191: Write Parameter 190 and 191 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_190_AND_191(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_190_AND_191_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33911744u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 192 and 193: Write Parameter 192 and 193 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_192_AND_193(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_192_AND_193_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33911808u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 194 and 195: Write Parameter 194 and 195 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_194_AND_195(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_194_AND_195_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33911872u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 196 and 197: Write Parameter 196 and 197 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_196_AND_197(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_196_AND_197_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33911936u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 198 and 199: Write Parameter 198 and 199 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_198_AND_199(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_198_AND_199_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33912000u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 200 and 201: Write Parameter 200 and 201 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_200_AND_201(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_200_AND_201_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33912064u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 202 and 203: Write Parameter 202 and 203 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_202_AND_203(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_202_AND_203_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33912128u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 204 and 205: Write Parameter 204 and 205 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_204_AND_205(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_204_AND_205_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33912192u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 206 and 207: Write Parameter 206 and 207 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_206_AND_207(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_206_AND_207_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33912256u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 208 and 209: Write Parameter 208 and 209 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_208_AND_209(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_208_AND_209_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33912320u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 210 and 211: Write Parameter 210 and 211 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_210_AND_211(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_210_AND_211_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33912384u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 212 and 213: Write Parameter 212 and 213 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_212_AND_213(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_212_AND_213_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33912448u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 214 and 215: Write Parameter 214 and 215 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_214_AND_215(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_214_AND_215_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33912512u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 216 and 217: Write Parameter 216 and 217 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_216_AND_217(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_216_AND_217_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33912576u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 218 and 219: Write Parameter 218 and 219 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_218_AND_219(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_218_AND_219_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33912640u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 220 and 221: Write Parameter 220 and 221 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_220_AND_221(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_220_AND_221_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33912704u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 222 and 223: Write Parameter 222 and 223 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_222_AND_223(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_222_AND_223_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33912768u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 224 and 225: Write Parameter 224 and 225 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_224_AND_225(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_224_AND_225_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33912832u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 226 and 227: Write Parameter 226 and 227 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_226_AND_227(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_226_AND_227_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33912896u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 228 and 229: Write Parameter 228 and 229 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_228_AND_229(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_228_AND_229_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33912960u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 230 and 231: Write Parameter 230 and 231 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_230_AND_231(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_230_AND_231_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33913024u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 232 and 233: Write Parameter 232 and 233 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_232_AND_233(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_232_AND_233_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33913088u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 234 and 235: Write Parameter 234 and 235 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_234_AND_235(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_234_AND_235_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33913152u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 236 and 237: Write Parameter 236 and 237 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_236_AND_237(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_236_AND_237_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33913216u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 238 and 239: Write Parameter 238 and 239 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_238_AND_239(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_238_AND_239_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33913280u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 240 and 241: Write Parameter 240 and 241 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_240_AND_241(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_240_AND_241_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33913344u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 242 and 243: Write Parameter 242 and 243 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_242_AND_243(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_242_AND_243_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33913408u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 244 and 245: Write Parameter 244 and 245 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_244_AND_245(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_244_AND_245_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33913472u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 246 and 247: Write Parameter 246 and 247 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_246_AND_247(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_246_AND_247_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33913536u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 248 and 249: Write Parameter 248 and 249 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_248_AND_249(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_248_AND_249_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33913600u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 250 and 251: Write Parameter 250 and 251 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_250_AND_251(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_250_AND_251_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33913664u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 252 and 253: Write Parameter 252 and 253 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_252_AND_253(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_252_AND_253_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33913728u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Write Parameter 254 and 255: Write Parameter 254 and 255 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    spark_can_frame spark_build_WRITE_PARAMETER_254_AND_255(uint8_t                                    device_id,
                                                            const Spark_WRITE_PARAMETER_254_AND_255_t* values)
    {
        spark_can_frame out{};
        out.id                          = (uint32_t)(33913792u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                         = 8u;
        out.is_rtr                      = false;
        uint64_t _FIRST_PARAMETER_VALUE = values ? (uint64_t)values->FIRST_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 32u, _FIRST_PARAMETER_VALUE, false);
        uint64_t _SECOND_PARAMETER_VALUE = values ? (uint64_t)values->SECOND_PARAMETER_VALUE : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 32u, 32u, _SECOND_PARAMETER_VALUE, false);
        return out;
    }

    // Build frame payload for Start Follower Mode: Starts follower mode. The relevant parameters must already be
    // configured. In response, a Start Follower Mode Response frame will be sent. Follower mode will be auto-started on
    // boot if the Follower Mode Leader ID parameter is set to a non-zero value.
    spark_can_frame spark_build_START_FOLLOWER_MODE(uint8_t device_id, const Spark_START_FOLLOWER_MODE_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33913856u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 0u;
        out.is_rtr = false;
        return out;
    }

    // Build frame payload for Start Follower Mode Response: Response for a Start Follower Mode command
    spark_can_frame spark_build_START_FOLLOWER_MODE_RESPONSE(uint8_t                                     device_id,
                                                             const Spark_START_FOLLOWER_MODE_RESPONSE_t* values)
    {
        spark_can_frame out{};
        out.id           = (uint32_t)(33913920u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc          = 1u;
        out.is_rtr       = false;
        uint64_t _STATUS = values ? (uint64_t)values->STATUS : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 8u, _STATUS, false);
        return out;
    }

    // Build frame payload for Stop Follower Mode: Exits follower mode and causes the device to resume listening for
    // setpoints addressed directly to it. In response, a Stop Follower Mode Response frame will be sent.
    spark_can_frame spark_build_STOP_FOLLOWER_MODE(uint8_t device_id, const Spark_STOP_FOLLOWER_MODE_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33913984u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 0u;
        out.is_rtr = false;
        return out;
    }

    // Build frame payload for Stop Follower Mode Response: Response for a Stop Follower Mode Command
    spark_can_frame spark_build_STOP_FOLLOWER_MODE_RESPONSE(uint8_t                                    device_id,
                                                            const Spark_STOP_FOLLOWER_MODE_RESPONSE_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33914048u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 0u;
        out.is_rtr = false;
        return out;
    }

    // Build frame payload for Enter SWDL CAN Bootloader
    spark_can_frame spark_build_ENTER_SWDL_CAN_BOOTLOADER(uint8_t                                  device_id,
                                                          const Spark_ENTER_SWDL_CAN_BOOTLOADER_t* values)
    {
        spark_can_frame out{};
        out.id     = (uint32_t)(33914816u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc    = 0u;
        out.is_rtr = false;
        return out;
    }

    // Build frame payload for Persist Parameters: Causes all parameters to be written to non-volatile storage. After
    // the operation (which may take up to a second) completes, a Persist Parameters Response frame will be sent.
    spark_can_frame spark_build_PERSIST_PARAMETERS(uint8_t device_id, const Spark_PERSIST_PARAMETERS_t* values)
    {
        spark_can_frame out{};
        out.id                 = (uint32_t)(33947584u) | ((uint32_t)device_id & SPARK_DEVICE_ID_MASK);
        out.dlc                = 2u;
        out.is_rtr             = false;
        uint64_t _MAGIC_NUMBER = values ? (uint64_t)values->MAGIC_NUMBER : 0ull;
        ::CanControl::LowLevel::pack_field(out.data, 0u, 16u, _MAGIC_NUMBER, false);
        return out;
    }

    // Decode frame payload for Legacy Status 0: This frame exists purely to inform old software that is not aware of
    // firmware version 25+ that the SPARK is present
    bool spark_decode_LEGACY_STATUS_0(const uint8_t* data, uint8_t dlc, Spark_LEGACY_STATUS_0_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->APPLIED_OUTPUT           = ::CanControl::LowLevel::unpack_field(data, 0u, 16u, false);
        out->FAULTS_AND_STICKY_FAULTS = ::CanControl::LowLevel::unpack_field(data, 16u, 32u, false);
        out->OTHER_SIGNALS            = ::CanControl::LowLevel::unpack_field(data, 48u, 16u, false);
        return true;
    }

    // Decode frame payload for Bootloader 0: Periodic frame when device is in the bootloader
    bool spark_decode_BOOTLOADER_0(const uint8_t* data, uint8_t dlc, Spark_BOOTLOADER_0_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->BL_MAJOR   = ::CanControl::LowLevel::unpack_field(data, 0u, 8u, false);
        out->BL_MINOR   = ::CanControl::LowLevel::unpack_field(data, 8u, 8u, false);
        out->PRODUCT_ID = ::CanControl::LowLevel::unpack_field(data, 16u, 16u, false);
        out->RSVD       = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Status 0: Includes general data that is likely to need frequent refreshing
    bool spark_decode_STATUS_0(const uint8_t* data, uint8_t dlc, Spark_STATUS_0_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        uint64_t _APPLIED_OUTPUT_u = ::CanControl::LowLevel::unpack_field(data, 0u, 16u, false);
        if (16u < 64u && (_APPLIED_OUTPUT_u & (1ull << (16u - 1u))))
        {
            _APPLIED_OUTPUT_u |= ~((1ull << 16) - 1ull);
        }
        out->APPLIED_OUTPUT             = (int64_t)_APPLIED_OUTPUT_u;
        out->VOLTAGE                    = ::CanControl::LowLevel::unpack_field(data, 16u, 12u, false);
        out->CURRENT                    = ::CanControl::LowLevel::unpack_field(data, 28u, 12u, false);
        out->MOTOR_TEMPERATURE          = ::CanControl::LowLevel::unpack_field(data, 40u, 8u, false);
        out->HARD_FORWARD_LIMIT_REACHED = ::CanControl::LowLevel::unpack_field(data, 48u, 1u, false) ? true : false;
        out->HARD_REVERSE_LIMIT_REACHED = ::CanControl::LowLevel::unpack_field(data, 49u, 1u, false) ? true : false;
        out->SOFT_FORWARD_LIMIT_REACHED = ::CanControl::LowLevel::unpack_field(data, 50u, 1u, false) ? true : false;
        out->SOFT_REVERSE_LIMIT_REACHED = ::CanControl::LowLevel::unpack_field(data, 51u, 1u, false) ? true : false;
        out->INVERTED                   = ::CanControl::LowLevel::unpack_field(data, 52u, 1u, false) ? true : false;
        out->PRIMARY_HEARTBEAT_LOCK     = ::CanControl::LowLevel::unpack_field(data, 53u, 1u, false) ? true : false;
        out->SPARK_MODEL                = ::CanControl::LowLevel::unpack_field(data, 54u, 4u, false);
        return true;
    }

    // Decode frame payload for Status 1: Includes general data that can likely tolerate infrequent refreshing
    bool spark_decode_STATUS_1(const uint8_t* data, uint8_t dlc, Spark_STATUS_1_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->OTHER_FAULT                = ::CanControl::LowLevel::unpack_field(data, 0u, 1u, false) ? true : false;
        out->MOTOR_TYPE_FAULT           = ::CanControl::LowLevel::unpack_field(data, 1u, 1u, false) ? true : false;
        out->SENSOR_FAULT               = ::CanControl::LowLevel::unpack_field(data, 2u, 1u, false) ? true : false;
        out->CAN_FAULT                  = ::CanControl::LowLevel::unpack_field(data, 3u, 1u, false) ? true : false;
        out->TEMPERATURE_FAULT          = ::CanControl::LowLevel::unpack_field(data, 4u, 1u, false) ? true : false;
        out->DRV_FAULT                  = ::CanControl::LowLevel::unpack_field(data, 5u, 1u, false) ? true : false;
        out->ESC_EEPROM_FAULT           = ::CanControl::LowLevel::unpack_field(data, 6u, 1u, false) ? true : false;
        out->FIRMWARE_FAULT             = ::CanControl::LowLevel::unpack_field(data, 7u, 1u, false) ? true : false;
        out->BROWNOUT_WARNING           = ::CanControl::LowLevel::unpack_field(data, 16u, 1u, false) ? true : false;
        out->OVERCURRENT_WARNING        = ::CanControl::LowLevel::unpack_field(data, 17u, 1u, false) ? true : false;
        out->ESC_EEPROM_WARNING         = ::CanControl::LowLevel::unpack_field(data, 18u, 1u, false) ? true : false;
        out->EXT_EEPROM_WARNING         = ::CanControl::LowLevel::unpack_field(data, 19u, 1u, false) ? true : false;
        out->SENSOR_WARNING             = ::CanControl::LowLevel::unpack_field(data, 20u, 1u, false) ? true : false;
        out->STALL_WARNING              = ::CanControl::LowLevel::unpack_field(data, 21u, 1u, false) ? true : false;
        out->HAS_RESET_WARNING          = ::CanControl::LowLevel::unpack_field(data, 22u, 1u, false) ? true : false;
        out->OTHER_WARNING              = ::CanControl::LowLevel::unpack_field(data, 23u, 1u, false) ? true : false;
        out->OTHER_STICKY_FAULT         = ::CanControl::LowLevel::unpack_field(data, 24u, 1u, false) ? true : false;
        out->MOTOR_TYPE_STICKY_FAULT    = ::CanControl::LowLevel::unpack_field(data, 25u, 1u, false) ? true : false;
        out->SENSOR_STICKY_FAULT        = ::CanControl::LowLevel::unpack_field(data, 26u, 1u, false) ? true : false;
        out->CAN_STICKY_FAULT           = ::CanControl::LowLevel::unpack_field(data, 27u, 1u, false) ? true : false;
        out->TEMPERATURE_STICKY_FAULT   = ::CanControl::LowLevel::unpack_field(data, 28u, 1u, false) ? true : false;
        out->DRV_STICKY_FAULT           = ::CanControl::LowLevel::unpack_field(data, 29u, 1u, false) ? true : false;
        out->ESC_EEPROM_STICKY_FAULT    = ::CanControl::LowLevel::unpack_field(data, 30u, 1u, false) ? true : false;
        out->FIRMWARE_STICKY_FAULT      = ::CanControl::LowLevel::unpack_field(data, 31u, 1u, false) ? true : false;
        out->BROWNOUT_STICKY_WARNING    = ::CanControl::LowLevel::unpack_field(data, 40u, 1u, false) ? true : false;
        out->OVERCURRENT_STICKY_WARNING = ::CanControl::LowLevel::unpack_field(data, 41u, 1u, false) ? true : false;
        out->ESC_EEPROM_STICKY_WARNING  = ::CanControl::LowLevel::unpack_field(data, 42u, 1u, false) ? true : false;
        out->EXT_EEPROM_STICKY_WARNING  = ::CanControl::LowLevel::unpack_field(data, 43u, 1u, false) ? true : false;
        out->SENSOR_STICKY_WARNING      = ::CanControl::LowLevel::unpack_field(data, 44u, 1u, false) ? true : false;
        out->STALL_STICKY_WARNING       = ::CanControl::LowLevel::unpack_field(data, 45u, 1u, false) ? true : false;
        out->HAS_RESET_STICKY_WARNING   = ::CanControl::LowLevel::unpack_field(data, 46u, 1u, false) ? true : false;
        out->OTHER_STICKY_WARNING       = ::CanControl::LowLevel::unpack_field(data, 47u, 1u, false) ? true : false;
        out->IS_FOLLOWER                = ::CanControl::LowLevel::unpack_field(data, 48u, 1u, false) ? true : false;
        return true;
    }

    // Decode frame payload for Status 2: Includes data from the primary encoder (either a brushless motor's internal
    // encoder, or the primary encoder associated with a brushed motor)
    bool spark_decode_STATUS_2(const uint8_t* data, uint8_t dlc, Spark_STATUS_2_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        uint32_t _PRIMARY_ENCODER_VELOCITY_u = (uint32_t)::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        union
        {
            uint32_t u;
            float    f;
        } _PRIMARY_ENCODER_VELOCITY          = {.u = _PRIMARY_ENCODER_VELOCITY_u};
        out->PRIMARY_ENCODER_VELOCITY        = _PRIMARY_ENCODER_VELOCITY.f;
        uint32_t _PRIMARY_ENCODER_POSITION_u = (uint32_t)::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        union
        {
            uint32_t u;
            float    f;
        } _PRIMARY_ENCODER_POSITION   = {.u = _PRIMARY_ENCODER_POSITION_u};
        out->PRIMARY_ENCODER_POSITION = _PRIMARY_ENCODER_POSITION.f;
        return true;
    }

    // Decode frame payload for Status 3: Includes data from an analog sensor
    bool spark_decode_STATUS_3(const uint8_t* data, uint8_t dlc, Spark_STATUS_3_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->ANALOG_VOLTAGE         = ::CanControl::LowLevel::unpack_field(data, 0u, 10u, false);
        uint64_t _ANALOG_VELOCITY_u = ::CanControl::LowLevel::unpack_field(data, 10u, 22u, false);
        if (22u < 64u && (_ANALOG_VELOCITY_u & (1ull << (22u - 1u))))
        {
            _ANALOG_VELOCITY_u |= ~((1ull << 22) - 1ull);
        }
        out->ANALOG_VELOCITY        = (int64_t)_ANALOG_VELOCITY_u;
        uint32_t _ANALOG_POSITION_u = (uint32_t)::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        union
        {
            uint32_t u;
            float    f;
        } _ANALOG_POSITION   = {.u = _ANALOG_POSITION_u};
        out->ANALOG_POSITION = _ANALOG_POSITION.f;
        return true;
    }

    // Decode frame payload for Status 4: Includes data from the External Encoder (on SPARK MAX, this is the Alternate
    // Encoder)
    bool spark_decode_STATUS_4(const uint8_t* data, uint8_t dlc, Spark_STATUS_4_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        uint32_t _EXTERNAL_OR_ALT_ENCODER_VELOCITY_u =
            (uint32_t)::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        union
        {
            uint32_t u;
            float    f;
        } _EXTERNAL_OR_ALT_ENCODER_VELOCITY   = {.u = _EXTERNAL_OR_ALT_ENCODER_VELOCITY_u};
        out->EXTERNAL_OR_ALT_ENCODER_VELOCITY = _EXTERNAL_OR_ALT_ENCODER_VELOCITY.f;
        uint32_t _EXTERNAL_OR_ALT_ENCODER_POSITION_u =
            (uint32_t)::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        union
        {
            uint32_t u;
            float    f;
        } _EXTERNAL_OR_ALT_ENCODER_POSITION   = {.u = _EXTERNAL_OR_ALT_ENCODER_POSITION_u};
        out->EXTERNAL_OR_ALT_ENCODER_POSITION = _EXTERNAL_OR_ALT_ENCODER_POSITION.f;
        return true;
    }

    // Decode frame payload for Status 5: Includes velocity and position data from a duty-cycle absolute encoder
    bool spark_decode_STATUS_5(const uint8_t* data, uint8_t dlc, Spark_STATUS_5_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        uint32_t _DUTY_CYCLE_ENCODER_VELOCITY_u = (uint32_t)::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        union
        {
            uint32_t u;
            float    f;
        } _DUTY_CYCLE_ENCODER_VELOCITY          = {.u = _DUTY_CYCLE_ENCODER_VELOCITY_u};
        out->DUTY_CYCLE_ENCODER_VELOCITY        = _DUTY_CYCLE_ENCODER_VELOCITY.f;
        uint32_t _DUTY_CYCLE_ENCODER_POSITION_u = (uint32_t)::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        union
        {
            uint32_t u;
            float    f;
        } _DUTY_CYCLE_ENCODER_POSITION   = {.u = _DUTY_CYCLE_ENCODER_POSITION_u};
        out->DUTY_CYCLE_ENCODER_POSITION = _DUTY_CYCLE_ENCODER_POSITION.f;
        return true;
    }

    // Decode frame payload for Status 6: Includes other data from a duty-cycle absolute encoder
    bool spark_decode_STATUS_6(const uint8_t* data, uint8_t dlc, Spark_STATUS_6_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->UNADJUSTED_DUTY_CYCLE = ::CanControl::LowLevel::unpack_field(data, 0u, 16u, false);
        out->DUTY_CYCLE_PERIOD     = ::CanControl::LowLevel::unpack_field(data, 16u, 16u, false);
        out->DUTY_CYCLE_NO_SIGNAL  = ::CanControl::LowLevel::unpack_field(data, 32u, 1u, false) ? true : false;
        return true;
    }

    // Decode frame payload for Status 7: Includes diagnostic data for closed-loop control
    bool spark_decode_STATUS_7(const uint8_t* data, uint8_t dlc, Spark_STATUS_7_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        uint32_t _I_ACCUMULATION_u = (uint32_t)::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        union
        {
            uint32_t u;
            float    f;
        } _I_ACCUMULATION   = {.u = _I_ACCUMULATION_u};
        out->I_ACCUMULATION = _I_ACCUMULATION.f;
        return true;
    }

    // Decode frame payload for Status 8: Includes additional diagnostic data for closed-loop control
    bool spark_decode_STATUS_8(const uint8_t* data, uint8_t dlc, Spark_STATUS_8_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        uint32_t _SETPOINT_u = (uint32_t)::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        union
        {
            uint32_t u;
            float    f;
        } _SETPOINT            = {.u = _SETPOINT_u};
        out->SETPOINT          = _SETPOINT.f;
        out->IS_AT_SETPOINT    = ::CanControl::LowLevel::unpack_field(data, 32u, 1u, false) ? true : false;
        out->SELECTED_PID_SLOT = ::CanControl::LowLevel::unpack_field(data, 33u, 4u, false);
        return true;
    }

    // Decode frame payload for Status 9: Includes diagnostic data for MAXMotion closed-loop control
    bool spark_decode_STATUS_9(const uint8_t* data, uint8_t dlc, Spark_STATUS_9_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        uint32_t _MAXMOTION_POSITION_SETPOINT_u = (uint32_t)::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        union
        {
            uint32_t u;
            float    f;
        } _MAXMOTION_POSITION_SETPOINT          = {.u = _MAXMOTION_POSITION_SETPOINT_u};
        out->MAXMOTION_POSITION_SETPOINT        = _MAXMOTION_POSITION_SETPOINT.f;
        uint32_t _MAXMOTION_VELOCITY_SETPOINT_u = (uint32_t)::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        union
        {
            uint32_t u;
            float    f;
        } _MAXMOTION_VELOCITY_SETPOINT   = {.u = _MAXMOTION_VELOCITY_SETPOINT_u};
        out->MAXMOTION_VELOCITY_SETPOINT = _MAXMOTION_VELOCITY_SETPOINT.f;
        return true;
    }

    // Decode frame payload for Unique ID Broadcast: Contains the unique ID of the device, to allow detecting duplicate
    // CAN IDs. To avoid collisions, the SPARK Flex firmware will send this at an irregular period between 1000ms and
    // 2000ms. SPARK MAX may use a constant period of 1000ms.
    bool spark_decode_UNIQUE_ID_BROADCAST(const uint8_t* data, uint8_t dlc, Spark_UNIQUE_ID_BROADCAST_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 4u)
            return false;
        out->UNIQUE_ID = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        return true;
    }

    // Decode frame payload for Velocity Setpoint: Sets the Control Type to Velocity and sets the target velocity
    bool spark_decode_VELOCITY_SETPOINT(const uint8_t* data, uint8_t dlc, Spark_VELOCITY_SETPOINT_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        uint32_t _SETPOINT_u = (uint32_t)::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        union
        {
            uint32_t u;
            float    f;
        } _SETPOINT                       = {.u = _SETPOINT_u};
        out->SETPOINT                     = _SETPOINT.f;
        uint64_t _ARBITRARY_FEEDFORWARD_u = ::CanControl::LowLevel::unpack_field(data, 32u, 16u, false);
        if (16u < 64u && (_ARBITRARY_FEEDFORWARD_u & (1ull << (16u - 1u))))
        {
            _ARBITRARY_FEEDFORWARD_u |= ~((1ull << 16) - 1ull);
        }
        out->ARBITRARY_FEEDFORWARD       = (int64_t)_ARBITRARY_FEEDFORWARD_u;
        out->PID_SLOT                    = ::CanControl::LowLevel::unpack_field(data, 48u, 2u, false);
        out->ARBITRARY_FEEDFORWARD_UNITS = ::CanControl::LowLevel::unpack_field(data, 50u, 1u, false);
        return true;
    }

    // Decode frame payload for Duty Cycle Setpoint: Sets the Control Type to Duty Cycle and sets the target duty cycle
    // (from -1 to 1)
    bool spark_decode_DUTY_CYCLE_SETPOINT(const uint8_t* data, uint8_t dlc, Spark_DUTY_CYCLE_SETPOINT_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        uint32_t _SETPOINT_u = (uint32_t)::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        union
        {
            uint32_t u;
            float    f;
        } _SETPOINT                       = {.u = _SETPOINT_u};
        out->SETPOINT                     = _SETPOINT.f;
        uint64_t _ARBITRARY_FEEDFORWARD_u = ::CanControl::LowLevel::unpack_field(data, 32u, 16u, false);
        if (16u < 64u && (_ARBITRARY_FEEDFORWARD_u & (1ull << (16u - 1u))))
        {
            _ARBITRARY_FEEDFORWARD_u |= ~((1ull << 16) - 1ull);
        }
        out->ARBITRARY_FEEDFORWARD       = (int64_t)_ARBITRARY_FEEDFORWARD_u;
        out->PID_SLOT                    = ::CanControl::LowLevel::unpack_field(data, 48u, 2u, false);
        out->ARBITRARY_FEEDFORWARD_UNITS = ::CanControl::LowLevel::unpack_field(data, 50u, 1u, false);
        return true;
    }

    // Decode frame payload for Position Setpoint: Sets the Control Type to Position and sets the target position
    bool spark_decode_POSITION_SETPOINT(const uint8_t* data, uint8_t dlc, Spark_POSITION_SETPOINT_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        uint32_t _SETPOINT_u = (uint32_t)::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        union
        {
            uint32_t u;
            float    f;
        } _SETPOINT                       = {.u = _SETPOINT_u};
        out->SETPOINT                     = _SETPOINT.f;
        uint64_t _ARBITRARY_FEEDFORWARD_u = ::CanControl::LowLevel::unpack_field(data, 32u, 16u, false);
        if (16u < 64u && (_ARBITRARY_FEEDFORWARD_u & (1ull << (16u - 1u))))
        {
            _ARBITRARY_FEEDFORWARD_u |= ~((1ull << 16) - 1ull);
        }
        out->ARBITRARY_FEEDFORWARD       = (int64_t)_ARBITRARY_FEEDFORWARD_u;
        out->PID_SLOT                    = ::CanControl::LowLevel::unpack_field(data, 48u, 2u, false);
        out->ARBITRARY_FEEDFORWARD_UNITS = ::CanControl::LowLevel::unpack_field(data, 50u, 1u, false);
        return true;
    }

    // Decode frame payload for Voltage Setpoint: Sets the Control Type to Voltage and sets the target voltage
    bool spark_decode_VOLTAGE_SETPOINT(const uint8_t* data, uint8_t dlc, Spark_VOLTAGE_SETPOINT_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        uint32_t _SETPOINT_u = (uint32_t)::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        union
        {
            uint32_t u;
            float    f;
        } _SETPOINT                       = {.u = _SETPOINT_u};
        out->SETPOINT                     = _SETPOINT.f;
        uint64_t _ARBITRARY_FEEDFORWARD_u = ::CanControl::LowLevel::unpack_field(data, 32u, 16u, false);
        if (16u < 64u && (_ARBITRARY_FEEDFORWARD_u & (1ull << (16u - 1u))))
        {
            _ARBITRARY_FEEDFORWARD_u |= ~((1ull << 16) - 1ull);
        }
        out->ARBITRARY_FEEDFORWARD       = (int64_t)_ARBITRARY_FEEDFORWARD_u;
        out->PID_SLOT                    = ::CanControl::LowLevel::unpack_field(data, 48u, 2u, false);
        out->ARBITRARY_FEEDFORWARD_UNITS = ::CanControl::LowLevel::unpack_field(data, 50u, 1u, false);
        return true;
    }

    // Decode frame payload for Current Setpoint: Sets the Control Type to Current and sets the target current
    bool spark_decode_CURRENT_SETPOINT(const uint8_t* data, uint8_t dlc, Spark_CURRENT_SETPOINT_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        uint32_t _SETPOINT_u = (uint32_t)::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        union
        {
            uint32_t u;
            float    f;
        } _SETPOINT                       = {.u = _SETPOINT_u};
        out->SETPOINT                     = _SETPOINT.f;
        uint64_t _ARBITRARY_FEEDFORWARD_u = ::CanControl::LowLevel::unpack_field(data, 32u, 16u, false);
        if (16u < 64u && (_ARBITRARY_FEEDFORWARD_u & (1ull << (16u - 1u))))
        {
            _ARBITRARY_FEEDFORWARD_u |= ~((1ull << 16) - 1ull);
        }
        out->ARBITRARY_FEEDFORWARD       = (int64_t)_ARBITRARY_FEEDFORWARD_u;
        out->PID_SLOT                    = ::CanControl::LowLevel::unpack_field(data, 48u, 2u, false);
        out->ARBITRARY_FEEDFORWARD_UNITS = ::CanControl::LowLevel::unpack_field(data, 50u, 1u, false);
        return true;
    }

    // Decode frame payload for MAXMotion Position Setpoint: Sets the Control Type to MAXMotion Position Control and
    // sets the target position
    bool spark_decode_MAXMOTION_POSITION_SETPOINT(const uint8_t* data, uint8_t dlc,
                                                  Spark_MAXMOTION_POSITION_SETPOINT_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        uint32_t _SETPOINT_u = (uint32_t)::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        union
        {
            uint32_t u;
            float    f;
        } _SETPOINT                       = {.u = _SETPOINT_u};
        out->SETPOINT                     = _SETPOINT.f;
        uint64_t _ARBITRARY_FEEDFORWARD_u = ::CanControl::LowLevel::unpack_field(data, 32u, 16u, false);
        if (16u < 64u && (_ARBITRARY_FEEDFORWARD_u & (1ull << (16u - 1u))))
        {
            _ARBITRARY_FEEDFORWARD_u |= ~((1ull << 16) - 1ull);
        }
        out->ARBITRARY_FEEDFORWARD       = (int64_t)_ARBITRARY_FEEDFORWARD_u;
        out->PID_SLOT                    = ::CanControl::LowLevel::unpack_field(data, 48u, 2u, false);
        out->ARBITRARY_FEEDFORWARD_UNITS = ::CanControl::LowLevel::unpack_field(data, 50u, 1u, false);
        return true;
    }

    // Decode frame payload for MAXMotion Velocity Setpoint: Sets the Control Type to MAXMotion Velocity Control and
    // sets the target velocity
    bool spark_decode_MAXMOTION_VELOCITY_SETPOINT(const uint8_t* data, uint8_t dlc,
                                                  Spark_MAXMOTION_VELOCITY_SETPOINT_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        uint32_t _SETPOINT_u = (uint32_t)::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        union
        {
            uint32_t u;
            float    f;
        } _SETPOINT                       = {.u = _SETPOINT_u};
        out->SETPOINT                     = _SETPOINT.f;
        uint64_t _ARBITRARY_FEEDFORWARD_u = ::CanControl::LowLevel::unpack_field(data, 32u, 16u, false);
        if (16u < 64u && (_ARBITRARY_FEEDFORWARD_u & (1ull << (16u - 1u))))
        {
            _ARBITRARY_FEEDFORWARD_u |= ~((1ull << 16) - 1ull);
        }
        out->ARBITRARY_FEEDFORWARD       = (int64_t)_ARBITRARY_FEEDFORWARD_u;
        out->PID_SLOT                    = ::CanControl::LowLevel::unpack_field(data, 48u, 2u, false);
        out->ARBITRARY_FEEDFORWARD_UNITS = ::CanControl::LowLevel::unpack_field(data, 50u, 1u, false);
        return true;
    }

    // Decode frame payload for Set Statuses Enabled: Enable or disable status frames. In response, a Set Statuses
    // Enabled Response frame will be sent.
    bool spark_decode_SET_STATUSES_ENABLED(const uint8_t* data, uint8_t dlc, Spark_SET_STATUSES_ENABLED_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 4u)
            return false;
        out->MASK             = ::CanControl::LowLevel::unpack_field(data, 0u, 16u, false);
        out->ENABLED_BITFIELD = ::CanControl::LowLevel::unpack_field(data, 16u, 16u, false);
        return true;
    }

    // Decode frame payload for Set Statuses Enabled Response: Response for a Set Statuses Enabled command
    bool spark_decode_SET_STATUSES_ENABLED_RESPONSE(const uint8_t* data, uint8_t dlc,
                                                    Spark_SET_STATUSES_ENABLED_RESPONSE_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 5u)
            return false;
        out->RESULT_CODE      = ::CanControl::LowLevel::unpack_field(data, 0u, 8u, false);
        out->SPECIFIED_MASK   = ::CanControl::LowLevel::unpack_field(data, 8u, 16u, false);
        out->ENABLED_BITFIELD = ::CanControl::LowLevel::unpack_field(data, 24u, 16u, false);
        return true;
    }

    // Decode frame payload for Persist Parameters Response
    bool spark_decode_PERSIST_PARAMETERS_RESPONSE(const uint8_t* data, uint8_t dlc,
                                                  Spark_PERSIST_PARAMETERS_RESPONSE_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 1u)
            return false;
        out->RESULT_CODE = ::CanControl::LowLevel::unpack_field(data, 0u, 8u, false);
        return true;
    }

    // Decode frame payload for Reset Safe Parameters: Resets most writable parameters to their default values, except
    // CAN ID, Motor Type, Idle Mode, PWM Input Deadband, and Duty Cycle Offset. In response, a Reset Safe Parameters
    // Response frame is sent.
    bool spark_decode_RESET_SAFE_PARAMETERS(const uint8_t* data, uint8_t dlc, Spark_RESET_SAFE_PARAMETERS_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 2u)
            return false;
        out->MAGIC_NUMBER = ::CanControl::LowLevel::unpack_field(data, 0u, 16u, false);
        return true;
    }

    // Decode frame payload for Reset Safe Parameters Response: Response for a Reset Safe Parameters command
    bool spark_decode_RESET_SAFE_PARAMETERS_RESPONSE(const uint8_t* data, uint8_t dlc,
                                                     Spark_RESET_SAFE_PARAMETERS_RESPONSE_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 1u)
            return false;
        out->RESULT_CODE = ::CanControl::LowLevel::unpack_field(data, 0u, 8u, false);
        return true;
    }

    // Decode frame payload for Complete Factory Reset: Resets all writable parameters to default values, even CAN ID,
    // Motor Type, Idle Mode, PWM Input Deadband, and Duty Cycle Offset. In response, a Complete Factory Reset Response
    // frame is sent.
    bool spark_decode_COMPLETE_FACTORY_RESET(const uint8_t* data, uint8_t dlc, Spark_COMPLETE_FACTORY_RESET_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 2u)
            return false;
        out->MAGIC_NUMBER = ::CanControl::LowLevel::unpack_field(data, 0u, 16u, false);
        return true;
    }

    // Decode frame payload for Complete Factory Reset Response: Response for a Complete Factory Reset command
    bool spark_decode_COMPLETE_FACTORY_RESET_RESPONSE(const uint8_t* data, uint8_t dlc,
                                                      Spark_COMPLETE_FACTORY_RESET_RESPONSE_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 1u)
            return false;
        out->RESULT_CODE = ::CanControl::LowLevel::unpack_field(data, 0u, 8u, false);
        return true;
    }

    // Decode frame payload for Identify Unique SPARK: Makes the specified, single SPARK (even if there are multiple
    // SPARKs that have the same CAN ID) temporarily perform a special blink pattern that will make it stand out
    bool spark_decode_IDENTIFY_UNIQUE_SPARK(const uint8_t* data, uint8_t dlc, Spark_IDENTIFY_UNIQUE_SPARK_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 4u)
            return false;
        out->UNIQUE_ID = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        return true;
    }

    // Decode frame payload for Set CAN ID: Allows changing the CAN ID when multiple devices on the bus currently have
    // the same CAN ID. Under normal circumstances, the CAN ID parameter can be used.
    bool spark_decode_SET_CAN_ID(const uint8_t* data, uint8_t dlc, Spark_SET_CAN_ID_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 5u)
            return false;
        out->UNIQUE_ID = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->CAN_ID    = ::CanControl::LowLevel::unpack_field(data, 32u, 8u, false);
        return true;
    }

    // Decode frame payload for Get Firmware Version
    bool spark_decode_GET_FIRMWARE_VERSION(const uint8_t* data, uint8_t dlc, Spark_GET_FIRMWARE_VERSION_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->MAJOR       = ::CanControl::LowLevel::unpack_field(data, 0u, 8u, false);
        out->MINOR       = ::CanControl::LowLevel::unpack_field(data, 8u, 8u, false);
        out->BUILD       = ::CanControl::LowLevel::unpack_field(data, 16u, 16u, true);
        out->DEBUG_BUILD = ::CanControl::LowLevel::unpack_field(data, 32u, 8u, false);
        out->HW_REV      = ::CanControl::LowLevel::unpack_field(data, 40u, 8u, false);
        return true;
    }

    // Decode frame payload for SWDL Data: Broadcast from the host to all SPARKs in SWDL mode, containing a slice of
    // firmware data
    bool spark_decode_SWDL_DATA(const uint8_t* data, uint8_t dlc, Spark_SWDL_DATA_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->DATA = ::CanControl::LowLevel::unpack_field(data, 0u, 64u, false);
        return true;
    }

    // Decode frame payload for SWDL Checksum: Broadcast from the host to all SPARKs in SWDL mode, containing the
    // checksum of the full firmware image that was just sent
    bool spark_decode_SWDL_CHECKSUM(const uint8_t* data, uint8_t dlc, Spark_SWDL_CHECKSUM_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->CHECKSUM = ::CanControl::LowLevel::unpack_field(data, 0u, 64u, false);
        return true;
    }

    // Decode frame payload for Set Primary Encoder Position
    bool spark_decode_SET_PRIMARY_ENCODER_POSITION(const uint8_t* data, uint8_t dlc,
                                                   Spark_SET_PRIMARY_ENCODER_POSITION_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 5u)
            return false;
        uint32_t _POSITION_u = (uint32_t)::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        union
        {
            uint32_t u;
            float    f;
        } _POSITION    = {.u = _POSITION_u};
        out->POSITION  = _POSITION.f;
        out->DATA_TYPE = ::CanControl::LowLevel::unpack_field(data, 32u, 8u, false);
        return true;
    }

    // Decode frame payload for Set I Accumulation
    bool spark_decode_SET_I_ACCUMULATION(const uint8_t* data, uint8_t dlc, Spark_SET_I_ACCUMULATION_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 5u)
            return false;
        uint32_t _I_ACCUMULATION_u = (uint32_t)::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        union
        {
            uint32_t u;
            float    f;
        } _I_ACCUMULATION   = {.u = _I_ACCUMULATION_u};
        out->I_ACCUMULATION = _I_ACCUMULATION.f;
        out->DATA_TYPE      = ::CanControl::LowLevel::unpack_field(data, 32u, 8u, false);
        return true;
    }

    // Decode frame payload for Set Analog Position
    bool spark_decode_SET_ANALOG_POSITION(const uint8_t* data, uint8_t dlc, Spark_SET_ANALOG_POSITION_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 5u)
            return false;
        uint32_t _POSITION_u = (uint32_t)::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        union
        {
            uint32_t u;
            float    f;
        } _POSITION    = {.u = _POSITION_u};
        out->POSITION  = _POSITION.f;
        out->DATA_TYPE = ::CanControl::LowLevel::unpack_field(data, 32u, 8u, false);
        return true;
    }

    // Decode frame payload for Set Ext or Alt Encoder Position
    bool spark_decode_SET_EXT_OR_ALT_ENCODER_POSITION(const uint8_t* data, uint8_t dlc,
                                                      Spark_SET_EXT_OR_ALT_ENCODER_POSITION_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 5u)
            return false;
        uint32_t _POSITION_u = (uint32_t)::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        union
        {
            uint32_t u;
            float    f;
        } _POSITION    = {.u = _POSITION_u};
        out->POSITION  = _POSITION.f;
        out->DATA_TYPE = ::CanControl::LowLevel::unpack_field(data, 32u, 8u, false);
        return true;
    }

    // Decode frame payload for Set Duty Cycle Position
    bool spark_decode_SET_DUTY_CYCLE_POSITION(const uint8_t* data, uint8_t dlc, Spark_SET_DUTY_CYCLE_POSITION_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 5u)
            return false;
        uint32_t _POSITION_u = (uint32_t)::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        union
        {
            uint32_t u;
            float    f;
        } _POSITION    = {.u = _POSITION_u};
        out->POSITION  = _POSITION.f;
        out->DATA_TYPE = ::CanControl::LowLevel::unpack_field(data, 32u, 8u, false);
        return true;
    }

    // Decode frame payload for Secondary Heartbeat: Heartbeat that allows enabling only specific SPARKs, but only gets
    // respected when the SPARK is not locked to the Universal Heartbeat or Primary Heartbeat
    bool spark_decode_SECONDARY_HEARTBEAT(const uint8_t* data, uint8_t dlc, Spark_SECONDARY_HEARTBEAT_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->ENABLED_SPARKS_BITFIELD = ::CanControl::LowLevel::unpack_field(data, 0u, 64u, false);
        return true;
    }

    // Decode frame payload for USB Only Enter DFU Bootloader: Causes the device to reboot into the DFU bootloader if
    // this command is received directly via USB
    bool spark_decode_USB_ONLY_ENTER_DFU_BOOTLOADER(const uint8_t* data, uint8_t dlc,
                                                    Spark_USB_ONLY_ENTER_DFU_BOOTLOADER_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 2u)
            return false;
        out->MAGIC_NUMBER = ::CanControl::LowLevel::unpack_field(data, 0u, 16u, false);
        return true;
    }

    // Decode frame payload for Get Temperatures
    bool spark_decode_GET_TEMPERATURES(const uint8_t* data, uint8_t dlc, Spark_GET_TEMPERATURES_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->MOTOR_TEMPERATURE           = ::CanControl::LowLevel::unpack_field(data, 0u, 8u, false);
        out->MICROCONTROLLER_TEMPERATURE = ::CanControl::LowLevel::unpack_field(data, 8u, 8u, false);
        out->FET_TEMPERATURE             = ::CanControl::LowLevel::unpack_field(data, 16u, 8u, false);
        out->MOTOR_TEMPERATURE_2         = ::CanControl::LowLevel::unpack_field(data, 24u, 8u, false);
        out->DOCK_TEMPERATURE            = ::CanControl::LowLevel::unpack_field(data, 32u, 8u, false);
        out->VALID_TEMPERATURES_BITMASK  = ::CanControl::LowLevel::unpack_field(data, 56u, 7u, false);
        out->UNUSED                      = ::CanControl::LowLevel::unpack_field(data, 63u, 1u, false);
        return true;
    }

    // Decode frame payload for Get Motor Interface
    bool spark_decode_GET_MOTOR_INTERFACE(const uint8_t* data, uint8_t dlc, Spark_GET_MOTOR_INTERFACE_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 3u)
            return false;
        out->MOTOR_INTERFACE     = ::CanControl::LowLevel::unpack_field(data, 0u, 16u, false);
        out->PRIMARY_SENSOR_TYPE = ::CanControl::LowLevel::unpack_field(data, 16u, 8u, false);
        return true;
    }

    // Decode frame payload for Get Parameter 0 to 15 Types: Get types of parameters 0 to 15
    bool spark_decode_GET_PARAMETER_0_TO_15_TYPES(const uint8_t* data, uint8_t dlc,
                                                  Spark_GET_PARAMETER_0_TO_15_TYPES_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->TYPE_0  = ::CanControl::LowLevel::unpack_field(data, 0u, 4u, false);
        out->TYPE_1  = ::CanControl::LowLevel::unpack_field(data, 4u, 4u, false);
        out->TYPE_2  = ::CanControl::LowLevel::unpack_field(data, 8u, 4u, false);
        out->TYPE_3  = ::CanControl::LowLevel::unpack_field(data, 12u, 4u, false);
        out->TYPE_4  = ::CanControl::LowLevel::unpack_field(data, 16u, 4u, false);
        out->TYPE_5  = ::CanControl::LowLevel::unpack_field(data, 20u, 4u, false);
        out->TYPE_6  = ::CanControl::LowLevel::unpack_field(data, 24u, 4u, false);
        out->TYPE_7  = ::CanControl::LowLevel::unpack_field(data, 28u, 4u, false);
        out->TYPE_8  = ::CanControl::LowLevel::unpack_field(data, 32u, 4u, false);
        out->TYPE_9  = ::CanControl::LowLevel::unpack_field(data, 36u, 4u, false);
        out->TYPE_10 = ::CanControl::LowLevel::unpack_field(data, 40u, 4u, false);
        out->TYPE_11 = ::CanControl::LowLevel::unpack_field(data, 44u, 4u, false);
        out->TYPE_12 = ::CanControl::LowLevel::unpack_field(data, 48u, 4u, false);
        out->TYPE_13 = ::CanControl::LowLevel::unpack_field(data, 52u, 4u, false);
        out->TYPE_14 = ::CanControl::LowLevel::unpack_field(data, 56u, 4u, false);
        out->TYPE_15 = ::CanControl::LowLevel::unpack_field(data, 60u, 4u, false);
        return true;
    }

    // Decode frame payload for Get Parameter 16 to 31 Types: Get types of parameters 16 to 31
    bool spark_decode_GET_PARAMETER_16_TO_31_TYPES(const uint8_t* data, uint8_t dlc,
                                                   Spark_GET_PARAMETER_16_TO_31_TYPES_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->TYPE_0  = ::CanControl::LowLevel::unpack_field(data, 0u, 4u, false);
        out->TYPE_1  = ::CanControl::LowLevel::unpack_field(data, 4u, 4u, false);
        out->TYPE_2  = ::CanControl::LowLevel::unpack_field(data, 8u, 4u, false);
        out->TYPE_3  = ::CanControl::LowLevel::unpack_field(data, 12u, 4u, false);
        out->TYPE_4  = ::CanControl::LowLevel::unpack_field(data, 16u, 4u, false);
        out->TYPE_5  = ::CanControl::LowLevel::unpack_field(data, 20u, 4u, false);
        out->TYPE_6  = ::CanControl::LowLevel::unpack_field(data, 24u, 4u, false);
        out->TYPE_7  = ::CanControl::LowLevel::unpack_field(data, 28u, 4u, false);
        out->TYPE_8  = ::CanControl::LowLevel::unpack_field(data, 32u, 4u, false);
        out->TYPE_9  = ::CanControl::LowLevel::unpack_field(data, 36u, 4u, false);
        out->TYPE_10 = ::CanControl::LowLevel::unpack_field(data, 40u, 4u, false);
        out->TYPE_11 = ::CanControl::LowLevel::unpack_field(data, 44u, 4u, false);
        out->TYPE_12 = ::CanControl::LowLevel::unpack_field(data, 48u, 4u, false);
        out->TYPE_13 = ::CanControl::LowLevel::unpack_field(data, 52u, 4u, false);
        out->TYPE_14 = ::CanControl::LowLevel::unpack_field(data, 56u, 4u, false);
        out->TYPE_15 = ::CanControl::LowLevel::unpack_field(data, 60u, 4u, false);
        return true;
    }

    // Decode frame payload for Get Parameter 32 to 47 Types: Get types of parameters 32 to 47
    bool spark_decode_GET_PARAMETER_32_TO_47_TYPES(const uint8_t* data, uint8_t dlc,
                                                   Spark_GET_PARAMETER_32_TO_47_TYPES_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->TYPE_0  = ::CanControl::LowLevel::unpack_field(data, 0u, 4u, false);
        out->TYPE_1  = ::CanControl::LowLevel::unpack_field(data, 4u, 4u, false);
        out->TYPE_2  = ::CanControl::LowLevel::unpack_field(data, 8u, 4u, false);
        out->TYPE_3  = ::CanControl::LowLevel::unpack_field(data, 12u, 4u, false);
        out->TYPE_4  = ::CanControl::LowLevel::unpack_field(data, 16u, 4u, false);
        out->TYPE_5  = ::CanControl::LowLevel::unpack_field(data, 20u, 4u, false);
        out->TYPE_6  = ::CanControl::LowLevel::unpack_field(data, 24u, 4u, false);
        out->TYPE_7  = ::CanControl::LowLevel::unpack_field(data, 28u, 4u, false);
        out->TYPE_8  = ::CanControl::LowLevel::unpack_field(data, 32u, 4u, false);
        out->TYPE_9  = ::CanControl::LowLevel::unpack_field(data, 36u, 4u, false);
        out->TYPE_10 = ::CanControl::LowLevel::unpack_field(data, 40u, 4u, false);
        out->TYPE_11 = ::CanControl::LowLevel::unpack_field(data, 44u, 4u, false);
        out->TYPE_12 = ::CanControl::LowLevel::unpack_field(data, 48u, 4u, false);
        out->TYPE_13 = ::CanControl::LowLevel::unpack_field(data, 52u, 4u, false);
        out->TYPE_14 = ::CanControl::LowLevel::unpack_field(data, 56u, 4u, false);
        out->TYPE_15 = ::CanControl::LowLevel::unpack_field(data, 60u, 4u, false);
        return true;
    }

    // Decode frame payload for Get Parameter 48 to 63 Types: Get types of parameters 48 to 63
    bool spark_decode_GET_PARAMETER_48_TO_63_TYPES(const uint8_t* data, uint8_t dlc,
                                                   Spark_GET_PARAMETER_48_TO_63_TYPES_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->TYPE_0  = ::CanControl::LowLevel::unpack_field(data, 0u, 4u, false);
        out->TYPE_1  = ::CanControl::LowLevel::unpack_field(data, 4u, 4u, false);
        out->TYPE_2  = ::CanControl::LowLevel::unpack_field(data, 8u, 4u, false);
        out->TYPE_3  = ::CanControl::LowLevel::unpack_field(data, 12u, 4u, false);
        out->TYPE_4  = ::CanControl::LowLevel::unpack_field(data, 16u, 4u, false);
        out->TYPE_5  = ::CanControl::LowLevel::unpack_field(data, 20u, 4u, false);
        out->TYPE_6  = ::CanControl::LowLevel::unpack_field(data, 24u, 4u, false);
        out->TYPE_7  = ::CanControl::LowLevel::unpack_field(data, 28u, 4u, false);
        out->TYPE_8  = ::CanControl::LowLevel::unpack_field(data, 32u, 4u, false);
        out->TYPE_9  = ::CanControl::LowLevel::unpack_field(data, 36u, 4u, false);
        out->TYPE_10 = ::CanControl::LowLevel::unpack_field(data, 40u, 4u, false);
        out->TYPE_11 = ::CanControl::LowLevel::unpack_field(data, 44u, 4u, false);
        out->TYPE_12 = ::CanControl::LowLevel::unpack_field(data, 48u, 4u, false);
        out->TYPE_13 = ::CanControl::LowLevel::unpack_field(data, 52u, 4u, false);
        out->TYPE_14 = ::CanControl::LowLevel::unpack_field(data, 56u, 4u, false);
        out->TYPE_15 = ::CanControl::LowLevel::unpack_field(data, 60u, 4u, false);
        return true;
    }

    // Decode frame payload for Get Parameter 64 to 79 Types: Get types of parameters 64 to 79
    bool spark_decode_GET_PARAMETER_64_TO_79_TYPES(const uint8_t* data, uint8_t dlc,
                                                   Spark_GET_PARAMETER_64_TO_79_TYPES_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->TYPE_0  = ::CanControl::LowLevel::unpack_field(data, 0u, 4u, false);
        out->TYPE_1  = ::CanControl::LowLevel::unpack_field(data, 4u, 4u, false);
        out->TYPE_2  = ::CanControl::LowLevel::unpack_field(data, 8u, 4u, false);
        out->TYPE_3  = ::CanControl::LowLevel::unpack_field(data, 12u, 4u, false);
        out->TYPE_4  = ::CanControl::LowLevel::unpack_field(data, 16u, 4u, false);
        out->TYPE_5  = ::CanControl::LowLevel::unpack_field(data, 20u, 4u, false);
        out->TYPE_6  = ::CanControl::LowLevel::unpack_field(data, 24u, 4u, false);
        out->TYPE_7  = ::CanControl::LowLevel::unpack_field(data, 28u, 4u, false);
        out->TYPE_8  = ::CanControl::LowLevel::unpack_field(data, 32u, 4u, false);
        out->TYPE_9  = ::CanControl::LowLevel::unpack_field(data, 36u, 4u, false);
        out->TYPE_10 = ::CanControl::LowLevel::unpack_field(data, 40u, 4u, false);
        out->TYPE_11 = ::CanControl::LowLevel::unpack_field(data, 44u, 4u, false);
        out->TYPE_12 = ::CanControl::LowLevel::unpack_field(data, 48u, 4u, false);
        out->TYPE_13 = ::CanControl::LowLevel::unpack_field(data, 52u, 4u, false);
        out->TYPE_14 = ::CanControl::LowLevel::unpack_field(data, 56u, 4u, false);
        out->TYPE_15 = ::CanControl::LowLevel::unpack_field(data, 60u, 4u, false);
        return true;
    }

    // Decode frame payload for Get Parameter 80 to 95 Types: Get types of parameters 80 to 95
    bool spark_decode_GET_PARAMETER_80_TO_95_TYPES(const uint8_t* data, uint8_t dlc,
                                                   Spark_GET_PARAMETER_80_TO_95_TYPES_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->TYPE_0  = ::CanControl::LowLevel::unpack_field(data, 0u, 4u, false);
        out->TYPE_1  = ::CanControl::LowLevel::unpack_field(data, 4u, 4u, false);
        out->TYPE_2  = ::CanControl::LowLevel::unpack_field(data, 8u, 4u, false);
        out->TYPE_3  = ::CanControl::LowLevel::unpack_field(data, 12u, 4u, false);
        out->TYPE_4  = ::CanControl::LowLevel::unpack_field(data, 16u, 4u, false);
        out->TYPE_5  = ::CanControl::LowLevel::unpack_field(data, 20u, 4u, false);
        out->TYPE_6  = ::CanControl::LowLevel::unpack_field(data, 24u, 4u, false);
        out->TYPE_7  = ::CanControl::LowLevel::unpack_field(data, 28u, 4u, false);
        out->TYPE_8  = ::CanControl::LowLevel::unpack_field(data, 32u, 4u, false);
        out->TYPE_9  = ::CanControl::LowLevel::unpack_field(data, 36u, 4u, false);
        out->TYPE_10 = ::CanControl::LowLevel::unpack_field(data, 40u, 4u, false);
        out->TYPE_11 = ::CanControl::LowLevel::unpack_field(data, 44u, 4u, false);
        out->TYPE_12 = ::CanControl::LowLevel::unpack_field(data, 48u, 4u, false);
        out->TYPE_13 = ::CanControl::LowLevel::unpack_field(data, 52u, 4u, false);
        out->TYPE_14 = ::CanControl::LowLevel::unpack_field(data, 56u, 4u, false);
        out->TYPE_15 = ::CanControl::LowLevel::unpack_field(data, 60u, 4u, false);
        return true;
    }

    // Decode frame payload for Get Parameter 96 to 111 Types: Get types of parameters 96 to 111
    bool spark_decode_GET_PARAMETER_96_TO_111_TYPES(const uint8_t* data, uint8_t dlc,
                                                    Spark_GET_PARAMETER_96_TO_111_TYPES_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->TYPE_0  = ::CanControl::LowLevel::unpack_field(data, 0u, 4u, false);
        out->TYPE_1  = ::CanControl::LowLevel::unpack_field(data, 4u, 4u, false);
        out->TYPE_2  = ::CanControl::LowLevel::unpack_field(data, 8u, 4u, false);
        out->TYPE_3  = ::CanControl::LowLevel::unpack_field(data, 12u, 4u, false);
        out->TYPE_4  = ::CanControl::LowLevel::unpack_field(data, 16u, 4u, false);
        out->TYPE_5  = ::CanControl::LowLevel::unpack_field(data, 20u, 4u, false);
        out->TYPE_6  = ::CanControl::LowLevel::unpack_field(data, 24u, 4u, false);
        out->TYPE_7  = ::CanControl::LowLevel::unpack_field(data, 28u, 4u, false);
        out->TYPE_8  = ::CanControl::LowLevel::unpack_field(data, 32u, 4u, false);
        out->TYPE_9  = ::CanControl::LowLevel::unpack_field(data, 36u, 4u, false);
        out->TYPE_10 = ::CanControl::LowLevel::unpack_field(data, 40u, 4u, false);
        out->TYPE_11 = ::CanControl::LowLevel::unpack_field(data, 44u, 4u, false);
        out->TYPE_12 = ::CanControl::LowLevel::unpack_field(data, 48u, 4u, false);
        out->TYPE_13 = ::CanControl::LowLevel::unpack_field(data, 52u, 4u, false);
        out->TYPE_14 = ::CanControl::LowLevel::unpack_field(data, 56u, 4u, false);
        out->TYPE_15 = ::CanControl::LowLevel::unpack_field(data, 60u, 4u, false);
        return true;
    }

    // Decode frame payload for Get Parameter 112 to 127 Types: Get types of parameters 112 to 127
    bool spark_decode_GET_PARAMETER_112_TO_127_TYPES(const uint8_t* data, uint8_t dlc,
                                                     Spark_GET_PARAMETER_112_TO_127_TYPES_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->TYPE_0  = ::CanControl::LowLevel::unpack_field(data, 0u, 4u, false);
        out->TYPE_1  = ::CanControl::LowLevel::unpack_field(data, 4u, 4u, false);
        out->TYPE_2  = ::CanControl::LowLevel::unpack_field(data, 8u, 4u, false);
        out->TYPE_3  = ::CanControl::LowLevel::unpack_field(data, 12u, 4u, false);
        out->TYPE_4  = ::CanControl::LowLevel::unpack_field(data, 16u, 4u, false);
        out->TYPE_5  = ::CanControl::LowLevel::unpack_field(data, 20u, 4u, false);
        out->TYPE_6  = ::CanControl::LowLevel::unpack_field(data, 24u, 4u, false);
        out->TYPE_7  = ::CanControl::LowLevel::unpack_field(data, 28u, 4u, false);
        out->TYPE_8  = ::CanControl::LowLevel::unpack_field(data, 32u, 4u, false);
        out->TYPE_9  = ::CanControl::LowLevel::unpack_field(data, 36u, 4u, false);
        out->TYPE_10 = ::CanControl::LowLevel::unpack_field(data, 40u, 4u, false);
        out->TYPE_11 = ::CanControl::LowLevel::unpack_field(data, 44u, 4u, false);
        out->TYPE_12 = ::CanControl::LowLevel::unpack_field(data, 48u, 4u, false);
        out->TYPE_13 = ::CanControl::LowLevel::unpack_field(data, 52u, 4u, false);
        out->TYPE_14 = ::CanControl::LowLevel::unpack_field(data, 56u, 4u, false);
        out->TYPE_15 = ::CanControl::LowLevel::unpack_field(data, 60u, 4u, false);
        return true;
    }

    // Decode frame payload for Get Parameter 128 to 143 Types: Get types of parameters 128 to 143
    bool spark_decode_GET_PARAMETER_128_TO_143_TYPES(const uint8_t* data, uint8_t dlc,
                                                     Spark_GET_PARAMETER_128_TO_143_TYPES_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->TYPE_0  = ::CanControl::LowLevel::unpack_field(data, 0u, 4u, false);
        out->TYPE_1  = ::CanControl::LowLevel::unpack_field(data, 4u, 4u, false);
        out->TYPE_2  = ::CanControl::LowLevel::unpack_field(data, 8u, 4u, false);
        out->TYPE_3  = ::CanControl::LowLevel::unpack_field(data, 12u, 4u, false);
        out->TYPE_4  = ::CanControl::LowLevel::unpack_field(data, 16u, 4u, false);
        out->TYPE_5  = ::CanControl::LowLevel::unpack_field(data, 20u, 4u, false);
        out->TYPE_6  = ::CanControl::LowLevel::unpack_field(data, 24u, 4u, false);
        out->TYPE_7  = ::CanControl::LowLevel::unpack_field(data, 28u, 4u, false);
        out->TYPE_8  = ::CanControl::LowLevel::unpack_field(data, 32u, 4u, false);
        out->TYPE_9  = ::CanControl::LowLevel::unpack_field(data, 36u, 4u, false);
        out->TYPE_10 = ::CanControl::LowLevel::unpack_field(data, 40u, 4u, false);
        out->TYPE_11 = ::CanControl::LowLevel::unpack_field(data, 44u, 4u, false);
        out->TYPE_12 = ::CanControl::LowLevel::unpack_field(data, 48u, 4u, false);
        out->TYPE_13 = ::CanControl::LowLevel::unpack_field(data, 52u, 4u, false);
        out->TYPE_14 = ::CanControl::LowLevel::unpack_field(data, 56u, 4u, false);
        out->TYPE_15 = ::CanControl::LowLevel::unpack_field(data, 60u, 4u, false);
        return true;
    }

    // Decode frame payload for Get Parameter 144 to 159 Types: Get types of parameters 144 to 159
    bool spark_decode_GET_PARAMETER_144_TO_159_TYPES(const uint8_t* data, uint8_t dlc,
                                                     Spark_GET_PARAMETER_144_TO_159_TYPES_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->TYPE_0  = ::CanControl::LowLevel::unpack_field(data, 0u, 4u, false);
        out->TYPE_1  = ::CanControl::LowLevel::unpack_field(data, 4u, 4u, false);
        out->TYPE_2  = ::CanControl::LowLevel::unpack_field(data, 8u, 4u, false);
        out->TYPE_3  = ::CanControl::LowLevel::unpack_field(data, 12u, 4u, false);
        out->TYPE_4  = ::CanControl::LowLevel::unpack_field(data, 16u, 4u, false);
        out->TYPE_5  = ::CanControl::LowLevel::unpack_field(data, 20u, 4u, false);
        out->TYPE_6  = ::CanControl::LowLevel::unpack_field(data, 24u, 4u, false);
        out->TYPE_7  = ::CanControl::LowLevel::unpack_field(data, 28u, 4u, false);
        out->TYPE_8  = ::CanControl::LowLevel::unpack_field(data, 32u, 4u, false);
        out->TYPE_9  = ::CanControl::LowLevel::unpack_field(data, 36u, 4u, false);
        out->TYPE_10 = ::CanControl::LowLevel::unpack_field(data, 40u, 4u, false);
        out->TYPE_11 = ::CanControl::LowLevel::unpack_field(data, 44u, 4u, false);
        out->TYPE_12 = ::CanControl::LowLevel::unpack_field(data, 48u, 4u, false);
        out->TYPE_13 = ::CanControl::LowLevel::unpack_field(data, 52u, 4u, false);
        out->TYPE_14 = ::CanControl::LowLevel::unpack_field(data, 56u, 4u, false);
        out->TYPE_15 = ::CanControl::LowLevel::unpack_field(data, 60u, 4u, false);
        return true;
    }

    // Decode frame payload for Get Parameter 160 to 175 Types: Get types of parameters 160 to 175
    bool spark_decode_GET_PARAMETER_160_TO_175_TYPES(const uint8_t* data, uint8_t dlc,
                                                     Spark_GET_PARAMETER_160_TO_175_TYPES_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->TYPE_0  = ::CanControl::LowLevel::unpack_field(data, 0u, 4u, false);
        out->TYPE_1  = ::CanControl::LowLevel::unpack_field(data, 4u, 4u, false);
        out->TYPE_2  = ::CanControl::LowLevel::unpack_field(data, 8u, 4u, false);
        out->TYPE_3  = ::CanControl::LowLevel::unpack_field(data, 12u, 4u, false);
        out->TYPE_4  = ::CanControl::LowLevel::unpack_field(data, 16u, 4u, false);
        out->TYPE_5  = ::CanControl::LowLevel::unpack_field(data, 20u, 4u, false);
        out->TYPE_6  = ::CanControl::LowLevel::unpack_field(data, 24u, 4u, false);
        out->TYPE_7  = ::CanControl::LowLevel::unpack_field(data, 28u, 4u, false);
        out->TYPE_8  = ::CanControl::LowLevel::unpack_field(data, 32u, 4u, false);
        out->TYPE_9  = ::CanControl::LowLevel::unpack_field(data, 36u, 4u, false);
        out->TYPE_10 = ::CanControl::LowLevel::unpack_field(data, 40u, 4u, false);
        out->TYPE_11 = ::CanControl::LowLevel::unpack_field(data, 44u, 4u, false);
        out->TYPE_12 = ::CanControl::LowLevel::unpack_field(data, 48u, 4u, false);
        out->TYPE_13 = ::CanControl::LowLevel::unpack_field(data, 52u, 4u, false);
        out->TYPE_14 = ::CanControl::LowLevel::unpack_field(data, 56u, 4u, false);
        out->TYPE_15 = ::CanControl::LowLevel::unpack_field(data, 60u, 4u, false);
        return true;
    }

    // Decode frame payload for Get Parameter 176 to 191 Types: Get types of parameters 176 to 191
    bool spark_decode_GET_PARAMETER_176_TO_191_TYPES(const uint8_t* data, uint8_t dlc,
                                                     Spark_GET_PARAMETER_176_TO_191_TYPES_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->TYPE_0  = ::CanControl::LowLevel::unpack_field(data, 0u, 4u, false);
        out->TYPE_1  = ::CanControl::LowLevel::unpack_field(data, 4u, 4u, false);
        out->TYPE_2  = ::CanControl::LowLevel::unpack_field(data, 8u, 4u, false);
        out->TYPE_3  = ::CanControl::LowLevel::unpack_field(data, 12u, 4u, false);
        out->TYPE_4  = ::CanControl::LowLevel::unpack_field(data, 16u, 4u, false);
        out->TYPE_5  = ::CanControl::LowLevel::unpack_field(data, 20u, 4u, false);
        out->TYPE_6  = ::CanControl::LowLevel::unpack_field(data, 24u, 4u, false);
        out->TYPE_7  = ::CanControl::LowLevel::unpack_field(data, 28u, 4u, false);
        out->TYPE_8  = ::CanControl::LowLevel::unpack_field(data, 32u, 4u, false);
        out->TYPE_9  = ::CanControl::LowLevel::unpack_field(data, 36u, 4u, false);
        out->TYPE_10 = ::CanControl::LowLevel::unpack_field(data, 40u, 4u, false);
        out->TYPE_11 = ::CanControl::LowLevel::unpack_field(data, 44u, 4u, false);
        out->TYPE_12 = ::CanControl::LowLevel::unpack_field(data, 48u, 4u, false);
        out->TYPE_13 = ::CanControl::LowLevel::unpack_field(data, 52u, 4u, false);
        out->TYPE_14 = ::CanControl::LowLevel::unpack_field(data, 56u, 4u, false);
        out->TYPE_15 = ::CanControl::LowLevel::unpack_field(data, 60u, 4u, false);
        return true;
    }

    // Decode frame payload for Get Parameter 192 to 207 Types: Get types of parameters 192 to 207
    bool spark_decode_GET_PARAMETER_192_TO_207_TYPES(const uint8_t* data, uint8_t dlc,
                                                     Spark_GET_PARAMETER_192_TO_207_TYPES_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->TYPE_0  = ::CanControl::LowLevel::unpack_field(data, 0u, 4u, false);
        out->TYPE_1  = ::CanControl::LowLevel::unpack_field(data, 4u, 4u, false);
        out->TYPE_2  = ::CanControl::LowLevel::unpack_field(data, 8u, 4u, false);
        out->TYPE_3  = ::CanControl::LowLevel::unpack_field(data, 12u, 4u, false);
        out->TYPE_4  = ::CanControl::LowLevel::unpack_field(data, 16u, 4u, false);
        out->TYPE_5  = ::CanControl::LowLevel::unpack_field(data, 20u, 4u, false);
        out->TYPE_6  = ::CanControl::LowLevel::unpack_field(data, 24u, 4u, false);
        out->TYPE_7  = ::CanControl::LowLevel::unpack_field(data, 28u, 4u, false);
        out->TYPE_8  = ::CanControl::LowLevel::unpack_field(data, 32u, 4u, false);
        out->TYPE_9  = ::CanControl::LowLevel::unpack_field(data, 36u, 4u, false);
        out->TYPE_10 = ::CanControl::LowLevel::unpack_field(data, 40u, 4u, false);
        out->TYPE_11 = ::CanControl::LowLevel::unpack_field(data, 44u, 4u, false);
        out->TYPE_12 = ::CanControl::LowLevel::unpack_field(data, 48u, 4u, false);
        out->TYPE_13 = ::CanControl::LowLevel::unpack_field(data, 52u, 4u, false);
        out->TYPE_14 = ::CanControl::LowLevel::unpack_field(data, 56u, 4u, false);
        out->TYPE_15 = ::CanControl::LowLevel::unpack_field(data, 60u, 4u, false);
        return true;
    }

    // Decode frame payload for Get Parameter 208 to 223 Types: Get types of parameters 208 to 223
    bool spark_decode_GET_PARAMETER_208_TO_223_TYPES(const uint8_t* data, uint8_t dlc,
                                                     Spark_GET_PARAMETER_208_TO_223_TYPES_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->TYPE_0  = ::CanControl::LowLevel::unpack_field(data, 0u, 4u, false);
        out->TYPE_1  = ::CanControl::LowLevel::unpack_field(data, 4u, 4u, false);
        out->TYPE_2  = ::CanControl::LowLevel::unpack_field(data, 8u, 4u, false);
        out->TYPE_3  = ::CanControl::LowLevel::unpack_field(data, 12u, 4u, false);
        out->TYPE_4  = ::CanControl::LowLevel::unpack_field(data, 16u, 4u, false);
        out->TYPE_5  = ::CanControl::LowLevel::unpack_field(data, 20u, 4u, false);
        out->TYPE_6  = ::CanControl::LowLevel::unpack_field(data, 24u, 4u, false);
        out->TYPE_7  = ::CanControl::LowLevel::unpack_field(data, 28u, 4u, false);
        out->TYPE_8  = ::CanControl::LowLevel::unpack_field(data, 32u, 4u, false);
        out->TYPE_9  = ::CanControl::LowLevel::unpack_field(data, 36u, 4u, false);
        out->TYPE_10 = ::CanControl::LowLevel::unpack_field(data, 40u, 4u, false);
        out->TYPE_11 = ::CanControl::LowLevel::unpack_field(data, 44u, 4u, false);
        out->TYPE_12 = ::CanControl::LowLevel::unpack_field(data, 48u, 4u, false);
        out->TYPE_13 = ::CanControl::LowLevel::unpack_field(data, 52u, 4u, false);
        out->TYPE_14 = ::CanControl::LowLevel::unpack_field(data, 56u, 4u, false);
        out->TYPE_15 = ::CanControl::LowLevel::unpack_field(data, 60u, 4u, false);
        return true;
    }

    // Decode frame payload for Get Parameter 224 to 239 Types: Get types of parameters 224 to 239
    bool spark_decode_GET_PARAMETER_224_TO_239_TYPES(const uint8_t* data, uint8_t dlc,
                                                     Spark_GET_PARAMETER_224_TO_239_TYPES_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->TYPE_0  = ::CanControl::LowLevel::unpack_field(data, 0u, 4u, false);
        out->TYPE_1  = ::CanControl::LowLevel::unpack_field(data, 4u, 4u, false);
        out->TYPE_2  = ::CanControl::LowLevel::unpack_field(data, 8u, 4u, false);
        out->TYPE_3  = ::CanControl::LowLevel::unpack_field(data, 12u, 4u, false);
        out->TYPE_4  = ::CanControl::LowLevel::unpack_field(data, 16u, 4u, false);
        out->TYPE_5  = ::CanControl::LowLevel::unpack_field(data, 20u, 4u, false);
        out->TYPE_6  = ::CanControl::LowLevel::unpack_field(data, 24u, 4u, false);
        out->TYPE_7  = ::CanControl::LowLevel::unpack_field(data, 28u, 4u, false);
        out->TYPE_8  = ::CanControl::LowLevel::unpack_field(data, 32u, 4u, false);
        out->TYPE_9  = ::CanControl::LowLevel::unpack_field(data, 36u, 4u, false);
        out->TYPE_10 = ::CanControl::LowLevel::unpack_field(data, 40u, 4u, false);
        out->TYPE_11 = ::CanControl::LowLevel::unpack_field(data, 44u, 4u, false);
        out->TYPE_12 = ::CanControl::LowLevel::unpack_field(data, 48u, 4u, false);
        out->TYPE_13 = ::CanControl::LowLevel::unpack_field(data, 52u, 4u, false);
        out->TYPE_14 = ::CanControl::LowLevel::unpack_field(data, 56u, 4u, false);
        out->TYPE_15 = ::CanControl::LowLevel::unpack_field(data, 60u, 4u, false);
        return true;
    }

    // Decode frame payload for Get Parameter 240 to 255 Types: Get types of parameters 240 to 255
    bool spark_decode_GET_PARAMETER_240_TO_255_TYPES(const uint8_t* data, uint8_t dlc,
                                                     Spark_GET_PARAMETER_240_TO_255_TYPES_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->TYPE_0  = ::CanControl::LowLevel::unpack_field(data, 0u, 4u, false);
        out->TYPE_1  = ::CanControl::LowLevel::unpack_field(data, 4u, 4u, false);
        out->TYPE_2  = ::CanControl::LowLevel::unpack_field(data, 8u, 4u, false);
        out->TYPE_3  = ::CanControl::LowLevel::unpack_field(data, 12u, 4u, false);
        out->TYPE_4  = ::CanControl::LowLevel::unpack_field(data, 16u, 4u, false);
        out->TYPE_5  = ::CanControl::LowLevel::unpack_field(data, 20u, 4u, false);
        out->TYPE_6  = ::CanControl::LowLevel::unpack_field(data, 24u, 4u, false);
        out->TYPE_7  = ::CanControl::LowLevel::unpack_field(data, 28u, 4u, false);
        out->TYPE_8  = ::CanControl::LowLevel::unpack_field(data, 32u, 4u, false);
        out->TYPE_9  = ::CanControl::LowLevel::unpack_field(data, 36u, 4u, false);
        out->TYPE_10 = ::CanControl::LowLevel::unpack_field(data, 40u, 4u, false);
        out->TYPE_11 = ::CanControl::LowLevel::unpack_field(data, 44u, 4u, false);
        out->TYPE_12 = ::CanControl::LowLevel::unpack_field(data, 48u, 4u, false);
        out->TYPE_13 = ::CanControl::LowLevel::unpack_field(data, 52u, 4u, false);
        out->TYPE_14 = ::CanControl::LowLevel::unpack_field(data, 56u, 4u, false);
        out->TYPE_15 = ::CanControl::LowLevel::unpack_field(data, 60u, 4u, false);
        return true;
    }

    // Decode frame payload for Parameter Write: Write a single parameter value. In response, a Parameter Write Response
    // frame will be sent.
    bool spark_decode_PARAMETER_WRITE(const uint8_t* data, uint8_t dlc, Spark_PARAMETER_WRITE_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 5u)
            return false;
        out->PARAMETER_ID = ::CanControl::LowLevel::unpack_field(data, 0u, 8u, false);
        out->VALUE        = ::CanControl::LowLevel::unpack_field(data, 8u, 32u, false);
        return true;
    }

    // Decode frame payload for Parameter Write Response: Response for a parameter write (including a write done as part
    // of a dual-write)
    bool spark_decode_PARAMETER_WRITE_RESPONSE(const uint8_t* data, uint8_t dlc, Spark_PARAMETER_WRITE_RESPONSE_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 7u)
            return false;
        out->PARAMETER_ID   = ::CanControl::LowLevel::unpack_field(data, 0u, 8u, false);
        out->PARAMETER_TYPE = ::CanControl::LowLevel::unpack_field(data, 8u, 8u, false);
        out->VALUE          = ::CanControl::LowLevel::unpack_field(data, 16u, 32u, false);
        out->RESULT_CODE    = ::CanControl::LowLevel::unpack_field(data, 48u, 8u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 0 and 1: Read parameter 0 and 1 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_0_AND_1(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_0_AND_1_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 2 and 3: Read parameter 2 and 3 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_2_AND_3(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_2_AND_3_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 4 and 5: Read parameter 4 and 5 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_4_AND_5(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_4_AND_5_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 6 and 7: Read parameter 6 and 7 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_6_AND_7(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_6_AND_7_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 8 and 9: Read parameter 8 and 9 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_8_AND_9(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_8_AND_9_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 10 and 11: Read parameter 10 and 11 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_10_AND_11(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_10_AND_11_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 12 and 13: Read parameter 12 and 13 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_12_AND_13(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_12_AND_13_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 14 and 15: Read parameter 14 and 15 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_14_AND_15(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_14_AND_15_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 16 and 17: Read parameter 16 and 17 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_16_AND_17(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_16_AND_17_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 18 and 19: Read parameter 18 and 19 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_18_AND_19(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_18_AND_19_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 20 and 21: Read parameter 20 and 21 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_20_AND_21(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_20_AND_21_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 22 and 23: Read parameter 22 and 23 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_22_AND_23(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_22_AND_23_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 24 and 25: Read parameter 24 and 25 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_24_AND_25(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_24_AND_25_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 26 and 27: Read parameter 26 and 27 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_26_AND_27(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_26_AND_27_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 28 and 29: Read parameter 28 and 29 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_28_AND_29(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_28_AND_29_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 30 and 31: Read parameter 30 and 31 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_30_AND_31(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_30_AND_31_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 32 and 33: Read parameter 32 and 33 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_32_AND_33(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_32_AND_33_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 34 and 35: Read parameter 34 and 35 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_34_AND_35(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_34_AND_35_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 36 and 37: Read parameter 36 and 37 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_36_AND_37(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_36_AND_37_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 38 and 39: Read parameter 38 and 39 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_38_AND_39(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_38_AND_39_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 40 and 41: Read parameter 40 and 41 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_40_AND_41(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_40_AND_41_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 42 and 43: Read parameter 42 and 43 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_42_AND_43(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_42_AND_43_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 44 and 45: Read parameter 44 and 45 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_44_AND_45(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_44_AND_45_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 46 and 47: Read parameter 46 and 47 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_46_AND_47(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_46_AND_47_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 48 and 49: Read parameter 48 and 49 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_48_AND_49(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_48_AND_49_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 50 and 51: Read parameter 50 and 51 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_50_AND_51(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_50_AND_51_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 52 and 53: Read parameter 52 and 53 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_52_AND_53(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_52_AND_53_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 54 and 55: Read parameter 54 and 55 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_54_AND_55(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_54_AND_55_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 56 and 57: Read parameter 56 and 57 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_56_AND_57(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_56_AND_57_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 58 and 59: Read parameter 58 and 59 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_58_AND_59(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_58_AND_59_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 60 and 61: Read parameter 60 and 61 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_60_AND_61(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_60_AND_61_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 62 and 63: Read parameter 62 and 63 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_62_AND_63(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_62_AND_63_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 64 and 65: Read parameter 64 and 65 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_64_AND_65(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_64_AND_65_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 66 and 67: Read parameter 66 and 67 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_66_AND_67(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_66_AND_67_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 68 and 69: Read parameter 68 and 69 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_68_AND_69(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_68_AND_69_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 70 and 71: Read parameter 70 and 71 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_70_AND_71(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_70_AND_71_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 72 and 73: Read parameter 72 and 73 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_72_AND_73(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_72_AND_73_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 74 and 75: Read parameter 74 and 75 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_74_AND_75(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_74_AND_75_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 76 and 77: Read parameter 76 and 77 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_76_AND_77(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_76_AND_77_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 78 and 79: Read parameter 78 and 79 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_78_AND_79(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_78_AND_79_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 80 and 81: Read parameter 80 and 81 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_80_AND_81(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_80_AND_81_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 82 and 83: Read parameter 82 and 83 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_82_AND_83(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_82_AND_83_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 84 and 85: Read parameter 84 and 85 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_84_AND_85(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_84_AND_85_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 86 and 87: Read parameter 86 and 87 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_86_AND_87(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_86_AND_87_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 88 and 89: Read parameter 88 and 89 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_88_AND_89(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_88_AND_89_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 90 and 91: Read parameter 90 and 91 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_90_AND_91(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_90_AND_91_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 92 and 93: Read parameter 92 and 93 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_92_AND_93(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_92_AND_93_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 94 and 95: Read parameter 94 and 95 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_94_AND_95(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_94_AND_95_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 96 and 97: Read parameter 96 and 97 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_96_AND_97(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_96_AND_97_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 98 and 99: Read parameter 98 and 99 at the same time. SPARK MAX does not
    // currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_98_AND_99(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_98_AND_99_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 100 and 101: Read parameter 100 and 101 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_100_AND_101(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_100_AND_101_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 102 and 103: Read parameter 102 and 103 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_102_AND_103(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_102_AND_103_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 104 and 105: Read parameter 104 and 105 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_104_AND_105(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_104_AND_105_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 106 and 107: Read parameter 106 and 107 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_106_AND_107(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_106_AND_107_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 108 and 109: Read parameter 108 and 109 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_108_AND_109(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_108_AND_109_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 110 and 111: Read parameter 110 and 111 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_110_AND_111(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_110_AND_111_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 112 and 113: Read parameter 112 and 113 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_112_AND_113(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_112_AND_113_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 114 and 115: Read parameter 114 and 115 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_114_AND_115(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_114_AND_115_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 116 and 117: Read parameter 116 and 117 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_116_AND_117(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_116_AND_117_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 118 and 119: Read parameter 118 and 119 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_118_AND_119(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_118_AND_119_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 120 and 121: Read parameter 120 and 121 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_120_AND_121(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_120_AND_121_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 122 and 123: Read parameter 122 and 123 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_122_AND_123(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_122_AND_123_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 124 and 125: Read parameter 124 and 125 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_124_AND_125(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_124_AND_125_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 126 and 127: Read parameter 126 and 127 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_126_AND_127(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_126_AND_127_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 128 and 129: Read parameter 128 and 129 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_128_AND_129(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_128_AND_129_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 130 and 131: Read parameter 130 and 131 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_130_AND_131(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_130_AND_131_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 132 and 133: Read parameter 132 and 133 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_132_AND_133(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_132_AND_133_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 134 and 135: Read parameter 134 and 135 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_134_AND_135(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_134_AND_135_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 136 and 137: Read parameter 136 and 137 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_136_AND_137(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_136_AND_137_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 138 and 139: Read parameter 138 and 139 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_138_AND_139(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_138_AND_139_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 140 and 141: Read parameter 140 and 141 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_140_AND_141(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_140_AND_141_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 142 and 143: Read parameter 142 and 143 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_142_AND_143(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_142_AND_143_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 144 and 145: Read parameter 144 and 145 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_144_AND_145(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_144_AND_145_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 146 and 147: Read parameter 146 and 147 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_146_AND_147(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_146_AND_147_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 148 and 149: Read parameter 148 and 149 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_148_AND_149(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_148_AND_149_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 150 and 151: Read parameter 150 and 151 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_150_AND_151(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_150_AND_151_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 152 and 153: Read parameter 152 and 153 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_152_AND_153(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_152_AND_153_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 154 and 155: Read parameter 154 and 155 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_154_AND_155(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_154_AND_155_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 156 and 157: Read parameter 156 and 157 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_156_AND_157(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_156_AND_157_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 158 and 159: Read parameter 158 and 159 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_158_AND_159(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_158_AND_159_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 160 and 161: Read parameter 160 and 161 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_160_AND_161(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_160_AND_161_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 162 and 163: Read parameter 162 and 163 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_162_AND_163(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_162_AND_163_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 164 and 165: Read parameter 164 and 165 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_164_AND_165(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_164_AND_165_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 166 and 167: Read parameter 166 and 167 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_166_AND_167(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_166_AND_167_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 168 and 169: Read parameter 168 and 169 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_168_AND_169(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_168_AND_169_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 170 and 171: Read parameter 170 and 171 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_170_AND_171(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_170_AND_171_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 172 and 173: Read parameter 172 and 173 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_172_AND_173(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_172_AND_173_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 174 and 175: Read parameter 174 and 175 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_174_AND_175(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_174_AND_175_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 176 and 177: Read parameter 176 and 177 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_176_AND_177(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_176_AND_177_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 178 and 179: Read parameter 178 and 179 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_178_AND_179(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_178_AND_179_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 180 and 181: Read parameter 180 and 181 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_180_AND_181(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_180_AND_181_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 182 and 183: Read parameter 182 and 183 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_182_AND_183(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_182_AND_183_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 184 and 185: Read parameter 184 and 185 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_184_AND_185(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_184_AND_185_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 186 and 187: Read parameter 186 and 187 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_186_AND_187(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_186_AND_187_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 188 and 189: Read parameter 188 and 189 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_188_AND_189(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_188_AND_189_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 190 and 191: Read parameter 190 and 191 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_190_AND_191(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_190_AND_191_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 192 and 193: Read parameter 192 and 193 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_192_AND_193(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_192_AND_193_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 194 and 195: Read parameter 194 and 195 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_194_AND_195(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_194_AND_195_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 196 and 197: Read parameter 196 and 197 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_196_AND_197(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_196_AND_197_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 198 and 199: Read parameter 198 and 199 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_198_AND_199(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_198_AND_199_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 200 and 201: Read parameter 200 and 201 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_200_AND_201(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_200_AND_201_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 202 and 203: Read parameter 202 and 203 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_202_AND_203(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_202_AND_203_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 204 and 205: Read parameter 204 and 205 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_204_AND_205(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_204_AND_205_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 206 and 207: Read parameter 206 and 207 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_206_AND_207(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_206_AND_207_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 208 and 209: Read parameter 208 and 209 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_208_AND_209(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_208_AND_209_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 210 and 211: Read parameter 210 and 211 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_210_AND_211(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_210_AND_211_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 212 and 213: Read parameter 212 and 213 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_212_AND_213(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_212_AND_213_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 214 and 215: Read parameter 214 and 215 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_214_AND_215(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_214_AND_215_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 216 and 217: Read parameter 216 and 217 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_216_AND_217(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_216_AND_217_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 218 and 219: Read parameter 218 and 219 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_218_AND_219(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_218_AND_219_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 220 and 221: Read parameter 220 and 221 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_220_AND_221(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_220_AND_221_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 222 and 223: Read parameter 222 and 223 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_222_AND_223(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_222_AND_223_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 224 and 225: Read parameter 224 and 225 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_224_AND_225(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_224_AND_225_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 226 and 227: Read parameter 226 and 227 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_226_AND_227(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_226_AND_227_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 228 and 229: Read parameter 228 and 229 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_228_AND_229(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_228_AND_229_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 230 and 231: Read parameter 230 and 231 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_230_AND_231(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_230_AND_231_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 232 and 233: Read parameter 232 and 233 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_232_AND_233(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_232_AND_233_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 234 and 235: Read parameter 234 and 235 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_234_AND_235(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_234_AND_235_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 236 and 237: Read parameter 236 and 237 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_236_AND_237(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_236_AND_237_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 238 and 239: Read parameter 238 and 239 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_238_AND_239(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_238_AND_239_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 240 and 241: Read parameter 240 and 241 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_240_AND_241(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_240_AND_241_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 242 and 243: Read parameter 242 and 243 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_242_AND_243(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_242_AND_243_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 244 and 245: Read parameter 244 and 245 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_244_AND_245(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_244_AND_245_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 246 and 247: Read parameter 246 and 247 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_246_AND_247(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_246_AND_247_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 248 and 249: Read parameter 248 and 249 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_248_AND_249(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_248_AND_249_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 250 and 251: Read parameter 250 and 251 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_250_AND_251(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_250_AND_251_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 252 and 253: Read parameter 252 and 253 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_252_AND_253(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_252_AND_253_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Read Parameter 254 and 255: Read parameter 254 and 255 at the same time. SPARK MAX does
    // not currently support this in v25.0.0-prerelease.4
    bool spark_decode_READ_PARAMETER_254_AND_255(const uint8_t* data, uint8_t dlc,
                                                 Spark_READ_PARAMETER_254_AND_255_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 0 and 1: Write Parameter 0 and 1 at the same time. Two Write Parameter
    // Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_0_AND_1(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_0_AND_1_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 2 and 3: Write Parameter 2 and 3 at the same time. Two Write Parameter
    // Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_2_AND_3(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_2_AND_3_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 4 and 5: Write Parameter 4 and 5 at the same time. Two Write Parameter
    // Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_4_AND_5(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_4_AND_5_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 6 and 7: Write Parameter 6 and 7 at the same time. Two Write Parameter
    // Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_6_AND_7(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_6_AND_7_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 8 and 9: Write Parameter 8 and 9 at the same time. Two Write Parameter
    // Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_8_AND_9(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_8_AND_9_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 10 and 11: Write Parameter 10 and 11 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_10_AND_11(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_10_AND_11_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 12 and 13: Write Parameter 12 and 13 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_12_AND_13(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_12_AND_13_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 14 and 15: Write Parameter 14 and 15 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_14_AND_15(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_14_AND_15_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 16 and 17: Write Parameter 16 and 17 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_16_AND_17(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_16_AND_17_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 18 and 19: Write Parameter 18 and 19 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_18_AND_19(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_18_AND_19_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 20 and 21: Write Parameter 20 and 21 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_20_AND_21(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_20_AND_21_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 22 and 23: Write Parameter 22 and 23 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_22_AND_23(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_22_AND_23_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 24 and 25: Write Parameter 24 and 25 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_24_AND_25(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_24_AND_25_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 26 and 27: Write Parameter 26 and 27 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_26_AND_27(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_26_AND_27_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 28 and 29: Write Parameter 28 and 29 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_28_AND_29(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_28_AND_29_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 30 and 31: Write Parameter 30 and 31 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_30_AND_31(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_30_AND_31_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 32 and 33: Write Parameter 32 and 33 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_32_AND_33(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_32_AND_33_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 34 and 35: Write Parameter 34 and 35 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_34_AND_35(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_34_AND_35_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 36 and 37: Write Parameter 36 and 37 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_36_AND_37(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_36_AND_37_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 38 and 39: Write Parameter 38 and 39 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_38_AND_39(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_38_AND_39_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 40 and 41: Write Parameter 40 and 41 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_40_AND_41(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_40_AND_41_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 42 and 43: Write Parameter 42 and 43 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_42_AND_43(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_42_AND_43_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 44 and 45: Write Parameter 44 and 45 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_44_AND_45(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_44_AND_45_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 46 and 47: Write Parameter 46 and 47 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_46_AND_47(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_46_AND_47_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 48 and 49: Write Parameter 48 and 49 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_48_AND_49(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_48_AND_49_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 50 and 51: Write Parameter 50 and 51 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_50_AND_51(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_50_AND_51_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 52 and 53: Write Parameter 52 and 53 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_52_AND_53(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_52_AND_53_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 54 and 55: Write Parameter 54 and 55 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_54_AND_55(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_54_AND_55_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 56 and 57: Write Parameter 56 and 57 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_56_AND_57(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_56_AND_57_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 58 and 59: Write Parameter 58 and 59 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_58_AND_59(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_58_AND_59_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 60 and 61: Write Parameter 60 and 61 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_60_AND_61(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_60_AND_61_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 62 and 63: Write Parameter 62 and 63 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_62_AND_63(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_62_AND_63_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 64 and 65: Write Parameter 64 and 65 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_64_AND_65(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_64_AND_65_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 66 and 67: Write Parameter 66 and 67 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_66_AND_67(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_66_AND_67_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 68 and 69: Write Parameter 68 and 69 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_68_AND_69(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_68_AND_69_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 70 and 71: Write Parameter 70 and 71 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_70_AND_71(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_70_AND_71_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 72 and 73: Write Parameter 72 and 73 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_72_AND_73(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_72_AND_73_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 74 and 75: Write Parameter 74 and 75 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_74_AND_75(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_74_AND_75_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 76 and 77: Write Parameter 76 and 77 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_76_AND_77(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_76_AND_77_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 78 and 79: Write Parameter 78 and 79 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_78_AND_79(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_78_AND_79_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 80 and 81: Write Parameter 80 and 81 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_80_AND_81(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_80_AND_81_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 82 and 83: Write Parameter 82 and 83 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_82_AND_83(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_82_AND_83_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 84 and 85: Write Parameter 84 and 85 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_84_AND_85(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_84_AND_85_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 86 and 87: Write Parameter 86 and 87 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_86_AND_87(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_86_AND_87_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 88 and 89: Write Parameter 88 and 89 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_88_AND_89(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_88_AND_89_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 90 and 91: Write Parameter 90 and 91 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_90_AND_91(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_90_AND_91_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 92 and 93: Write Parameter 92 and 93 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_92_AND_93(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_92_AND_93_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 94 and 95: Write Parameter 94 and 95 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_94_AND_95(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_94_AND_95_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 96 and 97: Write Parameter 96 and 97 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_96_AND_97(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_96_AND_97_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 98 and 99: Write Parameter 98 and 99 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_98_AND_99(const uint8_t* data, uint8_t dlc,
                                                Spark_WRITE_PARAMETER_98_AND_99_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 100 and 101: Write Parameter 100 and 101 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_100_AND_101(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_100_AND_101_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 102 and 103: Write Parameter 102 and 103 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_102_AND_103(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_102_AND_103_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 104 and 105: Write Parameter 104 and 105 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_104_AND_105(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_104_AND_105_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 106 and 107: Write Parameter 106 and 107 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_106_AND_107(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_106_AND_107_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 108 and 109: Write Parameter 108 and 109 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_108_AND_109(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_108_AND_109_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 110 and 111: Write Parameter 110 and 111 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_110_AND_111(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_110_AND_111_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 112 and 113: Write Parameter 112 and 113 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_112_AND_113(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_112_AND_113_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 114 and 115: Write Parameter 114 and 115 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_114_AND_115(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_114_AND_115_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 116 and 117: Write Parameter 116 and 117 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_116_AND_117(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_116_AND_117_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 118 and 119: Write Parameter 118 and 119 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_118_AND_119(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_118_AND_119_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 120 and 121: Write Parameter 120 and 121 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_120_AND_121(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_120_AND_121_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 122 and 123: Write Parameter 122 and 123 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_122_AND_123(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_122_AND_123_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 124 and 125: Write Parameter 124 and 125 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_124_AND_125(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_124_AND_125_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 126 and 127: Write Parameter 126 and 127 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_126_AND_127(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_126_AND_127_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 128 and 129: Write Parameter 128 and 129 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_128_AND_129(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_128_AND_129_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 130 and 131: Write Parameter 130 and 131 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_130_AND_131(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_130_AND_131_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 132 and 133: Write Parameter 132 and 133 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_132_AND_133(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_132_AND_133_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 134 and 135: Write Parameter 134 and 135 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_134_AND_135(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_134_AND_135_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 136 and 137: Write Parameter 136 and 137 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_136_AND_137(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_136_AND_137_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 138 and 139: Write Parameter 138 and 139 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_138_AND_139(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_138_AND_139_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 140 and 141: Write Parameter 140 and 141 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_140_AND_141(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_140_AND_141_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 142 and 143: Write Parameter 142 and 143 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_142_AND_143(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_142_AND_143_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 144 and 145: Write Parameter 144 and 145 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_144_AND_145(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_144_AND_145_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 146 and 147: Write Parameter 146 and 147 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_146_AND_147(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_146_AND_147_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 148 and 149: Write Parameter 148 and 149 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_148_AND_149(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_148_AND_149_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 150 and 151: Write Parameter 150 and 151 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_150_AND_151(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_150_AND_151_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 152 and 153: Write Parameter 152 and 153 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_152_AND_153(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_152_AND_153_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 154 and 155: Write Parameter 154 and 155 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_154_AND_155(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_154_AND_155_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 156 and 157: Write Parameter 156 and 157 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_156_AND_157(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_156_AND_157_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 158 and 159: Write Parameter 158 and 159 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_158_AND_159(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_158_AND_159_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 160 and 161: Write Parameter 160 and 161 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_160_AND_161(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_160_AND_161_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 162 and 163: Write Parameter 162 and 163 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_162_AND_163(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_162_AND_163_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 164 and 165: Write Parameter 164 and 165 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_164_AND_165(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_164_AND_165_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 166 and 167: Write Parameter 166 and 167 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_166_AND_167(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_166_AND_167_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 168 and 169: Write Parameter 168 and 169 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_168_AND_169(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_168_AND_169_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 170 and 171: Write Parameter 170 and 171 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_170_AND_171(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_170_AND_171_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 172 and 173: Write Parameter 172 and 173 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_172_AND_173(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_172_AND_173_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 174 and 175: Write Parameter 174 and 175 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_174_AND_175(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_174_AND_175_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 176 and 177: Write Parameter 176 and 177 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_176_AND_177(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_176_AND_177_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 178 and 179: Write Parameter 178 and 179 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_178_AND_179(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_178_AND_179_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 180 and 181: Write Parameter 180 and 181 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_180_AND_181(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_180_AND_181_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 182 and 183: Write Parameter 182 and 183 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_182_AND_183(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_182_AND_183_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 184 and 185: Write Parameter 184 and 185 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_184_AND_185(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_184_AND_185_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 186 and 187: Write Parameter 186 and 187 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_186_AND_187(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_186_AND_187_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 188 and 189: Write Parameter 188 and 189 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_188_AND_189(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_188_AND_189_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 190 and 191: Write Parameter 190 and 191 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_190_AND_191(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_190_AND_191_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 192 and 193: Write Parameter 192 and 193 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_192_AND_193(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_192_AND_193_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 194 and 195: Write Parameter 194 and 195 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_194_AND_195(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_194_AND_195_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 196 and 197: Write Parameter 196 and 197 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_196_AND_197(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_196_AND_197_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 198 and 199: Write Parameter 198 and 199 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_198_AND_199(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_198_AND_199_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 200 and 201: Write Parameter 200 and 201 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_200_AND_201(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_200_AND_201_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 202 and 203: Write Parameter 202 and 203 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_202_AND_203(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_202_AND_203_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 204 and 205: Write Parameter 204 and 205 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_204_AND_205(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_204_AND_205_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 206 and 207: Write Parameter 206 and 207 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_206_AND_207(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_206_AND_207_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 208 and 209: Write Parameter 208 and 209 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_208_AND_209(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_208_AND_209_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 210 and 211: Write Parameter 210 and 211 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_210_AND_211(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_210_AND_211_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 212 and 213: Write Parameter 212 and 213 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_212_AND_213(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_212_AND_213_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 214 and 215: Write Parameter 214 and 215 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_214_AND_215(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_214_AND_215_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 216 and 217: Write Parameter 216 and 217 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_216_AND_217(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_216_AND_217_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 218 and 219: Write Parameter 218 and 219 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_218_AND_219(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_218_AND_219_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 220 and 221: Write Parameter 220 and 221 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_220_AND_221(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_220_AND_221_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 222 and 223: Write Parameter 222 and 223 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_222_AND_223(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_222_AND_223_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 224 and 225: Write Parameter 224 and 225 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_224_AND_225(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_224_AND_225_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 226 and 227: Write Parameter 226 and 227 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_226_AND_227(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_226_AND_227_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 228 and 229: Write Parameter 228 and 229 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_228_AND_229(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_228_AND_229_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 230 and 231: Write Parameter 230 and 231 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_230_AND_231(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_230_AND_231_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 232 and 233: Write Parameter 232 and 233 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_232_AND_233(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_232_AND_233_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 234 and 235: Write Parameter 234 and 235 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_234_AND_235(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_234_AND_235_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 236 and 237: Write Parameter 236 and 237 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_236_AND_237(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_236_AND_237_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 238 and 239: Write Parameter 238 and 239 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_238_AND_239(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_238_AND_239_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 240 and 241: Write Parameter 240 and 241 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_240_AND_241(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_240_AND_241_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 242 and 243: Write Parameter 242 and 243 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_242_AND_243(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_242_AND_243_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 244 and 245: Write Parameter 244 and 245 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_244_AND_245(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_244_AND_245_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 246 and 247: Write Parameter 246 and 247 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_246_AND_247(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_246_AND_247_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 248 and 249: Write Parameter 248 and 249 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_248_AND_249(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_248_AND_249_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 250 and 251: Write Parameter 250 and 251 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_250_AND_251(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_250_AND_251_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 252 and 253: Write Parameter 252 and 253 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_252_AND_253(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_252_AND_253_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Write Parameter 254 and 255: Write Parameter 254 and 255 at the same time. Two Write
    // Parameter Response frames will be sent in response.
    bool spark_decode_WRITE_PARAMETER_254_AND_255(const uint8_t* data, uint8_t dlc,
                                                  Spark_WRITE_PARAMETER_254_AND_255_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 8u)
            return false;
        out->FIRST_PARAMETER_VALUE  = ::CanControl::LowLevel::unpack_field(data, 0u, 32u, false);
        out->SECOND_PARAMETER_VALUE = ::CanControl::LowLevel::unpack_field(data, 32u, 32u, false);
        return true;
    }

    // Decode frame payload for Start Follower Mode Response: Response for a Start Follower Mode command
    bool spark_decode_START_FOLLOWER_MODE_RESPONSE(const uint8_t* data, uint8_t dlc,
                                                   Spark_START_FOLLOWER_MODE_RESPONSE_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 1u)
            return false;
        out->STATUS = ::CanControl::LowLevel::unpack_field(data, 0u, 8u, false);
        return true;
    }

    // Decode frame payload for Persist Parameters: Causes all parameters to be written to non-volatile storage. After
    // the operation (which may take up to a second) completes, a Persist Parameters Response frame will be sent.
    bool spark_decode_PERSIST_PARAMETERS(const uint8_t* data, uint8_t dlc, Spark_PERSIST_PARAMETERS_t* out)
    {
        if (!data || !out)
            return false;
        if (dlc < 2u)
            return false;
        out->MAGIC_NUMBER = ::CanControl::LowLevel::unpack_field(data, 0u, 16u, false);
        return true;
    }

} // namespace CanControl::LowLevel::SparkMax
