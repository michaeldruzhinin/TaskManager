qt6_wrap_ui(UIS_H mainwindow.ui)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
add_library(gui
    mainwindow.cpp
    mainwindow.h
    ${UIS_H}
)

target_link_libraries(gui PUBLIC Qt6::Widgets core)
target_include_directories(gui PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

