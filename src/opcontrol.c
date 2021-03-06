#include "main.h"
#include "chassis.h" // redundant, but ensures that the corresponding header file (chassis.h) is included
#include "claw.h"
#include "shoulder.h"
#include "elbow.h"
#include "homeshoulder.h"
#include "homeelbow.h"
#include "wrist.h"

int shoulderTarget = 45;
int elbowTarget = 90;
int MAX_OUT = 127;




void operatorControl() {
   int loopCount = 0; //just a loop counter
	 int power, turn, rR, lL, mM;
   int distanceToObject;
   int distanceToObject2 = 0;
   int distanceToObject3 = 0;

   while(1) {
       //drive base control
  power = joystickGetAnalog(1, 2); // vertical axis on left joystick
  turn  = joystickGetAnalog(1, 1); // horizontal axis on left joystick
  chassisSet(power + turn, power - turn);

			 // controll claw and wrist with CH4 of joystick
clawSet(joystickGetAnalog(1, 4));
wristSet(joystickGetAnalog(1, 3));

			// control shoulder motor with button 6U and 6D
if(joystickGetDigital(1, 6, JOY_UP)) {
  printf("The shoulder encoder value is %d\n", encoderGet(shoulderEncoder));
	shoulderSet(127); // pressing up, so shoulder should go up
  shoulderTarget = encoderGet(shoulderEncoder);
}
else if(joystickGetDigital(1, 6, JOY_DOWN)) {
  printf("The shoulder encoder value is %d\n", encoderGet(shoulderEncoder));
    shoulderSet(-127); // pressing down, so shoulder should go down
    shoulderTarget = encoderGet(shoulderEncoder);
	}
else {
  printf("The shoulder encoder value is %d\n", encoderGet(shoulderEncoder));
  shoulderHold(shoulderTarget);// no buttons are pressed, stop the shoulder
  }

// control elbow motor with button 5U and 5D
if(joystickGetDigital(1, 5, JOY_UP)) {
  printf("The elbow encoder value is %d\n", encoderGet(elbowEncoder));
  elbowSet(127); // pressing up, so elbow should go up
  elbowTarget = encoderGet(elbowEncoder);
  }
else if(joystickGetDigital(1, 5, JOY_DOWN)) {
  printf("The elbow encoder value is %d\n", encoderGet(elbowEncoder));
elbowSet(-127); // pressing down, so elbow should go down
elbowTarget = encoderGet(elbowEncoder);
  }
else{
  printf("The elbow encoder value is %d\n", encoderGet(elbowEncoder));
elbowSet(0); // no buttons pressed, stop the elbow
elbowHold(elbowTarget);
  }
loopCount = loopCount + 1 ;
printf("the loop is %d \n", loopCount);

if(joystickGetDigital(1, 8, JOY_UP)){
	homeShoulder(-200);
}

if(joystickGetDigital(1, 8, JOY_DOWN)){
  homeElbow(90);
}

if(joystickGetDigital(1, 8, JOY_RIGHT)) {
  distanceToObject = ultrasonicGet(frontSonar);

  printf("The distance to the object is %d \n", distanceToObject);

  if ((distanceToObject > 25) && (distanceToObject < 100)) {
    chassisSet(-50, 50);
  }
  else if (distanceToObject < 10 && distanceToObject > 0) {
    chassisSet(50, -50);
  }
  else if (distanceToObject > 100){
    //printf("distanceToObject");
    chassisSet(30, 30);
    delay (1000);
    int x = ultrasonicGet(frontSonar);
    printf("x value is %d \n", x);
    chassisSet(-30, -30);
    delay(1500);
    int y = ultrasonicGet(frontSonar);
    printf("y value is %d \n", y);

    if (x > y){
      chassisSet(60, 60);
    }
    if (y > x){
      chassisSet(-60, -60);
    }
    //else if (x < 1 && y < 1) {
      //chassisSet(30, 30);

    //}
    }
    else if  (distanceToObject < 0 && distanceToObject2 < 0 && distanceToObject3 < 0){
      chassisSet(30, 30);
      delay (1300);
      int x = ultrasonicGet(frontSonar);
      printf("x value is %d \n", x);
      chassisSet(-30, -30);
      delay(1500);
      int y = ultrasonicGet(frontSonar);
      printf("y value is %d \n", y);

      if (x > y){
        chassisSet(60, 60);
      }
      if (y > x){
        chassisSet(-60, -60);
      }
      //else if (x < 1 && y < 1) {
        //chassisSet(30, 30);

      //}
    }

  else{
    chassisSet(0, 0);
  }

}
distanceToObject2 = distanceToObject;
distanceToObject3 = distanceToObject2;




if(joystickGetDigital(1, 8, JOY_LEFT)){
  rR = analogReadCalibrated(1);
  lL = analogReadCalibrated(3);
  mM = analogReadCalibrated(2);

  printf("Line tracker values are L %d R %d M %d \n", lL, rR, mM);

  if (mM > 100 + rR && mM > 100 + lL){
    chassisSet(-20, 20);
    int finalCommand = 1;
  }
  else if (rR > 100 + mM && rR > 100 + lL){
    chassisSet(-25, -25);
    int finalCommand = 2;
  }
  else if (lL > 100 + mM && lL > 100 + rR){
    chassisSet(25, 25);
    int finalCommand = 3;
    }

  else{
    chassisSet(20, -20);
    }
}



delay(100);
     }
   }
