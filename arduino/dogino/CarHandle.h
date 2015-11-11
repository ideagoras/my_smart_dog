#ifndef CAR_HANDLE_h
#define CAR_HANDLE_h

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "DualMC33926MotorShield.h"

typedef enum {
  CAR_HANDLE_LEFT = 1,
  CAR_HANDLE_RIGHT = 2,
  CAR_HANDLE_FORWARD = 3,
  CAR_HANDLE_BACK = 4,
  CAR_SPEED_UP = 5,
  CAR_SPEED_DOWN = 6,
  CAR_SPEED_BOOST = 7,
  CAR_SPEED_STOP = 8,
} carhandle_direction_t;

class CarHandle
{
public:
  CarHandle() {
    spd = 0;
    offset = 5;
  }

  void setup();
  
  void forward();
  void back();
  void left();
  void right();
  void brake();
  void speedUp();
  void speedDown();
  
private:
  DualMC33926MotorShield motors;

  int spd;
  int offset;
};

#endif
