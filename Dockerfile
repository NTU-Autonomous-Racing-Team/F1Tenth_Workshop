FROM ros:foxy

SHELL ["/bin/bash", "-c"]

# dependencies
RUN apt-get update --fix-missing && \
    apt-get install -y ros-foxy-rviz2 \
		       vim \
		       zsh

RUN touch /root/.zshrc && \
    echo "source /opt/ros/foxy/setup.zsh" > /root/.zshrc

WORKDIR '/root/jackal_files'

ENTRYPOINT ["/bin/zsh"]
