cmake_minimum_required(VERSION 3.25)
project(st_main)

set(CMAKE_CXX_STANDARD 23)

add_executable(st_main src/st_main.cpp)

target_link_libraries(st_main PUBLIC ui matrix ctx solver)

set(EXPORT_COMPILE_COMMANDS ON)
