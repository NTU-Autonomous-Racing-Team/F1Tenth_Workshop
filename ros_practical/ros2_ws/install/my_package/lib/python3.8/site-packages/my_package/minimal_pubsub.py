import rclpy
from rclpy.node import Node

from std_msgs.msg import Int32, String

"""
Quality of service 
- added to ROS2, absent in ROS
- a results of Data Distributed System (DDS), the middleware of ROS2 (ROS used TCP which is not good for lossy networks e.g. WiFi)
- ROS2 uses UDP for transporting messages
- enables higher degree of control over how messages are transported. 
- therefore makes it usable for critical systems

QoS Compatability
- QoS setting of two node have to be compatible, else it will not communicate properly. 

"""
class MinimalPubSub(Node):

    def __init__(self):
        super().__init__('minimal_pubsub')
        # By default, publishers and subscriptions in ROS 2 have “keep last” for history with a queue size of 10. 
        queue_size = 10

        # CREATE PUBLISHER
        # TODO: Replace <topic_name> with desired topic name
        published_topic = "my_topic2"
        self.publisher_ = self.create_publisher(String, published_topic, queue_size)
        # TODO: Replace <period> with desired timer period in seconds
        timer_period = 1
        self.timer = self.create_timer(timer_period, self.timer_callback)

        # Create a SUBSCRIBER
        # TODO: Replace <topic_name> with desired topic name
        subscribed_topic = "my_topic"
        self.subscriber_ = self.create_subscription(String, subscribed_topic, self.listener_callback, queue_size)
        self.subscriber_ #prevent unused variable warning. 
        self.msg_received = String()

    def timer_callback(self):
        msg = String()
        msg.data = self.msg_received.data
        self.publisher_.publish(msg)
        self.get_logger().info('I heard: "%s"' % msg.data)

    def listener_callback(self, msg):
        # self.get_logger().info('I heard: "%s"' % msg.data)
        self.msg_received = msg


def main(args=None):
    rclpy.init(args=args)

    minimal_pubsub = MinimalPubSub()

    rclpy.spin(minimal_pubsub)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_pubsub.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
