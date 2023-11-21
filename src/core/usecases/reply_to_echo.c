#include "usecases.h"

#include "trigger.h"
#include "listener.h"
#include "mock_protocol.h"

#include <stdlib.h>
#include <pthread.h>

Listener EchoReplyListenAsync()
{
    Listener listener = NewMockListener();
    if (listener == NULL)
    {
        return NULL;
    }

    pthread_t reply_thread;
    pthread_create(&reply_thread, NULL, (void *(*)(void *))StartListening, listener);
    pthread_detach(reply_thread);

    return listener;
}
