cmake_minimum_required(VERSION 3.13.2)\n
add_library(file\n    Private/File_Reader.cpp
    Private/Shader_Reader.cpp\n)\n
target_include_directories(file PRIVATE Private)
target_include_directories(file PUBLIC Public)
