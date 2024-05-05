cmake_minimum_required(VERSION 3.25)
project(padc_lab2)

add_subdirectory(matrix)
add_subdirectory(ui)
add_subdirectory(ctx)
add_subdirectory(solver)
add_subdirectory(mt_main)
add_subdirectory(st_main)
add_subdirectory(test)

set(EXPORT_COMPILE_COMMANDS ON)

