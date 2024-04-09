#!/usr/bin/env python3

import rclpy

from rclpy.node import Node

from sensor_msgs.msg import LaserScan
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Twist

import numpy as np


class WallFollow(Node):

    def __init__(self):
        super().__init__("wall_follow")

        # Subscribing to relevant topics
        self.sub_scan = self.create_subscription(
            LaserScan, "front/scan", self.scan_callback, 10
        )

        self.sub_odom = self.create_subscription(
            Odometry, "odom", self.odom_callback, 10
        )

        self.pub_drive = self.create_publisher(Twist, "cmd_vel", 10)

        self.sub_scan
        self.sub_odom

        self.drive_msg = Twist()

        self.Kp = 5.0
        self.Ki = 0.00
        self.Kd = 0.005

        self.integral = 0.0
        self.prev_error_1 = 0.0
        self.prev_secs = 0.0
        self.prev_nsecs = 0.0

        self.longitudinal_vel = 0
        self.front_dist = 0
        self.oldVel = True

    def getRange(self, scan_data, angle):
        ranges = scan_data.ranges
        angle_rad = angle * (np.pi / 180)
        index = int(abs(angle_rad - scan_data.angle_max) / scan_data.angle_increment)

        return ranges[index]

    def odom_callback(self, odom_data):
        self.longitudinal_vel = odom_data.twist.twist.linear.x

    def scan_callback(self, scan_data):

        self.front_dist = self.getRange(scan_data, 0)

        secs = scan_data.header.stamp.sec
        nsecs = scan_data.header.stamp.nanosec

        angle_b = 90
        angle_a = 40

        theta = (angle_b - angle_a) * (np.pi / 180)
        # 90 Degrees to the car
        distance_b = self.getRange(scan_data, angle_b)  # ranges[901]
        # ~ 35 Degrees to the first scan
        distance_a = self.getRange(scan_data, angle_a)  # ranges[760]

        alpha = -1 * np.arctan2(
            (distance_a * np.cos(theta) - distance_b), (distance_a * np.sin(theta))
        )

        actual_distance = distance_b * np.cos(alpha)
        desired_distance = 0.8  # Metres

        error = desired_distance - actual_distance
        lookahead_distance = self.longitudinal_vel * 0.45  # Metres

        error_1 = error + lookahead_distance * np.sin(alpha)

        if (
            (self.prev_secs == 0.0)
            & (self.prev_nsecs == 0.0)
            & (self.prev_error_1 == 0.0)
        ):
            self.prev_secs = secs
            self.prev_nsecs = nsecs
            self.prev_error_1 = error_1

        dt = secs - self.prev_secs + (nsecs - self.prev_nsecs) * 1e-9

        try:
            self.integral += error_1 * dt

            angular_vel = (
                (self.Kp * error_1)
                + (self.Ki * self.integral)
                + (self.Kd * (error_1 - self.prev_error_1) / dt)
            )

            # steering_angle_degrees = abs(steering_angle * (180 / np.pi))

            self.prev_error_1 = error_1
            self.prev_secs = secs
            self.prev_nsecs = nsecs

            # self.drive_msg.drive.speed = 0.8 * (1 / 1.2) ** (
            #     steering_angle_degrees - 15
            # )
            # if self.oldVel:
            #     self.drive_msg.angular.z = 0.9
            #     self.oldVel = False
            # else:
            #     self.drive_msg.angular.z = 0.5
            #     self.oldVel = True

            self.drive_msg.angular.z = round(angular_vel, 4)
            self.drive_msg.linear.x = 2.0
            self.pub_drive.publish(self.drive_msg)

            self.get_logger().info(
                f"90 degrees: {distance_b} | angular_vel: {round(angular_vel, 4)}"
            )
        except ZeroDivisionError:
            pass


def main(args=None):

    rclpy.init(args=args)

    wall_follow = WallFollow()

    rclpy.spin(wall_follow)

    wall_follow.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":

    main()
