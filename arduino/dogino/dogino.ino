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

char hello[64] = "hello my_smart_dog world!";

void msgDrivingCallback( const my_smart_dog::msgDriving& msgDriving) {
  //  std_msgs::String log;
  //
  //  char buffer[52];
  //  sprintf(buffer, "v=%d", msgDriving.velocity);
  //  log.data = buffer;
  //  logger.publish( &log );
  //
  //  sprintf(buffer, "d=%d", msgDriving.direction);
  //  log.data = buffer;
  //  logger.publish( &log );

  String message;
  message += "v=";
  message += msgDriving.velocity;

  std_msgs::String log;
  log.data = message.c_str();
  logger.publish(&log);
}

void echoCallback( const std_msgs::String& message) {

  logger.publish( &message );
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
  nodeHandle.spinOnce();
  delay(3000);
}
