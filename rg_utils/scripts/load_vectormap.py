#! /usr/bin/python

import rospy
import actionlib
import numpy as np
import os
import sys
import nav_msgs.msg
import geometry_msgs.msg
from nav_msgs.msg import Path
from geometry_msgs.msg import PoseStamped, Pose



_FRAME_ID = 'map'

def vectormap_manager():    
    msg = Path()
    msg.header.frame_id = _FRAME_ID
    msg.header.stamp = rospy.Time.now()

    vectormap_pub=rospy.Publisher('/vectormap',Path,queue_size=10)

    flag = 0
    while not rospy.is_shutdown() and not flag:

        map_txt = open(_FILEPATH, 'r')
        for line in map_txt:
            if line == '\n':
                pass
            else:
                pose = PoseStamped()
                # line = map_txt.readline()
                # if not line:
                    # print('break')
                    # break
                values = line.split(',')
                # print(values[0])
                # print(values[1])
                pose.pose.position.x = float(values[0])
                pose.pose.position.y = float(values[1])
                pose.pose.position.z = 0.0
                pose.pose.orientation.x = 0.
                pose.pose.orientation.y = 0.
                pose.pose.orientation.z = 0.
                pose.pose.orientation.w = 1.
                msg.poses.append(pose)
                z = raw_input('next?')
                if z == "q":
                    rospy.signal_shutdown()
                    flag = 1
                vectormap_pub.publish(msg)
        map_txt.close()
        flag = 1



if __name__ == '__main__':
    _FILEPATH = raw_input('Filepath to vector map: ')
    rospy.init_node('vectormap_manager')
    vectormap_manager()
   # mains()
