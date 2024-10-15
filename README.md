# ROS2_Workshop
  
# Installation

## Windows

1. [Install docker](https://desktop.docker.com/win/main/amd64/Docker%20Desktop%20Installer.exe)
3. **After docker is installed**, install WSL by launching Windows Powershell as **administrator** and running the following command
   
    ```powershell
    wsl --install
    ```
    
4. Enable Ubuntu in Docker Desktop settings
    - Navigate to settings in Docker Desktop
    - Under Resources > WSL integration
    - Enable the Ubuntu option then click "Apply and Restart"
  
5. After it's done installing run the following commands to start WSL

   ```powershell
   wsl --set-default Ubuntu
   wsl ~
   ```
6. Clone this repository
   ```sh
   git clone https://github.com/NTU-Autonomous-Racing-Team/F1Tenth_Workshop.git ~/F1Tenth_Workshop/
   ```
   > If you can't copy paste, right click powershell then navigate to `Properties > Tick "Use Ctrl+Shift+C/V as copy paste`"
8. Docker Setup
    - Setting up docker container
      
      ```sh
      cd ~/F1Tenth_Workshop/install_windows/
      sudo docker network create f1tenth_net
      sudo docker build -t f1tenth_gym_ros .
      ```

    - Run this script to start the docker container
      ```sh
      sudo ./run_docker_container_win.sh
      ```
      
## MacOS

### **If you have homebrew installed already, you can skip to installing git**
   - Make sure xcode-select is installed by launching a terminal and running this command
     ```sh
     xcode-select --install
     ```
     > If it is installed you will see this in your terminal
     >
     > `xcode-select: note: Command line tools are already installed. Use "Software Update" in System Settings or the softwareupdate command line interface to install updates`
     > 
     > This step will take some time if you don't have xcode installed
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
     git clone https://github.com/NTU-Autonomous-Racing-Team/F1Tenth_Workshop.git ~/F1Tenth_Workshop/
     ```
3. Launch Docker
4. Docker Setup
    - Setting up docker containers
      ```sh
      cd ~/F1Tenth_Workshop/install_macos/
      docker compose -p f1tenth_gym_ros up -d
      ```
    
    - Run this script to start the docker containers
      ```sh
      sudo ./run_docker_containers_mac.sh
      ```
      
## Ubuntu Linux

1. [Install docker](https://docs.docker.com/engine/install/ubuntu/)
2. [Add Docker into sudo group ](https://docs.docker.com/engine/install/linux-postinstall/)
3. Clone this repository
   
    ```sh
    git clone https://github.com/NTU-Autonomous-Racing-Team/F1Tenth_Workshop.git ~/F1Tenth_Workshop/
    ```
    
5. Docker Setup
    - Setting up docker container      
      ```sh
      cd ~/F1Tenth_Workshop/install_linux/
      sudo docker network create f1tenth_net
      sudo docker build -t f1tenth_gym_ros .
      ```

    - Run this script to start the docker container
      ```sh
      sudo ./run_docker_container.sh
      ```

# Running the simulator

In your respective terminals run 
> Windows users need to make sure they're in WSL
```sh
source /opt/ros/foxy/setup.bash
source ./install/local_setup.bash
ros2 launch f1tenth_gym_ros gym_bridge_launch.py
```
If everything is working, a window should pop up (It might take awhile for the simulation to startup when ran for the first time). For MacOS users click on this link [http://localhost:8080/vnc.html](http://localhost:8080/vnc.html) and click on connect to view the simulation.
