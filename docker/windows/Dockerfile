# escape=`

FROM mcr.microsoft.com/dotnet/framework/sdk:4.8-windowsservercore-ltsc2019

# Install dependencies
ENV chocolateyUseWindowsCompression false
SHELL ["powershell", "-Command", "$ErrorActionPreference = 'Stop'; $ProgressPreference = 'SilentlyContinue';"]
RUN iex ((new-object net.webclient).DownloadString('https://chocolatey.org/install.ps1')); `
    choco feature disable --name showDownloadProgress;
RUN choco install -y git; `
    choco install -y cmake --installargs 'ADD_CMAKE_TO_PATH=System'; `
    choco install -y python;
RUN choco install -y visualstudio2019buildtools --package-parameters "--allWorkloads --includeRecommended --passive"

# TODO fix visual studio not installed correctly
# issue: https://github.com/MicrosoftDocs/visualstudio-docs/issues/7278#issuecomment-1032098722

SHELL ["cmd", "/S", "/C"]

# Add git to path
RUN setx path "C:\\Program Files\\Git\\bin;%path%"

# Add workspace
WORKDIR /workspace

# Add project files
ADD .vscode /workspace/python-boost-cpp-example/.vscode
ADD py /workspace/python-boost-cpp-example/py
ADD src /workspace/python-boost-cpp-example/src
ADD include /workspace/python-boost-cpp-example/include
ADD CMakeLists.txt config.h.in /workspace/python-boost-cpp-example/

# WORKDIR /workspace/python-boost-cpp-example
# # Build project
# RUN mkdir build && `
#     cd build && `
#     cmake -G "Visual Studio 16 2019" -A x64 .. 
# RUN cmake --build .
# RUN cd build && `
#     ./PyHelloApp.exe