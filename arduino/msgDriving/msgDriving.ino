#include "SDMsgDriving.h"

#include "SDMsgLogger.h"
#include "SDMsgDriving.h"
#include "SDMsgEcho.h"

ros::NodeHandle  nodeHandle;
my_smart_dog::SDMsgLogger logger;
my_smart_dog::SDMsgDriving msgDriving;
my_smart_dog::SDMsgEcho msgEcho;

void setup()
{
  //  pinMode(13, OUTPUT);
  nodeHandle.initNode();
  
  logger.init(&nodeHandle);
  msgDriving.getInstance()->init(&nodeHandle, &logger);
  msgEcho.getInstance()->init(&nodeHandle, &logger);
}

void loop()
{
  nodeHandle.spinOnce();
  delay(3000);
}

