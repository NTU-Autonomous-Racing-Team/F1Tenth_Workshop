# ROS2 Practical

---

# Contents

1. [ROS2 Debugging on Terminal](#1-ros2-debugging-on-terminal)
2. [Creating ROS2 Workspaces](#2-creating-ros2-workspaces)
3. [Creating ROS2 Packages](#3-creating-ros-packages)
4. [Publishing](#4-minimal-publisher)
5. [Subscribing](#5-minimal-subscriber)
6. [Extra](#6-extra)
7. [References](#7-references)

---

# 1. ROS2 Debugging on Terminal

-   Useful for quick debugging and sanity checks
-   Viewing Topics
    `ros2 topic list`
-   Publishing Topics
    `ros2 topic pub -r 1 /topic_name std_msgs/String "data: Hello World!"`
-   Viewing messages of a topic
    `ros2 topic echo /topic_name`
-   Checking publish 
    `ros2 topic hz /topic_name`

---

# 2. Creating ROS2 Workspaces

1. Make a directory for a ros2 workspace

```
mkdir -p /ros2_ws/src
```

2. Change directory to the ros2 workspace

```
cd /ros2_ws
```

3. Build your workspace

```
colcon build
```

---

# 3. Creating ROS Packages

1. Change directory to the source folder

```
cd /ros2_ws/src
```

2. Create a ROS package

```
ros2 pkg create my_package --build-type ament_python --node-name my_node --dependencies rclpy
```

---

# 3. Creating ROS Package (for workshop)

-   To facilitate the workshop, all scripts and packages have already been made

1. Deleted the package created

```
rm -rf /ros2_ws/src/my_package
```

2. Copying the pre-made package

```
cp /f1tenth_workshop/ros2_ws/src/my_package /ros2_ws/src
```

---

# 4. Minimal Publisher

1. Writing your first publisher script

-   [minimal_publisher.py](../ros2_ws/src/my_package/my_package/minimal_publisher.py)

---

# 4. Minimal Publisher cont.

2. Adding your script as an executable. Open `setup.py`

```
entry_points = {
    "console_scripts":[
        ...
        minimal_publisher = my_package.minimal_publisher:main
        ...
    ]
}
```

---

# 4. Minimal Publisher cont.

3. Build your package

```
colcon build --packages-select my_package
```

4. Run your node

```
# Sourcing the Overlay
source /ros2_ws/install/local_setup.bash
# Starting the Node
ros2 run my_package minimal_publisher
```

---

# 5. Minimal Subscriber

1. Writing your first subscriber script

-   [minimal_subscriber.py](../ros2_ws/src/my_package/my_package/minimal_subscriber.py)

---

# 5. Subscriber cont.

2. Adding your script as an executable. Open `setup.py`

```
entry_points = {
    "console_scripts":[
        ...
        minimal_subscriber = my_package.minimal_publisher:main
        ...
    ]
}
```

---

# 5. Minimal Subscriber cont.

3. Build your package

```
colcon build --packages-select my_package
```

4. Run your node

-   Running ROS2 Executable

```
# Sourcing the Overlay
source /ros2_ws/install/local_setup.bash
# Starting the Node
ros2 run my_package minimal_publisher
```

---

# 6. Extra

-   [Additional Info](#additional-info)
-   [ROS2 Launch](#ros2-launch)
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

1. Initialise a ros2 package

```
ros2 pkg create my_bringup --dependencies ros2launch
```

2. Define your launch file [my_bringup.py](../ros2_ws/src/my_bringup/launch/my_demo.launch.py)
3. Add launch file to `setup.py`

```
import os
from glob import glob
...
(os.path.join('share', package_name, 'launch'), glob(os.path.join('launch', '*launch.[pxy][yma]*')))
...
```

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
cd /ros2_ws/src/
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
source /ros2_ws/install/local_setup.bash
ros2 topic pub -r 1 some_topic my_msgs/my_msg "{name: "Lawrence", some_integer: 10, some_vector: [1, 2]}"
ros2 topic echo some_topic
```

---

# 7. References

-   [Creating a Workspace](https://docs.ros.org/en/foxy/Tutorials/Beginner-Client-Libraries/Creating-A-Workspace/Creating-A-Workspace.html)
-   [Creating a Package](https://docs.ros.org/en/foxy/Tutorials/Beginner-Client-Libraries/Creating-Your-First-ROS2-Package.html)
-   [Simple Pusblisher/ Subscriber (Python)](https://docs.ros.org/en/foxy/Tutorials/Beginner-Client-Libraries/Writing-A-Simple-Py-Publisher-And-Subscriber.html)
-   [Create Custom Message](https://roboticsbackend.com/ros2-create-custom-message/#Using_existing_messagesinterfaces)
-   [Create a Launch File](https://docs.ros.org/en/foxy/Tutorials/Intermediate/Launch/Creating-Launch-Files.html)

---
