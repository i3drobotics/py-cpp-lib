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

# Add project files
ADD py /py-cpp-lib/py
ADD src /py-cpp-lib/src
ADD include /py-cpp-lib/include
ADD CMakeLists.txt config.h.in /py-cpp-lib/

WORKDIR /py-cpp-lib
# Build project
RUN mkdir build && \
    cd build && \
    cmake .. && \
    make -j4
