cmake_minimum_required(VERSION 3.13.2)

add_library(Amaneshi_Core)

add_subdirectory(
    Graphics
    Input
    Thread
)

target_include_directories(Amaneshi_Core
    Graphics
    Input
    Thread
)
