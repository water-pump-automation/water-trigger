#ifndef __LISTENER_H__
#define __LISTENER_H__

typedef char *Message;

typedef struct _listener *Listener;

typedef void (*FlushCallback)(Message message);

typedef Message (*StartReceiving)();

/********************************************************************
 * Listener type constructor
 *
 * Outputs:
 *  - Listener
 ********************************************************************/
Listener NewListener(StartReceiving receiver, FlushCallback callback);

/********************************************************************
 * This function waits (sync) for a incoming signal and reply
 * Inputs:
 *  - Listener
 ********************************************************************/
void StartListening(Listener listener);

/********************************************************************
 * Listener type destructor
 *
 * Inputs:
 *  - Listener
 ********************************************************************/
void DestroyListener(Listener *listener);

#endif