cmake_minimum_required(VERSION 3.13.2)

add_library(linkglfw
    Private/Initialize_GLFW.cpp
    Private/Update_GLFW.cpp
    Private/Window_GLFW.cpp
)

target_include_directories(linkglfw PRIVATE Private)
target_include_directories(linkglfw PUBLIC Public)
