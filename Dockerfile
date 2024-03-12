FROM ros:foxy

SHELL ["/bin/bash", "-c"]

# dependencies
RUN apt-get update --fix-missing && \
    apt-get install -y ros-foxy-rviz2 \
		       vim \
		       wget \
		       zsh \
           

# RUN wget https://packages.clearpathrobotics.com/public.key -O - | apt-key add - && \
#     sh -c 'echo "deb https://packages.clearpathrobotics.com/stable/ubuntu $(lsb_release -cs) main" > /etc/apt/sources.list.d/clearpath-latest.list' && \
#     apt-get update && \
#     apt-get install ros-foxy-jackal-desktop ros-foxy-jackal-simulator
RUN mkdir -p ~/jackal_ws/src && \
    cd ~/jackal_ws/src && \
    git clone -b foxy-devel https://github.com/jackal/jackal.git && \
    git clone -b foxy-devel https://github.com/jackal/jackal_desktop.git && \
    git clone -b foxy-devel https://github.com/jackal/jackal_simulator.git && \
    cd ..

RUN cd ~/jackal_ws && \
    source /opt/ros/foxy/setup.bash && \
    rosdep install --from-paths src --ignore-src --rosdistro=$ROS_DISTRO -y && \
    colcon build

RUN touch /root/.zshrc && \
    echo "source /opt/ros/foxy/setup.zsh" > /root/.zshrc && \
    echo "source /root/jackal_ws/install/local_setup.zsh" >> /root/.zshrc

WORKDIR '/root/jackal_files'

ENTRYPOINT ["/bin/zsh"]
