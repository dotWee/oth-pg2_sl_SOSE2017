cmake_minimum_required(VERSION 3.6)
project(blatt_03_final)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")
add_executable(blatt_03_final main.cpp Field.cpp Field.h LiNode.h List.h Renderer.cpp Renderer.h Stone.h Stone.cpp xy_pair_type.h)