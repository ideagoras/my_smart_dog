#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#include <ros.h>
#include <my_smart_dog/msgDriving.h>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>

#include <string.h>

void msgDrivingCallback( const my_smart_dog::msgDriving& msgDriving);
void echoCallback( const std_msgs::String& message);

ros::NodeHandle  nodeHandle;
ros::Subscriber<my_smart_dog::msgDriving> subscribeMsgDriving("msgDriving", msgDrivingCallback );
ros::Subscriber<std_msgs::String> subscribeEcho("my_smart_dog_echo", echoCallback );

std_msgs::String str_msg;
ros::Publisher logger("logger", &str_msg);

char hello[] = "hello my_smart_dog world!";

void msgDrivingCallback( const my_smart_dog::msgDriving& msgDriving) {
  char buffer[52];
//  sprintf(buffer, "d=%d v=%d .", msgDriving.direction, msgDriving.velocity);
  sprintf(buffer, "v=%d d=%d.", msgDriving.velocity, msgDriving.direction);
  
  std_msgs::String log;
  log.data = buffer;
  logger.publish( &log );
  
  //  digitalWrite(13, HIGH-digitalRead(13));   // blink the led
}

void echoCallback( const std_msgs::String& message) {
  
//  std_msgs::String log;
//  log.data = "echoCallback";
//  logger.publish( &log );
  logger.publish( &message );
//  str_msg.data = message.data;
}

void setup()
{
  //  pinMode(13, OUTPUT);
  nodeHandle.initNode();
  nodeHandle.advertise(logger);
  nodeHandle.subscribe(subscribeMsgDriving);
  nodeHandle.subscribe(subscribeEcho);
}

void loop()
{
  str_msg.data = hello;
  logger.publish( &str_msg );
  nodeHandle.spinOnce();
  delay(3000);
}
