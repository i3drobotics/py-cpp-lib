# Python boost C++ example
Example for creating a C++ library from a python module

## Build

### Linux
Install dependencies
```
sudo apt-get install libboost-all-dev python3-dev cmake g++
```

Build using cmake
```
mkdir build
cd build
cmake ..
make
```

### Windows
Install dependencies using [chocolatey](https://chocolatey.org/install#individual)
```
choco install cmake
choco install boost-msvc-14.2
choco install visualstudio2019community
```