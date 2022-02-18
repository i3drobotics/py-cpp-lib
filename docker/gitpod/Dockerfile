FROM gitpod/workspace-base:latest

# Install dependencies
RUN sudo apt-get update && \
    sudo TZ=Europe/London \
    DEBIAN_FRONTEND=noninteractive \
    apt-get install -y \
    build-essential gdb \
    python3-dev cmake g++ && \
    sudo rm -rf /var/lib/apt/lists/*

# Install boost
RUN git clone https://github.com/boostorg/boost.git -b boost-1.74.0 && \
    cd boost && \
    git submodule update --init tools/boostdep && \
    git submodule update --init libs/python && \
    python3 tools/boostdep/depinst/depinst.py python && \
    ./bootstrap.sh --with-python=python3 && \
    ./b2 --with-python