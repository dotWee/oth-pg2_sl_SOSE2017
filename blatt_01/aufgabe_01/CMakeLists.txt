cmake_minimum_required(VERSION 3.6)
project(blatt_01_aufgabe_01)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES main.cpp Notepad.cpp Notepad.h)
add_executable(blatt_01_aufgabe_01 ${SOURCE_FILES})