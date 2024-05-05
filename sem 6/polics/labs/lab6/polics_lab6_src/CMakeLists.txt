cmake_minimum_required(VERSION 3.27)
project(polics_lab6_src)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS Core Widgets Gui REQUIRED)

add_executable(polics_lab6_src main.cpp
        HillCipher.cpp
        HillCipher.hpp
        matrix.hpp)

target_link_libraries(polics_lab6_src Qt6::Core Qt6::Widgets)
