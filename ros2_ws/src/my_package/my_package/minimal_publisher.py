import rclpy
from rclpy.node import Node

from std_msgs.msg import String


class MinimalPublisher(Node):

    def __init__(self):
        # Initialize the Node object with the name 'minimal_publisher'
        super().__init__('minimal_publisher')
        # Create a publisher object with String message type, publishing to 'my_topic' topic
        self.publisher_ = self.create_publisher(String, 'my_topic', 10)
        # Create a timer object with timer_period seconds and timer_callback function
        self.timer = self.create_timer(1, self.timer_callback)
        # Initialize a counter variable
        self.i = 0

    def timer_callback(self):
        # Initialize a String message object
        msg = String()
        # Populate the message object with data
        msg.data = f"Publishing message {self.i}"
        # Publish the message object
        self.publisher_.publish(msg)
        # Log the message being published
        self.get_logger().info('Publishing: "%s"' % msg.data)
        # Increment the counter
        self.i += 1


def main(args=None):
    rclpy.init(args=args)

    minimal_publisher = MinimalPublisher()

    rclpy.spin(minimal_publisher)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
