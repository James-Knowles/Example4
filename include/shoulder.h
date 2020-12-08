#ifndef _SHOULDER_H_
#define _SHOULDER_H_

#include "main.h"

int Kp = 1;

void shoulderSet(int speed)
{
   motorSet(4, speed);

}

void shoulderHold(int shoulderTarget){

 printf("The shoulder encoder value is %d\n", encoderGet(shoulderEncoder));
 int counts = encoderGet(shoulderEncoder);
 int error = shoulderTarget - counts;
 shoulderSet(Kp * error);
 }

#endif
