from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()

    pub_node = Node(
        package="my_package",
        executable="minimal_publisher",
    )

    pubsub_node = Node(
        package="my_package",
        executable="minimal_pubsub",
    )

    ld.add_action(pub_node)
    ld.add_action(pubsub_node)

    return ld
