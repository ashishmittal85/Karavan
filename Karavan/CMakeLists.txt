cmake_minimum_required(VERSION 3.6)


if(WIN32)
    add_definitions(KV_PLATFORM_WINDOWS)
    add_definitions(KV_BUILD_DLL)
endif()

add_subdirectory(vendor/spdlog)
add_subdirectory(vendor/GLFW)

# Link library path
link_directories(Karavan ${PROJECT_SOURCE_DIR}/lib)
#link_directories(Karavan ${PROJECT_SOURCE_DIR}/Karavan/vendor/GLFW)


# Include path
include_directories(${PROJECT_SOURCE_DIR}/Karavan/vendor/GLFW/include)
include_directories(${PROJECT_SOURCE_DIR}/Karavan/vendor/spdlog/include)
include_directories(${PROJECT_SOURCE_DIR}/Karavan/src/Karavan)
include_directories(${PROJECT_SOURCE_DIR}/Karavan/src/)

# Source files
set(SRC_FILES ${PROJECT_SOURCE_DIR}/Karavan/src/Karavan/Log.cpp
              ${PROJECT_SOURCE_DIR}/Karavan/src/Karavan/Layer.cpp
              ${PROJECT_SOURCE_DIR}/Karavan/src/Karavan/LayerStack.cpp
              ${PROJECT_SOURCE_DIR}/Karavan/src/Platform/MacWindow.cpp
              ${PROJECT_SOURCE_DIR}/Karavan/src/Karavan/Application.cpp)

# Add the library
add_library(Karavan SHARED ${SRC_FILES})
set_target_properties(Karavan PROPERTIES XCODE_ATTRIBUTE_GCC_PREFIX_HEADER "${PROJECT_SOURCE_DIR}/Karavan/KVPCH.h"
                                            XCODE_ATTRIBUTE_GCC_PRECOMPILE_PREFIX_HEADER "YES")
# Link the libraries
target_link_libraries(Karavan glfw)

find_package(OpenGL REQUIRED)
target_link_libraries(Karavan OpenGL::GL)

# install command
install(TARGETS Karavan DESTINATION ${PROJECT_SOURCE_DIR}/lib)
