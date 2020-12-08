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
	 int power, turn;

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




delay(20);
     }
   }
