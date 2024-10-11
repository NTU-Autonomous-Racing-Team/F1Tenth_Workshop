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

## Launching The Simulator

```sh
source /opt/ros/foxy/setup.bash
source ./install/local_setup.bash
ros2 launch f1tenth_gym_ros gym_launch.py
```

> NOTE: Make sure in docker container ##

---

## Example Commands

```sh
ros2 topic list
ros2 topic pub /drive {...}
ros2 topic echo /laser
```

---

## Driving The Car

```sh
ros2 run teleop_twist_keyboard teleop_twist_keyboard
```
```sh
cd ...
python3 gap_finder_base 
```

---

## Changing The Map

**What text editor to use**
```sh
cd /sim_ws/
vim? src/f1tenth_gym_ros/config/sim.yaml
```

Edit the file
```yaml
    # map parameters
    map_path: '/sim_ws/src/f1tenth_gym_ros/maps/Spielberg_map'
    map_img_ext: '.png'
```

---

## Adding An Opponent Car

In the same file
```yaml
    # opponent parameters
    num_agent: 1
```