#ifndef SDMsgEcho_h
#define SDMsgEcho_h

#include "Arduino.h"
#include <ros.h>
#include <my_smart_dog/msgDriving.h>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>

#include <string.h>
#include "SDMsgLogger.h"

namespace my_smart_dog {

class SDMsgEcho
{
  public:
    SDMsgEcho()
    {
    }

     static SDMsgEcho *getInstance()
    {
      static SDMsgEcho instance;
      return &instance;
    }
    
    void init(ros::NodeHandle *nodeHandle, SDMsgLogger *logger)
    {
      _nodeHandle = nodeHandle;
      _logger = logger;

      _subscribeMsgDriving = new ros::Subscriber<my_smart_dog::msgDriving>("msgDriving", &SDMsgEcho::EchoCallback);
      _nodeHandle->subscribe(*_subscribeMsgDriving);
    }

  private:
    static void EchoCallback(const my_smart_dog::msgDriving& msgDriving) {
      SDMsgEcho::getInstance()->msgEchoCallback(msgDriving);
    }

    void msgEchoCallback( const my_smart_dog::msgDriving& msgDriving) {
      String message;
      message += "v=";
      message += msgDriving.velocity;

      if (_logger != NULL) {
        _logger->write(message);
      }
    }

    ros::NodeHandle *_nodeHandle;
    ros::Subscriber<my_smart_dog::msgDriving> *_subscribeMsgDriving;
    SDMsgLogger *_logger;
};

};
#endif
