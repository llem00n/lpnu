cmake_minimum_required(VERSION 3.21)
project(solver)

set(CMAKE_CXX_STANDARD 23)

add_library(solver include/solver/solver.hpp src/solver.cpp)

target_include_directories(solver PUBLIC include)
target_include_directories(solver INTERFACE include)

target_link_libraries(solver PUBLIC matrix ctx)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)