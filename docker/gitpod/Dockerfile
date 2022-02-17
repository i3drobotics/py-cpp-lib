FROM ubuntu:focal

# Install development dependices
RUN apt-get update && \
    TZ=Europe/London \
    DEBIAN_FRONTEND=noninteractive \
    apt-get install -y \
    sudo git build-essential gdb && \
    rm -rf /var/lib/apt/lists/*

### Gitpod user ###
# '-l': see https://docs.docker.com/develop/develop-images/dockerfile_best-practices/#user
RUN useradd -l -u 33333 -G sudo -md /home/gitpod -s /bin/bash -p gitpod gitpod \
    # passwordless sudo for users in the 'sudo' group
    && sed -i.bkp -e 's/%sudo\s\+ALL=(ALL\(:ALL\)\?)\s\+ALL/%sudo ALL=NOPASSWD:ALL/g' /etc/sudoer
USER gitpod

# Install project dependencies
RUN sudo apt-get update && \
    sudo TZ=Europe/London \
    DEBIAN_FRONTEND=noninteractive \
    apt-get install -y \
    libboost-all-dev \
    python3-dev \
    cmake g++ && \
    sudo rm -rf /var/lib/apt/lists/*
