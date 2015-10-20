#include "ros/ros.h"
#include "my_smart_dog/msgLegs.h"

void msgCallback(const my_smart_dog::msgLegs::ConstPtr& msg)
{
	ROS_INFO("receive msg: %d", msg->data);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "MDLegsSubscriber");
	ros::NodeHandle nodeHandle;

	ros::Subscriber subscriber = nodeHandle.subscribe("msgLegs", 10, msgCallback);
	ros::spin();

	return 0;
}