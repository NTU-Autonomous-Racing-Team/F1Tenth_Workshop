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

# F1Tenth Simulator

---

## Launch The Simulator

Open a terminal in the docker container
```sh
source /opt/ros/foxy/setup.bash
source ./install/local_setup.bash
ros2 launch f1tenth_gym_ros gym_bridge_aunch.py
```

---

## F1Tenth Topics

Open a new terminal in the container
```sh
ros2 topic list
```
Topics related to the car
```
/drive              # Drive command via AckermannDriveStamped messages
/ego_racecar/odom   # Odometry of the car
/scan               # Lidar Scans
/cmd_vel            
```
<!-- ros2 topic pub /drive {...}
ros2 topic echo /laser -->
---

## Publishing a Drive Command

`ros2 topic pub -r <Hz> <topic_name> <msg_type> <msg_atributes?>`

`ros2 topic pub -r 1 /drive ackermann_msgs/msg/AckermannDriveStamped "drive: {'speed': 1.0, 'steering_angle': 0.5}"`

---

## Echoing Odom

```sh
ros2 topic echo ego_racecar/odom --no-arr
```

> NOTE: The `--no-arr` argument is to prevent displaying large covariance arrays

---
## Driving The Car Via Teleoperation

Keyboard Teleoperation
```sh
ros2 run teleop_twist_keyboard teleop_twist_keyboard
```

---

## Changing The Map

- Stop the simulator from running using `CTRL+C`
- Navigate to `/sim_ws/src/f1tenth_gym_ros/config` and edit the `sim.yaml` file
  ```yaml
      # map parameters
      map_path: '/sim_ws/src/f1tenth_gym_ros/maps/Spielberg_map'
      map_img_ext: '.png'
  ```

- Rebuild the workspace
  ```sh
  colcon build
  source install/local_setup.bash
  ```

---

## Driving The Car Autonomously

Local Planner (Gap Finder)
```sh
cd /f1tenth_workshop/f1tenth_simulator
python3 gap_finder_base.py
```

<!-- ---

## Adding An Opponent Car (Opponent car is invisible what do)

In the same file
```yaml
    # opponent parameters
    num_agent: 2
```

Rebuild the workspace
```sh
colcon build
source install/local_setup.bash
``` -->