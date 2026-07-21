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

class MCP2515
{
  public:
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

    ERROR sendMessage(const can_frame*)
    {
        return ERROR_OK;
    }
};
