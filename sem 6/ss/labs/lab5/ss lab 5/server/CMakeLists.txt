cmake_minimum_required(VERSION 3.27)

project(server C)
set(CMAKE_C_STANDARD 23)

add_executable(server main.c)

target_link_libraries(server PRIVATE shared)