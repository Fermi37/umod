project(umod C)
cmake_minimum_required(VERSION 2.8.2)

add_library(triangle triangle.c)
set_target_properties(triangle PROPERTIES COMPILE_FLAGS "-DTRILIBRARY")
target_link_libraries(triangle m)

add_executable(umod umod.c mkmesh.c)
set_target_properties(umod PROPERTIES COMPILE_FLAGS "-Wall -W -pedantic -ansi -std=c99")
target_link_libraries(umod triangle)
