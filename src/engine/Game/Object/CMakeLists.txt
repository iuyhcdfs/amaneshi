cmake_minimum_required(VERSION 3.13.2)

add_library(object
    Private/Object_Sphere.cpp
)

target_include_directories(object PRIVATE Private)
target_include_directories(object PUBLIC Public)
