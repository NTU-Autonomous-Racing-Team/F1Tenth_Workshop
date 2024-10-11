container_name=f1tenth_gym_ros

if [ "$(docker ps -aq -f status=running -f name=${container_name})" ]
then
	echo "Container is Running. Starting new session." && \
	docker exec -it f1tenth_gym_ros-sim-1 bash
else
	docker start f1tenth_gym_ros-sim-1 && \
	docker start f1tenth_gym_ros-novnc-1
  docker exec -it f1tenth_gym_ros-sim-1 bash
fi
