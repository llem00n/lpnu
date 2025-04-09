cmake_minimum_required(VERSION 3.25)
project(mt)

add_executable(mt main.cpp)

find_package(MPI REQUIRED)
target_link_libraries(mt PRIVATE MPI::MPI_CXX)