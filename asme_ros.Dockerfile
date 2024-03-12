FROM ros:foxy

SHELL ["/bin/bash", "-c"]

# dependencies
RUN apt-get update --fix-missing && \
    apt-get install -y ros-foxy-rviz2 \
		       vim \
		       wget \
		       zsh

RUN apt-get -y dist-upgrade

RUN mkdir -p ~/jackal_ws/src && \
    cd ~/jackal_ws/src 

RUN git clone -b foxy-devel https://github.com/jackal/jackal.git && \
    git clone -b foxy-devel https://github.com/jackal/jackal_desktop.git && \
    git clone -b foxy-devel https://github.com/jackal/jackal_simulator.git

RUN cd ~/jackal_ws && \
    source /opt/ros/foxy/setup.bash && \
    apt-get update --fix-missing && \
    rosdep install --from-paths src --ignore-src --rosdistro=$ROS_DISTRO -y && \
    colcon build

RUN echo "source /opt/ros/foxy/setup.zsh" > ~/.zshrc && \
    echo "source /root/jackal_ws/install/local_setup.zsh" >> ~/.zshrc

WORKDIR '~/jackal_files'

ENTRYPOINT ["/bin/zsh"]
