#ifndef __USECASES_H__
#define __USECASES_H__

#include "forward.h"
#include "boolean.h"
#include "water_trigger.h"

#include "connect.h"
#include "listener.h"

#define MAX_RETRY 3

/* Network connection */
WTGR_Bool ConnectToLocalNetwork(Input *input, Output *output, int retries);

/* ICMP reply */
Listener EchoReplyListenAsync();

/* Sensor actions */
WTGR_Bool DetectedWater(WaterTrigger *trigger);
WTGR_Bool WaitToRanOutOfWater(WaterTrigger *trigger);

#endif