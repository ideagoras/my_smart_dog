#ifndef SDMsgLogger_h
#define SDMsgLogger_h

#include "Arduino.h"
#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>

#include <string.h>

namespace my_smart_dog {

class SDMsgLogger
{
  public:
    SDMsgLogger()
    {
    }

    void init(ros::NodeHandle *nodeHandle)
    {
      _nodeHandle = nodeHandle;

      std_msgs::String str_msg;
      _logger = new ros::Publisher("logger", &str_msg);
      _nodeHandle->advertise(*_logger);
    }

    void write(String &message)
    {
      std_msgs::String log;
      log.data = message.c_str();
      _logger->publish(&log);
    }


  private:
    ros::NodeHandle *_nodeHandle;
    ros::Publisher *_logger;

};

};
#endif
