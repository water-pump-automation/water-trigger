#include "usecases.h"
#include "connect.h"

#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

Bool ConnectToLocalNetwork(Input *input, Output *output)
{
    return Connect(MAX_RETRY, input, output);
}
