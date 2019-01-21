cmake_minimum_required(VERSION 3.13.2)

add_library(01 hello world)

target_include_directories(01 hello world PRIVATE Private)
target_include_directories(01 hello world PUBLIC Public)
