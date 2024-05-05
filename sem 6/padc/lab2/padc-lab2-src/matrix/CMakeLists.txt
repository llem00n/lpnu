cmake_minimum_required(VERSION 3.25)
project(padc_lab2_matrix)
set(CMAKE_CXX_STANDARD 23)

add_library(matrix include/matrix/matrix.hpp src/matrix.cpp include/matrix/msize_t.hpp)

target_include_directories(matrix PUBLIC include)
target_include_directories(matrix INTERFACE include)

set(EXPORT_COMPILE_COMMANDS ON)
