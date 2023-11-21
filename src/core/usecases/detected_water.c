#include "usecases.h"

#include <stdlib.h>

void _activate_sensor(WaterTrigger *trigger)
{
    if (sensor != NULL)
    {
        ActivateSensor(trigger->sensor);
        Forward(trigger->topic, trigger->accessToken, OK);
    }
}

Bool DetectedWater(WaterTrigger *trigger)
{
    if (trigger != NULL)
    {
        SensorDetect(trigger->sensor, (StageTrigger)_activate_sensor);
        return true;
    }
}
