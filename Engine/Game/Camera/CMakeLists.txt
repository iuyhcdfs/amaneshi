cmake_minimum_required(VERSION 3.13.2)\n
add_library(camera)\n
target_include_directories(camera PRIVATE Private)
target_include_directories(camera PUBLIC Public)
