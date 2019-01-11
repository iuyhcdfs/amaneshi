cmake_minimum_required(VERSION 3.13.2)

add_library(Amaneshi_game)

add_subdirectory(
    Camera
    Object
    World
)

target_include_directories(Amaneshi_game
    Camera
    Object
    World
)
