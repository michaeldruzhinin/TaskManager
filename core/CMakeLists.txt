add_library(core
    task.cpp
    task.h
    taskmanager.cpp
    taskmanager.h
)

target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
