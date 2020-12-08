#ifndef _ELBOW_H_
#define _ELBOW_H_

#include "main.h"

int Kp = 1;


void elbowSet(int speed)
{ motorSet(5, speed); }


void elbowHold(int elbowTarget){

 printf("The elbow encoder value is %d\n", encoderGet(elbowEncoder));
 int counts = encoderGet(elbowEncoder);
 int error = elbowTarget - counts;
 elbowSet(Kp * error);
 }

#endif
