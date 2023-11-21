#include "water_trigger.h"
#include "listener.h"
#include "usecases.h"

#include <string.h>
#include <stdio.h>

int failed_to_create_echo()
{
    printf("**********\n");
    printf("FAILED TO CREATE ECHO\n");
    printf("**********\n");

    Input connectionParams;
    Output forwardParams;

    if (connected)
    {
        printf("CONNECTED\n");
        Sensor sensor = NewSensor();
        if (sensor == NULL)
        {
            printf("SENSOR EMTPY\n");
            return -1;
        }
        printf("SENSOR FULL\n");

        WaterTrigger wTrigger;
        wTrigger.sensor = sensor;
        wTrigger.topic = forwardParams.topic;
        wTrigger.accessToken = forwardParams.accessToken;

        Listener listener = NULL;
        if (listener == NULL)
        {
            DestroySensor(&sensor);
            printf("LISTENER EMPTY\n");
            printf("FINISHED\n");
            return -1;
        }
        printf("LISTENER FULL\n");

        if (wtgr_true == DetectedWater(&wTrigger))
        {
            printf("DETECTED WATER\n");
            WaitToRanOutOfWater(&wTrigger);
            printf("RAN OUT OF WATER\n");
        }

        memset(&wTrigger, 0x00, sizeof(WaterTrigger));
        DestroySensor(&sensor);
        DestroyListener(&listener);
        printf("DESTROY\n");
    }

    return 0;
}
