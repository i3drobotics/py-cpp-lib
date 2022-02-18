FROM ubuntu:focal

# Install development dependencies
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
    python3-dev \
    cmake g++ && \
    sudo rm -rf /var/lib/apt/lists/*

WORKDIR /
# Install boost
RUN git clone https://github.com/boostorg/boost.git && \
    cd boost && \
    git submodule update --init tools/boostdep && \
    git submodule update --init libs/python && \
    python3 tools/boostdep/depinst/depinst.py python && \
    ./bootstrap.sh && \
    ./b2 --with-python
RUN sudo chown -R nonrootuser:nonrootuser /boost

# Add project files
ADD .vscode /workspace/py-cpp-lib/.vscode
ADD py /workspace/py-cpp-lib/py
ADD src /workspace/py-cpp-lib/src
ADD include /workspace/py-cpp-lib/include
ADD CMakeLists.txt config.h.in /workspace/py-cpp-lib/

RUN sudo chown -R nonrootuser:nonrootuser /workspace/py-cpp-lib

WORKDIR /workspace/py-cpp-lib
# Build project
RUN mkdir build && \
    cd build && \
    cmake -DBOOST_ROOT=/boost .. && \
    make -j4
RUN cd build && \
    ./PyHelloApp