#include "usecases.h"
#include "connect.h"

#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

WTGR_Bool ConnectToLocalNetwork(Input *input, Output *output, int retries)
{
    return (WTGR_Bool) Connect(retries, input, output);
}
