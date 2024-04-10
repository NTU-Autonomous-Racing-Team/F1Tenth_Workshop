#!/usr/bin/env python3

import rclpy

from rclpy.node import Node

from sensor_msgs.msg import LaserScan
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Twist

import numpy as np
import math


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

        self.timer = self.create_timer(0.02, self.timer_callback)

        self.drive_msg = Twist()

        # PID contants
        self.Kp = 5.0
        self.Ki = 0.00
        self.Kd = 0.00
        self.integral = 0.0

        # Variables to store the previous error and time
        self.prev_error_1 = 0.0
        self.prev_secs = 0.0
        self.prev_nsecs = 0.0

        self.longitudinal_vel = 0

        self.angle_b = 90
        self.angle_a = 40

    # Function to get the range of the LIDAR scan data at a specific angle
    def getRange(self, scan_data, angle):
        ranges = scan_data.ranges
        angle_rad = angle * (np.pi / 180)
        index = int(abs(angle_rad - scan_data.angle_max) / scan_data.angle_increment)

        return ranges[index]

    def odom_callback(self, odom_data):
        self.longitudinal_vel = odom_data.twist.twist.linear.x

    def scan_callback(self, scan_data):

        self.front_dist = self.getRange(scan_data, 0)

        self.secs = scan_data.header.stamp.sec
        self.nsecs = scan_data.header.stamp.nanosec

        # 90 Degrees to the car
        self.distance_b = self.getRange(scan_data, self.angle_b)  # ranges[901]
        # ~ 35 Degrees to the first scan
        self.distance_a = self.getRange(scan_data, self.angle_a)  # ranges[760]

    def timer_callback(self):

        theta = (self.angle_b - self.angle_a) * (np.pi / 180)

        alpha = -1 * np.arctan2(
            (self.distance_a * np.cos(theta) - self.distance_b),
            (self.distance_a * np.sin(theta)),
        )

        actual_distance = self.distance_b * np.cos(alpha)
        desired_distance = 0.8  # Metres

        error = desired_distance - actual_distance
        lookahead_distance = self.longitudinal_vel * 0.45  # Metres

        error_1 = error + lookahead_distance * np.sin(alpha)

        if (
            (self.prev_secs == 0.0)
            & (self.prev_nsecs == 0.0)
            & (self.prev_error_1 == 0.0)
        ):
            self.prev_secs = self.secs
            self.prev_nsecs = self.nsecs
            self.prev_error_1 = error_1

        dt = self.secs - self.prev_secs + (self.nsecs - self.prev_nsecs) * 1e-9

        try:
            self.integral += error_1 * dt

            angular_vel = (
                (self.Kp * error_1)
                + (self.Ki * self.integral)
                + (self.Kd * (error_1 - self.prev_error_1) / dt)
            )

            if math.isnan(angular_vel):
                angular_vel = 0.00

            self.prev_error_1 = error_1
            self.prev_secs = self.secs
            self.prev_nsecs = self.nsecs

            # Publishing the drive message
            self.drive_msg.angular.z = round(angular_vel, 4)
            self.drive_msg.linear.x = 1.0
            self.pub_drive.publish(self.drive_msg)

            self.get_logger().info(f"angular_vel: {angular_vel:.2f}")

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
