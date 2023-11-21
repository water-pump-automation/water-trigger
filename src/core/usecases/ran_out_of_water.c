#include "usecases.h"

#include <stdlib.h>

void _deactivate_sensor(WaterTrigger *trigger)
{
    if (sensor != NULL)
    {
        DeactivateSensor(trigger->sensor);
        Forward(trigger->topic, trigger->accessToken, NOK);
    }
}

Bool WaitToRanOutOfWater(WaterTrigger *trigger)
{
    if (trigger != NULL)
    {
        SensorDetect(trigger->sensor, (StageTrigger)_deactivate_sensor);
        return true;
    }
}
