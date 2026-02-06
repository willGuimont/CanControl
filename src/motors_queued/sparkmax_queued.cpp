#include "motors_queued/sparkmax_queued.h"

namespace CanControl
{
    SparkMaxQueued::SparkMaxQueued(CanController& controller, uint8_t device_id)
        : SparkMax(controller.get_mcp(), device_id), can_controller_(&controller)
    {
        can_controller_->add_periodic_sender(this);
    }

    MCP2515::ERROR SparkMaxQueued::dispatch_frame(const LowLevel::SparkMax::spark_can_frame& frame, bool periodic)
    {
        struct can_frame out{};
        LowLevel::basic_to_can_frame(frame, &out);

        if (periodic)
        {
            periodic_frame_     = out;
            has_periodic_frame_ = true;
            last_update_ms_     = millis();
            return MCP2515::ERROR_OK;
        }

        if (can_controller_->queue_frame(out))
        {
            return MCP2515::ERROR_OK;
        }
        else
        {
            return MCP2515::ERROR_FAILTX;
        }
    }

    bool SparkMaxQueued::send_periodic(MCP2515& mcp)
    {
        if (!has_periodic_frame_)
            return false;

        // Check timeout
        if (millis() - last_update_ms_ > SAFETY_TIMEOUT_MS)
        {
            // Timeout: Stop sending
            return false;
        }

        MCP2515::ERROR res = mcp.sendMessage(&periodic_frame_);
        if (res != MCP2515::ERROR_OK)
        {
            Serial.print("SparkMaxQueued periodic send failed (can_id=0x");
            Serial.print(periodic_frame_.can_id, HEX);
            Serial.print(") err=");
            Serial.print((int)res);
            Serial.print(" ");
            switch (res)
            {
            case MCP2515::ERROR_FAIL:
                Serial.print("ERROR_FAIL");
                break;
            case MCP2515::ERROR_ALLTXBUSY:
                Serial.print("ERROR_ALLTXBUSY");
                break;
            case MCP2515::ERROR_FAILINIT:
                Serial.print("ERROR_FAILINIT");
                break;
            case MCP2515::ERROR_FAILTX:
                Serial.print("ERROR_FAILTX");
                break;
            case MCP2515::ERROR_NOMSG:
                Serial.print("ERROR_NOMSG");
                break;
            default:
                Serial.print("ERROR_UNKNOWN");
                break;
            }
            Serial.println();

            // Extra MCP2515 diagnostics to help debug physical bus issues
            Serial.print("  MCP EFLG=0x");
            Serial.println(mcp.getErrorFlags(), HEX);
            Serial.print("  TEC=");
            Serial.println(mcp.errorCountTX());
            Serial.print("  REC=");
            Serial.println(mcp.errorCountRX());
            Serial.print("  STATUS=0x");
            Serial.println(mcp.getStatus(), HEX);

            return false;
        }
        else
        {
            // Optional: indicate periodic frame sent for debugging
            // Serial.print("SparkMaxQueued periodic sent (can_id=0x");
            // Serial.print(periodic_frame_.can_id, HEX);
            // Serial.println(")");
        }

        return true;
    }

} // namespace CanControl
