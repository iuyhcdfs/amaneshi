cmake_minimum_required(VERSION 3.13.2)

add_library(Amaneshi_Utility)

add_subdirectory(
    File
    Math
    Time
)

target_include_directories(Amaneshi_Utility
    File
    Math
    Time
)
