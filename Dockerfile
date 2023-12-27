FROM ros:foxy

SHELL ["/bin/bash", "-c"]

# dependencies
RUN apt-get update --fix-missing && \
    apt-get install -y ros-foxy-rviz2 \
		       vim \
		       wget \
		       zsh
RUN wget https://packages.clearpathrobotics.com/public.key -O - | sudo apt-key add - && \
    sudo sh -c 'echo "deb https://packages.clearpathrobotics.com/stable/ubuntu $(lsb_release -cs) main" > /etc/apt/sources.list.d/clearpath-latest.list' && \
    apt-get update && \
    apt-get install ros-foxy-jackal-desktop ros-foxy-jackal-simulator

RUN touch /root/.zshrc && \
    echo "source /opt/ros/foxy/setup.zsh" > /root/.zshrc

WORKDIR '/root/jackal_files'

ENTRYPOINT ["/bin/zsh"]
