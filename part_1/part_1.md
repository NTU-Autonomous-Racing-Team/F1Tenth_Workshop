# What is ROS?

## Building a ROS ws
```sh
mkdir -p ros2_ws/src
```

# Part 1 flow
*Do we want to make them source the environment themselves?*
1. Introduce CLI tools they need. cd, ls, mkdir, touch, mv, cp
2. Introduce messages, nodes and different types of data transfer (pub-sub, services, actions)
3. Building a Package & WS
   - Show them structure of different workspaces. Tree visualisation
   - Show them command to init a package
   - Copy code into package
   - colcon build
   - ros2 run <package>
   - python3 <python_file>
4. Using Launch files
   - Copy/Move launch file into the package
   - colcon build
   - ros2 launch <launch_file>
