import rclpy
from rclpy.node import Node
from visualization_msgs.msg import Marker
from geometry_msgs.msg import Point

class LineMarkerPublisher(Node):

    def __init__(self):
        super().__init__('line_visualiser')

        # Publisher for the marker
        self.marker_pub = self.create_publisher(Marker, '/line_marker', 10)

        # Timer to periodically publish the marker
        self.timer = self.create_timer(5.0, self.publish_line_marker)

    def publish_line_marker(self):
        # Create the marker
        marker = Marker()
        marker.header.frame_id = "/map"  # Replace with your map's frame
        marker.header.stamp = self.get_clock().now().to_msg()
        marker.ns = "line_marker"
        marker.id = 0
        marker.type = Marker.LINE_STRIP
        marker.action = Marker.ADD

        # Define the start and end points of the line
        start_point = Point()
        start_point.x = -0.43
        start_point.y = 1.26
        start_point.z = 0.0

        end_point = Point()
        end_point.x = 0.72  # Adjust coordinates as needed
        end_point.y = -1.20
        end_point.z = 0.0

        # Add the points to the marker
        marker.points.append(start_point)
        marker.points.append(end_point)

        # Set the line properties
        marker.scale.x = 0.1  # Line width
        marker.color.r = 1.0
        marker.color.g = 0.0
        marker.color.b = 0.0
        marker.color.a = 1.0  # Alpha (opacity)

        # Publish the marker
        self.marker_pub.publish(marker)

def main(args=None):
    rclpy.init(args=args)
    line_visualiser = LineMarkerPublisher()

    try:
        rclpy.spin(line_visualiser)
    except KeyboardInterrupt:
        pass
    finally:
        line_visualiser.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()