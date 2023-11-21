#include "usecases.h"

#include <stdlib.h>

void _deactivate_sensor(Sensor sensor)
{
    if (sensor != NULL)
    {
        DeactivateSensor(sensor);
    }
}

WTGR_Bool WaitToRanOutOfWater(WaterTrigger *trigger)
{
    if (trigger != NULL)
    {
        SensorDetect(trigger->sensor, (StageTrigger)_deactivate_sensor);
        Forward(trigger->topic, trigger->accessToken, NOK);
        return wtgr_true;
    }
}
