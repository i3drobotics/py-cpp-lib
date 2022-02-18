FROM ubuntu:focal

# Install development dependencies
RUN apt-get update && \
    TZ=Europe/London \
    DEBIAN_FRONTEND=noninteractive \
    apt-get install -y \
    sudo git build-essential gdb && \
    rm -rf /var/lib/apt/lists/*

### Non root user ###
# '-l': see https://docs.docker.com/develop/develop-images/dockerfile_best-practices/#user
RUN useradd -l -u 33333 -G sudo -md /home/nonrootuser -s /bin/bash -p nonrootuser nonrootuser \
    # passwordless sudo for users in the 'sudo' group
    && sed -i.bkp -e 's/%sudo\s\+ALL=(ALL\(:ALL\)\?)\s\+ALL/%sudo ALL=NOPASSWD:ALL/g' /etc/sudoers
ENV HOME=/home/nonrootuser
WORKDIR $HOME

### Non root user (2) ###
USER nonrootuser
# use sudo so that user does not get sudo usage info on (the first) login
RUN sudo echo "Running 'sudo' for Non root user: success" && \
    # create .bashrc.d folder and source it in the bashrc
    mkdir -p /home/nonrootuser/.bashrc.d && \
    (echo; echo "for i in \$(ls -A \$HOME/.bashrc.d/); do source \$HOME/.bashrc.d/\$i; done"; echo) >> /home/nonrootuser/.bashrc

# Install project dependencies
RUN sudo apt-get update && \
    sudo TZ=Europe/London \
    DEBIAN_FRONTEND=noninteractive \
    apt-get install -y \
    python3-dev \
    cmake g++ && \
    sudo rm -rf /var/lib/apt/lists/*

# Install boost
RUN git clone https://github.com/boostorg/boost.git -b boost-1.74.0
RUN cd boost && \
    git submodule update --init tools/boostdep && \
    git submodule update --init libs/python && \
    python3 tools/boostdep/depinst/depinst.py python && \
    ./bootstrap.sh --with-python=python3 && \
    ./b2 --with-python
    
RUN mkdir $HOME/python-boost-cpp-example

# Add project files
ADD .vscode $HOME/python-boost-cpp-example/.vscode
ADD py $HOME/python-boost-cpp-example/py
ADD src $HOME/python-boost-cpp-example/src
ADD include $HOME/python-boost-cpp-example/include
ADD CMakeLists.txt config.h.in $HOME/python-boost-cpp-example/

WORKDIR $HOME/python-boost-cpp-example
# Build project
RUN mkdir build && \
    cd build && \
    cmake -DBOOST_ROOT=$HOME/boost .. && \
    make -j4
RUN cd build && \
    ./PyHelloApp