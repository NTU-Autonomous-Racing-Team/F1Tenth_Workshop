---
theme: default
style: |
    section.lead h1 {
      font-size: 2.5rem;
      text-align: center;
      color: #6699FF;
    }
    section.lead h2 {
      font-size: 2.0rem;
      text-align: center;
      position: absolute;
      top: 2rem;
      left: 2rem;
      right: 2rem;
      color: #6699FF;
    }

    h3 {
        text-align: center;
        position: UNSET;
        color: white;
    }

paginate: false
class:
    - lead
    - invert
marp: true
---

<style scoped>
h2 {
    text-align: center;
    position: unset;
    color: white;
}
</style>

# Introduction to ROS

---

<style scoped>
h3 {
    text-align: center;
    position: unset;
    color: white;
}
</style>

# What is ROS?

### Middleware framework for robot software development

### Facilitates communication (Topics, Services, Actions) between different robot components (Nodes)

---

# Why Use ROS?

-   Modularity and reusability
-   Large, active community
-   A lot of libraries and tools provided

### OPEN SOURCE FTW!!

---

# What are ROS Nodes?

-   Nodes are individual processes that handle specific tasks
-   Examples:
    -   Sensor node
    -   Motor control node
    -   Camera node
-   Can be combined to create a complete robot system

---

# Node Communication

### How do nodes **communicate**?

-   **Topics**
-   **Services**
-   **Actions**

---

# ROS2 Communication: Topics
- Deploys a Publish-Subscribe Mechanism
- Used on continuous data streams
- The topic acts as a notice board for all to see messages.
- Nodes **publish** messages to topics and other nodes **subscribe** to those topics to receive the messages.

---

<style>
img[alt~="center"] {
  display: block;
  margin: 0 auto;
}
</style>

![width:800px center](multi_pub_sub.gif)

---

# ROS Messages

-   ROS messages are the data that are communicated via topics.
-   A message has a fixed structure that defines what kind of data it can carry (e.g. `sensor_msgs`, `geometry_msgs`)
-   Holds different types of data together

---

## Example: LaserScan Message

-   **`sensor_msgs/LaserScan`** is used to communicate data from a LIDAR sensor.
-   It contains:
    -   **Header**: Timestamp and frame ID
    -   **Angle** and **range** arrays for LIDAR measurements

```plaintext
std_msgs/Header header
float32 angle_min
float32 angle_max
float32[] ranges
```

---

## Example: Odom (Odometry) Message

-   **`nav_msgs/Odometry`** is used for representing robot's movement in space.
-   Contains:
    -   **Pose**: Position and orientation.
    -   **Twist**: Velocity information (linear and angular).

```plaintext
std_msgs/Header header
geometry_msgs/PoseWithCovariance pose
geometry_msgs/TwistWithCovariance twist
```

---

## Example: Ackermann Steering Message

-   **`ackermann_msgs/AckermannDrive`** is used for controlling vehicle steering.
-   Contains:
    -   **Steering angle**: Angle to turn the wheels.
    -   **Speed**: Forward velocity of the vehicle.

```plaintext
float32 steering_angle
float32 speed
```

---
<style scoped>

h2 {
    text-align: center;
    position: UNSET;
    color: white;
}
</style>

# ROS2 Communication: Services
- Deploys the call and respond model
- Used to perform actions once

---

# ROS2 Communication: Services cont.
![width:800px center](Service-SingleServiceClient.gif)

---

# ROS2 Communication: Actions
- Utilises both topics and services
- used to perform long running tasks
- Consists of a goal, feedback, and a result
---

# ROS2 Communication: Actions cont.
![width:800px center](Action-SingleActionClient.gif)

---

# ROS Projects

---

# Content

1. [ROS Workspaces](#ros-workspaces)
2. [ROS Packages](#ros-packages)
3. [ROS Launch Files](#ros-launch-files)

---

# ROS Workspaces

 ### A workspace is a collection of ROS2 packages and nodes for a specific project.
- It contains important directories:
  - **`src`**: Source code for packages
  - **`build`**: Compiled binaries
  - **`install`**: Development environment setup
- **Remember** to source the installation workspace to have the packages in that workspace available to you  **`source ./install/local_setup.bash`**

---
## Python Workspace
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
        ├── CMakeLists.txt
        ├── resource/my_package
        ├── setup.cfg
        ├── setup.py
        └── my_package/
            └── node.py
    └── my_messages
        └── msgs
            └── my_msg.msg
            └── ...
    └── my_bringup
        ├── launch
            └── my_demo.launch.py
        └── ...
```
---
# ROS Packages

### A ROS package is the basic building block of ROS projects.
It contains:
- Nodes
- Message definitions
- Service and Action definitions
- Launch files
- Metadata files like CMakeLists.txt and package.xml

**Makes it easier to share code with others**

---

# ROS Launch Files

-   A **launch file** is a script that automates the process of starting multiple nodes and setting configurations in ROS2.
-   Instead of manually starting each node, a launch file can launch them all together.
-   They are written in Python in ROS2 (unlike XML in ROS1).

---

## Why Use Launch Files?

-   Simplifies running multiple nodes, especially in complex systems.
-   Allows for setting parameters, remapping topics, and configuring environments.
-   Great for automating testing and deployment of robots.

---

# Launch File Example

```python
# my_launch_file.py
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='my_package',
            executable='my_node',
            name='my_node_name',
            output='screen',
        ),
    ])
