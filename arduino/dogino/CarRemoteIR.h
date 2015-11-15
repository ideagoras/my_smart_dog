#ifndef CAR_REMOTE_IR_h
#define CAR_REMOTE_IR_h

#include "CarHandle.h"
#include <IRremote.h>

class CarRemoteIR
{
  public:
    CarRemoteIR();

    void setup();
    carhandle_direction_t readDirection();

  private:
    IRrecv irrecv;
    decode_results results;
};

#endif
