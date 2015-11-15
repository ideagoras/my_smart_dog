#include <Arduino.h>

#include <ros.h>
#include <my_smart_dog/msgDriving.h>
#include <my_smart_dog/msgDrivingInfo.h>

#include <std_msgs/String.h>
#include <std_msgs/Empty.h>

#include <string.h>
#include "DualMC33926MotorShield.h"
#include "HMC5883L.h"

//#include "Compass.h"
#include "CarHandle.h"

void msgDrivingCallback( const my_smart_dog::msgDriving& msgDriving);
void echoCallback( const std_msgs::String& message);

ros::NodeHandle  nodeHandle;
ros::Subscriber<my_smart_dog::msgDriving> subscribeMsgDriving("msgDriving", msgDrivingCallback );
//ros::Subscriber<std_msgs::String> subscribeEcho("my_smart_dog_echo", echoCallback );

//std_msgs::String str_msg;
//ros::Publisher logger("logger", &str_msg);

//my_smart_dog::msgDrivingInfo msgDrivingInfo;
//ros::Publisher msgDrivingInfoPublisher("msgDrivingInfoPublisher", &msgDrivingInfo);

//Compass compass;
CarHandle carHandle;

void msgDrivingCallback( const my_smart_dog::msgDriving& msgDriving) {

  //String message;
  //message += " d=";
  //message += msgDriving.direction;

  //std_msgs::String log;
  //log.data = message.c_str();
  //logger.publish(&log);

  switch ( msgDriving.direction )
  {
    case CAR_HANDLE_FORWARD:
      carHandle.forward();
      break;

    case CAR_HANDLE_BACK:
      carHandle.back();
      break;

    case CAR_HANDLE_RIGHT:
      carHandle.right();
      break;

    case CAR_HANDLE_LEFT:
      carHandle.left();
      break;

    case CAR_SPEED_STOP:
      carHandle.brake();
      break;

    case CAR_SPEED_UP:
      carHandle.speedUp();
      break;
    case ( ',' ):
      carHandle.speedDown();
      break;

    default:
      break;
  }
}

void echoCallback( const std_msgs::String& message) {

  //logger.publish( &message );
}

void setup()
{
  //  pinMode(13, OUTPUT);
  nodeHandle.initNode();
  //nodeHandle.advertise(logger);
  //nodeHandle.advertise(msgDrivingInfoPublisher);
  nodeHandle.subscribe(subscribeMsgDriving);
  //nodeHandle.subscribe(subscribeEcho);

//  compass.setup();
  carHandle.setup();
}

void loop()
{
/*
  CompassInfo compassInfo;
  compass.getCompassInfo(compassInfo);

  my_smart_dog::msgDrivingInfo msgDrivingInfo;
  msgDrivingInfo.XAxis = compassInfo.XAxis;
  msgDrivingInfo.YAxis = compassInfo.YAxis;
  msgDrivingInfo.ZAxis = compassInfo.ZAxis;
  msgDrivingInfo.headingDegrees = compassInfo.headingDegrees;
  msgDrivingInfo.fixedHeadingDegrees = compassInfo.fixedHeadingDegrees;
  msgDrivingInfo.smoothHeadingDegrees = compassInfo.smoothHeadingDegrees;

  msgDrivingInfoPublisher.publish(&msgDrivingInfo);
*/
  nodeHandle.spinOnce();
  delay(30);
}

