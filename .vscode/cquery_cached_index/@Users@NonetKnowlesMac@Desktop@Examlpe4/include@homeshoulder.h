#ifndef _HOMESHOULDER_H_
#define _HOMESHOULDER_H_

#include "main.h"
#include "shoulder.h"
// Sets the speeds of the left and right wheels of the chassis


void homeShoulder(int homePosition) {
    printf("shoulder homing started, stand by \n");

while (digitalRead(3) == 1) { //while loops with condition lowerLimit == 1
  printf("The lowerLimit switch is \n");
  shoulderSet(60); //turn on shoulder in neg direction
}
    shoulderSet(0); // stop shoulder motor
    encoderReset(shoulderEncoder);


while (encoderGet(shoulderEncoder) > homePosition) {
  printf("The shoulder encoder is %d\n", encoderGet(shoulderEncoder));
  shoulderSet(-60);
}
 shoulderSet(0);



printf("shoulder homing complete \n");

}


#endif // _HOMESHOULDER_H_
