#!/bin/bash

# Remove compiled files and Docker images
make clean
docker rmi main
