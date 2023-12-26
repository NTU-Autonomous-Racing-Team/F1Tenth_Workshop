#!/bin/zsh

if [ "$(docker ps -aq -f status=exited -f name=${container_name})" ]
then
	docker start asme_ros &
	docker start novnc
fi

docker exec -it asme_ros /bin/zsh
