---
theme: default
style: |
  section.lead h1 {
    font-size: 2.5rem;
    text-align: center;
  }
paginate: false
class: 
    - lead
    - invert
marp: true

---

<style scoped>
h1 {
    font-size: 3.5rem; /* Adjust the font size as needed */
}
</style>

# **ASME: ROS workshop**

---
# Docker

- How use? HELP ME

---

<style scoped>
h1 {
    font-size: 3.5rem; /* Adjust the font size as needed */
}
</style>

# **Part 1**

- General CLI tools
- ROS2 CLI tools
    - ros2 <command>
    - visualisation tools
- Building a ROS2 package
- Pub-Sub code
- Building a ROS2 workspace
    - Types of workspaces (Tree Visualisation)
- Running the nodes
    - python3
    - ros2 run

---

- Launch files
    - yaml
    - xml
    - python

---
<style scoped>
h2 {
    text-align: center;
    font-size: 1.5rem
}
</style>

# What is ROS?

## Set of software frameworks and not an OS

I need help

---

# Why use ROS?

- Modular
- Open-source
- A lot of prebuilt packages

---

# Nodes
- Responsible for a single, modular purpose
- 3 different types of data transfer
    - Publisher - Subscriber
    - Services
    - Actions

---
# Messages
I am a message yay

---

# Publisher - Subscriber

- Transfer data via topics in the form of messages
<style>
img[alt~="center"] {
  display: block;
  margin: 0 auto;
}
</style>

![width:800px center](pub_sub.gif)

---

# Services 
- Call - Respond
- Only provide data when requested 
```sh
ros2 service call <service_name> <service_type>
```
- Spawn new entity at specified location (Example)

<style>
img[alt~="center"] {
  display: block;
  margin: 0 auto;
}
</style>

![width:500px center](services.gif)

--- 

# Actions
<!--
- Client - Server
    1. Client send goal request
    2. Server send goal response
    3. Server send feedback as it's performing the action
    4. Client request result
    5. Server send result
-->
<style>
img[alt~="center"] {
  display: block;
  margin: 0 auto;
}
</style>

![width:1000px center](actions.gif)

---

# General CLI Tools

```sh
cd <folder/path_to_folder> 
cd ~/Documents # Example (~/ describes your home directory)

ls # List files

mv <path_to_file> <path_to_new_location>
mv ~/Downloads/file_to_be_moved ~/Documents/ # Example

cp <path_to_file> <path_to_new_location> # Copies files or folders 

mkdir <folder_name> # Creates a new folder
mkdir ~/new_folder/ # Example

touch <file_name> # Creates a blank file
touch new_file_name # Example
```

---

# ROS CLI Tools

- need?
---
# ROS2 Workspaces

- What is a workspace
    - Directory containing ROS2 packages
    - If source the installation workspace then the packages become available to ROS2
- 3 types of workspaces
    - Python
    - Cpp
    - Python & Cpp

---

# Python Worksapce
```
ros_ws/
├── build/
│   └── ...
├── install/
│   └── ...
├── log/
│   └── ...
└── src/
    └── my_package/
        ├── package.xml
        ├── resource/my_package
        ├── setup.cfg
        ├── setup.py
        └── my_package/
            └── package.py
```
---

# Cpp Worksapce
```
ros_ws/
├── build/
│   └── ...
├── install/
│   └── ...
├── log/
│   └── ...
└── src/
    └── my_package/
        ├── CMakeLists.txt
        ├── include/my_package/
        ├── package.xml
        └── src/
```

---
# Cpp & Python
```
ros_ws/
├── build/
│   └── ...
├── install/
│   └── ...
├── log/
│   └── ...
└── src/
    └── my_package/
        ├── CMakeLists.txt
        ├── package.xml
        ├── config/
        │   └── my_package_params.yaml
        ├── launch/
        │   └── my_package_launch.py
        ├── include/
        │   └── header_file.hpp
        ├── src/
        │   └── my_package.cpp
        ├── my_package/
        │   └── module_to_import.py
        └── scripts/
            └── my_package.py
```

---

# Minimal Publisher code

## Imports

```python
import rclpy
from rclpy.node import Node

from std_msgs.msg import String
```
- Importing rclpy to be able to use the Node class
- Importing pre-built String message type

---
## Class initialisation

```python
class MinimalPublisher(Node):

    def __init__(self):
        super().__init__('minimal_publisher')
        # TODO: Replace <topic_name> with desired topic name
        self.publisher_ = self.create_publisher(String, '<topic_name>', 10)
        # TODOL Replace <period> with desired timer period in seconds
        timer_period = <period>  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0
```
- Create MinimalPublisher class which inherits from parent class Node
- Call parent class init method
- Initialise publisher and timer callback

---

## Timer callback

```python
    def timer_callback(self):
        msg = String()
        # TODO: Replace <custom_msg> with desired message or uncomment the line below
        # msg.data = 'Hello World: %d' % self.i
        msg.data = '<custom_msg> %d' % self.i
        self.publisher_.publish(msg)
        self.get_logger().info('Publishing: "%s"' % msg.data)
        self.i += 1
```
- Create String object
- Assign the desired message
- Publish the message
- Print debugging messages
---

## Main

```python
def main(args=None):
    rclpy.init(args=args)

    minimal_publisher = MinimalPublisher()

    rclpy.spin(minimal_publisher)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()
```
- rclpy library initialised
- Node object MinimalPublisher() created
- Then spin the node
---
# Minimal Subscriber code

## Imports

```python
import rclpy
from rclpy.node import Node

from std_msgs.msg import String
```
- Same libraries as the publisher node

---
## Initialisation

