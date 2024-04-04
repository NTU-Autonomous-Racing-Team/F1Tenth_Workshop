1. Let them echo the sensor topics, talk about the sensor msg and show them the components
   - ```sh
     ros2 topic echo /scan
     ros2 topic echo /odom
     ros2 topic echo --no-arr /odom
     ```
2. Launch Rviz and show them how to visualise the sensor data
   - Show jackal view model
     ```sh
     ros2 launch jackal_viz view_model.launch.py
     ```
   - Show with new session of Rviz
  
