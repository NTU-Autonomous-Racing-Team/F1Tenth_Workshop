#! /usr/bin/env python

import rclpy

from rclpy.node import Node

from geometry_msgs.msg import Point, Twist
from sensor_msgs.msg import LaserScan
from nav_msgs.msg import Odometry
from tf import transformations
from gazebo_msgs.msg import ModelState
from gazebo_msgs.srv import SetModelState

import math

yaw_ = 0
yaw_error_allowed_ = 5 * (math.pi / 180)  # 5 degrees
position_ = Point()
initial_position_ = Point()
initial_position_.x = 0.0
initial_position_.y = 0.0
initial_position_.z = 0.0
desired_position_ = Point()
desired_position_.x = 5.0
desired_position_.y = 0.0
desired_position_.z = 0.0
regions_ = None


class Bug0(Node):

    def __init__(self):
        super().__init__("bug0")

        self.sub_scan = self.create_subscription(
            LaserScan, "scan", self.scan_callback, 1
        )

        self.sub_odom = self.create_subscription(
            Odometry, "ego_racecar/odom", self.odom_callback, 1
        )

        self.pub_drive = self.create_publisher(Twist, "cmd_vel", 1)

        frequency = 50  # Hz
        timer_period = 1 / frequency  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0

    def normalize_angle(self, angle):
        if math.fabs(angle) > math.pi:
            angle = angle - (2 * math.pi * angle) / (math.fabs(angle))
        return angle

    def Pythagoras(self, x1, x2, y1, y2):
        return math.sqrt(((x1 - x2) ** 2 + (y1 - y2) ** 2))

    def follow_wall(self, regions):
        d = 0.4
        twist_msg = Twist()
        twist_msg.linear.x = 0
        twist_msg.angular.z = 0
        if (
            regions["front"] < d
            or regions["fright"] < d
            or regions["fleft"]
            or regions["left"]
        ):
            twist_msg.angular.z = 0.5
            return twist_msg
        elif regions["bleft"] < d or regions["back"] < d or regions["bright"]:
            twist_msg.angular.z = -0.5
            return twist_msg
        elif regions["right"] < d:
            twist_msg.linear.x = 0
            twist_msg.linear.x = 0.3
            return twist_msg
        else:
            twist_msg.linear.x = 0
            twist_msg.angular.z = 0
            return twist_msg

    def go_to_point(self, goal, position, err_yaw):
        goal_precision = 0.2
        twist_msg = Twist()
        dist = self.Pythagoras(goal.x, position.x, goal.y, position_.y)
        twist_msg.linear.x = 0
        twist_msg.angular.z = 0
        if math.fabs(err_yaw) > yaw_error_allowed_:
            twist_msg.angular.z = 0.4 if err_yaw > 0 else -0.4
            # rospy.loginfo("Turning")
        elif dist > goal_precision:
            twist_msg.linear.x = 0.3
            twist_msg.angular.z = 0.2 if err_yaw > 0 else -0.2
            # rospy.loginfo("Going straight")
        return twist_msg

    def odom_callback(self, msg):
        global position_, yaw_

        # position
        position_ = msg.pose.pose.position

        # yaw
        quaternion = (
            msg.pose.pose.orientation.x,
            msg.pose.pose.orientation.y,
            msg.pose.pose.orientation.z,
            msg.pose.pose.orientation.w,
        )
        euler = transformations.euler_from_quaternion(quaternion)
        yaw_ = euler[2]

    def scan_callback(msg):
        global regions_
        regions_ = {
            "front": min(min(msg.ranges[0:22] + msg.ranges[337:359]), 10),
            "fleft": min(min(msg.ranges[22:67]), 10),
            "left": min(min(msg.ranges[67:112]), 10),
            "bleft": min(min(msg.ranges[112:157]), 10),
            "back": min(min(msg.ranges[157:202]), 10),
            "bright": min(min(msg.ranges[202:247]), 10),
            "right": min(min(msg.ranges[247:292]), 10),
            "fright": min(min(msg.ranges[292:337]), 10),
        }

    def timer_callback(self):

        min_dist_from_wall = 0.4

        desired_yaw = math.atan2(
            desired_position_.y - position_.y, desired_position_.x - position_.x
        )
        err_yaw = self.normalize_angle(desired_yaw - yaw_)

        if (
            regions_["front"] > min_dist_from_wall
            and regions_["right"] > min_dist_from_wall
            and regions_["fright"] > min_dist_from_wall
        ):
            cmd_vel = self.go_to_point(desired_position_, position_, err_yaw)
        else:
            cmd_vel = self.follow_wall(regions_)

        self.pub_drive.publish(cmd_vel)


def main(args=None):

    rclpy.init(args=args)

    bug0 = Bug0()

    rclpy.spin(bug0)

    bug0.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()

