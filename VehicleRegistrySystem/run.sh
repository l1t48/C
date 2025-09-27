#!/bin/bash

docker build -t c-lab .
docker run --rm -it c-lab
