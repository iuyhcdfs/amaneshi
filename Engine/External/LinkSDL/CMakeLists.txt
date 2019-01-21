cmake_minimum_required(VERSION 3.13.2)

add_library(linksdl
    Private/Initialize_SDL.cpp
)

target_include_directories(linksdl PRIVATE Private)
target_include_directories(linksdl PUBLIC Public)
