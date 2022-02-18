# Python boost C++ example
Example for creating a C++ library from a python module

## Build

### Linux
Install dependencies using apt-get:
```
sudo apt-get install python3-dev cmake g++
```

Install boost python:
```
git clone https://github.com/boostorg/boost.git -t boost-1.74.0
cd boost
git submodule update --init tools/boostdep
git submodule update --init libs/python
python3 tools/boostdep/depinst/depinst.py python
./bootstrap.sh
./b2 --with-python
```

Build project using cmake:
```
mkdir build
cd build
cmake -DBOOST_ROOT=./boost ..
make
```

### Windows
Install required packages:
- [Visual Studio](https://visualstudio.microsoft.com/downloads/)
- [Python](https://www.python.org/downloads/)
- [CMake](https://cmake.org/download/)

These can be installed using [chocolatey](https://chocolatey.org/install#individual):
```
choco install -y visualstudio2019community --package-parameters "--allWorkloads --includeRecommended --passive"
choco install python --version 3.9
choco install cmake --installargs 'ADD_CMAKE_TO_PATH=System'
```

Install boost python:
```
git clone https://github.com/boostorg/boost.git
cd boost
git submodule update --init tools/boostdep
git submodule update --init libs/python
python tools/boostdep/depinst/depinst.py python
bootstrap
.\b2 --with-python
```

Build project using cmake:
```
mkdir build
cd build
cmake -G "Visual Studio 16 2019" -A x64 -DBOOST_ROOT=./boost ..
cmake --build .
```