# Part 2

1. Launch jackal sim'
   ```sh
   ros2 launch jackal_gazebo jackal_world.launch.py
   ```
3. Show them how to use teleop
   ```sh
   ros2 run teleop_twist_keyboard teleop_twist_keyboard
   ```
4. Build their own map
   - Launch Gazebo
   - Add obstacles
   - Save map
6. Edit code to change map
   - cp/mv world file into the worlds directory in jackal_ws/src/jackal_simulator/jackal_gazebo/worlds/
   - Edit jackal_world.launch.py in jackal_ws/src/jackal_simulator/jackal_gazebo/launch/
