cmake_minimum_required(VERSION 3.13.2)

add_library(02 stress test)

target_include_directories(02 stress test PRIVATE Private)
target_include_directories(02 stress test PUBLIC Public)
