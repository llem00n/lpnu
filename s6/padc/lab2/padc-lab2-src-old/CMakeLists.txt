cmake_minimum_required(VERSION 3.28)
project(padc_lab2_src CXX)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6Widgets REQUIRED)
find_package(MPI REQUIRED)

add_executable(padc_lab2_src
        matrix/matrix.cpp
        matrix/matrix.hpp
        ranks/mpi_rank_0.cpp
        ranks/mpi_rank_0.hpp
        ranks/mpi_rank_base.cpp
        ranks/mpi_rank_base.hpp
        ui/main_window.cpp
        ui/main_window.h
        main.cpp
        ui/matrix_input_window.cpp
        ui/matrix_input_window.h
        jobs_tree/job_tree.cpp
        jobs_tree/job_tree.h
)
target_include_directories(padc_lab2_src PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(padc_lab2_src MPI::MPI_CXX)
target_link_libraries(padc_lab2_src Qt6::Widgets)