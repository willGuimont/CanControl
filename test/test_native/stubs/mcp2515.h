#pragma once

#include "can.h"

enum CAN_SPEED
{
    CAN_1000KBPS,
};

enum CAN_CLOCK
{
    MCP_8MHZ,
    MCP_16MHZ,
    MCP_20MHZ,
};

struct MCP2515
{
    enum ERROR
    {
        ERROR_OK        = 0,
        ERROR_FAIL      = 1,
        ERROR_ALLTXBUSY = 2,
        ERROR_FAILINIT  = 3,
        ERROR_FAILTX    = 4,
        ERROR_NOMSG     = 5,
    };

    ERROR reset()
    {
        return ERROR_OK;
    }

    ERROR setBitrate(CAN_SPEED, CAN_CLOCK)
    {
        return ERROR_OK;
    }

    ERROR setNormalOneShotMode()
    {
        return ERROR_OK;
    }

    ERROR sendMessage(const can_frame* frame)
    {
        ++send_attempts;
        last_frame = *frame;
        return send_result;
    }

    can_frame last_frame{};
    unsigned  send_attempts = 0;
    ERROR     send_result   = ERROR_OK;
};
