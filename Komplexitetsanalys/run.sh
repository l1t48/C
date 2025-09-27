#!/bin/bash

# Build Docker image
docker build -t main .

# Run Docker container
docker run --rm -it main
