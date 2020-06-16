cmake_minimum_required(VERSION 3.6)


if(WIN32)
    add_definitions(KV_PLATFORM_WINDOWS)
    add_definitions(KV_BUILD_DLL)
endif()

# Link library path
link_directories(${PROJECT_SOURCE_DIR}/lib)

# Include path
include_directories(${PROJECT_SOURCE_DIR}/Karavan/src/Karavan)

# Source files
set(SRC_FILES ${PROJECT_SOURCE_DIR}/Karavan/src/Karavan/Application.cpp)

# Add teh library
add_library(Karavan SHARED ${SRC_FILES})

# install command
install(TARGETS Karavan DESTINATION ${PROJECT_SOURCE_DIR}/lib)
