# ROS2 Practical 
## Syllabus
1. ROS2 on terminal - Debugging
- `ros2 topic pub -r 1 /topic_name std_msgs/String "data: Hello World"` == publish at rate of 1 Hz <topic_name> <message_type> "<YAML dictionary>" 
    - useful for simple commands or sanity checks. 
- `ros2 topic echo /topic_name` == prints out the message
    - useful as a sanity check on expected messages. 
- `ros2 topic hz`
    - useful to tell if the compute takes too long. 
2. Creating scripts
- publisher
- subscriber
- pubsub
3. Creating workspaces
```
mkdir -p ~/ros2_ws/src
cd ~/ros2_ws/src
colcon build
```
4. Creating packages
```
cd ~/ros2_ws/src
ros2 pkg create --build-type ament_python --node-name my_node my_package
```
5. Setting up package
- in `setup.py` add `minimal_subscriber = my_package.minimal_subscriber:main` to create executable. 
5. Building 
```
colcon build --packages-select my_package
```
6. Running Node 
```
source install/local_setup.bash
ros2 run my_package minimal_pubsub
```
