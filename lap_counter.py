import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Point
from nav_msgs.msg import Odometry
import math

class LapCounter(Node):
    def __init__(self):
        super().__init__('lap_counter')

        # Parameters
        self.start_point = Point(x=-0.43, y=1.26, z=0.0)  # Start point of the line
        self.end_point = Point(x=0.72, y=-1.20, z=0.0)    # End point of the line
        self.car_position = None  # Current car position
        self.prev_position = None  # Previous car position
        self.lap_count = 0

        # Publishers and Subscribers
        self.odom_sub = self.create_subscription(Odometry, '/ego_racecar/odom', self.odom_callback, 1)

    def odom_callback(self, msg):
        # Get the car's current position from the odometry message
        current_position = msg.pose.pose.position

        # Save the current position as the previous one for the next iteration
        if self.car_position is not None:
            self.prev_position = self.car_position

        self.car_position = current_position

        # Check for line crossing if we have both current and previous positions
        if self.car_position and self.prev_position:
            if self.check_line_crossing(self.prev_position, self.car_position, self.start_point, self.end_point):
                self.lap_count += 1
                self.get_logger().info(f"Lap completed! Total laps: {self.lap_count}")

    def check_line_crossing(self, prev_pos, curr_pos, line_start, line_end):
        """Check if the line between prev_pos and curr_pos intersects the line segment line_start to line_end."""
        def is_counter_clockwise(p1, p2, p3):
            """Helper function to determine counter-clockwise order."""
            return (p3.y - p1.y) * (p2.x - p1.x) > (p2.y - p1.y) * (p3.x - p1.x)

        # Determine the relative orientation of the segments
        ccw1 = is_counter_clockwise(prev_pos, curr_pos, line_start)
        ccw2 = is_counter_clockwise(prev_pos, curr_pos, line_end)
        ccw3 = is_counter_clockwise(line_start, line_end, prev_pos)
        ccw4 = is_counter_clockwise(line_start, line_end, curr_pos)

        # Line segments intersect if and only if the orientations differ
        return ccw1 != ccw2 and ccw3 != ccw4
    
def main(args=None):
    rclpy.init(args=args)
    lap_counter = LapCounter()

    try:
        rclpy.spin(lap_counter)
    except KeyboardInterrupt:
        pass
    finally:
        lap_counter.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()