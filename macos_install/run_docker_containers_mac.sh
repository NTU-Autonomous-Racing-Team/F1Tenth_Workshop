container_name=asme_ros

if [ "$(docker ps -aq -f status=running -f name=${container_name})" ]
then
	echo "Container is Running. Starting new session." && \
	docker exec -it asme_ros-sim-1 bash
else
	docker start asme_ros-sim-1 && \
	docker start asme_ros-novnc-1
  docker exec -it asme_ros-sim-1 zsh
fi