```python
class MinimalSubscriber(Node):

    def __init__(self):
        super().__init__("minimal_subscriber")
        # TODO: replace '<topic_name>' with desired topic name
        self.subscription = self.create_subscription(
            String, "<topic_name>", self.listener_callback, 10
        )
        self.subscription  # prevent unused variable warning

    def listener_callback(self, msg):
        self.get_logger().info('I heard: "%s"' % msg.data)
```
- Subscriber created instead of publisher
- Subscriber creates a callback that is run everytime a message is received
- Callback prints the message to the terminal
---
## Main

```python
def main(args=None):
    rclpy.init(args=args)

    minimal_subscriber = MinimalSubscriber()

    rclpy.spin(minimal_subscriber)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_subscriber.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
```
- Code does the same thing as the publisher
---

# Building a ROS2 package

```sh
mkdir -p ros2_ws/src
cd ros2_ws/src
ros2 pkg create --build-type ament_python <package_name> # TODO: Replace Package name
```

---
# Copy code to the package directory

```sh
cd <package_name>/<package_name>
cp ~/jackal_files/github_dir/part_1/python_scripts/*
```

---

# Building a ROS2 Workspace

```sh
cd ../
colcon build
```
The workspace should have these folders once finish building
```
ros_ws/
├── build
├── install
├── log
└── src
```
---

# Running the nodes

## Using ros2 run

```sh
source /opt/ros/foxy/setup.bash
source ./install/local_setup.bash
ros2 run <package_name> <executable/python_file>
```
```sh
cd <package_name>/<package_name>
python3 <executable/python_file> 
```

---

# Launch files

- 3 different types of launch files
    - python
    - yaml
    - xml

---
## Python

```python
from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription(
        [
            Node(
                package="<package_name>",
                executable="minimal_publisher",
            ),
            Node(
                package="<package_name>",
                executable="minimal_subscriber",
            ),
        ]
    )
```
---
## XML
```xml
<launch>
  <node pkg="pub_sub" exec="minimal_publisher"/>
  <node pkg="pub_sub" exec="minimal_subscriber"/>
</launch>
```
---
## YAML
```yaml
launch:

- node:
    pkg: "pub_sub"
    exec: "minimal_publisher"

- node:
    pkg: "pub_sub"
    exec: "minimal_subscriber"

```
---
## Running the launch file
```sh
ros2 launch <package_name> launch.py 
```
**File extension depends on which launch file you want to use (launch.xml/launch.yaml)**

---

# **Part 2**
- Jackal sim
- teleop
- Build map in gazebo
- Change world to newly built map
    - cp world file
    - edit launch file

---

# Simulation
What put here? Explain Jackal???????
- ```sh
  ros2 topic list
  ```
- Important topics (/cmd_vel, /front/scan)

---

# Commands to run sim and teleop

Launch the jackal simulator
```sh
ros2 launch jackal_gazebo jackal_world.launch.py
```

Run the pre-built teleop node
```sh
ros2 run teleop_twist_keyboard teleop_twist_keyboard
```
**Read instructions when launch node pls don't bbe noob thanks**

---

# Build map in gazebo

1. Launch gazebo
    ```sh
    gazebo
    ```
2. Place models or shapes
![width:700px](gazebo_models.png)
3. Then save the file by navigating to File > Save World As. Then choose the location to save and remember it
3. Save the file in worlds folder?

---

# Use newly built map

- Copy the launch file and rename it something else
```
give them code or let them figure out????
```
- Rebuild the workspace
```sh
colcon build
```
- Launch the new file
```sh
ros2 launch LMAO U SUCK
```
---

# **Part 3**

---

# Sensor topics and msgs

```sh
ros2 topic echo /scan
ros2 topic echo /odom
ros2 topic echo --no-arr /odom
```

---
# LaserScan
```sh
ros2 topic echo front/scan
```
```sh
header:
  stamp:
    sec: 1541
    nanosec: 197000000
  frame_id: front_laser
angle_min: -2.3561899662017822
angle_max: 2.3561899662017822
angle_increment: 0.006554075051099062
time_increment: 0.0
scan_time: 0.0
range_min: 0.10000000149011612
range_max: 30.0
ranges:
- 3.672072410583496
- ...
```
---
# Odometry

```sh
ros2 topic echo --no-arr /odom
```
## Header
```sh
header:
  stamp:
    sec: 1712668434
    nanosec: 829049376
  frame_id: odom
child_frame_id: base_link
```
---
## Pose
```sh
pose:
  pose:
    position:
      x: 2.1441852005195785
      y: 1.408813177853442
      z: 0.0
    orientation:
      x: 0.0
      y: 0.0
      z: 0.06435134457900855
      w: 0.9979273041914796
  covariance: '<array type: double[36]>'
```
---
## Twist
```sh
twist:
  twist:
    linear:
      x: 3.7634551129476595e-06
      y: 0.0
      z: 0.0
    angular:
      x: 0.0
      y: 0.0
      z: -1.3571082599241658e-08
  covariance: '<array type: double[36]>'
```
---

# Visualize LaserScan in Rviz

## Jackal View Model
```sh
ros2 launch jackal_viz view_model.launch.py
```
Add LaserScan (Do I need Pics?)

## New session of rviz
```sh
rviz2
```
Add LaserScan and axes

---

# **Part 4**

---

# Working principle of a planner

- Given Sensor data how do we get to our desired position

---

# wall_follow

- Explain wall_follow algo?

## Run wall_follow in jackal sim
---

# Run Bug0

- Same thing here?

## Run Bug0 in jackal sim
---

# Additional resources
## [ros2 (foxy) tutorials](https://docs.ros.org/en/foxy/Tutorials.html)
Note ros2 foxy is EOL
## [jackal](https://clearpathrobotics.com/assets/guides/foxy/jackal/index.html)
