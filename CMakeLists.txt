cmake_minimum_required(VERSION 3.10)
project(menu)

# Setze die Ausgabeverzeichnisse für statische und gemeinsame Bibliotheken sowie ausführbare Dateien
set(FullOutputDir "${CMAKE_CURRENT_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}/${CMAKE_BUILD_TYPE}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${FullOutputDir}/static libs")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${FullOutputDir}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${FullOutputDir}")

# Finde die ncurses-Bibliothek
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

# Füge eine Bibliothek mymenu hinzu, die aus MyMenu.cpp kompiliert wird
# add_library(mymenu ${CMAKE_CURRENT_SOURCE_DIR}/Menu/MyMenu.cpp)  OLD ONE
file(GLOB MYMENU_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/Menu/*.cpp")
add_library(mymenu ${MYMENU_SOURCES})


# Erzeuge das ausführbare Ziel mit main.cpp
add_executable(${PROJECT_NAME} main.cpp)

# Verlinke das ausführbare Ziel mit der mymenu-Bibliothek und Curses
target_link_libraries(${PROJECT_NAME} mymenu ${CURSES_LIBRARIES})

