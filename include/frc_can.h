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

        static constexpr unsigned SHIFT_device_number = 0;
        static constexpr uint32_t MASK_device_number = 0x3Fu; // 6 bits

        static constexpr unsigned SHIFT_api_index = 6;
        static constexpr uint32_t MASK_api_index = 0x0Fu; // 4 bits

        static constexpr unsigned SHIFT_api_class = 10;
        static constexpr uint32_t MASK_api_class = 0x3Fu; // 6 bits

        static constexpr unsigned SHIFT_manufacturer_code = 16;
        static constexpr uint32_t MASK_manufacturer_code = 0xFFu; // 8 bits

        static constexpr unsigned SHIFT_device_type = 24;
        static constexpr uint32_t MASK_device_type = 0x1Fu; // 5 bits

        static constexpr unsigned SHIFT_flag_err = 29;
        static constexpr unsigned SHIFT_flag_rtr = 30;
        static constexpr unsigned SHIFT_flag_eff = 31;

        static constexpr uint32_t MASK_frc_id = 0x1FFFFFFFu;

        // Accessors
        uint32_t frc_id() const { return raw & MASK_frc_id; }
        uint32_t device_number() const { return (raw >> SHIFT_device_number) & MASK_device_number; }
        uint32_t api_index() const { return (raw >> SHIFT_api_index) & MASK_api_index; }
        uint32_t api_class() const { return (raw >> SHIFT_api_class) & MASK_api_class; }
        uint32_t manufacturer_code() const { return (raw >> SHIFT_manufacturer_code) & MASK_manufacturer_code; }
        uint32_t device_type() const { return (raw >> SHIFT_device_type) & MASK_device_type; }
        bool flag_err() const { return ((raw >> SHIFT_flag_err) & 0x1u) != 0; }
        bool flag_rtr() const { return ((raw >> SHIFT_flag_rtr) & 0x1u) != 0; }
        bool flag_eff() const { return ((raw >> SHIFT_flag_eff) & 0x1u) != 0; }

        // Mutators
        void set_device_number(uint32_t v) { raw = (raw & ~(MASK_device_number << SHIFT_device_number)) | ((v & MASK_device_number) << SHIFT_device_number); }
        void set_api_index(uint32_t v) { raw = (raw & ~(MASK_api_index << SHIFT_api_index)) | ((v & MASK_api_index) << SHIFT_api_index); }
        void set_api_class(uint32_t v) { raw = (raw & ~(MASK_api_class << SHIFT_api_class)) | ((v & MASK_api_class) << SHIFT_api_class); }
        void set_manufacturer_code(uint32_t v) { raw = (raw & ~(MASK_manufacturer_code << SHIFT_manufacturer_code)) | ((v & MASK_manufacturer_code) << SHIFT_manufacturer_code); }
        void set_device_type(uint32_t v) { raw = (raw & ~(MASK_device_type << SHIFT_device_type)) | ((v & MASK_device_type) << SHIFT_device_type); }
        void set_flag_err(bool v) { raw = (raw & ~(uint32_t(1) << SHIFT_flag_err)) | ((uint32_t(v) & 1u) << SHIFT_flag_err); }
        void set_flag_rtr(bool v) { raw = (raw & ~(uint32_t(1) << SHIFT_flag_rtr)) | ((uint32_t(v) & 1u) << SHIFT_flag_rtr); }
        void set_flag_eff(bool v) { raw = (raw & ~(uint32_t(1) << SHIFT_flag_eff)) | ((uint32_t(v) & 1u) << SHIFT_flag_eff); }
    };

    struct frc_can_frame
    {
        frc_can_id id;
        uint8_t dlc;
        uint8_t data[8];
    };

    namespace heartbeat
    {
        static const uint32_t HEARTHBEAT_ID = 0x01011840u;

        struct RobotState
        {
            uint64_t raw{0};

            static constexpr unsigned SHIFT_matchTimeSeconds = 0;
            static constexpr uint64_t MASK_matchTimeSeconds = 0xFFULL;

            static constexpr unsigned SHIFT_matchNumber = 8;
            static constexpr uint64_t MASK_matchNumber = 0x3FFULL;

            static constexpr unsigned SHIFT_replayNumber = 18;
            static constexpr uint64_t MASK_replayNumber = 0x3FULL;

            static constexpr unsigned SHIFT_redAlliance = 24;
            static constexpr uint64_t MASK_redAlliance = 0x1ULL;

            static constexpr unsigned SHIFT_enabled = 25;
            static constexpr uint64_t MASK_enabled = 0x1ULL;

            static constexpr unsigned SHIFT_autonomous = 26;
            static constexpr uint64_t MASK_autonomous = 0x1ULL;

            static constexpr unsigned SHIFT_testMode = 27;
            static constexpr uint64_t MASK_testMode = 0x1ULL;

            static constexpr unsigned SHIFT_systemWatchdog = 28;
            static constexpr uint64_t MASK_systemWatchdog = 0x1ULL;

            static constexpr unsigned SHIFT_tournamentType = 29;
            static constexpr uint64_t MASK_tournamentType = 0x7ULL;

            static constexpr unsigned SHIFT_timeOfDay_yr = 32;
            static constexpr uint64_t MASK_timeOfDay_yr = 0x3FULL;

            static constexpr unsigned SHIFT_timeOfDay_month = 38;
            static constexpr uint64_t MASK_timeOfDay_month = 0xFULL;

            static constexpr unsigned SHIFT_timeOfDay_day = 42;
            static constexpr uint64_t MASK_timeOfDay_day = 0x1FULL;

            static constexpr unsigned SHIFT_timeOfDay_sec = 47;
            static constexpr uint64_t MASK_timeOfDay_sec = 0x3FULL;

            static constexpr unsigned SHIFT_timeOfDay_min = 53;
            static constexpr uint64_t MASK_timeOfDay_min = 0x3FULL;

            static constexpr unsigned SHIFT_timeOfDay_hr = 59;
            static constexpr uint64_t MASK_timeOfDay_hr = 0x1FULL;

            // Accessors
            uint32_t matchTimeSeconds() const { return (raw >> SHIFT_matchTimeSeconds) & MASK_matchTimeSeconds; }
            uint32_t matchNumber() const { return (raw >> SHIFT_matchNumber) & MASK_matchNumber; }
            uint32_t replayNumber() const { return (raw >> SHIFT_replayNumber) & MASK_replayNumber; }
            bool redAlliance() const { return ((raw >> SHIFT_redAlliance) & MASK_redAlliance) != 0; }
            bool enabled() const { return ((raw >> SHIFT_enabled) & MASK_enabled) != 0; }
            bool autonomous() const { return ((raw >> SHIFT_autonomous) & MASK_autonomous) != 0; }
            bool testMode() const { return ((raw >> SHIFT_testMode) & MASK_testMode) != 0; }
            bool systemWatchdog() const { return ((raw >> SHIFT_systemWatchdog) & MASK_systemWatchdog) != 0; }
            uint32_t tournamentType() const { return (raw >> SHIFT_tournamentType) & MASK_tournamentType; }
            uint32_t timeOfDay_yr() const { return (raw >> SHIFT_timeOfDay_yr) & MASK_timeOfDay_yr; }
            uint32_t timeOfDay_month() const { return (raw >> SHIFT_timeOfDay_month) & MASK_timeOfDay_month; }
            uint32_t timeOfDay_day() const { return (raw >> SHIFT_timeOfDay_day) & MASK_timeOfDay_day; }
            uint32_t timeOfDay_sec() const { return (raw >> SHIFT_timeOfDay_sec) & MASK_timeOfDay_sec; }
            uint32_t timeOfDay_min() const { return (raw >> SHIFT_timeOfDay_min) & MASK_timeOfDay_min; }
            uint32_t timeOfDay_hr() const { return (raw >> SHIFT_timeOfDay_hr) & MASK_timeOfDay_hr; }

            // Mutators (return reference to allow chaining if desired)
            void set_matchTimeSeconds(uint64_t v) { raw = (raw & ~(MASK_matchTimeSeconds << SHIFT_matchTimeSeconds)) | ((v & MASK_matchTimeSeconds) << SHIFT_matchTimeSeconds); }
            void set_matchNumber(uint64_t v) { raw = (raw & ~(MASK_matchNumber << SHIFT_matchNumber)) | ((v & MASK_matchNumber) << SHIFT_matchNumber); }
            void set_replayNumber(uint64_t v) { raw = (raw & ~(MASK_replayNumber << SHIFT_replayNumber)) | ((v & MASK_replayNumber) << SHIFT_replayNumber); }
            void set_redAlliance(bool v) { raw = (raw & ~(MASK_redAlliance << SHIFT_redAlliance)) | ((uint64_t(v) & MASK_redAlliance) << SHIFT_redAlliance); }
            void set_enabled(bool v) { raw = (raw & ~(MASK_enabled << SHIFT_enabled)) | ((uint64_t(v) & MASK_enabled) << SHIFT_enabled); }
            void set_autonomous(bool v) { raw = (raw & ~(MASK_autonomous << SHIFT_autonomous)) | ((uint64_t(v) & MASK_autonomous) << SHIFT_autonomous); }
            void set_testMode(bool v) { raw = (raw & ~(MASK_testMode << SHIFT_testMode)) | ((uint64_t(v) & MASK_testMode) << SHIFT_testMode); }
            void set_systemWatchdog(bool v) { raw = (raw & ~(MASK_systemWatchdog << SHIFT_systemWatchdog)) | ((uint64_t(v) & MASK_systemWatchdog) << SHIFT_systemWatchdog); }
            void set_tournamentType(uint64_t v) { raw = (raw & ~(MASK_tournamentType << SHIFT_tournamentType)) | ((v & MASK_tournamentType) << SHIFT_tournamentType); }
            void set_timeOfDay_yr(uint64_t v) { raw = (raw & ~(MASK_timeOfDay_yr << SHIFT_timeOfDay_yr)) | ((v & MASK_timeOfDay_yr) << SHIFT_timeOfDay_yr); }
            void set_timeOfDay_month(uint64_t v) { raw = (raw & ~(MASK_timeOfDay_month << SHIFT_timeOfDay_month)) | ((v & MASK_timeOfDay_month) << SHIFT_timeOfDay_month); }
            void set_timeOfDay_day(uint64_t v) { raw = (raw & ~(MASK_timeOfDay_day << SHIFT_timeOfDay_day)) | ((v & MASK_timeOfDay_day) << SHIFT_timeOfDay_day); }
            void set_timeOfDay_sec(uint64_t v) { raw = (raw & ~(MASK_timeOfDay_sec << SHIFT_timeOfDay_sec)) | ((v & MASK_timeOfDay_sec) << SHIFT_timeOfDay_sec); }
            void set_timeOfDay_min(uint64_t v) { raw = (raw & ~(MASK_timeOfDay_min << SHIFT_timeOfDay_min)) | ((v & MASK_timeOfDay_min) << SHIFT_timeOfDay_min); }
            void set_timeOfDay_hr(uint64_t v) { raw = (raw & ~(MASK_timeOfDay_hr << SHIFT_timeOfDay_hr)) | ((v & MASK_timeOfDay_hr) << SHIFT_timeOfDay_hr); }
        };

        inline frc_can_frame to_frc_can_frame(const RobotState &s)
        {
            frc_can_frame f{};
            f.id.raw = (HEARTHBEAT_ID & 0x1FFFFFFFu) | EFF_FLAG;
            f.dlc = 8;
            uint64_t raw = s.raw;
            for (int i = 0; i < 8; ++i)
                f.data[i] = (raw >> (8 * i)) & 0xFFu;
            return f;
        }

        inline bool from_frc_can_frame(const frc_can_frame &f, RobotState &out)
        {
            if (!f.id.flag_eff())
                return false;
            if (f.dlc != 8)
                return false;
            if ((f.id.raw & 0x1FFFFFFFu) != HEARTHBEAT_ID)
                return false;
            uint64_t raw = 0;
            for (int i = 0; i < 8; ++i)
                raw |= (uint64_t)f.data[i] << (8 * i);
            out.raw = raw;
            return true;
        }

        inline bool is_heartbeat(const frc_can_frame &f)
        {
            return ((f.id.raw & 0x1FFFFFFFu) == HEARTHBEAT_ID) && f.id.flag_eff() && (f.dlc == 8);
        }
    }
}
