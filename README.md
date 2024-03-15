# ROS2_Workshop
  
# Installation

**Clone this repository**
```sh
git clone https://github.com/ASME-NTU/ROS2_Workshop.git
```
 
## Ubuntu Linux

1. [Install docker](https://docs.docker.com/engine/install/ubuntu/)
2. [Add Docker into sudo group ](https://docs.docker.com/engine/install/linux-postinstall/)

**Setting up docker container**
```sh
sudo docker create network asme_net
sudo docker build -f asme_ros.Dockerfile -t asme_ros .
```

**Run script to start docker container**
```sh
./run_docker_container.sh
```

## MacOS

1. [Install docker](https://docs.docker.com/desktop/install/mac-install/)

**Setting up docker container**
```sh
cd macos_install
docker compose -p asme_ros up
```
CTRL+C after everything is done to stop the docker containers

**Run script to start docker container**
```sh
./run_docker_containers_mac.sh
```
Then go to this link [http://localhost:8080/vnc.html](http://localhost:8080/vnc.html) to view the simulation
## Brainstorm
- Swapping planners within jackal
- changing maps
- rviz 
- gazebo
  
## Syllabus
> Part 1: Hello ROS
> -  The elements of ROS, Command line tools, General command line tools 
>> 1. What is ROS? "use terminal to show rqtgraph of the whole thing that they will be building"  
>> 2. Messages, Nodes, Services, Actions, Packages  
>> Publisher-Subsciber [CODE]
>>> 2.1 building ros_ws  
>>> 2.2 building packages  
>>> 2.3 python3, ros2 run [CODE] and ros2 launch [CODE]

> Part 2: Interacting with ROS
>> Gazebo - simulator with physics engine i.e diffeereent from rviz  
>> jackal bot - teleop no obs
>> - changing map [CODE]

> Part 3: Sensing and Measurments
>> Pose and Odometry - one liners  
>> Lidar and Camera - selecting what to visualise
>> RVIZ

> Part 4: Navigation and Local Planning  
> - communicate the theory/ working principle of the planner. 
>> Bug0 \[Luthov CODE](main\), Bug1, Bug2 (optional  [CODE]) 
>> - self written into a separate script. (fill in the blanks)
>> - build package
>> DWA, TEB [visualise CODE]
>> - swapping planners [CODE]

## Dependencies


> ROS: Foxy
>> [ROS-foxy Docs](https://docs.ros.org/en/foxy/Tutorials.html)
