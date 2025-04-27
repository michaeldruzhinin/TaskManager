cmake_minimum_required(VERSION 3.16)
project(TaskManager)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_subdirectory(src/core)
add_subdirectory(src/gui)
add_subdirectory(src/app)
