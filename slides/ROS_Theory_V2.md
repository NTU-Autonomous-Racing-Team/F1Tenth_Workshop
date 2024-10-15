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
-   Example (For camera processing):
    -   Camera node (to get images)
    -   Processing node (to process images)
    -   Output node (uploads the processed images)
-   Can be combined to create a complete robot system

---

# Node Communication

### How do nodes **communicate**?

-   **Topics**
-   **Services**
-   **Actions**

---

# ROS2 Communication: Topics

-   Deploys a Publish-Subscribe Mechanism
-   Used on continuous data streams
-   The topic acts as a notice board for all to see messages.
-   Nodes **publish** messages to topics and other nodes **subscribe** to those topics to receive the messages.

---

<style>
img[alt~="center"] {
  display: block;
  margin: 0 auto;
}
</style>

![width:800px center](../assets/multi_pub_sub.gif)

---

# ROS Messages

-   ROS messages are the data that are communicated via topics.
-   A message has a fixed structure that defines what kind of data it can carry (e.g. `sensor_msgs`, `geometry_msgs`)
-   Data types (vectors, numbers, characters)
-   Holds different types of data together

---
<style scoped>
pre {
   color: ;
}
</style>

## Example: LaserScan Message

-   **`sensor_msgs/LaserScan`** is used to communicate data from a LIDAR sensor.
-   It contains:
    -   **Header**: Timestamp and frame ID
    -   **Angle** and **range** arrays for LIDAR measurements

```
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

```
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

# ROS Projects

---

# Content

1. [ROS Workspaces](#ros-workspaces)
2. [ROS Packages](#ros-packages)
3. [ROS Launch Files](#ros-launch-files)

---

# ROS Workspaces

### A workspace is a collection of ROS2 packages and nodes for a specific project.

-   It contains important directories:
    -   **`src`**: Source code for packages
    -   **`build`**: Compiled binaries
    -   **`install`**: Development environment setup
-   **colcon build** builds your binaries. It happens when you're creating your workspace
-  **Sourcing** allows access to those binaries **`source ./install/local_setup.bash`**

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
```

---

# ROS Packages

### A ROS package is the basic building block of ROS projects.

It contains:

-   Nodes
-   Message definitions
-   Service and Action definitions
-   Launch files
-   Metadata files (list of dependencies)

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