FROM ubuntu:focal

# Install minimal gitpod dependices
RUN apt-get update && \
    TZ=Europe/London \
    DEBIAN_FRONTEND=noninteractive \
    apt-get install -y \
    git && \
    rm -rf /var/lib/apt/lists/*

# Install project dependencies
RUN apt-get update && \
    TZ=Europe/London \
    DEBIAN_FRONTEND=noninteractive \
    apt-get install -y \
    libboost-all-dev \
    python3-dev \
    cmake g++ && \
    rm -rf /var/lib/apt/lists/*