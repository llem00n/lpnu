cmake_minimum_required(VERSION 3.25)
project(test)

set(CMAKE_CXX_STANDARD 23)

add_executable(test src/main.cpp)

target_link_libraries(test PRIVATE ctx matrix ui)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
