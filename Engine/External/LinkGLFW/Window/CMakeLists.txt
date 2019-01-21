cmake_minimum_required(VERSION 3.13.2)

add_library(window)

target_include_directories(window PRIVATE Private)
target_include_directories(window PUBLIC Public)
