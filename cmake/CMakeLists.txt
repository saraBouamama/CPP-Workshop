cmake_minimum_required(VERSION 3.19.7)
project(cmake)

add_executable(hello main.cc)

add_subdirectory(libhello)

target_link_libraries(hello PUBLIC libhello)
