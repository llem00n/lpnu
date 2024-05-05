cmake_minimum_required(VERSION 3.27)

project(shared C)
set(CMAKE_C_STANDARD 23)

add_library(shared INTERFACE)

target_include_directories(shared INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)