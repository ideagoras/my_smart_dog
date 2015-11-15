#include "CarRemoteIR.h"

int RECV_PIN = 11;

CarRemoteIR::CarRemoteIR(): irrecv(RECV_PIN)
{
}

void CarRemoteIR::setup()
{
  Serial.println("CarRemoteIR::setup");
  irrecv.enableIRIn(); // Start the receiver
}

carhandle_direction_t CarRemoteIR::readDirection()
{
  carhandle_direction_t result = CAR_HANDLE_NONE;
  if (irrecv.decode(&results)) {
    //Serial.println(results.value, HEX);

    switch (results.value) {
      case 0x3D9AE3F7: result = CAR_HANDLE_FORWARD; break;
      case 0x1BC0157B: result = CAR_HANDLE_BACK; break;
      case 0x8C22657B: result = CAR_HANDLE_LEFT; break;
      case 0x0449E79F: result = CAR_HANDLE_RIGHT; break;
      case 0x9716BE3F: result = CAR_SPEED_UP; break;
      case 0x6182021B: result = CAR_SPEED_DOWN; break;
      case 0x488F3CBB: result = CAR_SPEED_STOP; break;
    }
    irrecv.resume(); // Receive the next value
  }
  return result;
}
