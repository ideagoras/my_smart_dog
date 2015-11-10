#ifndef SDMsgDriving_h
#define SDMsgDriving_h

#include "Arduino.h"
#include <ros.h>
#include <my_smart_dog/msgDriving.h>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>

#include <string.h>
#include "SDMsgLogger.h"

namespace my_smart_dog {

class SDMsgDriving
{
  public:
    SDMsgDriving()
    {
    }

    static SDMsgDriving *getInstance()
    {
      static SDMsgDriving instance;
      return &instance;
    }

    void init(ros::NodeHandle *nodeHandle, my_smart_dog::SDMsgLogger *logger)
    {
      _nodeHandle = nodeHandle;
      _logger = logger;

      _subscribeMsgDriving = new ros::Subscriber<my_smart_dog::msgDriving>("msgDriving", &SDMsgDriving::DrivingCallback);
      _nodeHandle->subscribe(*_subscribeMsgDriving);
    }

    void changeDirection(int direction)
    {

    }

    void changeSpeed(int speed)
    {

    }

  private:
    void msgDrivingCallback( const my_smart_dog::msgDriving& msgDriving) {
      String message;
      message += "v=";
      message += msgDriving.velocity;

      if (_logger != NULL) {
        _logger->write(message);
      }
    }
    static void DrivingCallback(const my_smart_dog::msgDriving& msgDriving) {
      SDMsgDriving::getInstance()->msgDrivingCallback(msgDriving);
    }
    
    ros::NodeHandle *_nodeHandle;
    ros::Subscriber<my_smart_dog::msgDriving> *_subscribeMsgDriving;
    SDMsgLogger *_logger;
};

};
#endif
