#ifndef __MOCK_PROTOCOL_H__
#define __MOCK_PROTOCOL_H__

#include "listener.h"

#define NewMockListener() NewListener(&MockStartReceiving, &MockFlush)

/********************************************************************
 * This function receives a message and forwards to Listener
 *
 * Outputs:
 *  - Message
 ********************************************************************/
Message MockStartReceiving();

/********************************************************************
 * This function flushes a message to an output
 *
 * Inputs:
 *  - Message
 ********************************************************************/
void MockFlush(Message message);

#endif