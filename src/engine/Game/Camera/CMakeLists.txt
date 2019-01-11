cmake_minimum_required(VERSION 3.13.2)

add_library(camera)

target_include_directories(camera PRIVATE Private)
target_include_directories(camera PUBLIC Public)
