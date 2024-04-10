# What is ROS?

## General CLI Tools
```sh
cd <folder/path_to_folder> # Change Directory
cd ~/Documents # Example (~/ describes your home directory)

ls # List files

mv <path_to_file> <path_to_new_location> # Move
mv ~/Downloads/file_to_be_moved ~/Documents/ # Example

cp <path_to_file> <path_to_new_location> # Copies files or folders 

mkdir <folder_name> # Make Directory a.k.a Creates a new folder
mkdir ~/new_folder/ # Example

touch <file_name> # Creates a blank file
touch new_file_name # Example
```
> - `./` describes your current directory
> - `../` describes your parent directory
> - `~/` describes your home directory

## Building a ROS2 package
```sh
mkdir -p /jackal_files/github_dir/ros_ws/src
cd /jackal_files/github_dir/ros_ws/src
ros2 pkg create --build-type ament_python pub_sub 
```

## Copy pub_sub code into the package
```sh
cd pub_sub/pub_sub
cp ~/jackal_files/github_dir/part_1/python_scripts/* ./
```
## Modifying setup.py

Copy the file into the package directory
```sh
cd /jackal_files/github_dir/
cp part_1/setup.py ros_ws/src/pub_sub/
```
or add these lines to the `setup.py` file in the package directory
```python
import os # Added
from glob import glob # Added
from setuptools import setup
```

```python
    entry_points={
        "console_scripts": [
            "minimal_publisher = pub_sub.minimal_publisher:main", # Added
            "minimal_subscriber = pub_sub.minimal_subscriber:main", # Added
        ],
```

## Building the ROS ws
```sh
cd /jackal_files/github_dir/ros_ws/
colcon build
```

## Using ros2 run
```sh
source /opt/ros/foxy/setup.bash
source ./install/local_setup.bash
ros2 run pub_sub minimal_publisher.py
```
> NOTE: To run the subscriber just replace minimal_publisher with minimal_subscriber
## Executing it directly
```sh
cd /jackal_files/github_dir/ros_ws/src/pub_sub/pub_sub
python3 minimal_publisher.py 
```
> NOTE: Same thing applies here

## Copy the launch folder
```sh
cp -r /jackal_files/github_dir/part_1/launch/ /jackal_files/github_dir/ros_ws/src/pub_sub/
```
## Edit setup.py file in the package directory
```python
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob(os.path.join('launch', '*launch.[pxy][yma]*'))) # Add
    ],
```
> Skip this step if you copied the `setup.py` file earlier

---
## Running the launch file
```sh
ros2 launch pub_sub launch.py 
```
> NOTE: file extension depends on which launch file you want to use (launch.xml/launch.yaml)