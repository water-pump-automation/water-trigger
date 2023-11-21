#include "water_trigger.h"
#include "listener.h"
#include "usecases.h"

#include <string.h>

int main()
{
    Input connectionParams;
    Output forwardParams;

    if (ConnectToLocalNetwork(&connectionParams, &forwardParams))
    {
        Sensor sensor = NewSensor();
        if (sensor == NULL)
        {
            return -1;
        }

        WaterTrigger wTrigger;
        wTrigger.sensor = sensor;
        wTrigger.topic = forwardParams.topic;
        wTrigger.accessToken = forwardParams.accessToken;

        Listener listener = EchoReplyListenAsync();
        if (listener == NULL)
        {
            DestroySensor(&sensor);
            return -1;
        }

        while (OK)
        {
            if (DetectedWater(&wTrigger))
            {
                WaitToRanOutOfWater(&wTrigger);
            }
        }

        memset(&wTrigger, 0x00, sizeof(WaterTrigger));
        DestroySensor(&sensor);
        DestroyListener(&listener);
    }

    return 0;
}
