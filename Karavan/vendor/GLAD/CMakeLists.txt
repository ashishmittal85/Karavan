cmake_minimum_required(VERSION 3.6)
project(GLAD)


# On Unix-like systems, shared libraries can use the soname system.
set(GLFW_LIB_NAME glad)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(glad STATIC ${PROJECT_SOURCE_DIR}/src/glad.c)

set_target_properties(glad PROPERTIES
                      OUTPUT_NAME glad
                      POSITION_INDEPENDENT_CODE ON
                      FOLDER "GLAD")