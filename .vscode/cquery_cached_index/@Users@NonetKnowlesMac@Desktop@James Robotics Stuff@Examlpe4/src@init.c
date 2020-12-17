

#include "main.h"



void initializeIO() {
  pinMode(LIMIT_SWITCH, 3);
  pinMode(LIMIT_SWITCH, 4);

}


void initialize() {
  shoulderEncoder = encoderInit(QUAD_TOP_PORT, QUAD_BOTTOM_PORT, true);
  elbowEncoder = encoderInit(QUAD_TOP_PORT_2, QUAD_BOTTOM_PORT_2, true);
  frontSonar = ultrasonicInit(7, 8);
  analogCalibrate(1);
  analogCalibrate(2);
  analogCalibrate(3);

  }
