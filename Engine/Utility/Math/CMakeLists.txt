cmake_minimum_required(VERSION 3.13.2)

add_library(math
    Private/Math_Vector.cpp
)

target_include_directories(math PRIVATE Private)
target_include_directories(math PUBLIC Public)
