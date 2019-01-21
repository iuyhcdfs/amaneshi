cmake_minimum_required(VERSION 3.13.2)

add_library(renderer)

target_include_directories(renderer PRIVATE Private)
target_include_directories(renderer PUBLIC Public)
