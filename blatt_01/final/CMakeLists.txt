cmake_minimum_required(VERSION 3.6)
project(blatt_01_final)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")
add_executable(blatt_01_final main.cpp Book.h Book.cpp Page.h Page.cpp)