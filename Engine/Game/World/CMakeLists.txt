cmake_minimum_required(VERSION 3.13.2)

add_library(world)

target_include_directories(world PRIVATE Private)
target_include_directories(world PUBLIC Public)
