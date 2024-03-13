# ROS2_Workshop
- This repo is to contain all the code and files for the ROS2 workshop 2024
- The main idea is that the main will be git cloned into the ros_ws and then ran. 
- Objective: users get an introdution to ROS and how to use it in real life. i.e. not the nitty gritty details. 

## Brainstorm
- Swapping planners within jackal
- changing maps
- rviz 
- gazebo
  
# Installation

 
## Ubuntu Linux

1. [Install docker](https://docs.docker.com/engine/install/ubuntu/)
2. [Add Docker into sudo group ](https://docs.docker.com/engine/install/linux-postinstall/)

```sh
# Clone github repository
git clone https://github.com/ASME-NTU/ROS2_Workshop.git

# Setting up docker container
sudo docker create network asme_net
sudo docker build -f asme_ros.Dockerfile -t asme_ros .

# Run script to start docker container
./run_docker_container.sh
```

## MacOS

```sh
# Clone github repository
git clone https://github.com/ASME-NTU/ROS2_Workshop.git

# Setting up docker container
cd macos_install
docker compose -p asme_ros up

# Run script to start docker container
./run_docker_container.sh
```

## Syllabus
> Part 1: Hello ROS
> -  the elements of ROS, Command line tools, 
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
