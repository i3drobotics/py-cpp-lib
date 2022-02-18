FROM ubuntu:focal

# Install development dependencies
RUN apt-get update && \
    TZ=Europe/London \
    DEBIAN_FRONTEND=noninteractive \
    apt-get install -y \
    sudo git build-essential gdb && \
    rm -rf /var/lib/apt/lists/*

# Install project dependencies
RUN apt-get update && \
    TZ=Europe/London \
    DEBIAN_FRONTEND=noninteractive \
    apt-get install -y \
    python3-dev \
    cmake g++ && \
    rm -rf /var/lib/apt/lists/*

# Install boost
RUN git clone https://github.com/boostorg/boost.git && \
    cd boost && \
    git submodule update --init tools/boostdep && \
    git submodule update --init libs/python && \
    python3 tools/boostdep/depinst/depinst.py python && \
    ./bootstrap.sh && \
    ./b2 --with-python