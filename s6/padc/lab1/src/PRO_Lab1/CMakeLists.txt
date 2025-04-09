cmake_minimum_required(VERSION 3.27)
project(PRO_Lab1)

set(CMAKE_CXX_STANDARD 14)

add_executable(PRO_Lab1
        main.c)

find_package(MPI REQUIRED)
target_link_libraries(PRO_Lab1 PRIVATE MPI::MPI_CXX)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/hf18
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/hf12
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})