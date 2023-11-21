#include "usecases.h"
#include "connect.h"

#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

WTGR_Bool ConnectToLocalNetwork(Input *input, Output *output)
{
    return (WTGR_Bool) Connect(MAX_RETRY, input, output);
}
