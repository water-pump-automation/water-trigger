#include "usecases.h"

#include "trigger.h"
#include "reply.h"

#include "protocol.h"
#include "safe_memory.h"

#include <stdlib.h>
#include <pthread.h>

Trigger EchoReplyListenAsync()
{
    Trigger trigger = NewTrigger();
    if (trigger == NULL)
    {
        return NULL;
    }

    pthread_t reply_thread;
    pthread_create(&reply_thread, NULL, (void *(*)(void *))StartReceiving, trigger);
    pthread_detach(reply_thread);

    return trigger;
}
