cmake_minimum_required(VERSION 3.27)
project(practical C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(practical
        include/utils.h
        src/main.c
        src/utils.c)
