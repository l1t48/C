#!/bin/bash

docker rm -f $(docker ps -a -q) 2>/dev/null
docker rmi -f c-lab 2>/dev/null
echo "Cleanup complete."
