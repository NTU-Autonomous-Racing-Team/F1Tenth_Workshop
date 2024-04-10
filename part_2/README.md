# Part 2

# Commands to run sim and teleop

Move the jackal_ws into the github directory
```sh
mv /jackal_files/jackal_ws/ /jackal_files/github_dir
cd /jackal_files/github_dir/jackal_ws
rm -rf build/ install/ log/
colcon build
```
Launch the jackal simulator
```sh
source /opt/ros/foxy/setup.bash
source ./install/local_setup.bash
ros2 launch jackal_gazebo jackal_world.launch.py
```

Run the pre-built teleop node
```sh
ros2 run teleop_twist_keyboard teleop_twist_keyboard
```

# Use newly built map

## Copy the launch file and rename it 
```sh
 cd /jackal_files/jackal_ws/src/jackal_simulator/jackal_gazebo/launch/
 cp jackal_world.launch.py custom_world.launch.py
```
## Edit the launch file

```python
def generate_launch_description():

    world_file = PathJoinSubstitution(
        [FindPackageShare('jackal_gazebo'),
        'worlds',
        'custom_world.world'], # Changed
    )
```

## Rebuild the workspace
```sh
cd jackal_files/github_dir/jackal_ws/
colcon build
```
> Make sure you're at the root of the workspace `jackal_ws/`

## Launch the new file
```sh
source ./install/local_setup.bash
ros2 launch jackal_gazebo custom_world.launch.py
```