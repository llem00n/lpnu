cmake_minimum_required(VERSION 3.25)
project(ctx)

set(CMAKE_CXX_STANDARD 23)

add_library(ctx 
    include/ctx/ctx.hpp
    src/ctx.cpp
)

target_link_libraries(ctx PUBLIC matrix)
target_include_directories(ctx PUBLIC include)
target_include_directories(ctx INTERFACE include)

set(EXPORT_COMPILE_COMMANDS ON)

