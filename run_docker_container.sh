#!/bin/sh

container_name=asme_ros

xhost + local:host &&

docker run -it \
--env="DISPLAY"\
--env="QT_X11_NO_MITSHM=1" \
--volume="/tmp/.X11-unix:/tmp/.X11-unix:rw" \
--volume="/home/luthov/.Xauthority:/root/.Xauthority" \
--privileged \
--net=host \
asme_ros
