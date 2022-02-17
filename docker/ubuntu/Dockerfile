FROM ubuntu:focal

# Install development dependices
RUN apt-get update && \
    TZ=Europe/London \
    DEBIAN_FRONTEND=noninteractive \
    apt-get install -y \
    sudo git build-essential gdb && \
    rm -rf /var/lib/apt/lists/*

# Add non root user
RUN adduser --disabled-password --gecos '' nonrootuser
RUN adduser nonrootuser sudo
RUN echo '%sudo ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers
USER nonrootuser

# Add workspace
WORKDIR /workspace
RUN sudo chown -R nonrootuser:nonrootuser /workspace && \
    sudo chmod 755 /workspace

# Install project dependencies
RUN sudo apt-get update && \
    sudo TZ=Europe/London \
    DEBIAN_FRONTEND=noninteractive \
    apt-get install -y \
    libboost-all-dev \
    python3-dev \
    cmake g++ && \
    sudo rm -rf /var/lib/apt/lists/*

# Add project files
ADD py /workspace/py-cpp-lib/py
ADD src /workspace/py-cpp-lib/src
ADD include /workspace/py-cpp-lib/include
ADD CMakeLists.txt config.h.in /workspace/py-cpp-lib/

RUN sudo chown -R nonrootuser:nonrootuser /workspace

WORKDIR /workspace/py-cpp-lib
# Build project
RUN mkdir build && \
    cd build && \
    cmake .. && \
    make -j4
