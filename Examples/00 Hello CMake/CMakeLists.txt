cmake_minimum_required(VERSION 3.13.2)

add_library(00 hello cmake
    Private/printer.cpp
)

target_include_directories(00 hello cmake PRIVATE Private)
target_include_directories(00 hello cmake PUBLIC Public)
