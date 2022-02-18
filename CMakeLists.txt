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
  if (UNIX)
    if (NOT APPLE)
      if (PYTHON_VERSION_MAJOR EQUAL 3)
          FIND_PACKAGE(Boost COMPONENTS python${PYTHON_VERSION_SUFFIX})
          FIND_PACKAGE(PythonInterp 3)
          FIND_PACKAGE(PythonLibs 3 REQUIRED)
      else()
          FIND_PACKAGE(Boost COMPONENTS python)
          FIND_PACKAGE(PythonInterp)
          FIND_PACKAGE(PythonLibs REQUIRED)
      endif()
    elseif(APPLE)
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
  endif()
  if (WIN32)
    set(Boost_USE_STATIC_LIBS ON)
    if (PYTHON_VERSION_MAJOR EQUAL 3)
        FIND_PACKAGE(Boost COMPONENTS python${PYTHON_VERSION_MAJOR}.${PYTHON_VERSION_MINOR})
        FIND_PACKAGE(PythonInterp 3)
        FIND_PACKAGE(PythonLibs 3 REQUIRED)
    else()
        FIND_PACKAGE(Boost COMPONENTS python)
        FIND_PACKAGE(PythonInterp)
        FIND_PACKAGE(PythonLibs REQUIRED)
    endif()
  endif()
else()
    message("Python not found")
endif()

message(STATUS "PYTHON_LIBRARIES = ${PYTHON_LIBRARIES}")
message(STATUS "PYTHON_EXECUTABLE = ${PYTHON_EXECUTABLE}")
message(STATUS "PYTHON_INCLUDE_DIRS = ${PYTHON_INCLUDE_DIRS}")
message(STATUS "Boost_LIBRARIES = ${Boost_LIBRARIES}")

include_directories(${PYTHON_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})

if (WIN32)
  set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

set(LIB_SRCS
  src/pyhelper.cpp
  src/pyhello.cpp
)

# Build pyHello library
add_library(${PROJECT_NAME} SHARED ${LIB_SRCS})
target_link_libraries(${PROJECT_NAME} PRIVATE
  ${PYTHON_LIBRARIES}
	${Boost_LIBRARIES}
)

set(APP_SRCS
  src/main.cpp
)

add_executable( ${PROJECT_NAME}App ${APP_SRCS} )
target_link_libraries(${PROJECT_NAME}App PRIVATE 
  ${PROJECT_NAME}
  ${PYTHON_LIBRARIES}
	${Boost_LIBRARIES}
)

add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND}
    ARGS -E copy_if_different ${CMAKE_CURRENT_SOURCE_DIR}/py/hello.py $<TARGET_FILE_DIR:${PROJECT_NAME}>
)