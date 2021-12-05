# Step 1: Download docker
# https://www.docker.com/get-started

# Step 2: Create a Dockerfile
FROM centos
RUN yum update -y
RUN yum -y install vim
RUN yum -y install gdb
RUN dnf -y group install "Development Tools"

# Step 3: Build an image
# build an image (note the “.”)
docker build -f Dockerfile -t dockerdev .

# Step 4: Create a container
# create a container
docker run -it dockerdev bash

# join an existing container
container=`docker ps | tail -1 | awk '{print $1}'`
docker exec -it $container bash
