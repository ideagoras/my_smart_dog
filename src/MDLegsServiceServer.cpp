#include "ros/ros.h"
#include "my_smart_dog/srvLegs.h"

#define PLUS		1
#define MINUS	2
#define MULTIPLICATION	3
#define DIVISION		4

int g_operator = PLUS;

bool calculation(my_smart_dog::srvLegs::Request &req, my_smart_dog::srvLegs::Response &res)
{
	switch (g_operator) {
		case PLUS:
			res.result = req.a + req.b;
		break;
		case MINUS:
			res.result = req.a - req.b;
		break;
		case MULTIPLICATION:
			res.result = req.a * req.b;
		break;
		case DIVISION:
			if (req.b == 0) {
				res.result = 0;
			} else {
				res.result = req.a / req.b;
			}
		break;
	}
	
	ROS_INFO("request:x=%ld y=%ld", (long int)req.a, (long int)req.b);
	ROS_INFO("sending back response:[%ld]", (long int)res.result);
	return true;
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "MDLegsServiceServer");
	ros::NodeHandle nodeHandle;

	nodeHandle.setParam("calculation_method", PLUS);
	ros::ServiceServer serviceServer = nodeHandle.advertiseService("srvLegs", calculation);

	ROS_INFO("ready srv server!");

	ros::Rate rate(10);
	while (1) {
		nodeHandle.getParam("calculation_method", g_operator);
		ros::spinOnce();
		rate.sleep();
	}
	
	return 0;
}