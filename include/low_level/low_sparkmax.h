// AUTO-GENERATED FILE. DO NOT EDIT. See gen.py
#pragma once
#include <stdint.h>
#include <string.h>
#include <mcp2515.h>
#include "frc_can.h"
#include "low_level.h"

namespace CanControl::LowLevel::SparkMax {

#define SPARK_DEVICE_ID_MASK 0x3Fu

using spark_can_frame = ::CanControl::LowLevel::basic_can_frame;

// Base arbitration IDs (OR with device_id & SPARK_DEVICE_ID_MASK)
// Legacy Status 0: This frame exists purely to inform old software that is not aware of firmware version 25+ that the SPARK is present
#define SPARK_ARB_LEGACY_STATUS_0 33888256u
// Bootloader 0: Periodic frame when device is in the bootloader
#define SPARK_ARB_BOOTLOADER_0 33927168u
// Status 0: Includes general data that is likely to need frequent refreshing
#define SPARK_ARB_STATUS_0 33929216u
// Status 1: Includes general data that can likely tolerate infrequent refreshing
#define SPARK_ARB_STATUS_1 33929280u
// Status 2: Includes data from the primary encoder (either a brushless motor's internal encoder, or the primary encoder associated with a brushed motor)
#define SPARK_ARB_STATUS_2 33929344u
// Status 3: Includes data from an analog sensor
#define SPARK_ARB_STATUS_3 33929408u
// Status 4: Includes data from the External Encoder (on SPARK MAX, this is the Alternate Encoder)
#define SPARK_ARB_STATUS_4 33929472u
// Status 5: Includes velocity and position data from a duty-cycle absolute encoder
#define SPARK_ARB_STATUS_5 33929536u
// Status 6: Includes other data from a duty-cycle absolute encoder
#define SPARK_ARB_STATUS_6 33929600u
// Status 7: Includes diagnostic data for closed-loop control
#define SPARK_ARB_STATUS_7 33929664u
// Status 8: Includes additional diagnostic data for closed-loop control
#define SPARK_ARB_STATUS_8 33929728u
// Status 9: Includes diagnostic data for MAXMotion closed-loop control
#define SPARK_ARB_STATUS_9 33929792u
// Unique ID Broadcast: Contains the unique ID of the device, to allow detecting duplicate CAN IDs. To avoid collisions, the SPARK Flex firmware will send this at an irregular period between 1000ms and 2000ms. SPARK MAX may use a constant period of 1000ms.
#define SPARK_ARB_UNIQUE_ID_BROADCAST 33930240u
// Velocity Setpoint: Sets the Control Type to Velocity and sets the target velocity
#define SPARK_ARB_VELOCITY_SETPOINT 33882112u
// Duty Cycle Setpoint: Sets the Control Type to Duty Cycle and sets the target duty cycle (from -1 to 1)
#define SPARK_ARB_DUTY_CYCLE_SETPOINT 33882240u
// Position Setpoint: Sets the Control Type to Position and sets the target position
#define SPARK_ARB_POSITION_SETPOINT 33882368u
// Voltage Setpoint: Sets the Control Type to Voltage and sets the target voltage
#define SPARK_ARB_VOLTAGE_SETPOINT 33882432u
// Current Setpoint: Sets the Control Type to Current and sets the target current
#define SPARK_ARB_CURRENT_SETPOINT 33882496u
// MAXMotion Position Setpoint: Sets the Control Type to MAXMotion Position Control and sets the target position
#define SPARK_ARB_MAXMOTION_POSITION_SETPOINT 33882624u
// MAXMotion Velocity Setpoint: Sets the Control Type to MAXMotion Velocity Control and sets the target velocity
#define SPARK_ARB_MAXMOTION_VELOCITY_SETPOINT 33882688u
// Set Statuses Enabled: Enable or disable status frames. In response, a Set Statuses Enabled Response frame will be sent.
#define SPARK_ARB_SET_STATUSES_ENABLED 33883136u
// Set Statuses Enabled Response: Response for a Set Statuses Enabled command
#define SPARK_ARB_SET_STATUSES_ENABLED_RESPONSE 33883200u
// Persist Parameters Response
#define SPARK_ARB_PERSIST_PARAMETERS_RESPONSE 33883392u
// Reset Safe Parameters: Resets most writable parameters to their default values, except CAN ID, Motor Type, Idle Mode, PWM Input Deadband, and Duty Cycle Offset. In response, a Reset Safe Parameters Response frame is sent.
#define SPARK_ARB_RESET_SAFE_PARAMETERS 33883456u
// Reset Safe Parameters Response: Response for a Reset Safe Parameters command
#define SPARK_ARB_RESET_SAFE_PARAMETERS_RESPONSE 33883520u
// Complete Factory Reset: Resets all writable parameters to default values, even CAN ID, Motor Type, Idle Mode, PWM Input Deadband, and Duty Cycle Offset. In response, a Complete Factory Reset Response frame is sent.
#define SPARK_ARB_COMPLETE_FACTORY_RESET 33883584u
// Complete Factory Reset Response: Response for a Complete Factory Reset command
#define SPARK_ARB_COMPLETE_FACTORY_RESET_RESPONSE 33883648u
// Clear Faults
#define SPARK_ARB_CLEAR_FAULTS 33889152u
// Identify Unique SPARK: Makes the specified, single SPARK (even if there are multiple SPARKs that have the same CAN ID) temporarily perform a special blink pattern that will make it stand out
#define SPARK_ARB_IDENTIFY_UNIQUE_SPARK 33889664u
// Identify: Makes the SPARK temporarily perform a special blink pattern that will make it stand out. Use Identify Unique Device if there may be multiple SPARKs with the same CAN ID.
#define SPARK_ARB_IDENTIFY 33889728u
// Nack: As of SPARK MAX firmware 1.6.3, this is only used as a potential response to setting the CAN ID
#define SPARK_ARB_NACK 33890304u
// Ack: As of SPARK MAX firmware 1.6.3, this is only used as a potential response to setting the CAN ID
#define SPARK_ARB_ACK 33890368u
// LED Sync: Causes all SPARKs on the bus to synchronize their LED patterns
#define SPARK_ARB_LED_SYNC 33891520u
// Set CAN ID: Allows changing the CAN ID when multiple devices on the bus currently have the same CAN ID. Under normal circumstances, the CAN ID parameter can be used.
#define SPARK_ARB_SET_CAN_ID 33891648u
// Get Firmware Version
#define SPARK_ARB_GET_FIRMWARE_VERSION 33891840u
// SWDL Data: Broadcast from the host to all SPARKs in SWDL mode, containing a slice of firmware data
#define SPARK_ARB_SWDL_DATA 33892096u
// SWDL Checksum: Broadcast from the host to all SPARKs in SWDL mode, containing the checksum of the full firmware image that was just sent
#define SPARK_ARB_SWDL_CHECKSUM 33892160u
// SWDL Retransmit: Sent by SPARK devices in response to receiving an SWDL Checksum frame that does not match the firmware data they received
#define SPARK_ARB_SWDL_RETRANSMIT 33892224u
// Set Primary Encoder Position
#define SPARK_ARB_SET_PRIMARY_ENCODER_POSITION 33892352u
// Set I Accumulation
#define SPARK_ARB_SET_I_ACCUMULATION 33892480u
// Set Analog Position
#define SPARK_ARB_SET_ANALOG_POSITION 33892544u
// Set Ext or Alt Encoder Position
#define SPARK_ARB_SET_EXT_OR_ALT_ENCODER_POSITION 33892608u
// Set Duty Cycle Position
#define SPARK_ARB_SET_DUTY_CYCLE_POSITION 33892672u
// Secondary Heartbeat: Heartbeat that allows enabling only specific SPARKs, but only gets respected when the SPARK is not locked to the Universal Heartbeat or Primary Heartbeat
#define SPARK_ARB_SECONDARY_HEARTBEAT 33893504u
// USB Only Identify: The response will only be sent if this command is received directly via USB. This has no relation to the normal Identify command, which displays an LED pattern.
#define SPARK_ARB_USB_ONLY_IDENTIFY 33893568u
// USB Only Enter DFU Bootloader: Causes the device to reboot into the DFU bootloader if this command is received directly via USB
#define SPARK_ARB_USB_ONLY_ENTER_DFU_BOOTLOADER 33893632u
// Get Temperatures
#define SPARK_ARB_GET_TEMPERATURES 33894400u
// Get Motor Interface
#define SPARK_ARB_GET_MOTOR_INTERFACE 33894720u
// Get Parameter 0 to 15 Types: Get types of parameters 0 to 15
#define SPARK_ARB_GET_PARAMETER_0_TO_15_TYPES 33895424u
// Get Parameter 16 to 31 Types: Get types of parameters 16 to 31
#define SPARK_ARB_GET_PARAMETER_16_TO_31_TYPES 33895488u
// Get Parameter 32 to 47 Types: Get types of parameters 32 to 47
#define SPARK_ARB_GET_PARAMETER_32_TO_47_TYPES 33895552u
// Get Parameter 48 to 63 Types: Get types of parameters 48 to 63
#define SPARK_ARB_GET_PARAMETER_48_TO_63_TYPES 33895616u
// Get Parameter 64 to 79 Types: Get types of parameters 64 to 79
#define SPARK_ARB_GET_PARAMETER_64_TO_79_TYPES 33895680u
// Get Parameter 80 to 95 Types: Get types of parameters 80 to 95
#define SPARK_ARB_GET_PARAMETER_80_TO_95_TYPES 33895744u
// Get Parameter 96 to 111 Types: Get types of parameters 96 to 111
#define SPARK_ARB_GET_PARAMETER_96_TO_111_TYPES 33895808u
// Get Parameter 112 to 127 Types: Get types of parameters 112 to 127
#define SPARK_ARB_GET_PARAMETER_112_TO_127_TYPES 33895872u
// Get Parameter 128 to 143 Types: Get types of parameters 128 to 143
#define SPARK_ARB_GET_PARAMETER_128_TO_143_TYPES 33895936u
// Get Parameter 144 to 159 Types: Get types of parameters 144 to 159
#define SPARK_ARB_GET_PARAMETER_144_TO_159_TYPES 33896000u
// Get Parameter 160 to 175 Types: Get types of parameters 160 to 175
#define SPARK_ARB_GET_PARAMETER_160_TO_175_TYPES 33896064u
// Get Parameter 176 to 191 Types: Get types of parameters 176 to 191
#define SPARK_ARB_GET_PARAMETER_176_TO_191_TYPES 33896128u
// Get Parameter 192 to 207 Types: Get types of parameters 192 to 207
#define SPARK_ARB_GET_PARAMETER_192_TO_207_TYPES 33896192u
// Get Parameter 208 to 223 Types: Get types of parameters 208 to 223
#define SPARK_ARB_GET_PARAMETER_208_TO_223_TYPES 33896256u
// Get Parameter 224 to 239 Types: Get types of parameters 224 to 239
#define SPARK_ARB_GET_PARAMETER_224_TO_239_TYPES 33896320u
// Get Parameter 240 to 255 Types: Get types of parameters 240 to 255
#define SPARK_ARB_GET_PARAMETER_240_TO_255_TYPES 33896384u
// Parameter Write: Write a single parameter value. In response, a Parameter Write Response frame will be sent.
#define SPARK_ARB_PARAMETER_WRITE 33896448u
// Parameter Write Response: Response for a parameter write (including a write done as part of a dual-write)
#define SPARK_ARB_PARAMETER_WRITE_RESPONSE 33896512u
// Read Parameter 0 and 1: Read parameter 0 and 1 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_0_AND_1 33897472u
// Read Parameter 2 and 3: Read parameter 2 and 3 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_2_AND_3 33897536u
// Read Parameter 4 and 5: Read parameter 4 and 5 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_4_AND_5 33897600u
// Read Parameter 6 and 7: Read parameter 6 and 7 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_6_AND_7 33897664u
// Read Parameter 8 and 9: Read parameter 8 and 9 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_8_AND_9 33897728u
// Read Parameter 10 and 11: Read parameter 10 and 11 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_10_AND_11 33897792u
// Read Parameter 12 and 13: Read parameter 12 and 13 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_12_AND_13 33897856u
// Read Parameter 14 and 15: Read parameter 14 and 15 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_14_AND_15 33897920u
// Read Parameter 16 and 17: Read parameter 16 and 17 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_16_AND_17 33897984u
// Read Parameter 18 and 19: Read parameter 18 and 19 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_18_AND_19 33898048u
// Read Parameter 20 and 21: Read parameter 20 and 21 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_20_AND_21 33898112u
// Read Parameter 22 and 23: Read parameter 22 and 23 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_22_AND_23 33898176u
// Read Parameter 24 and 25: Read parameter 24 and 25 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_24_AND_25 33898240u
// Read Parameter 26 and 27: Read parameter 26 and 27 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_26_AND_27 33898304u
// Read Parameter 28 and 29: Read parameter 28 and 29 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_28_AND_29 33898368u
// Read Parameter 30 and 31: Read parameter 30 and 31 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_30_AND_31 33898432u
// Read Parameter 32 and 33: Read parameter 32 and 33 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_32_AND_33 33898496u
// Read Parameter 34 and 35: Read parameter 34 and 35 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_34_AND_35 33898560u
// Read Parameter 36 and 37: Read parameter 36 and 37 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_36_AND_37 33898624u
// Read Parameter 38 and 39: Read parameter 38 and 39 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_38_AND_39 33898688u
// Read Parameter 40 and 41: Read parameter 40 and 41 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_40_AND_41 33898752u
// Read Parameter 42 and 43: Read parameter 42 and 43 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_42_AND_43 33898816u
// Read Parameter 44 and 45: Read parameter 44 and 45 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_44_AND_45 33898880u
// Read Parameter 46 and 47: Read parameter 46 and 47 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_46_AND_47 33898944u
// Read Parameter 48 and 49: Read parameter 48 and 49 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_48_AND_49 33899008u
// Read Parameter 50 and 51: Read parameter 50 and 51 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_50_AND_51 33899072u
// Read Parameter 52 and 53: Read parameter 52 and 53 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_52_AND_53 33899136u
// Read Parameter 54 and 55: Read parameter 54 and 55 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_54_AND_55 33899200u
// Read Parameter 56 and 57: Read parameter 56 and 57 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_56_AND_57 33899264u
// Read Parameter 58 and 59: Read parameter 58 and 59 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_58_AND_59 33899328u
// Read Parameter 60 and 61: Read parameter 60 and 61 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_60_AND_61 33899392u
// Read Parameter 62 and 63: Read parameter 62 and 63 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_62_AND_63 33899456u
// Read Parameter 64 and 65: Read parameter 64 and 65 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_64_AND_65 33899520u
// Read Parameter 66 and 67: Read parameter 66 and 67 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_66_AND_67 33899584u
// Read Parameter 68 and 69: Read parameter 68 and 69 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_68_AND_69 33899648u
// Read Parameter 70 and 71: Read parameter 70 and 71 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_70_AND_71 33899712u
// Read Parameter 72 and 73: Read parameter 72 and 73 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_72_AND_73 33899776u
// Read Parameter 74 and 75: Read parameter 74 and 75 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_74_AND_75 33899840u
// Read Parameter 76 and 77: Read parameter 76 and 77 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_76_AND_77 33899904u
// Read Parameter 78 and 79: Read parameter 78 and 79 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_78_AND_79 33899968u
// Read Parameter 80 and 81: Read parameter 80 and 81 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_80_AND_81 33900032u
// Read Parameter 82 and 83: Read parameter 82 and 83 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_82_AND_83 33900096u
// Read Parameter 84 and 85: Read parameter 84 and 85 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_84_AND_85 33900160u
// Read Parameter 86 and 87: Read parameter 86 and 87 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_86_AND_87 33900224u
// Read Parameter 88 and 89: Read parameter 88 and 89 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_88_AND_89 33900288u
// Read Parameter 90 and 91: Read parameter 90 and 91 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_90_AND_91 33900352u
// Read Parameter 92 and 93: Read parameter 92 and 93 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_92_AND_93 33900416u
// Read Parameter 94 and 95: Read parameter 94 and 95 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_94_AND_95 33900480u
// Read Parameter 96 and 97: Read parameter 96 and 97 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_96_AND_97 33900544u
// Read Parameter 98 and 99: Read parameter 98 and 99 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_98_AND_99 33900608u
// Read Parameter 100 and 101: Read parameter 100 and 101 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_100_AND_101 33900672u
// Read Parameter 102 and 103: Read parameter 102 and 103 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_102_AND_103 33900736u
// Read Parameter 104 and 105: Read parameter 104 and 105 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_104_AND_105 33900800u
// Read Parameter 106 and 107: Read parameter 106 and 107 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_106_AND_107 33900864u
// Read Parameter 108 and 109: Read parameter 108 and 109 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_108_AND_109 33900928u
// Read Parameter 110 and 111: Read parameter 110 and 111 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_110_AND_111 33900992u
// Read Parameter 112 and 113: Read parameter 112 and 113 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_112_AND_113 33901056u
// Read Parameter 114 and 115: Read parameter 114 and 115 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_114_AND_115 33901120u
// Read Parameter 116 and 117: Read parameter 116 and 117 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_116_AND_117 33901184u
// Read Parameter 118 and 119: Read parameter 118 and 119 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_118_AND_119 33901248u
// Read Parameter 120 and 121: Read parameter 120 and 121 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_120_AND_121 33901312u
// Read Parameter 122 and 123: Read parameter 122 and 123 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_122_AND_123 33901376u
// Read Parameter 124 and 125: Read parameter 124 and 125 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_124_AND_125 33901440u
// Read Parameter 126 and 127: Read parameter 126 and 127 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_126_AND_127 33901504u
// Read Parameter 128 and 129: Read parameter 128 and 129 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_128_AND_129 33901568u
// Read Parameter 130 and 131: Read parameter 130 and 131 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_130_AND_131 33901632u
// Read Parameter 132 and 133: Read parameter 132 and 133 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_132_AND_133 33901696u
// Read Parameter 134 and 135: Read parameter 134 and 135 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_134_AND_135 33901760u
// Read Parameter 136 and 137: Read parameter 136 and 137 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_136_AND_137 33901824u
// Read Parameter 138 and 139: Read parameter 138 and 139 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_138_AND_139 33901888u
// Read Parameter 140 and 141: Read parameter 140 and 141 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_140_AND_141 33901952u
// Read Parameter 142 and 143: Read parameter 142 and 143 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_142_AND_143 33902016u
// Read Parameter 144 and 145: Read parameter 144 and 145 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_144_AND_145 33902080u
// Read Parameter 146 and 147: Read parameter 146 and 147 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_146_AND_147 33902144u
// Read Parameter 148 and 149: Read parameter 148 and 149 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_148_AND_149 33902208u
// Read Parameter 150 and 151: Read parameter 150 and 151 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_150_AND_151 33902272u
// Read Parameter 152 and 153: Read parameter 152 and 153 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_152_AND_153 33902336u
// Read Parameter 154 and 155: Read parameter 154 and 155 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_154_AND_155 33902400u
// Read Parameter 156 and 157: Read parameter 156 and 157 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_156_AND_157 33902464u
// Read Parameter 158 and 159: Read parameter 158 and 159 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_158_AND_159 33902528u
// Read Parameter 160 and 161: Read parameter 160 and 161 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_160_AND_161 33902592u
// Read Parameter 162 and 163: Read parameter 162 and 163 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_162_AND_163 33902656u
// Read Parameter 164 and 165: Read parameter 164 and 165 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_164_AND_165 33902720u
// Read Parameter 166 and 167: Read parameter 166 and 167 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_166_AND_167 33902784u
// Read Parameter 168 and 169: Read parameter 168 and 169 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_168_AND_169 33902848u
// Read Parameter 170 and 171: Read parameter 170 and 171 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_170_AND_171 33902912u
// Read Parameter 172 and 173: Read parameter 172 and 173 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_172_AND_173 33902976u
// Read Parameter 174 and 175: Read parameter 174 and 175 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_174_AND_175 33903040u
// Read Parameter 176 and 177: Read parameter 176 and 177 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_176_AND_177 33903104u
// Read Parameter 178 and 179: Read parameter 178 and 179 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_178_AND_179 33903168u
// Read Parameter 180 and 181: Read parameter 180 and 181 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_180_AND_181 33903232u
// Read Parameter 182 and 183: Read parameter 182 and 183 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_182_AND_183 33903296u
// Read Parameter 184 and 185: Read parameter 184 and 185 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_184_AND_185 33903360u
// Read Parameter 186 and 187: Read parameter 186 and 187 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_186_AND_187 33903424u
// Read Parameter 188 and 189: Read parameter 188 and 189 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_188_AND_189 33903488u
// Read Parameter 190 and 191: Read parameter 190 and 191 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_190_AND_191 33903552u
// Read Parameter 192 and 193: Read parameter 192 and 193 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_192_AND_193 33903616u
// Read Parameter 194 and 195: Read parameter 194 and 195 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_194_AND_195 33903680u
// Read Parameter 196 and 197: Read parameter 196 and 197 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_196_AND_197 33903744u
// Read Parameter 198 and 199: Read parameter 198 and 199 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_198_AND_199 33903808u
// Read Parameter 200 and 201: Read parameter 200 and 201 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_200_AND_201 33903872u
// Read Parameter 202 and 203: Read parameter 202 and 203 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_202_AND_203 33903936u
// Read Parameter 204 and 205: Read parameter 204 and 205 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_204_AND_205 33904000u
// Read Parameter 206 and 207: Read parameter 206 and 207 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_206_AND_207 33904064u
// Read Parameter 208 and 209: Read parameter 208 and 209 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_208_AND_209 33904128u
// Read Parameter 210 and 211: Read parameter 210 and 211 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_210_AND_211 33904192u
// Read Parameter 212 and 213: Read parameter 212 and 213 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_212_AND_213 33904256u
// Read Parameter 214 and 215: Read parameter 214 and 215 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_214_AND_215 33904320u
// Read Parameter 216 and 217: Read parameter 216 and 217 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_216_AND_217 33904384u
// Read Parameter 218 and 219: Read parameter 218 and 219 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_218_AND_219 33904448u
// Read Parameter 220 and 221: Read parameter 220 and 221 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_220_AND_221 33904512u
// Read Parameter 222 and 223: Read parameter 222 and 223 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_222_AND_223 33904576u
// Read Parameter 224 and 225: Read parameter 224 and 225 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_224_AND_225 33904640u
// Read Parameter 226 and 227: Read parameter 226 and 227 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_226_AND_227 33904704u
// Read Parameter 228 and 229: Read parameter 228 and 229 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_228_AND_229 33904768u
// Read Parameter 230 and 231: Read parameter 230 and 231 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_230_AND_231 33904832u
// Read Parameter 232 and 233: Read parameter 232 and 233 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_232_AND_233 33904896u
// Read Parameter 234 and 235: Read parameter 234 and 235 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_234_AND_235 33904960u
// Read Parameter 236 and 237: Read parameter 236 and 237 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_236_AND_237 33905024u
// Read Parameter 238 and 239: Read parameter 238 and 239 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_238_AND_239 33905088u
// Read Parameter 240 and 241: Read parameter 240 and 241 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_240_AND_241 33905152u
// Read Parameter 242 and 243: Read parameter 242 and 243 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_242_AND_243 33905216u
// Read Parameter 244 and 245: Read parameter 244 and 245 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_244_AND_245 33905280u
// Read Parameter 246 and 247: Read parameter 246 and 247 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_246_AND_247 33905344u
// Read Parameter 248 and 249: Read parameter 248 and 249 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_248_AND_249 33905408u
// Read Parameter 250 and 251: Read parameter 250 and 251 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_250_AND_251 33905472u
// Read Parameter 252 and 253: Read parameter 252 and 253 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_252_AND_253 33905536u
// Read Parameter 254 and 255: Read parameter 254 and 255 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_ARB_READ_PARAMETER_254_AND_255 33905600u
// Write Parameter 0 and 1: Write Parameter 0 and 1 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_0_AND_1 33905664u
// Write Parameter 2 and 3: Write Parameter 2 and 3 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_2_AND_3 33905728u
// Write Parameter 4 and 5: Write Parameter 4 and 5 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_4_AND_5 33905792u
// Write Parameter 6 and 7: Write Parameter 6 and 7 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_6_AND_7 33905856u
// Write Parameter 8 and 9: Write Parameter 8 and 9 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_8_AND_9 33905920u
// Write Parameter 10 and 11: Write Parameter 10 and 11 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_10_AND_11 33905984u
// Write Parameter 12 and 13: Write Parameter 12 and 13 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_12_AND_13 33906048u
// Write Parameter 14 and 15: Write Parameter 14 and 15 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_14_AND_15 33906112u
// Write Parameter 16 and 17: Write Parameter 16 and 17 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_16_AND_17 33906176u
// Write Parameter 18 and 19: Write Parameter 18 and 19 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_18_AND_19 33906240u
// Write Parameter 20 and 21: Write Parameter 20 and 21 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_20_AND_21 33906304u
// Write Parameter 22 and 23: Write Parameter 22 and 23 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_22_AND_23 33906368u
// Write Parameter 24 and 25: Write Parameter 24 and 25 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_24_AND_25 33906432u
// Write Parameter 26 and 27: Write Parameter 26 and 27 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_26_AND_27 33906496u
// Write Parameter 28 and 29: Write Parameter 28 and 29 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_28_AND_29 33906560u
// Write Parameter 30 and 31: Write Parameter 30 and 31 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_30_AND_31 33906624u
// Write Parameter 32 and 33: Write Parameter 32 and 33 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_32_AND_33 33906688u
// Write Parameter 34 and 35: Write Parameter 34 and 35 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_34_AND_35 33906752u
// Write Parameter 36 and 37: Write Parameter 36 and 37 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_36_AND_37 33906816u
// Write Parameter 38 and 39: Write Parameter 38 and 39 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_38_AND_39 33906880u
// Write Parameter 40 and 41: Write Parameter 40 and 41 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_40_AND_41 33906944u
// Write Parameter 42 and 43: Write Parameter 42 and 43 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_42_AND_43 33907008u
// Write Parameter 44 and 45: Write Parameter 44 and 45 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_44_AND_45 33907072u
// Write Parameter 46 and 47: Write Parameter 46 and 47 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_46_AND_47 33907136u
// Write Parameter 48 and 49: Write Parameter 48 and 49 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_48_AND_49 33907200u
// Write Parameter 50 and 51: Write Parameter 50 and 51 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_50_AND_51 33907264u
// Write Parameter 52 and 53: Write Parameter 52 and 53 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_52_AND_53 33907328u
// Write Parameter 54 and 55: Write Parameter 54 and 55 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_54_AND_55 33907392u
// Write Parameter 56 and 57: Write Parameter 56 and 57 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_56_AND_57 33907456u
// Write Parameter 58 and 59: Write Parameter 58 and 59 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_58_AND_59 33907520u
// Write Parameter 60 and 61: Write Parameter 60 and 61 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_60_AND_61 33907584u
// Write Parameter 62 and 63: Write Parameter 62 and 63 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_62_AND_63 33907648u
// Write Parameter 64 and 65: Write Parameter 64 and 65 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_64_AND_65 33907712u
// Write Parameter 66 and 67: Write Parameter 66 and 67 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_66_AND_67 33907776u
// Write Parameter 68 and 69: Write Parameter 68 and 69 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_68_AND_69 33907840u
// Write Parameter 70 and 71: Write Parameter 70 and 71 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_70_AND_71 33907904u
// Write Parameter 72 and 73: Write Parameter 72 and 73 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_72_AND_73 33907968u
// Write Parameter 74 and 75: Write Parameter 74 and 75 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_74_AND_75 33908032u
// Write Parameter 76 and 77: Write Parameter 76 and 77 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_76_AND_77 33908096u
// Write Parameter 78 and 79: Write Parameter 78 and 79 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_78_AND_79 33908160u
// Write Parameter 80 and 81: Write Parameter 80 and 81 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_80_AND_81 33908224u
// Write Parameter 82 and 83: Write Parameter 82 and 83 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_82_AND_83 33908288u
// Write Parameter 84 and 85: Write Parameter 84 and 85 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_84_AND_85 33908352u
// Write Parameter 86 and 87: Write Parameter 86 and 87 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_86_AND_87 33908416u
// Write Parameter 88 and 89: Write Parameter 88 and 89 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_88_AND_89 33908480u
// Write Parameter 90 and 91: Write Parameter 90 and 91 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_90_AND_91 33908544u
// Write Parameter 92 and 93: Write Parameter 92 and 93 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_92_AND_93 33908608u
// Write Parameter 94 and 95: Write Parameter 94 and 95 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_94_AND_95 33908672u
// Write Parameter 96 and 97: Write Parameter 96 and 97 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_96_AND_97 33908736u
// Write Parameter 98 and 99: Write Parameter 98 and 99 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_98_AND_99 33908800u
// Write Parameter 100 and 101: Write Parameter 100 and 101 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_100_AND_101 33908864u
// Write Parameter 102 and 103: Write Parameter 102 and 103 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_102_AND_103 33908928u
// Write Parameter 104 and 105: Write Parameter 104 and 105 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_104_AND_105 33908992u
// Write Parameter 106 and 107: Write Parameter 106 and 107 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_106_AND_107 33909056u
// Write Parameter 108 and 109: Write Parameter 108 and 109 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_108_AND_109 33909120u
// Write Parameter 110 and 111: Write Parameter 110 and 111 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_110_AND_111 33909184u
// Write Parameter 112 and 113: Write Parameter 112 and 113 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_112_AND_113 33909248u
// Write Parameter 114 and 115: Write Parameter 114 and 115 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_114_AND_115 33909312u
// Write Parameter 116 and 117: Write Parameter 116 and 117 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_116_AND_117 33909376u
// Write Parameter 118 and 119: Write Parameter 118 and 119 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_118_AND_119 33909440u
// Write Parameter 120 and 121: Write Parameter 120 and 121 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_120_AND_121 33909504u
// Write Parameter 122 and 123: Write Parameter 122 and 123 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_122_AND_123 33909568u
// Write Parameter 124 and 125: Write Parameter 124 and 125 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_124_AND_125 33909632u
// Write Parameter 126 and 127: Write Parameter 126 and 127 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_126_AND_127 33909696u
// Write Parameter 128 and 129: Write Parameter 128 and 129 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_128_AND_129 33909760u
// Write Parameter 130 and 131: Write Parameter 130 and 131 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_130_AND_131 33909824u
// Write Parameter 132 and 133: Write Parameter 132 and 133 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_132_AND_133 33909888u
// Write Parameter 134 and 135: Write Parameter 134 and 135 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_134_AND_135 33909952u
// Write Parameter 136 and 137: Write Parameter 136 and 137 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_136_AND_137 33910016u
// Write Parameter 138 and 139: Write Parameter 138 and 139 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_138_AND_139 33910080u
// Write Parameter 140 and 141: Write Parameter 140 and 141 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_140_AND_141 33910144u
// Write Parameter 142 and 143: Write Parameter 142 and 143 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_142_AND_143 33910208u
// Write Parameter 144 and 145: Write Parameter 144 and 145 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_144_AND_145 33910272u
// Write Parameter 146 and 147: Write Parameter 146 and 147 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_146_AND_147 33910336u
// Write Parameter 148 and 149: Write Parameter 148 and 149 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_148_AND_149 33910400u
// Write Parameter 150 and 151: Write Parameter 150 and 151 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_150_AND_151 33910464u
// Write Parameter 152 and 153: Write Parameter 152 and 153 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_152_AND_153 33910528u
// Write Parameter 154 and 155: Write Parameter 154 and 155 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_154_AND_155 33910592u
// Write Parameter 156 and 157: Write Parameter 156 and 157 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_156_AND_157 33910656u
// Write Parameter 158 and 159: Write Parameter 158 and 159 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_158_AND_159 33910720u
// Write Parameter 160 and 161: Write Parameter 160 and 161 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_160_AND_161 33910784u
// Write Parameter 162 and 163: Write Parameter 162 and 163 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_162_AND_163 33910848u
// Write Parameter 164 and 165: Write Parameter 164 and 165 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_164_AND_165 33910912u
// Write Parameter 166 and 167: Write Parameter 166 and 167 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_166_AND_167 33910976u
// Write Parameter 168 and 169: Write Parameter 168 and 169 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_168_AND_169 33911040u
// Write Parameter 170 and 171: Write Parameter 170 and 171 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_170_AND_171 33911104u
// Write Parameter 172 and 173: Write Parameter 172 and 173 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_172_AND_173 33911168u
// Write Parameter 174 and 175: Write Parameter 174 and 175 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_174_AND_175 33911232u
// Write Parameter 176 and 177: Write Parameter 176 and 177 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_176_AND_177 33911296u
// Write Parameter 178 and 179: Write Parameter 178 and 179 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_178_AND_179 33911360u
// Write Parameter 180 and 181: Write Parameter 180 and 181 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_180_AND_181 33911424u
// Write Parameter 182 and 183: Write Parameter 182 and 183 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_182_AND_183 33911488u
// Write Parameter 184 and 185: Write Parameter 184 and 185 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_184_AND_185 33911552u
// Write Parameter 186 and 187: Write Parameter 186 and 187 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_186_AND_187 33911616u
// Write Parameter 188 and 189: Write Parameter 188 and 189 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_188_AND_189 33911680u
// Write Parameter 190 and 191: Write Parameter 190 and 191 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_190_AND_191 33911744u
// Write Parameter 192 and 193: Write Parameter 192 and 193 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_192_AND_193 33911808u
// Write Parameter 194 and 195: Write Parameter 194 and 195 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_194_AND_195 33911872u
// Write Parameter 196 and 197: Write Parameter 196 and 197 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_196_AND_197 33911936u
// Write Parameter 198 and 199: Write Parameter 198 and 199 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_198_AND_199 33912000u
// Write Parameter 200 and 201: Write Parameter 200 and 201 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_200_AND_201 33912064u
// Write Parameter 202 and 203: Write Parameter 202 and 203 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_202_AND_203 33912128u
// Write Parameter 204 and 205: Write Parameter 204 and 205 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_204_AND_205 33912192u
// Write Parameter 206 and 207: Write Parameter 206 and 207 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_206_AND_207 33912256u
// Write Parameter 208 and 209: Write Parameter 208 and 209 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_208_AND_209 33912320u
// Write Parameter 210 and 211: Write Parameter 210 and 211 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_210_AND_211 33912384u
// Write Parameter 212 and 213: Write Parameter 212 and 213 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_212_AND_213 33912448u
// Write Parameter 214 and 215: Write Parameter 214 and 215 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_214_AND_215 33912512u
// Write Parameter 216 and 217: Write Parameter 216 and 217 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_216_AND_217 33912576u
// Write Parameter 218 and 219: Write Parameter 218 and 219 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_218_AND_219 33912640u
// Write Parameter 220 and 221: Write Parameter 220 and 221 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_220_AND_221 33912704u
// Write Parameter 222 and 223: Write Parameter 222 and 223 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_222_AND_223 33912768u
// Write Parameter 224 and 225: Write Parameter 224 and 225 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_224_AND_225 33912832u
// Write Parameter 226 and 227: Write Parameter 226 and 227 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_226_AND_227 33912896u
// Write Parameter 228 and 229: Write Parameter 228 and 229 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_228_AND_229 33912960u
// Write Parameter 230 and 231: Write Parameter 230 and 231 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_230_AND_231 33913024u
// Write Parameter 232 and 233: Write Parameter 232 and 233 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_232_AND_233 33913088u
// Write Parameter 234 and 235: Write Parameter 234 and 235 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_234_AND_235 33913152u
// Write Parameter 236 and 237: Write Parameter 236 and 237 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_236_AND_237 33913216u
// Write Parameter 238 and 239: Write Parameter 238 and 239 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_238_AND_239 33913280u
// Write Parameter 240 and 241: Write Parameter 240 and 241 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_240_AND_241 33913344u
// Write Parameter 242 and 243: Write Parameter 242 and 243 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_242_AND_243 33913408u
// Write Parameter 244 and 245: Write Parameter 244 and 245 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_244_AND_245 33913472u
// Write Parameter 246 and 247: Write Parameter 246 and 247 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_246_AND_247 33913536u
// Write Parameter 248 and 249: Write Parameter 248 and 249 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_248_AND_249 33913600u
// Write Parameter 250 and 251: Write Parameter 250 and 251 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_250_AND_251 33913664u
// Write Parameter 252 and 253: Write Parameter 252 and 253 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_252_AND_253 33913728u
// Write Parameter 254 and 255: Write Parameter 254 and 255 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_ARB_WRITE_PARAMETER_254_AND_255 33913792u
// Start Follower Mode: Starts follower mode. The relevant parameters must already be configured. In response, a Start Follower Mode Response frame will be sent. Follower mode will be auto-started on boot if the Follower Mode Leader ID parameter is set to a non-zero value.
#define SPARK_ARB_START_FOLLOWER_MODE 33913856u
// Start Follower Mode Response: Response for a Start Follower Mode command
#define SPARK_ARB_START_FOLLOWER_MODE_RESPONSE 33913920u
// Stop Follower Mode: Exits follower mode and causes the device to resume listening for setpoints addressed directly to it. In response, a Stop Follower Mode Response frame will be sent.
#define SPARK_ARB_STOP_FOLLOWER_MODE 33913984u
// Stop Follower Mode Response: Response for a Stop Follower Mode Command
#define SPARK_ARB_STOP_FOLLOWER_MODE_RESPONSE 33914048u
// Enter SWDL CAN Bootloader
#define SPARK_ARB_ENTER_SWDL_CAN_BOOTLOADER 33914816u
// Persist Parameters: Causes all parameters to be written to non-volatile storage. After the operation (which may take up to a second) completes, a Persist Parameters Response frame will be sent.
#define SPARK_ARB_PERSIST_PARAMETERS 33947584u

// Match arbitration ID for frame Legacy Status 0: This frame exists purely to inform old software that is not aware of firmware version 25+ that the SPARK is present
#define SPARK_MATCH_LEGACY_STATUS_0(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_LEGACY_STATUS_0)
// Match arbitration ID for frame Bootloader 0: Periodic frame when device is in the bootloader
#define SPARK_MATCH_BOOTLOADER_0(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_BOOTLOADER_0)
// Match arbitration ID for frame Status 0: Includes general data that is likely to need frequent refreshing
#define SPARK_MATCH_STATUS_0(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_STATUS_0)
// Match arbitration ID for frame Status 1: Includes general data that can likely tolerate infrequent refreshing
#define SPARK_MATCH_STATUS_1(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_STATUS_1)
// Match arbitration ID for frame Status 2: Includes data from the primary encoder (either a brushless motor's internal encoder, or the primary encoder associated with a brushed motor)
#define SPARK_MATCH_STATUS_2(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_STATUS_2)
// Match arbitration ID for frame Status 3: Includes data from an analog sensor
#define SPARK_MATCH_STATUS_3(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_STATUS_3)
// Match arbitration ID for frame Status 4: Includes data from the External Encoder (on SPARK MAX, this is the Alternate Encoder)
#define SPARK_MATCH_STATUS_4(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_STATUS_4)
// Match arbitration ID for frame Status 5: Includes velocity and position data from a duty-cycle absolute encoder
#define SPARK_MATCH_STATUS_5(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_STATUS_5)
// Match arbitration ID for frame Status 6: Includes other data from a duty-cycle absolute encoder
#define SPARK_MATCH_STATUS_6(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_STATUS_6)
// Match arbitration ID for frame Status 7: Includes diagnostic data for closed-loop control
#define SPARK_MATCH_STATUS_7(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_STATUS_7)
// Match arbitration ID for frame Status 8: Includes additional diagnostic data for closed-loop control
#define SPARK_MATCH_STATUS_8(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_STATUS_8)
// Match arbitration ID for frame Status 9: Includes diagnostic data for MAXMotion closed-loop control
#define SPARK_MATCH_STATUS_9(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_STATUS_9)
// Match arbitration ID for frame Unique ID Broadcast: Contains the unique ID of the device, to allow detecting duplicate CAN IDs. To avoid collisions, the SPARK Flex firmware will send this at an irregular period between 1000ms and 2000ms. SPARK MAX may use a constant period of 1000ms.
#define SPARK_MATCH_UNIQUE_ID_BROADCAST(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_UNIQUE_ID_BROADCAST)
// Match arbitration ID for frame Velocity Setpoint: Sets the Control Type to Velocity and sets the target velocity
#define SPARK_MATCH_VELOCITY_SETPOINT(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_VELOCITY_SETPOINT)
// Match arbitration ID for frame Duty Cycle Setpoint: Sets the Control Type to Duty Cycle and sets the target duty cycle (from -1 to 1)
#define SPARK_MATCH_DUTY_CYCLE_SETPOINT(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_DUTY_CYCLE_SETPOINT)
// Match arbitration ID for frame Position Setpoint: Sets the Control Type to Position and sets the target position
#define SPARK_MATCH_POSITION_SETPOINT(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_POSITION_SETPOINT)
// Match arbitration ID for frame Voltage Setpoint: Sets the Control Type to Voltage and sets the target voltage
#define SPARK_MATCH_VOLTAGE_SETPOINT(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_VOLTAGE_SETPOINT)
// Match arbitration ID for frame Current Setpoint: Sets the Control Type to Current and sets the target current
#define SPARK_MATCH_CURRENT_SETPOINT(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_CURRENT_SETPOINT)
// Match arbitration ID for frame MAXMotion Position Setpoint: Sets the Control Type to MAXMotion Position Control and sets the target position
#define SPARK_MATCH_MAXMOTION_POSITION_SETPOINT(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_MAXMOTION_POSITION_SETPOINT)
// Match arbitration ID for frame MAXMotion Velocity Setpoint: Sets the Control Type to MAXMotion Velocity Control and sets the target velocity
#define SPARK_MATCH_MAXMOTION_VELOCITY_SETPOINT(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_MAXMOTION_VELOCITY_SETPOINT)
// Match arbitration ID for frame Set Statuses Enabled: Enable or disable status frames. In response, a Set Statuses Enabled Response frame will be sent.
#define SPARK_MATCH_SET_STATUSES_ENABLED(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_SET_STATUSES_ENABLED)
// Match arbitration ID for frame Set Statuses Enabled Response: Response for a Set Statuses Enabled command
#define SPARK_MATCH_SET_STATUSES_ENABLED_RESPONSE(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_SET_STATUSES_ENABLED_RESPONSE)
// Match arbitration ID for frame Persist Parameters Response
#define SPARK_MATCH_PERSIST_PARAMETERS_RESPONSE(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_PERSIST_PARAMETERS_RESPONSE)
// Match arbitration ID for frame Reset Safe Parameters: Resets most writable parameters to their default values, except CAN ID, Motor Type, Idle Mode, PWM Input Deadband, and Duty Cycle Offset. In response, a Reset Safe Parameters Response frame is sent.
#define SPARK_MATCH_RESET_SAFE_PARAMETERS(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_RESET_SAFE_PARAMETERS)
// Match arbitration ID for frame Reset Safe Parameters Response: Response for a Reset Safe Parameters command
#define SPARK_MATCH_RESET_SAFE_PARAMETERS_RESPONSE(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_RESET_SAFE_PARAMETERS_RESPONSE)
// Match arbitration ID for frame Complete Factory Reset: Resets all writable parameters to default values, even CAN ID, Motor Type, Idle Mode, PWM Input Deadband, and Duty Cycle Offset. In response, a Complete Factory Reset Response frame is sent.
#define SPARK_MATCH_COMPLETE_FACTORY_RESET(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_COMPLETE_FACTORY_RESET)
// Match arbitration ID for frame Complete Factory Reset Response: Response for a Complete Factory Reset command
#define SPARK_MATCH_COMPLETE_FACTORY_RESET_RESPONSE(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_COMPLETE_FACTORY_RESET_RESPONSE)
// Match arbitration ID for frame Clear Faults
#define SPARK_MATCH_CLEAR_FAULTS(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_CLEAR_FAULTS)
// Match arbitration ID for frame Identify Unique SPARK: Makes the specified, single SPARK (even if there are multiple SPARKs that have the same CAN ID) temporarily perform a special blink pattern that will make it stand out
#define SPARK_MATCH_IDENTIFY_UNIQUE_SPARK(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_IDENTIFY_UNIQUE_SPARK)
// Match arbitration ID for frame Identify: Makes the SPARK temporarily perform a special blink pattern that will make it stand out. Use Identify Unique Device if there may be multiple SPARKs with the same CAN ID.
#define SPARK_MATCH_IDENTIFY(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_IDENTIFY)
// Match arbitration ID for frame Nack: As of SPARK MAX firmware 1.6.3, this is only used as a potential response to setting the CAN ID
#define SPARK_MATCH_NACK(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_NACK)
// Match arbitration ID for frame Ack: As of SPARK MAX firmware 1.6.3, this is only used as a potential response to setting the CAN ID
#define SPARK_MATCH_ACK(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_ACK)
// Match arbitration ID for frame LED Sync: Causes all SPARKs on the bus to synchronize their LED patterns
#define SPARK_MATCH_LED_SYNC(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_LED_SYNC)
// Match arbitration ID for frame Set CAN ID: Allows changing the CAN ID when multiple devices on the bus currently have the same CAN ID. Under normal circumstances, the CAN ID parameter can be used.
#define SPARK_MATCH_SET_CAN_ID(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_SET_CAN_ID)
// Match arbitration ID for frame Get Firmware Version
#define SPARK_MATCH_GET_FIRMWARE_VERSION(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_GET_FIRMWARE_VERSION)
// Match arbitration ID for frame SWDL Data: Broadcast from the host to all SPARKs in SWDL mode, containing a slice of firmware data
#define SPARK_MATCH_SWDL_DATA(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_SWDL_DATA)
// Match arbitration ID for frame SWDL Checksum: Broadcast from the host to all SPARKs in SWDL mode, containing the checksum of the full firmware image that was just sent
#define SPARK_MATCH_SWDL_CHECKSUM(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_SWDL_CHECKSUM)
// Match arbitration ID for frame SWDL Retransmit: Sent by SPARK devices in response to receiving an SWDL Checksum frame that does not match the firmware data they received
#define SPARK_MATCH_SWDL_RETRANSMIT(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_SWDL_RETRANSMIT)
// Match arbitration ID for frame Set Primary Encoder Position
#define SPARK_MATCH_SET_PRIMARY_ENCODER_POSITION(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_SET_PRIMARY_ENCODER_POSITION)
// Match arbitration ID for frame Set I Accumulation
#define SPARK_MATCH_SET_I_ACCUMULATION(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_SET_I_ACCUMULATION)
// Match arbitration ID for frame Set Analog Position
#define SPARK_MATCH_SET_ANALOG_POSITION(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_SET_ANALOG_POSITION)
// Match arbitration ID for frame Set Ext or Alt Encoder Position
#define SPARK_MATCH_SET_EXT_OR_ALT_ENCODER_POSITION(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_SET_EXT_OR_ALT_ENCODER_POSITION)
// Match arbitration ID for frame Set Duty Cycle Position
#define SPARK_MATCH_SET_DUTY_CYCLE_POSITION(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_SET_DUTY_CYCLE_POSITION)
// Match arbitration ID for frame Secondary Heartbeat: Heartbeat that allows enabling only specific SPARKs, but only gets respected when the SPARK is not locked to the Universal Heartbeat or Primary Heartbeat
#define SPARK_MATCH_SECONDARY_HEARTBEAT(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_SECONDARY_HEARTBEAT)
// Match arbitration ID for frame USB Only Identify: The response will only be sent if this command is received directly via USB. This has no relation to the normal Identify command, which displays an LED pattern.
#define SPARK_MATCH_USB_ONLY_IDENTIFY(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_USB_ONLY_IDENTIFY)
// Match arbitration ID for frame USB Only Enter DFU Bootloader: Causes the device to reboot into the DFU bootloader if this command is received directly via USB
#define SPARK_MATCH_USB_ONLY_ENTER_DFU_BOOTLOADER(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_USB_ONLY_ENTER_DFU_BOOTLOADER)
// Match arbitration ID for frame Get Temperatures
#define SPARK_MATCH_GET_TEMPERATURES(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_GET_TEMPERATURES)
// Match arbitration ID for frame Get Motor Interface
#define SPARK_MATCH_GET_MOTOR_INTERFACE(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_GET_MOTOR_INTERFACE)
// Match arbitration ID for frame Get Parameter 0 to 15 Types: Get types of parameters 0 to 15
#define SPARK_MATCH_GET_PARAMETER_0_TO_15_TYPES(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_GET_PARAMETER_0_TO_15_TYPES)
// Match arbitration ID for frame Get Parameter 16 to 31 Types: Get types of parameters 16 to 31
#define SPARK_MATCH_GET_PARAMETER_16_TO_31_TYPES(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_GET_PARAMETER_16_TO_31_TYPES)
// Match arbitration ID for frame Get Parameter 32 to 47 Types: Get types of parameters 32 to 47
#define SPARK_MATCH_GET_PARAMETER_32_TO_47_TYPES(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_GET_PARAMETER_32_TO_47_TYPES)
// Match arbitration ID for frame Get Parameter 48 to 63 Types: Get types of parameters 48 to 63
#define SPARK_MATCH_GET_PARAMETER_48_TO_63_TYPES(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_GET_PARAMETER_48_TO_63_TYPES)
// Match arbitration ID for frame Get Parameter 64 to 79 Types: Get types of parameters 64 to 79
#define SPARK_MATCH_GET_PARAMETER_64_TO_79_TYPES(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_GET_PARAMETER_64_TO_79_TYPES)
// Match arbitration ID for frame Get Parameter 80 to 95 Types: Get types of parameters 80 to 95
#define SPARK_MATCH_GET_PARAMETER_80_TO_95_TYPES(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_GET_PARAMETER_80_TO_95_TYPES)
// Match arbitration ID for frame Get Parameter 96 to 111 Types: Get types of parameters 96 to 111
#define SPARK_MATCH_GET_PARAMETER_96_TO_111_TYPES(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_GET_PARAMETER_96_TO_111_TYPES)
// Match arbitration ID for frame Get Parameter 112 to 127 Types: Get types of parameters 112 to 127
#define SPARK_MATCH_GET_PARAMETER_112_TO_127_TYPES(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_GET_PARAMETER_112_TO_127_TYPES)
// Match arbitration ID for frame Get Parameter 128 to 143 Types: Get types of parameters 128 to 143
#define SPARK_MATCH_GET_PARAMETER_128_TO_143_TYPES(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_GET_PARAMETER_128_TO_143_TYPES)
// Match arbitration ID for frame Get Parameter 144 to 159 Types: Get types of parameters 144 to 159
#define SPARK_MATCH_GET_PARAMETER_144_TO_159_TYPES(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_GET_PARAMETER_144_TO_159_TYPES)
// Match arbitration ID for frame Get Parameter 160 to 175 Types: Get types of parameters 160 to 175
#define SPARK_MATCH_GET_PARAMETER_160_TO_175_TYPES(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_GET_PARAMETER_160_TO_175_TYPES)
// Match arbitration ID for frame Get Parameter 176 to 191 Types: Get types of parameters 176 to 191
#define SPARK_MATCH_GET_PARAMETER_176_TO_191_TYPES(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_GET_PARAMETER_176_TO_191_TYPES)
// Match arbitration ID for frame Get Parameter 192 to 207 Types: Get types of parameters 192 to 207
#define SPARK_MATCH_GET_PARAMETER_192_TO_207_TYPES(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_GET_PARAMETER_192_TO_207_TYPES)
// Match arbitration ID for frame Get Parameter 208 to 223 Types: Get types of parameters 208 to 223
#define SPARK_MATCH_GET_PARAMETER_208_TO_223_TYPES(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_GET_PARAMETER_208_TO_223_TYPES)
// Match arbitration ID for frame Get Parameter 224 to 239 Types: Get types of parameters 224 to 239
#define SPARK_MATCH_GET_PARAMETER_224_TO_239_TYPES(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_GET_PARAMETER_224_TO_239_TYPES)
// Match arbitration ID for frame Get Parameter 240 to 255 Types: Get types of parameters 240 to 255
#define SPARK_MATCH_GET_PARAMETER_240_TO_255_TYPES(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_GET_PARAMETER_240_TO_255_TYPES)
// Match arbitration ID for frame Parameter Write: Write a single parameter value. In response, a Parameter Write Response frame will be sent.
#define SPARK_MATCH_PARAMETER_WRITE(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_PARAMETER_WRITE)
// Match arbitration ID for frame Parameter Write Response: Response for a parameter write (including a write done as part of a dual-write)
#define SPARK_MATCH_PARAMETER_WRITE_RESPONSE(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_PARAMETER_WRITE_RESPONSE)
// Match arbitration ID for frame Read Parameter 0 and 1: Read parameter 0 and 1 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_0_AND_1(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_0_AND_1)
// Match arbitration ID for frame Read Parameter 2 and 3: Read parameter 2 and 3 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_2_AND_3(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_2_AND_3)
// Match arbitration ID for frame Read Parameter 4 and 5: Read parameter 4 and 5 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_4_AND_5(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_4_AND_5)
// Match arbitration ID for frame Read Parameter 6 and 7: Read parameter 6 and 7 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_6_AND_7(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_6_AND_7)
// Match arbitration ID for frame Read Parameter 8 and 9: Read parameter 8 and 9 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_8_AND_9(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_8_AND_9)
// Match arbitration ID for frame Read Parameter 10 and 11: Read parameter 10 and 11 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_10_AND_11(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_10_AND_11)
// Match arbitration ID for frame Read Parameter 12 and 13: Read parameter 12 and 13 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_12_AND_13(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_12_AND_13)
// Match arbitration ID for frame Read Parameter 14 and 15: Read parameter 14 and 15 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_14_AND_15(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_14_AND_15)
// Match arbitration ID for frame Read Parameter 16 and 17: Read parameter 16 and 17 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_16_AND_17(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_16_AND_17)
// Match arbitration ID for frame Read Parameter 18 and 19: Read parameter 18 and 19 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_18_AND_19(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_18_AND_19)
// Match arbitration ID for frame Read Parameter 20 and 21: Read parameter 20 and 21 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_20_AND_21(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_20_AND_21)
// Match arbitration ID for frame Read Parameter 22 and 23: Read parameter 22 and 23 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_22_AND_23(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_22_AND_23)
// Match arbitration ID for frame Read Parameter 24 and 25: Read parameter 24 and 25 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_24_AND_25(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_24_AND_25)
// Match arbitration ID for frame Read Parameter 26 and 27: Read parameter 26 and 27 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_26_AND_27(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_26_AND_27)
// Match arbitration ID for frame Read Parameter 28 and 29: Read parameter 28 and 29 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_28_AND_29(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_28_AND_29)
// Match arbitration ID for frame Read Parameter 30 and 31: Read parameter 30 and 31 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_30_AND_31(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_30_AND_31)
// Match arbitration ID for frame Read Parameter 32 and 33: Read parameter 32 and 33 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_32_AND_33(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_32_AND_33)
// Match arbitration ID for frame Read Parameter 34 and 35: Read parameter 34 and 35 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_34_AND_35(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_34_AND_35)
// Match arbitration ID for frame Read Parameter 36 and 37: Read parameter 36 and 37 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_36_AND_37(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_36_AND_37)
// Match arbitration ID for frame Read Parameter 38 and 39: Read parameter 38 and 39 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_38_AND_39(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_38_AND_39)
// Match arbitration ID for frame Read Parameter 40 and 41: Read parameter 40 and 41 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_40_AND_41(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_40_AND_41)
// Match arbitration ID for frame Read Parameter 42 and 43: Read parameter 42 and 43 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_42_AND_43(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_42_AND_43)
// Match arbitration ID for frame Read Parameter 44 and 45: Read parameter 44 and 45 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_44_AND_45(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_44_AND_45)
// Match arbitration ID for frame Read Parameter 46 and 47: Read parameter 46 and 47 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_46_AND_47(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_46_AND_47)
// Match arbitration ID for frame Read Parameter 48 and 49: Read parameter 48 and 49 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_48_AND_49(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_48_AND_49)
// Match arbitration ID for frame Read Parameter 50 and 51: Read parameter 50 and 51 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_50_AND_51(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_50_AND_51)
// Match arbitration ID for frame Read Parameter 52 and 53: Read parameter 52 and 53 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_52_AND_53(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_52_AND_53)
// Match arbitration ID for frame Read Parameter 54 and 55: Read parameter 54 and 55 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_54_AND_55(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_54_AND_55)
// Match arbitration ID for frame Read Parameter 56 and 57: Read parameter 56 and 57 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_56_AND_57(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_56_AND_57)
// Match arbitration ID for frame Read Parameter 58 and 59: Read parameter 58 and 59 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_58_AND_59(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_58_AND_59)
// Match arbitration ID for frame Read Parameter 60 and 61: Read parameter 60 and 61 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_60_AND_61(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_60_AND_61)
// Match arbitration ID for frame Read Parameter 62 and 63: Read parameter 62 and 63 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_62_AND_63(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_62_AND_63)
// Match arbitration ID for frame Read Parameter 64 and 65: Read parameter 64 and 65 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_64_AND_65(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_64_AND_65)
// Match arbitration ID for frame Read Parameter 66 and 67: Read parameter 66 and 67 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_66_AND_67(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_66_AND_67)
// Match arbitration ID for frame Read Parameter 68 and 69: Read parameter 68 and 69 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_68_AND_69(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_68_AND_69)
// Match arbitration ID for frame Read Parameter 70 and 71: Read parameter 70 and 71 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_70_AND_71(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_70_AND_71)
// Match arbitration ID for frame Read Parameter 72 and 73: Read parameter 72 and 73 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_72_AND_73(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_72_AND_73)
// Match arbitration ID for frame Read Parameter 74 and 75: Read parameter 74 and 75 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_74_AND_75(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_74_AND_75)
// Match arbitration ID for frame Read Parameter 76 and 77: Read parameter 76 and 77 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_76_AND_77(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_76_AND_77)
// Match arbitration ID for frame Read Parameter 78 and 79: Read parameter 78 and 79 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_78_AND_79(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_78_AND_79)
// Match arbitration ID for frame Read Parameter 80 and 81: Read parameter 80 and 81 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_80_AND_81(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_80_AND_81)
// Match arbitration ID for frame Read Parameter 82 and 83: Read parameter 82 and 83 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_82_AND_83(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_82_AND_83)
// Match arbitration ID for frame Read Parameter 84 and 85: Read parameter 84 and 85 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_84_AND_85(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_84_AND_85)
// Match arbitration ID for frame Read Parameter 86 and 87: Read parameter 86 and 87 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_86_AND_87(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_86_AND_87)
// Match arbitration ID for frame Read Parameter 88 and 89: Read parameter 88 and 89 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_88_AND_89(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_88_AND_89)
// Match arbitration ID for frame Read Parameter 90 and 91: Read parameter 90 and 91 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_90_AND_91(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_90_AND_91)
// Match arbitration ID for frame Read Parameter 92 and 93: Read parameter 92 and 93 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_92_AND_93(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_92_AND_93)
// Match arbitration ID for frame Read Parameter 94 and 95: Read parameter 94 and 95 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_94_AND_95(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_94_AND_95)
// Match arbitration ID for frame Read Parameter 96 and 97: Read parameter 96 and 97 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_96_AND_97(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_96_AND_97)
// Match arbitration ID for frame Read Parameter 98 and 99: Read parameter 98 and 99 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_98_AND_99(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_98_AND_99)
// Match arbitration ID for frame Read Parameter 100 and 101: Read parameter 100 and 101 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_100_AND_101(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_100_AND_101)
// Match arbitration ID for frame Read Parameter 102 and 103: Read parameter 102 and 103 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_102_AND_103(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_102_AND_103)
// Match arbitration ID for frame Read Parameter 104 and 105: Read parameter 104 and 105 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_104_AND_105(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_104_AND_105)
// Match arbitration ID for frame Read Parameter 106 and 107: Read parameter 106 and 107 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_106_AND_107(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_106_AND_107)
// Match arbitration ID for frame Read Parameter 108 and 109: Read parameter 108 and 109 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_108_AND_109(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_108_AND_109)
// Match arbitration ID for frame Read Parameter 110 and 111: Read parameter 110 and 111 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_110_AND_111(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_110_AND_111)
// Match arbitration ID for frame Read Parameter 112 and 113: Read parameter 112 and 113 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_112_AND_113(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_112_AND_113)
// Match arbitration ID for frame Read Parameter 114 and 115: Read parameter 114 and 115 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_114_AND_115(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_114_AND_115)
// Match arbitration ID for frame Read Parameter 116 and 117: Read parameter 116 and 117 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_116_AND_117(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_116_AND_117)
// Match arbitration ID for frame Read Parameter 118 and 119: Read parameter 118 and 119 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_118_AND_119(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_118_AND_119)
// Match arbitration ID for frame Read Parameter 120 and 121: Read parameter 120 and 121 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_120_AND_121(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_120_AND_121)
// Match arbitration ID for frame Read Parameter 122 and 123: Read parameter 122 and 123 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_122_AND_123(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_122_AND_123)
// Match arbitration ID for frame Read Parameter 124 and 125: Read parameter 124 and 125 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_124_AND_125(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_124_AND_125)
// Match arbitration ID for frame Read Parameter 126 and 127: Read parameter 126 and 127 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_126_AND_127(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_126_AND_127)
// Match arbitration ID for frame Read Parameter 128 and 129: Read parameter 128 and 129 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_128_AND_129(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_128_AND_129)
// Match arbitration ID for frame Read Parameter 130 and 131: Read parameter 130 and 131 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_130_AND_131(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_130_AND_131)
// Match arbitration ID for frame Read Parameter 132 and 133: Read parameter 132 and 133 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_132_AND_133(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_132_AND_133)
// Match arbitration ID for frame Read Parameter 134 and 135: Read parameter 134 and 135 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_134_AND_135(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_134_AND_135)
// Match arbitration ID for frame Read Parameter 136 and 137: Read parameter 136 and 137 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_136_AND_137(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_136_AND_137)
// Match arbitration ID for frame Read Parameter 138 and 139: Read parameter 138 and 139 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_138_AND_139(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_138_AND_139)
// Match arbitration ID for frame Read Parameter 140 and 141: Read parameter 140 and 141 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_140_AND_141(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_140_AND_141)
// Match arbitration ID for frame Read Parameter 142 and 143: Read parameter 142 and 143 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_142_AND_143(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_142_AND_143)
// Match arbitration ID for frame Read Parameter 144 and 145: Read parameter 144 and 145 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_144_AND_145(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_144_AND_145)
// Match arbitration ID for frame Read Parameter 146 and 147: Read parameter 146 and 147 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_146_AND_147(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_146_AND_147)
// Match arbitration ID for frame Read Parameter 148 and 149: Read parameter 148 and 149 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_148_AND_149(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_148_AND_149)
// Match arbitration ID for frame Read Parameter 150 and 151: Read parameter 150 and 151 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_150_AND_151(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_150_AND_151)
// Match arbitration ID for frame Read Parameter 152 and 153: Read parameter 152 and 153 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_152_AND_153(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_152_AND_153)
// Match arbitration ID for frame Read Parameter 154 and 155: Read parameter 154 and 155 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_154_AND_155(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_154_AND_155)
// Match arbitration ID for frame Read Parameter 156 and 157: Read parameter 156 and 157 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_156_AND_157(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_156_AND_157)
// Match arbitration ID for frame Read Parameter 158 and 159: Read parameter 158 and 159 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_158_AND_159(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_158_AND_159)
// Match arbitration ID for frame Read Parameter 160 and 161: Read parameter 160 and 161 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_160_AND_161(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_160_AND_161)
// Match arbitration ID for frame Read Parameter 162 and 163: Read parameter 162 and 163 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_162_AND_163(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_162_AND_163)
// Match arbitration ID for frame Read Parameter 164 and 165: Read parameter 164 and 165 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_164_AND_165(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_164_AND_165)
// Match arbitration ID for frame Read Parameter 166 and 167: Read parameter 166 and 167 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_166_AND_167(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_166_AND_167)
// Match arbitration ID for frame Read Parameter 168 and 169: Read parameter 168 and 169 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_168_AND_169(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_168_AND_169)
// Match arbitration ID for frame Read Parameter 170 and 171: Read parameter 170 and 171 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_170_AND_171(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_170_AND_171)
// Match arbitration ID for frame Read Parameter 172 and 173: Read parameter 172 and 173 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_172_AND_173(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_172_AND_173)
// Match arbitration ID for frame Read Parameter 174 and 175: Read parameter 174 and 175 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_174_AND_175(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_174_AND_175)
// Match arbitration ID for frame Read Parameter 176 and 177: Read parameter 176 and 177 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_176_AND_177(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_176_AND_177)
// Match arbitration ID for frame Read Parameter 178 and 179: Read parameter 178 and 179 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_178_AND_179(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_178_AND_179)
// Match arbitration ID for frame Read Parameter 180 and 181: Read parameter 180 and 181 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_180_AND_181(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_180_AND_181)
// Match arbitration ID for frame Read Parameter 182 and 183: Read parameter 182 and 183 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_182_AND_183(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_182_AND_183)
// Match arbitration ID for frame Read Parameter 184 and 185: Read parameter 184 and 185 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_184_AND_185(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_184_AND_185)
// Match arbitration ID for frame Read Parameter 186 and 187: Read parameter 186 and 187 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_186_AND_187(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_186_AND_187)
// Match arbitration ID for frame Read Parameter 188 and 189: Read parameter 188 and 189 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_188_AND_189(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_188_AND_189)
// Match arbitration ID for frame Read Parameter 190 and 191: Read parameter 190 and 191 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_190_AND_191(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_190_AND_191)
// Match arbitration ID for frame Read Parameter 192 and 193: Read parameter 192 and 193 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_192_AND_193(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_192_AND_193)
// Match arbitration ID for frame Read Parameter 194 and 195: Read parameter 194 and 195 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_194_AND_195(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_194_AND_195)
// Match arbitration ID for frame Read Parameter 196 and 197: Read parameter 196 and 197 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_196_AND_197(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_196_AND_197)
// Match arbitration ID for frame Read Parameter 198 and 199: Read parameter 198 and 199 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_198_AND_199(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_198_AND_199)
// Match arbitration ID for frame Read Parameter 200 and 201: Read parameter 200 and 201 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_200_AND_201(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_200_AND_201)
// Match arbitration ID for frame Read Parameter 202 and 203: Read parameter 202 and 203 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_202_AND_203(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_202_AND_203)
// Match arbitration ID for frame Read Parameter 204 and 205: Read parameter 204 and 205 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_204_AND_205(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_204_AND_205)
// Match arbitration ID for frame Read Parameter 206 and 207: Read parameter 206 and 207 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_206_AND_207(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_206_AND_207)
// Match arbitration ID for frame Read Parameter 208 and 209: Read parameter 208 and 209 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_208_AND_209(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_208_AND_209)
// Match arbitration ID for frame Read Parameter 210 and 211: Read parameter 210 and 211 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_210_AND_211(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_210_AND_211)
// Match arbitration ID for frame Read Parameter 212 and 213: Read parameter 212 and 213 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_212_AND_213(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_212_AND_213)
// Match arbitration ID for frame Read Parameter 214 and 215: Read parameter 214 and 215 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_214_AND_215(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_214_AND_215)
// Match arbitration ID for frame Read Parameter 216 and 217: Read parameter 216 and 217 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_216_AND_217(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_216_AND_217)
// Match arbitration ID for frame Read Parameter 218 and 219: Read parameter 218 and 219 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_218_AND_219(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_218_AND_219)
// Match arbitration ID for frame Read Parameter 220 and 221: Read parameter 220 and 221 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_220_AND_221(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_220_AND_221)
// Match arbitration ID for frame Read Parameter 222 and 223: Read parameter 222 and 223 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_222_AND_223(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_222_AND_223)
// Match arbitration ID for frame Read Parameter 224 and 225: Read parameter 224 and 225 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_224_AND_225(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_224_AND_225)
// Match arbitration ID for frame Read Parameter 226 and 227: Read parameter 226 and 227 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_226_AND_227(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_226_AND_227)
// Match arbitration ID for frame Read Parameter 228 and 229: Read parameter 228 and 229 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_228_AND_229(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_228_AND_229)
// Match arbitration ID for frame Read Parameter 230 and 231: Read parameter 230 and 231 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_230_AND_231(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_230_AND_231)
// Match arbitration ID for frame Read Parameter 232 and 233: Read parameter 232 and 233 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_232_AND_233(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_232_AND_233)
// Match arbitration ID for frame Read Parameter 234 and 235: Read parameter 234 and 235 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_234_AND_235(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_234_AND_235)
// Match arbitration ID for frame Read Parameter 236 and 237: Read parameter 236 and 237 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_236_AND_237(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_236_AND_237)
// Match arbitration ID for frame Read Parameter 238 and 239: Read parameter 238 and 239 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_238_AND_239(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_238_AND_239)
// Match arbitration ID for frame Read Parameter 240 and 241: Read parameter 240 and 241 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_240_AND_241(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_240_AND_241)
// Match arbitration ID for frame Read Parameter 242 and 243: Read parameter 242 and 243 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_242_AND_243(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_242_AND_243)
// Match arbitration ID for frame Read Parameter 244 and 245: Read parameter 244 and 245 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_244_AND_245(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_244_AND_245)
// Match arbitration ID for frame Read Parameter 246 and 247: Read parameter 246 and 247 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_246_AND_247(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_246_AND_247)
// Match arbitration ID for frame Read Parameter 248 and 249: Read parameter 248 and 249 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_248_AND_249(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_248_AND_249)
// Match arbitration ID for frame Read Parameter 250 and 251: Read parameter 250 and 251 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_250_AND_251(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_250_AND_251)
// Match arbitration ID for frame Read Parameter 252 and 253: Read parameter 252 and 253 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_252_AND_253(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_252_AND_253)
// Match arbitration ID for frame Read Parameter 254 and 255: Read parameter 254 and 255 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
#define SPARK_MATCH_READ_PARAMETER_254_AND_255(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_READ_PARAMETER_254_AND_255)
// Match arbitration ID for frame Write Parameter 0 and 1: Write Parameter 0 and 1 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_0_AND_1(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_0_AND_1)
// Match arbitration ID for frame Write Parameter 2 and 3: Write Parameter 2 and 3 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_2_AND_3(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_2_AND_3)
// Match arbitration ID for frame Write Parameter 4 and 5: Write Parameter 4 and 5 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_4_AND_5(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_4_AND_5)
// Match arbitration ID for frame Write Parameter 6 and 7: Write Parameter 6 and 7 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_6_AND_7(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_6_AND_7)
// Match arbitration ID for frame Write Parameter 8 and 9: Write Parameter 8 and 9 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_8_AND_9(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_8_AND_9)
// Match arbitration ID for frame Write Parameter 10 and 11: Write Parameter 10 and 11 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_10_AND_11(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_10_AND_11)
// Match arbitration ID for frame Write Parameter 12 and 13: Write Parameter 12 and 13 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_12_AND_13(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_12_AND_13)
// Match arbitration ID for frame Write Parameter 14 and 15: Write Parameter 14 and 15 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_14_AND_15(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_14_AND_15)
// Match arbitration ID for frame Write Parameter 16 and 17: Write Parameter 16 and 17 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_16_AND_17(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_16_AND_17)
// Match arbitration ID for frame Write Parameter 18 and 19: Write Parameter 18 and 19 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_18_AND_19(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_18_AND_19)
// Match arbitration ID for frame Write Parameter 20 and 21: Write Parameter 20 and 21 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_20_AND_21(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_20_AND_21)
// Match arbitration ID for frame Write Parameter 22 and 23: Write Parameter 22 and 23 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_22_AND_23(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_22_AND_23)
// Match arbitration ID for frame Write Parameter 24 and 25: Write Parameter 24 and 25 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_24_AND_25(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_24_AND_25)
// Match arbitration ID for frame Write Parameter 26 and 27: Write Parameter 26 and 27 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_26_AND_27(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_26_AND_27)
// Match arbitration ID for frame Write Parameter 28 and 29: Write Parameter 28 and 29 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_28_AND_29(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_28_AND_29)
// Match arbitration ID for frame Write Parameter 30 and 31: Write Parameter 30 and 31 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_30_AND_31(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_30_AND_31)
// Match arbitration ID for frame Write Parameter 32 and 33: Write Parameter 32 and 33 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_32_AND_33(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_32_AND_33)
// Match arbitration ID for frame Write Parameter 34 and 35: Write Parameter 34 and 35 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_34_AND_35(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_34_AND_35)
// Match arbitration ID for frame Write Parameter 36 and 37: Write Parameter 36 and 37 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_36_AND_37(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_36_AND_37)
// Match arbitration ID for frame Write Parameter 38 and 39: Write Parameter 38 and 39 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_38_AND_39(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_38_AND_39)
// Match arbitration ID for frame Write Parameter 40 and 41: Write Parameter 40 and 41 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_40_AND_41(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_40_AND_41)
// Match arbitration ID for frame Write Parameter 42 and 43: Write Parameter 42 and 43 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_42_AND_43(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_42_AND_43)
// Match arbitration ID for frame Write Parameter 44 and 45: Write Parameter 44 and 45 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_44_AND_45(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_44_AND_45)
// Match arbitration ID for frame Write Parameter 46 and 47: Write Parameter 46 and 47 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_46_AND_47(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_46_AND_47)
// Match arbitration ID for frame Write Parameter 48 and 49: Write Parameter 48 and 49 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_48_AND_49(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_48_AND_49)
// Match arbitration ID for frame Write Parameter 50 and 51: Write Parameter 50 and 51 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_50_AND_51(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_50_AND_51)
// Match arbitration ID for frame Write Parameter 52 and 53: Write Parameter 52 and 53 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_52_AND_53(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_52_AND_53)
// Match arbitration ID for frame Write Parameter 54 and 55: Write Parameter 54 and 55 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_54_AND_55(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_54_AND_55)
// Match arbitration ID for frame Write Parameter 56 and 57: Write Parameter 56 and 57 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_56_AND_57(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_56_AND_57)
// Match arbitration ID for frame Write Parameter 58 and 59: Write Parameter 58 and 59 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_58_AND_59(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_58_AND_59)
// Match arbitration ID for frame Write Parameter 60 and 61: Write Parameter 60 and 61 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_60_AND_61(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_60_AND_61)
// Match arbitration ID for frame Write Parameter 62 and 63: Write Parameter 62 and 63 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_62_AND_63(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_62_AND_63)
// Match arbitration ID for frame Write Parameter 64 and 65: Write Parameter 64 and 65 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_64_AND_65(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_64_AND_65)
// Match arbitration ID for frame Write Parameter 66 and 67: Write Parameter 66 and 67 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_66_AND_67(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_66_AND_67)
// Match arbitration ID for frame Write Parameter 68 and 69: Write Parameter 68 and 69 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_68_AND_69(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_68_AND_69)
// Match arbitration ID for frame Write Parameter 70 and 71: Write Parameter 70 and 71 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_70_AND_71(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_70_AND_71)
// Match arbitration ID for frame Write Parameter 72 and 73: Write Parameter 72 and 73 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_72_AND_73(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_72_AND_73)
// Match arbitration ID for frame Write Parameter 74 and 75: Write Parameter 74 and 75 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_74_AND_75(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_74_AND_75)
// Match arbitration ID for frame Write Parameter 76 and 77: Write Parameter 76 and 77 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_76_AND_77(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_76_AND_77)
// Match arbitration ID for frame Write Parameter 78 and 79: Write Parameter 78 and 79 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_78_AND_79(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_78_AND_79)
// Match arbitration ID for frame Write Parameter 80 and 81: Write Parameter 80 and 81 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_80_AND_81(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_80_AND_81)
// Match arbitration ID for frame Write Parameter 82 and 83: Write Parameter 82 and 83 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_82_AND_83(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_82_AND_83)
// Match arbitration ID for frame Write Parameter 84 and 85: Write Parameter 84 and 85 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_84_AND_85(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_84_AND_85)
// Match arbitration ID for frame Write Parameter 86 and 87: Write Parameter 86 and 87 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_86_AND_87(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_86_AND_87)
// Match arbitration ID for frame Write Parameter 88 and 89: Write Parameter 88 and 89 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_88_AND_89(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_88_AND_89)
// Match arbitration ID for frame Write Parameter 90 and 91: Write Parameter 90 and 91 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_90_AND_91(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_90_AND_91)
// Match arbitration ID for frame Write Parameter 92 and 93: Write Parameter 92 and 93 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_92_AND_93(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_92_AND_93)
// Match arbitration ID for frame Write Parameter 94 and 95: Write Parameter 94 and 95 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_94_AND_95(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_94_AND_95)
// Match arbitration ID for frame Write Parameter 96 and 97: Write Parameter 96 and 97 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_96_AND_97(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_96_AND_97)
// Match arbitration ID for frame Write Parameter 98 and 99: Write Parameter 98 and 99 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_98_AND_99(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_98_AND_99)
// Match arbitration ID for frame Write Parameter 100 and 101: Write Parameter 100 and 101 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_100_AND_101(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_100_AND_101)
// Match arbitration ID for frame Write Parameter 102 and 103: Write Parameter 102 and 103 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_102_AND_103(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_102_AND_103)
// Match arbitration ID for frame Write Parameter 104 and 105: Write Parameter 104 and 105 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_104_AND_105(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_104_AND_105)
// Match arbitration ID for frame Write Parameter 106 and 107: Write Parameter 106 and 107 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_106_AND_107(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_106_AND_107)
// Match arbitration ID for frame Write Parameter 108 and 109: Write Parameter 108 and 109 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_108_AND_109(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_108_AND_109)
// Match arbitration ID for frame Write Parameter 110 and 111: Write Parameter 110 and 111 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_110_AND_111(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_110_AND_111)
// Match arbitration ID for frame Write Parameter 112 and 113: Write Parameter 112 and 113 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_112_AND_113(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_112_AND_113)
// Match arbitration ID for frame Write Parameter 114 and 115: Write Parameter 114 and 115 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_114_AND_115(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_114_AND_115)
// Match arbitration ID for frame Write Parameter 116 and 117: Write Parameter 116 and 117 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_116_AND_117(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_116_AND_117)
// Match arbitration ID for frame Write Parameter 118 and 119: Write Parameter 118 and 119 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_118_AND_119(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_118_AND_119)
// Match arbitration ID for frame Write Parameter 120 and 121: Write Parameter 120 and 121 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_120_AND_121(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_120_AND_121)
// Match arbitration ID for frame Write Parameter 122 and 123: Write Parameter 122 and 123 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_122_AND_123(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_122_AND_123)
// Match arbitration ID for frame Write Parameter 124 and 125: Write Parameter 124 and 125 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_124_AND_125(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_124_AND_125)
// Match arbitration ID for frame Write Parameter 126 and 127: Write Parameter 126 and 127 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_126_AND_127(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_126_AND_127)
// Match arbitration ID for frame Write Parameter 128 and 129: Write Parameter 128 and 129 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_128_AND_129(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_128_AND_129)
// Match arbitration ID for frame Write Parameter 130 and 131: Write Parameter 130 and 131 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_130_AND_131(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_130_AND_131)
// Match arbitration ID for frame Write Parameter 132 and 133: Write Parameter 132 and 133 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_132_AND_133(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_132_AND_133)
// Match arbitration ID for frame Write Parameter 134 and 135: Write Parameter 134 and 135 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_134_AND_135(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_134_AND_135)
// Match arbitration ID for frame Write Parameter 136 and 137: Write Parameter 136 and 137 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_136_AND_137(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_136_AND_137)
// Match arbitration ID for frame Write Parameter 138 and 139: Write Parameter 138 and 139 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_138_AND_139(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_138_AND_139)
// Match arbitration ID for frame Write Parameter 140 and 141: Write Parameter 140 and 141 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_140_AND_141(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_140_AND_141)
// Match arbitration ID for frame Write Parameter 142 and 143: Write Parameter 142 and 143 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_142_AND_143(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_142_AND_143)
// Match arbitration ID for frame Write Parameter 144 and 145: Write Parameter 144 and 145 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_144_AND_145(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_144_AND_145)
// Match arbitration ID for frame Write Parameter 146 and 147: Write Parameter 146 and 147 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_146_AND_147(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_146_AND_147)
// Match arbitration ID for frame Write Parameter 148 and 149: Write Parameter 148 and 149 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_148_AND_149(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_148_AND_149)
// Match arbitration ID for frame Write Parameter 150 and 151: Write Parameter 150 and 151 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_150_AND_151(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_150_AND_151)
// Match arbitration ID for frame Write Parameter 152 and 153: Write Parameter 152 and 153 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_152_AND_153(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_152_AND_153)
// Match arbitration ID for frame Write Parameter 154 and 155: Write Parameter 154 and 155 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_154_AND_155(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_154_AND_155)
// Match arbitration ID for frame Write Parameter 156 and 157: Write Parameter 156 and 157 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_156_AND_157(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_156_AND_157)
// Match arbitration ID for frame Write Parameter 158 and 159: Write Parameter 158 and 159 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_158_AND_159(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_158_AND_159)
// Match arbitration ID for frame Write Parameter 160 and 161: Write Parameter 160 and 161 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_160_AND_161(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_160_AND_161)
// Match arbitration ID for frame Write Parameter 162 and 163: Write Parameter 162 and 163 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_162_AND_163(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_162_AND_163)
// Match arbitration ID for frame Write Parameter 164 and 165: Write Parameter 164 and 165 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_164_AND_165(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_164_AND_165)
// Match arbitration ID for frame Write Parameter 166 and 167: Write Parameter 166 and 167 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_166_AND_167(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_166_AND_167)
// Match arbitration ID for frame Write Parameter 168 and 169: Write Parameter 168 and 169 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_168_AND_169(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_168_AND_169)
// Match arbitration ID for frame Write Parameter 170 and 171: Write Parameter 170 and 171 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_170_AND_171(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_170_AND_171)
// Match arbitration ID for frame Write Parameter 172 and 173: Write Parameter 172 and 173 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_172_AND_173(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_172_AND_173)
// Match arbitration ID for frame Write Parameter 174 and 175: Write Parameter 174 and 175 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_174_AND_175(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_174_AND_175)
// Match arbitration ID for frame Write Parameter 176 and 177: Write Parameter 176 and 177 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_176_AND_177(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_176_AND_177)
// Match arbitration ID for frame Write Parameter 178 and 179: Write Parameter 178 and 179 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_178_AND_179(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_178_AND_179)
// Match arbitration ID for frame Write Parameter 180 and 181: Write Parameter 180 and 181 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_180_AND_181(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_180_AND_181)
// Match arbitration ID for frame Write Parameter 182 and 183: Write Parameter 182 and 183 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_182_AND_183(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_182_AND_183)
// Match arbitration ID for frame Write Parameter 184 and 185: Write Parameter 184 and 185 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_184_AND_185(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_184_AND_185)
// Match arbitration ID for frame Write Parameter 186 and 187: Write Parameter 186 and 187 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_186_AND_187(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_186_AND_187)
// Match arbitration ID for frame Write Parameter 188 and 189: Write Parameter 188 and 189 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_188_AND_189(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_188_AND_189)
// Match arbitration ID for frame Write Parameter 190 and 191: Write Parameter 190 and 191 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_190_AND_191(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_190_AND_191)
// Match arbitration ID for frame Write Parameter 192 and 193: Write Parameter 192 and 193 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_192_AND_193(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_192_AND_193)
// Match arbitration ID for frame Write Parameter 194 and 195: Write Parameter 194 and 195 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_194_AND_195(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_194_AND_195)
// Match arbitration ID for frame Write Parameter 196 and 197: Write Parameter 196 and 197 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_196_AND_197(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_196_AND_197)
// Match arbitration ID for frame Write Parameter 198 and 199: Write Parameter 198 and 199 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_198_AND_199(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_198_AND_199)
// Match arbitration ID for frame Write Parameter 200 and 201: Write Parameter 200 and 201 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_200_AND_201(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_200_AND_201)
// Match arbitration ID for frame Write Parameter 202 and 203: Write Parameter 202 and 203 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_202_AND_203(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_202_AND_203)
// Match arbitration ID for frame Write Parameter 204 and 205: Write Parameter 204 and 205 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_204_AND_205(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_204_AND_205)
// Match arbitration ID for frame Write Parameter 206 and 207: Write Parameter 206 and 207 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_206_AND_207(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_206_AND_207)
// Match arbitration ID for frame Write Parameter 208 and 209: Write Parameter 208 and 209 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_208_AND_209(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_208_AND_209)
// Match arbitration ID for frame Write Parameter 210 and 211: Write Parameter 210 and 211 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_210_AND_211(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_210_AND_211)
// Match arbitration ID for frame Write Parameter 212 and 213: Write Parameter 212 and 213 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_212_AND_213(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_212_AND_213)
// Match arbitration ID for frame Write Parameter 214 and 215: Write Parameter 214 and 215 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_214_AND_215(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_214_AND_215)
// Match arbitration ID for frame Write Parameter 216 and 217: Write Parameter 216 and 217 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_216_AND_217(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_216_AND_217)
// Match arbitration ID for frame Write Parameter 218 and 219: Write Parameter 218 and 219 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_218_AND_219(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_218_AND_219)
// Match arbitration ID for frame Write Parameter 220 and 221: Write Parameter 220 and 221 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_220_AND_221(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_220_AND_221)
// Match arbitration ID for frame Write Parameter 222 and 223: Write Parameter 222 and 223 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_222_AND_223(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_222_AND_223)
// Match arbitration ID for frame Write Parameter 224 and 225: Write Parameter 224 and 225 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_224_AND_225(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_224_AND_225)
// Match arbitration ID for frame Write Parameter 226 and 227: Write Parameter 226 and 227 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_226_AND_227(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_226_AND_227)
// Match arbitration ID for frame Write Parameter 228 and 229: Write Parameter 228 and 229 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_228_AND_229(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_228_AND_229)
// Match arbitration ID for frame Write Parameter 230 and 231: Write Parameter 230 and 231 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_230_AND_231(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_230_AND_231)
// Match arbitration ID for frame Write Parameter 232 and 233: Write Parameter 232 and 233 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_232_AND_233(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_232_AND_233)
// Match arbitration ID for frame Write Parameter 234 and 235: Write Parameter 234 and 235 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_234_AND_235(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_234_AND_235)
// Match arbitration ID for frame Write Parameter 236 and 237: Write Parameter 236 and 237 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_236_AND_237(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_236_AND_237)
// Match arbitration ID for frame Write Parameter 238 and 239: Write Parameter 238 and 239 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_238_AND_239(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_238_AND_239)
// Match arbitration ID for frame Write Parameter 240 and 241: Write Parameter 240 and 241 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_240_AND_241(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_240_AND_241)
// Match arbitration ID for frame Write Parameter 242 and 243: Write Parameter 242 and 243 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_242_AND_243(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_242_AND_243)
// Match arbitration ID for frame Write Parameter 244 and 245: Write Parameter 244 and 245 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_244_AND_245(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_244_AND_245)
// Match arbitration ID for frame Write Parameter 246 and 247: Write Parameter 246 and 247 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_246_AND_247(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_246_AND_247)
// Match arbitration ID for frame Write Parameter 248 and 249: Write Parameter 248 and 249 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_248_AND_249(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_248_AND_249)
// Match arbitration ID for frame Write Parameter 250 and 251: Write Parameter 250 and 251 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_250_AND_251(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_250_AND_251)
// Match arbitration ID for frame Write Parameter 252 and 253: Write Parameter 252 and 253 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_252_AND_253(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_252_AND_253)
// Match arbitration ID for frame Write Parameter 254 and 255: Write Parameter 254 and 255 at the same time. Two Write Parameter Response frames will be sent in response.
#define SPARK_MATCH_WRITE_PARAMETER_254_AND_255(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_WRITE_PARAMETER_254_AND_255)
// Match arbitration ID for frame Start Follower Mode: Starts follower mode. The relevant parameters must already be configured. In response, a Start Follower Mode Response frame will be sent. Follower mode will be auto-started on boot if the Follower Mode Leader ID parameter is set to a non-zero value.
#define SPARK_MATCH_START_FOLLOWER_MODE(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_START_FOLLOWER_MODE)
// Match arbitration ID for frame Start Follower Mode Response: Response for a Start Follower Mode command
#define SPARK_MATCH_START_FOLLOWER_MODE_RESPONSE(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_START_FOLLOWER_MODE_RESPONSE)
// Match arbitration ID for frame Stop Follower Mode: Exits follower mode and causes the device to resume listening for setpoints addressed directly to it. In response, a Stop Follower Mode Response frame will be sent.
#define SPARK_MATCH_STOP_FOLLOWER_MODE(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_STOP_FOLLOWER_MODE)
// Match arbitration ID for frame Stop Follower Mode Response: Response for a Stop Follower Mode Command
#define SPARK_MATCH_STOP_FOLLOWER_MODE_RESPONSE(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_STOP_FOLLOWER_MODE_RESPONSE)
// Match arbitration ID for frame Enter SWDL CAN Bootloader
#define SPARK_MATCH_ENTER_SWDL_CAN_BOOTLOADER(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_ENTER_SWDL_CAN_BOOTLOADER)
// Match arbitration ID for frame Persist Parameters: Causes all parameters to be written to non-volatile storage. After the operation (which may take up to a second) completes, a Persist Parameters Response frame will be sent.
#define SPARK_MATCH_PERSIST_PARAMETERS(id) ((((uint32_t)(id)) & ~SPARK_DEVICE_ID_MASK) == (uint32_t)SPARK_ARB_PERSIST_PARAMETERS)

// Frame values for Legacy Status 0: This frame exists purely to inform old software that is not aware of firmware version 25+ that the SPARK is present
typedef struct {
    // Applied Output: Always 0 so that SPARKs running old firmware trying to follow this SPARK don't move
    uint16_t APPLIED_OUTPUT;
    // Faults and Sticky Faults: Always has all faults set so that old software knows that something is wrong
    uint32_t FAULTS_AND_STICKY_FAULTS;
    // Other Signals: The other signals don't matter very much, and all get set to 0
    uint16_t OTHER_SIGNALS;
} Spark_LEGACY_STATUS_0_t;

// Decode frame payload for Legacy Status 0: This frame exists purely to inform old software that is not aware of firmware version 25+ that the SPARK is present
bool spark_decode_LEGACY_STATUS_0(const uint8_t* data, uint8_t dlc, Spark_LEGACY_STATUS_0_t* out);
static inline bool spark_decode_LEGACY_STATUS_0_frame(const spark_can_frame& in, Spark_LEGACY_STATUS_0_t* out) { return spark_decode_LEGACY_STATUS_0(in.data, in.dlc, out); }

// Frame values for Bootloader 0: Periodic frame when device is in the bootloader
typedef struct {
    // BL Major
    uint8_t BL_MAJOR;
    // BL Minor
    uint8_t BL_MINOR;
    // Product ID
    uint16_t PRODUCT_ID;
    // Rsvd
    uint32_t RSVD;
} Spark_BOOTLOADER_0_t;

// Decode frame payload for Bootloader 0: Periodic frame when device is in the bootloader
bool spark_decode_BOOTLOADER_0(const uint8_t* data, uint8_t dlc, Spark_BOOTLOADER_0_t* out);
static inline bool spark_decode_BOOTLOADER_0_frame(const spark_can_frame& in, Spark_BOOTLOADER_0_t* out) { return spark_decode_BOOTLOADER_0(in.data, in.dlc, out); }

// Frame values for Status 0: Includes general data that is likely to need frequent refreshing
typedef struct {
    // Applied Output
    int16_t APPLIED_OUTPUT;
    // Voltage
    uint16_t VOLTAGE;
    // Current
    uint16_t CURRENT;
    // Motor Temperature
    uint8_t MOTOR_TEMPERATURE;
    // Hard Forward Limit Reached: Whether the forward physical limit switch has been reached
    bool HARD_FORWARD_LIMIT_REACHED;
    // Hard Reverse Limit Reached: Whether the reverse physical limit switch has been reached
    bool HARD_REVERSE_LIMIT_REACHED;
    // Soft Forward Limit Reached: Whether the forward software-defined position limit has been reached
    bool SOFT_FORWARD_LIMIT_REACHED;
    // Soft Reverse Limit Reached: Whether the reverse software-defined position limit has been reached
    bool SOFT_REVERSE_LIMIT_REACHED;
    // Inverted
    bool INVERTED;
    // Primary Heartbeat Lock: Indicates that the SPARK is in competition mode and will ignore the Secondary Heartbeat until it is power cycled
    bool PRIMARY_HEARTBEAT_LOCK;
    // Spark Model
    uint8_t SPARK_MODEL;
} Spark_STATUS_0_t;

// Decode frame payload for Status 0: Includes general data that is likely to need frequent refreshing
bool spark_decode_STATUS_0(const uint8_t* data, uint8_t dlc, Spark_STATUS_0_t* out);
static inline bool spark_decode_STATUS_0_frame(const spark_can_frame& in, Spark_STATUS_0_t* out) { return spark_decode_STATUS_0(in.data, in.dlc, out); }

// Frame values for Status 1: Includes general data that can likely tolerate infrequent refreshing
typedef struct {
    // Other Fault
    bool OTHER_FAULT;
    // Motor Type Fault
    bool MOTOR_TYPE_FAULT;
    // Sensor Fault
    bool SENSOR_FAULT;
    // CAN Fault
    bool CAN_FAULT;
    // Temperature Fault
    bool TEMPERATURE_FAULT;
    // DRV Fault
    bool DRV_FAULT;
    // ESC EEPROM Fault
    bool ESC_EEPROM_FAULT;
    // Firmware Fault
    bool FIRMWARE_FAULT;
    // Brownout Warning
    bool BROWNOUT_WARNING;
    // Overcurrent Warning
    bool OVERCURRENT_WARNING;
    // ESC EEPROM Warning
    bool ESC_EEPROM_WARNING;
    // Ext EEPROM Warning
    bool EXT_EEPROM_WARNING;
    // Sensor Warning
    bool SENSOR_WARNING;
    // Stall Warning
    bool STALL_WARNING;
    // Has Reset Warning
    bool HAS_RESET_WARNING;
    // Other Warning
    bool OTHER_WARNING;
    // Other Sticky Fault
    bool OTHER_STICKY_FAULT;
    // Motor Type Sticky Fault
    bool MOTOR_TYPE_STICKY_FAULT;
    // Sensor Sticky Fault
    bool SENSOR_STICKY_FAULT;
    // CAN Sticky Fault
    bool CAN_STICKY_FAULT;
    // Temperature Sticky Fault
    bool TEMPERATURE_STICKY_FAULT;
    // DRV Sticky Fault
    bool DRV_STICKY_FAULT;
    // ESC EEPROM Sticky Fault
    bool ESC_EEPROM_STICKY_FAULT;
    // Firmware Sticky Fault
    bool FIRMWARE_STICKY_FAULT;
    // Brownout Sticky Warning
    bool BROWNOUT_STICKY_WARNING;
    // Overcurrent Sticky Warning
    bool OVERCURRENT_STICKY_WARNING;
    // ESC EEPROM Sticky Warning
    bool ESC_EEPROM_STICKY_WARNING;
    // Ext EEPROM Sticky Warning
    bool EXT_EEPROM_STICKY_WARNING;
    // Sensor Sticky Warning
    bool SENSOR_STICKY_WARNING;
    // Stall Sticky Warning
    bool STALL_STICKY_WARNING;
    // Has Reset Sticky Warning
    bool HAS_RESET_STICKY_WARNING;
    // Other Sticky Warning
    bool OTHER_STICKY_WARNING;
    // Is Follower
    bool IS_FOLLOWER;
} Spark_STATUS_1_t;

// Decode frame payload for Status 1: Includes general data that can likely tolerate infrequent refreshing
bool spark_decode_STATUS_1(const uint8_t* data, uint8_t dlc, Spark_STATUS_1_t* out);
static inline bool spark_decode_STATUS_1_frame(const spark_can_frame& in, Spark_STATUS_1_t* out) { return spark_decode_STATUS_1(in.data, in.dlc, out); }

// Frame values for Status 2: Includes data from the primary encoder (either a brushless motor's internal encoder, or the primary encoder associated with a brushed motor)
typedef struct {
    // Primary Encoder Velocity: By default, the unit is RPM, but it can be changed implicitly using the Velocity Conversion Factor parameter
    float PRIMARY_ENCODER_VELOCITY;
    // Primary Encoder Position: By default, the unit is rotations, but it can be changed implicitly using the Position Conversion Factor parameter
    float PRIMARY_ENCODER_POSITION;
} Spark_STATUS_2_t;

// Decode frame payload for Status 2: Includes data from the primary encoder (either a brushless motor's internal encoder, or the primary encoder associated with a brushed motor)
bool spark_decode_STATUS_2(const uint8_t* data, uint8_t dlc, Spark_STATUS_2_t* out);
static inline bool spark_decode_STATUS_2_frame(const spark_can_frame& in, Spark_STATUS_2_t* out) { return spark_decode_STATUS_2(in.data, in.dlc, out); }

// Frame values for Status 3: Includes data from an analog sensor
typedef struct {
    // Analog Voltage
    uint16_t ANALOG_VOLTAGE;
    // Analog Velocity: By default, the unit is RPM, but it can be changed implicitly using the Analog Velocity Conversion Factor parameter
    int32_t ANALOG_VELOCITY;
    // Analog Position: By default, the unit is rotations, but it can be changed implicitly using the Analog Position Conversion Factor parameter
    float ANALOG_POSITION;
} Spark_STATUS_3_t;

// Decode frame payload for Status 3: Includes data from an analog sensor
bool spark_decode_STATUS_3(const uint8_t* data, uint8_t dlc, Spark_STATUS_3_t* out);
static inline bool spark_decode_STATUS_3_frame(const spark_can_frame& in, Spark_STATUS_3_t* out) { return spark_decode_STATUS_3(in.data, in.dlc, out); }

// Frame values for Status 4: Includes data from the External Encoder (on SPARK MAX, this is the Alternate Encoder)
typedef struct {
    // External or Alt Encoder Velocity: By default, the unit is RPM, but it can be changed implicitly using the External/Alternate Encoder Velocity Conversion Factor parameter
    float EXTERNAL_OR_ALT_ENCODER_VELOCITY;
    // External or Alt Encoder Position: By default, the unit is rotations, but it can be changed implicitly using the External/Alternate Encoder Position Conversion Factor parameter
    float EXTERNAL_OR_ALT_ENCODER_POSITION;
} Spark_STATUS_4_t;

// Decode frame payload for Status 4: Includes data from the External Encoder (on SPARK MAX, this is the Alternate Encoder)
bool spark_decode_STATUS_4(const uint8_t* data, uint8_t dlc, Spark_STATUS_4_t* out);
static inline bool spark_decode_STATUS_4_frame(const spark_can_frame& in, Spark_STATUS_4_t* out) { return spark_decode_STATUS_4(in.data, in.dlc, out); }

// Frame values for Status 5: Includes velocity and position data from a duty-cycle absolute encoder
typedef struct {
    // Duty Cycle Encoder Velocity: By default, the unit is RPM, but it can be changed implicitly using the Duty Cycle Velocity Conversion Factor parameter
    float DUTY_CYCLE_ENCODER_VELOCITY;
    // Duty Cycle Encoder Position: By default, the unit is rotations, but it can be changed implicitly using the Duty Cycle Position Conversion Factor parameter
    float DUTY_CYCLE_ENCODER_POSITION;
} Spark_STATUS_5_t;

// Decode frame payload for Status 5: Includes velocity and position data from a duty-cycle absolute encoder
bool spark_decode_STATUS_5(const uint8_t* data, uint8_t dlc, Spark_STATUS_5_t* out);
static inline bool spark_decode_STATUS_5_frame(const spark_can_frame& in, Spark_STATUS_5_t* out) { return spark_decode_STATUS_5(in.data, in.dlc, out); }

// Frame values for Status 6: Includes other data from a duty-cycle absolute encoder
typedef struct {
    // Unadjusted Duty Cycle: The duty cycle from 0 to 1, with no inversion or conversion factor applied
    uint16_t UNADJUSTED_DUTY_CYCLE;
    // Duty Cycle Period
    uint16_t DUTY_CYCLE_PERIOD;
    // Duty Cycle No Signal
    bool DUTY_CYCLE_NO_SIGNAL;
} Spark_STATUS_6_t;

// Decode frame payload for Status 6: Includes other data from a duty-cycle absolute encoder
bool spark_decode_STATUS_6(const uint8_t* data, uint8_t dlc, Spark_STATUS_6_t* out);
static inline bool spark_decode_STATUS_6_frame(const spark_can_frame& in, Spark_STATUS_6_t* out) { return spark_decode_STATUS_6(in.data, in.dlc, out); }

// Frame values for Status 7: Includes diagnostic data for closed-loop control
typedef struct {
    // I Accumulation
    float I_ACCUMULATION;
} Spark_STATUS_7_t;

// Decode frame payload for Status 7: Includes diagnostic data for closed-loop control
bool spark_decode_STATUS_7(const uint8_t* data, uint8_t dlc, Spark_STATUS_7_t* out);
static inline bool spark_decode_STATUS_7_frame(const spark_can_frame& in, Spark_STATUS_7_t* out) { return spark_decode_STATUS_7(in.data, in.dlc, out); }

// Frame values for Status 8: Includes additional diagnostic data for closed-loop control
typedef struct {
    // Setpoint
    float SETPOINT;
    // Is At Setpoint
    bool IS_AT_SETPOINT;
    // Selected Pid Slot
    uint8_t SELECTED_PID_SLOT;
} Spark_STATUS_8_t;

// Decode frame payload for Status 8: Includes additional diagnostic data for closed-loop control
bool spark_decode_STATUS_8(const uint8_t* data, uint8_t dlc, Spark_STATUS_8_t* out);
static inline bool spark_decode_STATUS_8_frame(const spark_can_frame& in, Spark_STATUS_8_t* out) { return spark_decode_STATUS_8(in.data, in.dlc, out); }

// Frame values for Status 9: Includes diagnostic data for MAXMotion closed-loop control
typedef struct {
    // MAXMotion Position Setpoint: The internal, intermediate position target used by MAXMotion
    float MAXMOTION_POSITION_SETPOINT;
    // MAXMotion Velocity Setpoint: The internal, intermediate velocity target used by MAXMotion
    float MAXMOTION_VELOCITY_SETPOINT;
} Spark_STATUS_9_t;

// Decode frame payload for Status 9: Includes diagnostic data for MAXMotion closed-loop control
bool spark_decode_STATUS_9(const uint8_t* data, uint8_t dlc, Spark_STATUS_9_t* out);
static inline bool spark_decode_STATUS_9_frame(const spark_can_frame& in, Spark_STATUS_9_t* out) { return spark_decode_STATUS_9(in.data, in.dlc, out); }

// Frame values for Unique ID Broadcast: Contains the unique ID of the device, to allow detecting duplicate CAN IDs. To avoid collisions, the SPARK Flex firmware will send this at an irregular period between 1000ms and 2000ms. SPARK MAX may use a constant period of 1000ms.
typedef struct {
    // Unique ID
    uint32_t UNIQUE_ID;
} Spark_UNIQUE_ID_BROADCAST_t;

// Decode frame payload for Unique ID Broadcast: Contains the unique ID of the device, to allow detecting duplicate CAN IDs. To avoid collisions, the SPARK Flex firmware will send this at an irregular period between 1000ms and 2000ms. SPARK MAX may use a constant period of 1000ms.
bool spark_decode_UNIQUE_ID_BROADCAST(const uint8_t* data, uint8_t dlc, Spark_UNIQUE_ID_BROADCAST_t* out);
static inline bool spark_decode_UNIQUE_ID_BROADCAST_frame(const spark_can_frame& in, Spark_UNIQUE_ID_BROADCAST_t* out) { return spark_decode_UNIQUE_ID_BROADCAST(in.data, in.dlc, out); }

// Frame values for Velocity Setpoint: Sets the Control Type to Velocity and sets the target velocity
typedef struct {
    // Setpoint: By default, the unit is RPM, but it can be changed implicitly using the Velocity Conversion Factor parameter
    float SETPOINT;
    // Arbitrary Feedforward
    int16_t ARBITRARY_FEEDFORWARD;
    // PID Slot
    uint8_t PID_SLOT;
    // Arbitrary Feedforward Units: 0: Voltage, 1: Duty Cycle (-1 to 1)
    uint8_t ARBITRARY_FEEDFORWARD_UNITS;
} Spark_VELOCITY_SETPOINT_t;

// Decode frame payload for Velocity Setpoint: Sets the Control Type to Velocity and sets the target velocity
bool spark_decode_VELOCITY_SETPOINT(const uint8_t* data, uint8_t dlc, Spark_VELOCITY_SETPOINT_t* out);
static inline bool spark_decode_VELOCITY_SETPOINT_frame(const spark_can_frame& in, Spark_VELOCITY_SETPOINT_t* out) { return spark_decode_VELOCITY_SETPOINT(in.data, in.dlc, out); }

// Frame values for Duty Cycle Setpoint: Sets the Control Type to Duty Cycle and sets the target duty cycle (from -1 to 1)
typedef struct {
    // Setpoint
    float SETPOINT;
    // Arbitrary Feedforward
    int16_t ARBITRARY_FEEDFORWARD;
    // PID Slot
    uint8_t PID_SLOT;
    // Arbitrary Feedforward Units: 0: Voltage, 1: Duty Cycle (-1 to 1)
    uint8_t ARBITRARY_FEEDFORWARD_UNITS;
} Spark_DUTY_CYCLE_SETPOINT_t;

// Decode frame payload for Duty Cycle Setpoint: Sets the Control Type to Duty Cycle and sets the target duty cycle (from -1 to 1)
bool spark_decode_DUTY_CYCLE_SETPOINT(const uint8_t* data, uint8_t dlc, Spark_DUTY_CYCLE_SETPOINT_t* out);
static inline bool spark_decode_DUTY_CYCLE_SETPOINT_frame(const spark_can_frame& in, Spark_DUTY_CYCLE_SETPOINT_t* out) { return spark_decode_DUTY_CYCLE_SETPOINT(in.data, in.dlc, out); }

// Frame values for Position Setpoint: Sets the Control Type to Position and sets the target position
typedef struct {
    // Setpoint: By default, the unit is rotations, but it can be changed implicitly using the Position Conversion Factor parameter
    float SETPOINT;
    // Arbitrary Feedforward
    int16_t ARBITRARY_FEEDFORWARD;
    // PID Slot
    uint8_t PID_SLOT;
    // Arbitrary Feedforward Units: 0: Voltage, 1: Duty Cycle (-1 to 1)
    uint8_t ARBITRARY_FEEDFORWARD_UNITS;
} Spark_POSITION_SETPOINT_t;

// Decode frame payload for Position Setpoint: Sets the Control Type to Position and sets the target position
bool spark_decode_POSITION_SETPOINT(const uint8_t* data, uint8_t dlc, Spark_POSITION_SETPOINT_t* out);
static inline bool spark_decode_POSITION_SETPOINT_frame(const spark_can_frame& in, Spark_POSITION_SETPOINT_t* out) { return spark_decode_POSITION_SETPOINT(in.data, in.dlc, out); }

// Frame values for Voltage Setpoint: Sets the Control Type to Voltage and sets the target voltage
typedef struct {
    // Setpoint
    float SETPOINT;
    // Arbitrary Feedforward
    int16_t ARBITRARY_FEEDFORWARD;
    // PID Slot
    uint8_t PID_SLOT;
    // Arbitrary Feedforward Units: 0: Voltage, 1: Duty Cycle (-1 to 1)
    uint8_t ARBITRARY_FEEDFORWARD_UNITS;
} Spark_VOLTAGE_SETPOINT_t;

// Decode frame payload for Voltage Setpoint: Sets the Control Type to Voltage and sets the target voltage
bool spark_decode_VOLTAGE_SETPOINT(const uint8_t* data, uint8_t dlc, Spark_VOLTAGE_SETPOINT_t* out);
static inline bool spark_decode_VOLTAGE_SETPOINT_frame(const spark_can_frame& in, Spark_VOLTAGE_SETPOINT_t* out) { return spark_decode_VOLTAGE_SETPOINT(in.data, in.dlc, out); }

// Frame values for Current Setpoint: Sets the Control Type to Current and sets the target current
typedef struct {
    // Setpoint
    float SETPOINT;
    // Arbitrary Feedforward
    int16_t ARBITRARY_FEEDFORWARD;
    // PID Slot
    uint8_t PID_SLOT;
    // Arbitrary Feedforward Units: 0: Voltage, 1: Duty Cycle (-1 to 1)
    uint8_t ARBITRARY_FEEDFORWARD_UNITS;
} Spark_CURRENT_SETPOINT_t;

// Decode frame payload for Current Setpoint: Sets the Control Type to Current and sets the target current
bool spark_decode_CURRENT_SETPOINT(const uint8_t* data, uint8_t dlc, Spark_CURRENT_SETPOINT_t* out);
static inline bool spark_decode_CURRENT_SETPOINT_frame(const spark_can_frame& in, Spark_CURRENT_SETPOINT_t* out) { return spark_decode_CURRENT_SETPOINT(in.data, in.dlc, out); }

// Frame values for MAXMotion Position Setpoint: Sets the Control Type to MAXMotion Position Control and sets the target position
typedef struct {
    // Setpoint: By default, the unit is rotations, but it can be changed implicitly using the Position Conversion Factor parameter
    float SETPOINT;
    // Arbitrary Feedforward
    int16_t ARBITRARY_FEEDFORWARD;
    // PID Slot
    uint8_t PID_SLOT;
    // Arbitrary Feedforward Units: 0: Voltage, 1: Duty Cycle (-1 to 1)
    uint8_t ARBITRARY_FEEDFORWARD_UNITS;
} Spark_MAXMOTION_POSITION_SETPOINT_t;

// Decode frame payload for MAXMotion Position Setpoint: Sets the Control Type to MAXMotion Position Control and sets the target position
bool spark_decode_MAXMOTION_POSITION_SETPOINT(const uint8_t* data, uint8_t dlc, Spark_MAXMOTION_POSITION_SETPOINT_t* out);
static inline bool spark_decode_MAXMOTION_POSITION_SETPOINT_frame(const spark_can_frame& in, Spark_MAXMOTION_POSITION_SETPOINT_t* out) { return spark_decode_MAXMOTION_POSITION_SETPOINT(in.data, in.dlc, out); }

// Frame values for MAXMotion Velocity Setpoint: Sets the Control Type to MAXMotion Velocity Control and sets the target velocity
typedef struct {
    // Setpoint: By default, the unit is RPM, but it can be changed implicitly using the Velocity Conversion Factor parameter
    float SETPOINT;
    // Arbitrary Feedforward
    int16_t ARBITRARY_FEEDFORWARD;
    // PID Slot
    uint8_t PID_SLOT;
    // Arbitrary Feedforward Units: 0: Voltage, 1: Duty Cycle (-1 to 1)
    uint8_t ARBITRARY_FEEDFORWARD_UNITS;
} Spark_MAXMOTION_VELOCITY_SETPOINT_t;

// Decode frame payload for MAXMotion Velocity Setpoint: Sets the Control Type to MAXMotion Velocity Control and sets the target velocity
bool spark_decode_MAXMOTION_VELOCITY_SETPOINT(const uint8_t* data, uint8_t dlc, Spark_MAXMOTION_VELOCITY_SETPOINT_t* out);
static inline bool spark_decode_MAXMOTION_VELOCITY_SETPOINT_frame(const spark_can_frame& in, Spark_MAXMOTION_VELOCITY_SETPOINT_t* out) { return spark_decode_MAXMOTION_VELOCITY_SETPOINT(in.data, in.dlc, out); }

// Frame values for Set Statuses Enabled: Enable or disable status frames. In response, a Set Statuses Enabled Response frame will be sent.
typedef struct {
    // Mask
    uint16_t MASK;
    // Enabled Bitfield
    uint16_t ENABLED_BITFIELD;
} Spark_SET_STATUSES_ENABLED_t;

// Decode frame payload for Set Statuses Enabled: Enable or disable status frames. In response, a Set Statuses Enabled Response frame will be sent.
bool spark_decode_SET_STATUSES_ENABLED(const uint8_t* data, uint8_t dlc, Spark_SET_STATUSES_ENABLED_t* out);
static inline bool spark_decode_SET_STATUSES_ENABLED_frame(const spark_can_frame& in, Spark_SET_STATUSES_ENABLED_t* out) { return spark_decode_SET_STATUSES_ENABLED(in.data, in.dlc, out); }

// Frame values for Set Statuses Enabled Response: Response for a Set Statuses Enabled command
typedef struct {
    // Result Code: 0 on success, 1 if any non-existent or unavailable frames were specified to be enabled
    uint8_t RESULT_CODE;
    // Specified Mask: Contains the mask specified in the Set Statuses Enabled command that triggered this response
    uint16_t SPECIFIED_MASK;
    // Enabled Bitfield: Contains the full bitfield specifying which status frames are currently enabled, without any masking
    uint16_t ENABLED_BITFIELD;
} Spark_SET_STATUSES_ENABLED_RESPONSE_t;

// Decode frame payload for Set Statuses Enabled Response: Response for a Set Statuses Enabled command
bool spark_decode_SET_STATUSES_ENABLED_RESPONSE(const uint8_t* data, uint8_t dlc, Spark_SET_STATUSES_ENABLED_RESPONSE_t* out);
static inline bool spark_decode_SET_STATUSES_ENABLED_RESPONSE_frame(const spark_can_frame& in, Spark_SET_STATUSES_ENABLED_RESPONSE_t* out) { return spark_decode_SET_STATUSES_ENABLED_RESPONSE(in.data, in.dlc, out); }

// Frame values for Persist Parameters Response
typedef struct {
    // Result Code: 0 on success
    uint8_t RESULT_CODE;
} Spark_PERSIST_PARAMETERS_RESPONSE_t;

// Decode frame payload for Persist Parameters Response
bool spark_decode_PERSIST_PARAMETERS_RESPONSE(const uint8_t* data, uint8_t dlc, Spark_PERSIST_PARAMETERS_RESPONSE_t* out);
static inline bool spark_decode_PERSIST_PARAMETERS_RESPONSE_frame(const spark_can_frame& in, Spark_PERSIST_PARAMETERS_RESPONSE_t* out) { return spark_decode_PERSIST_PARAMETERS_RESPONSE(in.data, in.dlc, out); }

// Frame values for Reset Safe Parameters: Resets most writable parameters to their default values, except CAN ID, Motor Type, Idle Mode, PWM Input Deadband, and Duty Cycle Offset. In response, a Reset Safe Parameters Response frame is sent.
typedef struct {
    // Magic Number
    uint16_t MAGIC_NUMBER;
} Spark_RESET_SAFE_PARAMETERS_t;

// Decode frame payload for Reset Safe Parameters: Resets most writable parameters to their default values, except CAN ID, Motor Type, Idle Mode, PWM Input Deadband, and Duty Cycle Offset. In response, a Reset Safe Parameters Response frame is sent.
bool spark_decode_RESET_SAFE_PARAMETERS(const uint8_t* data, uint8_t dlc, Spark_RESET_SAFE_PARAMETERS_t* out);
static inline bool spark_decode_RESET_SAFE_PARAMETERS_frame(const spark_can_frame& in, Spark_RESET_SAFE_PARAMETERS_t* out) { return spark_decode_RESET_SAFE_PARAMETERS(in.data, in.dlc, out); }

// Frame values for Reset Safe Parameters Response: Response for a Reset Safe Parameters command
typedef struct {
    // Result Code: 0 on success
    uint8_t RESULT_CODE;
} Spark_RESET_SAFE_PARAMETERS_RESPONSE_t;

// Decode frame payload for Reset Safe Parameters Response: Response for a Reset Safe Parameters command
bool spark_decode_RESET_SAFE_PARAMETERS_RESPONSE(const uint8_t* data, uint8_t dlc, Spark_RESET_SAFE_PARAMETERS_RESPONSE_t* out);
static inline bool spark_decode_RESET_SAFE_PARAMETERS_RESPONSE_frame(const spark_can_frame& in, Spark_RESET_SAFE_PARAMETERS_RESPONSE_t* out) { return spark_decode_RESET_SAFE_PARAMETERS_RESPONSE(in.data, in.dlc, out); }

// Frame values for Complete Factory Reset: Resets all writable parameters to default values, even CAN ID, Motor Type, Idle Mode, PWM Input Deadband, and Duty Cycle Offset. In response, a Complete Factory Reset Response frame is sent.
typedef struct {
    // Magic Number
    uint16_t MAGIC_NUMBER;
} Spark_COMPLETE_FACTORY_RESET_t;

// Decode frame payload for Complete Factory Reset: Resets all writable parameters to default values, even CAN ID, Motor Type, Idle Mode, PWM Input Deadband, and Duty Cycle Offset. In response, a Complete Factory Reset Response frame is sent.
bool spark_decode_COMPLETE_FACTORY_RESET(const uint8_t* data, uint8_t dlc, Spark_COMPLETE_FACTORY_RESET_t* out);
static inline bool spark_decode_COMPLETE_FACTORY_RESET_frame(const spark_can_frame& in, Spark_COMPLETE_FACTORY_RESET_t* out) { return spark_decode_COMPLETE_FACTORY_RESET(in.data, in.dlc, out); }

// Frame values for Complete Factory Reset Response: Response for a Complete Factory Reset command
typedef struct {
    // Result Code: 0 on success
    uint8_t RESULT_CODE;
} Spark_COMPLETE_FACTORY_RESET_RESPONSE_t;

// Decode frame payload for Complete Factory Reset Response: Response for a Complete Factory Reset command
bool spark_decode_COMPLETE_FACTORY_RESET_RESPONSE(const uint8_t* data, uint8_t dlc, Spark_COMPLETE_FACTORY_RESET_RESPONSE_t* out);
static inline bool spark_decode_COMPLETE_FACTORY_RESET_RESPONSE_frame(const spark_can_frame& in, Spark_COMPLETE_FACTORY_RESET_RESPONSE_t* out) { return spark_decode_COMPLETE_FACTORY_RESET_RESPONSE(in.data, in.dlc, out); }

// Frame values for Clear Faults
typedef struct {
    uint8_t _reserved0; // no payload fields
} Spark_CLEAR_FAULTS_t;

// Frame values for Identify Unique SPARK: Makes the specified, single SPARK (even if there are multiple SPARKs that have the same CAN ID) temporarily perform a special blink pattern that will make it stand out
typedef struct {
    // Unique ID
    uint32_t UNIQUE_ID;
} Spark_IDENTIFY_UNIQUE_SPARK_t;

// Decode frame payload for Identify Unique SPARK: Makes the specified, single SPARK (even if there are multiple SPARKs that have the same CAN ID) temporarily perform a special blink pattern that will make it stand out
bool spark_decode_IDENTIFY_UNIQUE_SPARK(const uint8_t* data, uint8_t dlc, Spark_IDENTIFY_UNIQUE_SPARK_t* out);
static inline bool spark_decode_IDENTIFY_UNIQUE_SPARK_frame(const spark_can_frame& in, Spark_IDENTIFY_UNIQUE_SPARK_t* out) { return spark_decode_IDENTIFY_UNIQUE_SPARK(in.data, in.dlc, out); }

// Frame values for Identify: Makes the SPARK temporarily perform a special blink pattern that will make it stand out. Use Identify Unique Device if there may be multiple SPARKs with the same CAN ID.
typedef struct {
    uint8_t _reserved0; // no payload fields
} Spark_IDENTIFY_t;

// Frame values for Nack: As of SPARK MAX firmware 1.6.3, this is only used as a potential response to setting the CAN ID
typedef struct {
    uint8_t _reserved0; // no payload fields
} Spark_NACK_t;

// Frame values for Ack: As of SPARK MAX firmware 1.6.3, this is only used as a potential response to setting the CAN ID
typedef struct {
    uint8_t _reserved0; // no payload fields
} Spark_ACK_t;

// Frame values for LED Sync: Causes all SPARKs on the bus to synchronize their LED patterns
typedef struct {
    uint8_t _reserved0; // no payload fields
} Spark_LED_SYNC_t;

// Frame values for Set CAN ID: Allows changing the CAN ID when multiple devices on the bus currently have the same CAN ID. Under normal circumstances, the CAN ID parameter can be used.
typedef struct {
    // Unique ID
    uint32_t UNIQUE_ID;
    // CAN ID
    uint8_t CAN_ID;
} Spark_SET_CAN_ID_t;

// Decode frame payload for Set CAN ID: Allows changing the CAN ID when multiple devices on the bus currently have the same CAN ID. Under normal circumstances, the CAN ID parameter can be used.
bool spark_decode_SET_CAN_ID(const uint8_t* data, uint8_t dlc, Spark_SET_CAN_ID_t* out);
static inline bool spark_decode_SET_CAN_ID_frame(const spark_can_frame& in, Spark_SET_CAN_ID_t* out) { return spark_decode_SET_CAN_ID(in.data, in.dlc, out); }

// Frame values for Get Firmware Version
typedef struct {
    // Major
    uint8_t MAJOR;
    // Minor
    uint8_t MINOR;
    // Build
    uint16_t BUILD;
    // Debug Build
    uint8_t DEBUG_BUILD;
    // HW Rev
    uint8_t HW_REV;
} Spark_GET_FIRMWARE_VERSION_t;

// Decode frame payload for Get Firmware Version
bool spark_decode_GET_FIRMWARE_VERSION(const uint8_t* data, uint8_t dlc, Spark_GET_FIRMWARE_VERSION_t* out);
static inline bool spark_decode_GET_FIRMWARE_VERSION_frame(const spark_can_frame& in, Spark_GET_FIRMWARE_VERSION_t* out) { return spark_decode_GET_FIRMWARE_VERSION(in.data, in.dlc, out); }

// Frame values for SWDL Data: Broadcast from the host to all SPARKs in SWDL mode, containing a slice of firmware data
typedef struct {
    // Data
    uint64_t DATA;
} Spark_SWDL_DATA_t;

// Decode frame payload for SWDL Data: Broadcast from the host to all SPARKs in SWDL mode, containing a slice of firmware data
bool spark_decode_SWDL_DATA(const uint8_t* data, uint8_t dlc, Spark_SWDL_DATA_t* out);
static inline bool spark_decode_SWDL_DATA_frame(const spark_can_frame& in, Spark_SWDL_DATA_t* out) { return spark_decode_SWDL_DATA(in.data, in.dlc, out); }

// Frame values for SWDL Checksum: Broadcast from the host to all SPARKs in SWDL mode, containing the checksum of the full firmware image that was just sent
typedef struct {
    // Checksum
    uint64_t CHECKSUM;
} Spark_SWDL_CHECKSUM_t;

// Decode frame payload for SWDL Checksum: Broadcast from the host to all SPARKs in SWDL mode, containing the checksum of the full firmware image that was just sent
bool spark_decode_SWDL_CHECKSUM(const uint8_t* data, uint8_t dlc, Spark_SWDL_CHECKSUM_t* out);
static inline bool spark_decode_SWDL_CHECKSUM_frame(const spark_can_frame& in, Spark_SWDL_CHECKSUM_t* out) { return spark_decode_SWDL_CHECKSUM(in.data, in.dlc, out); }

// Frame values for SWDL Retransmit: Sent by SPARK devices in response to receiving an SWDL Checksum frame that does not match the firmware data they received
typedef struct {
    uint8_t _reserved0; // no payload fields
} Spark_SWDL_RETRANSMIT_t;

// Frame values for Set Primary Encoder Position
typedef struct {
    // Position: By default, the unit is rotations, but it can be changed implicitly using the Position Conversion Factor parameter
    float POSITION;
    // Data Type
    uint8_t DATA_TYPE;
} Spark_SET_PRIMARY_ENCODER_POSITION_t;

// Decode frame payload for Set Primary Encoder Position
bool spark_decode_SET_PRIMARY_ENCODER_POSITION(const uint8_t* data, uint8_t dlc, Spark_SET_PRIMARY_ENCODER_POSITION_t* out);
static inline bool spark_decode_SET_PRIMARY_ENCODER_POSITION_frame(const spark_can_frame& in, Spark_SET_PRIMARY_ENCODER_POSITION_t* out) { return spark_decode_SET_PRIMARY_ENCODER_POSITION(in.data, in.dlc, out); }

// Frame values for Set I Accumulation
typedef struct {
    // I Accumulation
    float I_ACCUMULATION;
    // Data Type
    uint8_t DATA_TYPE;
} Spark_SET_I_ACCUMULATION_t;

// Decode frame payload for Set I Accumulation
bool spark_decode_SET_I_ACCUMULATION(const uint8_t* data, uint8_t dlc, Spark_SET_I_ACCUMULATION_t* out);
static inline bool spark_decode_SET_I_ACCUMULATION_frame(const spark_can_frame& in, Spark_SET_I_ACCUMULATION_t* out) { return spark_decode_SET_I_ACCUMULATION(in.data, in.dlc, out); }

// Frame values for Set Analog Position
typedef struct {
    // Position: By default, the unit is rotations, but it can be changed implicitly using the Analog Position Conversion Factor parameter
    float POSITION;
    // Data Type
    uint8_t DATA_TYPE;
} Spark_SET_ANALOG_POSITION_t;

// Decode frame payload for Set Analog Position
bool spark_decode_SET_ANALOG_POSITION(const uint8_t* data, uint8_t dlc, Spark_SET_ANALOG_POSITION_t* out);
static inline bool spark_decode_SET_ANALOG_POSITION_frame(const spark_can_frame& in, Spark_SET_ANALOG_POSITION_t* out) { return spark_decode_SET_ANALOG_POSITION(in.data, in.dlc, out); }

// Frame values for Set Ext or Alt Encoder Position
typedef struct {
    // Position: By default, the unit is rotations, but it can be changed implicitly using the External/Alternate Encoder Position Conversion Factor parameter
    float POSITION;
    // Data Type
    uint8_t DATA_TYPE;
} Spark_SET_EXT_OR_ALT_ENCODER_POSITION_t;

// Decode frame payload for Set Ext or Alt Encoder Position
bool spark_decode_SET_EXT_OR_ALT_ENCODER_POSITION(const uint8_t* data, uint8_t dlc, Spark_SET_EXT_OR_ALT_ENCODER_POSITION_t* out);
static inline bool spark_decode_SET_EXT_OR_ALT_ENCODER_POSITION_frame(const spark_can_frame& in, Spark_SET_EXT_OR_ALT_ENCODER_POSITION_t* out) { return spark_decode_SET_EXT_OR_ALT_ENCODER_POSITION(in.data, in.dlc, out); }

// Frame values for Set Duty Cycle Position
typedef struct {
    // Position: By default, the unit is rotations, but it can be changed implicitly using the Duty Cycle Position Conversion Factor parameter
    float POSITION;
    // Data Type
    uint8_t DATA_TYPE;
} Spark_SET_DUTY_CYCLE_POSITION_t;

// Decode frame payload for Set Duty Cycle Position
bool spark_decode_SET_DUTY_CYCLE_POSITION(const uint8_t* data, uint8_t dlc, Spark_SET_DUTY_CYCLE_POSITION_t* out);
static inline bool spark_decode_SET_DUTY_CYCLE_POSITION_frame(const spark_can_frame& in, Spark_SET_DUTY_CYCLE_POSITION_t* out) { return spark_decode_SET_DUTY_CYCLE_POSITION(in.data, in.dlc, out); }

// Frame values for Secondary Heartbeat: Heartbeat that allows enabling only specific SPARKs, but only gets respected when the SPARK is not locked to the Universal Heartbeat or Primary Heartbeat
typedef struct {
    // Enabled SPARKs Bitfield
    uint64_t ENABLED_SPARKS_BITFIELD;
} Spark_SECONDARY_HEARTBEAT_t;

// Decode frame payload for Secondary Heartbeat: Heartbeat that allows enabling only specific SPARKs, but only gets respected when the SPARK is not locked to the Universal Heartbeat or Primary Heartbeat
bool spark_decode_SECONDARY_HEARTBEAT(const uint8_t* data, uint8_t dlc, Spark_SECONDARY_HEARTBEAT_t* out);
static inline bool spark_decode_SECONDARY_HEARTBEAT_frame(const spark_can_frame& in, Spark_SECONDARY_HEARTBEAT_t* out) { return spark_decode_SECONDARY_HEARTBEAT(in.data, in.dlc, out); }

// Frame values for USB Only Identify: The response will only be sent if this command is received directly via USB. This has no relation to the normal Identify command, which displays an LED pattern.
typedef struct {
    uint8_t _reserved0; // no payload fields
} Spark_USB_ONLY_IDENTIFY_t;

// Frame values for USB Only Enter DFU Bootloader: Causes the device to reboot into the DFU bootloader if this command is received directly via USB
typedef struct {
    // Magic Number
    uint16_t MAGIC_NUMBER;
} Spark_USB_ONLY_ENTER_DFU_BOOTLOADER_t;

// Decode frame payload for USB Only Enter DFU Bootloader: Causes the device to reboot into the DFU bootloader if this command is received directly via USB
bool spark_decode_USB_ONLY_ENTER_DFU_BOOTLOADER(const uint8_t* data, uint8_t dlc, Spark_USB_ONLY_ENTER_DFU_BOOTLOADER_t* out);
static inline bool spark_decode_USB_ONLY_ENTER_DFU_BOOTLOADER_frame(const spark_can_frame& in, Spark_USB_ONLY_ENTER_DFU_BOOTLOADER_t* out) { return spark_decode_USB_ONLY_ENTER_DFU_BOOTLOADER(in.data, in.dlc, out); }

// Frame values for Get Temperatures
typedef struct {
    // Motor Temperature
    uint8_t MOTOR_TEMPERATURE;
    // Microcontroller Temperature
    uint8_t MICROCONTROLLER_TEMPERATURE;
    // FET Temperature
    uint8_t FET_TEMPERATURE;
    // Motor Temperature 2
    uint8_t MOTOR_TEMPERATURE_2;
    // Dock Temperature
    uint8_t DOCK_TEMPERATURE;
    // Valid Temperatures Bitmask: Each bit corresponds to one of the 7 temperature fields
    uint8_t VALID_TEMPERATURES_BITMASK;
    // Unused
    uint8_t UNUSED;
} Spark_GET_TEMPERATURES_t;

// Decode frame payload for Get Temperatures
bool spark_decode_GET_TEMPERATURES(const uint8_t* data, uint8_t dlc, Spark_GET_TEMPERATURES_t* out);
static inline bool spark_decode_GET_TEMPERATURES_frame(const spark_can_frame& in, Spark_GET_TEMPERATURES_t* out) { return spark_decode_GET_TEMPERATURES(in.data, in.dlc, out); }

// Frame values for Get Motor Interface
typedef struct {
    // Motor Interface: 0: None, 1: SPARK Flex Dock / SPARK MAX, 2: SPARK Flex standard motor interface
    uint16_t MOTOR_INTERFACE;
    // Primary Sensor Type: 0: UVW, 1: Quadrature, 2: Quadrature (integrated)
    uint8_t PRIMARY_SENSOR_TYPE;
} Spark_GET_MOTOR_INTERFACE_t;

// Decode frame payload for Get Motor Interface
bool spark_decode_GET_MOTOR_INTERFACE(const uint8_t* data, uint8_t dlc, Spark_GET_MOTOR_INTERFACE_t* out);
static inline bool spark_decode_GET_MOTOR_INTERFACE_frame(const spark_can_frame& in, Spark_GET_MOTOR_INTERFACE_t* out) { return spark_decode_GET_MOTOR_INTERFACE(in.data, in.dlc, out); }

// Frame values for Get Parameter 0 to 15 Types: Get types of parameters 0 to 15
typedef struct {
    // Type 0: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_0;
    // Type 1: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_1;
    // Type 2: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_2;
    // Type 3: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_3;
    // Type 4: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_4;
    // Type 5: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_5;
    // Type 6: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_6;
    // Type 7: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_7;
    // Type 8: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_8;
    // Type 9: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_9;
    // Type 10: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_10;
    // Type 11: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_11;
    // Type 12: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_12;
    // Type 13: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_13;
    // Type 14: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_14;
    // Type 15: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_15;
} Spark_GET_PARAMETER_0_TO_15_TYPES_t;

// Decode frame payload for Get Parameter 0 to 15 Types: Get types of parameters 0 to 15
bool spark_decode_GET_PARAMETER_0_TO_15_TYPES(const uint8_t* data, uint8_t dlc, Spark_GET_PARAMETER_0_TO_15_TYPES_t* out);
static inline bool spark_decode_GET_PARAMETER_0_TO_15_TYPES_frame(const spark_can_frame& in, Spark_GET_PARAMETER_0_TO_15_TYPES_t* out) { return spark_decode_GET_PARAMETER_0_TO_15_TYPES(in.data, in.dlc, out); }

// Frame values for Get Parameter 16 to 31 Types: Get types of parameters 16 to 31
typedef struct {
    // Type 0: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_0;
    // Type 1: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_1;
    // Type 2: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_2;
    // Type 3: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_3;
    // Type 4: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_4;
    // Type 5: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_5;
    // Type 6: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_6;
    // Type 7: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_7;
    // Type 8: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_8;
    // Type 9: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_9;
    // Type 10: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_10;
    // Type 11: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_11;
    // Type 12: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_12;
    // Type 13: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_13;
    // Type 14: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_14;
    // Type 15: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_15;
} Spark_GET_PARAMETER_16_TO_31_TYPES_t;

// Decode frame payload for Get Parameter 16 to 31 Types: Get types of parameters 16 to 31
bool spark_decode_GET_PARAMETER_16_TO_31_TYPES(const uint8_t* data, uint8_t dlc, Spark_GET_PARAMETER_16_TO_31_TYPES_t* out);
static inline bool spark_decode_GET_PARAMETER_16_TO_31_TYPES_frame(const spark_can_frame& in, Spark_GET_PARAMETER_16_TO_31_TYPES_t* out) { return spark_decode_GET_PARAMETER_16_TO_31_TYPES(in.data, in.dlc, out); }

// Frame values for Get Parameter 32 to 47 Types: Get types of parameters 32 to 47
typedef struct {
    // Type 0: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_0;
    // Type 1: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_1;
    // Type 2: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_2;
    // Type 3: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_3;
    // Type 4: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_4;
    // Type 5: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_5;
    // Type 6: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_6;
    // Type 7: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_7;
    // Type 8: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_8;
    // Type 9: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_9;
    // Type 10: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_10;
    // Type 11: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_11;
    // Type 12: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_12;
    // Type 13: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_13;
    // Type 14: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_14;
    // Type 15: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_15;
} Spark_GET_PARAMETER_32_TO_47_TYPES_t;

// Decode frame payload for Get Parameter 32 to 47 Types: Get types of parameters 32 to 47
bool spark_decode_GET_PARAMETER_32_TO_47_TYPES(const uint8_t* data, uint8_t dlc, Spark_GET_PARAMETER_32_TO_47_TYPES_t* out);
static inline bool spark_decode_GET_PARAMETER_32_TO_47_TYPES_frame(const spark_can_frame& in, Spark_GET_PARAMETER_32_TO_47_TYPES_t* out) { return spark_decode_GET_PARAMETER_32_TO_47_TYPES(in.data, in.dlc, out); }

// Frame values for Get Parameter 48 to 63 Types: Get types of parameters 48 to 63
typedef struct {
    // Type 0: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_0;
    // Type 1: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_1;
    // Type 2: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_2;
    // Type 3: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_3;
    // Type 4: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_4;
    // Type 5: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_5;
    // Type 6: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_6;
    // Type 7: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_7;
    // Type 8: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_8;
    // Type 9: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_9;
    // Type 10: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_10;
    // Type 11: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_11;
    // Type 12: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_12;
    // Type 13: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_13;
    // Type 14: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_14;
    // Type 15: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_15;
} Spark_GET_PARAMETER_48_TO_63_TYPES_t;

// Decode frame payload for Get Parameter 48 to 63 Types: Get types of parameters 48 to 63
bool spark_decode_GET_PARAMETER_48_TO_63_TYPES(const uint8_t* data, uint8_t dlc, Spark_GET_PARAMETER_48_TO_63_TYPES_t* out);
static inline bool spark_decode_GET_PARAMETER_48_TO_63_TYPES_frame(const spark_can_frame& in, Spark_GET_PARAMETER_48_TO_63_TYPES_t* out) { return spark_decode_GET_PARAMETER_48_TO_63_TYPES(in.data, in.dlc, out); }

// Frame values for Get Parameter 64 to 79 Types: Get types of parameters 64 to 79
typedef struct {
    // Type 0: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_0;
    // Type 1: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_1;
    // Type 2: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_2;
    // Type 3: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_3;
    // Type 4: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_4;
    // Type 5: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_5;
    // Type 6: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_6;
    // Type 7: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_7;
    // Type 8: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_8;
    // Type 9: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_9;
    // Type 10: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_10;
    // Type 11: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_11;
    // Type 12: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_12;
    // Type 13: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_13;
    // Type 14: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_14;
    // Type 15: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_15;
} Spark_GET_PARAMETER_64_TO_79_TYPES_t;

// Decode frame payload for Get Parameter 64 to 79 Types: Get types of parameters 64 to 79
bool spark_decode_GET_PARAMETER_64_TO_79_TYPES(const uint8_t* data, uint8_t dlc, Spark_GET_PARAMETER_64_TO_79_TYPES_t* out);
static inline bool spark_decode_GET_PARAMETER_64_TO_79_TYPES_frame(const spark_can_frame& in, Spark_GET_PARAMETER_64_TO_79_TYPES_t* out) { return spark_decode_GET_PARAMETER_64_TO_79_TYPES(in.data, in.dlc, out); }

// Frame values for Get Parameter 80 to 95 Types: Get types of parameters 80 to 95
typedef struct {
    // Type 0: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_0;
    // Type 1: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_1;
    // Type 2: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_2;
    // Type 3: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_3;
    // Type 4: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_4;
    // Type 5: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_5;
    // Type 6: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_6;
    // Type 7: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_7;
    // Type 8: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_8;
    // Type 9: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_9;
    // Type 10: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_10;
    // Type 11: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_11;
    // Type 12: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_12;
    // Type 13: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_13;
    // Type 14: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_14;
    // Type 15: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_15;
} Spark_GET_PARAMETER_80_TO_95_TYPES_t;

// Decode frame payload for Get Parameter 80 to 95 Types: Get types of parameters 80 to 95
bool spark_decode_GET_PARAMETER_80_TO_95_TYPES(const uint8_t* data, uint8_t dlc, Spark_GET_PARAMETER_80_TO_95_TYPES_t* out);
static inline bool spark_decode_GET_PARAMETER_80_TO_95_TYPES_frame(const spark_can_frame& in, Spark_GET_PARAMETER_80_TO_95_TYPES_t* out) { return spark_decode_GET_PARAMETER_80_TO_95_TYPES(in.data, in.dlc, out); }

// Frame values for Get Parameter 96 to 111 Types: Get types of parameters 96 to 111
typedef struct {
    // Type 0: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_0;
    // Type 1: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_1;
    // Type 2: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_2;
    // Type 3: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_3;
    // Type 4: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_4;
    // Type 5: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_5;
    // Type 6: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_6;
    // Type 7: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_7;
    // Type 8: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_8;
    // Type 9: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_9;
    // Type 10: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_10;
    // Type 11: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_11;
    // Type 12: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_12;
    // Type 13: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_13;
    // Type 14: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_14;
    // Type 15: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_15;
} Spark_GET_PARAMETER_96_TO_111_TYPES_t;

// Decode frame payload for Get Parameter 96 to 111 Types: Get types of parameters 96 to 111
bool spark_decode_GET_PARAMETER_96_TO_111_TYPES(const uint8_t* data, uint8_t dlc, Spark_GET_PARAMETER_96_TO_111_TYPES_t* out);
static inline bool spark_decode_GET_PARAMETER_96_TO_111_TYPES_frame(const spark_can_frame& in, Spark_GET_PARAMETER_96_TO_111_TYPES_t* out) { return spark_decode_GET_PARAMETER_96_TO_111_TYPES(in.data, in.dlc, out); }

// Frame values for Get Parameter 112 to 127 Types: Get types of parameters 112 to 127
typedef struct {
    // Type 0: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_0;
    // Type 1: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_1;
    // Type 2: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_2;
    // Type 3: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_3;
    // Type 4: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_4;
    // Type 5: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_5;
    // Type 6: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_6;
    // Type 7: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_7;
    // Type 8: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_8;
    // Type 9: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_9;
    // Type 10: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_10;
    // Type 11: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_11;
    // Type 12: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_12;
    // Type 13: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_13;
    // Type 14: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_14;
    // Type 15: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_15;
} Spark_GET_PARAMETER_112_TO_127_TYPES_t;

// Decode frame payload for Get Parameter 112 to 127 Types: Get types of parameters 112 to 127
bool spark_decode_GET_PARAMETER_112_TO_127_TYPES(const uint8_t* data, uint8_t dlc, Spark_GET_PARAMETER_112_TO_127_TYPES_t* out);
static inline bool spark_decode_GET_PARAMETER_112_TO_127_TYPES_frame(const spark_can_frame& in, Spark_GET_PARAMETER_112_TO_127_TYPES_t* out) { return spark_decode_GET_PARAMETER_112_TO_127_TYPES(in.data, in.dlc, out); }

// Frame values for Get Parameter 128 to 143 Types: Get types of parameters 128 to 143
typedef struct {
    // Type 0: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_0;
    // Type 1: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_1;
    // Type 2: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_2;
    // Type 3: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_3;
    // Type 4: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_4;
    // Type 5: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_5;
    // Type 6: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_6;
    // Type 7: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_7;
    // Type 8: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_8;
    // Type 9: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_9;
    // Type 10: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_10;
    // Type 11: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_11;
    // Type 12: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_12;
    // Type 13: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_13;
    // Type 14: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_14;
    // Type 15: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_15;
} Spark_GET_PARAMETER_128_TO_143_TYPES_t;

// Decode frame payload for Get Parameter 128 to 143 Types: Get types of parameters 128 to 143
bool spark_decode_GET_PARAMETER_128_TO_143_TYPES(const uint8_t* data, uint8_t dlc, Spark_GET_PARAMETER_128_TO_143_TYPES_t* out);
static inline bool spark_decode_GET_PARAMETER_128_TO_143_TYPES_frame(const spark_can_frame& in, Spark_GET_PARAMETER_128_TO_143_TYPES_t* out) { return spark_decode_GET_PARAMETER_128_TO_143_TYPES(in.data, in.dlc, out); }

// Frame values for Get Parameter 144 to 159 Types: Get types of parameters 144 to 159
typedef struct {
    // Type 0: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_0;
    // Type 1: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_1;
    // Type 2: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_2;
    // Type 3: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_3;
    // Type 4: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_4;
    // Type 5: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_5;
    // Type 6: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_6;
    // Type 7: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_7;
    // Type 8: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_8;
    // Type 9: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_9;
    // Type 10: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_10;
    // Type 11: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_11;
    // Type 12: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_12;
    // Type 13: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_13;
    // Type 14: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_14;
    // Type 15: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_15;
} Spark_GET_PARAMETER_144_TO_159_TYPES_t;

// Decode frame payload for Get Parameter 144 to 159 Types: Get types of parameters 144 to 159
bool spark_decode_GET_PARAMETER_144_TO_159_TYPES(const uint8_t* data, uint8_t dlc, Spark_GET_PARAMETER_144_TO_159_TYPES_t* out);
static inline bool spark_decode_GET_PARAMETER_144_TO_159_TYPES_frame(const spark_can_frame& in, Spark_GET_PARAMETER_144_TO_159_TYPES_t* out) { return spark_decode_GET_PARAMETER_144_TO_159_TYPES(in.data, in.dlc, out); }

// Frame values for Get Parameter 160 to 175 Types: Get types of parameters 160 to 175
typedef struct {
    // Type 0: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_0;
    // Type 1: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_1;
    // Type 2: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_2;
    // Type 3: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_3;
    // Type 4: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_4;
    // Type 5: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_5;
    // Type 6: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_6;
    // Type 7: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_7;
    // Type 8: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_8;
    // Type 9: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_9;
    // Type 10: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_10;
    // Type 11: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_11;
    // Type 12: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_12;
    // Type 13: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_13;
    // Type 14: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_14;
    // Type 15: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_15;
} Spark_GET_PARAMETER_160_TO_175_TYPES_t;

// Decode frame payload for Get Parameter 160 to 175 Types: Get types of parameters 160 to 175
bool spark_decode_GET_PARAMETER_160_TO_175_TYPES(const uint8_t* data, uint8_t dlc, Spark_GET_PARAMETER_160_TO_175_TYPES_t* out);
static inline bool spark_decode_GET_PARAMETER_160_TO_175_TYPES_frame(const spark_can_frame& in, Spark_GET_PARAMETER_160_TO_175_TYPES_t* out) { return spark_decode_GET_PARAMETER_160_TO_175_TYPES(in.data, in.dlc, out); }

// Frame values for Get Parameter 176 to 191 Types: Get types of parameters 176 to 191
typedef struct {
    // Type 0: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_0;
    // Type 1: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_1;
    // Type 2: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_2;
    // Type 3: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_3;
    // Type 4: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_4;
    // Type 5: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_5;
    // Type 6: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_6;
    // Type 7: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_7;
    // Type 8: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_8;
    // Type 9: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_9;
    // Type 10: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_10;
    // Type 11: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_11;
    // Type 12: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_12;
    // Type 13: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_13;
    // Type 14: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_14;
    // Type 15: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_15;
} Spark_GET_PARAMETER_176_TO_191_TYPES_t;

// Decode frame payload for Get Parameter 176 to 191 Types: Get types of parameters 176 to 191
bool spark_decode_GET_PARAMETER_176_TO_191_TYPES(const uint8_t* data, uint8_t dlc, Spark_GET_PARAMETER_176_TO_191_TYPES_t* out);
static inline bool spark_decode_GET_PARAMETER_176_TO_191_TYPES_frame(const spark_can_frame& in, Spark_GET_PARAMETER_176_TO_191_TYPES_t* out) { return spark_decode_GET_PARAMETER_176_TO_191_TYPES(in.data, in.dlc, out); }

// Frame values for Get Parameter 192 to 207 Types: Get types of parameters 192 to 207
typedef struct {
    // Type 0: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_0;
    // Type 1: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_1;
    // Type 2: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_2;
    // Type 3: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_3;
    // Type 4: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_4;
    // Type 5: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_5;
    // Type 6: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_6;
    // Type 7: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_7;
    // Type 8: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_8;
    // Type 9: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_9;
    // Type 10: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_10;
    // Type 11: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_11;
    // Type 12: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_12;
    // Type 13: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_13;
    // Type 14: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_14;
    // Type 15: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_15;
} Spark_GET_PARAMETER_192_TO_207_TYPES_t;

// Decode frame payload for Get Parameter 192 to 207 Types: Get types of parameters 192 to 207
bool spark_decode_GET_PARAMETER_192_TO_207_TYPES(const uint8_t* data, uint8_t dlc, Spark_GET_PARAMETER_192_TO_207_TYPES_t* out);
static inline bool spark_decode_GET_PARAMETER_192_TO_207_TYPES_frame(const spark_can_frame& in, Spark_GET_PARAMETER_192_TO_207_TYPES_t* out) { return spark_decode_GET_PARAMETER_192_TO_207_TYPES(in.data, in.dlc, out); }

// Frame values for Get Parameter 208 to 223 Types: Get types of parameters 208 to 223
typedef struct {
    // Type 0: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_0;
    // Type 1: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_1;
    // Type 2: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_2;
    // Type 3: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_3;
    // Type 4: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_4;
    // Type 5: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_5;
    // Type 6: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_6;
    // Type 7: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_7;
    // Type 8: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_8;
    // Type 9: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_9;
    // Type 10: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_10;
    // Type 11: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_11;
    // Type 12: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_12;
    // Type 13: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_13;
    // Type 14: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_14;
    // Type 15: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_15;
} Spark_GET_PARAMETER_208_TO_223_TYPES_t;

// Decode frame payload for Get Parameter 208 to 223 Types: Get types of parameters 208 to 223
bool spark_decode_GET_PARAMETER_208_TO_223_TYPES(const uint8_t* data, uint8_t dlc, Spark_GET_PARAMETER_208_TO_223_TYPES_t* out);
static inline bool spark_decode_GET_PARAMETER_208_TO_223_TYPES_frame(const spark_can_frame& in, Spark_GET_PARAMETER_208_TO_223_TYPES_t* out) { return spark_decode_GET_PARAMETER_208_TO_223_TYPES(in.data, in.dlc, out); }

// Frame values for Get Parameter 224 to 239 Types: Get types of parameters 224 to 239
typedef struct {
    // Type 0: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_0;
    // Type 1: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_1;
    // Type 2: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_2;
    // Type 3: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_3;
    // Type 4: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_4;
    // Type 5: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_5;
    // Type 6: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_6;
    // Type 7: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_7;
    // Type 8: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_8;
    // Type 9: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_9;
    // Type 10: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_10;
    // Type 11: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_11;
    // Type 12: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_12;
    // Type 13: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_13;
    // Type 14: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_14;
    // Type 15: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_15;
} Spark_GET_PARAMETER_224_TO_239_TYPES_t;

// Decode frame payload for Get Parameter 224 to 239 Types: Get types of parameters 224 to 239
bool spark_decode_GET_PARAMETER_224_TO_239_TYPES(const uint8_t* data, uint8_t dlc, Spark_GET_PARAMETER_224_TO_239_TYPES_t* out);
static inline bool spark_decode_GET_PARAMETER_224_TO_239_TYPES_frame(const spark_can_frame& in, Spark_GET_PARAMETER_224_TO_239_TYPES_t* out) { return spark_decode_GET_PARAMETER_224_TO_239_TYPES(in.data, in.dlc, out); }

// Frame values for Get Parameter 240 to 255 Types: Get types of parameters 240 to 255
typedef struct {
    // Type 0: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_0;
    // Type 1: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_1;
    // Type 2: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_2;
    // Type 3: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_3;
    // Type 4: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_4;
    // Type 5: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_5;
    // Type 6: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_6;
    // Type 7: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_7;
    // Type 8: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_8;
    // Type 9: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_9;
    // Type 10: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_10;
    // Type 11: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_11;
    // Type 12: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_12;
    // Type 13: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_13;
    // Type 14: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_14;
    // Type 15: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t TYPE_15;
} Spark_GET_PARAMETER_240_TO_255_TYPES_t;

// Decode frame payload for Get Parameter 240 to 255 Types: Get types of parameters 240 to 255
bool spark_decode_GET_PARAMETER_240_TO_255_TYPES(const uint8_t* data, uint8_t dlc, Spark_GET_PARAMETER_240_TO_255_TYPES_t* out);
static inline bool spark_decode_GET_PARAMETER_240_TO_255_TYPES_frame(const spark_can_frame& in, Spark_GET_PARAMETER_240_TO_255_TYPES_t* out) { return spark_decode_GET_PARAMETER_240_TO_255_TYPES(in.data, in.dlc, out); }

// Frame values for Parameter Write: Write a single parameter value. In response, a Parameter Write Response frame will be sent.
typedef struct {
    // Parameter ID
    uint8_t PARAMETER_ID;
    // Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t VALUE;
} Spark_PARAMETER_WRITE_t;

// Decode frame payload for Parameter Write: Write a single parameter value. In response, a Parameter Write Response frame will be sent.
bool spark_decode_PARAMETER_WRITE(const uint8_t* data, uint8_t dlc, Spark_PARAMETER_WRITE_t* out);
static inline bool spark_decode_PARAMETER_WRITE_frame(const spark_can_frame& in, Spark_PARAMETER_WRITE_t* out) { return spark_decode_PARAMETER_WRITE(in.data, in.dlc, out); }

// Frame values for Parameter Write Response: Response for a parameter write (including a write done as part of a dual-write)
typedef struct {
    // Parameter ID
    uint8_t PARAMETER_ID;
    // Parameter Type: 0: Unused, 1: Int, 2: Uint, 3: Float, 4: Boolean
    uint8_t PARAMETER_TYPE;
    // Value: The actual type of this field is specified by the Parameter Type field. Contains the current value of the parameter, which will not match what was specified in the write command if the write failed.
    uint32_t VALUE;
    // Result Code: 0: Success, 1: Invalid ID, 2: Mismatched Type, 3: Access Mode, 4: Invalid, 5: Not Implemented
    uint8_t RESULT_CODE;
} Spark_PARAMETER_WRITE_RESPONSE_t;

// Decode frame payload for Parameter Write Response: Response for a parameter write (including a write done as part of a dual-write)
bool spark_decode_PARAMETER_WRITE_RESPONSE(const uint8_t* data, uint8_t dlc, Spark_PARAMETER_WRITE_RESPONSE_t* out);
static inline bool spark_decode_PARAMETER_WRITE_RESPONSE_frame(const spark_can_frame& in, Spark_PARAMETER_WRITE_RESPONSE_t* out) { return spark_decode_PARAMETER_WRITE_RESPONSE(in.data, in.dlc, out); }

// Frame values for Read Parameter 0 and 1: Read parameter 0 and 1 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_0_AND_1_t;

// Decode frame payload for Read Parameter 0 and 1: Read parameter 0 and 1 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_0_AND_1(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_0_AND_1_t* out);
static inline bool spark_decode_READ_PARAMETER_0_AND_1_frame(const spark_can_frame& in, Spark_READ_PARAMETER_0_AND_1_t* out) { return spark_decode_READ_PARAMETER_0_AND_1(in.data, in.dlc, out); }

// Frame values for Read Parameter 2 and 3: Read parameter 2 and 3 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_2_AND_3_t;

// Decode frame payload for Read Parameter 2 and 3: Read parameter 2 and 3 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_2_AND_3(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_2_AND_3_t* out);
static inline bool spark_decode_READ_PARAMETER_2_AND_3_frame(const spark_can_frame& in, Spark_READ_PARAMETER_2_AND_3_t* out) { return spark_decode_READ_PARAMETER_2_AND_3(in.data, in.dlc, out); }

// Frame values for Read Parameter 4 and 5: Read parameter 4 and 5 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_4_AND_5_t;

// Decode frame payload for Read Parameter 4 and 5: Read parameter 4 and 5 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_4_AND_5(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_4_AND_5_t* out);
static inline bool spark_decode_READ_PARAMETER_4_AND_5_frame(const spark_can_frame& in, Spark_READ_PARAMETER_4_AND_5_t* out) { return spark_decode_READ_PARAMETER_4_AND_5(in.data, in.dlc, out); }

// Frame values for Read Parameter 6 and 7: Read parameter 6 and 7 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_6_AND_7_t;

// Decode frame payload for Read Parameter 6 and 7: Read parameter 6 and 7 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_6_AND_7(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_6_AND_7_t* out);
static inline bool spark_decode_READ_PARAMETER_6_AND_7_frame(const spark_can_frame& in, Spark_READ_PARAMETER_6_AND_7_t* out) { return spark_decode_READ_PARAMETER_6_AND_7(in.data, in.dlc, out); }

// Frame values for Read Parameter 8 and 9: Read parameter 8 and 9 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_8_AND_9_t;

// Decode frame payload for Read Parameter 8 and 9: Read parameter 8 and 9 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_8_AND_9(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_8_AND_9_t* out);
static inline bool spark_decode_READ_PARAMETER_8_AND_9_frame(const spark_can_frame& in, Spark_READ_PARAMETER_8_AND_9_t* out) { return spark_decode_READ_PARAMETER_8_AND_9(in.data, in.dlc, out); }

// Frame values for Read Parameter 10 and 11: Read parameter 10 and 11 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_10_AND_11_t;

// Decode frame payload for Read Parameter 10 and 11: Read parameter 10 and 11 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_10_AND_11(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_10_AND_11_t* out);
static inline bool spark_decode_READ_PARAMETER_10_AND_11_frame(const spark_can_frame& in, Spark_READ_PARAMETER_10_AND_11_t* out) { return spark_decode_READ_PARAMETER_10_AND_11(in.data, in.dlc, out); }

// Frame values for Read Parameter 12 and 13: Read parameter 12 and 13 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_12_AND_13_t;

// Decode frame payload for Read Parameter 12 and 13: Read parameter 12 and 13 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_12_AND_13(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_12_AND_13_t* out);
static inline bool spark_decode_READ_PARAMETER_12_AND_13_frame(const spark_can_frame& in, Spark_READ_PARAMETER_12_AND_13_t* out) { return spark_decode_READ_PARAMETER_12_AND_13(in.data, in.dlc, out); }

// Frame values for Read Parameter 14 and 15: Read parameter 14 and 15 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_14_AND_15_t;

// Decode frame payload for Read Parameter 14 and 15: Read parameter 14 and 15 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_14_AND_15(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_14_AND_15_t* out);
static inline bool spark_decode_READ_PARAMETER_14_AND_15_frame(const spark_can_frame& in, Spark_READ_PARAMETER_14_AND_15_t* out) { return spark_decode_READ_PARAMETER_14_AND_15(in.data, in.dlc, out); }

// Frame values for Read Parameter 16 and 17: Read parameter 16 and 17 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_16_AND_17_t;

// Decode frame payload for Read Parameter 16 and 17: Read parameter 16 and 17 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_16_AND_17(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_16_AND_17_t* out);
static inline bool spark_decode_READ_PARAMETER_16_AND_17_frame(const spark_can_frame& in, Spark_READ_PARAMETER_16_AND_17_t* out) { return spark_decode_READ_PARAMETER_16_AND_17(in.data, in.dlc, out); }

// Frame values for Read Parameter 18 and 19: Read parameter 18 and 19 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_18_AND_19_t;

// Decode frame payload for Read Parameter 18 and 19: Read parameter 18 and 19 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_18_AND_19(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_18_AND_19_t* out);
static inline bool spark_decode_READ_PARAMETER_18_AND_19_frame(const spark_can_frame& in, Spark_READ_PARAMETER_18_AND_19_t* out) { return spark_decode_READ_PARAMETER_18_AND_19(in.data, in.dlc, out); }

// Frame values for Read Parameter 20 and 21: Read parameter 20 and 21 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_20_AND_21_t;

// Decode frame payload for Read Parameter 20 and 21: Read parameter 20 and 21 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_20_AND_21(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_20_AND_21_t* out);
static inline bool spark_decode_READ_PARAMETER_20_AND_21_frame(const spark_can_frame& in, Spark_READ_PARAMETER_20_AND_21_t* out) { return spark_decode_READ_PARAMETER_20_AND_21(in.data, in.dlc, out); }

// Frame values for Read Parameter 22 and 23: Read parameter 22 and 23 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_22_AND_23_t;

// Decode frame payload for Read Parameter 22 and 23: Read parameter 22 and 23 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_22_AND_23(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_22_AND_23_t* out);
static inline bool spark_decode_READ_PARAMETER_22_AND_23_frame(const spark_can_frame& in, Spark_READ_PARAMETER_22_AND_23_t* out) { return spark_decode_READ_PARAMETER_22_AND_23(in.data, in.dlc, out); }

// Frame values for Read Parameter 24 and 25: Read parameter 24 and 25 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_24_AND_25_t;

// Decode frame payload for Read Parameter 24 and 25: Read parameter 24 and 25 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_24_AND_25(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_24_AND_25_t* out);
static inline bool spark_decode_READ_PARAMETER_24_AND_25_frame(const spark_can_frame& in, Spark_READ_PARAMETER_24_AND_25_t* out) { return spark_decode_READ_PARAMETER_24_AND_25(in.data, in.dlc, out); }

// Frame values for Read Parameter 26 and 27: Read parameter 26 and 27 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_26_AND_27_t;

// Decode frame payload for Read Parameter 26 and 27: Read parameter 26 and 27 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_26_AND_27(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_26_AND_27_t* out);
static inline bool spark_decode_READ_PARAMETER_26_AND_27_frame(const spark_can_frame& in, Spark_READ_PARAMETER_26_AND_27_t* out) { return spark_decode_READ_PARAMETER_26_AND_27(in.data, in.dlc, out); }

// Frame values for Read Parameter 28 and 29: Read parameter 28 and 29 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_28_AND_29_t;

// Decode frame payload for Read Parameter 28 and 29: Read parameter 28 and 29 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_28_AND_29(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_28_AND_29_t* out);
static inline bool spark_decode_READ_PARAMETER_28_AND_29_frame(const spark_can_frame& in, Spark_READ_PARAMETER_28_AND_29_t* out) { return spark_decode_READ_PARAMETER_28_AND_29(in.data, in.dlc, out); }

// Frame values for Read Parameter 30 and 31: Read parameter 30 and 31 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_30_AND_31_t;

// Decode frame payload for Read Parameter 30 and 31: Read parameter 30 and 31 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_30_AND_31(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_30_AND_31_t* out);
static inline bool spark_decode_READ_PARAMETER_30_AND_31_frame(const spark_can_frame& in, Spark_READ_PARAMETER_30_AND_31_t* out) { return spark_decode_READ_PARAMETER_30_AND_31(in.data, in.dlc, out); }

// Frame values for Read Parameter 32 and 33: Read parameter 32 and 33 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_32_AND_33_t;

// Decode frame payload for Read Parameter 32 and 33: Read parameter 32 and 33 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_32_AND_33(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_32_AND_33_t* out);
static inline bool spark_decode_READ_PARAMETER_32_AND_33_frame(const spark_can_frame& in, Spark_READ_PARAMETER_32_AND_33_t* out) { return spark_decode_READ_PARAMETER_32_AND_33(in.data, in.dlc, out); }

// Frame values for Read Parameter 34 and 35: Read parameter 34 and 35 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_34_AND_35_t;

// Decode frame payload for Read Parameter 34 and 35: Read parameter 34 and 35 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_34_AND_35(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_34_AND_35_t* out);
static inline bool spark_decode_READ_PARAMETER_34_AND_35_frame(const spark_can_frame& in, Spark_READ_PARAMETER_34_AND_35_t* out) { return spark_decode_READ_PARAMETER_34_AND_35(in.data, in.dlc, out); }

// Frame values for Read Parameter 36 and 37: Read parameter 36 and 37 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_36_AND_37_t;

// Decode frame payload for Read Parameter 36 and 37: Read parameter 36 and 37 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_36_AND_37(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_36_AND_37_t* out);
static inline bool spark_decode_READ_PARAMETER_36_AND_37_frame(const spark_can_frame& in, Spark_READ_PARAMETER_36_AND_37_t* out) { return spark_decode_READ_PARAMETER_36_AND_37(in.data, in.dlc, out); }

// Frame values for Read Parameter 38 and 39: Read parameter 38 and 39 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_38_AND_39_t;

// Decode frame payload for Read Parameter 38 and 39: Read parameter 38 and 39 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_38_AND_39(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_38_AND_39_t* out);
static inline bool spark_decode_READ_PARAMETER_38_AND_39_frame(const spark_can_frame& in, Spark_READ_PARAMETER_38_AND_39_t* out) { return spark_decode_READ_PARAMETER_38_AND_39(in.data, in.dlc, out); }

// Frame values for Read Parameter 40 and 41: Read parameter 40 and 41 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_40_AND_41_t;

// Decode frame payload for Read Parameter 40 and 41: Read parameter 40 and 41 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_40_AND_41(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_40_AND_41_t* out);
static inline bool spark_decode_READ_PARAMETER_40_AND_41_frame(const spark_can_frame& in, Spark_READ_PARAMETER_40_AND_41_t* out) { return spark_decode_READ_PARAMETER_40_AND_41(in.data, in.dlc, out); }

// Frame values for Read Parameter 42 and 43: Read parameter 42 and 43 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_42_AND_43_t;

// Decode frame payload for Read Parameter 42 and 43: Read parameter 42 and 43 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_42_AND_43(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_42_AND_43_t* out);
static inline bool spark_decode_READ_PARAMETER_42_AND_43_frame(const spark_can_frame& in, Spark_READ_PARAMETER_42_AND_43_t* out) { return spark_decode_READ_PARAMETER_42_AND_43(in.data, in.dlc, out); }

// Frame values for Read Parameter 44 and 45: Read parameter 44 and 45 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_44_AND_45_t;

// Decode frame payload for Read Parameter 44 and 45: Read parameter 44 and 45 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_44_AND_45(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_44_AND_45_t* out);
static inline bool spark_decode_READ_PARAMETER_44_AND_45_frame(const spark_can_frame& in, Spark_READ_PARAMETER_44_AND_45_t* out) { return spark_decode_READ_PARAMETER_44_AND_45(in.data, in.dlc, out); }

// Frame values for Read Parameter 46 and 47: Read parameter 46 and 47 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_46_AND_47_t;

// Decode frame payload for Read Parameter 46 and 47: Read parameter 46 and 47 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_46_AND_47(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_46_AND_47_t* out);
static inline bool spark_decode_READ_PARAMETER_46_AND_47_frame(const spark_can_frame& in, Spark_READ_PARAMETER_46_AND_47_t* out) { return spark_decode_READ_PARAMETER_46_AND_47(in.data, in.dlc, out); }

// Frame values for Read Parameter 48 and 49: Read parameter 48 and 49 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_48_AND_49_t;

// Decode frame payload for Read Parameter 48 and 49: Read parameter 48 and 49 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_48_AND_49(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_48_AND_49_t* out);
static inline bool spark_decode_READ_PARAMETER_48_AND_49_frame(const spark_can_frame& in, Spark_READ_PARAMETER_48_AND_49_t* out) { return spark_decode_READ_PARAMETER_48_AND_49(in.data, in.dlc, out); }

// Frame values for Read Parameter 50 and 51: Read parameter 50 and 51 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_50_AND_51_t;

// Decode frame payload for Read Parameter 50 and 51: Read parameter 50 and 51 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_50_AND_51(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_50_AND_51_t* out);
static inline bool spark_decode_READ_PARAMETER_50_AND_51_frame(const spark_can_frame& in, Spark_READ_PARAMETER_50_AND_51_t* out) { return spark_decode_READ_PARAMETER_50_AND_51(in.data, in.dlc, out); }

// Frame values for Read Parameter 52 and 53: Read parameter 52 and 53 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_52_AND_53_t;

// Decode frame payload for Read Parameter 52 and 53: Read parameter 52 and 53 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_52_AND_53(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_52_AND_53_t* out);
static inline bool spark_decode_READ_PARAMETER_52_AND_53_frame(const spark_can_frame& in, Spark_READ_PARAMETER_52_AND_53_t* out) { return spark_decode_READ_PARAMETER_52_AND_53(in.data, in.dlc, out); }

// Frame values for Read Parameter 54 and 55: Read parameter 54 and 55 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_54_AND_55_t;

// Decode frame payload for Read Parameter 54 and 55: Read parameter 54 and 55 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_54_AND_55(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_54_AND_55_t* out);
static inline bool spark_decode_READ_PARAMETER_54_AND_55_frame(const spark_can_frame& in, Spark_READ_PARAMETER_54_AND_55_t* out) { return spark_decode_READ_PARAMETER_54_AND_55(in.data, in.dlc, out); }

// Frame values for Read Parameter 56 and 57: Read parameter 56 and 57 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_56_AND_57_t;

// Decode frame payload for Read Parameter 56 and 57: Read parameter 56 and 57 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_56_AND_57(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_56_AND_57_t* out);
static inline bool spark_decode_READ_PARAMETER_56_AND_57_frame(const spark_can_frame& in, Spark_READ_PARAMETER_56_AND_57_t* out) { return spark_decode_READ_PARAMETER_56_AND_57(in.data, in.dlc, out); }

// Frame values for Read Parameter 58 and 59: Read parameter 58 and 59 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_58_AND_59_t;

// Decode frame payload for Read Parameter 58 and 59: Read parameter 58 and 59 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_58_AND_59(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_58_AND_59_t* out);
static inline bool spark_decode_READ_PARAMETER_58_AND_59_frame(const spark_can_frame& in, Spark_READ_PARAMETER_58_AND_59_t* out) { return spark_decode_READ_PARAMETER_58_AND_59(in.data, in.dlc, out); }

// Frame values for Read Parameter 60 and 61: Read parameter 60 and 61 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_60_AND_61_t;

// Decode frame payload for Read Parameter 60 and 61: Read parameter 60 and 61 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_60_AND_61(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_60_AND_61_t* out);
static inline bool spark_decode_READ_PARAMETER_60_AND_61_frame(const spark_can_frame& in, Spark_READ_PARAMETER_60_AND_61_t* out) { return spark_decode_READ_PARAMETER_60_AND_61(in.data, in.dlc, out); }

// Frame values for Read Parameter 62 and 63: Read parameter 62 and 63 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_62_AND_63_t;

// Decode frame payload for Read Parameter 62 and 63: Read parameter 62 and 63 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_62_AND_63(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_62_AND_63_t* out);
static inline bool spark_decode_READ_PARAMETER_62_AND_63_frame(const spark_can_frame& in, Spark_READ_PARAMETER_62_AND_63_t* out) { return spark_decode_READ_PARAMETER_62_AND_63(in.data, in.dlc, out); }

// Frame values for Read Parameter 64 and 65: Read parameter 64 and 65 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_64_AND_65_t;

// Decode frame payload for Read Parameter 64 and 65: Read parameter 64 and 65 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_64_AND_65(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_64_AND_65_t* out);
static inline bool spark_decode_READ_PARAMETER_64_AND_65_frame(const spark_can_frame& in, Spark_READ_PARAMETER_64_AND_65_t* out) { return spark_decode_READ_PARAMETER_64_AND_65(in.data, in.dlc, out); }

// Frame values for Read Parameter 66 and 67: Read parameter 66 and 67 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_66_AND_67_t;

// Decode frame payload for Read Parameter 66 and 67: Read parameter 66 and 67 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_66_AND_67(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_66_AND_67_t* out);
static inline bool spark_decode_READ_PARAMETER_66_AND_67_frame(const spark_can_frame& in, Spark_READ_PARAMETER_66_AND_67_t* out) { return spark_decode_READ_PARAMETER_66_AND_67(in.data, in.dlc, out); }

// Frame values for Read Parameter 68 and 69: Read parameter 68 and 69 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_68_AND_69_t;

// Decode frame payload for Read Parameter 68 and 69: Read parameter 68 and 69 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_68_AND_69(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_68_AND_69_t* out);
static inline bool spark_decode_READ_PARAMETER_68_AND_69_frame(const spark_can_frame& in, Spark_READ_PARAMETER_68_AND_69_t* out) { return spark_decode_READ_PARAMETER_68_AND_69(in.data, in.dlc, out); }

// Frame values for Read Parameter 70 and 71: Read parameter 70 and 71 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_70_AND_71_t;

// Decode frame payload for Read Parameter 70 and 71: Read parameter 70 and 71 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_70_AND_71(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_70_AND_71_t* out);
static inline bool spark_decode_READ_PARAMETER_70_AND_71_frame(const spark_can_frame& in, Spark_READ_PARAMETER_70_AND_71_t* out) { return spark_decode_READ_PARAMETER_70_AND_71(in.data, in.dlc, out); }

// Frame values for Read Parameter 72 and 73: Read parameter 72 and 73 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_72_AND_73_t;

// Decode frame payload for Read Parameter 72 and 73: Read parameter 72 and 73 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_72_AND_73(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_72_AND_73_t* out);
static inline bool spark_decode_READ_PARAMETER_72_AND_73_frame(const spark_can_frame& in, Spark_READ_PARAMETER_72_AND_73_t* out) { return spark_decode_READ_PARAMETER_72_AND_73(in.data, in.dlc, out); }

// Frame values for Read Parameter 74 and 75: Read parameter 74 and 75 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_74_AND_75_t;

// Decode frame payload for Read Parameter 74 and 75: Read parameter 74 and 75 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_74_AND_75(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_74_AND_75_t* out);
static inline bool spark_decode_READ_PARAMETER_74_AND_75_frame(const spark_can_frame& in, Spark_READ_PARAMETER_74_AND_75_t* out) { return spark_decode_READ_PARAMETER_74_AND_75(in.data, in.dlc, out); }

// Frame values for Read Parameter 76 and 77: Read parameter 76 and 77 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_76_AND_77_t;

// Decode frame payload for Read Parameter 76 and 77: Read parameter 76 and 77 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_76_AND_77(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_76_AND_77_t* out);
static inline bool spark_decode_READ_PARAMETER_76_AND_77_frame(const spark_can_frame& in, Spark_READ_PARAMETER_76_AND_77_t* out) { return spark_decode_READ_PARAMETER_76_AND_77(in.data, in.dlc, out); }

// Frame values for Read Parameter 78 and 79: Read parameter 78 and 79 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_78_AND_79_t;

// Decode frame payload for Read Parameter 78 and 79: Read parameter 78 and 79 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_78_AND_79(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_78_AND_79_t* out);
static inline bool spark_decode_READ_PARAMETER_78_AND_79_frame(const spark_can_frame& in, Spark_READ_PARAMETER_78_AND_79_t* out) { return spark_decode_READ_PARAMETER_78_AND_79(in.data, in.dlc, out); }

// Frame values for Read Parameter 80 and 81: Read parameter 80 and 81 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_80_AND_81_t;

// Decode frame payload for Read Parameter 80 and 81: Read parameter 80 and 81 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_80_AND_81(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_80_AND_81_t* out);
static inline bool spark_decode_READ_PARAMETER_80_AND_81_frame(const spark_can_frame& in, Spark_READ_PARAMETER_80_AND_81_t* out) { return spark_decode_READ_PARAMETER_80_AND_81(in.data, in.dlc, out); }

// Frame values for Read Parameter 82 and 83: Read parameter 82 and 83 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_82_AND_83_t;

// Decode frame payload for Read Parameter 82 and 83: Read parameter 82 and 83 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_82_AND_83(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_82_AND_83_t* out);
static inline bool spark_decode_READ_PARAMETER_82_AND_83_frame(const spark_can_frame& in, Spark_READ_PARAMETER_82_AND_83_t* out) { return spark_decode_READ_PARAMETER_82_AND_83(in.data, in.dlc, out); }

// Frame values for Read Parameter 84 and 85: Read parameter 84 and 85 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_84_AND_85_t;

// Decode frame payload for Read Parameter 84 and 85: Read parameter 84 and 85 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_84_AND_85(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_84_AND_85_t* out);
static inline bool spark_decode_READ_PARAMETER_84_AND_85_frame(const spark_can_frame& in, Spark_READ_PARAMETER_84_AND_85_t* out) { return spark_decode_READ_PARAMETER_84_AND_85(in.data, in.dlc, out); }

// Frame values for Read Parameter 86 and 87: Read parameter 86 and 87 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_86_AND_87_t;

// Decode frame payload for Read Parameter 86 and 87: Read parameter 86 and 87 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_86_AND_87(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_86_AND_87_t* out);
static inline bool spark_decode_READ_PARAMETER_86_AND_87_frame(const spark_can_frame& in, Spark_READ_PARAMETER_86_AND_87_t* out) { return spark_decode_READ_PARAMETER_86_AND_87(in.data, in.dlc, out); }

// Frame values for Read Parameter 88 and 89: Read parameter 88 and 89 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_88_AND_89_t;

// Decode frame payload for Read Parameter 88 and 89: Read parameter 88 and 89 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_88_AND_89(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_88_AND_89_t* out);
static inline bool spark_decode_READ_PARAMETER_88_AND_89_frame(const spark_can_frame& in, Spark_READ_PARAMETER_88_AND_89_t* out) { return spark_decode_READ_PARAMETER_88_AND_89(in.data, in.dlc, out); }

// Frame values for Read Parameter 90 and 91: Read parameter 90 and 91 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_90_AND_91_t;

// Decode frame payload for Read Parameter 90 and 91: Read parameter 90 and 91 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_90_AND_91(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_90_AND_91_t* out);
static inline bool spark_decode_READ_PARAMETER_90_AND_91_frame(const spark_can_frame& in, Spark_READ_PARAMETER_90_AND_91_t* out) { return spark_decode_READ_PARAMETER_90_AND_91(in.data, in.dlc, out); }

// Frame values for Read Parameter 92 and 93: Read parameter 92 and 93 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_92_AND_93_t;

// Decode frame payload for Read Parameter 92 and 93: Read parameter 92 and 93 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_92_AND_93(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_92_AND_93_t* out);
static inline bool spark_decode_READ_PARAMETER_92_AND_93_frame(const spark_can_frame& in, Spark_READ_PARAMETER_92_AND_93_t* out) { return spark_decode_READ_PARAMETER_92_AND_93(in.data, in.dlc, out); }

// Frame values for Read Parameter 94 and 95: Read parameter 94 and 95 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_94_AND_95_t;

// Decode frame payload for Read Parameter 94 and 95: Read parameter 94 and 95 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_94_AND_95(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_94_AND_95_t* out);
static inline bool spark_decode_READ_PARAMETER_94_AND_95_frame(const spark_can_frame& in, Spark_READ_PARAMETER_94_AND_95_t* out) { return spark_decode_READ_PARAMETER_94_AND_95(in.data, in.dlc, out); }

// Frame values for Read Parameter 96 and 97: Read parameter 96 and 97 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_96_AND_97_t;

// Decode frame payload for Read Parameter 96 and 97: Read parameter 96 and 97 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_96_AND_97(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_96_AND_97_t* out);
static inline bool spark_decode_READ_PARAMETER_96_AND_97_frame(const spark_can_frame& in, Spark_READ_PARAMETER_96_AND_97_t* out) { return spark_decode_READ_PARAMETER_96_AND_97(in.data, in.dlc, out); }

// Frame values for Read Parameter 98 and 99: Read parameter 98 and 99 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_98_AND_99_t;

// Decode frame payload for Read Parameter 98 and 99: Read parameter 98 and 99 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_98_AND_99(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_98_AND_99_t* out);
static inline bool spark_decode_READ_PARAMETER_98_AND_99_frame(const spark_can_frame& in, Spark_READ_PARAMETER_98_AND_99_t* out) { return spark_decode_READ_PARAMETER_98_AND_99(in.data, in.dlc, out); }

// Frame values for Read Parameter 100 and 101: Read parameter 100 and 101 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_100_AND_101_t;

// Decode frame payload for Read Parameter 100 and 101: Read parameter 100 and 101 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_100_AND_101(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_100_AND_101_t* out);
static inline bool spark_decode_READ_PARAMETER_100_AND_101_frame(const spark_can_frame& in, Spark_READ_PARAMETER_100_AND_101_t* out) { return spark_decode_READ_PARAMETER_100_AND_101(in.data, in.dlc, out); }

// Frame values for Read Parameter 102 and 103: Read parameter 102 and 103 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_102_AND_103_t;

// Decode frame payload for Read Parameter 102 and 103: Read parameter 102 and 103 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_102_AND_103(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_102_AND_103_t* out);
static inline bool spark_decode_READ_PARAMETER_102_AND_103_frame(const spark_can_frame& in, Spark_READ_PARAMETER_102_AND_103_t* out) { return spark_decode_READ_PARAMETER_102_AND_103(in.data, in.dlc, out); }

// Frame values for Read Parameter 104 and 105: Read parameter 104 and 105 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_104_AND_105_t;

// Decode frame payload for Read Parameter 104 and 105: Read parameter 104 and 105 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_104_AND_105(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_104_AND_105_t* out);
static inline bool spark_decode_READ_PARAMETER_104_AND_105_frame(const spark_can_frame& in, Spark_READ_PARAMETER_104_AND_105_t* out) { return spark_decode_READ_PARAMETER_104_AND_105(in.data, in.dlc, out); }

// Frame values for Read Parameter 106 and 107: Read parameter 106 and 107 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_106_AND_107_t;

// Decode frame payload for Read Parameter 106 and 107: Read parameter 106 and 107 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_106_AND_107(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_106_AND_107_t* out);
static inline bool spark_decode_READ_PARAMETER_106_AND_107_frame(const spark_can_frame& in, Spark_READ_PARAMETER_106_AND_107_t* out) { return spark_decode_READ_PARAMETER_106_AND_107(in.data, in.dlc, out); }

// Frame values for Read Parameter 108 and 109: Read parameter 108 and 109 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_108_AND_109_t;

// Decode frame payload for Read Parameter 108 and 109: Read parameter 108 and 109 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_108_AND_109(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_108_AND_109_t* out);
static inline bool spark_decode_READ_PARAMETER_108_AND_109_frame(const spark_can_frame& in, Spark_READ_PARAMETER_108_AND_109_t* out) { return spark_decode_READ_PARAMETER_108_AND_109(in.data, in.dlc, out); }

// Frame values for Read Parameter 110 and 111: Read parameter 110 and 111 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_110_AND_111_t;

// Decode frame payload for Read Parameter 110 and 111: Read parameter 110 and 111 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_110_AND_111(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_110_AND_111_t* out);
static inline bool spark_decode_READ_PARAMETER_110_AND_111_frame(const spark_can_frame& in, Spark_READ_PARAMETER_110_AND_111_t* out) { return spark_decode_READ_PARAMETER_110_AND_111(in.data, in.dlc, out); }

// Frame values for Read Parameter 112 and 113: Read parameter 112 and 113 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_112_AND_113_t;

// Decode frame payload for Read Parameter 112 and 113: Read parameter 112 and 113 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_112_AND_113(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_112_AND_113_t* out);
static inline bool spark_decode_READ_PARAMETER_112_AND_113_frame(const spark_can_frame& in, Spark_READ_PARAMETER_112_AND_113_t* out) { return spark_decode_READ_PARAMETER_112_AND_113(in.data, in.dlc, out); }

// Frame values for Read Parameter 114 and 115: Read parameter 114 and 115 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_114_AND_115_t;

// Decode frame payload for Read Parameter 114 and 115: Read parameter 114 and 115 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_114_AND_115(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_114_AND_115_t* out);
static inline bool spark_decode_READ_PARAMETER_114_AND_115_frame(const spark_can_frame& in, Spark_READ_PARAMETER_114_AND_115_t* out) { return spark_decode_READ_PARAMETER_114_AND_115(in.data, in.dlc, out); }

// Frame values for Read Parameter 116 and 117: Read parameter 116 and 117 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_116_AND_117_t;

// Decode frame payload for Read Parameter 116 and 117: Read parameter 116 and 117 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_116_AND_117(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_116_AND_117_t* out);
static inline bool spark_decode_READ_PARAMETER_116_AND_117_frame(const spark_can_frame& in, Spark_READ_PARAMETER_116_AND_117_t* out) { return spark_decode_READ_PARAMETER_116_AND_117(in.data, in.dlc, out); }

// Frame values for Read Parameter 118 and 119: Read parameter 118 and 119 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_118_AND_119_t;

// Decode frame payload for Read Parameter 118 and 119: Read parameter 118 and 119 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_118_AND_119(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_118_AND_119_t* out);
static inline bool spark_decode_READ_PARAMETER_118_AND_119_frame(const spark_can_frame& in, Spark_READ_PARAMETER_118_AND_119_t* out) { return spark_decode_READ_PARAMETER_118_AND_119(in.data, in.dlc, out); }

// Frame values for Read Parameter 120 and 121: Read parameter 120 and 121 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_120_AND_121_t;

// Decode frame payload for Read Parameter 120 and 121: Read parameter 120 and 121 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_120_AND_121(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_120_AND_121_t* out);
static inline bool spark_decode_READ_PARAMETER_120_AND_121_frame(const spark_can_frame& in, Spark_READ_PARAMETER_120_AND_121_t* out) { return spark_decode_READ_PARAMETER_120_AND_121(in.data, in.dlc, out); }

// Frame values for Read Parameter 122 and 123: Read parameter 122 and 123 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_122_AND_123_t;

// Decode frame payload for Read Parameter 122 and 123: Read parameter 122 and 123 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_122_AND_123(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_122_AND_123_t* out);
static inline bool spark_decode_READ_PARAMETER_122_AND_123_frame(const spark_can_frame& in, Spark_READ_PARAMETER_122_AND_123_t* out) { return spark_decode_READ_PARAMETER_122_AND_123(in.data, in.dlc, out); }

// Frame values for Read Parameter 124 and 125: Read parameter 124 and 125 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_124_AND_125_t;

// Decode frame payload for Read Parameter 124 and 125: Read parameter 124 and 125 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_124_AND_125(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_124_AND_125_t* out);
static inline bool spark_decode_READ_PARAMETER_124_AND_125_frame(const spark_can_frame& in, Spark_READ_PARAMETER_124_AND_125_t* out) { return spark_decode_READ_PARAMETER_124_AND_125(in.data, in.dlc, out); }

// Frame values for Read Parameter 126 and 127: Read parameter 126 and 127 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_126_AND_127_t;

// Decode frame payload for Read Parameter 126 and 127: Read parameter 126 and 127 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_126_AND_127(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_126_AND_127_t* out);
static inline bool spark_decode_READ_PARAMETER_126_AND_127_frame(const spark_can_frame& in, Spark_READ_PARAMETER_126_AND_127_t* out) { return spark_decode_READ_PARAMETER_126_AND_127(in.data, in.dlc, out); }

// Frame values for Read Parameter 128 and 129: Read parameter 128 and 129 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_128_AND_129_t;

// Decode frame payload for Read Parameter 128 and 129: Read parameter 128 and 129 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_128_AND_129(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_128_AND_129_t* out);
static inline bool spark_decode_READ_PARAMETER_128_AND_129_frame(const spark_can_frame& in, Spark_READ_PARAMETER_128_AND_129_t* out) { return spark_decode_READ_PARAMETER_128_AND_129(in.data, in.dlc, out); }

// Frame values for Read Parameter 130 and 131: Read parameter 130 and 131 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_130_AND_131_t;

// Decode frame payload for Read Parameter 130 and 131: Read parameter 130 and 131 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_130_AND_131(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_130_AND_131_t* out);
static inline bool spark_decode_READ_PARAMETER_130_AND_131_frame(const spark_can_frame& in, Spark_READ_PARAMETER_130_AND_131_t* out) { return spark_decode_READ_PARAMETER_130_AND_131(in.data, in.dlc, out); }

// Frame values for Read Parameter 132 and 133: Read parameter 132 and 133 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_132_AND_133_t;

// Decode frame payload for Read Parameter 132 and 133: Read parameter 132 and 133 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_132_AND_133(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_132_AND_133_t* out);
static inline bool spark_decode_READ_PARAMETER_132_AND_133_frame(const spark_can_frame& in, Spark_READ_PARAMETER_132_AND_133_t* out) { return spark_decode_READ_PARAMETER_132_AND_133(in.data, in.dlc, out); }

// Frame values for Read Parameter 134 and 135: Read parameter 134 and 135 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_134_AND_135_t;

// Decode frame payload for Read Parameter 134 and 135: Read parameter 134 and 135 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_134_AND_135(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_134_AND_135_t* out);
static inline bool spark_decode_READ_PARAMETER_134_AND_135_frame(const spark_can_frame& in, Spark_READ_PARAMETER_134_AND_135_t* out) { return spark_decode_READ_PARAMETER_134_AND_135(in.data, in.dlc, out); }

// Frame values for Read Parameter 136 and 137: Read parameter 136 and 137 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_136_AND_137_t;

// Decode frame payload for Read Parameter 136 and 137: Read parameter 136 and 137 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_136_AND_137(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_136_AND_137_t* out);
static inline bool spark_decode_READ_PARAMETER_136_AND_137_frame(const spark_can_frame& in, Spark_READ_PARAMETER_136_AND_137_t* out) { return spark_decode_READ_PARAMETER_136_AND_137(in.data, in.dlc, out); }

// Frame values for Read Parameter 138 and 139: Read parameter 138 and 139 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_138_AND_139_t;

// Decode frame payload for Read Parameter 138 and 139: Read parameter 138 and 139 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_138_AND_139(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_138_AND_139_t* out);
static inline bool spark_decode_READ_PARAMETER_138_AND_139_frame(const spark_can_frame& in, Spark_READ_PARAMETER_138_AND_139_t* out) { return spark_decode_READ_PARAMETER_138_AND_139(in.data, in.dlc, out); }

// Frame values for Read Parameter 140 and 141: Read parameter 140 and 141 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_140_AND_141_t;

// Decode frame payload for Read Parameter 140 and 141: Read parameter 140 and 141 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_140_AND_141(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_140_AND_141_t* out);
static inline bool spark_decode_READ_PARAMETER_140_AND_141_frame(const spark_can_frame& in, Spark_READ_PARAMETER_140_AND_141_t* out) { return spark_decode_READ_PARAMETER_140_AND_141(in.data, in.dlc, out); }

// Frame values for Read Parameter 142 and 143: Read parameter 142 and 143 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_142_AND_143_t;

// Decode frame payload for Read Parameter 142 and 143: Read parameter 142 and 143 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_142_AND_143(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_142_AND_143_t* out);
static inline bool spark_decode_READ_PARAMETER_142_AND_143_frame(const spark_can_frame& in, Spark_READ_PARAMETER_142_AND_143_t* out) { return spark_decode_READ_PARAMETER_142_AND_143(in.data, in.dlc, out); }

// Frame values for Read Parameter 144 and 145: Read parameter 144 and 145 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_144_AND_145_t;

// Decode frame payload for Read Parameter 144 and 145: Read parameter 144 and 145 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_144_AND_145(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_144_AND_145_t* out);
static inline bool spark_decode_READ_PARAMETER_144_AND_145_frame(const spark_can_frame& in, Spark_READ_PARAMETER_144_AND_145_t* out) { return spark_decode_READ_PARAMETER_144_AND_145(in.data, in.dlc, out); }

// Frame values for Read Parameter 146 and 147: Read parameter 146 and 147 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_146_AND_147_t;

// Decode frame payload for Read Parameter 146 and 147: Read parameter 146 and 147 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_146_AND_147(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_146_AND_147_t* out);
static inline bool spark_decode_READ_PARAMETER_146_AND_147_frame(const spark_can_frame& in, Spark_READ_PARAMETER_146_AND_147_t* out) { return spark_decode_READ_PARAMETER_146_AND_147(in.data, in.dlc, out); }

// Frame values for Read Parameter 148 and 149: Read parameter 148 and 149 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_148_AND_149_t;

// Decode frame payload for Read Parameter 148 and 149: Read parameter 148 and 149 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_148_AND_149(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_148_AND_149_t* out);
static inline bool spark_decode_READ_PARAMETER_148_AND_149_frame(const spark_can_frame& in, Spark_READ_PARAMETER_148_AND_149_t* out) { return spark_decode_READ_PARAMETER_148_AND_149(in.data, in.dlc, out); }

// Frame values for Read Parameter 150 and 151: Read parameter 150 and 151 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_150_AND_151_t;

// Decode frame payload for Read Parameter 150 and 151: Read parameter 150 and 151 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_150_AND_151(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_150_AND_151_t* out);
static inline bool spark_decode_READ_PARAMETER_150_AND_151_frame(const spark_can_frame& in, Spark_READ_PARAMETER_150_AND_151_t* out) { return spark_decode_READ_PARAMETER_150_AND_151(in.data, in.dlc, out); }

// Frame values for Read Parameter 152 and 153: Read parameter 152 and 153 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_152_AND_153_t;

// Decode frame payload for Read Parameter 152 and 153: Read parameter 152 and 153 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_152_AND_153(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_152_AND_153_t* out);
static inline bool spark_decode_READ_PARAMETER_152_AND_153_frame(const spark_can_frame& in, Spark_READ_PARAMETER_152_AND_153_t* out) { return spark_decode_READ_PARAMETER_152_AND_153(in.data, in.dlc, out); }

// Frame values for Read Parameter 154 and 155: Read parameter 154 and 155 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_154_AND_155_t;

// Decode frame payload for Read Parameter 154 and 155: Read parameter 154 and 155 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_154_AND_155(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_154_AND_155_t* out);
static inline bool spark_decode_READ_PARAMETER_154_AND_155_frame(const spark_can_frame& in, Spark_READ_PARAMETER_154_AND_155_t* out) { return spark_decode_READ_PARAMETER_154_AND_155(in.data, in.dlc, out); }

// Frame values for Read Parameter 156 and 157: Read parameter 156 and 157 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_156_AND_157_t;

// Decode frame payload for Read Parameter 156 and 157: Read parameter 156 and 157 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_156_AND_157(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_156_AND_157_t* out);
static inline bool spark_decode_READ_PARAMETER_156_AND_157_frame(const spark_can_frame& in, Spark_READ_PARAMETER_156_AND_157_t* out) { return spark_decode_READ_PARAMETER_156_AND_157(in.data, in.dlc, out); }

// Frame values for Read Parameter 158 and 159: Read parameter 158 and 159 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_158_AND_159_t;

// Decode frame payload for Read Parameter 158 and 159: Read parameter 158 and 159 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_158_AND_159(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_158_AND_159_t* out);
static inline bool spark_decode_READ_PARAMETER_158_AND_159_frame(const spark_can_frame& in, Spark_READ_PARAMETER_158_AND_159_t* out) { return spark_decode_READ_PARAMETER_158_AND_159(in.data, in.dlc, out); }

// Frame values for Read Parameter 160 and 161: Read parameter 160 and 161 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_160_AND_161_t;

// Decode frame payload for Read Parameter 160 and 161: Read parameter 160 and 161 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_160_AND_161(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_160_AND_161_t* out);
static inline bool spark_decode_READ_PARAMETER_160_AND_161_frame(const spark_can_frame& in, Spark_READ_PARAMETER_160_AND_161_t* out) { return spark_decode_READ_PARAMETER_160_AND_161(in.data, in.dlc, out); }

// Frame values for Read Parameter 162 and 163: Read parameter 162 and 163 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_162_AND_163_t;

// Decode frame payload for Read Parameter 162 and 163: Read parameter 162 and 163 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_162_AND_163(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_162_AND_163_t* out);
static inline bool spark_decode_READ_PARAMETER_162_AND_163_frame(const spark_can_frame& in, Spark_READ_PARAMETER_162_AND_163_t* out) { return spark_decode_READ_PARAMETER_162_AND_163(in.data, in.dlc, out); }

// Frame values for Read Parameter 164 and 165: Read parameter 164 and 165 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_164_AND_165_t;

// Decode frame payload for Read Parameter 164 and 165: Read parameter 164 and 165 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_164_AND_165(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_164_AND_165_t* out);
static inline bool spark_decode_READ_PARAMETER_164_AND_165_frame(const spark_can_frame& in, Spark_READ_PARAMETER_164_AND_165_t* out) { return spark_decode_READ_PARAMETER_164_AND_165(in.data, in.dlc, out); }

// Frame values for Read Parameter 166 and 167: Read parameter 166 and 167 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_166_AND_167_t;

// Decode frame payload for Read Parameter 166 and 167: Read parameter 166 and 167 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_166_AND_167(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_166_AND_167_t* out);
static inline bool spark_decode_READ_PARAMETER_166_AND_167_frame(const spark_can_frame& in, Spark_READ_PARAMETER_166_AND_167_t* out) { return spark_decode_READ_PARAMETER_166_AND_167(in.data, in.dlc, out); }

// Frame values for Read Parameter 168 and 169: Read parameter 168 and 169 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_168_AND_169_t;

// Decode frame payload for Read Parameter 168 and 169: Read parameter 168 and 169 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_168_AND_169(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_168_AND_169_t* out);
static inline bool spark_decode_READ_PARAMETER_168_AND_169_frame(const spark_can_frame& in, Spark_READ_PARAMETER_168_AND_169_t* out) { return spark_decode_READ_PARAMETER_168_AND_169(in.data, in.dlc, out); }

// Frame values for Read Parameter 170 and 171: Read parameter 170 and 171 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_170_AND_171_t;

// Decode frame payload for Read Parameter 170 and 171: Read parameter 170 and 171 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_170_AND_171(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_170_AND_171_t* out);
static inline bool spark_decode_READ_PARAMETER_170_AND_171_frame(const spark_can_frame& in, Spark_READ_PARAMETER_170_AND_171_t* out) { return spark_decode_READ_PARAMETER_170_AND_171(in.data, in.dlc, out); }

// Frame values for Read Parameter 172 and 173: Read parameter 172 and 173 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_172_AND_173_t;

// Decode frame payload for Read Parameter 172 and 173: Read parameter 172 and 173 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_172_AND_173(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_172_AND_173_t* out);
static inline bool spark_decode_READ_PARAMETER_172_AND_173_frame(const spark_can_frame& in, Spark_READ_PARAMETER_172_AND_173_t* out) { return spark_decode_READ_PARAMETER_172_AND_173(in.data, in.dlc, out); }

// Frame values for Read Parameter 174 and 175: Read parameter 174 and 175 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_174_AND_175_t;

// Decode frame payload for Read Parameter 174 and 175: Read parameter 174 and 175 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_174_AND_175(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_174_AND_175_t* out);
static inline bool spark_decode_READ_PARAMETER_174_AND_175_frame(const spark_can_frame& in, Spark_READ_PARAMETER_174_AND_175_t* out) { return spark_decode_READ_PARAMETER_174_AND_175(in.data, in.dlc, out); }

// Frame values for Read Parameter 176 and 177: Read parameter 176 and 177 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_176_AND_177_t;

// Decode frame payload for Read Parameter 176 and 177: Read parameter 176 and 177 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_176_AND_177(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_176_AND_177_t* out);
static inline bool spark_decode_READ_PARAMETER_176_AND_177_frame(const spark_can_frame& in, Spark_READ_PARAMETER_176_AND_177_t* out) { return spark_decode_READ_PARAMETER_176_AND_177(in.data, in.dlc, out); }

// Frame values for Read Parameter 178 and 179: Read parameter 178 and 179 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_178_AND_179_t;

// Decode frame payload for Read Parameter 178 and 179: Read parameter 178 and 179 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_178_AND_179(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_178_AND_179_t* out);
static inline bool spark_decode_READ_PARAMETER_178_AND_179_frame(const spark_can_frame& in, Spark_READ_PARAMETER_178_AND_179_t* out) { return spark_decode_READ_PARAMETER_178_AND_179(in.data, in.dlc, out); }

// Frame values for Read Parameter 180 and 181: Read parameter 180 and 181 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_180_AND_181_t;

// Decode frame payload for Read Parameter 180 and 181: Read parameter 180 and 181 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_180_AND_181(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_180_AND_181_t* out);
static inline bool spark_decode_READ_PARAMETER_180_AND_181_frame(const spark_can_frame& in, Spark_READ_PARAMETER_180_AND_181_t* out) { return spark_decode_READ_PARAMETER_180_AND_181(in.data, in.dlc, out); }

// Frame values for Read Parameter 182 and 183: Read parameter 182 and 183 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_182_AND_183_t;

// Decode frame payload for Read Parameter 182 and 183: Read parameter 182 and 183 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_182_AND_183(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_182_AND_183_t* out);
static inline bool spark_decode_READ_PARAMETER_182_AND_183_frame(const spark_can_frame& in, Spark_READ_PARAMETER_182_AND_183_t* out) { return spark_decode_READ_PARAMETER_182_AND_183(in.data, in.dlc, out); }

// Frame values for Read Parameter 184 and 185: Read parameter 184 and 185 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_184_AND_185_t;

// Decode frame payload for Read Parameter 184 and 185: Read parameter 184 and 185 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_184_AND_185(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_184_AND_185_t* out);
static inline bool spark_decode_READ_PARAMETER_184_AND_185_frame(const spark_can_frame& in, Spark_READ_PARAMETER_184_AND_185_t* out) { return spark_decode_READ_PARAMETER_184_AND_185(in.data, in.dlc, out); }

// Frame values for Read Parameter 186 and 187: Read parameter 186 and 187 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_186_AND_187_t;

// Decode frame payload for Read Parameter 186 and 187: Read parameter 186 and 187 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_186_AND_187(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_186_AND_187_t* out);
static inline bool spark_decode_READ_PARAMETER_186_AND_187_frame(const spark_can_frame& in, Spark_READ_PARAMETER_186_AND_187_t* out) { return spark_decode_READ_PARAMETER_186_AND_187(in.data, in.dlc, out); }

// Frame values for Read Parameter 188 and 189: Read parameter 188 and 189 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_188_AND_189_t;

// Decode frame payload for Read Parameter 188 and 189: Read parameter 188 and 189 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_188_AND_189(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_188_AND_189_t* out);
static inline bool spark_decode_READ_PARAMETER_188_AND_189_frame(const spark_can_frame& in, Spark_READ_PARAMETER_188_AND_189_t* out) { return spark_decode_READ_PARAMETER_188_AND_189(in.data, in.dlc, out); }

// Frame values for Read Parameter 190 and 191: Read parameter 190 and 191 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_190_AND_191_t;

// Decode frame payload for Read Parameter 190 and 191: Read parameter 190 and 191 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_190_AND_191(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_190_AND_191_t* out);
static inline bool spark_decode_READ_PARAMETER_190_AND_191_frame(const spark_can_frame& in, Spark_READ_PARAMETER_190_AND_191_t* out) { return spark_decode_READ_PARAMETER_190_AND_191(in.data, in.dlc, out); }

// Frame values for Read Parameter 192 and 193: Read parameter 192 and 193 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_192_AND_193_t;

// Decode frame payload for Read Parameter 192 and 193: Read parameter 192 and 193 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_192_AND_193(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_192_AND_193_t* out);
static inline bool spark_decode_READ_PARAMETER_192_AND_193_frame(const spark_can_frame& in, Spark_READ_PARAMETER_192_AND_193_t* out) { return spark_decode_READ_PARAMETER_192_AND_193(in.data, in.dlc, out); }

// Frame values for Read Parameter 194 and 195: Read parameter 194 and 195 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_194_AND_195_t;

// Decode frame payload for Read Parameter 194 and 195: Read parameter 194 and 195 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_194_AND_195(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_194_AND_195_t* out);
static inline bool spark_decode_READ_PARAMETER_194_AND_195_frame(const spark_can_frame& in, Spark_READ_PARAMETER_194_AND_195_t* out) { return spark_decode_READ_PARAMETER_194_AND_195(in.data, in.dlc, out); }

// Frame values for Read Parameter 196 and 197: Read parameter 196 and 197 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_196_AND_197_t;

// Decode frame payload for Read Parameter 196 and 197: Read parameter 196 and 197 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_196_AND_197(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_196_AND_197_t* out);
static inline bool spark_decode_READ_PARAMETER_196_AND_197_frame(const spark_can_frame& in, Spark_READ_PARAMETER_196_AND_197_t* out) { return spark_decode_READ_PARAMETER_196_AND_197(in.data, in.dlc, out); }

// Frame values for Read Parameter 198 and 199: Read parameter 198 and 199 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_198_AND_199_t;

// Decode frame payload for Read Parameter 198 and 199: Read parameter 198 and 199 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_198_AND_199(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_198_AND_199_t* out);
static inline bool spark_decode_READ_PARAMETER_198_AND_199_frame(const spark_can_frame& in, Spark_READ_PARAMETER_198_AND_199_t* out) { return spark_decode_READ_PARAMETER_198_AND_199(in.data, in.dlc, out); }

// Frame values for Read Parameter 200 and 201: Read parameter 200 and 201 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_200_AND_201_t;

// Decode frame payload for Read Parameter 200 and 201: Read parameter 200 and 201 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_200_AND_201(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_200_AND_201_t* out);
static inline bool spark_decode_READ_PARAMETER_200_AND_201_frame(const spark_can_frame& in, Spark_READ_PARAMETER_200_AND_201_t* out) { return spark_decode_READ_PARAMETER_200_AND_201(in.data, in.dlc, out); }

// Frame values for Read Parameter 202 and 203: Read parameter 202 and 203 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_202_AND_203_t;

// Decode frame payload for Read Parameter 202 and 203: Read parameter 202 and 203 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_202_AND_203(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_202_AND_203_t* out);
static inline bool spark_decode_READ_PARAMETER_202_AND_203_frame(const spark_can_frame& in, Spark_READ_PARAMETER_202_AND_203_t* out) { return spark_decode_READ_PARAMETER_202_AND_203(in.data, in.dlc, out); }

// Frame values for Read Parameter 204 and 205: Read parameter 204 and 205 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_204_AND_205_t;

// Decode frame payload for Read Parameter 204 and 205: Read parameter 204 and 205 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_204_AND_205(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_204_AND_205_t* out);
static inline bool spark_decode_READ_PARAMETER_204_AND_205_frame(const spark_can_frame& in, Spark_READ_PARAMETER_204_AND_205_t* out) { return spark_decode_READ_PARAMETER_204_AND_205(in.data, in.dlc, out); }

// Frame values for Read Parameter 206 and 207: Read parameter 206 and 207 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_206_AND_207_t;

// Decode frame payload for Read Parameter 206 and 207: Read parameter 206 and 207 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_206_AND_207(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_206_AND_207_t* out);
static inline bool spark_decode_READ_PARAMETER_206_AND_207_frame(const spark_can_frame& in, Spark_READ_PARAMETER_206_AND_207_t* out) { return spark_decode_READ_PARAMETER_206_AND_207(in.data, in.dlc, out); }

// Frame values for Read Parameter 208 and 209: Read parameter 208 and 209 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_208_AND_209_t;

// Decode frame payload for Read Parameter 208 and 209: Read parameter 208 and 209 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_208_AND_209(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_208_AND_209_t* out);
static inline bool spark_decode_READ_PARAMETER_208_AND_209_frame(const spark_can_frame& in, Spark_READ_PARAMETER_208_AND_209_t* out) { return spark_decode_READ_PARAMETER_208_AND_209(in.data, in.dlc, out); }

// Frame values for Read Parameter 210 and 211: Read parameter 210 and 211 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_210_AND_211_t;

// Decode frame payload for Read Parameter 210 and 211: Read parameter 210 and 211 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_210_AND_211(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_210_AND_211_t* out);
static inline bool spark_decode_READ_PARAMETER_210_AND_211_frame(const spark_can_frame& in, Spark_READ_PARAMETER_210_AND_211_t* out) { return spark_decode_READ_PARAMETER_210_AND_211(in.data, in.dlc, out); }

// Frame values for Read Parameter 212 and 213: Read parameter 212 and 213 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_212_AND_213_t;

// Decode frame payload for Read Parameter 212 and 213: Read parameter 212 and 213 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_212_AND_213(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_212_AND_213_t* out);
static inline bool spark_decode_READ_PARAMETER_212_AND_213_frame(const spark_can_frame& in, Spark_READ_PARAMETER_212_AND_213_t* out) { return spark_decode_READ_PARAMETER_212_AND_213(in.data, in.dlc, out); }

// Frame values for Read Parameter 214 and 215: Read parameter 214 and 215 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_214_AND_215_t;

// Decode frame payload for Read Parameter 214 and 215: Read parameter 214 and 215 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_214_AND_215(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_214_AND_215_t* out);
static inline bool spark_decode_READ_PARAMETER_214_AND_215_frame(const spark_can_frame& in, Spark_READ_PARAMETER_214_AND_215_t* out) { return spark_decode_READ_PARAMETER_214_AND_215(in.data, in.dlc, out); }

// Frame values for Read Parameter 216 and 217: Read parameter 216 and 217 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_216_AND_217_t;

// Decode frame payload for Read Parameter 216 and 217: Read parameter 216 and 217 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_216_AND_217(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_216_AND_217_t* out);
static inline bool spark_decode_READ_PARAMETER_216_AND_217_frame(const spark_can_frame& in, Spark_READ_PARAMETER_216_AND_217_t* out) { return spark_decode_READ_PARAMETER_216_AND_217(in.data, in.dlc, out); }

// Frame values for Read Parameter 218 and 219: Read parameter 218 and 219 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_218_AND_219_t;

// Decode frame payload for Read Parameter 218 and 219: Read parameter 218 and 219 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_218_AND_219(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_218_AND_219_t* out);
static inline bool spark_decode_READ_PARAMETER_218_AND_219_frame(const spark_can_frame& in, Spark_READ_PARAMETER_218_AND_219_t* out) { return spark_decode_READ_PARAMETER_218_AND_219(in.data, in.dlc, out); }

// Frame values for Read Parameter 220 and 221: Read parameter 220 and 221 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_220_AND_221_t;

// Decode frame payload for Read Parameter 220 and 221: Read parameter 220 and 221 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_220_AND_221(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_220_AND_221_t* out);
static inline bool spark_decode_READ_PARAMETER_220_AND_221_frame(const spark_can_frame& in, Spark_READ_PARAMETER_220_AND_221_t* out) { return spark_decode_READ_PARAMETER_220_AND_221(in.data, in.dlc, out); }

// Frame values for Read Parameter 222 and 223: Read parameter 222 and 223 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_222_AND_223_t;

// Decode frame payload for Read Parameter 222 and 223: Read parameter 222 and 223 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_222_AND_223(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_222_AND_223_t* out);
static inline bool spark_decode_READ_PARAMETER_222_AND_223_frame(const spark_can_frame& in, Spark_READ_PARAMETER_222_AND_223_t* out) { return spark_decode_READ_PARAMETER_222_AND_223(in.data, in.dlc, out); }

// Frame values for Read Parameter 224 and 225: Read parameter 224 and 225 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_224_AND_225_t;

// Decode frame payload for Read Parameter 224 and 225: Read parameter 224 and 225 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_224_AND_225(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_224_AND_225_t* out);
static inline bool spark_decode_READ_PARAMETER_224_AND_225_frame(const spark_can_frame& in, Spark_READ_PARAMETER_224_AND_225_t* out) { return spark_decode_READ_PARAMETER_224_AND_225(in.data, in.dlc, out); }

// Frame values for Read Parameter 226 and 227: Read parameter 226 and 227 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_226_AND_227_t;

// Decode frame payload for Read Parameter 226 and 227: Read parameter 226 and 227 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_226_AND_227(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_226_AND_227_t* out);
static inline bool spark_decode_READ_PARAMETER_226_AND_227_frame(const spark_can_frame& in, Spark_READ_PARAMETER_226_AND_227_t* out) { return spark_decode_READ_PARAMETER_226_AND_227(in.data, in.dlc, out); }

// Frame values for Read Parameter 228 and 229: Read parameter 228 and 229 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_228_AND_229_t;

// Decode frame payload for Read Parameter 228 and 229: Read parameter 228 and 229 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_228_AND_229(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_228_AND_229_t* out);
static inline bool spark_decode_READ_PARAMETER_228_AND_229_frame(const spark_can_frame& in, Spark_READ_PARAMETER_228_AND_229_t* out) { return spark_decode_READ_PARAMETER_228_AND_229(in.data, in.dlc, out); }

// Frame values for Read Parameter 230 and 231: Read parameter 230 and 231 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_230_AND_231_t;

// Decode frame payload for Read Parameter 230 and 231: Read parameter 230 and 231 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_230_AND_231(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_230_AND_231_t* out);
static inline bool spark_decode_READ_PARAMETER_230_AND_231_frame(const spark_can_frame& in, Spark_READ_PARAMETER_230_AND_231_t* out) { return spark_decode_READ_PARAMETER_230_AND_231(in.data, in.dlc, out); }

// Frame values for Read Parameter 232 and 233: Read parameter 232 and 233 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_232_AND_233_t;

// Decode frame payload for Read Parameter 232 and 233: Read parameter 232 and 233 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_232_AND_233(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_232_AND_233_t* out);
static inline bool spark_decode_READ_PARAMETER_232_AND_233_frame(const spark_can_frame& in, Spark_READ_PARAMETER_232_AND_233_t* out) { return spark_decode_READ_PARAMETER_232_AND_233(in.data, in.dlc, out); }

// Frame values for Read Parameter 234 and 235: Read parameter 234 and 235 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_234_AND_235_t;

// Decode frame payload for Read Parameter 234 and 235: Read parameter 234 and 235 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_234_AND_235(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_234_AND_235_t* out);
static inline bool spark_decode_READ_PARAMETER_234_AND_235_frame(const spark_can_frame& in, Spark_READ_PARAMETER_234_AND_235_t* out) { return spark_decode_READ_PARAMETER_234_AND_235(in.data, in.dlc, out); }

// Frame values for Read Parameter 236 and 237: Read parameter 236 and 237 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_236_AND_237_t;

// Decode frame payload for Read Parameter 236 and 237: Read parameter 236 and 237 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_236_AND_237(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_236_AND_237_t* out);
static inline bool spark_decode_READ_PARAMETER_236_AND_237_frame(const spark_can_frame& in, Spark_READ_PARAMETER_236_AND_237_t* out) { return spark_decode_READ_PARAMETER_236_AND_237(in.data, in.dlc, out); }

// Frame values for Read Parameter 238 and 239: Read parameter 238 and 239 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_238_AND_239_t;

// Decode frame payload for Read Parameter 238 and 239: Read parameter 238 and 239 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_238_AND_239(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_238_AND_239_t* out);
static inline bool spark_decode_READ_PARAMETER_238_AND_239_frame(const spark_can_frame& in, Spark_READ_PARAMETER_238_AND_239_t* out) { return spark_decode_READ_PARAMETER_238_AND_239(in.data, in.dlc, out); }

// Frame values for Read Parameter 240 and 241: Read parameter 240 and 241 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_240_AND_241_t;

// Decode frame payload for Read Parameter 240 and 241: Read parameter 240 and 241 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_240_AND_241(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_240_AND_241_t* out);
static inline bool spark_decode_READ_PARAMETER_240_AND_241_frame(const spark_can_frame& in, Spark_READ_PARAMETER_240_AND_241_t* out) { return spark_decode_READ_PARAMETER_240_AND_241(in.data, in.dlc, out); }

// Frame values for Read Parameter 242 and 243: Read parameter 242 and 243 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_242_AND_243_t;

// Decode frame payload for Read Parameter 242 and 243: Read parameter 242 and 243 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_242_AND_243(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_242_AND_243_t* out);
static inline bool spark_decode_READ_PARAMETER_242_AND_243_frame(const spark_can_frame& in, Spark_READ_PARAMETER_242_AND_243_t* out) { return spark_decode_READ_PARAMETER_242_AND_243(in.data, in.dlc, out); }

// Frame values for Read Parameter 244 and 245: Read parameter 244 and 245 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_244_AND_245_t;

// Decode frame payload for Read Parameter 244 and 245: Read parameter 244 and 245 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_244_AND_245(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_244_AND_245_t* out);
static inline bool spark_decode_READ_PARAMETER_244_AND_245_frame(const spark_can_frame& in, Spark_READ_PARAMETER_244_AND_245_t* out) { return spark_decode_READ_PARAMETER_244_AND_245(in.data, in.dlc, out); }

// Frame values for Read Parameter 246 and 247: Read parameter 246 and 247 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_246_AND_247_t;

// Decode frame payload for Read Parameter 246 and 247: Read parameter 246 and 247 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_246_AND_247(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_246_AND_247_t* out);
static inline bool spark_decode_READ_PARAMETER_246_AND_247_frame(const spark_can_frame& in, Spark_READ_PARAMETER_246_AND_247_t* out) { return spark_decode_READ_PARAMETER_246_AND_247(in.data, in.dlc, out); }

// Frame values for Read Parameter 248 and 249: Read parameter 248 and 249 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_248_AND_249_t;

// Decode frame payload for Read Parameter 248 and 249: Read parameter 248 and 249 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_248_AND_249(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_248_AND_249_t* out);
static inline bool spark_decode_READ_PARAMETER_248_AND_249_frame(const spark_can_frame& in, Spark_READ_PARAMETER_248_AND_249_t* out) { return spark_decode_READ_PARAMETER_248_AND_249(in.data, in.dlc, out); }

// Frame values for Read Parameter 250 and 251: Read parameter 250 and 251 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_250_AND_251_t;

// Decode frame payload for Read Parameter 250 and 251: Read parameter 250 and 251 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_250_AND_251(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_250_AND_251_t* out);
static inline bool spark_decode_READ_PARAMETER_250_AND_251_frame(const spark_can_frame& in, Spark_READ_PARAMETER_250_AND_251_t* out) { return spark_decode_READ_PARAMETER_250_AND_251(in.data, in.dlc, out); }

// Frame values for Read Parameter 252 and 253: Read parameter 252 and 253 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_252_AND_253_t;

// Decode frame payload for Read Parameter 252 and 253: Read parameter 252 and 253 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_252_AND_253(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_252_AND_253_t* out);
static inline bool spark_decode_READ_PARAMETER_252_AND_253_frame(const spark_can_frame& in, Spark_READ_PARAMETER_252_AND_253_t* out) { return spark_decode_READ_PARAMETER_252_AND_253(in.data, in.dlc, out); }

// Frame values for Read Parameter 254 and 255: Read parameter 254 and 255 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_READ_PARAMETER_254_AND_255_t;

// Decode frame payload for Read Parameter 254 and 255: Read parameter 254 and 255 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
bool spark_decode_READ_PARAMETER_254_AND_255(const uint8_t* data, uint8_t dlc, Spark_READ_PARAMETER_254_AND_255_t* out);
static inline bool spark_decode_READ_PARAMETER_254_AND_255_frame(const spark_can_frame& in, Spark_READ_PARAMETER_254_AND_255_t* out) { return spark_decode_READ_PARAMETER_254_AND_255(in.data, in.dlc, out); }

// Frame values for Write Parameter 0 and 1: Write Parameter 0 and 1 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_0_AND_1_t;

// Decode frame payload for Write Parameter 0 and 1: Write Parameter 0 and 1 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_0_AND_1(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_0_AND_1_t* out);
static inline bool spark_decode_WRITE_PARAMETER_0_AND_1_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_0_AND_1_t* out) { return spark_decode_WRITE_PARAMETER_0_AND_1(in.data, in.dlc, out); }

// Frame values for Write Parameter 2 and 3: Write Parameter 2 and 3 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_2_AND_3_t;

// Decode frame payload for Write Parameter 2 and 3: Write Parameter 2 and 3 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_2_AND_3(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_2_AND_3_t* out);
static inline bool spark_decode_WRITE_PARAMETER_2_AND_3_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_2_AND_3_t* out) { return spark_decode_WRITE_PARAMETER_2_AND_3(in.data, in.dlc, out); }

// Frame values for Write Parameter 4 and 5: Write Parameter 4 and 5 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_4_AND_5_t;

// Decode frame payload for Write Parameter 4 and 5: Write Parameter 4 and 5 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_4_AND_5(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_4_AND_5_t* out);
static inline bool spark_decode_WRITE_PARAMETER_4_AND_5_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_4_AND_5_t* out) { return spark_decode_WRITE_PARAMETER_4_AND_5(in.data, in.dlc, out); }

// Frame values for Write Parameter 6 and 7: Write Parameter 6 and 7 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_6_AND_7_t;

// Decode frame payload for Write Parameter 6 and 7: Write Parameter 6 and 7 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_6_AND_7(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_6_AND_7_t* out);
static inline bool spark_decode_WRITE_PARAMETER_6_AND_7_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_6_AND_7_t* out) { return spark_decode_WRITE_PARAMETER_6_AND_7(in.data, in.dlc, out); }

// Frame values for Write Parameter 8 and 9: Write Parameter 8 and 9 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_8_AND_9_t;

// Decode frame payload for Write Parameter 8 and 9: Write Parameter 8 and 9 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_8_AND_9(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_8_AND_9_t* out);
static inline bool spark_decode_WRITE_PARAMETER_8_AND_9_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_8_AND_9_t* out) { return spark_decode_WRITE_PARAMETER_8_AND_9(in.data, in.dlc, out); }

// Frame values for Write Parameter 10 and 11: Write Parameter 10 and 11 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_10_AND_11_t;

// Decode frame payload for Write Parameter 10 and 11: Write Parameter 10 and 11 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_10_AND_11(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_10_AND_11_t* out);
static inline bool spark_decode_WRITE_PARAMETER_10_AND_11_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_10_AND_11_t* out) { return spark_decode_WRITE_PARAMETER_10_AND_11(in.data, in.dlc, out); }

// Frame values for Write Parameter 12 and 13: Write Parameter 12 and 13 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_12_AND_13_t;

// Decode frame payload for Write Parameter 12 and 13: Write Parameter 12 and 13 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_12_AND_13(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_12_AND_13_t* out);
static inline bool spark_decode_WRITE_PARAMETER_12_AND_13_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_12_AND_13_t* out) { return spark_decode_WRITE_PARAMETER_12_AND_13(in.data, in.dlc, out); }

// Frame values for Write Parameter 14 and 15: Write Parameter 14 and 15 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_14_AND_15_t;

// Decode frame payload for Write Parameter 14 and 15: Write Parameter 14 and 15 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_14_AND_15(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_14_AND_15_t* out);
static inline bool spark_decode_WRITE_PARAMETER_14_AND_15_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_14_AND_15_t* out) { return spark_decode_WRITE_PARAMETER_14_AND_15(in.data, in.dlc, out); }

// Frame values for Write Parameter 16 and 17: Write Parameter 16 and 17 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_16_AND_17_t;

// Decode frame payload for Write Parameter 16 and 17: Write Parameter 16 and 17 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_16_AND_17(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_16_AND_17_t* out);
static inline bool spark_decode_WRITE_PARAMETER_16_AND_17_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_16_AND_17_t* out) { return spark_decode_WRITE_PARAMETER_16_AND_17(in.data, in.dlc, out); }

// Frame values for Write Parameter 18 and 19: Write Parameter 18 and 19 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_18_AND_19_t;

// Decode frame payload for Write Parameter 18 and 19: Write Parameter 18 and 19 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_18_AND_19(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_18_AND_19_t* out);
static inline bool spark_decode_WRITE_PARAMETER_18_AND_19_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_18_AND_19_t* out) { return spark_decode_WRITE_PARAMETER_18_AND_19(in.data, in.dlc, out); }

// Frame values for Write Parameter 20 and 21: Write Parameter 20 and 21 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_20_AND_21_t;

// Decode frame payload for Write Parameter 20 and 21: Write Parameter 20 and 21 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_20_AND_21(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_20_AND_21_t* out);
static inline bool spark_decode_WRITE_PARAMETER_20_AND_21_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_20_AND_21_t* out) { return spark_decode_WRITE_PARAMETER_20_AND_21(in.data, in.dlc, out); }

// Frame values for Write Parameter 22 and 23: Write Parameter 22 and 23 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_22_AND_23_t;

// Decode frame payload for Write Parameter 22 and 23: Write Parameter 22 and 23 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_22_AND_23(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_22_AND_23_t* out);
static inline bool spark_decode_WRITE_PARAMETER_22_AND_23_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_22_AND_23_t* out) { return spark_decode_WRITE_PARAMETER_22_AND_23(in.data, in.dlc, out); }

// Frame values for Write Parameter 24 and 25: Write Parameter 24 and 25 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_24_AND_25_t;

// Decode frame payload for Write Parameter 24 and 25: Write Parameter 24 and 25 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_24_AND_25(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_24_AND_25_t* out);
static inline bool spark_decode_WRITE_PARAMETER_24_AND_25_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_24_AND_25_t* out) { return spark_decode_WRITE_PARAMETER_24_AND_25(in.data, in.dlc, out); }

// Frame values for Write Parameter 26 and 27: Write Parameter 26 and 27 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_26_AND_27_t;

// Decode frame payload for Write Parameter 26 and 27: Write Parameter 26 and 27 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_26_AND_27(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_26_AND_27_t* out);
static inline bool spark_decode_WRITE_PARAMETER_26_AND_27_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_26_AND_27_t* out) { return spark_decode_WRITE_PARAMETER_26_AND_27(in.data, in.dlc, out); }

// Frame values for Write Parameter 28 and 29: Write Parameter 28 and 29 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_28_AND_29_t;

// Decode frame payload for Write Parameter 28 and 29: Write Parameter 28 and 29 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_28_AND_29(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_28_AND_29_t* out);
static inline bool spark_decode_WRITE_PARAMETER_28_AND_29_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_28_AND_29_t* out) { return spark_decode_WRITE_PARAMETER_28_AND_29(in.data, in.dlc, out); }

// Frame values for Write Parameter 30 and 31: Write Parameter 30 and 31 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_30_AND_31_t;

// Decode frame payload for Write Parameter 30 and 31: Write Parameter 30 and 31 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_30_AND_31(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_30_AND_31_t* out);
static inline bool spark_decode_WRITE_PARAMETER_30_AND_31_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_30_AND_31_t* out) { return spark_decode_WRITE_PARAMETER_30_AND_31(in.data, in.dlc, out); }

// Frame values for Write Parameter 32 and 33: Write Parameter 32 and 33 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_32_AND_33_t;

// Decode frame payload for Write Parameter 32 and 33: Write Parameter 32 and 33 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_32_AND_33(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_32_AND_33_t* out);
static inline bool spark_decode_WRITE_PARAMETER_32_AND_33_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_32_AND_33_t* out) { return spark_decode_WRITE_PARAMETER_32_AND_33(in.data, in.dlc, out); }

// Frame values for Write Parameter 34 and 35: Write Parameter 34 and 35 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_34_AND_35_t;

// Decode frame payload for Write Parameter 34 and 35: Write Parameter 34 and 35 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_34_AND_35(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_34_AND_35_t* out);
static inline bool spark_decode_WRITE_PARAMETER_34_AND_35_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_34_AND_35_t* out) { return spark_decode_WRITE_PARAMETER_34_AND_35(in.data, in.dlc, out); }

// Frame values for Write Parameter 36 and 37: Write Parameter 36 and 37 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_36_AND_37_t;

// Decode frame payload for Write Parameter 36 and 37: Write Parameter 36 and 37 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_36_AND_37(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_36_AND_37_t* out);
static inline bool spark_decode_WRITE_PARAMETER_36_AND_37_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_36_AND_37_t* out) { return spark_decode_WRITE_PARAMETER_36_AND_37(in.data, in.dlc, out); }

// Frame values for Write Parameter 38 and 39: Write Parameter 38 and 39 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_38_AND_39_t;

// Decode frame payload for Write Parameter 38 and 39: Write Parameter 38 and 39 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_38_AND_39(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_38_AND_39_t* out);
static inline bool spark_decode_WRITE_PARAMETER_38_AND_39_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_38_AND_39_t* out) { return spark_decode_WRITE_PARAMETER_38_AND_39(in.data, in.dlc, out); }

// Frame values for Write Parameter 40 and 41: Write Parameter 40 and 41 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_40_AND_41_t;

// Decode frame payload for Write Parameter 40 and 41: Write Parameter 40 and 41 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_40_AND_41(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_40_AND_41_t* out);
static inline bool spark_decode_WRITE_PARAMETER_40_AND_41_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_40_AND_41_t* out) { return spark_decode_WRITE_PARAMETER_40_AND_41(in.data, in.dlc, out); }

// Frame values for Write Parameter 42 and 43: Write Parameter 42 and 43 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_42_AND_43_t;

// Decode frame payload for Write Parameter 42 and 43: Write Parameter 42 and 43 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_42_AND_43(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_42_AND_43_t* out);
static inline bool spark_decode_WRITE_PARAMETER_42_AND_43_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_42_AND_43_t* out) { return spark_decode_WRITE_PARAMETER_42_AND_43(in.data, in.dlc, out); }

// Frame values for Write Parameter 44 and 45: Write Parameter 44 and 45 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_44_AND_45_t;

// Decode frame payload for Write Parameter 44 and 45: Write Parameter 44 and 45 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_44_AND_45(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_44_AND_45_t* out);
static inline bool spark_decode_WRITE_PARAMETER_44_AND_45_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_44_AND_45_t* out) { return spark_decode_WRITE_PARAMETER_44_AND_45(in.data, in.dlc, out); }

// Frame values for Write Parameter 46 and 47: Write Parameter 46 and 47 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_46_AND_47_t;

// Decode frame payload for Write Parameter 46 and 47: Write Parameter 46 and 47 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_46_AND_47(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_46_AND_47_t* out);
static inline bool spark_decode_WRITE_PARAMETER_46_AND_47_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_46_AND_47_t* out) { return spark_decode_WRITE_PARAMETER_46_AND_47(in.data, in.dlc, out); }

// Frame values for Write Parameter 48 and 49: Write Parameter 48 and 49 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_48_AND_49_t;

// Decode frame payload for Write Parameter 48 and 49: Write Parameter 48 and 49 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_48_AND_49(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_48_AND_49_t* out);
static inline bool spark_decode_WRITE_PARAMETER_48_AND_49_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_48_AND_49_t* out) { return spark_decode_WRITE_PARAMETER_48_AND_49(in.data, in.dlc, out); }

// Frame values for Write Parameter 50 and 51: Write Parameter 50 and 51 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_50_AND_51_t;

// Decode frame payload for Write Parameter 50 and 51: Write Parameter 50 and 51 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_50_AND_51(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_50_AND_51_t* out);
static inline bool spark_decode_WRITE_PARAMETER_50_AND_51_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_50_AND_51_t* out) { return spark_decode_WRITE_PARAMETER_50_AND_51(in.data, in.dlc, out); }

// Frame values for Write Parameter 52 and 53: Write Parameter 52 and 53 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_52_AND_53_t;

// Decode frame payload for Write Parameter 52 and 53: Write Parameter 52 and 53 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_52_AND_53(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_52_AND_53_t* out);
static inline bool spark_decode_WRITE_PARAMETER_52_AND_53_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_52_AND_53_t* out) { return spark_decode_WRITE_PARAMETER_52_AND_53(in.data, in.dlc, out); }

// Frame values for Write Parameter 54 and 55: Write Parameter 54 and 55 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_54_AND_55_t;

// Decode frame payload for Write Parameter 54 and 55: Write Parameter 54 and 55 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_54_AND_55(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_54_AND_55_t* out);
static inline bool spark_decode_WRITE_PARAMETER_54_AND_55_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_54_AND_55_t* out) { return spark_decode_WRITE_PARAMETER_54_AND_55(in.data, in.dlc, out); }

// Frame values for Write Parameter 56 and 57: Write Parameter 56 and 57 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_56_AND_57_t;

// Decode frame payload for Write Parameter 56 and 57: Write Parameter 56 and 57 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_56_AND_57(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_56_AND_57_t* out);
static inline bool spark_decode_WRITE_PARAMETER_56_AND_57_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_56_AND_57_t* out) { return spark_decode_WRITE_PARAMETER_56_AND_57(in.data, in.dlc, out); }

// Frame values for Write Parameter 58 and 59: Write Parameter 58 and 59 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_58_AND_59_t;

// Decode frame payload for Write Parameter 58 and 59: Write Parameter 58 and 59 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_58_AND_59(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_58_AND_59_t* out);
static inline bool spark_decode_WRITE_PARAMETER_58_AND_59_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_58_AND_59_t* out) { return spark_decode_WRITE_PARAMETER_58_AND_59(in.data, in.dlc, out); }

// Frame values for Write Parameter 60 and 61: Write Parameter 60 and 61 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_60_AND_61_t;

// Decode frame payload for Write Parameter 60 and 61: Write Parameter 60 and 61 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_60_AND_61(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_60_AND_61_t* out);
static inline bool spark_decode_WRITE_PARAMETER_60_AND_61_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_60_AND_61_t* out) { return spark_decode_WRITE_PARAMETER_60_AND_61(in.data, in.dlc, out); }

// Frame values for Write Parameter 62 and 63: Write Parameter 62 and 63 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_62_AND_63_t;

// Decode frame payload for Write Parameter 62 and 63: Write Parameter 62 and 63 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_62_AND_63(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_62_AND_63_t* out);
static inline bool spark_decode_WRITE_PARAMETER_62_AND_63_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_62_AND_63_t* out) { return spark_decode_WRITE_PARAMETER_62_AND_63(in.data, in.dlc, out); }

// Frame values for Write Parameter 64 and 65: Write Parameter 64 and 65 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_64_AND_65_t;

// Decode frame payload for Write Parameter 64 and 65: Write Parameter 64 and 65 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_64_AND_65(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_64_AND_65_t* out);
static inline bool spark_decode_WRITE_PARAMETER_64_AND_65_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_64_AND_65_t* out) { return spark_decode_WRITE_PARAMETER_64_AND_65(in.data, in.dlc, out); }

// Frame values for Write Parameter 66 and 67: Write Parameter 66 and 67 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_66_AND_67_t;

// Decode frame payload for Write Parameter 66 and 67: Write Parameter 66 and 67 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_66_AND_67(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_66_AND_67_t* out);
static inline bool spark_decode_WRITE_PARAMETER_66_AND_67_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_66_AND_67_t* out) { return spark_decode_WRITE_PARAMETER_66_AND_67(in.data, in.dlc, out); }

// Frame values for Write Parameter 68 and 69: Write Parameter 68 and 69 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_68_AND_69_t;

// Decode frame payload for Write Parameter 68 and 69: Write Parameter 68 and 69 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_68_AND_69(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_68_AND_69_t* out);
static inline bool spark_decode_WRITE_PARAMETER_68_AND_69_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_68_AND_69_t* out) { return spark_decode_WRITE_PARAMETER_68_AND_69(in.data, in.dlc, out); }

// Frame values for Write Parameter 70 and 71: Write Parameter 70 and 71 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_70_AND_71_t;

// Decode frame payload for Write Parameter 70 and 71: Write Parameter 70 and 71 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_70_AND_71(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_70_AND_71_t* out);
static inline bool spark_decode_WRITE_PARAMETER_70_AND_71_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_70_AND_71_t* out) { return spark_decode_WRITE_PARAMETER_70_AND_71(in.data, in.dlc, out); }

// Frame values for Write Parameter 72 and 73: Write Parameter 72 and 73 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_72_AND_73_t;

// Decode frame payload for Write Parameter 72 and 73: Write Parameter 72 and 73 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_72_AND_73(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_72_AND_73_t* out);
static inline bool spark_decode_WRITE_PARAMETER_72_AND_73_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_72_AND_73_t* out) { return spark_decode_WRITE_PARAMETER_72_AND_73(in.data, in.dlc, out); }

// Frame values for Write Parameter 74 and 75: Write Parameter 74 and 75 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_74_AND_75_t;

// Decode frame payload for Write Parameter 74 and 75: Write Parameter 74 and 75 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_74_AND_75(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_74_AND_75_t* out);
static inline bool spark_decode_WRITE_PARAMETER_74_AND_75_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_74_AND_75_t* out) { return spark_decode_WRITE_PARAMETER_74_AND_75(in.data, in.dlc, out); }

// Frame values for Write Parameter 76 and 77: Write Parameter 76 and 77 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_76_AND_77_t;

// Decode frame payload for Write Parameter 76 and 77: Write Parameter 76 and 77 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_76_AND_77(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_76_AND_77_t* out);
static inline bool spark_decode_WRITE_PARAMETER_76_AND_77_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_76_AND_77_t* out) { return spark_decode_WRITE_PARAMETER_76_AND_77(in.data, in.dlc, out); }

// Frame values for Write Parameter 78 and 79: Write Parameter 78 and 79 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_78_AND_79_t;

// Decode frame payload for Write Parameter 78 and 79: Write Parameter 78 and 79 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_78_AND_79(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_78_AND_79_t* out);
static inline bool spark_decode_WRITE_PARAMETER_78_AND_79_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_78_AND_79_t* out) { return spark_decode_WRITE_PARAMETER_78_AND_79(in.data, in.dlc, out); }

// Frame values for Write Parameter 80 and 81: Write Parameter 80 and 81 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_80_AND_81_t;

// Decode frame payload for Write Parameter 80 and 81: Write Parameter 80 and 81 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_80_AND_81(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_80_AND_81_t* out);
static inline bool spark_decode_WRITE_PARAMETER_80_AND_81_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_80_AND_81_t* out) { return spark_decode_WRITE_PARAMETER_80_AND_81(in.data, in.dlc, out); }

// Frame values for Write Parameter 82 and 83: Write Parameter 82 and 83 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_82_AND_83_t;

// Decode frame payload for Write Parameter 82 and 83: Write Parameter 82 and 83 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_82_AND_83(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_82_AND_83_t* out);
static inline bool spark_decode_WRITE_PARAMETER_82_AND_83_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_82_AND_83_t* out) { return spark_decode_WRITE_PARAMETER_82_AND_83(in.data, in.dlc, out); }

// Frame values for Write Parameter 84 and 85: Write Parameter 84 and 85 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_84_AND_85_t;

// Decode frame payload for Write Parameter 84 and 85: Write Parameter 84 and 85 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_84_AND_85(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_84_AND_85_t* out);
static inline bool spark_decode_WRITE_PARAMETER_84_AND_85_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_84_AND_85_t* out) { return spark_decode_WRITE_PARAMETER_84_AND_85(in.data, in.dlc, out); }

// Frame values for Write Parameter 86 and 87: Write Parameter 86 and 87 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_86_AND_87_t;

// Decode frame payload for Write Parameter 86 and 87: Write Parameter 86 and 87 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_86_AND_87(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_86_AND_87_t* out);
static inline bool spark_decode_WRITE_PARAMETER_86_AND_87_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_86_AND_87_t* out) { return spark_decode_WRITE_PARAMETER_86_AND_87(in.data, in.dlc, out); }

// Frame values for Write Parameter 88 and 89: Write Parameter 88 and 89 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_88_AND_89_t;

// Decode frame payload for Write Parameter 88 and 89: Write Parameter 88 and 89 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_88_AND_89(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_88_AND_89_t* out);
static inline bool spark_decode_WRITE_PARAMETER_88_AND_89_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_88_AND_89_t* out) { return spark_decode_WRITE_PARAMETER_88_AND_89(in.data, in.dlc, out); }

// Frame values for Write Parameter 90 and 91: Write Parameter 90 and 91 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_90_AND_91_t;

// Decode frame payload for Write Parameter 90 and 91: Write Parameter 90 and 91 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_90_AND_91(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_90_AND_91_t* out);
static inline bool spark_decode_WRITE_PARAMETER_90_AND_91_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_90_AND_91_t* out) { return spark_decode_WRITE_PARAMETER_90_AND_91(in.data, in.dlc, out); }

// Frame values for Write Parameter 92 and 93: Write Parameter 92 and 93 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_92_AND_93_t;

// Decode frame payload for Write Parameter 92 and 93: Write Parameter 92 and 93 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_92_AND_93(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_92_AND_93_t* out);
static inline bool spark_decode_WRITE_PARAMETER_92_AND_93_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_92_AND_93_t* out) { return spark_decode_WRITE_PARAMETER_92_AND_93(in.data, in.dlc, out); }

// Frame values for Write Parameter 94 and 95: Write Parameter 94 and 95 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_94_AND_95_t;

// Decode frame payload for Write Parameter 94 and 95: Write Parameter 94 and 95 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_94_AND_95(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_94_AND_95_t* out);
static inline bool spark_decode_WRITE_PARAMETER_94_AND_95_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_94_AND_95_t* out) { return spark_decode_WRITE_PARAMETER_94_AND_95(in.data, in.dlc, out); }

// Frame values for Write Parameter 96 and 97: Write Parameter 96 and 97 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_96_AND_97_t;

// Decode frame payload for Write Parameter 96 and 97: Write Parameter 96 and 97 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_96_AND_97(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_96_AND_97_t* out);
static inline bool spark_decode_WRITE_PARAMETER_96_AND_97_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_96_AND_97_t* out) { return spark_decode_WRITE_PARAMETER_96_AND_97(in.data, in.dlc, out); }

// Frame values for Write Parameter 98 and 99: Write Parameter 98 and 99 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_98_AND_99_t;

// Decode frame payload for Write Parameter 98 and 99: Write Parameter 98 and 99 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_98_AND_99(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_98_AND_99_t* out);
static inline bool spark_decode_WRITE_PARAMETER_98_AND_99_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_98_AND_99_t* out) { return spark_decode_WRITE_PARAMETER_98_AND_99(in.data, in.dlc, out); }

// Frame values for Write Parameter 100 and 101: Write Parameter 100 and 101 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_100_AND_101_t;

// Decode frame payload for Write Parameter 100 and 101: Write Parameter 100 and 101 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_100_AND_101(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_100_AND_101_t* out);
static inline bool spark_decode_WRITE_PARAMETER_100_AND_101_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_100_AND_101_t* out) { return spark_decode_WRITE_PARAMETER_100_AND_101(in.data, in.dlc, out); }

// Frame values for Write Parameter 102 and 103: Write Parameter 102 and 103 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_102_AND_103_t;

// Decode frame payload for Write Parameter 102 and 103: Write Parameter 102 and 103 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_102_AND_103(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_102_AND_103_t* out);
static inline bool spark_decode_WRITE_PARAMETER_102_AND_103_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_102_AND_103_t* out) { return spark_decode_WRITE_PARAMETER_102_AND_103(in.data, in.dlc, out); }

// Frame values for Write Parameter 104 and 105: Write Parameter 104 and 105 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_104_AND_105_t;

// Decode frame payload for Write Parameter 104 and 105: Write Parameter 104 and 105 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_104_AND_105(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_104_AND_105_t* out);
static inline bool spark_decode_WRITE_PARAMETER_104_AND_105_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_104_AND_105_t* out) { return spark_decode_WRITE_PARAMETER_104_AND_105(in.data, in.dlc, out); }

// Frame values for Write Parameter 106 and 107: Write Parameter 106 and 107 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_106_AND_107_t;

// Decode frame payload for Write Parameter 106 and 107: Write Parameter 106 and 107 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_106_AND_107(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_106_AND_107_t* out);
static inline bool spark_decode_WRITE_PARAMETER_106_AND_107_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_106_AND_107_t* out) { return spark_decode_WRITE_PARAMETER_106_AND_107(in.data, in.dlc, out); }

// Frame values for Write Parameter 108 and 109: Write Parameter 108 and 109 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_108_AND_109_t;

// Decode frame payload for Write Parameter 108 and 109: Write Parameter 108 and 109 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_108_AND_109(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_108_AND_109_t* out);
static inline bool spark_decode_WRITE_PARAMETER_108_AND_109_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_108_AND_109_t* out) { return spark_decode_WRITE_PARAMETER_108_AND_109(in.data, in.dlc, out); }

// Frame values for Write Parameter 110 and 111: Write Parameter 110 and 111 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_110_AND_111_t;

// Decode frame payload for Write Parameter 110 and 111: Write Parameter 110 and 111 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_110_AND_111(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_110_AND_111_t* out);
static inline bool spark_decode_WRITE_PARAMETER_110_AND_111_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_110_AND_111_t* out) { return spark_decode_WRITE_PARAMETER_110_AND_111(in.data, in.dlc, out); }

// Frame values for Write Parameter 112 and 113: Write Parameter 112 and 113 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_112_AND_113_t;

// Decode frame payload for Write Parameter 112 and 113: Write Parameter 112 and 113 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_112_AND_113(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_112_AND_113_t* out);
static inline bool spark_decode_WRITE_PARAMETER_112_AND_113_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_112_AND_113_t* out) { return spark_decode_WRITE_PARAMETER_112_AND_113(in.data, in.dlc, out); }

// Frame values for Write Parameter 114 and 115: Write Parameter 114 and 115 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_114_AND_115_t;

// Decode frame payload for Write Parameter 114 and 115: Write Parameter 114 and 115 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_114_AND_115(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_114_AND_115_t* out);
static inline bool spark_decode_WRITE_PARAMETER_114_AND_115_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_114_AND_115_t* out) { return spark_decode_WRITE_PARAMETER_114_AND_115(in.data, in.dlc, out); }

// Frame values for Write Parameter 116 and 117: Write Parameter 116 and 117 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_116_AND_117_t;

// Decode frame payload for Write Parameter 116 and 117: Write Parameter 116 and 117 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_116_AND_117(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_116_AND_117_t* out);
static inline bool spark_decode_WRITE_PARAMETER_116_AND_117_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_116_AND_117_t* out) { return spark_decode_WRITE_PARAMETER_116_AND_117(in.data, in.dlc, out); }

// Frame values for Write Parameter 118 and 119: Write Parameter 118 and 119 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_118_AND_119_t;

// Decode frame payload for Write Parameter 118 and 119: Write Parameter 118 and 119 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_118_AND_119(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_118_AND_119_t* out);
static inline bool spark_decode_WRITE_PARAMETER_118_AND_119_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_118_AND_119_t* out) { return spark_decode_WRITE_PARAMETER_118_AND_119(in.data, in.dlc, out); }

// Frame values for Write Parameter 120 and 121: Write Parameter 120 and 121 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_120_AND_121_t;

// Decode frame payload for Write Parameter 120 and 121: Write Parameter 120 and 121 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_120_AND_121(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_120_AND_121_t* out);
static inline bool spark_decode_WRITE_PARAMETER_120_AND_121_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_120_AND_121_t* out) { return spark_decode_WRITE_PARAMETER_120_AND_121(in.data, in.dlc, out); }

// Frame values for Write Parameter 122 and 123: Write Parameter 122 and 123 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_122_AND_123_t;

// Decode frame payload for Write Parameter 122 and 123: Write Parameter 122 and 123 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_122_AND_123(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_122_AND_123_t* out);
static inline bool spark_decode_WRITE_PARAMETER_122_AND_123_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_122_AND_123_t* out) { return spark_decode_WRITE_PARAMETER_122_AND_123(in.data, in.dlc, out); }

// Frame values for Write Parameter 124 and 125: Write Parameter 124 and 125 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_124_AND_125_t;

// Decode frame payload for Write Parameter 124 and 125: Write Parameter 124 and 125 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_124_AND_125(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_124_AND_125_t* out);
static inline bool spark_decode_WRITE_PARAMETER_124_AND_125_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_124_AND_125_t* out) { return spark_decode_WRITE_PARAMETER_124_AND_125(in.data, in.dlc, out); }

// Frame values for Write Parameter 126 and 127: Write Parameter 126 and 127 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_126_AND_127_t;

// Decode frame payload for Write Parameter 126 and 127: Write Parameter 126 and 127 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_126_AND_127(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_126_AND_127_t* out);
static inline bool spark_decode_WRITE_PARAMETER_126_AND_127_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_126_AND_127_t* out) { return spark_decode_WRITE_PARAMETER_126_AND_127(in.data, in.dlc, out); }

// Frame values for Write Parameter 128 and 129: Write Parameter 128 and 129 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_128_AND_129_t;

// Decode frame payload for Write Parameter 128 and 129: Write Parameter 128 and 129 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_128_AND_129(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_128_AND_129_t* out);
static inline bool spark_decode_WRITE_PARAMETER_128_AND_129_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_128_AND_129_t* out) { return spark_decode_WRITE_PARAMETER_128_AND_129(in.data, in.dlc, out); }

// Frame values for Write Parameter 130 and 131: Write Parameter 130 and 131 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_130_AND_131_t;

// Decode frame payload for Write Parameter 130 and 131: Write Parameter 130 and 131 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_130_AND_131(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_130_AND_131_t* out);
static inline bool spark_decode_WRITE_PARAMETER_130_AND_131_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_130_AND_131_t* out) { return spark_decode_WRITE_PARAMETER_130_AND_131(in.data, in.dlc, out); }

// Frame values for Write Parameter 132 and 133: Write Parameter 132 and 133 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_132_AND_133_t;

// Decode frame payload for Write Parameter 132 and 133: Write Parameter 132 and 133 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_132_AND_133(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_132_AND_133_t* out);
static inline bool spark_decode_WRITE_PARAMETER_132_AND_133_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_132_AND_133_t* out) { return spark_decode_WRITE_PARAMETER_132_AND_133(in.data, in.dlc, out); }

// Frame values for Write Parameter 134 and 135: Write Parameter 134 and 135 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_134_AND_135_t;

// Decode frame payload for Write Parameter 134 and 135: Write Parameter 134 and 135 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_134_AND_135(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_134_AND_135_t* out);
static inline bool spark_decode_WRITE_PARAMETER_134_AND_135_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_134_AND_135_t* out) { return spark_decode_WRITE_PARAMETER_134_AND_135(in.data, in.dlc, out); }

// Frame values for Write Parameter 136 and 137: Write Parameter 136 and 137 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_136_AND_137_t;

// Decode frame payload for Write Parameter 136 and 137: Write Parameter 136 and 137 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_136_AND_137(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_136_AND_137_t* out);
static inline bool spark_decode_WRITE_PARAMETER_136_AND_137_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_136_AND_137_t* out) { return spark_decode_WRITE_PARAMETER_136_AND_137(in.data, in.dlc, out); }

// Frame values for Write Parameter 138 and 139: Write Parameter 138 and 139 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_138_AND_139_t;

// Decode frame payload for Write Parameter 138 and 139: Write Parameter 138 and 139 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_138_AND_139(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_138_AND_139_t* out);
static inline bool spark_decode_WRITE_PARAMETER_138_AND_139_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_138_AND_139_t* out) { return spark_decode_WRITE_PARAMETER_138_AND_139(in.data, in.dlc, out); }

// Frame values for Write Parameter 140 and 141: Write Parameter 140 and 141 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_140_AND_141_t;

// Decode frame payload for Write Parameter 140 and 141: Write Parameter 140 and 141 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_140_AND_141(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_140_AND_141_t* out);
static inline bool spark_decode_WRITE_PARAMETER_140_AND_141_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_140_AND_141_t* out) { return spark_decode_WRITE_PARAMETER_140_AND_141(in.data, in.dlc, out); }

// Frame values for Write Parameter 142 and 143: Write Parameter 142 and 143 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_142_AND_143_t;

// Decode frame payload for Write Parameter 142 and 143: Write Parameter 142 and 143 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_142_AND_143(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_142_AND_143_t* out);
static inline bool spark_decode_WRITE_PARAMETER_142_AND_143_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_142_AND_143_t* out) { return spark_decode_WRITE_PARAMETER_142_AND_143(in.data, in.dlc, out); }

// Frame values for Write Parameter 144 and 145: Write Parameter 144 and 145 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_144_AND_145_t;

// Decode frame payload for Write Parameter 144 and 145: Write Parameter 144 and 145 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_144_AND_145(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_144_AND_145_t* out);
static inline bool spark_decode_WRITE_PARAMETER_144_AND_145_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_144_AND_145_t* out) { return spark_decode_WRITE_PARAMETER_144_AND_145(in.data, in.dlc, out); }

// Frame values for Write Parameter 146 and 147: Write Parameter 146 and 147 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_146_AND_147_t;

// Decode frame payload for Write Parameter 146 and 147: Write Parameter 146 and 147 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_146_AND_147(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_146_AND_147_t* out);
static inline bool spark_decode_WRITE_PARAMETER_146_AND_147_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_146_AND_147_t* out) { return spark_decode_WRITE_PARAMETER_146_AND_147(in.data, in.dlc, out); }

// Frame values for Write Parameter 148 and 149: Write Parameter 148 and 149 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_148_AND_149_t;

// Decode frame payload for Write Parameter 148 and 149: Write Parameter 148 and 149 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_148_AND_149(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_148_AND_149_t* out);
static inline bool spark_decode_WRITE_PARAMETER_148_AND_149_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_148_AND_149_t* out) { return spark_decode_WRITE_PARAMETER_148_AND_149(in.data, in.dlc, out); }

// Frame values for Write Parameter 150 and 151: Write Parameter 150 and 151 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_150_AND_151_t;

// Decode frame payload for Write Parameter 150 and 151: Write Parameter 150 and 151 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_150_AND_151(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_150_AND_151_t* out);
static inline bool spark_decode_WRITE_PARAMETER_150_AND_151_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_150_AND_151_t* out) { return spark_decode_WRITE_PARAMETER_150_AND_151(in.data, in.dlc, out); }

// Frame values for Write Parameter 152 and 153: Write Parameter 152 and 153 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_152_AND_153_t;

// Decode frame payload for Write Parameter 152 and 153: Write Parameter 152 and 153 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_152_AND_153(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_152_AND_153_t* out);
static inline bool spark_decode_WRITE_PARAMETER_152_AND_153_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_152_AND_153_t* out) { return spark_decode_WRITE_PARAMETER_152_AND_153(in.data, in.dlc, out); }

// Frame values for Write Parameter 154 and 155: Write Parameter 154 and 155 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_154_AND_155_t;

// Decode frame payload for Write Parameter 154 and 155: Write Parameter 154 and 155 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_154_AND_155(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_154_AND_155_t* out);
static inline bool spark_decode_WRITE_PARAMETER_154_AND_155_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_154_AND_155_t* out) { return spark_decode_WRITE_PARAMETER_154_AND_155(in.data, in.dlc, out); }

// Frame values for Write Parameter 156 and 157: Write Parameter 156 and 157 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_156_AND_157_t;

// Decode frame payload for Write Parameter 156 and 157: Write Parameter 156 and 157 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_156_AND_157(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_156_AND_157_t* out);
static inline bool spark_decode_WRITE_PARAMETER_156_AND_157_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_156_AND_157_t* out) { return spark_decode_WRITE_PARAMETER_156_AND_157(in.data, in.dlc, out); }

// Frame values for Write Parameter 158 and 159: Write Parameter 158 and 159 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_158_AND_159_t;

// Decode frame payload for Write Parameter 158 and 159: Write Parameter 158 and 159 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_158_AND_159(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_158_AND_159_t* out);
static inline bool spark_decode_WRITE_PARAMETER_158_AND_159_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_158_AND_159_t* out) { return spark_decode_WRITE_PARAMETER_158_AND_159(in.data, in.dlc, out); }

// Frame values for Write Parameter 160 and 161: Write Parameter 160 and 161 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_160_AND_161_t;

// Decode frame payload for Write Parameter 160 and 161: Write Parameter 160 and 161 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_160_AND_161(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_160_AND_161_t* out);
static inline bool spark_decode_WRITE_PARAMETER_160_AND_161_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_160_AND_161_t* out) { return spark_decode_WRITE_PARAMETER_160_AND_161(in.data, in.dlc, out); }

// Frame values for Write Parameter 162 and 163: Write Parameter 162 and 163 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_162_AND_163_t;

// Decode frame payload for Write Parameter 162 and 163: Write Parameter 162 and 163 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_162_AND_163(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_162_AND_163_t* out);
static inline bool spark_decode_WRITE_PARAMETER_162_AND_163_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_162_AND_163_t* out) { return spark_decode_WRITE_PARAMETER_162_AND_163(in.data, in.dlc, out); }

// Frame values for Write Parameter 164 and 165: Write Parameter 164 and 165 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_164_AND_165_t;

// Decode frame payload for Write Parameter 164 and 165: Write Parameter 164 and 165 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_164_AND_165(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_164_AND_165_t* out);
static inline bool spark_decode_WRITE_PARAMETER_164_AND_165_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_164_AND_165_t* out) { return spark_decode_WRITE_PARAMETER_164_AND_165(in.data, in.dlc, out); }

// Frame values for Write Parameter 166 and 167: Write Parameter 166 and 167 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_166_AND_167_t;

// Decode frame payload for Write Parameter 166 and 167: Write Parameter 166 and 167 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_166_AND_167(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_166_AND_167_t* out);
static inline bool spark_decode_WRITE_PARAMETER_166_AND_167_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_166_AND_167_t* out) { return spark_decode_WRITE_PARAMETER_166_AND_167(in.data, in.dlc, out); }

// Frame values for Write Parameter 168 and 169: Write Parameter 168 and 169 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_168_AND_169_t;

// Decode frame payload for Write Parameter 168 and 169: Write Parameter 168 and 169 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_168_AND_169(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_168_AND_169_t* out);
static inline bool spark_decode_WRITE_PARAMETER_168_AND_169_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_168_AND_169_t* out) { return spark_decode_WRITE_PARAMETER_168_AND_169(in.data, in.dlc, out); }

// Frame values for Write Parameter 170 and 171: Write Parameter 170 and 171 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_170_AND_171_t;

// Decode frame payload for Write Parameter 170 and 171: Write Parameter 170 and 171 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_170_AND_171(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_170_AND_171_t* out);
static inline bool spark_decode_WRITE_PARAMETER_170_AND_171_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_170_AND_171_t* out) { return spark_decode_WRITE_PARAMETER_170_AND_171(in.data, in.dlc, out); }

// Frame values for Write Parameter 172 and 173: Write Parameter 172 and 173 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_172_AND_173_t;

// Decode frame payload for Write Parameter 172 and 173: Write Parameter 172 and 173 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_172_AND_173(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_172_AND_173_t* out);
static inline bool spark_decode_WRITE_PARAMETER_172_AND_173_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_172_AND_173_t* out) { return spark_decode_WRITE_PARAMETER_172_AND_173(in.data, in.dlc, out); }

// Frame values for Write Parameter 174 and 175: Write Parameter 174 and 175 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_174_AND_175_t;

// Decode frame payload for Write Parameter 174 and 175: Write Parameter 174 and 175 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_174_AND_175(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_174_AND_175_t* out);
static inline bool spark_decode_WRITE_PARAMETER_174_AND_175_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_174_AND_175_t* out) { return spark_decode_WRITE_PARAMETER_174_AND_175(in.data, in.dlc, out); }

// Frame values for Write Parameter 176 and 177: Write Parameter 176 and 177 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_176_AND_177_t;

// Decode frame payload for Write Parameter 176 and 177: Write Parameter 176 and 177 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_176_AND_177(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_176_AND_177_t* out);
static inline bool spark_decode_WRITE_PARAMETER_176_AND_177_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_176_AND_177_t* out) { return spark_decode_WRITE_PARAMETER_176_AND_177(in.data, in.dlc, out); }

// Frame values for Write Parameter 178 and 179: Write Parameter 178 and 179 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_178_AND_179_t;

// Decode frame payload for Write Parameter 178 and 179: Write Parameter 178 and 179 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_178_AND_179(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_178_AND_179_t* out);
static inline bool spark_decode_WRITE_PARAMETER_178_AND_179_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_178_AND_179_t* out) { return spark_decode_WRITE_PARAMETER_178_AND_179(in.data, in.dlc, out); }

// Frame values for Write Parameter 180 and 181: Write Parameter 180 and 181 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_180_AND_181_t;

// Decode frame payload for Write Parameter 180 and 181: Write Parameter 180 and 181 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_180_AND_181(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_180_AND_181_t* out);
static inline bool spark_decode_WRITE_PARAMETER_180_AND_181_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_180_AND_181_t* out) { return spark_decode_WRITE_PARAMETER_180_AND_181(in.data, in.dlc, out); }

// Frame values for Write Parameter 182 and 183: Write Parameter 182 and 183 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_182_AND_183_t;

// Decode frame payload for Write Parameter 182 and 183: Write Parameter 182 and 183 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_182_AND_183(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_182_AND_183_t* out);
static inline bool spark_decode_WRITE_PARAMETER_182_AND_183_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_182_AND_183_t* out) { return spark_decode_WRITE_PARAMETER_182_AND_183(in.data, in.dlc, out); }

// Frame values for Write Parameter 184 and 185: Write Parameter 184 and 185 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_184_AND_185_t;

// Decode frame payload for Write Parameter 184 and 185: Write Parameter 184 and 185 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_184_AND_185(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_184_AND_185_t* out);
static inline bool spark_decode_WRITE_PARAMETER_184_AND_185_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_184_AND_185_t* out) { return spark_decode_WRITE_PARAMETER_184_AND_185(in.data, in.dlc, out); }

// Frame values for Write Parameter 186 and 187: Write Parameter 186 and 187 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_186_AND_187_t;

// Decode frame payload for Write Parameter 186 and 187: Write Parameter 186 and 187 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_186_AND_187(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_186_AND_187_t* out);
static inline bool spark_decode_WRITE_PARAMETER_186_AND_187_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_186_AND_187_t* out) { return spark_decode_WRITE_PARAMETER_186_AND_187(in.data, in.dlc, out); }

// Frame values for Write Parameter 188 and 189: Write Parameter 188 and 189 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_188_AND_189_t;

// Decode frame payload for Write Parameter 188 and 189: Write Parameter 188 and 189 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_188_AND_189(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_188_AND_189_t* out);
static inline bool spark_decode_WRITE_PARAMETER_188_AND_189_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_188_AND_189_t* out) { return spark_decode_WRITE_PARAMETER_188_AND_189(in.data, in.dlc, out); }

// Frame values for Write Parameter 190 and 191: Write Parameter 190 and 191 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_190_AND_191_t;

// Decode frame payload for Write Parameter 190 and 191: Write Parameter 190 and 191 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_190_AND_191(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_190_AND_191_t* out);
static inline bool spark_decode_WRITE_PARAMETER_190_AND_191_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_190_AND_191_t* out) { return spark_decode_WRITE_PARAMETER_190_AND_191(in.data, in.dlc, out); }

// Frame values for Write Parameter 192 and 193: Write Parameter 192 and 193 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_192_AND_193_t;

// Decode frame payload for Write Parameter 192 and 193: Write Parameter 192 and 193 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_192_AND_193(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_192_AND_193_t* out);
static inline bool spark_decode_WRITE_PARAMETER_192_AND_193_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_192_AND_193_t* out) { return spark_decode_WRITE_PARAMETER_192_AND_193(in.data, in.dlc, out); }

// Frame values for Write Parameter 194 and 195: Write Parameter 194 and 195 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_194_AND_195_t;

// Decode frame payload for Write Parameter 194 and 195: Write Parameter 194 and 195 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_194_AND_195(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_194_AND_195_t* out);
static inline bool spark_decode_WRITE_PARAMETER_194_AND_195_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_194_AND_195_t* out) { return spark_decode_WRITE_PARAMETER_194_AND_195(in.data, in.dlc, out); }

// Frame values for Write Parameter 196 and 197: Write Parameter 196 and 197 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_196_AND_197_t;

// Decode frame payload for Write Parameter 196 and 197: Write Parameter 196 and 197 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_196_AND_197(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_196_AND_197_t* out);
static inline bool spark_decode_WRITE_PARAMETER_196_AND_197_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_196_AND_197_t* out) { return spark_decode_WRITE_PARAMETER_196_AND_197(in.data, in.dlc, out); }

// Frame values for Write Parameter 198 and 199: Write Parameter 198 and 199 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_198_AND_199_t;

// Decode frame payload for Write Parameter 198 and 199: Write Parameter 198 and 199 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_198_AND_199(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_198_AND_199_t* out);
static inline bool spark_decode_WRITE_PARAMETER_198_AND_199_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_198_AND_199_t* out) { return spark_decode_WRITE_PARAMETER_198_AND_199(in.data, in.dlc, out); }

// Frame values for Write Parameter 200 and 201: Write Parameter 200 and 201 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_200_AND_201_t;

// Decode frame payload for Write Parameter 200 and 201: Write Parameter 200 and 201 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_200_AND_201(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_200_AND_201_t* out);
static inline bool spark_decode_WRITE_PARAMETER_200_AND_201_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_200_AND_201_t* out) { return spark_decode_WRITE_PARAMETER_200_AND_201(in.data, in.dlc, out); }

// Frame values for Write Parameter 202 and 203: Write Parameter 202 and 203 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_202_AND_203_t;

// Decode frame payload for Write Parameter 202 and 203: Write Parameter 202 and 203 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_202_AND_203(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_202_AND_203_t* out);
static inline bool spark_decode_WRITE_PARAMETER_202_AND_203_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_202_AND_203_t* out) { return spark_decode_WRITE_PARAMETER_202_AND_203(in.data, in.dlc, out); }

// Frame values for Write Parameter 204 and 205: Write Parameter 204 and 205 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_204_AND_205_t;

// Decode frame payload for Write Parameter 204 and 205: Write Parameter 204 and 205 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_204_AND_205(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_204_AND_205_t* out);
static inline bool spark_decode_WRITE_PARAMETER_204_AND_205_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_204_AND_205_t* out) { return spark_decode_WRITE_PARAMETER_204_AND_205(in.data, in.dlc, out); }

// Frame values for Write Parameter 206 and 207: Write Parameter 206 and 207 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_206_AND_207_t;

// Decode frame payload for Write Parameter 206 and 207: Write Parameter 206 and 207 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_206_AND_207(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_206_AND_207_t* out);
static inline bool spark_decode_WRITE_PARAMETER_206_AND_207_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_206_AND_207_t* out) { return spark_decode_WRITE_PARAMETER_206_AND_207(in.data, in.dlc, out); }

// Frame values for Write Parameter 208 and 209: Write Parameter 208 and 209 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_208_AND_209_t;

// Decode frame payload for Write Parameter 208 and 209: Write Parameter 208 and 209 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_208_AND_209(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_208_AND_209_t* out);
static inline bool spark_decode_WRITE_PARAMETER_208_AND_209_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_208_AND_209_t* out) { return spark_decode_WRITE_PARAMETER_208_AND_209(in.data, in.dlc, out); }

// Frame values for Write Parameter 210 and 211: Write Parameter 210 and 211 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_210_AND_211_t;

// Decode frame payload for Write Parameter 210 and 211: Write Parameter 210 and 211 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_210_AND_211(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_210_AND_211_t* out);
static inline bool spark_decode_WRITE_PARAMETER_210_AND_211_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_210_AND_211_t* out) { return spark_decode_WRITE_PARAMETER_210_AND_211(in.data, in.dlc, out); }

// Frame values for Write Parameter 212 and 213: Write Parameter 212 and 213 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_212_AND_213_t;

// Decode frame payload for Write Parameter 212 and 213: Write Parameter 212 and 213 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_212_AND_213(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_212_AND_213_t* out);
static inline bool spark_decode_WRITE_PARAMETER_212_AND_213_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_212_AND_213_t* out) { return spark_decode_WRITE_PARAMETER_212_AND_213(in.data, in.dlc, out); }

// Frame values for Write Parameter 214 and 215: Write Parameter 214 and 215 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_214_AND_215_t;

// Decode frame payload for Write Parameter 214 and 215: Write Parameter 214 and 215 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_214_AND_215(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_214_AND_215_t* out);
static inline bool spark_decode_WRITE_PARAMETER_214_AND_215_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_214_AND_215_t* out) { return spark_decode_WRITE_PARAMETER_214_AND_215(in.data, in.dlc, out); }

// Frame values for Write Parameter 216 and 217: Write Parameter 216 and 217 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_216_AND_217_t;

// Decode frame payload for Write Parameter 216 and 217: Write Parameter 216 and 217 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_216_AND_217(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_216_AND_217_t* out);
static inline bool spark_decode_WRITE_PARAMETER_216_AND_217_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_216_AND_217_t* out) { return spark_decode_WRITE_PARAMETER_216_AND_217(in.data, in.dlc, out); }

// Frame values for Write Parameter 218 and 219: Write Parameter 218 and 219 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_218_AND_219_t;

// Decode frame payload for Write Parameter 218 and 219: Write Parameter 218 and 219 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_218_AND_219(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_218_AND_219_t* out);
static inline bool spark_decode_WRITE_PARAMETER_218_AND_219_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_218_AND_219_t* out) { return spark_decode_WRITE_PARAMETER_218_AND_219(in.data, in.dlc, out); }

// Frame values for Write Parameter 220 and 221: Write Parameter 220 and 221 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_220_AND_221_t;

// Decode frame payload for Write Parameter 220 and 221: Write Parameter 220 and 221 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_220_AND_221(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_220_AND_221_t* out);
static inline bool spark_decode_WRITE_PARAMETER_220_AND_221_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_220_AND_221_t* out) { return spark_decode_WRITE_PARAMETER_220_AND_221(in.data, in.dlc, out); }

// Frame values for Write Parameter 222 and 223: Write Parameter 222 and 223 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_222_AND_223_t;

// Decode frame payload for Write Parameter 222 and 223: Write Parameter 222 and 223 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_222_AND_223(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_222_AND_223_t* out);
static inline bool spark_decode_WRITE_PARAMETER_222_AND_223_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_222_AND_223_t* out) { return spark_decode_WRITE_PARAMETER_222_AND_223(in.data, in.dlc, out); }

// Frame values for Write Parameter 224 and 225: Write Parameter 224 and 225 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_224_AND_225_t;

// Decode frame payload for Write Parameter 224 and 225: Write Parameter 224 and 225 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_224_AND_225(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_224_AND_225_t* out);
static inline bool spark_decode_WRITE_PARAMETER_224_AND_225_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_224_AND_225_t* out) { return spark_decode_WRITE_PARAMETER_224_AND_225(in.data, in.dlc, out); }

// Frame values for Write Parameter 226 and 227: Write Parameter 226 and 227 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_226_AND_227_t;

// Decode frame payload for Write Parameter 226 and 227: Write Parameter 226 and 227 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_226_AND_227(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_226_AND_227_t* out);
static inline bool spark_decode_WRITE_PARAMETER_226_AND_227_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_226_AND_227_t* out) { return spark_decode_WRITE_PARAMETER_226_AND_227(in.data, in.dlc, out); }

// Frame values for Write Parameter 228 and 229: Write Parameter 228 and 229 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_228_AND_229_t;

// Decode frame payload for Write Parameter 228 and 229: Write Parameter 228 and 229 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_228_AND_229(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_228_AND_229_t* out);
static inline bool spark_decode_WRITE_PARAMETER_228_AND_229_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_228_AND_229_t* out) { return spark_decode_WRITE_PARAMETER_228_AND_229(in.data, in.dlc, out); }

// Frame values for Write Parameter 230 and 231: Write Parameter 230 and 231 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_230_AND_231_t;

// Decode frame payload for Write Parameter 230 and 231: Write Parameter 230 and 231 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_230_AND_231(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_230_AND_231_t* out);
static inline bool spark_decode_WRITE_PARAMETER_230_AND_231_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_230_AND_231_t* out) { return spark_decode_WRITE_PARAMETER_230_AND_231(in.data, in.dlc, out); }

// Frame values for Write Parameter 232 and 233: Write Parameter 232 and 233 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_232_AND_233_t;

// Decode frame payload for Write Parameter 232 and 233: Write Parameter 232 and 233 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_232_AND_233(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_232_AND_233_t* out);
static inline bool spark_decode_WRITE_PARAMETER_232_AND_233_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_232_AND_233_t* out) { return spark_decode_WRITE_PARAMETER_232_AND_233(in.data, in.dlc, out); }

// Frame values for Write Parameter 234 and 235: Write Parameter 234 and 235 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_234_AND_235_t;

// Decode frame payload for Write Parameter 234 and 235: Write Parameter 234 and 235 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_234_AND_235(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_234_AND_235_t* out);
static inline bool spark_decode_WRITE_PARAMETER_234_AND_235_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_234_AND_235_t* out) { return spark_decode_WRITE_PARAMETER_234_AND_235(in.data, in.dlc, out); }

// Frame values for Write Parameter 236 and 237: Write Parameter 236 and 237 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_236_AND_237_t;

// Decode frame payload for Write Parameter 236 and 237: Write Parameter 236 and 237 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_236_AND_237(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_236_AND_237_t* out);
static inline bool spark_decode_WRITE_PARAMETER_236_AND_237_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_236_AND_237_t* out) { return spark_decode_WRITE_PARAMETER_236_AND_237(in.data, in.dlc, out); }

// Frame values for Write Parameter 238 and 239: Write Parameter 238 and 239 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_238_AND_239_t;

// Decode frame payload for Write Parameter 238 and 239: Write Parameter 238 and 239 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_238_AND_239(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_238_AND_239_t* out);
static inline bool spark_decode_WRITE_PARAMETER_238_AND_239_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_238_AND_239_t* out) { return spark_decode_WRITE_PARAMETER_238_AND_239(in.data, in.dlc, out); }

// Frame values for Write Parameter 240 and 241: Write Parameter 240 and 241 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_240_AND_241_t;

// Decode frame payload for Write Parameter 240 and 241: Write Parameter 240 and 241 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_240_AND_241(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_240_AND_241_t* out);
static inline bool spark_decode_WRITE_PARAMETER_240_AND_241_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_240_AND_241_t* out) { return spark_decode_WRITE_PARAMETER_240_AND_241(in.data, in.dlc, out); }

// Frame values for Write Parameter 242 and 243: Write Parameter 242 and 243 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_242_AND_243_t;

// Decode frame payload for Write Parameter 242 and 243: Write Parameter 242 and 243 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_242_AND_243(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_242_AND_243_t* out);
static inline bool spark_decode_WRITE_PARAMETER_242_AND_243_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_242_AND_243_t* out) { return spark_decode_WRITE_PARAMETER_242_AND_243(in.data, in.dlc, out); }

// Frame values for Write Parameter 244 and 245: Write Parameter 244 and 245 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_244_AND_245_t;

// Decode frame payload for Write Parameter 244 and 245: Write Parameter 244 and 245 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_244_AND_245(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_244_AND_245_t* out);
static inline bool spark_decode_WRITE_PARAMETER_244_AND_245_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_244_AND_245_t* out) { return spark_decode_WRITE_PARAMETER_244_AND_245(in.data, in.dlc, out); }

// Frame values for Write Parameter 246 and 247: Write Parameter 246 and 247 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_246_AND_247_t;

// Decode frame payload for Write Parameter 246 and 247: Write Parameter 246 and 247 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_246_AND_247(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_246_AND_247_t* out);
static inline bool spark_decode_WRITE_PARAMETER_246_AND_247_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_246_AND_247_t* out) { return spark_decode_WRITE_PARAMETER_246_AND_247(in.data, in.dlc, out); }

// Frame values for Write Parameter 248 and 249: Write Parameter 248 and 249 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_248_AND_249_t;

// Decode frame payload for Write Parameter 248 and 249: Write Parameter 248 and 249 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_248_AND_249(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_248_AND_249_t* out);
static inline bool spark_decode_WRITE_PARAMETER_248_AND_249_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_248_AND_249_t* out) { return spark_decode_WRITE_PARAMETER_248_AND_249(in.data, in.dlc, out); }

// Frame values for Write Parameter 250 and 251: Write Parameter 250 and 251 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_250_AND_251_t;

// Decode frame payload for Write Parameter 250 and 251: Write Parameter 250 and 251 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_250_AND_251(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_250_AND_251_t* out);
static inline bool spark_decode_WRITE_PARAMETER_250_AND_251_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_250_AND_251_t* out) { return spark_decode_WRITE_PARAMETER_250_AND_251(in.data, in.dlc, out); }

// Frame values for Write Parameter 252 and 253: Write Parameter 252 and 253 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_252_AND_253_t;

// Decode frame payload for Write Parameter 252 and 253: Write Parameter 252 and 253 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_252_AND_253(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_252_AND_253_t* out);
static inline bool spark_decode_WRITE_PARAMETER_252_AND_253_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_252_AND_253_t* out) { return spark_decode_WRITE_PARAMETER_252_AND_253(in.data, in.dlc, out); }

// Frame values for Write Parameter 254 and 255: Write Parameter 254 and 255 at the same time. Two Write Parameter Response frames will be sent in response.
typedef struct {
    // First Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t FIRST_PARAMETER_VALUE;
    // Second Parameter Value: The actual type of this data depends on the Parameter Type of the parameter in question
    uint32_t SECOND_PARAMETER_VALUE;
} Spark_WRITE_PARAMETER_254_AND_255_t;

// Decode frame payload for Write Parameter 254 and 255: Write Parameter 254 and 255 at the same time. Two Write Parameter Response frames will be sent in response.
bool spark_decode_WRITE_PARAMETER_254_AND_255(const uint8_t* data, uint8_t dlc, Spark_WRITE_PARAMETER_254_AND_255_t* out);
static inline bool spark_decode_WRITE_PARAMETER_254_AND_255_frame(const spark_can_frame& in, Spark_WRITE_PARAMETER_254_AND_255_t* out) { return spark_decode_WRITE_PARAMETER_254_AND_255(in.data, in.dlc, out); }

// Frame values for Start Follower Mode: Starts follower mode. The relevant parameters must already be configured. In response, a Start Follower Mode Response frame will be sent. Follower mode will be auto-started on boot if the Follower Mode Leader ID parameter is set to a non-zero value.
typedef struct {
    uint8_t _reserved0; // no payload fields
} Spark_START_FOLLOWER_MODE_t;

// Frame values for Start Follower Mode Response: Response for a Start Follower Mode command
typedef struct {
    // status: 0 for success. 1 for invalid parameters
    uint8_t STATUS;
} Spark_START_FOLLOWER_MODE_RESPONSE_t;

// Decode frame payload for Start Follower Mode Response: Response for a Start Follower Mode command
bool spark_decode_START_FOLLOWER_MODE_RESPONSE(const uint8_t* data, uint8_t dlc, Spark_START_FOLLOWER_MODE_RESPONSE_t* out);
static inline bool spark_decode_START_FOLLOWER_MODE_RESPONSE_frame(const spark_can_frame& in, Spark_START_FOLLOWER_MODE_RESPONSE_t* out) { return spark_decode_START_FOLLOWER_MODE_RESPONSE(in.data, in.dlc, out); }

// Frame values for Stop Follower Mode: Exits follower mode and causes the device to resume listening for setpoints addressed directly to it. In response, a Stop Follower Mode Response frame will be sent.
typedef struct {
    uint8_t _reserved0; // no payload fields
} Spark_STOP_FOLLOWER_MODE_t;

// Frame values for Stop Follower Mode Response: Response for a Stop Follower Mode Command
typedef struct {
    uint8_t _reserved0; // no payload fields
} Spark_STOP_FOLLOWER_MODE_RESPONSE_t;

// Frame values for Enter SWDL CAN Bootloader
typedef struct {
    uint8_t _reserved0; // no payload fields
} Spark_ENTER_SWDL_CAN_BOOTLOADER_t;

// Frame values for Persist Parameters: Causes all parameters to be written to non-volatile storage. After the operation (which may take up to a second) completes, a Persist Parameters Response frame will be sent.
typedef struct {
    // Magic Number
    uint16_t MAGIC_NUMBER;
} Spark_PERSIST_PARAMETERS_t;

// Decode frame payload for Persist Parameters: Causes all parameters to be written to non-volatile storage. After the operation (which may take up to a second) completes, a Persist Parameters Response frame will be sent.
bool spark_decode_PERSIST_PARAMETERS(const uint8_t* data, uint8_t dlc, Spark_PERSIST_PARAMETERS_t* out);
static inline bool spark_decode_PERSIST_PARAMETERS_frame(const spark_can_frame& in, Spark_PERSIST_PARAMETERS_t* out) { return spark_decode_PERSIST_PARAMETERS(in.data, in.dlc, out); }

// Build frame for Velocity Setpoint: Sets the Control Type to Velocity and sets the target velocity
spark_can_frame spark_build_VELOCITY_SETPOINT(uint8_t device_id, const Spark_VELOCITY_SETPOINT_t* values);

// Build frame for Duty Cycle Setpoint: Sets the Control Type to Duty Cycle and sets the target duty cycle (from -1 to 1)
spark_can_frame spark_build_DUTY_CYCLE_SETPOINT(uint8_t device_id, const Spark_DUTY_CYCLE_SETPOINT_t* values);

// Build frame for Position Setpoint: Sets the Control Type to Position and sets the target position
spark_can_frame spark_build_POSITION_SETPOINT(uint8_t device_id, const Spark_POSITION_SETPOINT_t* values);

// Build frame for Voltage Setpoint: Sets the Control Type to Voltage and sets the target voltage
spark_can_frame spark_build_VOLTAGE_SETPOINT(uint8_t device_id, const Spark_VOLTAGE_SETPOINT_t* values);

// Build frame for Current Setpoint: Sets the Control Type to Current and sets the target current
spark_can_frame spark_build_CURRENT_SETPOINT(uint8_t device_id, const Spark_CURRENT_SETPOINT_t* values);

// Build frame for MAXMotion Position Setpoint: Sets the Control Type to MAXMotion Position Control and sets the target position
spark_can_frame spark_build_MAXMOTION_POSITION_SETPOINT(uint8_t device_id, const Spark_MAXMOTION_POSITION_SETPOINT_t* values);

// Build frame for MAXMotion Velocity Setpoint: Sets the Control Type to MAXMotion Velocity Control and sets the target velocity
spark_can_frame spark_build_MAXMOTION_VELOCITY_SETPOINT(uint8_t device_id, const Spark_MAXMOTION_VELOCITY_SETPOINT_t* values);

// Build frame for Set Statuses Enabled: Enable or disable status frames. In response, a Set Statuses Enabled Response frame will be sent.
spark_can_frame spark_build_SET_STATUSES_ENABLED(uint8_t device_id, const Spark_SET_STATUSES_ENABLED_t* values);

// Build frame for Set Statuses Enabled Response: Response for a Set Statuses Enabled command
spark_can_frame spark_build_SET_STATUSES_ENABLED_RESPONSE(uint8_t device_id, const Spark_SET_STATUSES_ENABLED_RESPONSE_t* values);

// Build frame for Persist Parameters Response
spark_can_frame spark_build_PERSIST_PARAMETERS_RESPONSE(uint8_t device_id, const Spark_PERSIST_PARAMETERS_RESPONSE_t* values);

// Build frame for Reset Safe Parameters: Resets most writable parameters to their default values, except CAN ID, Motor Type, Idle Mode, PWM Input Deadband, and Duty Cycle Offset. In response, a Reset Safe Parameters Response frame is sent.
spark_can_frame spark_build_RESET_SAFE_PARAMETERS(uint8_t device_id, const Spark_RESET_SAFE_PARAMETERS_t* values);

// Build frame for Reset Safe Parameters Response: Response for a Reset Safe Parameters command
spark_can_frame spark_build_RESET_SAFE_PARAMETERS_RESPONSE(uint8_t device_id, const Spark_RESET_SAFE_PARAMETERS_RESPONSE_t* values);

// Build frame for Complete Factory Reset: Resets all writable parameters to default values, even CAN ID, Motor Type, Idle Mode, PWM Input Deadband, and Duty Cycle Offset. In response, a Complete Factory Reset Response frame is sent.
spark_can_frame spark_build_COMPLETE_FACTORY_RESET(uint8_t device_id, const Spark_COMPLETE_FACTORY_RESET_t* values);

// Build frame for Complete Factory Reset Response: Response for a Complete Factory Reset command
spark_can_frame spark_build_COMPLETE_FACTORY_RESET_RESPONSE(uint8_t device_id, const Spark_COMPLETE_FACTORY_RESET_RESPONSE_t* values);

// Build frame for Clear Faults
spark_can_frame spark_build_CLEAR_FAULTS(uint8_t device_id, const Spark_CLEAR_FAULTS_t* values);

// Build frame for Identify Unique SPARK: Makes the specified, single SPARK (even if there are multiple SPARKs that have the same CAN ID) temporarily perform a special blink pattern that will make it stand out
spark_can_frame spark_build_IDENTIFY_UNIQUE_SPARK(uint8_t device_id, const Spark_IDENTIFY_UNIQUE_SPARK_t* values);

// Build frame for Identify: Makes the SPARK temporarily perform a special blink pattern that will make it stand out. Use Identify Unique Device if there may be multiple SPARKs with the same CAN ID.
spark_can_frame spark_build_IDENTIFY(uint8_t device_id, const Spark_IDENTIFY_t* values);

// Build frame for Nack: As of SPARK MAX firmware 1.6.3, this is only used as a potential response to setting the CAN ID
spark_can_frame spark_build_NACK(uint8_t device_id, const Spark_NACK_t* values);

// Build frame for Ack: As of SPARK MAX firmware 1.6.3, this is only used as a potential response to setting the CAN ID
spark_can_frame spark_build_ACK(uint8_t device_id, const Spark_ACK_t* values);

// Build frame for LED Sync: Causes all SPARKs on the bus to synchronize their LED patterns
spark_can_frame spark_build_LED_SYNC(uint8_t device_id, const Spark_LED_SYNC_t* values);

// Build frame for Set CAN ID: Allows changing the CAN ID when multiple devices on the bus currently have the same CAN ID. Under normal circumstances, the CAN ID parameter can be used.
spark_can_frame spark_build_SET_CAN_ID(uint8_t device_id, const Spark_SET_CAN_ID_t* values);

// Build frame for Get Firmware Version
spark_can_frame spark_build_GET_FIRMWARE_VERSION(uint8_t device_id, const Spark_GET_FIRMWARE_VERSION_t* values);

// Build frame for SWDL Data: Broadcast from the host to all SPARKs in SWDL mode, containing a slice of firmware data
spark_can_frame spark_build_SWDL_DATA(uint8_t device_id, const Spark_SWDL_DATA_t* values);

// Build frame for SWDL Checksum: Broadcast from the host to all SPARKs in SWDL mode, containing the checksum of the full firmware image that was just sent
spark_can_frame spark_build_SWDL_CHECKSUM(uint8_t device_id, const Spark_SWDL_CHECKSUM_t* values);

// Build frame for SWDL Retransmit: Sent by SPARK devices in response to receiving an SWDL Checksum frame that does not match the firmware data they received
spark_can_frame spark_build_SWDL_RETRANSMIT(uint8_t device_id, const Spark_SWDL_RETRANSMIT_t* values);

// Build frame for Set Primary Encoder Position
spark_can_frame spark_build_SET_PRIMARY_ENCODER_POSITION(uint8_t device_id, const Spark_SET_PRIMARY_ENCODER_POSITION_t* values);

// Build frame for Set I Accumulation
spark_can_frame spark_build_SET_I_ACCUMULATION(uint8_t device_id, const Spark_SET_I_ACCUMULATION_t* values);

// Build frame for Set Analog Position
spark_can_frame spark_build_SET_ANALOG_POSITION(uint8_t device_id, const Spark_SET_ANALOG_POSITION_t* values);

// Build frame for Set Ext or Alt Encoder Position
spark_can_frame spark_build_SET_EXT_OR_ALT_ENCODER_POSITION(uint8_t device_id, const Spark_SET_EXT_OR_ALT_ENCODER_POSITION_t* values);

// Build frame for Set Duty Cycle Position
spark_can_frame spark_build_SET_DUTY_CYCLE_POSITION(uint8_t device_id, const Spark_SET_DUTY_CYCLE_POSITION_t* values);

// Build frame for Secondary Heartbeat: Heartbeat that allows enabling only specific SPARKs, but only gets respected when the SPARK is not locked to the Universal Heartbeat or Primary Heartbeat
spark_can_frame spark_build_SECONDARY_HEARTBEAT(uint8_t device_id, const Spark_SECONDARY_HEARTBEAT_t* values);

// Build frame for USB Only Identify: The response will only be sent if this command is received directly via USB. This has no relation to the normal Identify command, which displays an LED pattern.
spark_can_frame spark_build_USB_ONLY_IDENTIFY(uint8_t device_id, const Spark_USB_ONLY_IDENTIFY_t* values);

// Build frame for USB Only Enter DFU Bootloader: Causes the device to reboot into the DFU bootloader if this command is received directly via USB
spark_can_frame spark_build_USB_ONLY_ENTER_DFU_BOOTLOADER(uint8_t device_id, const Spark_USB_ONLY_ENTER_DFU_BOOTLOADER_t* values);

// Build frame for Get Temperatures
spark_can_frame spark_build_GET_TEMPERATURES(uint8_t device_id, const Spark_GET_TEMPERATURES_t* values);

// Build frame for Get Motor Interface
spark_can_frame spark_build_GET_MOTOR_INTERFACE(uint8_t device_id, const Spark_GET_MOTOR_INTERFACE_t* values);

// Build frame for Get Parameter 0 to 15 Types: Get types of parameters 0 to 15
spark_can_frame spark_build_GET_PARAMETER_0_TO_15_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_0_TO_15_TYPES_t* values);

// Build frame for Get Parameter 16 to 31 Types: Get types of parameters 16 to 31
spark_can_frame spark_build_GET_PARAMETER_16_TO_31_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_16_TO_31_TYPES_t* values);

// Build frame for Get Parameter 32 to 47 Types: Get types of parameters 32 to 47
spark_can_frame spark_build_GET_PARAMETER_32_TO_47_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_32_TO_47_TYPES_t* values);

// Build frame for Get Parameter 48 to 63 Types: Get types of parameters 48 to 63
spark_can_frame spark_build_GET_PARAMETER_48_TO_63_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_48_TO_63_TYPES_t* values);

// Build frame for Get Parameter 64 to 79 Types: Get types of parameters 64 to 79
spark_can_frame spark_build_GET_PARAMETER_64_TO_79_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_64_TO_79_TYPES_t* values);

// Build frame for Get Parameter 80 to 95 Types: Get types of parameters 80 to 95
spark_can_frame spark_build_GET_PARAMETER_80_TO_95_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_80_TO_95_TYPES_t* values);

// Build frame for Get Parameter 96 to 111 Types: Get types of parameters 96 to 111
spark_can_frame spark_build_GET_PARAMETER_96_TO_111_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_96_TO_111_TYPES_t* values);

// Build frame for Get Parameter 112 to 127 Types: Get types of parameters 112 to 127
spark_can_frame spark_build_GET_PARAMETER_112_TO_127_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_112_TO_127_TYPES_t* values);

// Build frame for Get Parameter 128 to 143 Types: Get types of parameters 128 to 143
spark_can_frame spark_build_GET_PARAMETER_128_TO_143_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_128_TO_143_TYPES_t* values);

// Build frame for Get Parameter 144 to 159 Types: Get types of parameters 144 to 159
spark_can_frame spark_build_GET_PARAMETER_144_TO_159_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_144_TO_159_TYPES_t* values);

// Build frame for Get Parameter 160 to 175 Types: Get types of parameters 160 to 175
spark_can_frame spark_build_GET_PARAMETER_160_TO_175_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_160_TO_175_TYPES_t* values);

// Build frame for Get Parameter 176 to 191 Types: Get types of parameters 176 to 191
spark_can_frame spark_build_GET_PARAMETER_176_TO_191_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_176_TO_191_TYPES_t* values);

// Build frame for Get Parameter 192 to 207 Types: Get types of parameters 192 to 207
spark_can_frame spark_build_GET_PARAMETER_192_TO_207_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_192_TO_207_TYPES_t* values);

// Build frame for Get Parameter 208 to 223 Types: Get types of parameters 208 to 223
spark_can_frame spark_build_GET_PARAMETER_208_TO_223_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_208_TO_223_TYPES_t* values);

// Build frame for Get Parameter 224 to 239 Types: Get types of parameters 224 to 239
spark_can_frame spark_build_GET_PARAMETER_224_TO_239_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_224_TO_239_TYPES_t* values);

// Build frame for Get Parameter 240 to 255 Types: Get types of parameters 240 to 255
spark_can_frame spark_build_GET_PARAMETER_240_TO_255_TYPES(uint8_t device_id, const Spark_GET_PARAMETER_240_TO_255_TYPES_t* values);

// Build frame for Parameter Write: Write a single parameter value. In response, a Parameter Write Response frame will be sent.
spark_can_frame spark_build_PARAMETER_WRITE(uint8_t device_id, const Spark_PARAMETER_WRITE_t* values);

// Build frame for Parameter Write Response: Response for a parameter write (including a write done as part of a dual-write)
spark_can_frame spark_build_PARAMETER_WRITE_RESPONSE(uint8_t device_id, const Spark_PARAMETER_WRITE_RESPONSE_t* values);

// Build frame for Read Parameter 0 and 1: Read parameter 0 and 1 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_0_AND_1(uint8_t device_id, const Spark_READ_PARAMETER_0_AND_1_t* values);

// Build frame for Read Parameter 2 and 3: Read parameter 2 and 3 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_2_AND_3(uint8_t device_id, const Spark_READ_PARAMETER_2_AND_3_t* values);

// Build frame for Read Parameter 4 and 5: Read parameter 4 and 5 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_4_AND_5(uint8_t device_id, const Spark_READ_PARAMETER_4_AND_5_t* values);

// Build frame for Read Parameter 6 and 7: Read parameter 6 and 7 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_6_AND_7(uint8_t device_id, const Spark_READ_PARAMETER_6_AND_7_t* values);

// Build frame for Read Parameter 8 and 9: Read parameter 8 and 9 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_8_AND_9(uint8_t device_id, const Spark_READ_PARAMETER_8_AND_9_t* values);

// Build frame for Read Parameter 10 and 11: Read parameter 10 and 11 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_10_AND_11(uint8_t device_id, const Spark_READ_PARAMETER_10_AND_11_t* values);

// Build frame for Read Parameter 12 and 13: Read parameter 12 and 13 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_12_AND_13(uint8_t device_id, const Spark_READ_PARAMETER_12_AND_13_t* values);

// Build frame for Read Parameter 14 and 15: Read parameter 14 and 15 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_14_AND_15(uint8_t device_id, const Spark_READ_PARAMETER_14_AND_15_t* values);

// Build frame for Read Parameter 16 and 17: Read parameter 16 and 17 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_16_AND_17(uint8_t device_id, const Spark_READ_PARAMETER_16_AND_17_t* values);

// Build frame for Read Parameter 18 and 19: Read parameter 18 and 19 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_18_AND_19(uint8_t device_id, const Spark_READ_PARAMETER_18_AND_19_t* values);

// Build frame for Read Parameter 20 and 21: Read parameter 20 and 21 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_20_AND_21(uint8_t device_id, const Spark_READ_PARAMETER_20_AND_21_t* values);

// Build frame for Read Parameter 22 and 23: Read parameter 22 and 23 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_22_AND_23(uint8_t device_id, const Spark_READ_PARAMETER_22_AND_23_t* values);

// Build frame for Read Parameter 24 and 25: Read parameter 24 and 25 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_24_AND_25(uint8_t device_id, const Spark_READ_PARAMETER_24_AND_25_t* values);

// Build frame for Read Parameter 26 and 27: Read parameter 26 and 27 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_26_AND_27(uint8_t device_id, const Spark_READ_PARAMETER_26_AND_27_t* values);

// Build frame for Read Parameter 28 and 29: Read parameter 28 and 29 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_28_AND_29(uint8_t device_id, const Spark_READ_PARAMETER_28_AND_29_t* values);

// Build frame for Read Parameter 30 and 31: Read parameter 30 and 31 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_30_AND_31(uint8_t device_id, const Spark_READ_PARAMETER_30_AND_31_t* values);

// Build frame for Read Parameter 32 and 33: Read parameter 32 and 33 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_32_AND_33(uint8_t device_id, const Spark_READ_PARAMETER_32_AND_33_t* values);

// Build frame for Read Parameter 34 and 35: Read parameter 34 and 35 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_34_AND_35(uint8_t device_id, const Spark_READ_PARAMETER_34_AND_35_t* values);

// Build frame for Read Parameter 36 and 37: Read parameter 36 and 37 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_36_AND_37(uint8_t device_id, const Spark_READ_PARAMETER_36_AND_37_t* values);

// Build frame for Read Parameter 38 and 39: Read parameter 38 and 39 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_38_AND_39(uint8_t device_id, const Spark_READ_PARAMETER_38_AND_39_t* values);

// Build frame for Read Parameter 40 and 41: Read parameter 40 and 41 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_40_AND_41(uint8_t device_id, const Spark_READ_PARAMETER_40_AND_41_t* values);

// Build frame for Read Parameter 42 and 43: Read parameter 42 and 43 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_42_AND_43(uint8_t device_id, const Spark_READ_PARAMETER_42_AND_43_t* values);

// Build frame for Read Parameter 44 and 45: Read parameter 44 and 45 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_44_AND_45(uint8_t device_id, const Spark_READ_PARAMETER_44_AND_45_t* values);

// Build frame for Read Parameter 46 and 47: Read parameter 46 and 47 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_46_AND_47(uint8_t device_id, const Spark_READ_PARAMETER_46_AND_47_t* values);

// Build frame for Read Parameter 48 and 49: Read parameter 48 and 49 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_48_AND_49(uint8_t device_id, const Spark_READ_PARAMETER_48_AND_49_t* values);

// Build frame for Read Parameter 50 and 51: Read parameter 50 and 51 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_50_AND_51(uint8_t device_id, const Spark_READ_PARAMETER_50_AND_51_t* values);

// Build frame for Read Parameter 52 and 53: Read parameter 52 and 53 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_52_AND_53(uint8_t device_id, const Spark_READ_PARAMETER_52_AND_53_t* values);

// Build frame for Read Parameter 54 and 55: Read parameter 54 and 55 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_54_AND_55(uint8_t device_id, const Spark_READ_PARAMETER_54_AND_55_t* values);

// Build frame for Read Parameter 56 and 57: Read parameter 56 and 57 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_56_AND_57(uint8_t device_id, const Spark_READ_PARAMETER_56_AND_57_t* values);

// Build frame for Read Parameter 58 and 59: Read parameter 58 and 59 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_58_AND_59(uint8_t device_id, const Spark_READ_PARAMETER_58_AND_59_t* values);

// Build frame for Read Parameter 60 and 61: Read parameter 60 and 61 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_60_AND_61(uint8_t device_id, const Spark_READ_PARAMETER_60_AND_61_t* values);

// Build frame for Read Parameter 62 and 63: Read parameter 62 and 63 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_62_AND_63(uint8_t device_id, const Spark_READ_PARAMETER_62_AND_63_t* values);

// Build frame for Read Parameter 64 and 65: Read parameter 64 and 65 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_64_AND_65(uint8_t device_id, const Spark_READ_PARAMETER_64_AND_65_t* values);

// Build frame for Read Parameter 66 and 67: Read parameter 66 and 67 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_66_AND_67(uint8_t device_id, const Spark_READ_PARAMETER_66_AND_67_t* values);

// Build frame for Read Parameter 68 and 69: Read parameter 68 and 69 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_68_AND_69(uint8_t device_id, const Spark_READ_PARAMETER_68_AND_69_t* values);

// Build frame for Read Parameter 70 and 71: Read parameter 70 and 71 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_70_AND_71(uint8_t device_id, const Spark_READ_PARAMETER_70_AND_71_t* values);

// Build frame for Read Parameter 72 and 73: Read parameter 72 and 73 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_72_AND_73(uint8_t device_id, const Spark_READ_PARAMETER_72_AND_73_t* values);

// Build frame for Read Parameter 74 and 75: Read parameter 74 and 75 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_74_AND_75(uint8_t device_id, const Spark_READ_PARAMETER_74_AND_75_t* values);

// Build frame for Read Parameter 76 and 77: Read parameter 76 and 77 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_76_AND_77(uint8_t device_id, const Spark_READ_PARAMETER_76_AND_77_t* values);

// Build frame for Read Parameter 78 and 79: Read parameter 78 and 79 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_78_AND_79(uint8_t device_id, const Spark_READ_PARAMETER_78_AND_79_t* values);

// Build frame for Read Parameter 80 and 81: Read parameter 80 and 81 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_80_AND_81(uint8_t device_id, const Spark_READ_PARAMETER_80_AND_81_t* values);

// Build frame for Read Parameter 82 and 83: Read parameter 82 and 83 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_82_AND_83(uint8_t device_id, const Spark_READ_PARAMETER_82_AND_83_t* values);

// Build frame for Read Parameter 84 and 85: Read parameter 84 and 85 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_84_AND_85(uint8_t device_id, const Spark_READ_PARAMETER_84_AND_85_t* values);

// Build frame for Read Parameter 86 and 87: Read parameter 86 and 87 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_86_AND_87(uint8_t device_id, const Spark_READ_PARAMETER_86_AND_87_t* values);

// Build frame for Read Parameter 88 and 89: Read parameter 88 and 89 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_88_AND_89(uint8_t device_id, const Spark_READ_PARAMETER_88_AND_89_t* values);

// Build frame for Read Parameter 90 and 91: Read parameter 90 and 91 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_90_AND_91(uint8_t device_id, const Spark_READ_PARAMETER_90_AND_91_t* values);

// Build frame for Read Parameter 92 and 93: Read parameter 92 and 93 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_92_AND_93(uint8_t device_id, const Spark_READ_PARAMETER_92_AND_93_t* values);

// Build frame for Read Parameter 94 and 95: Read parameter 94 and 95 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_94_AND_95(uint8_t device_id, const Spark_READ_PARAMETER_94_AND_95_t* values);

// Build frame for Read Parameter 96 and 97: Read parameter 96 and 97 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_96_AND_97(uint8_t device_id, const Spark_READ_PARAMETER_96_AND_97_t* values);

// Build frame for Read Parameter 98 and 99: Read parameter 98 and 99 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_98_AND_99(uint8_t device_id, const Spark_READ_PARAMETER_98_AND_99_t* values);

// Build frame for Read Parameter 100 and 101: Read parameter 100 and 101 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_100_AND_101(uint8_t device_id, const Spark_READ_PARAMETER_100_AND_101_t* values);

// Build frame for Read Parameter 102 and 103: Read parameter 102 and 103 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_102_AND_103(uint8_t device_id, const Spark_READ_PARAMETER_102_AND_103_t* values);

// Build frame for Read Parameter 104 and 105: Read parameter 104 and 105 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_104_AND_105(uint8_t device_id, const Spark_READ_PARAMETER_104_AND_105_t* values);

// Build frame for Read Parameter 106 and 107: Read parameter 106 and 107 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_106_AND_107(uint8_t device_id, const Spark_READ_PARAMETER_106_AND_107_t* values);

// Build frame for Read Parameter 108 and 109: Read parameter 108 and 109 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_108_AND_109(uint8_t device_id, const Spark_READ_PARAMETER_108_AND_109_t* values);

// Build frame for Read Parameter 110 and 111: Read parameter 110 and 111 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_110_AND_111(uint8_t device_id, const Spark_READ_PARAMETER_110_AND_111_t* values);

// Build frame for Read Parameter 112 and 113: Read parameter 112 and 113 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_112_AND_113(uint8_t device_id, const Spark_READ_PARAMETER_112_AND_113_t* values);

// Build frame for Read Parameter 114 and 115: Read parameter 114 and 115 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_114_AND_115(uint8_t device_id, const Spark_READ_PARAMETER_114_AND_115_t* values);

// Build frame for Read Parameter 116 and 117: Read parameter 116 and 117 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_116_AND_117(uint8_t device_id, const Spark_READ_PARAMETER_116_AND_117_t* values);

// Build frame for Read Parameter 118 and 119: Read parameter 118 and 119 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_118_AND_119(uint8_t device_id, const Spark_READ_PARAMETER_118_AND_119_t* values);

// Build frame for Read Parameter 120 and 121: Read parameter 120 and 121 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_120_AND_121(uint8_t device_id, const Spark_READ_PARAMETER_120_AND_121_t* values);

// Build frame for Read Parameter 122 and 123: Read parameter 122 and 123 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_122_AND_123(uint8_t device_id, const Spark_READ_PARAMETER_122_AND_123_t* values);

// Build frame for Read Parameter 124 and 125: Read parameter 124 and 125 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_124_AND_125(uint8_t device_id, const Spark_READ_PARAMETER_124_AND_125_t* values);

// Build frame for Read Parameter 126 and 127: Read parameter 126 and 127 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_126_AND_127(uint8_t device_id, const Spark_READ_PARAMETER_126_AND_127_t* values);

// Build frame for Read Parameter 128 and 129: Read parameter 128 and 129 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_128_AND_129(uint8_t device_id, const Spark_READ_PARAMETER_128_AND_129_t* values);

// Build frame for Read Parameter 130 and 131: Read parameter 130 and 131 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_130_AND_131(uint8_t device_id, const Spark_READ_PARAMETER_130_AND_131_t* values);

// Build frame for Read Parameter 132 and 133: Read parameter 132 and 133 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_132_AND_133(uint8_t device_id, const Spark_READ_PARAMETER_132_AND_133_t* values);

// Build frame for Read Parameter 134 and 135: Read parameter 134 and 135 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_134_AND_135(uint8_t device_id, const Spark_READ_PARAMETER_134_AND_135_t* values);

// Build frame for Read Parameter 136 and 137: Read parameter 136 and 137 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_136_AND_137(uint8_t device_id, const Spark_READ_PARAMETER_136_AND_137_t* values);

// Build frame for Read Parameter 138 and 139: Read parameter 138 and 139 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_138_AND_139(uint8_t device_id, const Spark_READ_PARAMETER_138_AND_139_t* values);

// Build frame for Read Parameter 140 and 141: Read parameter 140 and 141 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_140_AND_141(uint8_t device_id, const Spark_READ_PARAMETER_140_AND_141_t* values);

// Build frame for Read Parameter 142 and 143: Read parameter 142 and 143 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_142_AND_143(uint8_t device_id, const Spark_READ_PARAMETER_142_AND_143_t* values);

// Build frame for Read Parameter 144 and 145: Read parameter 144 and 145 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_144_AND_145(uint8_t device_id, const Spark_READ_PARAMETER_144_AND_145_t* values);

// Build frame for Read Parameter 146 and 147: Read parameter 146 and 147 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_146_AND_147(uint8_t device_id, const Spark_READ_PARAMETER_146_AND_147_t* values);

// Build frame for Read Parameter 148 and 149: Read parameter 148 and 149 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_148_AND_149(uint8_t device_id, const Spark_READ_PARAMETER_148_AND_149_t* values);

// Build frame for Read Parameter 150 and 151: Read parameter 150 and 151 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_150_AND_151(uint8_t device_id, const Spark_READ_PARAMETER_150_AND_151_t* values);

// Build frame for Read Parameter 152 and 153: Read parameter 152 and 153 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_152_AND_153(uint8_t device_id, const Spark_READ_PARAMETER_152_AND_153_t* values);

// Build frame for Read Parameter 154 and 155: Read parameter 154 and 155 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_154_AND_155(uint8_t device_id, const Spark_READ_PARAMETER_154_AND_155_t* values);

// Build frame for Read Parameter 156 and 157: Read parameter 156 and 157 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_156_AND_157(uint8_t device_id, const Spark_READ_PARAMETER_156_AND_157_t* values);

// Build frame for Read Parameter 158 and 159: Read parameter 158 and 159 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_158_AND_159(uint8_t device_id, const Spark_READ_PARAMETER_158_AND_159_t* values);

// Build frame for Read Parameter 160 and 161: Read parameter 160 and 161 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_160_AND_161(uint8_t device_id, const Spark_READ_PARAMETER_160_AND_161_t* values);

// Build frame for Read Parameter 162 and 163: Read parameter 162 and 163 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_162_AND_163(uint8_t device_id, const Spark_READ_PARAMETER_162_AND_163_t* values);

// Build frame for Read Parameter 164 and 165: Read parameter 164 and 165 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_164_AND_165(uint8_t device_id, const Spark_READ_PARAMETER_164_AND_165_t* values);

// Build frame for Read Parameter 166 and 167: Read parameter 166 and 167 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_166_AND_167(uint8_t device_id, const Spark_READ_PARAMETER_166_AND_167_t* values);

// Build frame for Read Parameter 168 and 169: Read parameter 168 and 169 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_168_AND_169(uint8_t device_id, const Spark_READ_PARAMETER_168_AND_169_t* values);

// Build frame for Read Parameter 170 and 171: Read parameter 170 and 171 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_170_AND_171(uint8_t device_id, const Spark_READ_PARAMETER_170_AND_171_t* values);

// Build frame for Read Parameter 172 and 173: Read parameter 172 and 173 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_172_AND_173(uint8_t device_id, const Spark_READ_PARAMETER_172_AND_173_t* values);

// Build frame for Read Parameter 174 and 175: Read parameter 174 and 175 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_174_AND_175(uint8_t device_id, const Spark_READ_PARAMETER_174_AND_175_t* values);

// Build frame for Read Parameter 176 and 177: Read parameter 176 and 177 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_176_AND_177(uint8_t device_id, const Spark_READ_PARAMETER_176_AND_177_t* values);

// Build frame for Read Parameter 178 and 179: Read parameter 178 and 179 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_178_AND_179(uint8_t device_id, const Spark_READ_PARAMETER_178_AND_179_t* values);

// Build frame for Read Parameter 180 and 181: Read parameter 180 and 181 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_180_AND_181(uint8_t device_id, const Spark_READ_PARAMETER_180_AND_181_t* values);

// Build frame for Read Parameter 182 and 183: Read parameter 182 and 183 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_182_AND_183(uint8_t device_id, const Spark_READ_PARAMETER_182_AND_183_t* values);

// Build frame for Read Parameter 184 and 185: Read parameter 184 and 185 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_184_AND_185(uint8_t device_id, const Spark_READ_PARAMETER_184_AND_185_t* values);

// Build frame for Read Parameter 186 and 187: Read parameter 186 and 187 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_186_AND_187(uint8_t device_id, const Spark_READ_PARAMETER_186_AND_187_t* values);

// Build frame for Read Parameter 188 and 189: Read parameter 188 and 189 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_188_AND_189(uint8_t device_id, const Spark_READ_PARAMETER_188_AND_189_t* values);

// Build frame for Read Parameter 190 and 191: Read parameter 190 and 191 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_190_AND_191(uint8_t device_id, const Spark_READ_PARAMETER_190_AND_191_t* values);

// Build frame for Read Parameter 192 and 193: Read parameter 192 and 193 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_192_AND_193(uint8_t device_id, const Spark_READ_PARAMETER_192_AND_193_t* values);

// Build frame for Read Parameter 194 and 195: Read parameter 194 and 195 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_194_AND_195(uint8_t device_id, const Spark_READ_PARAMETER_194_AND_195_t* values);

// Build frame for Read Parameter 196 and 197: Read parameter 196 and 197 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_196_AND_197(uint8_t device_id, const Spark_READ_PARAMETER_196_AND_197_t* values);

// Build frame for Read Parameter 198 and 199: Read parameter 198 and 199 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_198_AND_199(uint8_t device_id, const Spark_READ_PARAMETER_198_AND_199_t* values);

// Build frame for Read Parameter 200 and 201: Read parameter 200 and 201 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_200_AND_201(uint8_t device_id, const Spark_READ_PARAMETER_200_AND_201_t* values);

// Build frame for Read Parameter 202 and 203: Read parameter 202 and 203 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_202_AND_203(uint8_t device_id, const Spark_READ_PARAMETER_202_AND_203_t* values);

// Build frame for Read Parameter 204 and 205: Read parameter 204 and 205 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_204_AND_205(uint8_t device_id, const Spark_READ_PARAMETER_204_AND_205_t* values);

// Build frame for Read Parameter 206 and 207: Read parameter 206 and 207 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_206_AND_207(uint8_t device_id, const Spark_READ_PARAMETER_206_AND_207_t* values);

// Build frame for Read Parameter 208 and 209: Read parameter 208 and 209 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_208_AND_209(uint8_t device_id, const Spark_READ_PARAMETER_208_AND_209_t* values);

// Build frame for Read Parameter 210 and 211: Read parameter 210 and 211 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_210_AND_211(uint8_t device_id, const Spark_READ_PARAMETER_210_AND_211_t* values);

// Build frame for Read Parameter 212 and 213: Read parameter 212 and 213 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_212_AND_213(uint8_t device_id, const Spark_READ_PARAMETER_212_AND_213_t* values);

// Build frame for Read Parameter 214 and 215: Read parameter 214 and 215 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_214_AND_215(uint8_t device_id, const Spark_READ_PARAMETER_214_AND_215_t* values);

// Build frame for Read Parameter 216 and 217: Read parameter 216 and 217 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_216_AND_217(uint8_t device_id, const Spark_READ_PARAMETER_216_AND_217_t* values);

// Build frame for Read Parameter 218 and 219: Read parameter 218 and 219 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_218_AND_219(uint8_t device_id, const Spark_READ_PARAMETER_218_AND_219_t* values);

// Build frame for Read Parameter 220 and 221: Read parameter 220 and 221 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_220_AND_221(uint8_t device_id, const Spark_READ_PARAMETER_220_AND_221_t* values);

// Build frame for Read Parameter 222 and 223: Read parameter 222 and 223 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_222_AND_223(uint8_t device_id, const Spark_READ_PARAMETER_222_AND_223_t* values);

// Build frame for Read Parameter 224 and 225: Read parameter 224 and 225 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_224_AND_225(uint8_t device_id, const Spark_READ_PARAMETER_224_AND_225_t* values);

// Build frame for Read Parameter 226 and 227: Read parameter 226 and 227 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_226_AND_227(uint8_t device_id, const Spark_READ_PARAMETER_226_AND_227_t* values);

// Build frame for Read Parameter 228 and 229: Read parameter 228 and 229 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_228_AND_229(uint8_t device_id, const Spark_READ_PARAMETER_228_AND_229_t* values);

// Build frame for Read Parameter 230 and 231: Read parameter 230 and 231 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_230_AND_231(uint8_t device_id, const Spark_READ_PARAMETER_230_AND_231_t* values);

// Build frame for Read Parameter 232 and 233: Read parameter 232 and 233 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_232_AND_233(uint8_t device_id, const Spark_READ_PARAMETER_232_AND_233_t* values);

// Build frame for Read Parameter 234 and 235: Read parameter 234 and 235 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_234_AND_235(uint8_t device_id, const Spark_READ_PARAMETER_234_AND_235_t* values);

// Build frame for Read Parameter 236 and 237: Read parameter 236 and 237 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_236_AND_237(uint8_t device_id, const Spark_READ_PARAMETER_236_AND_237_t* values);

// Build frame for Read Parameter 238 and 239: Read parameter 238 and 239 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_238_AND_239(uint8_t device_id, const Spark_READ_PARAMETER_238_AND_239_t* values);

// Build frame for Read Parameter 240 and 241: Read parameter 240 and 241 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_240_AND_241(uint8_t device_id, const Spark_READ_PARAMETER_240_AND_241_t* values);

// Build frame for Read Parameter 242 and 243: Read parameter 242 and 243 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_242_AND_243(uint8_t device_id, const Spark_READ_PARAMETER_242_AND_243_t* values);

// Build frame for Read Parameter 244 and 245: Read parameter 244 and 245 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_244_AND_245(uint8_t device_id, const Spark_READ_PARAMETER_244_AND_245_t* values);

// Build frame for Read Parameter 246 and 247: Read parameter 246 and 247 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_246_AND_247(uint8_t device_id, const Spark_READ_PARAMETER_246_AND_247_t* values);

// Build frame for Read Parameter 248 and 249: Read parameter 248 and 249 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_248_AND_249(uint8_t device_id, const Spark_READ_PARAMETER_248_AND_249_t* values);

// Build frame for Read Parameter 250 and 251: Read parameter 250 and 251 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_250_AND_251(uint8_t device_id, const Spark_READ_PARAMETER_250_AND_251_t* values);

// Build frame for Read Parameter 252 and 253: Read parameter 252 and 253 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_252_AND_253(uint8_t device_id, const Spark_READ_PARAMETER_252_AND_253_t* values);

// Build frame for Read Parameter 254 and 255: Read parameter 254 and 255 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
spark_can_frame spark_build_READ_PARAMETER_254_AND_255(uint8_t device_id, const Spark_READ_PARAMETER_254_AND_255_t* values);

// Build frame for Write Parameter 0 and 1: Write Parameter 0 and 1 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_0_AND_1(uint8_t device_id, const Spark_WRITE_PARAMETER_0_AND_1_t* values);

// Build frame for Write Parameter 2 and 3: Write Parameter 2 and 3 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_2_AND_3(uint8_t device_id, const Spark_WRITE_PARAMETER_2_AND_3_t* values);

// Build frame for Write Parameter 4 and 5: Write Parameter 4 and 5 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_4_AND_5(uint8_t device_id, const Spark_WRITE_PARAMETER_4_AND_5_t* values);

// Build frame for Write Parameter 6 and 7: Write Parameter 6 and 7 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_6_AND_7(uint8_t device_id, const Spark_WRITE_PARAMETER_6_AND_7_t* values);

// Build frame for Write Parameter 8 and 9: Write Parameter 8 and 9 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_8_AND_9(uint8_t device_id, const Spark_WRITE_PARAMETER_8_AND_9_t* values);

// Build frame for Write Parameter 10 and 11: Write Parameter 10 and 11 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_10_AND_11(uint8_t device_id, const Spark_WRITE_PARAMETER_10_AND_11_t* values);

// Build frame for Write Parameter 12 and 13: Write Parameter 12 and 13 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_12_AND_13(uint8_t device_id, const Spark_WRITE_PARAMETER_12_AND_13_t* values);

// Build frame for Write Parameter 14 and 15: Write Parameter 14 and 15 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_14_AND_15(uint8_t device_id, const Spark_WRITE_PARAMETER_14_AND_15_t* values);

// Build frame for Write Parameter 16 and 17: Write Parameter 16 and 17 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_16_AND_17(uint8_t device_id, const Spark_WRITE_PARAMETER_16_AND_17_t* values);

// Build frame for Write Parameter 18 and 19: Write Parameter 18 and 19 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_18_AND_19(uint8_t device_id, const Spark_WRITE_PARAMETER_18_AND_19_t* values);

// Build frame for Write Parameter 20 and 21: Write Parameter 20 and 21 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_20_AND_21(uint8_t device_id, const Spark_WRITE_PARAMETER_20_AND_21_t* values);

// Build frame for Write Parameter 22 and 23: Write Parameter 22 and 23 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_22_AND_23(uint8_t device_id, const Spark_WRITE_PARAMETER_22_AND_23_t* values);

// Build frame for Write Parameter 24 and 25: Write Parameter 24 and 25 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_24_AND_25(uint8_t device_id, const Spark_WRITE_PARAMETER_24_AND_25_t* values);

// Build frame for Write Parameter 26 and 27: Write Parameter 26 and 27 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_26_AND_27(uint8_t device_id, const Spark_WRITE_PARAMETER_26_AND_27_t* values);

// Build frame for Write Parameter 28 and 29: Write Parameter 28 and 29 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_28_AND_29(uint8_t device_id, const Spark_WRITE_PARAMETER_28_AND_29_t* values);

// Build frame for Write Parameter 30 and 31: Write Parameter 30 and 31 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_30_AND_31(uint8_t device_id, const Spark_WRITE_PARAMETER_30_AND_31_t* values);

// Build frame for Write Parameter 32 and 33: Write Parameter 32 and 33 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_32_AND_33(uint8_t device_id, const Spark_WRITE_PARAMETER_32_AND_33_t* values);

// Build frame for Write Parameter 34 and 35: Write Parameter 34 and 35 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_34_AND_35(uint8_t device_id, const Spark_WRITE_PARAMETER_34_AND_35_t* values);

// Build frame for Write Parameter 36 and 37: Write Parameter 36 and 37 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_36_AND_37(uint8_t device_id, const Spark_WRITE_PARAMETER_36_AND_37_t* values);

// Build frame for Write Parameter 38 and 39: Write Parameter 38 and 39 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_38_AND_39(uint8_t device_id, const Spark_WRITE_PARAMETER_38_AND_39_t* values);

// Build frame for Write Parameter 40 and 41: Write Parameter 40 and 41 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_40_AND_41(uint8_t device_id, const Spark_WRITE_PARAMETER_40_AND_41_t* values);

// Build frame for Write Parameter 42 and 43: Write Parameter 42 and 43 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_42_AND_43(uint8_t device_id, const Spark_WRITE_PARAMETER_42_AND_43_t* values);

// Build frame for Write Parameter 44 and 45: Write Parameter 44 and 45 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_44_AND_45(uint8_t device_id, const Spark_WRITE_PARAMETER_44_AND_45_t* values);

// Build frame for Write Parameter 46 and 47: Write Parameter 46 and 47 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_46_AND_47(uint8_t device_id, const Spark_WRITE_PARAMETER_46_AND_47_t* values);

// Build frame for Write Parameter 48 and 49: Write Parameter 48 and 49 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_48_AND_49(uint8_t device_id, const Spark_WRITE_PARAMETER_48_AND_49_t* values);

// Build frame for Write Parameter 50 and 51: Write Parameter 50 and 51 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_50_AND_51(uint8_t device_id, const Spark_WRITE_PARAMETER_50_AND_51_t* values);

// Build frame for Write Parameter 52 and 53: Write Parameter 52 and 53 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_52_AND_53(uint8_t device_id, const Spark_WRITE_PARAMETER_52_AND_53_t* values);

// Build frame for Write Parameter 54 and 55: Write Parameter 54 and 55 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_54_AND_55(uint8_t device_id, const Spark_WRITE_PARAMETER_54_AND_55_t* values);

// Build frame for Write Parameter 56 and 57: Write Parameter 56 and 57 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_56_AND_57(uint8_t device_id, const Spark_WRITE_PARAMETER_56_AND_57_t* values);

// Build frame for Write Parameter 58 and 59: Write Parameter 58 and 59 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_58_AND_59(uint8_t device_id, const Spark_WRITE_PARAMETER_58_AND_59_t* values);

// Build frame for Write Parameter 60 and 61: Write Parameter 60 and 61 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_60_AND_61(uint8_t device_id, const Spark_WRITE_PARAMETER_60_AND_61_t* values);

// Build frame for Write Parameter 62 and 63: Write Parameter 62 and 63 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_62_AND_63(uint8_t device_id, const Spark_WRITE_PARAMETER_62_AND_63_t* values);

// Build frame for Write Parameter 64 and 65: Write Parameter 64 and 65 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_64_AND_65(uint8_t device_id, const Spark_WRITE_PARAMETER_64_AND_65_t* values);

// Build frame for Write Parameter 66 and 67: Write Parameter 66 and 67 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_66_AND_67(uint8_t device_id, const Spark_WRITE_PARAMETER_66_AND_67_t* values);

// Build frame for Write Parameter 68 and 69: Write Parameter 68 and 69 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_68_AND_69(uint8_t device_id, const Spark_WRITE_PARAMETER_68_AND_69_t* values);

// Build frame for Write Parameter 70 and 71: Write Parameter 70 and 71 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_70_AND_71(uint8_t device_id, const Spark_WRITE_PARAMETER_70_AND_71_t* values);

// Build frame for Write Parameter 72 and 73: Write Parameter 72 and 73 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_72_AND_73(uint8_t device_id, const Spark_WRITE_PARAMETER_72_AND_73_t* values);

// Build frame for Write Parameter 74 and 75: Write Parameter 74 and 75 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_74_AND_75(uint8_t device_id, const Spark_WRITE_PARAMETER_74_AND_75_t* values);

// Build frame for Write Parameter 76 and 77: Write Parameter 76 and 77 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_76_AND_77(uint8_t device_id, const Spark_WRITE_PARAMETER_76_AND_77_t* values);

// Build frame for Write Parameter 78 and 79: Write Parameter 78 and 79 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_78_AND_79(uint8_t device_id, const Spark_WRITE_PARAMETER_78_AND_79_t* values);

// Build frame for Write Parameter 80 and 81: Write Parameter 80 and 81 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_80_AND_81(uint8_t device_id, const Spark_WRITE_PARAMETER_80_AND_81_t* values);

// Build frame for Write Parameter 82 and 83: Write Parameter 82 and 83 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_82_AND_83(uint8_t device_id, const Spark_WRITE_PARAMETER_82_AND_83_t* values);

// Build frame for Write Parameter 84 and 85: Write Parameter 84 and 85 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_84_AND_85(uint8_t device_id, const Spark_WRITE_PARAMETER_84_AND_85_t* values);

// Build frame for Write Parameter 86 and 87: Write Parameter 86 and 87 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_86_AND_87(uint8_t device_id, const Spark_WRITE_PARAMETER_86_AND_87_t* values);

// Build frame for Write Parameter 88 and 89: Write Parameter 88 and 89 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_88_AND_89(uint8_t device_id, const Spark_WRITE_PARAMETER_88_AND_89_t* values);

// Build frame for Write Parameter 90 and 91: Write Parameter 90 and 91 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_90_AND_91(uint8_t device_id, const Spark_WRITE_PARAMETER_90_AND_91_t* values);

// Build frame for Write Parameter 92 and 93: Write Parameter 92 and 93 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_92_AND_93(uint8_t device_id, const Spark_WRITE_PARAMETER_92_AND_93_t* values);

// Build frame for Write Parameter 94 and 95: Write Parameter 94 and 95 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_94_AND_95(uint8_t device_id, const Spark_WRITE_PARAMETER_94_AND_95_t* values);

// Build frame for Write Parameter 96 and 97: Write Parameter 96 and 97 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_96_AND_97(uint8_t device_id, const Spark_WRITE_PARAMETER_96_AND_97_t* values);

// Build frame for Write Parameter 98 and 99: Write Parameter 98 and 99 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_98_AND_99(uint8_t device_id, const Spark_WRITE_PARAMETER_98_AND_99_t* values);

// Build frame for Write Parameter 100 and 101: Write Parameter 100 and 101 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_100_AND_101(uint8_t device_id, const Spark_WRITE_PARAMETER_100_AND_101_t* values);

// Build frame for Write Parameter 102 and 103: Write Parameter 102 and 103 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_102_AND_103(uint8_t device_id, const Spark_WRITE_PARAMETER_102_AND_103_t* values);

// Build frame for Write Parameter 104 and 105: Write Parameter 104 and 105 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_104_AND_105(uint8_t device_id, const Spark_WRITE_PARAMETER_104_AND_105_t* values);

// Build frame for Write Parameter 106 and 107: Write Parameter 106 and 107 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_106_AND_107(uint8_t device_id, const Spark_WRITE_PARAMETER_106_AND_107_t* values);

// Build frame for Write Parameter 108 and 109: Write Parameter 108 and 109 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_108_AND_109(uint8_t device_id, const Spark_WRITE_PARAMETER_108_AND_109_t* values);

// Build frame for Write Parameter 110 and 111: Write Parameter 110 and 111 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_110_AND_111(uint8_t device_id, const Spark_WRITE_PARAMETER_110_AND_111_t* values);

// Build frame for Write Parameter 112 and 113: Write Parameter 112 and 113 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_112_AND_113(uint8_t device_id, const Spark_WRITE_PARAMETER_112_AND_113_t* values);

// Build frame for Write Parameter 114 and 115: Write Parameter 114 and 115 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_114_AND_115(uint8_t device_id, const Spark_WRITE_PARAMETER_114_AND_115_t* values);

// Build frame for Write Parameter 116 and 117: Write Parameter 116 and 117 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_116_AND_117(uint8_t device_id, const Spark_WRITE_PARAMETER_116_AND_117_t* values);

// Build frame for Write Parameter 118 and 119: Write Parameter 118 and 119 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_118_AND_119(uint8_t device_id, const Spark_WRITE_PARAMETER_118_AND_119_t* values);

// Build frame for Write Parameter 120 and 121: Write Parameter 120 and 121 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_120_AND_121(uint8_t device_id, const Spark_WRITE_PARAMETER_120_AND_121_t* values);

// Build frame for Write Parameter 122 and 123: Write Parameter 122 and 123 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_122_AND_123(uint8_t device_id, const Spark_WRITE_PARAMETER_122_AND_123_t* values);

// Build frame for Write Parameter 124 and 125: Write Parameter 124 and 125 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_124_AND_125(uint8_t device_id, const Spark_WRITE_PARAMETER_124_AND_125_t* values);

// Build frame for Write Parameter 126 and 127: Write Parameter 126 and 127 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_126_AND_127(uint8_t device_id, const Spark_WRITE_PARAMETER_126_AND_127_t* values);

// Build frame for Write Parameter 128 and 129: Write Parameter 128 and 129 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_128_AND_129(uint8_t device_id, const Spark_WRITE_PARAMETER_128_AND_129_t* values);

// Build frame for Write Parameter 130 and 131: Write Parameter 130 and 131 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_130_AND_131(uint8_t device_id, const Spark_WRITE_PARAMETER_130_AND_131_t* values);

// Build frame for Write Parameter 132 and 133: Write Parameter 132 and 133 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_132_AND_133(uint8_t device_id, const Spark_WRITE_PARAMETER_132_AND_133_t* values);

// Build frame for Write Parameter 134 and 135: Write Parameter 134 and 135 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_134_AND_135(uint8_t device_id, const Spark_WRITE_PARAMETER_134_AND_135_t* values);

// Build frame for Write Parameter 136 and 137: Write Parameter 136 and 137 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_136_AND_137(uint8_t device_id, const Spark_WRITE_PARAMETER_136_AND_137_t* values);

// Build frame for Write Parameter 138 and 139: Write Parameter 138 and 139 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_138_AND_139(uint8_t device_id, const Spark_WRITE_PARAMETER_138_AND_139_t* values);

// Build frame for Write Parameter 140 and 141: Write Parameter 140 and 141 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_140_AND_141(uint8_t device_id, const Spark_WRITE_PARAMETER_140_AND_141_t* values);

// Build frame for Write Parameter 142 and 143: Write Parameter 142 and 143 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_142_AND_143(uint8_t device_id, const Spark_WRITE_PARAMETER_142_AND_143_t* values);

// Build frame for Write Parameter 144 and 145: Write Parameter 144 and 145 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_144_AND_145(uint8_t device_id, const Spark_WRITE_PARAMETER_144_AND_145_t* values);

// Build frame for Write Parameter 146 and 147: Write Parameter 146 and 147 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_146_AND_147(uint8_t device_id, const Spark_WRITE_PARAMETER_146_AND_147_t* values);

// Build frame for Write Parameter 148 and 149: Write Parameter 148 and 149 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_148_AND_149(uint8_t device_id, const Spark_WRITE_PARAMETER_148_AND_149_t* values);

// Build frame for Write Parameter 150 and 151: Write Parameter 150 and 151 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_150_AND_151(uint8_t device_id, const Spark_WRITE_PARAMETER_150_AND_151_t* values);

// Build frame for Write Parameter 152 and 153: Write Parameter 152 and 153 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_152_AND_153(uint8_t device_id, const Spark_WRITE_PARAMETER_152_AND_153_t* values);

// Build frame for Write Parameter 154 and 155: Write Parameter 154 and 155 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_154_AND_155(uint8_t device_id, const Spark_WRITE_PARAMETER_154_AND_155_t* values);

// Build frame for Write Parameter 156 and 157: Write Parameter 156 and 157 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_156_AND_157(uint8_t device_id, const Spark_WRITE_PARAMETER_156_AND_157_t* values);

// Build frame for Write Parameter 158 and 159: Write Parameter 158 and 159 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_158_AND_159(uint8_t device_id, const Spark_WRITE_PARAMETER_158_AND_159_t* values);

// Build frame for Write Parameter 160 and 161: Write Parameter 160 and 161 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_160_AND_161(uint8_t device_id, const Spark_WRITE_PARAMETER_160_AND_161_t* values);

// Build frame for Write Parameter 162 and 163: Write Parameter 162 and 163 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_162_AND_163(uint8_t device_id, const Spark_WRITE_PARAMETER_162_AND_163_t* values);

// Build frame for Write Parameter 164 and 165: Write Parameter 164 and 165 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_164_AND_165(uint8_t device_id, const Spark_WRITE_PARAMETER_164_AND_165_t* values);

// Build frame for Write Parameter 166 and 167: Write Parameter 166 and 167 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_166_AND_167(uint8_t device_id, const Spark_WRITE_PARAMETER_166_AND_167_t* values);

// Build frame for Write Parameter 168 and 169: Write Parameter 168 and 169 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_168_AND_169(uint8_t device_id, const Spark_WRITE_PARAMETER_168_AND_169_t* values);

// Build frame for Write Parameter 170 and 171: Write Parameter 170 and 171 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_170_AND_171(uint8_t device_id, const Spark_WRITE_PARAMETER_170_AND_171_t* values);

// Build frame for Write Parameter 172 and 173: Write Parameter 172 and 173 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_172_AND_173(uint8_t device_id, const Spark_WRITE_PARAMETER_172_AND_173_t* values);

// Build frame for Write Parameter 174 and 175: Write Parameter 174 and 175 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_174_AND_175(uint8_t device_id, const Spark_WRITE_PARAMETER_174_AND_175_t* values);

// Build frame for Write Parameter 176 and 177: Write Parameter 176 and 177 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_176_AND_177(uint8_t device_id, const Spark_WRITE_PARAMETER_176_AND_177_t* values);

// Build frame for Write Parameter 178 and 179: Write Parameter 178 and 179 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_178_AND_179(uint8_t device_id, const Spark_WRITE_PARAMETER_178_AND_179_t* values);

// Build frame for Write Parameter 180 and 181: Write Parameter 180 and 181 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_180_AND_181(uint8_t device_id, const Spark_WRITE_PARAMETER_180_AND_181_t* values);

// Build frame for Write Parameter 182 and 183: Write Parameter 182 and 183 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_182_AND_183(uint8_t device_id, const Spark_WRITE_PARAMETER_182_AND_183_t* values);

// Build frame for Write Parameter 184 and 185: Write Parameter 184 and 185 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_184_AND_185(uint8_t device_id, const Spark_WRITE_PARAMETER_184_AND_185_t* values);

// Build frame for Write Parameter 186 and 187: Write Parameter 186 and 187 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_186_AND_187(uint8_t device_id, const Spark_WRITE_PARAMETER_186_AND_187_t* values);

// Build frame for Write Parameter 188 and 189: Write Parameter 188 and 189 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_188_AND_189(uint8_t device_id, const Spark_WRITE_PARAMETER_188_AND_189_t* values);

// Build frame for Write Parameter 190 and 191: Write Parameter 190 and 191 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_190_AND_191(uint8_t device_id, const Spark_WRITE_PARAMETER_190_AND_191_t* values);

// Build frame for Write Parameter 192 and 193: Write Parameter 192 and 193 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_192_AND_193(uint8_t device_id, const Spark_WRITE_PARAMETER_192_AND_193_t* values);

// Build frame for Write Parameter 194 and 195: Write Parameter 194 and 195 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_194_AND_195(uint8_t device_id, const Spark_WRITE_PARAMETER_194_AND_195_t* values);

// Build frame for Write Parameter 196 and 197: Write Parameter 196 and 197 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_196_AND_197(uint8_t device_id, const Spark_WRITE_PARAMETER_196_AND_197_t* values);

// Build frame for Write Parameter 198 and 199: Write Parameter 198 and 199 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_198_AND_199(uint8_t device_id, const Spark_WRITE_PARAMETER_198_AND_199_t* values);

// Build frame for Write Parameter 200 and 201: Write Parameter 200 and 201 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_200_AND_201(uint8_t device_id, const Spark_WRITE_PARAMETER_200_AND_201_t* values);

// Build frame for Write Parameter 202 and 203: Write Parameter 202 and 203 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_202_AND_203(uint8_t device_id, const Spark_WRITE_PARAMETER_202_AND_203_t* values);

// Build frame for Write Parameter 204 and 205: Write Parameter 204 and 205 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_204_AND_205(uint8_t device_id, const Spark_WRITE_PARAMETER_204_AND_205_t* values);

// Build frame for Write Parameter 206 and 207: Write Parameter 206 and 207 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_206_AND_207(uint8_t device_id, const Spark_WRITE_PARAMETER_206_AND_207_t* values);

// Build frame for Write Parameter 208 and 209: Write Parameter 208 and 209 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_208_AND_209(uint8_t device_id, const Spark_WRITE_PARAMETER_208_AND_209_t* values);

// Build frame for Write Parameter 210 and 211: Write Parameter 210 and 211 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_210_AND_211(uint8_t device_id, const Spark_WRITE_PARAMETER_210_AND_211_t* values);

// Build frame for Write Parameter 212 and 213: Write Parameter 212 and 213 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_212_AND_213(uint8_t device_id, const Spark_WRITE_PARAMETER_212_AND_213_t* values);

// Build frame for Write Parameter 214 and 215: Write Parameter 214 and 215 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_214_AND_215(uint8_t device_id, const Spark_WRITE_PARAMETER_214_AND_215_t* values);

// Build frame for Write Parameter 216 and 217: Write Parameter 216 and 217 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_216_AND_217(uint8_t device_id, const Spark_WRITE_PARAMETER_216_AND_217_t* values);

// Build frame for Write Parameter 218 and 219: Write Parameter 218 and 219 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_218_AND_219(uint8_t device_id, const Spark_WRITE_PARAMETER_218_AND_219_t* values);

// Build frame for Write Parameter 220 and 221: Write Parameter 220 and 221 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_220_AND_221(uint8_t device_id, const Spark_WRITE_PARAMETER_220_AND_221_t* values);

// Build frame for Write Parameter 222 and 223: Write Parameter 222 and 223 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_222_AND_223(uint8_t device_id, const Spark_WRITE_PARAMETER_222_AND_223_t* values);

// Build frame for Write Parameter 224 and 225: Write Parameter 224 and 225 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_224_AND_225(uint8_t device_id, const Spark_WRITE_PARAMETER_224_AND_225_t* values);

// Build frame for Write Parameter 226 and 227: Write Parameter 226 and 227 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_226_AND_227(uint8_t device_id, const Spark_WRITE_PARAMETER_226_AND_227_t* values);

// Build frame for Write Parameter 228 and 229: Write Parameter 228 and 229 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_228_AND_229(uint8_t device_id, const Spark_WRITE_PARAMETER_228_AND_229_t* values);

// Build frame for Write Parameter 230 and 231: Write Parameter 230 and 231 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_230_AND_231(uint8_t device_id, const Spark_WRITE_PARAMETER_230_AND_231_t* values);

// Build frame for Write Parameter 232 and 233: Write Parameter 232 and 233 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_232_AND_233(uint8_t device_id, const Spark_WRITE_PARAMETER_232_AND_233_t* values);

// Build frame for Write Parameter 234 and 235: Write Parameter 234 and 235 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_234_AND_235(uint8_t device_id, const Spark_WRITE_PARAMETER_234_AND_235_t* values);

// Build frame for Write Parameter 236 and 237: Write Parameter 236 and 237 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_236_AND_237(uint8_t device_id, const Spark_WRITE_PARAMETER_236_AND_237_t* values);

// Build frame for Write Parameter 238 and 239: Write Parameter 238 and 239 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_238_AND_239(uint8_t device_id, const Spark_WRITE_PARAMETER_238_AND_239_t* values);

// Build frame for Write Parameter 240 and 241: Write Parameter 240 and 241 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_240_AND_241(uint8_t device_id, const Spark_WRITE_PARAMETER_240_AND_241_t* values);

// Build frame for Write Parameter 242 and 243: Write Parameter 242 and 243 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_242_AND_243(uint8_t device_id, const Spark_WRITE_PARAMETER_242_AND_243_t* values);

// Build frame for Write Parameter 244 and 245: Write Parameter 244 and 245 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_244_AND_245(uint8_t device_id, const Spark_WRITE_PARAMETER_244_AND_245_t* values);

// Build frame for Write Parameter 246 and 247: Write Parameter 246 and 247 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_246_AND_247(uint8_t device_id, const Spark_WRITE_PARAMETER_246_AND_247_t* values);

// Build frame for Write Parameter 248 and 249: Write Parameter 248 and 249 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_248_AND_249(uint8_t device_id, const Spark_WRITE_PARAMETER_248_AND_249_t* values);

// Build frame for Write Parameter 250 and 251: Write Parameter 250 and 251 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_250_AND_251(uint8_t device_id, const Spark_WRITE_PARAMETER_250_AND_251_t* values);

// Build frame for Write Parameter 252 and 253: Write Parameter 252 and 253 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_252_AND_253(uint8_t device_id, const Spark_WRITE_PARAMETER_252_AND_253_t* values);

// Build frame for Write Parameter 254 and 255: Write Parameter 254 and 255 at the same time. Two Write Parameter Response frames will be sent in response.
spark_can_frame spark_build_WRITE_PARAMETER_254_AND_255(uint8_t device_id, const Spark_WRITE_PARAMETER_254_AND_255_t* values);

// Build frame for Start Follower Mode: Starts follower mode. The relevant parameters must already be configured. In response, a Start Follower Mode Response frame will be sent. Follower mode will be auto-started on boot if the Follower Mode Leader ID parameter is set to a non-zero value.
spark_can_frame spark_build_START_FOLLOWER_MODE(uint8_t device_id, const Spark_START_FOLLOWER_MODE_t* values);

// Build frame for Start Follower Mode Response: Response for a Start Follower Mode command
spark_can_frame spark_build_START_FOLLOWER_MODE_RESPONSE(uint8_t device_id, const Spark_START_FOLLOWER_MODE_RESPONSE_t* values);

// Build frame for Stop Follower Mode: Exits follower mode and causes the device to resume listening for setpoints addressed directly to it. In response, a Stop Follower Mode Response frame will be sent.
spark_can_frame spark_build_STOP_FOLLOWER_MODE(uint8_t device_id, const Spark_STOP_FOLLOWER_MODE_t* values);

// Build frame for Stop Follower Mode Response: Response for a Stop Follower Mode Command
spark_can_frame spark_build_STOP_FOLLOWER_MODE_RESPONSE(uint8_t device_id, const Spark_STOP_FOLLOWER_MODE_RESPONSE_t* values);

// Build frame for Enter SWDL CAN Bootloader
spark_can_frame spark_build_ENTER_SWDL_CAN_BOOTLOADER(uint8_t device_id, const Spark_ENTER_SWDL_CAN_BOOTLOADER_t* values);

// Build frame for Persist Parameters: Causes all parameters to be written to non-volatile storage. After the operation (which may take up to a second) completes, a Persist Parameters Response frame will be sent.
spark_can_frame spark_build_PERSIST_PARAMETERS(uint8_t device_id, const Spark_PERSIST_PARAMETERS_t* values);

class SparkCanDevice {
public:
    explicit SparkCanDevice(uint8_t device_id);
    SparkCanDevice(MCP2515& controller, uint8_t device_id);
    void set_controller(MCP2515& controller);
    MCP2515* controller() const;
    bool has_controller() const;
    void set_device_id(uint8_t device_id);
    uint8_t device_id() const;
    // Build CAN frame for Velocity Setpoint: Sets the Control Type to Velocity and sets the target velocity
    spark_can_frame build_VELOCITY_SETPOINT(const Spark_VELOCITY_SETPOINT_t* values = nullptr) const;
    // Build CAN frame for Duty Cycle Setpoint: Sets the Control Type to Duty Cycle and sets the target duty cycle (from -1 to 1)
    spark_can_frame build_DUTY_CYCLE_SETPOINT(const Spark_DUTY_CYCLE_SETPOINT_t* values = nullptr) const;
    // Build CAN frame for Position Setpoint: Sets the Control Type to Position and sets the target position
    spark_can_frame build_POSITION_SETPOINT(const Spark_POSITION_SETPOINT_t* values = nullptr) const;
    // Build CAN frame for Voltage Setpoint: Sets the Control Type to Voltage and sets the target voltage
    spark_can_frame build_VOLTAGE_SETPOINT(const Spark_VOLTAGE_SETPOINT_t* values = nullptr) const;
    // Build CAN frame for Current Setpoint: Sets the Control Type to Current and sets the target current
    spark_can_frame build_CURRENT_SETPOINT(const Spark_CURRENT_SETPOINT_t* values = nullptr) const;
    // Build CAN frame for MAXMotion Position Setpoint: Sets the Control Type to MAXMotion Position Control and sets the target position
    spark_can_frame build_MAXMOTION_POSITION_SETPOINT(const Spark_MAXMOTION_POSITION_SETPOINT_t* values = nullptr) const;
    // Build CAN frame for MAXMotion Velocity Setpoint: Sets the Control Type to MAXMotion Velocity Control and sets the target velocity
    spark_can_frame build_MAXMOTION_VELOCITY_SETPOINT(const Spark_MAXMOTION_VELOCITY_SETPOINT_t* values = nullptr) const;
    // Build CAN frame for Set Statuses Enabled: Enable or disable status frames. In response, a Set Statuses Enabled Response frame will be sent.
    spark_can_frame build_SET_STATUSES_ENABLED(const Spark_SET_STATUSES_ENABLED_t* values = nullptr) const;
    // Build CAN frame for Set Statuses Enabled Response: Response for a Set Statuses Enabled command
    spark_can_frame build_SET_STATUSES_ENABLED_RESPONSE(const Spark_SET_STATUSES_ENABLED_RESPONSE_t* values = nullptr) const;
    // Build CAN frame for Persist Parameters Response
    spark_can_frame build_PERSIST_PARAMETERS_RESPONSE(const Spark_PERSIST_PARAMETERS_RESPONSE_t* values = nullptr) const;
    // Build CAN frame for Reset Safe Parameters: Resets most writable parameters to their default values, except CAN ID, Motor Type, Idle Mode, PWM Input Deadband, and Duty Cycle Offset. In response, a Reset Safe Parameters Response frame is sent.
    spark_can_frame build_RESET_SAFE_PARAMETERS(const Spark_RESET_SAFE_PARAMETERS_t* values = nullptr) const;
    // Build CAN frame for Reset Safe Parameters Response: Response for a Reset Safe Parameters command
    spark_can_frame build_RESET_SAFE_PARAMETERS_RESPONSE(const Spark_RESET_SAFE_PARAMETERS_RESPONSE_t* values = nullptr) const;
    // Build CAN frame for Complete Factory Reset: Resets all writable parameters to default values, even CAN ID, Motor Type, Idle Mode, PWM Input Deadband, and Duty Cycle Offset. In response, a Complete Factory Reset Response frame is sent.
    spark_can_frame build_COMPLETE_FACTORY_RESET(const Spark_COMPLETE_FACTORY_RESET_t* values = nullptr) const;
    // Build CAN frame for Complete Factory Reset Response: Response for a Complete Factory Reset command
    spark_can_frame build_COMPLETE_FACTORY_RESET_RESPONSE(const Spark_COMPLETE_FACTORY_RESET_RESPONSE_t* values = nullptr) const;
    // Build CAN frame for Clear Faults
    spark_can_frame build_CLEAR_FAULTS(const Spark_CLEAR_FAULTS_t* values = nullptr) const;
    // Build CAN frame for Identify Unique SPARK: Makes the specified, single SPARK (even if there are multiple SPARKs that have the same CAN ID) temporarily perform a special blink pattern that will make it stand out
    spark_can_frame build_IDENTIFY_UNIQUE_SPARK(const Spark_IDENTIFY_UNIQUE_SPARK_t* values = nullptr) const;
    // Build CAN frame for Identify: Makes the SPARK temporarily perform a special blink pattern that will make it stand out. Use Identify Unique Device if there may be multiple SPARKs with the same CAN ID.
    spark_can_frame build_IDENTIFY(const Spark_IDENTIFY_t* values = nullptr) const;
    // Build CAN frame for Nack: As of SPARK MAX firmware 1.6.3, this is only used as a potential response to setting the CAN ID
    spark_can_frame build_NACK(const Spark_NACK_t* values = nullptr) const;
    // Build CAN frame for Ack: As of SPARK MAX firmware 1.6.3, this is only used as a potential response to setting the CAN ID
    spark_can_frame build_ACK(const Spark_ACK_t* values = nullptr) const;
    // Build CAN frame for LED Sync: Causes all SPARKs on the bus to synchronize their LED patterns
    spark_can_frame build_LED_SYNC(const Spark_LED_SYNC_t* values = nullptr) const;
    // Build CAN frame for Set CAN ID: Allows changing the CAN ID when multiple devices on the bus currently have the same CAN ID. Under normal circumstances, the CAN ID parameter can be used.
    spark_can_frame build_SET_CAN_ID(const Spark_SET_CAN_ID_t* values = nullptr) const;
    // Build CAN frame for Get Firmware Version
    spark_can_frame build_GET_FIRMWARE_VERSION(const Spark_GET_FIRMWARE_VERSION_t* values = nullptr) const;
    // Build CAN frame for SWDL Data: Broadcast from the host to all SPARKs in SWDL mode, containing a slice of firmware data
    spark_can_frame build_SWDL_DATA(const Spark_SWDL_DATA_t* values = nullptr) const;
    // Build CAN frame for SWDL Checksum: Broadcast from the host to all SPARKs in SWDL mode, containing the checksum of the full firmware image that was just sent
    spark_can_frame build_SWDL_CHECKSUM(const Spark_SWDL_CHECKSUM_t* values = nullptr) const;
    // Build CAN frame for SWDL Retransmit: Sent by SPARK devices in response to receiving an SWDL Checksum frame that does not match the firmware data they received
    spark_can_frame build_SWDL_RETRANSMIT(const Spark_SWDL_RETRANSMIT_t* values = nullptr) const;
    // Build CAN frame for Set Primary Encoder Position
    spark_can_frame build_SET_PRIMARY_ENCODER_POSITION(const Spark_SET_PRIMARY_ENCODER_POSITION_t* values = nullptr) const;
    // Build CAN frame for Set I Accumulation
    spark_can_frame build_SET_I_ACCUMULATION(const Spark_SET_I_ACCUMULATION_t* values = nullptr) const;
    // Build CAN frame for Set Analog Position
    spark_can_frame build_SET_ANALOG_POSITION(const Spark_SET_ANALOG_POSITION_t* values = nullptr) const;
    // Build CAN frame for Set Ext or Alt Encoder Position
    spark_can_frame build_SET_EXT_OR_ALT_ENCODER_POSITION(const Spark_SET_EXT_OR_ALT_ENCODER_POSITION_t* values = nullptr) const;
    // Build CAN frame for Set Duty Cycle Position
    spark_can_frame build_SET_DUTY_CYCLE_POSITION(const Spark_SET_DUTY_CYCLE_POSITION_t* values = nullptr) const;
    // Build CAN frame for Secondary Heartbeat: Heartbeat that allows enabling only specific SPARKs, but only gets respected when the SPARK is not locked to the Universal Heartbeat or Primary Heartbeat
    spark_can_frame build_SECONDARY_HEARTBEAT(const Spark_SECONDARY_HEARTBEAT_t* values = nullptr) const;
    // Build CAN frame for USB Only Identify: The response will only be sent if this command is received directly via USB. This has no relation to the normal Identify command, which displays an LED pattern.
    spark_can_frame build_USB_ONLY_IDENTIFY(const Spark_USB_ONLY_IDENTIFY_t* values = nullptr) const;
    // Build CAN frame for USB Only Enter DFU Bootloader: Causes the device to reboot into the DFU bootloader if this command is received directly via USB
    spark_can_frame build_USB_ONLY_ENTER_DFU_BOOTLOADER(const Spark_USB_ONLY_ENTER_DFU_BOOTLOADER_t* values = nullptr) const;
    // Build CAN frame for Get Temperatures
    spark_can_frame build_GET_TEMPERATURES(const Spark_GET_TEMPERATURES_t* values = nullptr) const;
    // Build CAN frame for Get Motor Interface
    spark_can_frame build_GET_MOTOR_INTERFACE(const Spark_GET_MOTOR_INTERFACE_t* values = nullptr) const;
    // Build CAN frame for Get Parameter 0 to 15 Types: Get types of parameters 0 to 15
    spark_can_frame build_GET_PARAMETER_0_TO_15_TYPES(const Spark_GET_PARAMETER_0_TO_15_TYPES_t* values = nullptr) const;
    // Build CAN frame for Get Parameter 16 to 31 Types: Get types of parameters 16 to 31
    spark_can_frame build_GET_PARAMETER_16_TO_31_TYPES(const Spark_GET_PARAMETER_16_TO_31_TYPES_t* values = nullptr) const;
    // Build CAN frame for Get Parameter 32 to 47 Types: Get types of parameters 32 to 47
    spark_can_frame build_GET_PARAMETER_32_TO_47_TYPES(const Spark_GET_PARAMETER_32_TO_47_TYPES_t* values = nullptr) const;
    // Build CAN frame for Get Parameter 48 to 63 Types: Get types of parameters 48 to 63
    spark_can_frame build_GET_PARAMETER_48_TO_63_TYPES(const Spark_GET_PARAMETER_48_TO_63_TYPES_t* values = nullptr) const;
    // Build CAN frame for Get Parameter 64 to 79 Types: Get types of parameters 64 to 79
    spark_can_frame build_GET_PARAMETER_64_TO_79_TYPES(const Spark_GET_PARAMETER_64_TO_79_TYPES_t* values = nullptr) const;
    // Build CAN frame for Get Parameter 80 to 95 Types: Get types of parameters 80 to 95
    spark_can_frame build_GET_PARAMETER_80_TO_95_TYPES(const Spark_GET_PARAMETER_80_TO_95_TYPES_t* values = nullptr) const;
    // Build CAN frame for Get Parameter 96 to 111 Types: Get types of parameters 96 to 111
    spark_can_frame build_GET_PARAMETER_96_TO_111_TYPES(const Spark_GET_PARAMETER_96_TO_111_TYPES_t* values = nullptr) const;
    // Build CAN frame for Get Parameter 112 to 127 Types: Get types of parameters 112 to 127
    spark_can_frame build_GET_PARAMETER_112_TO_127_TYPES(const Spark_GET_PARAMETER_112_TO_127_TYPES_t* values = nullptr) const;
    // Build CAN frame for Get Parameter 128 to 143 Types: Get types of parameters 128 to 143
    spark_can_frame build_GET_PARAMETER_128_TO_143_TYPES(const Spark_GET_PARAMETER_128_TO_143_TYPES_t* values = nullptr) const;
    // Build CAN frame for Get Parameter 144 to 159 Types: Get types of parameters 144 to 159
    spark_can_frame build_GET_PARAMETER_144_TO_159_TYPES(const Spark_GET_PARAMETER_144_TO_159_TYPES_t* values = nullptr) const;
    // Build CAN frame for Get Parameter 160 to 175 Types: Get types of parameters 160 to 175
    spark_can_frame build_GET_PARAMETER_160_TO_175_TYPES(const Spark_GET_PARAMETER_160_TO_175_TYPES_t* values = nullptr) const;
    // Build CAN frame for Get Parameter 176 to 191 Types: Get types of parameters 176 to 191
    spark_can_frame build_GET_PARAMETER_176_TO_191_TYPES(const Spark_GET_PARAMETER_176_TO_191_TYPES_t* values = nullptr) const;
    // Build CAN frame for Get Parameter 192 to 207 Types: Get types of parameters 192 to 207
    spark_can_frame build_GET_PARAMETER_192_TO_207_TYPES(const Spark_GET_PARAMETER_192_TO_207_TYPES_t* values = nullptr) const;
    // Build CAN frame for Get Parameter 208 to 223 Types: Get types of parameters 208 to 223
    spark_can_frame build_GET_PARAMETER_208_TO_223_TYPES(const Spark_GET_PARAMETER_208_TO_223_TYPES_t* values = nullptr) const;
    // Build CAN frame for Get Parameter 224 to 239 Types: Get types of parameters 224 to 239
    spark_can_frame build_GET_PARAMETER_224_TO_239_TYPES(const Spark_GET_PARAMETER_224_TO_239_TYPES_t* values = nullptr) const;
    // Build CAN frame for Get Parameter 240 to 255 Types: Get types of parameters 240 to 255
    spark_can_frame build_GET_PARAMETER_240_TO_255_TYPES(const Spark_GET_PARAMETER_240_TO_255_TYPES_t* values = nullptr) const;
    // Build CAN frame for Parameter Write: Write a single parameter value. In response, a Parameter Write Response frame will be sent.
    spark_can_frame build_PARAMETER_WRITE(const Spark_PARAMETER_WRITE_t* values = nullptr) const;
    // Build CAN frame for Parameter Write Response: Response for a parameter write (including a write done as part of a dual-write)
    spark_can_frame build_PARAMETER_WRITE_RESPONSE(const Spark_PARAMETER_WRITE_RESPONSE_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 0 and 1: Read parameter 0 and 1 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_0_AND_1(const Spark_READ_PARAMETER_0_AND_1_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 2 and 3: Read parameter 2 and 3 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_2_AND_3(const Spark_READ_PARAMETER_2_AND_3_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 4 and 5: Read parameter 4 and 5 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_4_AND_5(const Spark_READ_PARAMETER_4_AND_5_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 6 and 7: Read parameter 6 and 7 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_6_AND_7(const Spark_READ_PARAMETER_6_AND_7_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 8 and 9: Read parameter 8 and 9 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_8_AND_9(const Spark_READ_PARAMETER_8_AND_9_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 10 and 11: Read parameter 10 and 11 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_10_AND_11(const Spark_READ_PARAMETER_10_AND_11_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 12 and 13: Read parameter 12 and 13 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_12_AND_13(const Spark_READ_PARAMETER_12_AND_13_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 14 and 15: Read parameter 14 and 15 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_14_AND_15(const Spark_READ_PARAMETER_14_AND_15_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 16 and 17: Read parameter 16 and 17 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_16_AND_17(const Spark_READ_PARAMETER_16_AND_17_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 18 and 19: Read parameter 18 and 19 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_18_AND_19(const Spark_READ_PARAMETER_18_AND_19_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 20 and 21: Read parameter 20 and 21 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_20_AND_21(const Spark_READ_PARAMETER_20_AND_21_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 22 and 23: Read parameter 22 and 23 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_22_AND_23(const Spark_READ_PARAMETER_22_AND_23_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 24 and 25: Read parameter 24 and 25 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_24_AND_25(const Spark_READ_PARAMETER_24_AND_25_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 26 and 27: Read parameter 26 and 27 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_26_AND_27(const Spark_READ_PARAMETER_26_AND_27_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 28 and 29: Read parameter 28 and 29 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_28_AND_29(const Spark_READ_PARAMETER_28_AND_29_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 30 and 31: Read parameter 30 and 31 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_30_AND_31(const Spark_READ_PARAMETER_30_AND_31_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 32 and 33: Read parameter 32 and 33 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_32_AND_33(const Spark_READ_PARAMETER_32_AND_33_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 34 and 35: Read parameter 34 and 35 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_34_AND_35(const Spark_READ_PARAMETER_34_AND_35_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 36 and 37: Read parameter 36 and 37 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_36_AND_37(const Spark_READ_PARAMETER_36_AND_37_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 38 and 39: Read parameter 38 and 39 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_38_AND_39(const Spark_READ_PARAMETER_38_AND_39_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 40 and 41: Read parameter 40 and 41 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_40_AND_41(const Spark_READ_PARAMETER_40_AND_41_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 42 and 43: Read parameter 42 and 43 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_42_AND_43(const Spark_READ_PARAMETER_42_AND_43_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 44 and 45: Read parameter 44 and 45 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_44_AND_45(const Spark_READ_PARAMETER_44_AND_45_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 46 and 47: Read parameter 46 and 47 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_46_AND_47(const Spark_READ_PARAMETER_46_AND_47_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 48 and 49: Read parameter 48 and 49 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_48_AND_49(const Spark_READ_PARAMETER_48_AND_49_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 50 and 51: Read parameter 50 and 51 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_50_AND_51(const Spark_READ_PARAMETER_50_AND_51_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 52 and 53: Read parameter 52 and 53 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_52_AND_53(const Spark_READ_PARAMETER_52_AND_53_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 54 and 55: Read parameter 54 and 55 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_54_AND_55(const Spark_READ_PARAMETER_54_AND_55_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 56 and 57: Read parameter 56 and 57 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_56_AND_57(const Spark_READ_PARAMETER_56_AND_57_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 58 and 59: Read parameter 58 and 59 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_58_AND_59(const Spark_READ_PARAMETER_58_AND_59_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 60 and 61: Read parameter 60 and 61 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_60_AND_61(const Spark_READ_PARAMETER_60_AND_61_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 62 and 63: Read parameter 62 and 63 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_62_AND_63(const Spark_READ_PARAMETER_62_AND_63_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 64 and 65: Read parameter 64 and 65 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_64_AND_65(const Spark_READ_PARAMETER_64_AND_65_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 66 and 67: Read parameter 66 and 67 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_66_AND_67(const Spark_READ_PARAMETER_66_AND_67_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 68 and 69: Read parameter 68 and 69 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_68_AND_69(const Spark_READ_PARAMETER_68_AND_69_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 70 and 71: Read parameter 70 and 71 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_70_AND_71(const Spark_READ_PARAMETER_70_AND_71_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 72 and 73: Read parameter 72 and 73 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_72_AND_73(const Spark_READ_PARAMETER_72_AND_73_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 74 and 75: Read parameter 74 and 75 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_74_AND_75(const Spark_READ_PARAMETER_74_AND_75_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 76 and 77: Read parameter 76 and 77 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_76_AND_77(const Spark_READ_PARAMETER_76_AND_77_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 78 and 79: Read parameter 78 and 79 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_78_AND_79(const Spark_READ_PARAMETER_78_AND_79_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 80 and 81: Read parameter 80 and 81 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_80_AND_81(const Spark_READ_PARAMETER_80_AND_81_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 82 and 83: Read parameter 82 and 83 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_82_AND_83(const Spark_READ_PARAMETER_82_AND_83_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 84 and 85: Read parameter 84 and 85 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_84_AND_85(const Spark_READ_PARAMETER_84_AND_85_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 86 and 87: Read parameter 86 and 87 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_86_AND_87(const Spark_READ_PARAMETER_86_AND_87_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 88 and 89: Read parameter 88 and 89 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_88_AND_89(const Spark_READ_PARAMETER_88_AND_89_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 90 and 91: Read parameter 90 and 91 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_90_AND_91(const Spark_READ_PARAMETER_90_AND_91_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 92 and 93: Read parameter 92 and 93 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_92_AND_93(const Spark_READ_PARAMETER_92_AND_93_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 94 and 95: Read parameter 94 and 95 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_94_AND_95(const Spark_READ_PARAMETER_94_AND_95_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 96 and 97: Read parameter 96 and 97 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_96_AND_97(const Spark_READ_PARAMETER_96_AND_97_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 98 and 99: Read parameter 98 and 99 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_98_AND_99(const Spark_READ_PARAMETER_98_AND_99_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 100 and 101: Read parameter 100 and 101 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_100_AND_101(const Spark_READ_PARAMETER_100_AND_101_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 102 and 103: Read parameter 102 and 103 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_102_AND_103(const Spark_READ_PARAMETER_102_AND_103_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 104 and 105: Read parameter 104 and 105 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_104_AND_105(const Spark_READ_PARAMETER_104_AND_105_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 106 and 107: Read parameter 106 and 107 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_106_AND_107(const Spark_READ_PARAMETER_106_AND_107_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 108 and 109: Read parameter 108 and 109 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_108_AND_109(const Spark_READ_PARAMETER_108_AND_109_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 110 and 111: Read parameter 110 and 111 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_110_AND_111(const Spark_READ_PARAMETER_110_AND_111_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 112 and 113: Read parameter 112 and 113 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_112_AND_113(const Spark_READ_PARAMETER_112_AND_113_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 114 and 115: Read parameter 114 and 115 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_114_AND_115(const Spark_READ_PARAMETER_114_AND_115_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 116 and 117: Read parameter 116 and 117 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_116_AND_117(const Spark_READ_PARAMETER_116_AND_117_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 118 and 119: Read parameter 118 and 119 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_118_AND_119(const Spark_READ_PARAMETER_118_AND_119_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 120 and 121: Read parameter 120 and 121 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_120_AND_121(const Spark_READ_PARAMETER_120_AND_121_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 122 and 123: Read parameter 122 and 123 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_122_AND_123(const Spark_READ_PARAMETER_122_AND_123_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 124 and 125: Read parameter 124 and 125 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_124_AND_125(const Spark_READ_PARAMETER_124_AND_125_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 126 and 127: Read parameter 126 and 127 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_126_AND_127(const Spark_READ_PARAMETER_126_AND_127_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 128 and 129: Read parameter 128 and 129 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_128_AND_129(const Spark_READ_PARAMETER_128_AND_129_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 130 and 131: Read parameter 130 and 131 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_130_AND_131(const Spark_READ_PARAMETER_130_AND_131_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 132 and 133: Read parameter 132 and 133 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_132_AND_133(const Spark_READ_PARAMETER_132_AND_133_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 134 and 135: Read parameter 134 and 135 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_134_AND_135(const Spark_READ_PARAMETER_134_AND_135_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 136 and 137: Read parameter 136 and 137 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_136_AND_137(const Spark_READ_PARAMETER_136_AND_137_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 138 and 139: Read parameter 138 and 139 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_138_AND_139(const Spark_READ_PARAMETER_138_AND_139_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 140 and 141: Read parameter 140 and 141 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_140_AND_141(const Spark_READ_PARAMETER_140_AND_141_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 142 and 143: Read parameter 142 and 143 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_142_AND_143(const Spark_READ_PARAMETER_142_AND_143_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 144 and 145: Read parameter 144 and 145 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_144_AND_145(const Spark_READ_PARAMETER_144_AND_145_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 146 and 147: Read parameter 146 and 147 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_146_AND_147(const Spark_READ_PARAMETER_146_AND_147_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 148 and 149: Read parameter 148 and 149 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_148_AND_149(const Spark_READ_PARAMETER_148_AND_149_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 150 and 151: Read parameter 150 and 151 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_150_AND_151(const Spark_READ_PARAMETER_150_AND_151_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 152 and 153: Read parameter 152 and 153 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_152_AND_153(const Spark_READ_PARAMETER_152_AND_153_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 154 and 155: Read parameter 154 and 155 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_154_AND_155(const Spark_READ_PARAMETER_154_AND_155_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 156 and 157: Read parameter 156 and 157 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_156_AND_157(const Spark_READ_PARAMETER_156_AND_157_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 158 and 159: Read parameter 158 and 159 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_158_AND_159(const Spark_READ_PARAMETER_158_AND_159_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 160 and 161: Read parameter 160 and 161 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_160_AND_161(const Spark_READ_PARAMETER_160_AND_161_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 162 and 163: Read parameter 162 and 163 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_162_AND_163(const Spark_READ_PARAMETER_162_AND_163_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 164 and 165: Read parameter 164 and 165 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_164_AND_165(const Spark_READ_PARAMETER_164_AND_165_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 166 and 167: Read parameter 166 and 167 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_166_AND_167(const Spark_READ_PARAMETER_166_AND_167_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 168 and 169: Read parameter 168 and 169 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_168_AND_169(const Spark_READ_PARAMETER_168_AND_169_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 170 and 171: Read parameter 170 and 171 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_170_AND_171(const Spark_READ_PARAMETER_170_AND_171_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 172 and 173: Read parameter 172 and 173 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_172_AND_173(const Spark_READ_PARAMETER_172_AND_173_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 174 and 175: Read parameter 174 and 175 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_174_AND_175(const Spark_READ_PARAMETER_174_AND_175_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 176 and 177: Read parameter 176 and 177 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_176_AND_177(const Spark_READ_PARAMETER_176_AND_177_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 178 and 179: Read parameter 178 and 179 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_178_AND_179(const Spark_READ_PARAMETER_178_AND_179_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 180 and 181: Read parameter 180 and 181 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_180_AND_181(const Spark_READ_PARAMETER_180_AND_181_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 182 and 183: Read parameter 182 and 183 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_182_AND_183(const Spark_READ_PARAMETER_182_AND_183_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 184 and 185: Read parameter 184 and 185 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_184_AND_185(const Spark_READ_PARAMETER_184_AND_185_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 186 and 187: Read parameter 186 and 187 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_186_AND_187(const Spark_READ_PARAMETER_186_AND_187_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 188 and 189: Read parameter 188 and 189 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_188_AND_189(const Spark_READ_PARAMETER_188_AND_189_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 190 and 191: Read parameter 190 and 191 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_190_AND_191(const Spark_READ_PARAMETER_190_AND_191_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 192 and 193: Read parameter 192 and 193 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_192_AND_193(const Spark_READ_PARAMETER_192_AND_193_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 194 and 195: Read parameter 194 and 195 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_194_AND_195(const Spark_READ_PARAMETER_194_AND_195_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 196 and 197: Read parameter 196 and 197 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_196_AND_197(const Spark_READ_PARAMETER_196_AND_197_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 198 and 199: Read parameter 198 and 199 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_198_AND_199(const Spark_READ_PARAMETER_198_AND_199_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 200 and 201: Read parameter 200 and 201 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_200_AND_201(const Spark_READ_PARAMETER_200_AND_201_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 202 and 203: Read parameter 202 and 203 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_202_AND_203(const Spark_READ_PARAMETER_202_AND_203_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 204 and 205: Read parameter 204 and 205 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_204_AND_205(const Spark_READ_PARAMETER_204_AND_205_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 206 and 207: Read parameter 206 and 207 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_206_AND_207(const Spark_READ_PARAMETER_206_AND_207_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 208 and 209: Read parameter 208 and 209 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_208_AND_209(const Spark_READ_PARAMETER_208_AND_209_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 210 and 211: Read parameter 210 and 211 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_210_AND_211(const Spark_READ_PARAMETER_210_AND_211_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 212 and 213: Read parameter 212 and 213 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_212_AND_213(const Spark_READ_PARAMETER_212_AND_213_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 214 and 215: Read parameter 214 and 215 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_214_AND_215(const Spark_READ_PARAMETER_214_AND_215_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 216 and 217: Read parameter 216 and 217 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_216_AND_217(const Spark_READ_PARAMETER_216_AND_217_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 218 and 219: Read parameter 218 and 219 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_218_AND_219(const Spark_READ_PARAMETER_218_AND_219_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 220 and 221: Read parameter 220 and 221 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_220_AND_221(const Spark_READ_PARAMETER_220_AND_221_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 222 and 223: Read parameter 222 and 223 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_222_AND_223(const Spark_READ_PARAMETER_222_AND_223_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 224 and 225: Read parameter 224 and 225 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_224_AND_225(const Spark_READ_PARAMETER_224_AND_225_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 226 and 227: Read parameter 226 and 227 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_226_AND_227(const Spark_READ_PARAMETER_226_AND_227_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 228 and 229: Read parameter 228 and 229 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_228_AND_229(const Spark_READ_PARAMETER_228_AND_229_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 230 and 231: Read parameter 230 and 231 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_230_AND_231(const Spark_READ_PARAMETER_230_AND_231_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 232 and 233: Read parameter 232 and 233 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_232_AND_233(const Spark_READ_PARAMETER_232_AND_233_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 234 and 235: Read parameter 234 and 235 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_234_AND_235(const Spark_READ_PARAMETER_234_AND_235_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 236 and 237: Read parameter 236 and 237 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_236_AND_237(const Spark_READ_PARAMETER_236_AND_237_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 238 and 239: Read parameter 238 and 239 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_238_AND_239(const Spark_READ_PARAMETER_238_AND_239_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 240 and 241: Read parameter 240 and 241 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_240_AND_241(const Spark_READ_PARAMETER_240_AND_241_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 242 and 243: Read parameter 242 and 243 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_242_AND_243(const Spark_READ_PARAMETER_242_AND_243_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 244 and 245: Read parameter 244 and 245 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_244_AND_245(const Spark_READ_PARAMETER_244_AND_245_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 246 and 247: Read parameter 246 and 247 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_246_AND_247(const Spark_READ_PARAMETER_246_AND_247_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 248 and 249: Read parameter 248 and 249 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_248_AND_249(const Spark_READ_PARAMETER_248_AND_249_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 250 and 251: Read parameter 250 and 251 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_250_AND_251(const Spark_READ_PARAMETER_250_AND_251_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 252 and 253: Read parameter 252 and 253 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_252_AND_253(const Spark_READ_PARAMETER_252_AND_253_t* values = nullptr) const;
    // Build CAN frame for Read Parameter 254 and 255: Read parameter 254 and 255 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4
    spark_can_frame build_READ_PARAMETER_254_AND_255(const Spark_READ_PARAMETER_254_AND_255_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 0 and 1: Write Parameter 0 and 1 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_0_AND_1(const Spark_WRITE_PARAMETER_0_AND_1_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 2 and 3: Write Parameter 2 and 3 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_2_AND_3(const Spark_WRITE_PARAMETER_2_AND_3_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 4 and 5: Write Parameter 4 and 5 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_4_AND_5(const Spark_WRITE_PARAMETER_4_AND_5_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 6 and 7: Write Parameter 6 and 7 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_6_AND_7(const Spark_WRITE_PARAMETER_6_AND_7_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 8 and 9: Write Parameter 8 and 9 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_8_AND_9(const Spark_WRITE_PARAMETER_8_AND_9_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 10 and 11: Write Parameter 10 and 11 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_10_AND_11(const Spark_WRITE_PARAMETER_10_AND_11_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 12 and 13: Write Parameter 12 and 13 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_12_AND_13(const Spark_WRITE_PARAMETER_12_AND_13_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 14 and 15: Write Parameter 14 and 15 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_14_AND_15(const Spark_WRITE_PARAMETER_14_AND_15_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 16 and 17: Write Parameter 16 and 17 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_16_AND_17(const Spark_WRITE_PARAMETER_16_AND_17_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 18 and 19: Write Parameter 18 and 19 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_18_AND_19(const Spark_WRITE_PARAMETER_18_AND_19_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 20 and 21: Write Parameter 20 and 21 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_20_AND_21(const Spark_WRITE_PARAMETER_20_AND_21_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 22 and 23: Write Parameter 22 and 23 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_22_AND_23(const Spark_WRITE_PARAMETER_22_AND_23_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 24 and 25: Write Parameter 24 and 25 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_24_AND_25(const Spark_WRITE_PARAMETER_24_AND_25_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 26 and 27: Write Parameter 26 and 27 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_26_AND_27(const Spark_WRITE_PARAMETER_26_AND_27_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 28 and 29: Write Parameter 28 and 29 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_28_AND_29(const Spark_WRITE_PARAMETER_28_AND_29_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 30 and 31: Write Parameter 30 and 31 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_30_AND_31(const Spark_WRITE_PARAMETER_30_AND_31_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 32 and 33: Write Parameter 32 and 33 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_32_AND_33(const Spark_WRITE_PARAMETER_32_AND_33_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 34 and 35: Write Parameter 34 and 35 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_34_AND_35(const Spark_WRITE_PARAMETER_34_AND_35_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 36 and 37: Write Parameter 36 and 37 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_36_AND_37(const Spark_WRITE_PARAMETER_36_AND_37_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 38 and 39: Write Parameter 38 and 39 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_38_AND_39(const Spark_WRITE_PARAMETER_38_AND_39_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 40 and 41: Write Parameter 40 and 41 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_40_AND_41(const Spark_WRITE_PARAMETER_40_AND_41_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 42 and 43: Write Parameter 42 and 43 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_42_AND_43(const Spark_WRITE_PARAMETER_42_AND_43_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 44 and 45: Write Parameter 44 and 45 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_44_AND_45(const Spark_WRITE_PARAMETER_44_AND_45_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 46 and 47: Write Parameter 46 and 47 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_46_AND_47(const Spark_WRITE_PARAMETER_46_AND_47_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 48 and 49: Write Parameter 48 and 49 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_48_AND_49(const Spark_WRITE_PARAMETER_48_AND_49_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 50 and 51: Write Parameter 50 and 51 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_50_AND_51(const Spark_WRITE_PARAMETER_50_AND_51_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 52 and 53: Write Parameter 52 and 53 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_52_AND_53(const Spark_WRITE_PARAMETER_52_AND_53_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 54 and 55: Write Parameter 54 and 55 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_54_AND_55(const Spark_WRITE_PARAMETER_54_AND_55_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 56 and 57: Write Parameter 56 and 57 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_56_AND_57(const Spark_WRITE_PARAMETER_56_AND_57_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 58 and 59: Write Parameter 58 and 59 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_58_AND_59(const Spark_WRITE_PARAMETER_58_AND_59_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 60 and 61: Write Parameter 60 and 61 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_60_AND_61(const Spark_WRITE_PARAMETER_60_AND_61_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 62 and 63: Write Parameter 62 and 63 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_62_AND_63(const Spark_WRITE_PARAMETER_62_AND_63_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 64 and 65: Write Parameter 64 and 65 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_64_AND_65(const Spark_WRITE_PARAMETER_64_AND_65_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 66 and 67: Write Parameter 66 and 67 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_66_AND_67(const Spark_WRITE_PARAMETER_66_AND_67_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 68 and 69: Write Parameter 68 and 69 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_68_AND_69(const Spark_WRITE_PARAMETER_68_AND_69_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 70 and 71: Write Parameter 70 and 71 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_70_AND_71(const Spark_WRITE_PARAMETER_70_AND_71_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 72 and 73: Write Parameter 72 and 73 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_72_AND_73(const Spark_WRITE_PARAMETER_72_AND_73_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 74 and 75: Write Parameter 74 and 75 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_74_AND_75(const Spark_WRITE_PARAMETER_74_AND_75_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 76 and 77: Write Parameter 76 and 77 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_76_AND_77(const Spark_WRITE_PARAMETER_76_AND_77_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 78 and 79: Write Parameter 78 and 79 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_78_AND_79(const Spark_WRITE_PARAMETER_78_AND_79_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 80 and 81: Write Parameter 80 and 81 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_80_AND_81(const Spark_WRITE_PARAMETER_80_AND_81_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 82 and 83: Write Parameter 82 and 83 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_82_AND_83(const Spark_WRITE_PARAMETER_82_AND_83_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 84 and 85: Write Parameter 84 and 85 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_84_AND_85(const Spark_WRITE_PARAMETER_84_AND_85_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 86 and 87: Write Parameter 86 and 87 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_86_AND_87(const Spark_WRITE_PARAMETER_86_AND_87_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 88 and 89: Write Parameter 88 and 89 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_88_AND_89(const Spark_WRITE_PARAMETER_88_AND_89_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 90 and 91: Write Parameter 90 and 91 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_90_AND_91(const Spark_WRITE_PARAMETER_90_AND_91_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 92 and 93: Write Parameter 92 and 93 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_92_AND_93(const Spark_WRITE_PARAMETER_92_AND_93_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 94 and 95: Write Parameter 94 and 95 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_94_AND_95(const Spark_WRITE_PARAMETER_94_AND_95_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 96 and 97: Write Parameter 96 and 97 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_96_AND_97(const Spark_WRITE_PARAMETER_96_AND_97_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 98 and 99: Write Parameter 98 and 99 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_98_AND_99(const Spark_WRITE_PARAMETER_98_AND_99_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 100 and 101: Write Parameter 100 and 101 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_100_AND_101(const Spark_WRITE_PARAMETER_100_AND_101_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 102 and 103: Write Parameter 102 and 103 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_102_AND_103(const Spark_WRITE_PARAMETER_102_AND_103_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 104 and 105: Write Parameter 104 and 105 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_104_AND_105(const Spark_WRITE_PARAMETER_104_AND_105_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 106 and 107: Write Parameter 106 and 107 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_106_AND_107(const Spark_WRITE_PARAMETER_106_AND_107_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 108 and 109: Write Parameter 108 and 109 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_108_AND_109(const Spark_WRITE_PARAMETER_108_AND_109_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 110 and 111: Write Parameter 110 and 111 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_110_AND_111(const Spark_WRITE_PARAMETER_110_AND_111_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 112 and 113: Write Parameter 112 and 113 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_112_AND_113(const Spark_WRITE_PARAMETER_112_AND_113_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 114 and 115: Write Parameter 114 and 115 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_114_AND_115(const Spark_WRITE_PARAMETER_114_AND_115_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 116 and 117: Write Parameter 116 and 117 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_116_AND_117(const Spark_WRITE_PARAMETER_116_AND_117_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 118 and 119: Write Parameter 118 and 119 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_118_AND_119(const Spark_WRITE_PARAMETER_118_AND_119_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 120 and 121: Write Parameter 120 and 121 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_120_AND_121(const Spark_WRITE_PARAMETER_120_AND_121_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 122 and 123: Write Parameter 122 and 123 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_122_AND_123(const Spark_WRITE_PARAMETER_122_AND_123_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 124 and 125: Write Parameter 124 and 125 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_124_AND_125(const Spark_WRITE_PARAMETER_124_AND_125_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 126 and 127: Write Parameter 126 and 127 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_126_AND_127(const Spark_WRITE_PARAMETER_126_AND_127_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 128 and 129: Write Parameter 128 and 129 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_128_AND_129(const Spark_WRITE_PARAMETER_128_AND_129_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 130 and 131: Write Parameter 130 and 131 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_130_AND_131(const Spark_WRITE_PARAMETER_130_AND_131_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 132 and 133: Write Parameter 132 and 133 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_132_AND_133(const Spark_WRITE_PARAMETER_132_AND_133_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 134 and 135: Write Parameter 134 and 135 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_134_AND_135(const Spark_WRITE_PARAMETER_134_AND_135_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 136 and 137: Write Parameter 136 and 137 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_136_AND_137(const Spark_WRITE_PARAMETER_136_AND_137_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 138 and 139: Write Parameter 138 and 139 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_138_AND_139(const Spark_WRITE_PARAMETER_138_AND_139_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 140 and 141: Write Parameter 140 and 141 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_140_AND_141(const Spark_WRITE_PARAMETER_140_AND_141_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 142 and 143: Write Parameter 142 and 143 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_142_AND_143(const Spark_WRITE_PARAMETER_142_AND_143_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 144 and 145: Write Parameter 144 and 145 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_144_AND_145(const Spark_WRITE_PARAMETER_144_AND_145_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 146 and 147: Write Parameter 146 and 147 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_146_AND_147(const Spark_WRITE_PARAMETER_146_AND_147_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 148 and 149: Write Parameter 148 and 149 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_148_AND_149(const Spark_WRITE_PARAMETER_148_AND_149_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 150 and 151: Write Parameter 150 and 151 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_150_AND_151(const Spark_WRITE_PARAMETER_150_AND_151_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 152 and 153: Write Parameter 152 and 153 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_152_AND_153(const Spark_WRITE_PARAMETER_152_AND_153_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 154 and 155: Write Parameter 154 and 155 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_154_AND_155(const Spark_WRITE_PARAMETER_154_AND_155_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 156 and 157: Write Parameter 156 and 157 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_156_AND_157(const Spark_WRITE_PARAMETER_156_AND_157_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 158 and 159: Write Parameter 158 and 159 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_158_AND_159(const Spark_WRITE_PARAMETER_158_AND_159_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 160 and 161: Write Parameter 160 and 161 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_160_AND_161(const Spark_WRITE_PARAMETER_160_AND_161_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 162 and 163: Write Parameter 162 and 163 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_162_AND_163(const Spark_WRITE_PARAMETER_162_AND_163_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 164 and 165: Write Parameter 164 and 165 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_164_AND_165(const Spark_WRITE_PARAMETER_164_AND_165_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 166 and 167: Write Parameter 166 and 167 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_166_AND_167(const Spark_WRITE_PARAMETER_166_AND_167_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 168 and 169: Write Parameter 168 and 169 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_168_AND_169(const Spark_WRITE_PARAMETER_168_AND_169_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 170 and 171: Write Parameter 170 and 171 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_170_AND_171(const Spark_WRITE_PARAMETER_170_AND_171_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 172 and 173: Write Parameter 172 and 173 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_172_AND_173(const Spark_WRITE_PARAMETER_172_AND_173_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 174 and 175: Write Parameter 174 and 175 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_174_AND_175(const Spark_WRITE_PARAMETER_174_AND_175_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 176 and 177: Write Parameter 176 and 177 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_176_AND_177(const Spark_WRITE_PARAMETER_176_AND_177_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 178 and 179: Write Parameter 178 and 179 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_178_AND_179(const Spark_WRITE_PARAMETER_178_AND_179_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 180 and 181: Write Parameter 180 and 181 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_180_AND_181(const Spark_WRITE_PARAMETER_180_AND_181_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 182 and 183: Write Parameter 182 and 183 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_182_AND_183(const Spark_WRITE_PARAMETER_182_AND_183_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 184 and 185: Write Parameter 184 and 185 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_184_AND_185(const Spark_WRITE_PARAMETER_184_AND_185_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 186 and 187: Write Parameter 186 and 187 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_186_AND_187(const Spark_WRITE_PARAMETER_186_AND_187_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 188 and 189: Write Parameter 188 and 189 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_188_AND_189(const Spark_WRITE_PARAMETER_188_AND_189_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 190 and 191: Write Parameter 190 and 191 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_190_AND_191(const Spark_WRITE_PARAMETER_190_AND_191_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 192 and 193: Write Parameter 192 and 193 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_192_AND_193(const Spark_WRITE_PARAMETER_192_AND_193_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 194 and 195: Write Parameter 194 and 195 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_194_AND_195(const Spark_WRITE_PARAMETER_194_AND_195_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 196 and 197: Write Parameter 196 and 197 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_196_AND_197(const Spark_WRITE_PARAMETER_196_AND_197_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 198 and 199: Write Parameter 198 and 199 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_198_AND_199(const Spark_WRITE_PARAMETER_198_AND_199_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 200 and 201: Write Parameter 200 and 201 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_200_AND_201(const Spark_WRITE_PARAMETER_200_AND_201_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 202 and 203: Write Parameter 202 and 203 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_202_AND_203(const Spark_WRITE_PARAMETER_202_AND_203_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 204 and 205: Write Parameter 204 and 205 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_204_AND_205(const Spark_WRITE_PARAMETER_204_AND_205_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 206 and 207: Write Parameter 206 and 207 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_206_AND_207(const Spark_WRITE_PARAMETER_206_AND_207_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 208 and 209: Write Parameter 208 and 209 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_208_AND_209(const Spark_WRITE_PARAMETER_208_AND_209_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 210 and 211: Write Parameter 210 and 211 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_210_AND_211(const Spark_WRITE_PARAMETER_210_AND_211_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 212 and 213: Write Parameter 212 and 213 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_212_AND_213(const Spark_WRITE_PARAMETER_212_AND_213_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 214 and 215: Write Parameter 214 and 215 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_214_AND_215(const Spark_WRITE_PARAMETER_214_AND_215_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 216 and 217: Write Parameter 216 and 217 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_216_AND_217(const Spark_WRITE_PARAMETER_216_AND_217_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 218 and 219: Write Parameter 218 and 219 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_218_AND_219(const Spark_WRITE_PARAMETER_218_AND_219_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 220 and 221: Write Parameter 220 and 221 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_220_AND_221(const Spark_WRITE_PARAMETER_220_AND_221_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 222 and 223: Write Parameter 222 and 223 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_222_AND_223(const Spark_WRITE_PARAMETER_222_AND_223_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 224 and 225: Write Parameter 224 and 225 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_224_AND_225(const Spark_WRITE_PARAMETER_224_AND_225_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 226 and 227: Write Parameter 226 and 227 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_226_AND_227(const Spark_WRITE_PARAMETER_226_AND_227_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 228 and 229: Write Parameter 228 and 229 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_228_AND_229(const Spark_WRITE_PARAMETER_228_AND_229_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 230 and 231: Write Parameter 230 and 231 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_230_AND_231(const Spark_WRITE_PARAMETER_230_AND_231_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 232 and 233: Write Parameter 232 and 233 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_232_AND_233(const Spark_WRITE_PARAMETER_232_AND_233_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 234 and 235: Write Parameter 234 and 235 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_234_AND_235(const Spark_WRITE_PARAMETER_234_AND_235_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 236 and 237: Write Parameter 236 and 237 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_236_AND_237(const Spark_WRITE_PARAMETER_236_AND_237_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 238 and 239: Write Parameter 238 and 239 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_238_AND_239(const Spark_WRITE_PARAMETER_238_AND_239_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 240 and 241: Write Parameter 240 and 241 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_240_AND_241(const Spark_WRITE_PARAMETER_240_AND_241_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 242 and 243: Write Parameter 242 and 243 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_242_AND_243(const Spark_WRITE_PARAMETER_242_AND_243_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 244 and 245: Write Parameter 244 and 245 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_244_AND_245(const Spark_WRITE_PARAMETER_244_AND_245_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 246 and 247: Write Parameter 246 and 247 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_246_AND_247(const Spark_WRITE_PARAMETER_246_AND_247_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 248 and 249: Write Parameter 248 and 249 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_248_AND_249(const Spark_WRITE_PARAMETER_248_AND_249_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 250 and 251: Write Parameter 250 and 251 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_250_AND_251(const Spark_WRITE_PARAMETER_250_AND_251_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 252 and 253: Write Parameter 252 and 253 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_252_AND_253(const Spark_WRITE_PARAMETER_252_AND_253_t* values = nullptr) const;
    // Build CAN frame for Write Parameter 254 and 255: Write Parameter 254 and 255 at the same time. Two Write Parameter Response frames will be sent in response.
    spark_can_frame build_WRITE_PARAMETER_254_AND_255(const Spark_WRITE_PARAMETER_254_AND_255_t* values = nullptr) const;
    // Build CAN frame for Start Follower Mode: Starts follower mode. The relevant parameters must already be configured. In response, a Start Follower Mode Response frame will be sent. Follower mode will be auto-started on boot if the Follower Mode Leader ID parameter is set to a non-zero value.
    spark_can_frame build_START_FOLLOWER_MODE(const Spark_START_FOLLOWER_MODE_t* values = nullptr) const;
    // Build CAN frame for Start Follower Mode Response: Response for a Start Follower Mode command
    spark_can_frame build_START_FOLLOWER_MODE_RESPONSE(const Spark_START_FOLLOWER_MODE_RESPONSE_t* values = nullptr) const;
    // Build CAN frame for Stop Follower Mode: Exits follower mode and causes the device to resume listening for setpoints addressed directly to it. In response, a Stop Follower Mode Response frame will be sent.
    spark_can_frame build_STOP_FOLLOWER_MODE(const Spark_STOP_FOLLOWER_MODE_t* values = nullptr) const;
    // Build CAN frame for Stop Follower Mode Response: Response for a Stop Follower Mode Command
    spark_can_frame build_STOP_FOLLOWER_MODE_RESPONSE(const Spark_STOP_FOLLOWER_MODE_RESPONSE_t* values = nullptr) const;
    // Build CAN frame for Enter SWDL CAN Bootloader
    spark_can_frame build_ENTER_SWDL_CAN_BOOTLOADER(const Spark_ENTER_SWDL_CAN_BOOTLOADER_t* values = nullptr) const;
    // Build CAN frame for Persist Parameters: Causes all parameters to be written to non-volatile storage. After the operation (which may take up to a second) completes, a Persist Parameters Response frame will be sent.
    spark_can_frame build_PERSIST_PARAMETERS(const Spark_PERSIST_PARAMETERS_t* values = nullptr) const;
    // Build and send Velocity Setpoint: Sets the Control Type to Velocity and sets the target velocity (pointer overload)
    MCP2515::ERROR send_velocity_setpoint(const Spark_VELOCITY_SETPOINT_t* values = nullptr) const;
    // Build and send Velocity Setpoint: Sets the Control Type to Velocity and sets the target velocity (by-value overload)
    MCP2515::ERROR send_velocity_setpoint(const Spark_VELOCITY_SETPOINT_t& values) const { return send_velocity_setpoint(&values); }
    // Build and send Velocity Setpoint: Sets the Control Type to Velocity and sets the target velocity via alias 'set_velocity_setpoint' (pointer overload)
    MCP2515::ERROR set_velocity_setpoint(const Spark_VELOCITY_SETPOINT_t* values = nullptr) const { return send_velocity_setpoint(values); }
    // Build and send Velocity Setpoint: Sets the Control Type to Velocity and sets the target velocity via alias 'set_velocity_setpoint' (by-value overload)
    MCP2515::ERROR set_velocity_setpoint(const Spark_VELOCITY_SETPOINT_t& values) const { return send_velocity_setpoint(values); }
    // Build and send Duty Cycle Setpoint: Sets the Control Type to Duty Cycle and sets the target duty cycle (from -1 to 1) (pointer overload)
    MCP2515::ERROR send_duty_cycle_setpoint(const Spark_DUTY_CYCLE_SETPOINT_t* values = nullptr) const;
    // Build and send Duty Cycle Setpoint: Sets the Control Type to Duty Cycle and sets the target duty cycle (from -1 to 1) (by-value overload)
    MCP2515::ERROR send_duty_cycle_setpoint(const Spark_DUTY_CYCLE_SETPOINT_t& values) const { return send_duty_cycle_setpoint(&values); }
    // Build and send Duty Cycle Setpoint: Sets the Control Type to Duty Cycle and sets the target duty cycle (from -1 to 1) via alias 'set_duty_cycle_setpoint' (pointer overload)
    MCP2515::ERROR set_duty_cycle_setpoint(const Spark_DUTY_CYCLE_SETPOINT_t* values = nullptr) const { return send_duty_cycle_setpoint(values); }
    // Build and send Duty Cycle Setpoint: Sets the Control Type to Duty Cycle and sets the target duty cycle (from -1 to 1) via alias 'set_duty_cycle_setpoint' (by-value overload)
    MCP2515::ERROR set_duty_cycle_setpoint(const Spark_DUTY_CYCLE_SETPOINT_t& values) const { return send_duty_cycle_setpoint(values); }
    // Build and send Position Setpoint: Sets the Control Type to Position and sets the target position (pointer overload)
    MCP2515::ERROR send_position_setpoint(const Spark_POSITION_SETPOINT_t* values = nullptr) const;
    // Build and send Position Setpoint: Sets the Control Type to Position and sets the target position (by-value overload)
    MCP2515::ERROR send_position_setpoint(const Spark_POSITION_SETPOINT_t& values) const { return send_position_setpoint(&values); }
    // Build and send Position Setpoint: Sets the Control Type to Position and sets the target position via alias 'set_position_setpoint' (pointer overload)
    MCP2515::ERROR set_position_setpoint(const Spark_POSITION_SETPOINT_t* values = nullptr) const { return send_position_setpoint(values); }
    // Build and send Position Setpoint: Sets the Control Type to Position and sets the target position via alias 'set_position_setpoint' (by-value overload)
    MCP2515::ERROR set_position_setpoint(const Spark_POSITION_SETPOINT_t& values) const { return send_position_setpoint(values); }
    // Build and send Voltage Setpoint: Sets the Control Type to Voltage and sets the target voltage (pointer overload)
    MCP2515::ERROR send_voltage_setpoint(const Spark_VOLTAGE_SETPOINT_t* values = nullptr) const;
    // Build and send Voltage Setpoint: Sets the Control Type to Voltage and sets the target voltage (by-value overload)
    MCP2515::ERROR send_voltage_setpoint(const Spark_VOLTAGE_SETPOINT_t& values) const { return send_voltage_setpoint(&values); }
    // Build and send Voltage Setpoint: Sets the Control Type to Voltage and sets the target voltage via alias 'set_voltage_setpoint' (pointer overload)
    MCP2515::ERROR set_voltage_setpoint(const Spark_VOLTAGE_SETPOINT_t* values = nullptr) const { return send_voltage_setpoint(values); }
    // Build and send Voltage Setpoint: Sets the Control Type to Voltage and sets the target voltage via alias 'set_voltage_setpoint' (by-value overload)
    MCP2515::ERROR set_voltage_setpoint(const Spark_VOLTAGE_SETPOINT_t& values) const { return send_voltage_setpoint(values); }
    // Build and send Current Setpoint: Sets the Control Type to Current and sets the target current (pointer overload)
    MCP2515::ERROR send_current_setpoint(const Spark_CURRENT_SETPOINT_t* values = nullptr) const;
    // Build and send Current Setpoint: Sets the Control Type to Current and sets the target current (by-value overload)
    MCP2515::ERROR send_current_setpoint(const Spark_CURRENT_SETPOINT_t& values) const { return send_current_setpoint(&values); }
    // Build and send Current Setpoint: Sets the Control Type to Current and sets the target current via alias 'set_current_setpoint' (pointer overload)
    MCP2515::ERROR set_current_setpoint(const Spark_CURRENT_SETPOINT_t* values = nullptr) const { return send_current_setpoint(values); }
    // Build and send Current Setpoint: Sets the Control Type to Current and sets the target current via alias 'set_current_setpoint' (by-value overload)
    MCP2515::ERROR set_current_setpoint(const Spark_CURRENT_SETPOINT_t& values) const { return send_current_setpoint(values); }
    // Build and send MAXMotion Position Setpoint: Sets the Control Type to MAXMotion Position Control and sets the target position (pointer overload)
    MCP2515::ERROR send_maxmotion_position_setpoint(const Spark_MAXMOTION_POSITION_SETPOINT_t* values = nullptr) const;
    // Build and send MAXMotion Position Setpoint: Sets the Control Type to MAXMotion Position Control and sets the target position (by-value overload)
    MCP2515::ERROR send_maxmotion_position_setpoint(const Spark_MAXMOTION_POSITION_SETPOINT_t& values) const { return send_maxmotion_position_setpoint(&values); }
    // Build and send MAXMotion Position Setpoint: Sets the Control Type to MAXMotion Position Control and sets the target position via alias 'set_maxmotion_position_setpoint' (pointer overload)
    MCP2515::ERROR set_maxmotion_position_setpoint(const Spark_MAXMOTION_POSITION_SETPOINT_t* values = nullptr) const { return send_maxmotion_position_setpoint(values); }
    // Build and send MAXMotion Position Setpoint: Sets the Control Type to MAXMotion Position Control and sets the target position via alias 'set_maxmotion_position_setpoint' (by-value overload)
    MCP2515::ERROR set_maxmotion_position_setpoint(const Spark_MAXMOTION_POSITION_SETPOINT_t& values) const { return send_maxmotion_position_setpoint(values); }
    // Build and send MAXMotion Velocity Setpoint: Sets the Control Type to MAXMotion Velocity Control and sets the target velocity (pointer overload)
    MCP2515::ERROR send_maxmotion_velocity_setpoint(const Spark_MAXMOTION_VELOCITY_SETPOINT_t* values = nullptr) const;
    // Build and send MAXMotion Velocity Setpoint: Sets the Control Type to MAXMotion Velocity Control and sets the target velocity (by-value overload)
    MCP2515::ERROR send_maxmotion_velocity_setpoint(const Spark_MAXMOTION_VELOCITY_SETPOINT_t& values) const { return send_maxmotion_velocity_setpoint(&values); }
    // Build and send MAXMotion Velocity Setpoint: Sets the Control Type to MAXMotion Velocity Control and sets the target velocity via alias 'set_maxmotion_velocity_setpoint' (pointer overload)
    MCP2515::ERROR set_maxmotion_velocity_setpoint(const Spark_MAXMOTION_VELOCITY_SETPOINT_t* values = nullptr) const { return send_maxmotion_velocity_setpoint(values); }
    // Build and send MAXMotion Velocity Setpoint: Sets the Control Type to MAXMotion Velocity Control and sets the target velocity via alias 'set_maxmotion_velocity_setpoint' (by-value overload)
    MCP2515::ERROR set_maxmotion_velocity_setpoint(const Spark_MAXMOTION_VELOCITY_SETPOINT_t& values) const { return send_maxmotion_velocity_setpoint(values); }
    // Build and send Set Statuses Enabled: Enable or disable status frames. In response, a Set Statuses Enabled Response frame will be sent. (pointer overload)
    MCP2515::ERROR send_set_statuses_enabled(const Spark_SET_STATUSES_ENABLED_t* values = nullptr) const;
    // Build and send Set Statuses Enabled: Enable or disable status frames. In response, a Set Statuses Enabled Response frame will be sent. (by-value overload)
    MCP2515::ERROR send_set_statuses_enabled(const Spark_SET_STATUSES_ENABLED_t& values) const { return send_set_statuses_enabled(&values); }
    // Build and send Set Statuses Enabled: Enable or disable status frames. In response, a Set Statuses Enabled Response frame will be sent. via alias 'set_statuses_enabled' (pointer overload)
    MCP2515::ERROR set_statuses_enabled(const Spark_SET_STATUSES_ENABLED_t* values = nullptr) const { return send_set_statuses_enabled(values); }
    // Build and send Set Statuses Enabled: Enable or disable status frames. In response, a Set Statuses Enabled Response frame will be sent. via alias 'set_statuses_enabled' (by-value overload)
    MCP2515::ERROR set_statuses_enabled(const Spark_SET_STATUSES_ENABLED_t& values) const { return send_set_statuses_enabled(values); }
    // Build and send Set Statuses Enabled Response: Response for a Set Statuses Enabled command (pointer overload)
    MCP2515::ERROR send_set_statuses_enabled_response(const Spark_SET_STATUSES_ENABLED_RESPONSE_t* values = nullptr) const;
    // Build and send Set Statuses Enabled Response: Response for a Set Statuses Enabled command (by-value overload)
    MCP2515::ERROR send_set_statuses_enabled_response(const Spark_SET_STATUSES_ENABLED_RESPONSE_t& values) const { return send_set_statuses_enabled_response(&values); }
    // Build and send Set Statuses Enabled Response: Response for a Set Statuses Enabled command via alias 'set_statuses_enabled_response' (pointer overload)
    MCP2515::ERROR set_statuses_enabled_response(const Spark_SET_STATUSES_ENABLED_RESPONSE_t* values = nullptr) const { return send_set_statuses_enabled_response(values); }
    // Build and send Set Statuses Enabled Response: Response for a Set Statuses Enabled command via alias 'set_statuses_enabled_response' (by-value overload)
    MCP2515::ERROR set_statuses_enabled_response(const Spark_SET_STATUSES_ENABLED_RESPONSE_t& values) const { return send_set_statuses_enabled_response(values); }
    // Build and send Persist Parameters Response (pointer overload)
    MCP2515::ERROR send_persist_parameters_response(const Spark_PERSIST_PARAMETERS_RESPONSE_t* values = nullptr) const;
    // Build and send Persist Parameters Response (by-value overload)
    MCP2515::ERROR send_persist_parameters_response(const Spark_PERSIST_PARAMETERS_RESPONSE_t& values) const { return send_persist_parameters_response(&values); }
    // Build and send Reset Safe Parameters: Resets most writable parameters to their default values, except CAN ID, Motor Type, Idle Mode, PWM Input Deadband, and Duty Cycle Offset. In response, a Reset Safe Parameters Response frame is sent. (pointer overload)
    MCP2515::ERROR send_reset_safe_parameters(const Spark_RESET_SAFE_PARAMETERS_t* values = nullptr) const;
    // Build and send Reset Safe Parameters: Resets most writable parameters to their default values, except CAN ID, Motor Type, Idle Mode, PWM Input Deadband, and Duty Cycle Offset. In response, a Reset Safe Parameters Response frame is sent. (by-value overload)
    MCP2515::ERROR send_reset_safe_parameters(const Spark_RESET_SAFE_PARAMETERS_t& values) const { return send_reset_safe_parameters(&values); }
    // Build and send Reset Safe Parameters Response: Response for a Reset Safe Parameters command (pointer overload)
    MCP2515::ERROR send_reset_safe_parameters_response(const Spark_RESET_SAFE_PARAMETERS_RESPONSE_t* values = nullptr) const;
    // Build and send Reset Safe Parameters Response: Response for a Reset Safe Parameters command (by-value overload)
    MCP2515::ERROR send_reset_safe_parameters_response(const Spark_RESET_SAFE_PARAMETERS_RESPONSE_t& values) const { return send_reset_safe_parameters_response(&values); }
    // Build and send Complete Factory Reset: Resets all writable parameters to default values, even CAN ID, Motor Type, Idle Mode, PWM Input Deadband, and Duty Cycle Offset. In response, a Complete Factory Reset Response frame is sent. (pointer overload)
    MCP2515::ERROR send_complete_factory_reset(const Spark_COMPLETE_FACTORY_RESET_t* values = nullptr) const;
    // Build and send Complete Factory Reset: Resets all writable parameters to default values, even CAN ID, Motor Type, Idle Mode, PWM Input Deadband, and Duty Cycle Offset. In response, a Complete Factory Reset Response frame is sent. (by-value overload)
    MCP2515::ERROR send_complete_factory_reset(const Spark_COMPLETE_FACTORY_RESET_t& values) const { return send_complete_factory_reset(&values); }
    // Build and send Complete Factory Reset Response: Response for a Complete Factory Reset command (pointer overload)
    MCP2515::ERROR send_complete_factory_reset_response(const Spark_COMPLETE_FACTORY_RESET_RESPONSE_t* values = nullptr) const;
    // Build and send Complete Factory Reset Response: Response for a Complete Factory Reset command (by-value overload)
    MCP2515::ERROR send_complete_factory_reset_response(const Spark_COMPLETE_FACTORY_RESET_RESPONSE_t& values) const { return send_complete_factory_reset_response(&values); }
    // Build and send Clear Faults (pointer overload)
    MCP2515::ERROR send_clear_faults(const Spark_CLEAR_FAULTS_t* values = nullptr) const;
    // Build and send Clear Faults (by-value overload)
    MCP2515::ERROR send_clear_faults(const Spark_CLEAR_FAULTS_t& values) const { return send_clear_faults(&values); }
    // Build and send Identify Unique SPARK: Makes the specified, single SPARK (even if there are multiple SPARKs that have the same CAN ID) temporarily perform a special blink pattern that will make it stand out (pointer overload)
    MCP2515::ERROR send_identify_unique_spark(const Spark_IDENTIFY_UNIQUE_SPARK_t* values = nullptr) const;
    // Build and send Identify Unique SPARK: Makes the specified, single SPARK (even if there are multiple SPARKs that have the same CAN ID) temporarily perform a special blink pattern that will make it stand out (by-value overload)
    MCP2515::ERROR send_identify_unique_spark(const Spark_IDENTIFY_UNIQUE_SPARK_t& values) const { return send_identify_unique_spark(&values); }
    // Build and send Identify: Makes the SPARK temporarily perform a special blink pattern that will make it stand out. Use Identify Unique Device if there may be multiple SPARKs with the same CAN ID. (pointer overload)
    MCP2515::ERROR send_identify(const Spark_IDENTIFY_t* values = nullptr) const;
    // Build and send Identify: Makes the SPARK temporarily perform a special blink pattern that will make it stand out. Use Identify Unique Device if there may be multiple SPARKs with the same CAN ID. (by-value overload)
    MCP2515::ERROR send_identify(const Spark_IDENTIFY_t& values) const { return send_identify(&values); }
    // Build and send Nack: As of SPARK MAX firmware 1.6.3, this is only used as a potential response to setting the CAN ID (pointer overload)
    MCP2515::ERROR send_nack(const Spark_NACK_t* values = nullptr) const;
    // Build and send Nack: As of SPARK MAX firmware 1.6.3, this is only used as a potential response to setting the CAN ID (by-value overload)
    MCP2515::ERROR send_nack(const Spark_NACK_t& values) const { return send_nack(&values); }
    // Build and send Ack: As of SPARK MAX firmware 1.6.3, this is only used as a potential response to setting the CAN ID (pointer overload)
    MCP2515::ERROR send_ack(const Spark_ACK_t* values = nullptr) const;
    // Build and send Ack: As of SPARK MAX firmware 1.6.3, this is only used as a potential response to setting the CAN ID (by-value overload)
    MCP2515::ERROR send_ack(const Spark_ACK_t& values) const { return send_ack(&values); }
    // Build and send LED Sync: Causes all SPARKs on the bus to synchronize their LED patterns (pointer overload)
    MCP2515::ERROR send_led_sync(const Spark_LED_SYNC_t* values = nullptr) const;
    // Build and send LED Sync: Causes all SPARKs on the bus to synchronize their LED patterns (by-value overload)
    MCP2515::ERROR send_led_sync(const Spark_LED_SYNC_t& values) const { return send_led_sync(&values); }
    // Build and send Set CAN ID: Allows changing the CAN ID when multiple devices on the bus currently have the same CAN ID. Under normal circumstances, the CAN ID parameter can be used. (pointer overload)
    MCP2515::ERROR send_set_can_id(const Spark_SET_CAN_ID_t* values = nullptr) const;
    // Build and send Set CAN ID: Allows changing the CAN ID when multiple devices on the bus currently have the same CAN ID. Under normal circumstances, the CAN ID parameter can be used. (by-value overload)
    MCP2515::ERROR send_set_can_id(const Spark_SET_CAN_ID_t& values) const { return send_set_can_id(&values); }
    // Build and send Set CAN ID: Allows changing the CAN ID when multiple devices on the bus currently have the same CAN ID. Under normal circumstances, the CAN ID parameter can be used. via alias 'set_can_id' (pointer overload)
    MCP2515::ERROR set_can_id(const Spark_SET_CAN_ID_t* values = nullptr) const { return send_set_can_id(values); }
    // Build and send Set CAN ID: Allows changing the CAN ID when multiple devices on the bus currently have the same CAN ID. Under normal circumstances, the CAN ID parameter can be used. via alias 'set_can_id' (by-value overload)
    MCP2515::ERROR set_can_id(const Spark_SET_CAN_ID_t& values) const { return send_set_can_id(values); }
    // Build and send Get Firmware Version (pointer overload)
    MCP2515::ERROR send_get_firmware_version(const Spark_GET_FIRMWARE_VERSION_t* values = nullptr) const;
    // Build and send Get Firmware Version (by-value overload)
    MCP2515::ERROR send_get_firmware_version(const Spark_GET_FIRMWARE_VERSION_t& values) const { return send_get_firmware_version(&values); }
    // Build and send SWDL Data: Broadcast from the host to all SPARKs in SWDL mode, containing a slice of firmware data (pointer overload)
    MCP2515::ERROR send_swdl_data(const Spark_SWDL_DATA_t* values = nullptr) const;
    // Build and send SWDL Data: Broadcast from the host to all SPARKs in SWDL mode, containing a slice of firmware data (by-value overload)
    MCP2515::ERROR send_swdl_data(const Spark_SWDL_DATA_t& values) const { return send_swdl_data(&values); }
    // Build and send SWDL Checksum: Broadcast from the host to all SPARKs in SWDL mode, containing the checksum of the full firmware image that was just sent (pointer overload)
    MCP2515::ERROR send_swdl_checksum(const Spark_SWDL_CHECKSUM_t* values = nullptr) const;
    // Build and send SWDL Checksum: Broadcast from the host to all SPARKs in SWDL mode, containing the checksum of the full firmware image that was just sent (by-value overload)
    MCP2515::ERROR send_swdl_checksum(const Spark_SWDL_CHECKSUM_t& values) const { return send_swdl_checksum(&values); }
    // Build and send SWDL Retransmit: Sent by SPARK devices in response to receiving an SWDL Checksum frame that does not match the firmware data they received (pointer overload)
    MCP2515::ERROR send_swdl_retransmit(const Spark_SWDL_RETRANSMIT_t* values = nullptr) const;
    // Build and send SWDL Retransmit: Sent by SPARK devices in response to receiving an SWDL Checksum frame that does not match the firmware data they received (by-value overload)
    MCP2515::ERROR send_swdl_retransmit(const Spark_SWDL_RETRANSMIT_t& values) const { return send_swdl_retransmit(&values); }
    // Build and send Set Primary Encoder Position (pointer overload)
    MCP2515::ERROR send_set_primary_encoder_position(const Spark_SET_PRIMARY_ENCODER_POSITION_t* values = nullptr) const;
    // Build and send Set Primary Encoder Position (by-value overload)
    MCP2515::ERROR send_set_primary_encoder_position(const Spark_SET_PRIMARY_ENCODER_POSITION_t& values) const { return send_set_primary_encoder_position(&values); }
    // Build and send Set Primary Encoder Position via alias 'set_primary_encoder_position' (pointer overload)
    MCP2515::ERROR set_primary_encoder_position(const Spark_SET_PRIMARY_ENCODER_POSITION_t* values = nullptr) const { return send_set_primary_encoder_position(values); }
    // Build and send Set Primary Encoder Position via alias 'set_primary_encoder_position' (by-value overload)
    MCP2515::ERROR set_primary_encoder_position(const Spark_SET_PRIMARY_ENCODER_POSITION_t& values) const { return send_set_primary_encoder_position(values); }
    // Build and send Set I Accumulation (pointer overload)
    MCP2515::ERROR send_set_i_accumulation(const Spark_SET_I_ACCUMULATION_t* values = nullptr) const;
    // Build and send Set I Accumulation (by-value overload)
    MCP2515::ERROR send_set_i_accumulation(const Spark_SET_I_ACCUMULATION_t& values) const { return send_set_i_accumulation(&values); }
    // Build and send Set I Accumulation via alias 'set_i_accumulation' (pointer overload)
    MCP2515::ERROR set_i_accumulation(const Spark_SET_I_ACCUMULATION_t* values = nullptr) const { return send_set_i_accumulation(values); }
    // Build and send Set I Accumulation via alias 'set_i_accumulation' (by-value overload)
    MCP2515::ERROR set_i_accumulation(const Spark_SET_I_ACCUMULATION_t& values) const { return send_set_i_accumulation(values); }
    // Build and send Set Analog Position (pointer overload)
    MCP2515::ERROR send_set_analog_position(const Spark_SET_ANALOG_POSITION_t* values = nullptr) const;
    // Build and send Set Analog Position (by-value overload)
    MCP2515::ERROR send_set_analog_position(const Spark_SET_ANALOG_POSITION_t& values) const { return send_set_analog_position(&values); }
    // Build and send Set Analog Position via alias 'set_analog_position' (pointer overload)
    MCP2515::ERROR set_analog_position(const Spark_SET_ANALOG_POSITION_t* values = nullptr) const { return send_set_analog_position(values); }
    // Build and send Set Analog Position via alias 'set_analog_position' (by-value overload)
    MCP2515::ERROR set_analog_position(const Spark_SET_ANALOG_POSITION_t& values) const { return send_set_analog_position(values); }
    // Build and send Set Ext or Alt Encoder Position (pointer overload)
    MCP2515::ERROR send_set_ext_or_alt_encoder_position(const Spark_SET_EXT_OR_ALT_ENCODER_POSITION_t* values = nullptr) const;
    // Build and send Set Ext or Alt Encoder Position (by-value overload)
    MCP2515::ERROR send_set_ext_or_alt_encoder_position(const Spark_SET_EXT_OR_ALT_ENCODER_POSITION_t& values) const { return send_set_ext_or_alt_encoder_position(&values); }
    // Build and send Set Ext or Alt Encoder Position via alias 'set_ext_or_alt_encoder_position' (pointer overload)
    MCP2515::ERROR set_ext_or_alt_encoder_position(const Spark_SET_EXT_OR_ALT_ENCODER_POSITION_t* values = nullptr) const { return send_set_ext_or_alt_encoder_position(values); }
    // Build and send Set Ext or Alt Encoder Position via alias 'set_ext_or_alt_encoder_position' (by-value overload)
    MCP2515::ERROR set_ext_or_alt_encoder_position(const Spark_SET_EXT_OR_ALT_ENCODER_POSITION_t& values) const { return send_set_ext_or_alt_encoder_position(values); }
    // Build and send Set Duty Cycle Position (pointer overload)
    MCP2515::ERROR send_set_duty_cycle_position(const Spark_SET_DUTY_CYCLE_POSITION_t* values = nullptr) const;
    // Build and send Set Duty Cycle Position (by-value overload)
    MCP2515::ERROR send_set_duty_cycle_position(const Spark_SET_DUTY_CYCLE_POSITION_t& values) const { return send_set_duty_cycle_position(&values); }
    // Build and send Set Duty Cycle Position via alias 'set_duty_cycle_position' (pointer overload)
    MCP2515::ERROR set_duty_cycle_position(const Spark_SET_DUTY_CYCLE_POSITION_t* values = nullptr) const { return send_set_duty_cycle_position(values); }
    // Build and send Set Duty Cycle Position via alias 'set_duty_cycle_position' (by-value overload)
    MCP2515::ERROR set_duty_cycle_position(const Spark_SET_DUTY_CYCLE_POSITION_t& values) const { return send_set_duty_cycle_position(values); }
    // Build and send Secondary Heartbeat: Heartbeat that allows enabling only specific SPARKs, but only gets respected when the SPARK is not locked to the Universal Heartbeat or Primary Heartbeat (pointer overload)
    MCP2515::ERROR send_secondary_heartbeat(const Spark_SECONDARY_HEARTBEAT_t* values = nullptr) const;
    // Build and send Secondary Heartbeat: Heartbeat that allows enabling only specific SPARKs, but only gets respected when the SPARK is not locked to the Universal Heartbeat or Primary Heartbeat (by-value overload)
    MCP2515::ERROR send_secondary_heartbeat(const Spark_SECONDARY_HEARTBEAT_t& values) const { return send_secondary_heartbeat(&values); }
    // Build and send USB Only Identify: The response will only be sent if this command is received directly via USB. This has no relation to the normal Identify command, which displays an LED pattern. (pointer overload)
    MCP2515::ERROR send_usb_only_identify(const Spark_USB_ONLY_IDENTIFY_t* values = nullptr) const;
    // Build and send USB Only Identify: The response will only be sent if this command is received directly via USB. This has no relation to the normal Identify command, which displays an LED pattern. (by-value overload)
    MCP2515::ERROR send_usb_only_identify(const Spark_USB_ONLY_IDENTIFY_t& values) const { return send_usb_only_identify(&values); }
    // Build and send USB Only Enter DFU Bootloader: Causes the device to reboot into the DFU bootloader if this command is received directly via USB (pointer overload)
    MCP2515::ERROR send_usb_only_enter_dfu_bootloader(const Spark_USB_ONLY_ENTER_DFU_BOOTLOADER_t* values = nullptr) const;
    // Build and send USB Only Enter DFU Bootloader: Causes the device to reboot into the DFU bootloader if this command is received directly via USB (by-value overload)
    MCP2515::ERROR send_usb_only_enter_dfu_bootloader(const Spark_USB_ONLY_ENTER_DFU_BOOTLOADER_t& values) const { return send_usb_only_enter_dfu_bootloader(&values); }
    // Build and send Get Temperatures (pointer overload)
    MCP2515::ERROR send_get_temperatures(const Spark_GET_TEMPERATURES_t* values = nullptr) const;
    // Build and send Get Temperatures (by-value overload)
    MCP2515::ERROR send_get_temperatures(const Spark_GET_TEMPERATURES_t& values) const { return send_get_temperatures(&values); }
    // Build and send Get Motor Interface (pointer overload)
    MCP2515::ERROR send_get_motor_interface(const Spark_GET_MOTOR_INTERFACE_t* values = nullptr) const;
    // Build and send Get Motor Interface (by-value overload)
    MCP2515::ERROR send_get_motor_interface(const Spark_GET_MOTOR_INTERFACE_t& values) const { return send_get_motor_interface(&values); }
    // Build and send Get Parameter 0 to 15 Types: Get types of parameters 0 to 15 (pointer overload)
    MCP2515::ERROR send_get_parameter_0_to_15_types(const Spark_GET_PARAMETER_0_TO_15_TYPES_t* values = nullptr) const;
    // Build and send Get Parameter 0 to 15 Types: Get types of parameters 0 to 15 (by-value overload)
    MCP2515::ERROR send_get_parameter_0_to_15_types(const Spark_GET_PARAMETER_0_TO_15_TYPES_t& values) const { return send_get_parameter_0_to_15_types(&values); }
    // Build and send Get Parameter 16 to 31 Types: Get types of parameters 16 to 31 (pointer overload)
    MCP2515::ERROR send_get_parameter_16_to_31_types(const Spark_GET_PARAMETER_16_TO_31_TYPES_t* values = nullptr) const;
    // Build and send Get Parameter 16 to 31 Types: Get types of parameters 16 to 31 (by-value overload)
    MCP2515::ERROR send_get_parameter_16_to_31_types(const Spark_GET_PARAMETER_16_TO_31_TYPES_t& values) const { return send_get_parameter_16_to_31_types(&values); }
    // Build and send Get Parameter 32 to 47 Types: Get types of parameters 32 to 47 (pointer overload)
    MCP2515::ERROR send_get_parameter_32_to_47_types(const Spark_GET_PARAMETER_32_TO_47_TYPES_t* values = nullptr) const;
    // Build and send Get Parameter 32 to 47 Types: Get types of parameters 32 to 47 (by-value overload)
    MCP2515::ERROR send_get_parameter_32_to_47_types(const Spark_GET_PARAMETER_32_TO_47_TYPES_t& values) const { return send_get_parameter_32_to_47_types(&values); }
    // Build and send Get Parameter 48 to 63 Types: Get types of parameters 48 to 63 (pointer overload)
    MCP2515::ERROR send_get_parameter_48_to_63_types(const Spark_GET_PARAMETER_48_TO_63_TYPES_t* values = nullptr) const;
    // Build and send Get Parameter 48 to 63 Types: Get types of parameters 48 to 63 (by-value overload)
    MCP2515::ERROR send_get_parameter_48_to_63_types(const Spark_GET_PARAMETER_48_TO_63_TYPES_t& values) const { return send_get_parameter_48_to_63_types(&values); }
    // Build and send Get Parameter 64 to 79 Types: Get types of parameters 64 to 79 (pointer overload)
    MCP2515::ERROR send_get_parameter_64_to_79_types(const Spark_GET_PARAMETER_64_TO_79_TYPES_t* values = nullptr) const;
    // Build and send Get Parameter 64 to 79 Types: Get types of parameters 64 to 79 (by-value overload)
    MCP2515::ERROR send_get_parameter_64_to_79_types(const Spark_GET_PARAMETER_64_TO_79_TYPES_t& values) const { return send_get_parameter_64_to_79_types(&values); }
    // Build and send Get Parameter 80 to 95 Types: Get types of parameters 80 to 95 (pointer overload)
    MCP2515::ERROR send_get_parameter_80_to_95_types(const Spark_GET_PARAMETER_80_TO_95_TYPES_t* values = nullptr) const;
    // Build and send Get Parameter 80 to 95 Types: Get types of parameters 80 to 95 (by-value overload)
    MCP2515::ERROR send_get_parameter_80_to_95_types(const Spark_GET_PARAMETER_80_TO_95_TYPES_t& values) const { return send_get_parameter_80_to_95_types(&values); }
    // Build and send Get Parameter 96 to 111 Types: Get types of parameters 96 to 111 (pointer overload)
    MCP2515::ERROR send_get_parameter_96_to_111_types(const Spark_GET_PARAMETER_96_TO_111_TYPES_t* values = nullptr) const;
    // Build and send Get Parameter 96 to 111 Types: Get types of parameters 96 to 111 (by-value overload)
    MCP2515::ERROR send_get_parameter_96_to_111_types(const Spark_GET_PARAMETER_96_TO_111_TYPES_t& values) const { return send_get_parameter_96_to_111_types(&values); }
    // Build and send Get Parameter 112 to 127 Types: Get types of parameters 112 to 127 (pointer overload)
    MCP2515::ERROR send_get_parameter_112_to_127_types(const Spark_GET_PARAMETER_112_TO_127_TYPES_t* values = nullptr) const;
    // Build and send Get Parameter 112 to 127 Types: Get types of parameters 112 to 127 (by-value overload)
    MCP2515::ERROR send_get_parameter_112_to_127_types(const Spark_GET_PARAMETER_112_TO_127_TYPES_t& values) const { return send_get_parameter_112_to_127_types(&values); }
    // Build and send Get Parameter 128 to 143 Types: Get types of parameters 128 to 143 (pointer overload)
    MCP2515::ERROR send_get_parameter_128_to_143_types(const Spark_GET_PARAMETER_128_TO_143_TYPES_t* values = nullptr) const;
    // Build and send Get Parameter 128 to 143 Types: Get types of parameters 128 to 143 (by-value overload)
    MCP2515::ERROR send_get_parameter_128_to_143_types(const Spark_GET_PARAMETER_128_TO_143_TYPES_t& values) const { return send_get_parameter_128_to_143_types(&values); }
    // Build and send Get Parameter 144 to 159 Types: Get types of parameters 144 to 159 (pointer overload)
    MCP2515::ERROR send_get_parameter_144_to_159_types(const Spark_GET_PARAMETER_144_TO_159_TYPES_t* values = nullptr) const;
    // Build and send Get Parameter 144 to 159 Types: Get types of parameters 144 to 159 (by-value overload)
    MCP2515::ERROR send_get_parameter_144_to_159_types(const Spark_GET_PARAMETER_144_TO_159_TYPES_t& values) const { return send_get_parameter_144_to_159_types(&values); }
    // Build and send Get Parameter 160 to 175 Types: Get types of parameters 160 to 175 (pointer overload)
    MCP2515::ERROR send_get_parameter_160_to_175_types(const Spark_GET_PARAMETER_160_TO_175_TYPES_t* values = nullptr) const;
    // Build and send Get Parameter 160 to 175 Types: Get types of parameters 160 to 175 (by-value overload)
    MCP2515::ERROR send_get_parameter_160_to_175_types(const Spark_GET_PARAMETER_160_TO_175_TYPES_t& values) const { return send_get_parameter_160_to_175_types(&values); }
    // Build and send Get Parameter 176 to 191 Types: Get types of parameters 176 to 191 (pointer overload)
    MCP2515::ERROR send_get_parameter_176_to_191_types(const Spark_GET_PARAMETER_176_TO_191_TYPES_t* values = nullptr) const;
    // Build and send Get Parameter 176 to 191 Types: Get types of parameters 176 to 191 (by-value overload)
    MCP2515::ERROR send_get_parameter_176_to_191_types(const Spark_GET_PARAMETER_176_TO_191_TYPES_t& values) const { return send_get_parameter_176_to_191_types(&values); }
    // Build and send Get Parameter 192 to 207 Types: Get types of parameters 192 to 207 (pointer overload)
    MCP2515::ERROR send_get_parameter_192_to_207_types(const Spark_GET_PARAMETER_192_TO_207_TYPES_t* values = nullptr) const;
    // Build and send Get Parameter 192 to 207 Types: Get types of parameters 192 to 207 (by-value overload)
    MCP2515::ERROR send_get_parameter_192_to_207_types(const Spark_GET_PARAMETER_192_TO_207_TYPES_t& values) const { return send_get_parameter_192_to_207_types(&values); }
    // Build and send Get Parameter 208 to 223 Types: Get types of parameters 208 to 223 (pointer overload)
    MCP2515::ERROR send_get_parameter_208_to_223_types(const Spark_GET_PARAMETER_208_TO_223_TYPES_t* values = nullptr) const;
    // Build and send Get Parameter 208 to 223 Types: Get types of parameters 208 to 223 (by-value overload)
    MCP2515::ERROR send_get_parameter_208_to_223_types(const Spark_GET_PARAMETER_208_TO_223_TYPES_t& values) const { return send_get_parameter_208_to_223_types(&values); }
    // Build and send Get Parameter 224 to 239 Types: Get types of parameters 224 to 239 (pointer overload)
    MCP2515::ERROR send_get_parameter_224_to_239_types(const Spark_GET_PARAMETER_224_TO_239_TYPES_t* values = nullptr) const;
    // Build and send Get Parameter 224 to 239 Types: Get types of parameters 224 to 239 (by-value overload)
    MCP2515::ERROR send_get_parameter_224_to_239_types(const Spark_GET_PARAMETER_224_TO_239_TYPES_t& values) const { return send_get_parameter_224_to_239_types(&values); }
    // Build and send Get Parameter 240 to 255 Types: Get types of parameters 240 to 255 (pointer overload)
    MCP2515::ERROR send_get_parameter_240_to_255_types(const Spark_GET_PARAMETER_240_TO_255_TYPES_t* values = nullptr) const;
    // Build and send Get Parameter 240 to 255 Types: Get types of parameters 240 to 255 (by-value overload)
    MCP2515::ERROR send_get_parameter_240_to_255_types(const Spark_GET_PARAMETER_240_TO_255_TYPES_t& values) const { return send_get_parameter_240_to_255_types(&values); }
    // Build and send Parameter Write: Write a single parameter value. In response, a Parameter Write Response frame will be sent. (pointer overload)
    MCP2515::ERROR send_parameter_write(const Spark_PARAMETER_WRITE_t* values = nullptr) const;
    // Build and send Parameter Write: Write a single parameter value. In response, a Parameter Write Response frame will be sent. (by-value overload)
    MCP2515::ERROR send_parameter_write(const Spark_PARAMETER_WRITE_t& values) const { return send_parameter_write(&values); }
    // Build and send Parameter Write Response: Response for a parameter write (including a write done as part of a dual-write) (pointer overload)
    MCP2515::ERROR send_parameter_write_response(const Spark_PARAMETER_WRITE_RESPONSE_t* values = nullptr) const;
    // Build and send Parameter Write Response: Response for a parameter write (including a write done as part of a dual-write) (by-value overload)
    MCP2515::ERROR send_parameter_write_response(const Spark_PARAMETER_WRITE_RESPONSE_t& values) const { return send_parameter_write_response(&values); }
    // Build and send Read Parameter 0 and 1: Read parameter 0 and 1 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_0_and_1(const Spark_READ_PARAMETER_0_AND_1_t* values = nullptr) const;
    // Build and send Read Parameter 0 and 1: Read parameter 0 and 1 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_0_and_1(const Spark_READ_PARAMETER_0_AND_1_t& values) const { return send_read_parameter_0_and_1(&values); }
    // Build and send Read Parameter 2 and 3: Read parameter 2 and 3 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_2_and_3(const Spark_READ_PARAMETER_2_AND_3_t* values = nullptr) const;
    // Build and send Read Parameter 2 and 3: Read parameter 2 and 3 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_2_and_3(const Spark_READ_PARAMETER_2_AND_3_t& values) const { return send_read_parameter_2_and_3(&values); }
    // Build and send Read Parameter 4 and 5: Read parameter 4 and 5 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_4_and_5(const Spark_READ_PARAMETER_4_AND_5_t* values = nullptr) const;
    // Build and send Read Parameter 4 and 5: Read parameter 4 and 5 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_4_and_5(const Spark_READ_PARAMETER_4_AND_5_t& values) const { return send_read_parameter_4_and_5(&values); }
    // Build and send Read Parameter 6 and 7: Read parameter 6 and 7 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_6_and_7(const Spark_READ_PARAMETER_6_AND_7_t* values = nullptr) const;
    // Build and send Read Parameter 6 and 7: Read parameter 6 and 7 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_6_and_7(const Spark_READ_PARAMETER_6_AND_7_t& values) const { return send_read_parameter_6_and_7(&values); }
    // Build and send Read Parameter 8 and 9: Read parameter 8 and 9 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_8_and_9(const Spark_READ_PARAMETER_8_AND_9_t* values = nullptr) const;
    // Build and send Read Parameter 8 and 9: Read parameter 8 and 9 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_8_and_9(const Spark_READ_PARAMETER_8_AND_9_t& values) const { return send_read_parameter_8_and_9(&values); }
    // Build and send Read Parameter 10 and 11: Read parameter 10 and 11 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_10_and_11(const Spark_READ_PARAMETER_10_AND_11_t* values = nullptr) const;
    // Build and send Read Parameter 10 and 11: Read parameter 10 and 11 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_10_and_11(const Spark_READ_PARAMETER_10_AND_11_t& values) const { return send_read_parameter_10_and_11(&values); }
    // Build and send Read Parameter 12 and 13: Read parameter 12 and 13 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_12_and_13(const Spark_READ_PARAMETER_12_AND_13_t* values = nullptr) const;
    // Build and send Read Parameter 12 and 13: Read parameter 12 and 13 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_12_and_13(const Spark_READ_PARAMETER_12_AND_13_t& values) const { return send_read_parameter_12_and_13(&values); }
    // Build and send Read Parameter 14 and 15: Read parameter 14 and 15 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_14_and_15(const Spark_READ_PARAMETER_14_AND_15_t* values = nullptr) const;
    // Build and send Read Parameter 14 and 15: Read parameter 14 and 15 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_14_and_15(const Spark_READ_PARAMETER_14_AND_15_t& values) const { return send_read_parameter_14_and_15(&values); }
    // Build and send Read Parameter 16 and 17: Read parameter 16 and 17 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_16_and_17(const Spark_READ_PARAMETER_16_AND_17_t* values = nullptr) const;
    // Build and send Read Parameter 16 and 17: Read parameter 16 and 17 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_16_and_17(const Spark_READ_PARAMETER_16_AND_17_t& values) const { return send_read_parameter_16_and_17(&values); }
    // Build and send Read Parameter 18 and 19: Read parameter 18 and 19 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_18_and_19(const Spark_READ_PARAMETER_18_AND_19_t* values = nullptr) const;
    // Build and send Read Parameter 18 and 19: Read parameter 18 and 19 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_18_and_19(const Spark_READ_PARAMETER_18_AND_19_t& values) const { return send_read_parameter_18_and_19(&values); }
    // Build and send Read Parameter 20 and 21: Read parameter 20 and 21 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_20_and_21(const Spark_READ_PARAMETER_20_AND_21_t* values = nullptr) const;
    // Build and send Read Parameter 20 and 21: Read parameter 20 and 21 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_20_and_21(const Spark_READ_PARAMETER_20_AND_21_t& values) const { return send_read_parameter_20_and_21(&values); }
    // Build and send Read Parameter 22 and 23: Read parameter 22 and 23 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_22_and_23(const Spark_READ_PARAMETER_22_AND_23_t* values = nullptr) const;
    // Build and send Read Parameter 22 and 23: Read parameter 22 and 23 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_22_and_23(const Spark_READ_PARAMETER_22_AND_23_t& values) const { return send_read_parameter_22_and_23(&values); }
    // Build and send Read Parameter 24 and 25: Read parameter 24 and 25 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_24_and_25(const Spark_READ_PARAMETER_24_AND_25_t* values = nullptr) const;
    // Build and send Read Parameter 24 and 25: Read parameter 24 and 25 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_24_and_25(const Spark_READ_PARAMETER_24_AND_25_t& values) const { return send_read_parameter_24_and_25(&values); }
    // Build and send Read Parameter 26 and 27: Read parameter 26 and 27 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_26_and_27(const Spark_READ_PARAMETER_26_AND_27_t* values = nullptr) const;
    // Build and send Read Parameter 26 and 27: Read parameter 26 and 27 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_26_and_27(const Spark_READ_PARAMETER_26_AND_27_t& values) const { return send_read_parameter_26_and_27(&values); }
    // Build and send Read Parameter 28 and 29: Read parameter 28 and 29 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_28_and_29(const Spark_READ_PARAMETER_28_AND_29_t* values = nullptr) const;
    // Build and send Read Parameter 28 and 29: Read parameter 28 and 29 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_28_and_29(const Spark_READ_PARAMETER_28_AND_29_t& values) const { return send_read_parameter_28_and_29(&values); }
    // Build and send Read Parameter 30 and 31: Read parameter 30 and 31 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_30_and_31(const Spark_READ_PARAMETER_30_AND_31_t* values = nullptr) const;
    // Build and send Read Parameter 30 and 31: Read parameter 30 and 31 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_30_and_31(const Spark_READ_PARAMETER_30_AND_31_t& values) const { return send_read_parameter_30_and_31(&values); }
    // Build and send Read Parameter 32 and 33: Read parameter 32 and 33 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_32_and_33(const Spark_READ_PARAMETER_32_AND_33_t* values = nullptr) const;
    // Build and send Read Parameter 32 and 33: Read parameter 32 and 33 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_32_and_33(const Spark_READ_PARAMETER_32_AND_33_t& values) const { return send_read_parameter_32_and_33(&values); }
    // Build and send Read Parameter 34 and 35: Read parameter 34 and 35 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_34_and_35(const Spark_READ_PARAMETER_34_AND_35_t* values = nullptr) const;
    // Build and send Read Parameter 34 and 35: Read parameter 34 and 35 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_34_and_35(const Spark_READ_PARAMETER_34_AND_35_t& values) const { return send_read_parameter_34_and_35(&values); }
    // Build and send Read Parameter 36 and 37: Read parameter 36 and 37 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_36_and_37(const Spark_READ_PARAMETER_36_AND_37_t* values = nullptr) const;
    // Build and send Read Parameter 36 and 37: Read parameter 36 and 37 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_36_and_37(const Spark_READ_PARAMETER_36_AND_37_t& values) const { return send_read_parameter_36_and_37(&values); }
    // Build and send Read Parameter 38 and 39: Read parameter 38 and 39 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_38_and_39(const Spark_READ_PARAMETER_38_AND_39_t* values = nullptr) const;
    // Build and send Read Parameter 38 and 39: Read parameter 38 and 39 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_38_and_39(const Spark_READ_PARAMETER_38_AND_39_t& values) const { return send_read_parameter_38_and_39(&values); }
    // Build and send Read Parameter 40 and 41: Read parameter 40 and 41 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_40_and_41(const Spark_READ_PARAMETER_40_AND_41_t* values = nullptr) const;
    // Build and send Read Parameter 40 and 41: Read parameter 40 and 41 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_40_and_41(const Spark_READ_PARAMETER_40_AND_41_t& values) const { return send_read_parameter_40_and_41(&values); }
    // Build and send Read Parameter 42 and 43: Read parameter 42 and 43 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_42_and_43(const Spark_READ_PARAMETER_42_AND_43_t* values = nullptr) const;
    // Build and send Read Parameter 42 and 43: Read parameter 42 and 43 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_42_and_43(const Spark_READ_PARAMETER_42_AND_43_t& values) const { return send_read_parameter_42_and_43(&values); }
    // Build and send Read Parameter 44 and 45: Read parameter 44 and 45 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_44_and_45(const Spark_READ_PARAMETER_44_AND_45_t* values = nullptr) const;
    // Build and send Read Parameter 44 and 45: Read parameter 44 and 45 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_44_and_45(const Spark_READ_PARAMETER_44_AND_45_t& values) const { return send_read_parameter_44_and_45(&values); }
    // Build and send Read Parameter 46 and 47: Read parameter 46 and 47 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_46_and_47(const Spark_READ_PARAMETER_46_AND_47_t* values = nullptr) const;
    // Build and send Read Parameter 46 and 47: Read parameter 46 and 47 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_46_and_47(const Spark_READ_PARAMETER_46_AND_47_t& values) const { return send_read_parameter_46_and_47(&values); }
    // Build and send Read Parameter 48 and 49: Read parameter 48 and 49 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_48_and_49(const Spark_READ_PARAMETER_48_AND_49_t* values = nullptr) const;
    // Build and send Read Parameter 48 and 49: Read parameter 48 and 49 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_48_and_49(const Spark_READ_PARAMETER_48_AND_49_t& values) const { return send_read_parameter_48_and_49(&values); }
    // Build and send Read Parameter 50 and 51: Read parameter 50 and 51 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_50_and_51(const Spark_READ_PARAMETER_50_AND_51_t* values = nullptr) const;
    // Build and send Read Parameter 50 and 51: Read parameter 50 and 51 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_50_and_51(const Spark_READ_PARAMETER_50_AND_51_t& values) const { return send_read_parameter_50_and_51(&values); }
    // Build and send Read Parameter 52 and 53: Read parameter 52 and 53 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_52_and_53(const Spark_READ_PARAMETER_52_AND_53_t* values = nullptr) const;
    // Build and send Read Parameter 52 and 53: Read parameter 52 and 53 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_52_and_53(const Spark_READ_PARAMETER_52_AND_53_t& values) const { return send_read_parameter_52_and_53(&values); }
    // Build and send Read Parameter 54 and 55: Read parameter 54 and 55 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_54_and_55(const Spark_READ_PARAMETER_54_AND_55_t* values = nullptr) const;
    // Build and send Read Parameter 54 and 55: Read parameter 54 and 55 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_54_and_55(const Spark_READ_PARAMETER_54_AND_55_t& values) const { return send_read_parameter_54_and_55(&values); }
    // Build and send Read Parameter 56 and 57: Read parameter 56 and 57 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_56_and_57(const Spark_READ_PARAMETER_56_AND_57_t* values = nullptr) const;
    // Build and send Read Parameter 56 and 57: Read parameter 56 and 57 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_56_and_57(const Spark_READ_PARAMETER_56_AND_57_t& values) const { return send_read_parameter_56_and_57(&values); }
    // Build and send Read Parameter 58 and 59: Read parameter 58 and 59 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_58_and_59(const Spark_READ_PARAMETER_58_AND_59_t* values = nullptr) const;
    // Build and send Read Parameter 58 and 59: Read parameter 58 and 59 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_58_and_59(const Spark_READ_PARAMETER_58_AND_59_t& values) const { return send_read_parameter_58_and_59(&values); }
    // Build and send Read Parameter 60 and 61: Read parameter 60 and 61 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_60_and_61(const Spark_READ_PARAMETER_60_AND_61_t* values = nullptr) const;
    // Build and send Read Parameter 60 and 61: Read parameter 60 and 61 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_60_and_61(const Spark_READ_PARAMETER_60_AND_61_t& values) const { return send_read_parameter_60_and_61(&values); }
    // Build and send Read Parameter 62 and 63: Read parameter 62 and 63 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_62_and_63(const Spark_READ_PARAMETER_62_AND_63_t* values = nullptr) const;
    // Build and send Read Parameter 62 and 63: Read parameter 62 and 63 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_62_and_63(const Spark_READ_PARAMETER_62_AND_63_t& values) const { return send_read_parameter_62_and_63(&values); }
    // Build and send Read Parameter 64 and 65: Read parameter 64 and 65 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_64_and_65(const Spark_READ_PARAMETER_64_AND_65_t* values = nullptr) const;
    // Build and send Read Parameter 64 and 65: Read parameter 64 and 65 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_64_and_65(const Spark_READ_PARAMETER_64_AND_65_t& values) const { return send_read_parameter_64_and_65(&values); }
    // Build and send Read Parameter 66 and 67: Read parameter 66 and 67 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_66_and_67(const Spark_READ_PARAMETER_66_AND_67_t* values = nullptr) const;
    // Build and send Read Parameter 66 and 67: Read parameter 66 and 67 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_66_and_67(const Spark_READ_PARAMETER_66_AND_67_t& values) const { return send_read_parameter_66_and_67(&values); }
    // Build and send Read Parameter 68 and 69: Read parameter 68 and 69 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_68_and_69(const Spark_READ_PARAMETER_68_AND_69_t* values = nullptr) const;
    // Build and send Read Parameter 68 and 69: Read parameter 68 and 69 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_68_and_69(const Spark_READ_PARAMETER_68_AND_69_t& values) const { return send_read_parameter_68_and_69(&values); }
    // Build and send Read Parameter 70 and 71: Read parameter 70 and 71 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_70_and_71(const Spark_READ_PARAMETER_70_AND_71_t* values = nullptr) const;
    // Build and send Read Parameter 70 and 71: Read parameter 70 and 71 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_70_and_71(const Spark_READ_PARAMETER_70_AND_71_t& values) const { return send_read_parameter_70_and_71(&values); }
    // Build and send Read Parameter 72 and 73: Read parameter 72 and 73 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_72_and_73(const Spark_READ_PARAMETER_72_AND_73_t* values = nullptr) const;
    // Build and send Read Parameter 72 and 73: Read parameter 72 and 73 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_72_and_73(const Spark_READ_PARAMETER_72_AND_73_t& values) const { return send_read_parameter_72_and_73(&values); }
    // Build and send Read Parameter 74 and 75: Read parameter 74 and 75 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_74_and_75(const Spark_READ_PARAMETER_74_AND_75_t* values = nullptr) const;
    // Build and send Read Parameter 74 and 75: Read parameter 74 and 75 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_74_and_75(const Spark_READ_PARAMETER_74_AND_75_t& values) const { return send_read_parameter_74_and_75(&values); }
    // Build and send Read Parameter 76 and 77: Read parameter 76 and 77 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_76_and_77(const Spark_READ_PARAMETER_76_AND_77_t* values = nullptr) const;
    // Build and send Read Parameter 76 and 77: Read parameter 76 and 77 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_76_and_77(const Spark_READ_PARAMETER_76_AND_77_t& values) const { return send_read_parameter_76_and_77(&values); }
    // Build and send Read Parameter 78 and 79: Read parameter 78 and 79 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_78_and_79(const Spark_READ_PARAMETER_78_AND_79_t* values = nullptr) const;
    // Build and send Read Parameter 78 and 79: Read parameter 78 and 79 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_78_and_79(const Spark_READ_PARAMETER_78_AND_79_t& values) const { return send_read_parameter_78_and_79(&values); }
    // Build and send Read Parameter 80 and 81: Read parameter 80 and 81 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_80_and_81(const Spark_READ_PARAMETER_80_AND_81_t* values = nullptr) const;
    // Build and send Read Parameter 80 and 81: Read parameter 80 and 81 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_80_and_81(const Spark_READ_PARAMETER_80_AND_81_t& values) const { return send_read_parameter_80_and_81(&values); }
    // Build and send Read Parameter 82 and 83: Read parameter 82 and 83 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_82_and_83(const Spark_READ_PARAMETER_82_AND_83_t* values = nullptr) const;
    // Build and send Read Parameter 82 and 83: Read parameter 82 and 83 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_82_and_83(const Spark_READ_PARAMETER_82_AND_83_t& values) const { return send_read_parameter_82_and_83(&values); }
    // Build and send Read Parameter 84 and 85: Read parameter 84 and 85 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_84_and_85(const Spark_READ_PARAMETER_84_AND_85_t* values = nullptr) const;
    // Build and send Read Parameter 84 and 85: Read parameter 84 and 85 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_84_and_85(const Spark_READ_PARAMETER_84_AND_85_t& values) const { return send_read_parameter_84_and_85(&values); }
    // Build and send Read Parameter 86 and 87: Read parameter 86 and 87 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_86_and_87(const Spark_READ_PARAMETER_86_AND_87_t* values = nullptr) const;
    // Build and send Read Parameter 86 and 87: Read parameter 86 and 87 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_86_and_87(const Spark_READ_PARAMETER_86_AND_87_t& values) const { return send_read_parameter_86_and_87(&values); }
    // Build and send Read Parameter 88 and 89: Read parameter 88 and 89 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_88_and_89(const Spark_READ_PARAMETER_88_AND_89_t* values = nullptr) const;
    // Build and send Read Parameter 88 and 89: Read parameter 88 and 89 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_88_and_89(const Spark_READ_PARAMETER_88_AND_89_t& values) const { return send_read_parameter_88_and_89(&values); }
    // Build and send Read Parameter 90 and 91: Read parameter 90 and 91 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_90_and_91(const Spark_READ_PARAMETER_90_AND_91_t* values = nullptr) const;
    // Build and send Read Parameter 90 and 91: Read parameter 90 and 91 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_90_and_91(const Spark_READ_PARAMETER_90_AND_91_t& values) const { return send_read_parameter_90_and_91(&values); }
    // Build and send Read Parameter 92 and 93: Read parameter 92 and 93 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_92_and_93(const Spark_READ_PARAMETER_92_AND_93_t* values = nullptr) const;
    // Build and send Read Parameter 92 and 93: Read parameter 92 and 93 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_92_and_93(const Spark_READ_PARAMETER_92_AND_93_t& values) const { return send_read_parameter_92_and_93(&values); }
    // Build and send Read Parameter 94 and 95: Read parameter 94 and 95 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_94_and_95(const Spark_READ_PARAMETER_94_AND_95_t* values = nullptr) const;
    // Build and send Read Parameter 94 and 95: Read parameter 94 and 95 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_94_and_95(const Spark_READ_PARAMETER_94_AND_95_t& values) const { return send_read_parameter_94_and_95(&values); }
    // Build and send Read Parameter 96 and 97: Read parameter 96 and 97 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_96_and_97(const Spark_READ_PARAMETER_96_AND_97_t* values = nullptr) const;
    // Build and send Read Parameter 96 and 97: Read parameter 96 and 97 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_96_and_97(const Spark_READ_PARAMETER_96_AND_97_t& values) const { return send_read_parameter_96_and_97(&values); }
    // Build and send Read Parameter 98 and 99: Read parameter 98 and 99 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_98_and_99(const Spark_READ_PARAMETER_98_AND_99_t* values = nullptr) const;
    // Build and send Read Parameter 98 and 99: Read parameter 98 and 99 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_98_and_99(const Spark_READ_PARAMETER_98_AND_99_t& values) const { return send_read_parameter_98_and_99(&values); }
    // Build and send Read Parameter 100 and 101: Read parameter 100 and 101 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_100_and_101(const Spark_READ_PARAMETER_100_AND_101_t* values = nullptr) const;
    // Build and send Read Parameter 100 and 101: Read parameter 100 and 101 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_100_and_101(const Spark_READ_PARAMETER_100_AND_101_t& values) const { return send_read_parameter_100_and_101(&values); }
    // Build and send Read Parameter 102 and 103: Read parameter 102 and 103 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_102_and_103(const Spark_READ_PARAMETER_102_AND_103_t* values = nullptr) const;
    // Build and send Read Parameter 102 and 103: Read parameter 102 and 103 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_102_and_103(const Spark_READ_PARAMETER_102_AND_103_t& values) const { return send_read_parameter_102_and_103(&values); }
    // Build and send Read Parameter 104 and 105: Read parameter 104 and 105 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_104_and_105(const Spark_READ_PARAMETER_104_AND_105_t* values = nullptr) const;
    // Build and send Read Parameter 104 and 105: Read parameter 104 and 105 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_104_and_105(const Spark_READ_PARAMETER_104_AND_105_t& values) const { return send_read_parameter_104_and_105(&values); }
    // Build and send Read Parameter 106 and 107: Read parameter 106 and 107 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_106_and_107(const Spark_READ_PARAMETER_106_AND_107_t* values = nullptr) const;
    // Build and send Read Parameter 106 and 107: Read parameter 106 and 107 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_106_and_107(const Spark_READ_PARAMETER_106_AND_107_t& values) const { return send_read_parameter_106_and_107(&values); }
    // Build and send Read Parameter 108 and 109: Read parameter 108 and 109 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_108_and_109(const Spark_READ_PARAMETER_108_AND_109_t* values = nullptr) const;
    // Build and send Read Parameter 108 and 109: Read parameter 108 and 109 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_108_and_109(const Spark_READ_PARAMETER_108_AND_109_t& values) const { return send_read_parameter_108_and_109(&values); }
    // Build and send Read Parameter 110 and 111: Read parameter 110 and 111 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_110_and_111(const Spark_READ_PARAMETER_110_AND_111_t* values = nullptr) const;
    // Build and send Read Parameter 110 and 111: Read parameter 110 and 111 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_110_and_111(const Spark_READ_PARAMETER_110_AND_111_t& values) const { return send_read_parameter_110_and_111(&values); }
    // Build and send Read Parameter 112 and 113: Read parameter 112 and 113 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_112_and_113(const Spark_READ_PARAMETER_112_AND_113_t* values = nullptr) const;
    // Build and send Read Parameter 112 and 113: Read parameter 112 and 113 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_112_and_113(const Spark_READ_PARAMETER_112_AND_113_t& values) const { return send_read_parameter_112_and_113(&values); }
    // Build and send Read Parameter 114 and 115: Read parameter 114 and 115 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_114_and_115(const Spark_READ_PARAMETER_114_AND_115_t* values = nullptr) const;
    // Build and send Read Parameter 114 and 115: Read parameter 114 and 115 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_114_and_115(const Spark_READ_PARAMETER_114_AND_115_t& values) const { return send_read_parameter_114_and_115(&values); }
    // Build and send Read Parameter 116 and 117: Read parameter 116 and 117 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_116_and_117(const Spark_READ_PARAMETER_116_AND_117_t* values = nullptr) const;
    // Build and send Read Parameter 116 and 117: Read parameter 116 and 117 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_116_and_117(const Spark_READ_PARAMETER_116_AND_117_t& values) const { return send_read_parameter_116_and_117(&values); }
    // Build and send Read Parameter 118 and 119: Read parameter 118 and 119 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_118_and_119(const Spark_READ_PARAMETER_118_AND_119_t* values = nullptr) const;
    // Build and send Read Parameter 118 and 119: Read parameter 118 and 119 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_118_and_119(const Spark_READ_PARAMETER_118_AND_119_t& values) const { return send_read_parameter_118_and_119(&values); }
    // Build and send Read Parameter 120 and 121: Read parameter 120 and 121 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_120_and_121(const Spark_READ_PARAMETER_120_AND_121_t* values = nullptr) const;
    // Build and send Read Parameter 120 and 121: Read parameter 120 and 121 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_120_and_121(const Spark_READ_PARAMETER_120_AND_121_t& values) const { return send_read_parameter_120_and_121(&values); }
    // Build and send Read Parameter 122 and 123: Read parameter 122 and 123 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_122_and_123(const Spark_READ_PARAMETER_122_AND_123_t* values = nullptr) const;
    // Build and send Read Parameter 122 and 123: Read parameter 122 and 123 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_122_and_123(const Spark_READ_PARAMETER_122_AND_123_t& values) const { return send_read_parameter_122_and_123(&values); }
    // Build and send Read Parameter 124 and 125: Read parameter 124 and 125 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_124_and_125(const Spark_READ_PARAMETER_124_AND_125_t* values = nullptr) const;
    // Build and send Read Parameter 124 and 125: Read parameter 124 and 125 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_124_and_125(const Spark_READ_PARAMETER_124_AND_125_t& values) const { return send_read_parameter_124_and_125(&values); }
    // Build and send Read Parameter 126 and 127: Read parameter 126 and 127 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_126_and_127(const Spark_READ_PARAMETER_126_AND_127_t* values = nullptr) const;
    // Build and send Read Parameter 126 and 127: Read parameter 126 and 127 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_126_and_127(const Spark_READ_PARAMETER_126_AND_127_t& values) const { return send_read_parameter_126_and_127(&values); }
    // Build and send Read Parameter 128 and 129: Read parameter 128 and 129 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_128_and_129(const Spark_READ_PARAMETER_128_AND_129_t* values = nullptr) const;
    // Build and send Read Parameter 128 and 129: Read parameter 128 and 129 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_128_and_129(const Spark_READ_PARAMETER_128_AND_129_t& values) const { return send_read_parameter_128_and_129(&values); }
    // Build and send Read Parameter 130 and 131: Read parameter 130 and 131 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_130_and_131(const Spark_READ_PARAMETER_130_AND_131_t* values = nullptr) const;
    // Build and send Read Parameter 130 and 131: Read parameter 130 and 131 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_130_and_131(const Spark_READ_PARAMETER_130_AND_131_t& values) const { return send_read_parameter_130_and_131(&values); }
    // Build and send Read Parameter 132 and 133: Read parameter 132 and 133 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_132_and_133(const Spark_READ_PARAMETER_132_AND_133_t* values = nullptr) const;
    // Build and send Read Parameter 132 and 133: Read parameter 132 and 133 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_132_and_133(const Spark_READ_PARAMETER_132_AND_133_t& values) const { return send_read_parameter_132_and_133(&values); }
    // Build and send Read Parameter 134 and 135: Read parameter 134 and 135 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_134_and_135(const Spark_READ_PARAMETER_134_AND_135_t* values = nullptr) const;
    // Build and send Read Parameter 134 and 135: Read parameter 134 and 135 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_134_and_135(const Spark_READ_PARAMETER_134_AND_135_t& values) const { return send_read_parameter_134_and_135(&values); }
    // Build and send Read Parameter 136 and 137: Read parameter 136 and 137 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_136_and_137(const Spark_READ_PARAMETER_136_AND_137_t* values = nullptr) const;
    // Build and send Read Parameter 136 and 137: Read parameter 136 and 137 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_136_and_137(const Spark_READ_PARAMETER_136_AND_137_t& values) const { return send_read_parameter_136_and_137(&values); }
    // Build and send Read Parameter 138 and 139: Read parameter 138 and 139 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_138_and_139(const Spark_READ_PARAMETER_138_AND_139_t* values = nullptr) const;
    // Build and send Read Parameter 138 and 139: Read parameter 138 and 139 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_138_and_139(const Spark_READ_PARAMETER_138_AND_139_t& values) const { return send_read_parameter_138_and_139(&values); }
    // Build and send Read Parameter 140 and 141: Read parameter 140 and 141 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_140_and_141(const Spark_READ_PARAMETER_140_AND_141_t* values = nullptr) const;
    // Build and send Read Parameter 140 and 141: Read parameter 140 and 141 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_140_and_141(const Spark_READ_PARAMETER_140_AND_141_t& values) const { return send_read_parameter_140_and_141(&values); }
    // Build and send Read Parameter 142 and 143: Read parameter 142 and 143 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_142_and_143(const Spark_READ_PARAMETER_142_AND_143_t* values = nullptr) const;
    // Build and send Read Parameter 142 and 143: Read parameter 142 and 143 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_142_and_143(const Spark_READ_PARAMETER_142_AND_143_t& values) const { return send_read_parameter_142_and_143(&values); }
    // Build and send Read Parameter 144 and 145: Read parameter 144 and 145 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_144_and_145(const Spark_READ_PARAMETER_144_AND_145_t* values = nullptr) const;
    // Build and send Read Parameter 144 and 145: Read parameter 144 and 145 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_144_and_145(const Spark_READ_PARAMETER_144_AND_145_t& values) const { return send_read_parameter_144_and_145(&values); }
    // Build and send Read Parameter 146 and 147: Read parameter 146 and 147 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_146_and_147(const Spark_READ_PARAMETER_146_AND_147_t* values = nullptr) const;
    // Build and send Read Parameter 146 and 147: Read parameter 146 and 147 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_146_and_147(const Spark_READ_PARAMETER_146_AND_147_t& values) const { return send_read_parameter_146_and_147(&values); }
    // Build and send Read Parameter 148 and 149: Read parameter 148 and 149 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_148_and_149(const Spark_READ_PARAMETER_148_AND_149_t* values = nullptr) const;
    // Build and send Read Parameter 148 and 149: Read parameter 148 and 149 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_148_and_149(const Spark_READ_PARAMETER_148_AND_149_t& values) const { return send_read_parameter_148_and_149(&values); }
    // Build and send Read Parameter 150 and 151: Read parameter 150 and 151 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_150_and_151(const Spark_READ_PARAMETER_150_AND_151_t* values = nullptr) const;
    // Build and send Read Parameter 150 and 151: Read parameter 150 and 151 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_150_and_151(const Spark_READ_PARAMETER_150_AND_151_t& values) const { return send_read_parameter_150_and_151(&values); }
    // Build and send Read Parameter 152 and 153: Read parameter 152 and 153 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_152_and_153(const Spark_READ_PARAMETER_152_AND_153_t* values = nullptr) const;
    // Build and send Read Parameter 152 and 153: Read parameter 152 and 153 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_152_and_153(const Spark_READ_PARAMETER_152_AND_153_t& values) const { return send_read_parameter_152_and_153(&values); }
    // Build and send Read Parameter 154 and 155: Read parameter 154 and 155 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_154_and_155(const Spark_READ_PARAMETER_154_AND_155_t* values = nullptr) const;
    // Build and send Read Parameter 154 and 155: Read parameter 154 and 155 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_154_and_155(const Spark_READ_PARAMETER_154_AND_155_t& values) const { return send_read_parameter_154_and_155(&values); }
    // Build and send Read Parameter 156 and 157: Read parameter 156 and 157 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_156_and_157(const Spark_READ_PARAMETER_156_AND_157_t* values = nullptr) const;
    // Build and send Read Parameter 156 and 157: Read parameter 156 and 157 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_156_and_157(const Spark_READ_PARAMETER_156_AND_157_t& values) const { return send_read_parameter_156_and_157(&values); }
    // Build and send Read Parameter 158 and 159: Read parameter 158 and 159 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_158_and_159(const Spark_READ_PARAMETER_158_AND_159_t* values = nullptr) const;
    // Build and send Read Parameter 158 and 159: Read parameter 158 and 159 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_158_and_159(const Spark_READ_PARAMETER_158_AND_159_t& values) const { return send_read_parameter_158_and_159(&values); }
    // Build and send Read Parameter 160 and 161: Read parameter 160 and 161 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_160_and_161(const Spark_READ_PARAMETER_160_AND_161_t* values = nullptr) const;
    // Build and send Read Parameter 160 and 161: Read parameter 160 and 161 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_160_and_161(const Spark_READ_PARAMETER_160_AND_161_t& values) const { return send_read_parameter_160_and_161(&values); }
    // Build and send Read Parameter 162 and 163: Read parameter 162 and 163 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_162_and_163(const Spark_READ_PARAMETER_162_AND_163_t* values = nullptr) const;
    // Build and send Read Parameter 162 and 163: Read parameter 162 and 163 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_162_and_163(const Spark_READ_PARAMETER_162_AND_163_t& values) const { return send_read_parameter_162_and_163(&values); }
    // Build and send Read Parameter 164 and 165: Read parameter 164 and 165 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_164_and_165(const Spark_READ_PARAMETER_164_AND_165_t* values = nullptr) const;
    // Build and send Read Parameter 164 and 165: Read parameter 164 and 165 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_164_and_165(const Spark_READ_PARAMETER_164_AND_165_t& values) const { return send_read_parameter_164_and_165(&values); }
    // Build and send Read Parameter 166 and 167: Read parameter 166 and 167 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_166_and_167(const Spark_READ_PARAMETER_166_AND_167_t* values = nullptr) const;
    // Build and send Read Parameter 166 and 167: Read parameter 166 and 167 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_166_and_167(const Spark_READ_PARAMETER_166_AND_167_t& values) const { return send_read_parameter_166_and_167(&values); }
    // Build and send Read Parameter 168 and 169: Read parameter 168 and 169 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_168_and_169(const Spark_READ_PARAMETER_168_AND_169_t* values = nullptr) const;
    // Build and send Read Parameter 168 and 169: Read parameter 168 and 169 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_168_and_169(const Spark_READ_PARAMETER_168_AND_169_t& values) const { return send_read_parameter_168_and_169(&values); }
    // Build and send Read Parameter 170 and 171: Read parameter 170 and 171 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_170_and_171(const Spark_READ_PARAMETER_170_AND_171_t* values = nullptr) const;
    // Build and send Read Parameter 170 and 171: Read parameter 170 and 171 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_170_and_171(const Spark_READ_PARAMETER_170_AND_171_t& values) const { return send_read_parameter_170_and_171(&values); }
    // Build and send Read Parameter 172 and 173: Read parameter 172 and 173 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_172_and_173(const Spark_READ_PARAMETER_172_AND_173_t* values = nullptr) const;
    // Build and send Read Parameter 172 and 173: Read parameter 172 and 173 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_172_and_173(const Spark_READ_PARAMETER_172_AND_173_t& values) const { return send_read_parameter_172_and_173(&values); }
    // Build and send Read Parameter 174 and 175: Read parameter 174 and 175 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_174_and_175(const Spark_READ_PARAMETER_174_AND_175_t* values = nullptr) const;
    // Build and send Read Parameter 174 and 175: Read parameter 174 and 175 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_174_and_175(const Spark_READ_PARAMETER_174_AND_175_t& values) const { return send_read_parameter_174_and_175(&values); }
    // Build and send Read Parameter 176 and 177: Read parameter 176 and 177 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_176_and_177(const Spark_READ_PARAMETER_176_AND_177_t* values = nullptr) const;
    // Build and send Read Parameter 176 and 177: Read parameter 176 and 177 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_176_and_177(const Spark_READ_PARAMETER_176_AND_177_t& values) const { return send_read_parameter_176_and_177(&values); }
    // Build and send Read Parameter 178 and 179: Read parameter 178 and 179 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_178_and_179(const Spark_READ_PARAMETER_178_AND_179_t* values = nullptr) const;
    // Build and send Read Parameter 178 and 179: Read parameter 178 and 179 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_178_and_179(const Spark_READ_PARAMETER_178_AND_179_t& values) const { return send_read_parameter_178_and_179(&values); }
    // Build and send Read Parameter 180 and 181: Read parameter 180 and 181 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_180_and_181(const Spark_READ_PARAMETER_180_AND_181_t* values = nullptr) const;
    // Build and send Read Parameter 180 and 181: Read parameter 180 and 181 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_180_and_181(const Spark_READ_PARAMETER_180_AND_181_t& values) const { return send_read_parameter_180_and_181(&values); }
    // Build and send Read Parameter 182 and 183: Read parameter 182 and 183 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_182_and_183(const Spark_READ_PARAMETER_182_AND_183_t* values = nullptr) const;
    // Build and send Read Parameter 182 and 183: Read parameter 182 and 183 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_182_and_183(const Spark_READ_PARAMETER_182_AND_183_t& values) const { return send_read_parameter_182_and_183(&values); }
    // Build and send Read Parameter 184 and 185: Read parameter 184 and 185 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_184_and_185(const Spark_READ_PARAMETER_184_AND_185_t* values = nullptr) const;
    // Build and send Read Parameter 184 and 185: Read parameter 184 and 185 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_184_and_185(const Spark_READ_PARAMETER_184_AND_185_t& values) const { return send_read_parameter_184_and_185(&values); }
    // Build and send Read Parameter 186 and 187: Read parameter 186 and 187 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_186_and_187(const Spark_READ_PARAMETER_186_AND_187_t* values = nullptr) const;
    // Build and send Read Parameter 186 and 187: Read parameter 186 and 187 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_186_and_187(const Spark_READ_PARAMETER_186_AND_187_t& values) const { return send_read_parameter_186_and_187(&values); }
    // Build and send Read Parameter 188 and 189: Read parameter 188 and 189 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_188_and_189(const Spark_READ_PARAMETER_188_AND_189_t* values = nullptr) const;
    // Build and send Read Parameter 188 and 189: Read parameter 188 and 189 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_188_and_189(const Spark_READ_PARAMETER_188_AND_189_t& values) const { return send_read_parameter_188_and_189(&values); }
    // Build and send Read Parameter 190 and 191: Read parameter 190 and 191 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_190_and_191(const Spark_READ_PARAMETER_190_AND_191_t* values = nullptr) const;
    // Build and send Read Parameter 190 and 191: Read parameter 190 and 191 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_190_and_191(const Spark_READ_PARAMETER_190_AND_191_t& values) const { return send_read_parameter_190_and_191(&values); }
    // Build and send Read Parameter 192 and 193: Read parameter 192 and 193 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_192_and_193(const Spark_READ_PARAMETER_192_AND_193_t* values = nullptr) const;
    // Build and send Read Parameter 192 and 193: Read parameter 192 and 193 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_192_and_193(const Spark_READ_PARAMETER_192_AND_193_t& values) const { return send_read_parameter_192_and_193(&values); }
    // Build and send Read Parameter 194 and 195: Read parameter 194 and 195 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_194_and_195(const Spark_READ_PARAMETER_194_AND_195_t* values = nullptr) const;
    // Build and send Read Parameter 194 and 195: Read parameter 194 and 195 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_194_and_195(const Spark_READ_PARAMETER_194_AND_195_t& values) const { return send_read_parameter_194_and_195(&values); }
    // Build and send Read Parameter 196 and 197: Read parameter 196 and 197 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_196_and_197(const Spark_READ_PARAMETER_196_AND_197_t* values = nullptr) const;
    // Build and send Read Parameter 196 and 197: Read parameter 196 and 197 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_196_and_197(const Spark_READ_PARAMETER_196_AND_197_t& values) const { return send_read_parameter_196_and_197(&values); }
    // Build and send Read Parameter 198 and 199: Read parameter 198 and 199 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_198_and_199(const Spark_READ_PARAMETER_198_AND_199_t* values = nullptr) const;
    // Build and send Read Parameter 198 and 199: Read parameter 198 and 199 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_198_and_199(const Spark_READ_PARAMETER_198_AND_199_t& values) const { return send_read_parameter_198_and_199(&values); }
    // Build and send Read Parameter 200 and 201: Read parameter 200 and 201 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_200_and_201(const Spark_READ_PARAMETER_200_AND_201_t* values = nullptr) const;
    // Build and send Read Parameter 200 and 201: Read parameter 200 and 201 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_200_and_201(const Spark_READ_PARAMETER_200_AND_201_t& values) const { return send_read_parameter_200_and_201(&values); }
    // Build and send Read Parameter 202 and 203: Read parameter 202 and 203 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_202_and_203(const Spark_READ_PARAMETER_202_AND_203_t* values = nullptr) const;
    // Build and send Read Parameter 202 and 203: Read parameter 202 and 203 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_202_and_203(const Spark_READ_PARAMETER_202_AND_203_t& values) const { return send_read_parameter_202_and_203(&values); }
    // Build and send Read Parameter 204 and 205: Read parameter 204 and 205 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_204_and_205(const Spark_READ_PARAMETER_204_AND_205_t* values = nullptr) const;
    // Build and send Read Parameter 204 and 205: Read parameter 204 and 205 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_204_and_205(const Spark_READ_PARAMETER_204_AND_205_t& values) const { return send_read_parameter_204_and_205(&values); }
    // Build and send Read Parameter 206 and 207: Read parameter 206 and 207 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_206_and_207(const Spark_READ_PARAMETER_206_AND_207_t* values = nullptr) const;
    // Build and send Read Parameter 206 and 207: Read parameter 206 and 207 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_206_and_207(const Spark_READ_PARAMETER_206_AND_207_t& values) const { return send_read_parameter_206_and_207(&values); }
    // Build and send Read Parameter 208 and 209: Read parameter 208 and 209 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_208_and_209(const Spark_READ_PARAMETER_208_AND_209_t* values = nullptr) const;
    // Build and send Read Parameter 208 and 209: Read parameter 208 and 209 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_208_and_209(const Spark_READ_PARAMETER_208_AND_209_t& values) const { return send_read_parameter_208_and_209(&values); }
    // Build and send Read Parameter 210 and 211: Read parameter 210 and 211 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_210_and_211(const Spark_READ_PARAMETER_210_AND_211_t* values = nullptr) const;
    // Build and send Read Parameter 210 and 211: Read parameter 210 and 211 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_210_and_211(const Spark_READ_PARAMETER_210_AND_211_t& values) const { return send_read_parameter_210_and_211(&values); }
    // Build and send Read Parameter 212 and 213: Read parameter 212 and 213 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_212_and_213(const Spark_READ_PARAMETER_212_AND_213_t* values = nullptr) const;
    // Build and send Read Parameter 212 and 213: Read parameter 212 and 213 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_212_and_213(const Spark_READ_PARAMETER_212_AND_213_t& values) const { return send_read_parameter_212_and_213(&values); }
    // Build and send Read Parameter 214 and 215: Read parameter 214 and 215 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_214_and_215(const Spark_READ_PARAMETER_214_AND_215_t* values = nullptr) const;
    // Build and send Read Parameter 214 and 215: Read parameter 214 and 215 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_214_and_215(const Spark_READ_PARAMETER_214_AND_215_t& values) const { return send_read_parameter_214_and_215(&values); }
    // Build and send Read Parameter 216 and 217: Read parameter 216 and 217 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_216_and_217(const Spark_READ_PARAMETER_216_AND_217_t* values = nullptr) const;
    // Build and send Read Parameter 216 and 217: Read parameter 216 and 217 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_216_and_217(const Spark_READ_PARAMETER_216_AND_217_t& values) const { return send_read_parameter_216_and_217(&values); }
    // Build and send Read Parameter 218 and 219: Read parameter 218 and 219 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_218_and_219(const Spark_READ_PARAMETER_218_AND_219_t* values = nullptr) const;
    // Build and send Read Parameter 218 and 219: Read parameter 218 and 219 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_218_and_219(const Spark_READ_PARAMETER_218_AND_219_t& values) const { return send_read_parameter_218_and_219(&values); }
    // Build and send Read Parameter 220 and 221: Read parameter 220 and 221 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_220_and_221(const Spark_READ_PARAMETER_220_AND_221_t* values = nullptr) const;
    // Build and send Read Parameter 220 and 221: Read parameter 220 and 221 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_220_and_221(const Spark_READ_PARAMETER_220_AND_221_t& values) const { return send_read_parameter_220_and_221(&values); }
    // Build and send Read Parameter 222 and 223: Read parameter 222 and 223 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_222_and_223(const Spark_READ_PARAMETER_222_AND_223_t* values = nullptr) const;
    // Build and send Read Parameter 222 and 223: Read parameter 222 and 223 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_222_and_223(const Spark_READ_PARAMETER_222_AND_223_t& values) const { return send_read_parameter_222_and_223(&values); }
    // Build and send Read Parameter 224 and 225: Read parameter 224 and 225 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_224_and_225(const Spark_READ_PARAMETER_224_AND_225_t* values = nullptr) const;
    // Build and send Read Parameter 224 and 225: Read parameter 224 and 225 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_224_and_225(const Spark_READ_PARAMETER_224_AND_225_t& values) const { return send_read_parameter_224_and_225(&values); }
    // Build and send Read Parameter 226 and 227: Read parameter 226 and 227 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_226_and_227(const Spark_READ_PARAMETER_226_AND_227_t* values = nullptr) const;
    // Build and send Read Parameter 226 and 227: Read parameter 226 and 227 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_226_and_227(const Spark_READ_PARAMETER_226_AND_227_t& values) const { return send_read_parameter_226_and_227(&values); }
    // Build and send Read Parameter 228 and 229: Read parameter 228 and 229 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_228_and_229(const Spark_READ_PARAMETER_228_AND_229_t* values = nullptr) const;
    // Build and send Read Parameter 228 and 229: Read parameter 228 and 229 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_228_and_229(const Spark_READ_PARAMETER_228_AND_229_t& values) const { return send_read_parameter_228_and_229(&values); }
    // Build and send Read Parameter 230 and 231: Read parameter 230 and 231 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_230_and_231(const Spark_READ_PARAMETER_230_AND_231_t* values = nullptr) const;
    // Build and send Read Parameter 230 and 231: Read parameter 230 and 231 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_230_and_231(const Spark_READ_PARAMETER_230_AND_231_t& values) const { return send_read_parameter_230_and_231(&values); }
    // Build and send Read Parameter 232 and 233: Read parameter 232 and 233 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_232_and_233(const Spark_READ_PARAMETER_232_AND_233_t* values = nullptr) const;
    // Build and send Read Parameter 232 and 233: Read parameter 232 and 233 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_232_and_233(const Spark_READ_PARAMETER_232_AND_233_t& values) const { return send_read_parameter_232_and_233(&values); }
    // Build and send Read Parameter 234 and 235: Read parameter 234 and 235 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_234_and_235(const Spark_READ_PARAMETER_234_AND_235_t* values = nullptr) const;
    // Build and send Read Parameter 234 and 235: Read parameter 234 and 235 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_234_and_235(const Spark_READ_PARAMETER_234_AND_235_t& values) const { return send_read_parameter_234_and_235(&values); }
    // Build and send Read Parameter 236 and 237: Read parameter 236 and 237 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_236_and_237(const Spark_READ_PARAMETER_236_AND_237_t* values = nullptr) const;
    // Build and send Read Parameter 236 and 237: Read parameter 236 and 237 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_236_and_237(const Spark_READ_PARAMETER_236_AND_237_t& values) const { return send_read_parameter_236_and_237(&values); }
    // Build and send Read Parameter 238 and 239: Read parameter 238 and 239 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_238_and_239(const Spark_READ_PARAMETER_238_AND_239_t* values = nullptr) const;
    // Build and send Read Parameter 238 and 239: Read parameter 238 and 239 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_238_and_239(const Spark_READ_PARAMETER_238_AND_239_t& values) const { return send_read_parameter_238_and_239(&values); }
    // Build and send Read Parameter 240 and 241: Read parameter 240 and 241 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_240_and_241(const Spark_READ_PARAMETER_240_AND_241_t* values = nullptr) const;
    // Build and send Read Parameter 240 and 241: Read parameter 240 and 241 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_240_and_241(const Spark_READ_PARAMETER_240_AND_241_t& values) const { return send_read_parameter_240_and_241(&values); }
    // Build and send Read Parameter 242 and 243: Read parameter 242 and 243 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_242_and_243(const Spark_READ_PARAMETER_242_AND_243_t* values = nullptr) const;
    // Build and send Read Parameter 242 and 243: Read parameter 242 and 243 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_242_and_243(const Spark_READ_PARAMETER_242_AND_243_t& values) const { return send_read_parameter_242_and_243(&values); }
    // Build and send Read Parameter 244 and 245: Read parameter 244 and 245 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_244_and_245(const Spark_READ_PARAMETER_244_AND_245_t* values = nullptr) const;
    // Build and send Read Parameter 244 and 245: Read parameter 244 and 245 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_244_and_245(const Spark_READ_PARAMETER_244_AND_245_t& values) const { return send_read_parameter_244_and_245(&values); }
    // Build and send Read Parameter 246 and 247: Read parameter 246 and 247 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_246_and_247(const Spark_READ_PARAMETER_246_AND_247_t* values = nullptr) const;
    // Build and send Read Parameter 246 and 247: Read parameter 246 and 247 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_246_and_247(const Spark_READ_PARAMETER_246_AND_247_t& values) const { return send_read_parameter_246_and_247(&values); }
    // Build and send Read Parameter 248 and 249: Read parameter 248 and 249 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_248_and_249(const Spark_READ_PARAMETER_248_AND_249_t* values = nullptr) const;
    // Build and send Read Parameter 248 and 249: Read parameter 248 and 249 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_248_and_249(const Spark_READ_PARAMETER_248_AND_249_t& values) const { return send_read_parameter_248_and_249(&values); }
    // Build and send Read Parameter 250 and 251: Read parameter 250 and 251 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_250_and_251(const Spark_READ_PARAMETER_250_AND_251_t* values = nullptr) const;
    // Build and send Read Parameter 250 and 251: Read parameter 250 and 251 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_250_and_251(const Spark_READ_PARAMETER_250_AND_251_t& values) const { return send_read_parameter_250_and_251(&values); }
    // Build and send Read Parameter 252 and 253: Read parameter 252 and 253 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_252_and_253(const Spark_READ_PARAMETER_252_AND_253_t* values = nullptr) const;
    // Build and send Read Parameter 252 and 253: Read parameter 252 and 253 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_252_and_253(const Spark_READ_PARAMETER_252_AND_253_t& values) const { return send_read_parameter_252_and_253(&values); }
    // Build and send Read Parameter 254 and 255: Read parameter 254 and 255 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (pointer overload)
    MCP2515::ERROR send_read_parameter_254_and_255(const Spark_READ_PARAMETER_254_AND_255_t* values = nullptr) const;
    // Build and send Read Parameter 254 and 255: Read parameter 254 and 255 at the same time. SPARK MAX does not currently support this in v25.0.0-prerelease.4 (by-value overload)
    MCP2515::ERROR send_read_parameter_254_and_255(const Spark_READ_PARAMETER_254_AND_255_t& values) const { return send_read_parameter_254_and_255(&values); }
    // Build and send Write Parameter 0 and 1: Write Parameter 0 and 1 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_0_and_1(const Spark_WRITE_PARAMETER_0_AND_1_t* values = nullptr) const;
    // Build and send Write Parameter 0 and 1: Write Parameter 0 and 1 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_0_and_1(const Spark_WRITE_PARAMETER_0_AND_1_t& values) const { return send_write_parameter_0_and_1(&values); }
    // Build and send Write Parameter 2 and 3: Write Parameter 2 and 3 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_2_and_3(const Spark_WRITE_PARAMETER_2_AND_3_t* values = nullptr) const;
    // Build and send Write Parameter 2 and 3: Write Parameter 2 and 3 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_2_and_3(const Spark_WRITE_PARAMETER_2_AND_3_t& values) const { return send_write_parameter_2_and_3(&values); }
    // Build and send Write Parameter 4 and 5: Write Parameter 4 and 5 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_4_and_5(const Spark_WRITE_PARAMETER_4_AND_5_t* values = nullptr) const;
    // Build and send Write Parameter 4 and 5: Write Parameter 4 and 5 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_4_and_5(const Spark_WRITE_PARAMETER_4_AND_5_t& values) const { return send_write_parameter_4_and_5(&values); }
    // Build and send Write Parameter 6 and 7: Write Parameter 6 and 7 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_6_and_7(const Spark_WRITE_PARAMETER_6_AND_7_t* values = nullptr) const;
    // Build and send Write Parameter 6 and 7: Write Parameter 6 and 7 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_6_and_7(const Spark_WRITE_PARAMETER_6_AND_7_t& values) const { return send_write_parameter_6_and_7(&values); }
    // Build and send Write Parameter 8 and 9: Write Parameter 8 and 9 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_8_and_9(const Spark_WRITE_PARAMETER_8_AND_9_t* values = nullptr) const;
    // Build and send Write Parameter 8 and 9: Write Parameter 8 and 9 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_8_and_9(const Spark_WRITE_PARAMETER_8_AND_9_t& values) const { return send_write_parameter_8_and_9(&values); }
    // Build and send Write Parameter 10 and 11: Write Parameter 10 and 11 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_10_and_11(const Spark_WRITE_PARAMETER_10_AND_11_t* values = nullptr) const;
    // Build and send Write Parameter 10 and 11: Write Parameter 10 and 11 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_10_and_11(const Spark_WRITE_PARAMETER_10_AND_11_t& values) const { return send_write_parameter_10_and_11(&values); }
    // Build and send Write Parameter 12 and 13: Write Parameter 12 and 13 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_12_and_13(const Spark_WRITE_PARAMETER_12_AND_13_t* values = nullptr) const;
    // Build and send Write Parameter 12 and 13: Write Parameter 12 and 13 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_12_and_13(const Spark_WRITE_PARAMETER_12_AND_13_t& values) const { return send_write_parameter_12_and_13(&values); }
    // Build and send Write Parameter 14 and 15: Write Parameter 14 and 15 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_14_and_15(const Spark_WRITE_PARAMETER_14_AND_15_t* values = nullptr) const;
    // Build and send Write Parameter 14 and 15: Write Parameter 14 and 15 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_14_and_15(const Spark_WRITE_PARAMETER_14_AND_15_t& values) const { return send_write_parameter_14_and_15(&values); }
    // Build and send Write Parameter 16 and 17: Write Parameter 16 and 17 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_16_and_17(const Spark_WRITE_PARAMETER_16_AND_17_t* values = nullptr) const;
    // Build and send Write Parameter 16 and 17: Write Parameter 16 and 17 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_16_and_17(const Spark_WRITE_PARAMETER_16_AND_17_t& values) const { return send_write_parameter_16_and_17(&values); }
    // Build and send Write Parameter 18 and 19: Write Parameter 18 and 19 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_18_and_19(const Spark_WRITE_PARAMETER_18_AND_19_t* values = nullptr) const;
    // Build and send Write Parameter 18 and 19: Write Parameter 18 and 19 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_18_and_19(const Spark_WRITE_PARAMETER_18_AND_19_t& values) const { return send_write_parameter_18_and_19(&values); }
    // Build and send Write Parameter 20 and 21: Write Parameter 20 and 21 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_20_and_21(const Spark_WRITE_PARAMETER_20_AND_21_t* values = nullptr) const;
    // Build and send Write Parameter 20 and 21: Write Parameter 20 and 21 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_20_and_21(const Spark_WRITE_PARAMETER_20_AND_21_t& values) const { return send_write_parameter_20_and_21(&values); }
    // Build and send Write Parameter 22 and 23: Write Parameter 22 and 23 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_22_and_23(const Spark_WRITE_PARAMETER_22_AND_23_t* values = nullptr) const;
    // Build and send Write Parameter 22 and 23: Write Parameter 22 and 23 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_22_and_23(const Spark_WRITE_PARAMETER_22_AND_23_t& values) const { return send_write_parameter_22_and_23(&values); }
    // Build and send Write Parameter 24 and 25: Write Parameter 24 and 25 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_24_and_25(const Spark_WRITE_PARAMETER_24_AND_25_t* values = nullptr) const;
    // Build and send Write Parameter 24 and 25: Write Parameter 24 and 25 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_24_and_25(const Spark_WRITE_PARAMETER_24_AND_25_t& values) const { return send_write_parameter_24_and_25(&values); }
    // Build and send Write Parameter 26 and 27: Write Parameter 26 and 27 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_26_and_27(const Spark_WRITE_PARAMETER_26_AND_27_t* values = nullptr) const;
    // Build and send Write Parameter 26 and 27: Write Parameter 26 and 27 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_26_and_27(const Spark_WRITE_PARAMETER_26_AND_27_t& values) const { return send_write_parameter_26_and_27(&values); }
    // Build and send Write Parameter 28 and 29: Write Parameter 28 and 29 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_28_and_29(const Spark_WRITE_PARAMETER_28_AND_29_t* values = nullptr) const;
    // Build and send Write Parameter 28 and 29: Write Parameter 28 and 29 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_28_and_29(const Spark_WRITE_PARAMETER_28_AND_29_t& values) const { return send_write_parameter_28_and_29(&values); }
    // Build and send Write Parameter 30 and 31: Write Parameter 30 and 31 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_30_and_31(const Spark_WRITE_PARAMETER_30_AND_31_t* values = nullptr) const;
    // Build and send Write Parameter 30 and 31: Write Parameter 30 and 31 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_30_and_31(const Spark_WRITE_PARAMETER_30_AND_31_t& values) const { return send_write_parameter_30_and_31(&values); }
    // Build and send Write Parameter 32 and 33: Write Parameter 32 and 33 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_32_and_33(const Spark_WRITE_PARAMETER_32_AND_33_t* values = nullptr) const;
    // Build and send Write Parameter 32 and 33: Write Parameter 32 and 33 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_32_and_33(const Spark_WRITE_PARAMETER_32_AND_33_t& values) const { return send_write_parameter_32_and_33(&values); }
    // Build and send Write Parameter 34 and 35: Write Parameter 34 and 35 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_34_and_35(const Spark_WRITE_PARAMETER_34_AND_35_t* values = nullptr) const;
    // Build and send Write Parameter 34 and 35: Write Parameter 34 and 35 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_34_and_35(const Spark_WRITE_PARAMETER_34_AND_35_t& values) const { return send_write_parameter_34_and_35(&values); }
    // Build and send Write Parameter 36 and 37: Write Parameter 36 and 37 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_36_and_37(const Spark_WRITE_PARAMETER_36_AND_37_t* values = nullptr) const;
    // Build and send Write Parameter 36 and 37: Write Parameter 36 and 37 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_36_and_37(const Spark_WRITE_PARAMETER_36_AND_37_t& values) const { return send_write_parameter_36_and_37(&values); }
    // Build and send Write Parameter 38 and 39: Write Parameter 38 and 39 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_38_and_39(const Spark_WRITE_PARAMETER_38_AND_39_t* values = nullptr) const;
    // Build and send Write Parameter 38 and 39: Write Parameter 38 and 39 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_38_and_39(const Spark_WRITE_PARAMETER_38_AND_39_t& values) const { return send_write_parameter_38_and_39(&values); }
    // Build and send Write Parameter 40 and 41: Write Parameter 40 and 41 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_40_and_41(const Spark_WRITE_PARAMETER_40_AND_41_t* values = nullptr) const;
    // Build and send Write Parameter 40 and 41: Write Parameter 40 and 41 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_40_and_41(const Spark_WRITE_PARAMETER_40_AND_41_t& values) const { return send_write_parameter_40_and_41(&values); }
    // Build and send Write Parameter 42 and 43: Write Parameter 42 and 43 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_42_and_43(const Spark_WRITE_PARAMETER_42_AND_43_t* values = nullptr) const;
    // Build and send Write Parameter 42 and 43: Write Parameter 42 and 43 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_42_and_43(const Spark_WRITE_PARAMETER_42_AND_43_t& values) const { return send_write_parameter_42_and_43(&values); }
    // Build and send Write Parameter 44 and 45: Write Parameter 44 and 45 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_44_and_45(const Spark_WRITE_PARAMETER_44_AND_45_t* values = nullptr) const;
    // Build and send Write Parameter 44 and 45: Write Parameter 44 and 45 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_44_and_45(const Spark_WRITE_PARAMETER_44_AND_45_t& values) const { return send_write_parameter_44_and_45(&values); }
    // Build and send Write Parameter 46 and 47: Write Parameter 46 and 47 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_46_and_47(const Spark_WRITE_PARAMETER_46_AND_47_t* values = nullptr) const;
    // Build and send Write Parameter 46 and 47: Write Parameter 46 and 47 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_46_and_47(const Spark_WRITE_PARAMETER_46_AND_47_t& values) const { return send_write_parameter_46_and_47(&values); }
    // Build and send Write Parameter 48 and 49: Write Parameter 48 and 49 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_48_and_49(const Spark_WRITE_PARAMETER_48_AND_49_t* values = nullptr) const;
    // Build and send Write Parameter 48 and 49: Write Parameter 48 and 49 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_48_and_49(const Spark_WRITE_PARAMETER_48_AND_49_t& values) const { return send_write_parameter_48_and_49(&values); }
    // Build and send Write Parameter 50 and 51: Write Parameter 50 and 51 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_50_and_51(const Spark_WRITE_PARAMETER_50_AND_51_t* values = nullptr) const;
    // Build and send Write Parameter 50 and 51: Write Parameter 50 and 51 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_50_and_51(const Spark_WRITE_PARAMETER_50_AND_51_t& values) const { return send_write_parameter_50_and_51(&values); }
    // Build and send Write Parameter 52 and 53: Write Parameter 52 and 53 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_52_and_53(const Spark_WRITE_PARAMETER_52_AND_53_t* values = nullptr) const;
    // Build and send Write Parameter 52 and 53: Write Parameter 52 and 53 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_52_and_53(const Spark_WRITE_PARAMETER_52_AND_53_t& values) const { return send_write_parameter_52_and_53(&values); }
    // Build and send Write Parameter 54 and 55: Write Parameter 54 and 55 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_54_and_55(const Spark_WRITE_PARAMETER_54_AND_55_t* values = nullptr) const;
    // Build and send Write Parameter 54 and 55: Write Parameter 54 and 55 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_54_and_55(const Spark_WRITE_PARAMETER_54_AND_55_t& values) const { return send_write_parameter_54_and_55(&values); }
    // Build and send Write Parameter 56 and 57: Write Parameter 56 and 57 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_56_and_57(const Spark_WRITE_PARAMETER_56_AND_57_t* values = nullptr) const;
    // Build and send Write Parameter 56 and 57: Write Parameter 56 and 57 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_56_and_57(const Spark_WRITE_PARAMETER_56_AND_57_t& values) const { return send_write_parameter_56_and_57(&values); }
    // Build and send Write Parameter 58 and 59: Write Parameter 58 and 59 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_58_and_59(const Spark_WRITE_PARAMETER_58_AND_59_t* values = nullptr) const;
    // Build and send Write Parameter 58 and 59: Write Parameter 58 and 59 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_58_and_59(const Spark_WRITE_PARAMETER_58_AND_59_t& values) const { return send_write_parameter_58_and_59(&values); }
    // Build and send Write Parameter 60 and 61: Write Parameter 60 and 61 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_60_and_61(const Spark_WRITE_PARAMETER_60_AND_61_t* values = nullptr) const;
    // Build and send Write Parameter 60 and 61: Write Parameter 60 and 61 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_60_and_61(const Spark_WRITE_PARAMETER_60_AND_61_t& values) const { return send_write_parameter_60_and_61(&values); }
    // Build and send Write Parameter 62 and 63: Write Parameter 62 and 63 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_62_and_63(const Spark_WRITE_PARAMETER_62_AND_63_t* values = nullptr) const;
    // Build and send Write Parameter 62 and 63: Write Parameter 62 and 63 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_62_and_63(const Spark_WRITE_PARAMETER_62_AND_63_t& values) const { return send_write_parameter_62_and_63(&values); }
    // Build and send Write Parameter 64 and 65: Write Parameter 64 and 65 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_64_and_65(const Spark_WRITE_PARAMETER_64_AND_65_t* values = nullptr) const;
    // Build and send Write Parameter 64 and 65: Write Parameter 64 and 65 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_64_and_65(const Spark_WRITE_PARAMETER_64_AND_65_t& values) const { return send_write_parameter_64_and_65(&values); }
    // Build and send Write Parameter 66 and 67: Write Parameter 66 and 67 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_66_and_67(const Spark_WRITE_PARAMETER_66_AND_67_t* values = nullptr) const;
    // Build and send Write Parameter 66 and 67: Write Parameter 66 and 67 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_66_and_67(const Spark_WRITE_PARAMETER_66_AND_67_t& values) const { return send_write_parameter_66_and_67(&values); }
    // Build and send Write Parameter 68 and 69: Write Parameter 68 and 69 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_68_and_69(const Spark_WRITE_PARAMETER_68_AND_69_t* values = nullptr) const;
    // Build and send Write Parameter 68 and 69: Write Parameter 68 and 69 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_68_and_69(const Spark_WRITE_PARAMETER_68_AND_69_t& values) const { return send_write_parameter_68_and_69(&values); }
    // Build and send Write Parameter 70 and 71: Write Parameter 70 and 71 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_70_and_71(const Spark_WRITE_PARAMETER_70_AND_71_t* values = nullptr) const;
    // Build and send Write Parameter 70 and 71: Write Parameter 70 and 71 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_70_and_71(const Spark_WRITE_PARAMETER_70_AND_71_t& values) const { return send_write_parameter_70_and_71(&values); }
    // Build and send Write Parameter 72 and 73: Write Parameter 72 and 73 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_72_and_73(const Spark_WRITE_PARAMETER_72_AND_73_t* values = nullptr) const;
    // Build and send Write Parameter 72 and 73: Write Parameter 72 and 73 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_72_and_73(const Spark_WRITE_PARAMETER_72_AND_73_t& values) const { return send_write_parameter_72_and_73(&values); }
    // Build and send Write Parameter 74 and 75: Write Parameter 74 and 75 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_74_and_75(const Spark_WRITE_PARAMETER_74_AND_75_t* values = nullptr) const;
    // Build and send Write Parameter 74 and 75: Write Parameter 74 and 75 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_74_and_75(const Spark_WRITE_PARAMETER_74_AND_75_t& values) const { return send_write_parameter_74_and_75(&values); }
    // Build and send Write Parameter 76 and 77: Write Parameter 76 and 77 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_76_and_77(const Spark_WRITE_PARAMETER_76_AND_77_t* values = nullptr) const;
    // Build and send Write Parameter 76 and 77: Write Parameter 76 and 77 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_76_and_77(const Spark_WRITE_PARAMETER_76_AND_77_t& values) const { return send_write_parameter_76_and_77(&values); }
    // Build and send Write Parameter 78 and 79: Write Parameter 78 and 79 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_78_and_79(const Spark_WRITE_PARAMETER_78_AND_79_t* values = nullptr) const;
    // Build and send Write Parameter 78 and 79: Write Parameter 78 and 79 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_78_and_79(const Spark_WRITE_PARAMETER_78_AND_79_t& values) const { return send_write_parameter_78_and_79(&values); }
    // Build and send Write Parameter 80 and 81: Write Parameter 80 and 81 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_80_and_81(const Spark_WRITE_PARAMETER_80_AND_81_t* values = nullptr) const;
    // Build and send Write Parameter 80 and 81: Write Parameter 80 and 81 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_80_and_81(const Spark_WRITE_PARAMETER_80_AND_81_t& values) const { return send_write_parameter_80_and_81(&values); }
    // Build and send Write Parameter 82 and 83: Write Parameter 82 and 83 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_82_and_83(const Spark_WRITE_PARAMETER_82_AND_83_t* values = nullptr) const;
    // Build and send Write Parameter 82 and 83: Write Parameter 82 and 83 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_82_and_83(const Spark_WRITE_PARAMETER_82_AND_83_t& values) const { return send_write_parameter_82_and_83(&values); }
    // Build and send Write Parameter 84 and 85: Write Parameter 84 and 85 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_84_and_85(const Spark_WRITE_PARAMETER_84_AND_85_t* values = nullptr) const;
    // Build and send Write Parameter 84 and 85: Write Parameter 84 and 85 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_84_and_85(const Spark_WRITE_PARAMETER_84_AND_85_t& values) const { return send_write_parameter_84_and_85(&values); }
    // Build and send Write Parameter 86 and 87: Write Parameter 86 and 87 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_86_and_87(const Spark_WRITE_PARAMETER_86_AND_87_t* values = nullptr) const;
    // Build and send Write Parameter 86 and 87: Write Parameter 86 and 87 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_86_and_87(const Spark_WRITE_PARAMETER_86_AND_87_t& values) const { return send_write_parameter_86_and_87(&values); }
    // Build and send Write Parameter 88 and 89: Write Parameter 88 and 89 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_88_and_89(const Spark_WRITE_PARAMETER_88_AND_89_t* values = nullptr) const;
    // Build and send Write Parameter 88 and 89: Write Parameter 88 and 89 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_88_and_89(const Spark_WRITE_PARAMETER_88_AND_89_t& values) const { return send_write_parameter_88_and_89(&values); }
    // Build and send Write Parameter 90 and 91: Write Parameter 90 and 91 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_90_and_91(const Spark_WRITE_PARAMETER_90_AND_91_t* values = nullptr) const;
    // Build and send Write Parameter 90 and 91: Write Parameter 90 and 91 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_90_and_91(const Spark_WRITE_PARAMETER_90_AND_91_t& values) const { return send_write_parameter_90_and_91(&values); }
    // Build and send Write Parameter 92 and 93: Write Parameter 92 and 93 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_92_and_93(const Spark_WRITE_PARAMETER_92_AND_93_t* values = nullptr) const;
    // Build and send Write Parameter 92 and 93: Write Parameter 92 and 93 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_92_and_93(const Spark_WRITE_PARAMETER_92_AND_93_t& values) const { return send_write_parameter_92_and_93(&values); }
    // Build and send Write Parameter 94 and 95: Write Parameter 94 and 95 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_94_and_95(const Spark_WRITE_PARAMETER_94_AND_95_t* values = nullptr) const;
    // Build and send Write Parameter 94 and 95: Write Parameter 94 and 95 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_94_and_95(const Spark_WRITE_PARAMETER_94_AND_95_t& values) const { return send_write_parameter_94_and_95(&values); }
    // Build and send Write Parameter 96 and 97: Write Parameter 96 and 97 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_96_and_97(const Spark_WRITE_PARAMETER_96_AND_97_t* values = nullptr) const;
    // Build and send Write Parameter 96 and 97: Write Parameter 96 and 97 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_96_and_97(const Spark_WRITE_PARAMETER_96_AND_97_t& values) const { return send_write_parameter_96_and_97(&values); }
    // Build and send Write Parameter 98 and 99: Write Parameter 98 and 99 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_98_and_99(const Spark_WRITE_PARAMETER_98_AND_99_t* values = nullptr) const;
    // Build and send Write Parameter 98 and 99: Write Parameter 98 and 99 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_98_and_99(const Spark_WRITE_PARAMETER_98_AND_99_t& values) const { return send_write_parameter_98_and_99(&values); }
    // Build and send Write Parameter 100 and 101: Write Parameter 100 and 101 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_100_and_101(const Spark_WRITE_PARAMETER_100_AND_101_t* values = nullptr) const;
    // Build and send Write Parameter 100 and 101: Write Parameter 100 and 101 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_100_and_101(const Spark_WRITE_PARAMETER_100_AND_101_t& values) const { return send_write_parameter_100_and_101(&values); }
    // Build and send Write Parameter 102 and 103: Write Parameter 102 and 103 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_102_and_103(const Spark_WRITE_PARAMETER_102_AND_103_t* values = nullptr) const;
    // Build and send Write Parameter 102 and 103: Write Parameter 102 and 103 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_102_and_103(const Spark_WRITE_PARAMETER_102_AND_103_t& values) const { return send_write_parameter_102_and_103(&values); }
    // Build and send Write Parameter 104 and 105: Write Parameter 104 and 105 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_104_and_105(const Spark_WRITE_PARAMETER_104_AND_105_t* values = nullptr) const;
    // Build and send Write Parameter 104 and 105: Write Parameter 104 and 105 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_104_and_105(const Spark_WRITE_PARAMETER_104_AND_105_t& values) const { return send_write_parameter_104_and_105(&values); }
    // Build and send Write Parameter 106 and 107: Write Parameter 106 and 107 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_106_and_107(const Spark_WRITE_PARAMETER_106_AND_107_t* values = nullptr) const;
    // Build and send Write Parameter 106 and 107: Write Parameter 106 and 107 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_106_and_107(const Spark_WRITE_PARAMETER_106_AND_107_t& values) const { return send_write_parameter_106_and_107(&values); }
    // Build and send Write Parameter 108 and 109: Write Parameter 108 and 109 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_108_and_109(const Spark_WRITE_PARAMETER_108_AND_109_t* values = nullptr) const;
    // Build and send Write Parameter 108 and 109: Write Parameter 108 and 109 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_108_and_109(const Spark_WRITE_PARAMETER_108_AND_109_t& values) const { return send_write_parameter_108_and_109(&values); }
    // Build and send Write Parameter 110 and 111: Write Parameter 110 and 111 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_110_and_111(const Spark_WRITE_PARAMETER_110_AND_111_t* values = nullptr) const;
    // Build and send Write Parameter 110 and 111: Write Parameter 110 and 111 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_110_and_111(const Spark_WRITE_PARAMETER_110_AND_111_t& values) const { return send_write_parameter_110_and_111(&values); }
    // Build and send Write Parameter 112 and 113: Write Parameter 112 and 113 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_112_and_113(const Spark_WRITE_PARAMETER_112_AND_113_t* values = nullptr) const;
    // Build and send Write Parameter 112 and 113: Write Parameter 112 and 113 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_112_and_113(const Spark_WRITE_PARAMETER_112_AND_113_t& values) const { return send_write_parameter_112_and_113(&values); }
    // Build and send Write Parameter 114 and 115: Write Parameter 114 and 115 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_114_and_115(const Spark_WRITE_PARAMETER_114_AND_115_t* values = nullptr) const;
    // Build and send Write Parameter 114 and 115: Write Parameter 114 and 115 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_114_and_115(const Spark_WRITE_PARAMETER_114_AND_115_t& values) const { return send_write_parameter_114_and_115(&values); }
    // Build and send Write Parameter 116 and 117: Write Parameter 116 and 117 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_116_and_117(const Spark_WRITE_PARAMETER_116_AND_117_t* values = nullptr) const;
    // Build and send Write Parameter 116 and 117: Write Parameter 116 and 117 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_116_and_117(const Spark_WRITE_PARAMETER_116_AND_117_t& values) const { return send_write_parameter_116_and_117(&values); }
    // Build and send Write Parameter 118 and 119: Write Parameter 118 and 119 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_118_and_119(const Spark_WRITE_PARAMETER_118_AND_119_t* values = nullptr) const;
    // Build and send Write Parameter 118 and 119: Write Parameter 118 and 119 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_118_and_119(const Spark_WRITE_PARAMETER_118_AND_119_t& values) const { return send_write_parameter_118_and_119(&values); }
    // Build and send Write Parameter 120 and 121: Write Parameter 120 and 121 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_120_and_121(const Spark_WRITE_PARAMETER_120_AND_121_t* values = nullptr) const;
    // Build and send Write Parameter 120 and 121: Write Parameter 120 and 121 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_120_and_121(const Spark_WRITE_PARAMETER_120_AND_121_t& values) const { return send_write_parameter_120_and_121(&values); }
    // Build and send Write Parameter 122 and 123: Write Parameter 122 and 123 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_122_and_123(const Spark_WRITE_PARAMETER_122_AND_123_t* values = nullptr) const;
    // Build and send Write Parameter 122 and 123: Write Parameter 122 and 123 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_122_and_123(const Spark_WRITE_PARAMETER_122_AND_123_t& values) const { return send_write_parameter_122_and_123(&values); }
    // Build and send Write Parameter 124 and 125: Write Parameter 124 and 125 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_124_and_125(const Spark_WRITE_PARAMETER_124_AND_125_t* values = nullptr) const;
    // Build and send Write Parameter 124 and 125: Write Parameter 124 and 125 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_124_and_125(const Spark_WRITE_PARAMETER_124_AND_125_t& values) const { return send_write_parameter_124_and_125(&values); }
    // Build and send Write Parameter 126 and 127: Write Parameter 126 and 127 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_126_and_127(const Spark_WRITE_PARAMETER_126_AND_127_t* values = nullptr) const;
    // Build and send Write Parameter 126 and 127: Write Parameter 126 and 127 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_126_and_127(const Spark_WRITE_PARAMETER_126_AND_127_t& values) const { return send_write_parameter_126_and_127(&values); }
    // Build and send Write Parameter 128 and 129: Write Parameter 128 and 129 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_128_and_129(const Spark_WRITE_PARAMETER_128_AND_129_t* values = nullptr) const;
    // Build and send Write Parameter 128 and 129: Write Parameter 128 and 129 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_128_and_129(const Spark_WRITE_PARAMETER_128_AND_129_t& values) const { return send_write_parameter_128_and_129(&values); }
    // Build and send Write Parameter 130 and 131: Write Parameter 130 and 131 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_130_and_131(const Spark_WRITE_PARAMETER_130_AND_131_t* values = nullptr) const;
    // Build and send Write Parameter 130 and 131: Write Parameter 130 and 131 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_130_and_131(const Spark_WRITE_PARAMETER_130_AND_131_t& values) const { return send_write_parameter_130_and_131(&values); }
    // Build and send Write Parameter 132 and 133: Write Parameter 132 and 133 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_132_and_133(const Spark_WRITE_PARAMETER_132_AND_133_t* values = nullptr) const;
    // Build and send Write Parameter 132 and 133: Write Parameter 132 and 133 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_132_and_133(const Spark_WRITE_PARAMETER_132_AND_133_t& values) const { return send_write_parameter_132_and_133(&values); }
    // Build and send Write Parameter 134 and 135: Write Parameter 134 and 135 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_134_and_135(const Spark_WRITE_PARAMETER_134_AND_135_t* values = nullptr) const;
    // Build and send Write Parameter 134 and 135: Write Parameter 134 and 135 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_134_and_135(const Spark_WRITE_PARAMETER_134_AND_135_t& values) const { return send_write_parameter_134_and_135(&values); }
    // Build and send Write Parameter 136 and 137: Write Parameter 136 and 137 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_136_and_137(const Spark_WRITE_PARAMETER_136_AND_137_t* values = nullptr) const;
    // Build and send Write Parameter 136 and 137: Write Parameter 136 and 137 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_136_and_137(const Spark_WRITE_PARAMETER_136_AND_137_t& values) const { return send_write_parameter_136_and_137(&values); }
    // Build and send Write Parameter 138 and 139: Write Parameter 138 and 139 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_138_and_139(const Spark_WRITE_PARAMETER_138_AND_139_t* values = nullptr) const;
    // Build and send Write Parameter 138 and 139: Write Parameter 138 and 139 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_138_and_139(const Spark_WRITE_PARAMETER_138_AND_139_t& values) const { return send_write_parameter_138_and_139(&values); }
    // Build and send Write Parameter 140 and 141: Write Parameter 140 and 141 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_140_and_141(const Spark_WRITE_PARAMETER_140_AND_141_t* values = nullptr) const;
    // Build and send Write Parameter 140 and 141: Write Parameter 140 and 141 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_140_and_141(const Spark_WRITE_PARAMETER_140_AND_141_t& values) const { return send_write_parameter_140_and_141(&values); }
    // Build and send Write Parameter 142 and 143: Write Parameter 142 and 143 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_142_and_143(const Spark_WRITE_PARAMETER_142_AND_143_t* values = nullptr) const;
    // Build and send Write Parameter 142 and 143: Write Parameter 142 and 143 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_142_and_143(const Spark_WRITE_PARAMETER_142_AND_143_t& values) const { return send_write_parameter_142_and_143(&values); }
    // Build and send Write Parameter 144 and 145: Write Parameter 144 and 145 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_144_and_145(const Spark_WRITE_PARAMETER_144_AND_145_t* values = nullptr) const;
    // Build and send Write Parameter 144 and 145: Write Parameter 144 and 145 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_144_and_145(const Spark_WRITE_PARAMETER_144_AND_145_t& values) const { return send_write_parameter_144_and_145(&values); }
    // Build and send Write Parameter 146 and 147: Write Parameter 146 and 147 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_146_and_147(const Spark_WRITE_PARAMETER_146_AND_147_t* values = nullptr) const;
    // Build and send Write Parameter 146 and 147: Write Parameter 146 and 147 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_146_and_147(const Spark_WRITE_PARAMETER_146_AND_147_t& values) const { return send_write_parameter_146_and_147(&values); }
    // Build and send Write Parameter 148 and 149: Write Parameter 148 and 149 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_148_and_149(const Spark_WRITE_PARAMETER_148_AND_149_t* values = nullptr) const;
    // Build and send Write Parameter 148 and 149: Write Parameter 148 and 149 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_148_and_149(const Spark_WRITE_PARAMETER_148_AND_149_t& values) const { return send_write_parameter_148_and_149(&values); }
    // Build and send Write Parameter 150 and 151: Write Parameter 150 and 151 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_150_and_151(const Spark_WRITE_PARAMETER_150_AND_151_t* values = nullptr) const;
    // Build and send Write Parameter 150 and 151: Write Parameter 150 and 151 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_150_and_151(const Spark_WRITE_PARAMETER_150_AND_151_t& values) const { return send_write_parameter_150_and_151(&values); }
    // Build and send Write Parameter 152 and 153: Write Parameter 152 and 153 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_152_and_153(const Spark_WRITE_PARAMETER_152_AND_153_t* values = nullptr) const;
    // Build and send Write Parameter 152 and 153: Write Parameter 152 and 153 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_152_and_153(const Spark_WRITE_PARAMETER_152_AND_153_t& values) const { return send_write_parameter_152_and_153(&values); }
    // Build and send Write Parameter 154 and 155: Write Parameter 154 and 155 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_154_and_155(const Spark_WRITE_PARAMETER_154_AND_155_t* values = nullptr) const;
    // Build and send Write Parameter 154 and 155: Write Parameter 154 and 155 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_154_and_155(const Spark_WRITE_PARAMETER_154_AND_155_t& values) const { return send_write_parameter_154_and_155(&values); }
    // Build and send Write Parameter 156 and 157: Write Parameter 156 and 157 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_156_and_157(const Spark_WRITE_PARAMETER_156_AND_157_t* values = nullptr) const;
    // Build and send Write Parameter 156 and 157: Write Parameter 156 and 157 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_156_and_157(const Spark_WRITE_PARAMETER_156_AND_157_t& values) const { return send_write_parameter_156_and_157(&values); }
    // Build and send Write Parameter 158 and 159: Write Parameter 158 and 159 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_158_and_159(const Spark_WRITE_PARAMETER_158_AND_159_t* values = nullptr) const;
    // Build and send Write Parameter 158 and 159: Write Parameter 158 and 159 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_158_and_159(const Spark_WRITE_PARAMETER_158_AND_159_t& values) const { return send_write_parameter_158_and_159(&values); }
    // Build and send Write Parameter 160 and 161: Write Parameter 160 and 161 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_160_and_161(const Spark_WRITE_PARAMETER_160_AND_161_t* values = nullptr) const;
    // Build and send Write Parameter 160 and 161: Write Parameter 160 and 161 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_160_and_161(const Spark_WRITE_PARAMETER_160_AND_161_t& values) const { return send_write_parameter_160_and_161(&values); }
    // Build and send Write Parameter 162 and 163: Write Parameter 162 and 163 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_162_and_163(const Spark_WRITE_PARAMETER_162_AND_163_t* values = nullptr) const;
    // Build and send Write Parameter 162 and 163: Write Parameter 162 and 163 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_162_and_163(const Spark_WRITE_PARAMETER_162_AND_163_t& values) const { return send_write_parameter_162_and_163(&values); }
    // Build and send Write Parameter 164 and 165: Write Parameter 164 and 165 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_164_and_165(const Spark_WRITE_PARAMETER_164_AND_165_t* values = nullptr) const;
    // Build and send Write Parameter 164 and 165: Write Parameter 164 and 165 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_164_and_165(const Spark_WRITE_PARAMETER_164_AND_165_t& values) const { return send_write_parameter_164_and_165(&values); }
    // Build and send Write Parameter 166 and 167: Write Parameter 166 and 167 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_166_and_167(const Spark_WRITE_PARAMETER_166_AND_167_t* values = nullptr) const;
    // Build and send Write Parameter 166 and 167: Write Parameter 166 and 167 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_166_and_167(const Spark_WRITE_PARAMETER_166_AND_167_t& values) const { return send_write_parameter_166_and_167(&values); }
    // Build and send Write Parameter 168 and 169: Write Parameter 168 and 169 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_168_and_169(const Spark_WRITE_PARAMETER_168_AND_169_t* values = nullptr) const;
    // Build and send Write Parameter 168 and 169: Write Parameter 168 and 169 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_168_and_169(const Spark_WRITE_PARAMETER_168_AND_169_t& values) const { return send_write_parameter_168_and_169(&values); }
    // Build and send Write Parameter 170 and 171: Write Parameter 170 and 171 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_170_and_171(const Spark_WRITE_PARAMETER_170_AND_171_t* values = nullptr) const;
    // Build and send Write Parameter 170 and 171: Write Parameter 170 and 171 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_170_and_171(const Spark_WRITE_PARAMETER_170_AND_171_t& values) const { return send_write_parameter_170_and_171(&values); }
    // Build and send Write Parameter 172 and 173: Write Parameter 172 and 173 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_172_and_173(const Spark_WRITE_PARAMETER_172_AND_173_t* values = nullptr) const;
    // Build and send Write Parameter 172 and 173: Write Parameter 172 and 173 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_172_and_173(const Spark_WRITE_PARAMETER_172_AND_173_t& values) const { return send_write_parameter_172_and_173(&values); }
    // Build and send Write Parameter 174 and 175: Write Parameter 174 and 175 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_174_and_175(const Spark_WRITE_PARAMETER_174_AND_175_t* values = nullptr) const;
    // Build and send Write Parameter 174 and 175: Write Parameter 174 and 175 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_174_and_175(const Spark_WRITE_PARAMETER_174_AND_175_t& values) const { return send_write_parameter_174_and_175(&values); }
    // Build and send Write Parameter 176 and 177: Write Parameter 176 and 177 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_176_and_177(const Spark_WRITE_PARAMETER_176_AND_177_t* values = nullptr) const;
    // Build and send Write Parameter 176 and 177: Write Parameter 176 and 177 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_176_and_177(const Spark_WRITE_PARAMETER_176_AND_177_t& values) const { return send_write_parameter_176_and_177(&values); }
    // Build and send Write Parameter 178 and 179: Write Parameter 178 and 179 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_178_and_179(const Spark_WRITE_PARAMETER_178_AND_179_t* values = nullptr) const;
    // Build and send Write Parameter 178 and 179: Write Parameter 178 and 179 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_178_and_179(const Spark_WRITE_PARAMETER_178_AND_179_t& values) const { return send_write_parameter_178_and_179(&values); }
    // Build and send Write Parameter 180 and 181: Write Parameter 180 and 181 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_180_and_181(const Spark_WRITE_PARAMETER_180_AND_181_t* values = nullptr) const;
    // Build and send Write Parameter 180 and 181: Write Parameter 180 and 181 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_180_and_181(const Spark_WRITE_PARAMETER_180_AND_181_t& values) const { return send_write_parameter_180_and_181(&values); }
    // Build and send Write Parameter 182 and 183: Write Parameter 182 and 183 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_182_and_183(const Spark_WRITE_PARAMETER_182_AND_183_t* values = nullptr) const;
    // Build and send Write Parameter 182 and 183: Write Parameter 182 and 183 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_182_and_183(const Spark_WRITE_PARAMETER_182_AND_183_t& values) const { return send_write_parameter_182_and_183(&values); }
    // Build and send Write Parameter 184 and 185: Write Parameter 184 and 185 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_184_and_185(const Spark_WRITE_PARAMETER_184_AND_185_t* values = nullptr) const;
    // Build and send Write Parameter 184 and 185: Write Parameter 184 and 185 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_184_and_185(const Spark_WRITE_PARAMETER_184_AND_185_t& values) const { return send_write_parameter_184_and_185(&values); }
    // Build and send Write Parameter 186 and 187: Write Parameter 186 and 187 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_186_and_187(const Spark_WRITE_PARAMETER_186_AND_187_t* values = nullptr) const;
    // Build and send Write Parameter 186 and 187: Write Parameter 186 and 187 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_186_and_187(const Spark_WRITE_PARAMETER_186_AND_187_t& values) const { return send_write_parameter_186_and_187(&values); }
    // Build and send Write Parameter 188 and 189: Write Parameter 188 and 189 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_188_and_189(const Spark_WRITE_PARAMETER_188_AND_189_t* values = nullptr) const;
    // Build and send Write Parameter 188 and 189: Write Parameter 188 and 189 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_188_and_189(const Spark_WRITE_PARAMETER_188_AND_189_t& values) const { return send_write_parameter_188_and_189(&values); }
    // Build and send Write Parameter 190 and 191: Write Parameter 190 and 191 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_190_and_191(const Spark_WRITE_PARAMETER_190_AND_191_t* values = nullptr) const;
    // Build and send Write Parameter 190 and 191: Write Parameter 190 and 191 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_190_and_191(const Spark_WRITE_PARAMETER_190_AND_191_t& values) const { return send_write_parameter_190_and_191(&values); }
    // Build and send Write Parameter 192 and 193: Write Parameter 192 and 193 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_192_and_193(const Spark_WRITE_PARAMETER_192_AND_193_t* values = nullptr) const;
    // Build and send Write Parameter 192 and 193: Write Parameter 192 and 193 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_192_and_193(const Spark_WRITE_PARAMETER_192_AND_193_t& values) const { return send_write_parameter_192_and_193(&values); }
    // Build and send Write Parameter 194 and 195: Write Parameter 194 and 195 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_194_and_195(const Spark_WRITE_PARAMETER_194_AND_195_t* values = nullptr) const;
    // Build and send Write Parameter 194 and 195: Write Parameter 194 and 195 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_194_and_195(const Spark_WRITE_PARAMETER_194_AND_195_t& values) const { return send_write_parameter_194_and_195(&values); }
    // Build and send Write Parameter 196 and 197: Write Parameter 196 and 197 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_196_and_197(const Spark_WRITE_PARAMETER_196_AND_197_t* values = nullptr) const;
    // Build and send Write Parameter 196 and 197: Write Parameter 196 and 197 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_196_and_197(const Spark_WRITE_PARAMETER_196_AND_197_t& values) const { return send_write_parameter_196_and_197(&values); }
    // Build and send Write Parameter 198 and 199: Write Parameter 198 and 199 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_198_and_199(const Spark_WRITE_PARAMETER_198_AND_199_t* values = nullptr) const;
    // Build and send Write Parameter 198 and 199: Write Parameter 198 and 199 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_198_and_199(const Spark_WRITE_PARAMETER_198_AND_199_t& values) const { return send_write_parameter_198_and_199(&values); }
    // Build and send Write Parameter 200 and 201: Write Parameter 200 and 201 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_200_and_201(const Spark_WRITE_PARAMETER_200_AND_201_t* values = nullptr) const;
    // Build and send Write Parameter 200 and 201: Write Parameter 200 and 201 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_200_and_201(const Spark_WRITE_PARAMETER_200_AND_201_t& values) const { return send_write_parameter_200_and_201(&values); }
    // Build and send Write Parameter 202 and 203: Write Parameter 202 and 203 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_202_and_203(const Spark_WRITE_PARAMETER_202_AND_203_t* values = nullptr) const;
    // Build and send Write Parameter 202 and 203: Write Parameter 202 and 203 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_202_and_203(const Spark_WRITE_PARAMETER_202_AND_203_t& values) const { return send_write_parameter_202_and_203(&values); }
    // Build and send Write Parameter 204 and 205: Write Parameter 204 and 205 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_204_and_205(const Spark_WRITE_PARAMETER_204_AND_205_t* values = nullptr) const;
    // Build and send Write Parameter 204 and 205: Write Parameter 204 and 205 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_204_and_205(const Spark_WRITE_PARAMETER_204_AND_205_t& values) const { return send_write_parameter_204_and_205(&values); }
    // Build and send Write Parameter 206 and 207: Write Parameter 206 and 207 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_206_and_207(const Spark_WRITE_PARAMETER_206_AND_207_t* values = nullptr) const;
    // Build and send Write Parameter 206 and 207: Write Parameter 206 and 207 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_206_and_207(const Spark_WRITE_PARAMETER_206_AND_207_t& values) const { return send_write_parameter_206_and_207(&values); }
    // Build and send Write Parameter 208 and 209: Write Parameter 208 and 209 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_208_and_209(const Spark_WRITE_PARAMETER_208_AND_209_t* values = nullptr) const;
    // Build and send Write Parameter 208 and 209: Write Parameter 208 and 209 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_208_and_209(const Spark_WRITE_PARAMETER_208_AND_209_t& values) const { return send_write_parameter_208_and_209(&values); }
    // Build and send Write Parameter 210 and 211: Write Parameter 210 and 211 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_210_and_211(const Spark_WRITE_PARAMETER_210_AND_211_t* values = nullptr) const;
    // Build and send Write Parameter 210 and 211: Write Parameter 210 and 211 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_210_and_211(const Spark_WRITE_PARAMETER_210_AND_211_t& values) const { return send_write_parameter_210_and_211(&values); }
    // Build and send Write Parameter 212 and 213: Write Parameter 212 and 213 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_212_and_213(const Spark_WRITE_PARAMETER_212_AND_213_t* values = nullptr) const;
    // Build and send Write Parameter 212 and 213: Write Parameter 212 and 213 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_212_and_213(const Spark_WRITE_PARAMETER_212_AND_213_t& values) const { return send_write_parameter_212_and_213(&values); }
    // Build and send Write Parameter 214 and 215: Write Parameter 214 and 215 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_214_and_215(const Spark_WRITE_PARAMETER_214_AND_215_t* values = nullptr) const;
    // Build and send Write Parameter 214 and 215: Write Parameter 214 and 215 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_214_and_215(const Spark_WRITE_PARAMETER_214_AND_215_t& values) const { return send_write_parameter_214_and_215(&values); }
    // Build and send Write Parameter 216 and 217: Write Parameter 216 and 217 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_216_and_217(const Spark_WRITE_PARAMETER_216_AND_217_t* values = nullptr) const;
    // Build and send Write Parameter 216 and 217: Write Parameter 216 and 217 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_216_and_217(const Spark_WRITE_PARAMETER_216_AND_217_t& values) const { return send_write_parameter_216_and_217(&values); }
    // Build and send Write Parameter 218 and 219: Write Parameter 218 and 219 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_218_and_219(const Spark_WRITE_PARAMETER_218_AND_219_t* values = nullptr) const;
    // Build and send Write Parameter 218 and 219: Write Parameter 218 and 219 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_218_and_219(const Spark_WRITE_PARAMETER_218_AND_219_t& values) const { return send_write_parameter_218_and_219(&values); }
    // Build and send Write Parameter 220 and 221: Write Parameter 220 and 221 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_220_and_221(const Spark_WRITE_PARAMETER_220_AND_221_t* values = nullptr) const;
    // Build and send Write Parameter 220 and 221: Write Parameter 220 and 221 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_220_and_221(const Spark_WRITE_PARAMETER_220_AND_221_t& values) const { return send_write_parameter_220_and_221(&values); }
    // Build and send Write Parameter 222 and 223: Write Parameter 222 and 223 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_222_and_223(const Spark_WRITE_PARAMETER_222_AND_223_t* values = nullptr) const;
    // Build and send Write Parameter 222 and 223: Write Parameter 222 and 223 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_222_and_223(const Spark_WRITE_PARAMETER_222_AND_223_t& values) const { return send_write_parameter_222_and_223(&values); }
    // Build and send Write Parameter 224 and 225: Write Parameter 224 and 225 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_224_and_225(const Spark_WRITE_PARAMETER_224_AND_225_t* values = nullptr) const;
    // Build and send Write Parameter 224 and 225: Write Parameter 224 and 225 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_224_and_225(const Spark_WRITE_PARAMETER_224_AND_225_t& values) const { return send_write_parameter_224_and_225(&values); }
    // Build and send Write Parameter 226 and 227: Write Parameter 226 and 227 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_226_and_227(const Spark_WRITE_PARAMETER_226_AND_227_t* values = nullptr) const;
    // Build and send Write Parameter 226 and 227: Write Parameter 226 and 227 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_226_and_227(const Spark_WRITE_PARAMETER_226_AND_227_t& values) const { return send_write_parameter_226_and_227(&values); }
    // Build and send Write Parameter 228 and 229: Write Parameter 228 and 229 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_228_and_229(const Spark_WRITE_PARAMETER_228_AND_229_t* values = nullptr) const;
    // Build and send Write Parameter 228 and 229: Write Parameter 228 and 229 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_228_and_229(const Spark_WRITE_PARAMETER_228_AND_229_t& values) const { return send_write_parameter_228_and_229(&values); }
    // Build and send Write Parameter 230 and 231: Write Parameter 230 and 231 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_230_and_231(const Spark_WRITE_PARAMETER_230_AND_231_t* values = nullptr) const;
    // Build and send Write Parameter 230 and 231: Write Parameter 230 and 231 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_230_and_231(const Spark_WRITE_PARAMETER_230_AND_231_t& values) const { return send_write_parameter_230_and_231(&values); }
    // Build and send Write Parameter 232 and 233: Write Parameter 232 and 233 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_232_and_233(const Spark_WRITE_PARAMETER_232_AND_233_t* values = nullptr) const;
    // Build and send Write Parameter 232 and 233: Write Parameter 232 and 233 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_232_and_233(const Spark_WRITE_PARAMETER_232_AND_233_t& values) const { return send_write_parameter_232_and_233(&values); }
    // Build and send Write Parameter 234 and 235: Write Parameter 234 and 235 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_234_and_235(const Spark_WRITE_PARAMETER_234_AND_235_t* values = nullptr) const;
    // Build and send Write Parameter 234 and 235: Write Parameter 234 and 235 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_234_and_235(const Spark_WRITE_PARAMETER_234_AND_235_t& values) const { return send_write_parameter_234_and_235(&values); }
    // Build and send Write Parameter 236 and 237: Write Parameter 236 and 237 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_236_and_237(const Spark_WRITE_PARAMETER_236_AND_237_t* values = nullptr) const;
    // Build and send Write Parameter 236 and 237: Write Parameter 236 and 237 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_236_and_237(const Spark_WRITE_PARAMETER_236_AND_237_t& values) const { return send_write_parameter_236_and_237(&values); }
    // Build and send Write Parameter 238 and 239: Write Parameter 238 and 239 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_238_and_239(const Spark_WRITE_PARAMETER_238_AND_239_t* values = nullptr) const;
    // Build and send Write Parameter 238 and 239: Write Parameter 238 and 239 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_238_and_239(const Spark_WRITE_PARAMETER_238_AND_239_t& values) const { return send_write_parameter_238_and_239(&values); }
    // Build and send Write Parameter 240 and 241: Write Parameter 240 and 241 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_240_and_241(const Spark_WRITE_PARAMETER_240_AND_241_t* values = nullptr) const;
    // Build and send Write Parameter 240 and 241: Write Parameter 240 and 241 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_240_and_241(const Spark_WRITE_PARAMETER_240_AND_241_t& values) const { return send_write_parameter_240_and_241(&values); }
    // Build and send Write Parameter 242 and 243: Write Parameter 242 and 243 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_242_and_243(const Spark_WRITE_PARAMETER_242_AND_243_t* values = nullptr) const;
    // Build and send Write Parameter 242 and 243: Write Parameter 242 and 243 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_242_and_243(const Spark_WRITE_PARAMETER_242_AND_243_t& values) const { return send_write_parameter_242_and_243(&values); }
    // Build and send Write Parameter 244 and 245: Write Parameter 244 and 245 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_244_and_245(const Spark_WRITE_PARAMETER_244_AND_245_t* values = nullptr) const;
    // Build and send Write Parameter 244 and 245: Write Parameter 244 and 245 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_244_and_245(const Spark_WRITE_PARAMETER_244_AND_245_t& values) const { return send_write_parameter_244_and_245(&values); }
    // Build and send Write Parameter 246 and 247: Write Parameter 246 and 247 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_246_and_247(const Spark_WRITE_PARAMETER_246_AND_247_t* values = nullptr) const;
    // Build and send Write Parameter 246 and 247: Write Parameter 246 and 247 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_246_and_247(const Spark_WRITE_PARAMETER_246_AND_247_t& values) const { return send_write_parameter_246_and_247(&values); }
    // Build and send Write Parameter 248 and 249: Write Parameter 248 and 249 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_248_and_249(const Spark_WRITE_PARAMETER_248_AND_249_t* values = nullptr) const;
    // Build and send Write Parameter 248 and 249: Write Parameter 248 and 249 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_248_and_249(const Spark_WRITE_PARAMETER_248_AND_249_t& values) const { return send_write_parameter_248_and_249(&values); }
    // Build and send Write Parameter 250 and 251: Write Parameter 250 and 251 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_250_and_251(const Spark_WRITE_PARAMETER_250_AND_251_t* values = nullptr) const;
    // Build and send Write Parameter 250 and 251: Write Parameter 250 and 251 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_250_and_251(const Spark_WRITE_PARAMETER_250_AND_251_t& values) const { return send_write_parameter_250_and_251(&values); }
    // Build and send Write Parameter 252 and 253: Write Parameter 252 and 253 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_252_and_253(const Spark_WRITE_PARAMETER_252_AND_253_t* values = nullptr) const;
    // Build and send Write Parameter 252 and 253: Write Parameter 252 and 253 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_252_and_253(const Spark_WRITE_PARAMETER_252_AND_253_t& values) const { return send_write_parameter_252_and_253(&values); }
    // Build and send Write Parameter 254 and 255: Write Parameter 254 and 255 at the same time. Two Write Parameter Response frames will be sent in response. (pointer overload)
    MCP2515::ERROR send_write_parameter_254_and_255(const Spark_WRITE_PARAMETER_254_AND_255_t* values = nullptr) const;
    // Build and send Write Parameter 254 and 255: Write Parameter 254 and 255 at the same time. Two Write Parameter Response frames will be sent in response. (by-value overload)
    MCP2515::ERROR send_write_parameter_254_and_255(const Spark_WRITE_PARAMETER_254_AND_255_t& values) const { return send_write_parameter_254_and_255(&values); }
    // Build and send Start Follower Mode: Starts follower mode. The relevant parameters must already be configured. In response, a Start Follower Mode Response frame will be sent. Follower mode will be auto-started on boot if the Follower Mode Leader ID parameter is set to a non-zero value. (pointer overload)
    MCP2515::ERROR send_start_follower_mode(const Spark_START_FOLLOWER_MODE_t* values = nullptr) const;
    // Build and send Start Follower Mode: Starts follower mode. The relevant parameters must already be configured. In response, a Start Follower Mode Response frame will be sent. Follower mode will be auto-started on boot if the Follower Mode Leader ID parameter is set to a non-zero value. (by-value overload)
    MCP2515::ERROR send_start_follower_mode(const Spark_START_FOLLOWER_MODE_t& values) const { return send_start_follower_mode(&values); }
    // Build and send Start Follower Mode Response: Response for a Start Follower Mode command (pointer overload)
    MCP2515::ERROR send_start_follower_mode_response(const Spark_START_FOLLOWER_MODE_RESPONSE_t* values = nullptr) const;
    // Build and send Start Follower Mode Response: Response for a Start Follower Mode command (by-value overload)
    MCP2515::ERROR send_start_follower_mode_response(const Spark_START_FOLLOWER_MODE_RESPONSE_t& values) const { return send_start_follower_mode_response(&values); }
    // Build and send Stop Follower Mode: Exits follower mode and causes the device to resume listening for setpoints addressed directly to it. In response, a Stop Follower Mode Response frame will be sent. (pointer overload)
    MCP2515::ERROR send_stop_follower_mode(const Spark_STOP_FOLLOWER_MODE_t* values = nullptr) const;
    // Build and send Stop Follower Mode: Exits follower mode and causes the device to resume listening for setpoints addressed directly to it. In response, a Stop Follower Mode Response frame will be sent. (by-value overload)
    MCP2515::ERROR send_stop_follower_mode(const Spark_STOP_FOLLOWER_MODE_t& values) const { return send_stop_follower_mode(&values); }
    // Build and send Stop Follower Mode Response: Response for a Stop Follower Mode Command (pointer overload)
    MCP2515::ERROR send_stop_follower_mode_response(const Spark_STOP_FOLLOWER_MODE_RESPONSE_t* values = nullptr) const;
    // Build and send Stop Follower Mode Response: Response for a Stop Follower Mode Command (by-value overload)
    MCP2515::ERROR send_stop_follower_mode_response(const Spark_STOP_FOLLOWER_MODE_RESPONSE_t& values) const { return send_stop_follower_mode_response(&values); }
    // Build and send Enter SWDL CAN Bootloader (pointer overload)
    MCP2515::ERROR send_enter_swdl_can_bootloader(const Spark_ENTER_SWDL_CAN_BOOTLOADER_t* values = nullptr) const;
    // Build and send Enter SWDL CAN Bootloader (by-value overload)
    MCP2515::ERROR send_enter_swdl_can_bootloader(const Spark_ENTER_SWDL_CAN_BOOTLOADER_t& values) const { return send_enter_swdl_can_bootloader(&values); }
    // Build and send Persist Parameters: Causes all parameters to be written to non-volatile storage. After the operation (which may take up to a second) completes, a Persist Parameters Response frame will be sent. (pointer overload)
    MCP2515::ERROR send_persist_parameters(const Spark_PERSIST_PARAMETERS_t* values = nullptr) const;
    // Build and send Persist Parameters: Causes all parameters to be written to non-volatile storage. After the operation (which may take up to a second) completes, a Persist Parameters Response frame will be sent. (by-value overload)
    MCP2515::ERROR send_persist_parameters(const Spark_PERSIST_PARAMETERS_t& values) const { return send_persist_parameters(&values); }
private:
    uint8_t device_id_;
    MCP2515* controller_;
    MCP2515::ERROR dispatch_frame(const spark_can_frame& frame) const;
};

} // namespace CanControl::LowLevel::SparkMax

