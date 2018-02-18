cmake_minimum_required(VERSION 3.6)
project(PA2)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES life.c game.c board.c board.h game.h)
add_executable(PA2 ${SOURCE_FILES})