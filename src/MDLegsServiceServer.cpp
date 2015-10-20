#include "ros/ros.h"
#include "my_smart_dog/srvLegs.h"

bool calculation(my_smart_dog::srvLegs::Request &req, my_smart_dog::srvLegs::Response &res)
{
	res.result = req.a + req.b;

	ROS_INFO("request:x=%ld y=%ld", (long int)req.a, (long int)req.b);
	ROS_INFO("sending back response:[%ld]", (long int)res.result);
	return true;
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "MDLegsServiceServer");
	ros::NodeHandle nodeHandle;

	ros::ServiceServer serviceServer = nodeHandle.advertiseService("srvLegs", calculation);

	ROS_INFO("ready srv server!");

	ros::spin();

	return 0;
}