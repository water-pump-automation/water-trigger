#ifndef __CONNECT_H__
#define __CONNECT_H__

typedef char *String;
typedef enum _bool
{
    not_connected = 0,
    connected
} Conn;

typedef struct _input
{
    String connectionAddress;
    String contextName;
    String groupName;
} Input;

typedef struct _output
{
    String topic;
    String accessToken;
} Output;

Conn Connect(int retries, Input *input, Output *output);

#endif