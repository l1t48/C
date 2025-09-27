#!/bin/bash

# Build Docker image
docker build -t lab-app .

# Run Docker container interactively
docker run -it --rm lab-app
