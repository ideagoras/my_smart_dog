#include "ros/ros.h"
#include "my_smart_dog/srvLegs.h"
#include <cstdlib>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "MDLegsServiceClient");

	if (argc != 3) {
		ROS_INFO("cmd : rosrun my_smart_dog MDLegsServiceClient arg0 arg1");
		ROS_INFO("arg0: double number, arg1: double number");
		return 1;
	}

	ros::NodeHandle nodeHandle;
	ros::ServiceClient serviceClient = nodeHandle.serviceClient<my_smart_dog::srvLegs>("srvLegs");
	my_smart_dog::srvLegs srv;

	srv.request.a = atoll(argv[1]);
	srv.request.b = atoll(argv[2]);
	
	if (serviceClient.call(srv)) {
		ROS_INFO("send srv, srv.Request.a and b: %ld, %ld", (long int)srv.request.a, (long int)srv.request.b);
		ROS_INFO("receive srv, srv.Response.result: %ld", (long int)srv.response.result);

	} else {
		ROS_ERROR("Fail");
		return 1;
	}

	return 0;
}