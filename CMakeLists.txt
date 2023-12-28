# cmake version
cmake_minimum_required(VERSION 3.10)
# Project name
project(gaja)

# Use compile option
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--no-as-needed") # Prevent build errors for lower gcc versions

#dependencies
include_directories(/usr/local/include)
link_directories(/usr/local/lib)

# yaml-cpp
find_package(yaml-cpp 0.7.0 REQUIRED)
set(LIBS ${LIBS} yaml-cpp)

# Header folder
include_directories(include)

# Include heaer-only file
include_directories(${PROJECT_SOURCE_DIR}/external)
# Include external libraries


# Set variable to collect all the source files
file(GLOB_RECURSE SRC_FILES "${PROJECT_SOURCE_DIR}/src/*.cpp")


# Executable for the project
add_executable(${PROJECT_NAME} main.cpp ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} ${LIBS})

# Link with external libraries
# target_link_libraries(gaja library2)
# ... link more libraries as needed

# Optionally, you can also enable testing
# enable_testing()
# add_subdirectory(tests)