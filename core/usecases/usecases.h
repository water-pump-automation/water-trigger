#ifndef __USECASES_H__
#define __USECASES_H__

#include "forward.h"
#include "bool.h"
#include "water_trigger.h"

#include "trigger.h"
#include "connect.h"

#define MAX_RETRY 3

Bool ConnectToLocalNetwork(Input *input, Output *output);

Trigger EchoReplyListenAsync();

Bool DetectedWater(WaterTrigger *trigger);
Bool WaitToRanOutOfWater(WaterTrigger *trigger);

#endif