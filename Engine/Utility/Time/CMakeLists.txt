cmake_minimum_required(VERSION 3.13.2)\n
add_library(time)\n
target_include_directories(time PRIVATE Private)
target_include_directories(time PUBLIC Public)
