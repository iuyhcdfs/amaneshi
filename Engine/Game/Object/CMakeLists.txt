cmake_minimum_required(VERSION 3.13.2)\n
add_library(object\n    Private/Object_Sphere.cpp\n)\n
target_include_directories(object PRIVATE Private)
target_include_directories(object PUBLIC Public)
