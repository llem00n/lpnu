cmake_minimum_required(VERSION 3.25)
project(mt_main)

set(CMAKE_CXX_STANDARD 23)

find_package(MPI REQUIRED)

add_executable(mt_main src/mt_main.cpp include/mt_main/ranks.hpp
        include/mt_main/mpi_app.hpp
        src/mpi_app.cpp)

target_link_libraries(mt_main PRIVATE ui matrix ctx solver MPI::MPI_CXX)
target_include_directories(mt_main PRIVATE include)

set(EXPORT_COMPILE_COMMANDS ON)
