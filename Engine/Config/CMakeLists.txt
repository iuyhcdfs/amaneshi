cmake_minimum_required(VERSION 3.13.2)

add_library(config
    Private/Dummy.cpp
)

target_include_directories(config PRIVATE Private)
target_include_directories(config PUBLIC Public)
