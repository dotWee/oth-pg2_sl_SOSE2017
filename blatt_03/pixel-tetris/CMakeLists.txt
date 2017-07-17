cmake_minimum_required(VERSION 3.6)
project(blatt_32_pixel-tetris)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES_TEST main_test.cpp test/FieldTest.cpp test/FieldTest.h libs/XyPair.cpp libs/XyPair.h libs/Stone.cpp libs/Stone.h libs/Field.cpp libs/Field.h libs/Renderer.cpp libs/Renderer.h test/StoneTest.cpp test/StoneTest.h)
add_executable(blatt_03_pixel-tetris_test ${SOURCE_FILES_TEST})

set(SOURCE_FILES main.cpp libs/XyPair.cpp libs/XyPair.h libs/Stone.cpp libs/Stone.h libs/Field.cpp libs/Field.h libs/Renderer.cpp libs/Renderer.h)
add_executable(blatt_03_pixel-tetris ${SOURCE_FILES})
add_dependencies(blatt_03_pixel-tetris blatt_02_pixel-tetris_test)