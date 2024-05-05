cmake_minimum_required(VERSION 3.28)
project(polics_lab1_src)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(polics_lab1_src main.cpp
        CaesarCipherWindow.cpp
        CaesarCipherWindow.h)

target_link_libraries(polics_lab1_src
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

