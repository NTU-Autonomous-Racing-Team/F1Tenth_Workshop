#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

from sensor_msgs.msg import LaserScan
from ackermann_msgs.msg import AckermannDriveStamped

import numpy as np


class WallFollowingNode(Node):
    """
    ROS2 Node Class that handles all the subscibers and publishers for the PID wall follower.
    It abstracts the gap finder algorithm from the ROS2 interface.
    The only things to tune or change are in the sections:
    - ROS2 PARAMETERS
    - SPEED AND STEERING LIMITS
    - GAP FINDER ALGORITHM
    """

    def __init__(self):
        ### ROS2 PARAMETERS ###
        scan_topic = "scan"
        # drive_topic = "/nav/drive"
        drive_topic = "drive"

        ### SPEED AND STEERING LIMITS ###
        self.v_forward = 1.0  # [m/s]
        self.max_steering = 0.5  # [rad]

        ### Wallfollower parameters ###
        self.lookahead = 15

        ### PID Parameters ###
        self.k_p = 0.75
        self.k_d = 0.25
        self.k_i = 0
        self.setpoint = 1

        ### Control State ###
        self.prev_error = 0
        self.accumulated_error = 0

        ### ROS2 NODE ###
        super().__init__("wall_follower")
        # Drive Publisher
        self.drive_msg = AckermannDriveStamped()
        self.drive_publisher = self.create_publisher(
            AckermannDriveStamped, drive_topic, 1
        )
        # Scan Subscriber
        self.scan_subscriber = self.create_subscription(
            LaserScan, scan_topic, self.scan_callback, 1
        )
        self.scan_subscriber  # prevent unused variable warning

    def scan_callback(self, scan_msg):
        ranges = np.array(scan_msg.ranges)
        angle_increment = scan_msg.angle_increment
        angle_min = scan_msg.angle_min
        angle_max = scan_msg.angle_max

        # Find distance to wall
        offset = - np.pi / 2 - angle_min
        theta = self.lookahead * np.pi / 180
        a = ranges[int(offset / angle_increment)] 
        b = ranges[int((offset + theta) / angle_increment)]
        alpha = np.arctan2(a * np.cos(theta) - b, a * np.sin(theta))
        distance = b * np.cos(alpha)

        # Update PID
        error = self.setpoint - distance
        steering_angle = self.k_p * error + self.k_d * self.prev_error + self.k_i * self.accumulated_error
        self.prev_error = error
        self.accumulated_error += error

        # Publish Drive Message
        self.drive_msg.drive.speed = self.v_forward
        self.drive_msg.drive.steering_angle = steering_angle
        self.drive_publisher.publish(self.drive_msg)


def main(args=None):
    rclpy.init(args=args)

    wallFollower = WallFollowingNode()

    rclpy.spin(wallFollower)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    wallFollower.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
