cmake_minimum_required(VERSION 3.25)
project(polics_lab5_src)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(polics_lab5_src main.cpp
        FeistelCipher.cpp
        FeistelCipher.hpp
)

target_link_libraries(polics_lab5_src
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

