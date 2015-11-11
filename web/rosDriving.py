import logging
import roslib; roslib.load_manifest('my_smart_dog')
import rospy
import sys
from my_smart_dog.srv import *
from my_smart_dog.msg import *
from std_msgs.msg import String

def changeDirection(direction):
	logging.debug('changeDirection: %s' % direction)
	#add_two_ints_client(4, 5)
	#sendEcho()
	directionNumber = 0
	if "left" == direction:
		directionNumber = 1
	elif "right" == direction:
		directionNumber = 2
	elif "up" == direction:
		directionNumber = 3
	elif "down" == direction:
		directionNumber = 2
	elif "stop" == direction:
		directionNumber = 0

	sendDirection(directionNumber)
	return

def sendDirection(direction):
	try:
		publisher = rospy.Publisher('msgDriving', msgDriving, queue_size=10)
		rospy.init_node('ros_driving_node')
		msg = msgDriving()
		msg.direction = direction;
		msg.velocity = -1;
		publisher.publish(msg)
		logging.debug('success send')
	except rospy.ServiceException, e:
		print "Service call failed: %s"% e
	return

def sendEcho():
	try:
		publisher = rospy.Publisher('my_smart_dog_echo', String, queue_size=10)
		rospy.init_node('ros_driving_node')
		publisher.publish("hello echo")
		logging.debug('success send')
	except rospy.ServiceException, e:
		print "Service call failed: %s"% e
	return

def add_two_ints_client(x, y):
    #rospy.wait_for_service('add_two_ints')
    try:
        add_two_ints = rospy.ServiceProxy('add_two_ints', srvLegs)
        resp1 = add_two_ints(x, y)
        logging.debug('add two result: %d' % resp1.result)
        return resp1.result
    except rospy.ServiceException, e:
    		print "Service call failed: %s"% e


def changeSpeed(speed):
	logging.debug('changeSpeed: %s' % speed)
	
	return

if __name__ == "__main__":
	logging.basicConfig(level=logging.DEBUG)
	changeDirection('left')
	changeSpeed(100)