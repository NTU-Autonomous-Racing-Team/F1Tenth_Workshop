#!/bin/zsh

container_name=ASME_ROS

if [ "$(docker ps -aq -f status=exited -f name=${container_name})" ]
then
	docker start ${container_name}
fi

docker exec -it ${container_name} /bin/zsh

xhost +local:root
