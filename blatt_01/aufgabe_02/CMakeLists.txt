cmake_minimum_required(VERSION 3.6)
project(blatt_01_aufgabe_02)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES main.cpp Notepad.cpp Notepad.h Book.cpp Book.h)
add_executable(blatt_01_aufgabe_02 ${SOURCE_FILES})