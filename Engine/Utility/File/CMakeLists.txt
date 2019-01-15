cmake_minimum_required(VERSION 3.13.2)

add_library(file
    Private/File_Reader.cpp
    Private/Shader_Reader.cpp
)

target_include_directories(file PRIVATE Private)
target_include_directories(file PUBLIC Public)