```

---

# ROS2 Practical

---

# Contents

1. [ROS2 and the Terminal](#1-ros2-and-the-terminal)
2. [ROS2 Workspaces](#2-ros2-workspaces)
3. [ROS2 Packages](#3-ros-packages)
4. [Publishing](#4-publisher)
5. [Subscribing](#5-subscriber)
6. [Additional](#6-additional)
7. [References](#7-references)

---

# 1. ROS2 and the Terminal

-   Useful for quick debugging and sanity checks
-   Viewing Topics
    `ros2 topic list`
-   Publishing Topics
    `ros2 topic pub -r 1 /topic_name std_msgs/String "data: Hello World!"`
-   Viewing messages of a topic
    `ros2 topic echo /topic_name`

---

# 2. ROS2 Workspaces

```
# Create a workspace directory
mkdir -p ~/ros2_ws/src

# Open the workspace directory
cd ~/ros2_ws/src

# Initialise the Workspace
colcon build
```

---

# 3. ROS Packages

```
# Open the workspace source folder
cd ~/ros2_ws/src

# Initialise a package
ros2 pkg create my_package --build-type ament_python --node-name my_node --dependencies rclpy
```

---

# 4. Publisher

1. Writing your first publisher script

-   [minimal_publisher.py](./ros2_ws/src/my_package/my_package/minimal_publisher.py)

---

# 4. Publisher cont.

2. Adding your script as an executable. Open `setup.py`

```
entry_points = {
    "console_scripts":[
        my_node = my_package.my_node:main
        minimal_publisher = my_package.minimal_publisher:main
    ]
}
```

---

# 4. Publisher cont.

3. Build your package

```
colcon build --packages-select my_package
```

4. Run your node

```
# Sourcing the Overlay
source ~/ros2_ws/install/local_setup.bash
# Starting the Node
ros2 run my_package minimal_publisher
```

---

# 5. Subscriber

1. Writing your first subscriber script

-   [minimal_subscriber.py](./ros2_ws/src/my_package/myp_ackage/minimal_subscriber.py)

---

# 5. Subscriber cont.

2. Adding your script as an executable. Open `setup.py`

```
entry_points = {
    "console_scripts":[
        my_node = my_package.my_node:main
        minimal_publisher = my_package.minimal_publisher:main
    ]
}
```

---

# 5. Subscriber cont.

3. Build your package

```
colcon build --packages-select my_package
```

4. Run your node

-   Running ROS2 Executable

```
# Sourcing the Overlay
source ~/ros2_ws/install/local_setup.bash
# Starting the Node
ros2 run my_package minimal_publisher
```

---

# 6. Additional

-   [Additional Info](#additional-info)
- [ROS2 Launch](#ros2-launch)
-   [ROS2 Messages](#ros2-messages)

---

# Additional Info

-   Running as Python script as it is a quick way to tune parameters.

```
python3 minimal_pubsub.py
```

-   Publishing and Subscribing in the same node. [minimal_pubsub](./ros2_ws/src/my_package/my_package/minimal_pubsub.py)

```
ros2 run my_package minimal_pubsub

```

-   Developing ROS2 packages in C++ `ros2 pkg create cpp_package --build-type ament_cmake

---

# ROS2 Launch
- [my_bringup](../ros2_practical/ros2_ws/src/my_bringup/my_demo.launch.py)

---

# ROS2 Messages

-   Rarely, altough sometimes, you'll need to create your own ROS messages.
-   Steps:

1. Initialise a ros2 package `ros2 pkg create my_msgs --dependencies std_msgs geometry_msgs`
2. Edit the `CMakeList`:

```
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
	"msgs/MyMessage.msg"
)

ament_export_dependencies(rosidl_default_runtime)

```

---

# ROS2 Messages cont.

3. Edit the `package.xml`

```
  <buildtool_depend>rosidl_default_generators</buildtool_depend>
  <exec_depend>rosidl_default_runtime</exec_depend>
  <member_of_group>rosidl_interface_packages</member_of_group>

```

---

# ROS2 Messages cont.

4. Create your message file:

```
cd ~/ros2_ws/src/
mkdir msgs
cd msgs
touch my_msg.msg
```

---

# ROS2 Messages cont.

5. Define your message file.

-   This uses other ROS2 messages e.g. std_msgs, geometry_msgs
-   [my_msg.msg](./ros2_ws/src/my_msgs/msgs/MyMessage.msg)

---

# ROS2 Messages cont.

6. Build, Source and Run

```
colcon build --packages-select my_msgs
source ~/ros2_ws/install/local_setup.bash
ros2 topic pub -r 1 some_topic my_msgs/my_msg "{name: "Lawrence", some_integer: 10, some_vector: [1, 2]}"
ros2 topic echo some_topic
```

---

# 7. References

-   [Creating a Workspace](https://docs.ros.org/en/foxy/Tutorials/Beginner-Client-Libraries/Creating-A-Workspace/Creating-A-Workspace.html)
-   [Creating a Package](https://docs.ros.org/en/foxy/Tutorials/Beginner-Client-Libraries/Creating-Your-First-ROS2-Package.html)
-   [Simple Pusblisher/ Subscriber (Python)](https://docs.ros.org/en/foxy/Tutorials/Beginner-Client-Libraries/Writing-A-Simple-Py-Publisher-And-Subscriber.html)
-   [Create Custom Message](https://roboticsbackend.com/ros2-create-custom-message/#Using_existing_messagesinterfaces)

---
