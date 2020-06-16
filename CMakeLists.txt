cmake_minimum_required(VERSION 3.6)

# C++ Standard we will use
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Build type
set(CMAKE_BUILD_TYPE Debug)

project(Karavan)

add_subdirectory(Karavan)
add_subdirectory(Sandbox)