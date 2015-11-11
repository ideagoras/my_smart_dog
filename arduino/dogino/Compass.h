#ifndef COMPASS_h
#define COMPASS_h

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <Wire.h>
#include "HMC5883L.h"

struct CompassInfo
{
  float XAxis;
  float YAxis;
  float ZAxis;
  float headingDegrees;
  float fixedHeadingDegrees;
  float smoothHeadingDegrees;
};

class Compass
{
  public:
    void setup();
    void getCompassInfo(CompassInfo& compassInfo);

  private:

    HMC5883L compass;
    int previousDegree;
};

#endif

