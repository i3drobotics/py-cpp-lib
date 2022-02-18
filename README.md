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
choco install -y visualstudio2019community --package-parameters "--allWorkloads --includeRecommended --passive"
choco install python --version 3.9
choco install cmake --installargs 'ADD_CMAKE_TO_PATH=System'
choco install boost-msvc-14.2
```
Build boost for installed python version
```
cd 
bootstrap
.\b2 --with-python
```

Build using cmake
```
mkdir build
cd build
cmake -G "Visual Studio 16 2019" -A x64 ..
cmake --build .
```