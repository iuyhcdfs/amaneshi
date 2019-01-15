cmake_minimum_required(VERSION 3.13.2)

add_library(graphics
    Private/Graphics_Interface.cpp
    Private/Graphics_Shader.cpp
    Private/Graphics_Window.cpp
    Private/Messy_GLFW.cpp
    Private/Messy_OpenGL.cpp
)

target_include_directories(graphics PRIVATE Private)
target_include_directories(graphics PUBLIC Public)
