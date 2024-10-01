---
theme: default
style: |
    section.lead h1 {
      font-size: 2.5rem;
      text-align: center;
      color: #6699FF;
    }
    section.lead h2{
      font-size: 2.0rem;
      text-align: center;
      position: absolute;
      top: 2rem;
      left: 2rem;
      right: 2rem;
      color: #6699FF;
    }

paginate: false
class:
    - lead
    - invert
marp: true
---

# ROS2 Practical

---

# Contents

1. ROS2 and the Terminal
2. ROS2 Python Scripts
3. ROS2 Workspaces
4. Packages

---

# 1. ROS2 and the Terminal

-   Useful for quick debugging and sanity checks
-   Viewing Topics
    `ros2 topic list`
-   Publishing Topics
    `ros2 topic pub -r 1 /topic_name std_msgs/String "data: Hello World!`
-   Viewing messages of a topic
    `ros2 topic echo /topic_name`

---

# 2. ROS Workspaces

-   A workspace is a directory containing ROS 2 packages.
-   Creating a ROS2 workspace:

```
# Create a workspace directory
mkdir -p ~/ros2_ws/src

# Open the workspace directory
cd ~/ros2_ws/src

# Initialise the Workspace
colcon build
```

---

# 2. ROS Workspaces

-   `build` - contains the return of your building. i.e. your executables
-   `install` - workspace’s setup files are, which you can use to source your overlay. i.e. lets you run packages from the workspace
-   `log` - contains logs from building, logging etc
-   `src` - contains your packages

---

# 3. ROS Packages

-   A package is an organizational unit for your ROS 2 code. e.g. navigation, SLAM, drivers.
-   Creating a Python package with node

```
# Open the workspace source folder
cd ~/ros2_ws/src

# Initialise a package
ros2 pkg create my_package --build-type ament_python --node-name my_node --dependencies rclpy
```

-   Expected outcome is a package directory.

---

# 4. Publisher

1. Writing your first publisher script

-   [minimal_publisher.py](./minimal_publisher.py)

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

# 4. Publisher

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

-   [minimal_subscriber](./minimal_subscriber.py)

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

# 5. Subscriber

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

# Additional

-   Running as Python script as it is a quick way to tune parameters.

```
python3 minimal_pubsub.py
```
