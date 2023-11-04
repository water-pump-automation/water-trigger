#ifndef __FORWARD_H__
#define __FORWARD_H__

typedef int Signal;

#define OK 1
#define NOK 0

void Forward(char *topic, char *accessToken, Signal signal);

#endif