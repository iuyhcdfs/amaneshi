cmake_minimum_required(VERSION 3.13.2)

add_library(file
    Private/File.cpp
    Private/File_Shader.cpp
)

target_include_directories(file PRIVATE Private)
target_include_directories(file PUBLIC Public)
