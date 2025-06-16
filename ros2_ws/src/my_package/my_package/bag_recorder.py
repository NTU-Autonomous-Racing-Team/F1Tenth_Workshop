import rclpy
from rclpy.node import Node

from sensor_msgs.msg import LaserScan
from ackermann_msgs.msg import AckermannDriveStamped

import numpy as np
import time

class BagRecorder(Node):

    def __init__(self):
        super().__init__("bag_recorder")
        self.scan_sub = self.create_subscription(
            LaserScan, "scan", self.scan_sub_callback, 1
        )
        self.drivecmd_sub = self.create_subscription(
            AckermannDriveStamped, "drive", self.drivecmd_sub_callback, 1
        )
        self.speed = None
        self.angle = None

    def drivecmd_sub_callback(self, msg):
        # Log the message being received
        #self.get_logger().info('I heard: "%s"' % msg.data)
        self.speed = msg.drive.speed
        self.angle = msg.drive.steering_angle

    def scan_sub_callback(self, msg):
        scan = np.array(msg.ranges)
        np.savez(f'{time.time()}.npz', x=scan, speed=np.array(self.speed), angle=np.array(self.angle))


def main(args=None):
    rclpy.init(args=args)

    bag_recorder = BagRecorder()

    rclpy.spin(bag_recorder)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    bag_recorder.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
