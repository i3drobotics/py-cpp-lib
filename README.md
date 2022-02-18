# Python boost C++ example
Example for creating a C++ library from a python module

## Build

### Linux
Install dependencies:
```
sudo apt-get install libboost-all-dev python3-dev cmake g++
```

Build project using cmake:
```
mkdir build
cd build
cmake ..
make
```

### Windows
Dependencies can be installed easily using [chocolatey](https://chocolatey.org/install#individual).  
If it's not already installed, run the following command in an admin powershell terminal:
```
Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))
```

Install the dependencies using chocolatey:
```
choco install -y visualstudio2019community --package-parameters "--allWorkloads --includeRecommended --passive"
choco install python --version 3.9
choco install cmake --installargs 'ADD_CMAKE_TO_PATH=System'
choco install boost-msvc-14.2
```

Build boost for installed python version:
```
cd C:\local\boost_*
bootstrap
.\b2 --with-python
```

Build project using cmake:
```
mkdir build
cd build
cmake -G "Visual Studio 16 2019" -A x64 ..
cmake --build .
```