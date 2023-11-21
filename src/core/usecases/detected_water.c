#include "usecases.h"

#include <stdlib.h>

void _activate_sensor(Sensor sensor)
{
    if (sensor != NULL)
    {
        ActivateSensor(sensor);
    }
}

WTGR_Bool DetectedWater(WaterTrigger *trigger)
{
    if (trigger != NULL)
    {
        SensorDetect(trigger->sensor, (StageTrigger)_activate_sensor);
        Forward(trigger->topic, trigger->accessToken, OK);
        return wtgr_true;
    }
}
