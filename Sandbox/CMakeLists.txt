cmake_minimum_required(VERSION 3.6)

# C++ Standard we will use
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#link directories 
link_directories(${PROJECT_SOURCE_DIR}/lib)

#include directories
include_directories(${PROJECT_SOURCE_DIR}/Karavan/src)

# add the executable
add_executable(Sandbox src/Sandbox.cpp)
target_link_libraries(Sandbox Karavan)

#install
install(TARGETS Sandbox DESTINATION ${PROJECT_SOURCE_DIR}/bin)