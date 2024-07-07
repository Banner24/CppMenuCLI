cmake_minimum_required(VERSION 3.10)
project(menu)

# Set the output directories for static and shared libraries as well as executable files
set(FullOutputDir "${CMAKE_CURRENT_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${FullOutputDir}/static libs")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${FullOutputDir}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${FullOutputDir}")

# Find the ncurses library
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

# Add a library mymenu compiled from MyMenu.cpp
# Collect source files from the Menu directory
file(GLOB MYMENU_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/Menu/*.cpp")
# Collect source files from the Operations directory
file(GLOB OPERATIONS_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/Operations/*.cpp")
# Combine both source lists
set(ALL_SOURCES ${MYMENU_SOURCES} ${OPERATIONS_SOURCES})
# Add a single library target using the combined source list
add_library(mymenu ${ALL_SOURCES})


# Create the executable target with main.cpp
add_executable(${PROJECT_NAME} main.cpp)

# Link the executable target with the mymenu library and Curses
target_link_libraries(${PROJECT_NAME} mymenu ${CURSES_LIBRARIES})
