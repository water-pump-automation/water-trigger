#ifndef __WATER_TRIGGER_H__
#define __WATER_TRIGGER_H__

#include "sensor.h"

typedef struct _water_trigger
{
    Sensor sensor;
    char *topic;
    char *accessToken;
} WaterTrigger;

#endif