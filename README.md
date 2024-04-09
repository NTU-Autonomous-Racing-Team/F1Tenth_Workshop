# ROS2_Workshop
  
# Installation

## Windows

1. [Install docker](https://desktop.docker.com/win/main/amd64/Docker%20Desktop%20Installer.exe)
3. Install WSL by launching Windows Powershell as **administrator** and running the following command
   
    ```powershell
    wsl --install
    ```
    
4. Enable Ubuntu in Docker Desktop settings
    - Navigate to settings in Docker Desktop
    - Under Resources > WSL integration
    - Enable the Ubuntu option
  
5. After it's done installing run the following commands to start WSL

   ```powershell
   wsl --set-default Ubuntu
   wsl ~
   ```
6. Clone this repository
   ```sh
   git clone https://github.com/ASME-NTU/ROS2_Workshop.git ~/ROS2_Workshop/
   ```
   If you can't copy paste, right click powershell then navigate to Properties > Tick "Use Ctrl+Shift+C/V as copy paste"
8. Docker Setup
    - Setting up docker container
      
      ```sh
      cd ~/ROS2_Workshop/install_windows/
      sudo docker network create asme_net
      sudo docker build -f asme_ros.Dockerfile -t asme_ros .
      ```

    - Run this script to start the docker container
      ```sh
      ./run_docker_container_win.sh
      ```
      
## MacOS

1. Installing dependencies
   - Make sure xcode-select is installed by launching a terminal and running this command
     ```sh
     xcode-select --install
     ```
   - Install Homebrew
     ```sh
     /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
     ```
   - Install git
   
     ```sh
     brew install git
     ```
   - [Install docker](https://docs.docker.com/desktop/install/mac-install/)
2.  Clone this repository
   
     ```sh
     git clone https://github.com/ASME-NTU/ROS2_Workshop.git ~/ROS2_Workshop/
     ```
3. Docker Setup
    - Setting up docker containers
      ```sh
      cd ~/ROS2_Workshop/install_macos/
      docker compose -p asme_ros up -d
      ```
      **CTRL+C** after everything is done to stop the docker containers
    
    - Run this script to start the docker containers
      ```sh
      ./run_docker_containers_mac.sh
      ```
      
## Ubuntu Linux

1. [Install docker](https://docs.docker.com/engine/install/ubuntu/)
2. [Add Docker into sudo group ](https://docs.docker.com/engine/install/linux-postinstall/)
3. Clone this repository
   
    ```sh
    git clone https://github.com/ASME-NTU/ROS2_Workshop.git ~/ROS2_Workshop/
    ```
    
5. Docker Setup
    - Setting up docker container      
      ```sh
      cd ~/ROS2_Workshop/install_linux/
      sudo docker network create asme_net
      sudo docker build -f asme_ros.Dockerfile -t asme_ros .
      ```

    - Run this script to start the docker container
      ```sh
      ./run_docker_container.sh
      ```

# Running the simulator

In your respective terminals run (Windows users need to make sure they're in WSL)
```sh
cd jackal_ws/
source /opt/ros/foxy/setup.bash
source ./install/local_setup.bash
ros2 launch jackal_gazebo jackal_world.launch.py
```
If everything is working, a window should pop up (It might take awhile as the simulation takes time to startup when first ran). For MacOS users click on this link [http://localhost:8080/vnc.html](http://localhost:8080/vnc.html) to view the simulation.

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
