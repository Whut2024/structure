cmake_minimum_required(VERSION 3.27)
project(Structure C)

set(CMAKE_C_STANDARD 23)

add_executable(Structure main.c
        B-Tree/b-tree.h
)
