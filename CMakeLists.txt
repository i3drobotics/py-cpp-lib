cmake_minimum_required(VERSION 3.9)

set(PROJECT_NAME_READABLE "PyHello")
set(PROJECT_NAME_NO_SPACES "PyHello")

set(PROJECT_VER_MINOR_PATCH "0")
project(${PROJECT_NAME_NO_SPACES} VERSION "0.0.1")
configure_file(${PROJECT_SOURCE_DIR}/config.h.in ${PROJECT_BINARY_DIR}/config.h)

# Define GNU standard installation directories
include(GNUInstallDirs)

include_directories(
	${PROJECT_SOURCE_DIR}/src
	${PROJECT_SOURCE_DIR}/include
)

FIND_PACKAGE(PythonInterp)
if (PYTHONINTERP_FOUND)
  if (UNIX AND NOT APPLE)
    if (PYTHON_VERSION_MAJOR EQUAL 3)
        FIND_PACKAGE(Boost COMPONENTS python${PYTHON_VERSION_SUFFIX})
        FIND_PACKAGE(PythonInterp 3)
        FIND_PACKAGE(PythonLibs 3 REQUIRED)
    else()
        FIND_PACKAGE(Boost COMPONENTS python)
        FIND_PACKAGE(PythonInterp)
        FIND_PACKAGE(PythonLibs REQUIRED)
    endif()
  else()	
    if (PYTHON_VERSION_MAJOR EQUAL 3)
        FIND_PACKAGE(Boost COMPONENTS python${PYTHON_VERSION_MAJOR}${PYTHON_VERSION_MINOR})
        FIND_PACKAGE(PythonInterp 3)
        FIND_PACKAGE(PythonLibs 3 REQUIRED)
    else()
        FIND_PACKAGE(Boost COMPONENTS python${PYTHON_VERSION_MAJOR}${PYTHON_VERSION_MINOR})
        FIND_PACKAGE(PythonInterp)
        FIND_PACKAGE(PythonLibs REQUIRED)
    endif()
  endif()
else()
    message("Python not found")
endif()

FIND_PACKAGE(Boost COMPONENTS python)

message(STATUS "PYTHON_LIBRARIES = ${PYTHON_LIBRARIES}")
message(STATUS "PYTHON_EXECUTABLE = ${PYTHON_EXECUTABLE}")
message(STATUS "PYTHON_INCLUDE_DIRS = ${PYTHON_INCLUDE_DIRS}")
message(STATUS "Boost_LIBRARIES = ${Boost_LIBRARIES}")

include_directories(${PYTHON_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})

set(HEADERS
	${HEADERS}
  include/pyhelper.hpp
	include/pyhello.hpp
)

set(SOURCES
	${SOURCES}
	src/main.cpp
)

add_executable( ${PROJECT_NAME} ${HEADERS} ${SOURCES} )
target_link_libraries(${PROJECT_NAME} PUBLIC 
	${PYTHON_LIBRARIES}
	${Boost_LIBRARIES}
)

FILE(COPY py/hello.py DESTINATION .)