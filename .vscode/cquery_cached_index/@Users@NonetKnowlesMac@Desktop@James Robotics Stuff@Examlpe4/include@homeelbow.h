#ifndef _HOMEELBOW_H_
#define _HOMEELBOW_H_

#include "main.h"
#include "elbow.h"
// Sets the speeds of the left and right wheels of the chassis


void homeElbow(int homePosition) {
printf("elbow homing started, stand by \n");

while (digitalRead(4) == 1) { //while loops with condition lowerLimit == 1
  printf("The elbow encoder is %d\n", encoderGet(elbowEncoder));
  elbowSet(-60); //turn on shoulder in neg direction
}
    elbowSet(0); // stop shoulder motor
    encoderReset(elbowEncoder);


while (encoderGet(elbowEncoder) < homePosition) {

  elbowSet(60);
}
 elbowSet(0);



printf("elbow homing complete \n");

}

#endif // _HOMEELBOW_H_
