#ifndef _CHASSIS_H_
#define _CHASSIS_H_

#include "main.h"
// Sets the speeds of the left and right wheels of the chassis

void chassisSet(int left, int right) {
  motorSet(2, left);
  motorSet(3, right);
  printf("right motor speed %d /n", right);
  printf("left motor speed %d /n", left);
}

#endif // _CHASSIS_H_
