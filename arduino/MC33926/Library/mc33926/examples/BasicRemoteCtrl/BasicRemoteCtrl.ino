/* 
 * Sketch of Basic Remote Cotroll Rover-5 with Dual MC33926 Motor
 * Driver Shield.
 * This example code doesn't contain any fault process or current
 * sensing.
 *                                  2015. 09. 24. GroundZero
 *                           http://blog.naver.com/thumbdown 
 */

#include "DualMC33926MotorShield.h"

DualMC33926MotorShield motors;

int spd = 0;  int offset = 5;
// int spd_L, int spd_R;

void setup()
{
  motors.init();
  //for( int i=7; i<=10; i++ ) pinMode( i, OUTPUT );
  Serial.begin(115200);
  Serial.println("basic control rover5 & mc33926 mobile base");
  forward();
}

void forward()
{
  delay(2);
  motors.setSpeeds(spd, spd);
  digitalWrite( 8, 1 );  digitalWrite( 7, 0 );
}

void back()
{
  delay(2);
  motors.setSpeeds(spd, spd);
  digitalWrite( 8, 0 );  digitalWrite( 7, 1 );
}

void left()
{
  delay(2);
  motors.setSpeeds(spd, spd);
  digitalWrite( 8, 1 );  digitalWrite( 7, 1 );
}

void right()
{
  delay(2);
  motors.setSpeeds(spd, spd);
  digitalWrite( 8, 0 ); // left
  digitalWrite( 7, 0 ); // right
}

void speedUp()
{
  if( spd < 400 )  spd = spd + offset;
  else             spd = 400;
  OCR1A = OCR1B = spd;
}

void speedDown()
{
  if( spd > 0 )  spd = spd - offset;
  else           spd = 0;
  OCR1A = OCR1B = spd;
}

void brake()
{  motors.setSpeeds( 0, 0 );  }

void loop()
{
  if (Serial.available() > 0)
  {
    char ch = Serial.read();
    if( ch == 224 )   ch = Serial.read();  // Extended ASCII Detect            

    switch( ch )
    {
      case( 65 ):     //  '↑' key detect
        forward();    Serial.println("forward    ");     break;
          
      case( 66 ):     //  '↓' key detect
        back();       Serial.println("back       ");     break;
           
      case( 67 ):     //  '→' key detect
        right();      Serial.println("turn right ");     break;
        
      case( 68 ):     //  '←' key detect
        left();       Serial.println("turn left  ");     break;
        
      case( 'q' ):
        brake();      Serial.println("stop       ");     break;
        
      case( '.' ):
        speedUp();    Serial.print("speed up  ");
                      Serial.println(spd);               break;
      case( ',' ):
        speedDown();  Serial.print("speed down ");
                      Serial.println(spd);               break;
                      
      default:                                            break;
    }
  }
  else;
}
