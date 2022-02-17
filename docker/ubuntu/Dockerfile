FROM ubuntu:focal

RUN apt-get update && \
    TZ=Europe/London \
    DEBIAN_FRONTEND=noninteractive \
    apt-get install -y \
    libboost-all-dev \
    python3-dev \
    cmake g++ && \
    rm -rf /var/lib/apt/lists/*

ADD py /py-cpp-lib/py
ADD src /py-cpp-lib/src
ADD include /py-cpp-lib/include
ADD CMakeLists.txt config.h.in /py-cpp-lib/

WORKDIR /py-cpp-lib

RUN mkdir build && \
    cd build && \
    cmake .. && \
    make -j4