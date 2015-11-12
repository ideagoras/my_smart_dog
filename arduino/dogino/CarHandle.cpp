#include "CarHandle.h"


void CarHandle::setup()
{
  motors.init();
  forward();
}

void CarHandle::forward()
{
  delay(2);
  motors.setSpeeds(spd, spd);
  digitalWrite( 8, 1 );  digitalWrite( 7, 0 );
}

void CarHandle::back()
{
  delay(2);
  motors.setSpeeds(spd, spd);
  digitalWrite( 8, 0 );  digitalWrite( 7, 1 );
}

void CarHandle::left()
{
  delay(2);
  motors.setSpeeds(spd, spd);
  digitalWrite( 8, 1 );  digitalWrite( 7, 1 );
}

void CarHandle::right()
{
  delay(2);
  motors.setSpeeds(spd, spd);
  digitalWrite( 8, 0 ); // left
  digitalWrite( 7, 0 ); // right
}

void CarHandle::speedUp()
{
  if( spd < 400 )  spd = spd + offset;
  else             spd = 400;
  OCR1A = OCR1B = spd;
}

void CarHandle::speedDown()
{
  if( spd > 0 )  spd = spd - offset;
  else           spd = 0;
  OCR1A = OCR1B = spd;
}

void CarHandle::brake()
{  motors.setSpeeds( 0, 0 );  }
