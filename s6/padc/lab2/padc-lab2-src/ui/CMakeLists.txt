cmake_minimum_required(VERSION 3.25)
project(padc_lab2_ui)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_library(ui 
    include/ui/main_window.hpp
    src/main_window.cpp
    include/ui/matrix_input_window.hpp
    src/matrix_input_window.cpp
    include/ui/app.hpp
    src/app.cpp
    include/ui/matrix_output_window.hpp
    src/matrix_output_window.cpp
)

target_link_libraries(ui PUBLIC matrix ctx)

target_include_directories(ui INTERFACE include)
target_include_directories(ui PUBLIC include)
target_link_libraries(ui PUBLIC Qt6::Widgets)

set(EXPORT_COMPILE_COMMANDS ON)
