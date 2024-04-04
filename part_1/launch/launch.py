# TODO change node names and launch the correct ones. Or we could just use these

from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription(
        [
            Node(
                package="pub_sub",
                namespace="publisher",
                executable="minimal_publisher",
                name="pub_sub",
            ),
            Node(
                package="pub_sub",
                namespace="subscriber",
                executable="minimal_subscriber",
                name="pub_sub",
            ),
        ]
    )
