cmake_minimum_required(VERSION 3.13.2)

add_library(time
    Private/Time_FPS.cpp
)

target_include_directories(time PRIVATE Private)
target_include_directories(time PUBLIC Public)
