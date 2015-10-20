#include "ros/ros.h"
#include "my_smart_dog/msgLegs.h"

int main(int argc, char **argv)
{
	ros::init(argc, argv, "MDLegsPublisher");
	ros::NodeHandle nodeHandle;

	ros::Publisher publisher = nodeHandle.advertise<my_smart_dog::msgLegs>("msgLegs", 100);

	ros::Rate loopRate(10);
	int count = 0;

	while (ros::ok()) {
		my_smart_dog::msgLegs msg;
		msg.data = count;
		ROS_INFO("send msg=%d", count);

		publisher.publish(msg);

		loopRate.sleep();
		++count;
	}

	return 0;
}