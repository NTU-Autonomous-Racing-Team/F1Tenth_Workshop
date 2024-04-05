# What is ROS?

## General CLI Tools
```sh
cd <folder/path> # Use this command to change directories (Tab+Tab autocompletes)
ls # List all files and folders in the current directory
mv <path_to_file> <path_to_new_location> # Move files or folders
cp <path_to_file> <path_to_new_location> # Copies files or folders
mkdir <folder_name> # Creates a new folder
touch <file_name> # Creates a blank file
```
**Things to note**
- ./ describes your current directory
- ../ describes your parent directory

## Building a ROS2 package
```sh
mkdir -p ros2_ws/src
cd ros2_ws/src
ros2 pkg create --build-type ament_python <package_name> # TODO: Replace Package name
```

## Copy pub_sub code into the package
```sh
cd <package_name>/<package_name>
cp ../../../../part_1/python_scripts/* .

cp ../../part_1/python_scripts/* <package_name>/<package_name>
```

## Build the ROS2 ws
```sh
cd ../
colcon build
```
## Running the nodes
```sh
ros2 run <package_name> <executable/python_file>
python3 <executable/python_file> # Make sure you're in the same directory as the node!
```

## Using launch files to run the nodes
```sh
ros2 launch <package_name> launch.py # File extension depends on which launch file you want to use (launch.xml/launch.yaml)
```

# Part 1 flow
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
## Thoughts
- Do we want to make them source the environment themselves?
