#!/usr/bin/python3.8
from telnetlib import Telnet
import roslib; roslib.load_manifest('wsjs')
import rospy
import tf.transformations
from geometry_msgs.msg import Twist
x = 0
y = 0

tn = Telnet('192.168.1.1',23)

def callback(msg):
    rospy.loginfo("Received a /cmd_vel message!")
    rospy.loginfo("Linear Components: [%f, %f, %f]"%(msg.linear.x, msg.linear.y, msg.linear.z))
    rospy.loginfo("Angular Components: [%f, %f, %f]"%(msg.angular.x, msg.angular.y, msg.angular.z))
    x = msg.linear.x + 0.03
    y = msg.angular.z
    cats = bytes(str(str(int((x * 80) + 50)) + str(int(((-1 * y) * 80) + 50))), 'utf-8')
    cats2 = (str(str(int((x * 80) + 50)) + str(int((y * 80) + 50))))
    rospy.loginfo("cats = [%s]"%cats2)
    tn.write(cats)
    rospy.loginfo("Telnet interacting!:[%s]"%cats)
    

def listener():
    rospy.init_node('cmd_vel_listener')
    rospy.Subscriber("/input_joy/cmd_vel", Twist, callback)
    tn = Telnet('192.168.1.1',23)

    
    rospy.spin()

if __name__ == '__main__':
    listener()
