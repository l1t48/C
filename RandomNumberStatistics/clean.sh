#!/bin/bash

# Remove Docker image
docker rmi lab-app

# Remove dangling containers and images
docker system prune -f
