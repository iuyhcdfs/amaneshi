cmake_minimum_required(VERSION 3.13.2)

add_library(config_external
    Private/Dummy.cpp
)

target_include_directories(config_external PRIVATE Private)
target_include_directories(config_external PUBLIC Public)
