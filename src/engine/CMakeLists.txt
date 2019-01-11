cmake_minimum_required(VERSION 3.13.2)

add_library(Amaneshi_Engine)

add_subdirectory(
    Core
    Game
    Utility
)

target_include_directories(Amaneshi_Engine
    Core
    Game
    Utility
)
