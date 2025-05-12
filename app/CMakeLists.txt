add_executable(TaskManagerApp
    main.cpp
)

target_link_libraries(TaskManagerApp PRIVATE core)
target_link_libraries(TaskManagerApp PRIVATE gui core Qt6::Widgets)
