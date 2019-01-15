cmake_minimum_required(VERSION 3.13.2)

add_library(input
    Private/Input_Interface.cpp
)

target_include_directories(input PRIVATE Private)
target_include_directories(input PUBLIC Public)
