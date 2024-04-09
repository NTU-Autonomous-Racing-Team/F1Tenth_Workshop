# ROS2_Workshop
  
# Installation

## Windows

1. [Install docker](https://desktop.docker.com/win/main/amd64/Docker%20Desktop%20Installer.exe)
3. Install WSL by launching Windows Powershell and running the following command
   
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
   git clone https://github.com/ASME-NTU/ROS2_Workshop.git ~/
   ```
8. Docker Setup
    - Setting up docker container
      
      ```sh
      cd ~/ROS2_Workshop/windows_install/
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
     git clone https://github.com/ASME-NTU/ROS2_Workshop.git ~/
     ```
3. Docker Setup
    - Setting up docker containers
      ```sh
      cd ~/ROS2_Workshop/macos_install
      docker compose -p asme_ros up -d
      ```
    
    - Run this script to start the docker containers
      ```sh
      ./run_docker_containers_mac.sh
      ```
      
## Ubuntu Linux

1. [Install docker](https://docs.docker.com/engine/install/ubuntu/)
2. [Add Docker into sudo group ](https://docs.docker.com/engine/install/linux-postinstall/)
3. Clone this repository
   
    ```sh
    git clone https://github.com/ASME-NTU/ROS2_Workshop.git ~/
    ```
    
5. Docker Setup
    - Setting up docker container      
      ```sh
      cd ~/ROS2_Workshop/linux_install/
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
If everything is working, a window should pop up. For MacOS users click on this link [http://localhost:8080/vnc.html](http://localhost:8080/vnc.html) to view the simulation.
