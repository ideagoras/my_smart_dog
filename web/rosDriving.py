import logging
import roslib; roslib.load_manifest('my_smart_dog')
import rospy
import sys
from my_smart_dog.srv import *
from my_smart_dog.msg import *

def changeDirection(direction):
	logging.debug('changeDirection: %s' % direction)
	add_two_ints_client(4, 5)
	return

def add_two_ints_client(x, y):
    rospy.wait_for_service('add_two_ints')
    try:
        add_two_ints = rospy.ServiceProxy('add_two_ints', srvLegs)
        resp1 = add_two_ints(x, y)
        return resp1.result
    except rospy.ServiceException, e:
        print "Service call failed: %s"%e


def changeSpeed(speed):
	logging.debug('changeSpeed: %s' % speed)
	
	return

if __name__ == "__main__":
	logging.basicConfig(level=logging.DEBUG)
	changeDirection('left')
	changeSpeed(100)