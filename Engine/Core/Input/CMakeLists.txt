cmake_minimum_required(VERSION 3.13.2)\n
add_library(input\n    Private/Input_Interface.cpp\n)\n
target_include_directories(input PRIVATE Private)
target_include_directories(input PUBLIC Public)
