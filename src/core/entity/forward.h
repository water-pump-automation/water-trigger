#ifndef __FORWARD_H__
#define __FORWARD_H__

#include <stdint.h>

typedef uint8_t Signal;

#define OK 1
#define NOK 0

void Forward(char *topic, char *accessToken, Signal signal);

#endif