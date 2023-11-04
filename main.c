#include "water_trigger.h"
#include "connect_to_network.h"

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

        Trigger echo = EchoReplyListenAsync();

        while (OK)
        {
            if (DetectedWater(wTrigger))
            {
                WaitToRanOutOfWater(wTrigger);
            }
        }

        DestroySensor(&sensor);
        memset(&wTrigger, 0x00, sizeof(WaterTrigger));

        DestroyTrigger(echo);
    }
}
