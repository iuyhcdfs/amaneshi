cmake_minimum_required(VERSION 3.13.2)

add_library(Object
    Private/Object_Sphere.cpp
)

target_include_directories(Object PRIVATE Private)
target_include_directories(Object PUBLIC Public)
