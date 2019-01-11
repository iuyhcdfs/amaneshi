cmake_minimum_required(VERSION 3.13.2)

add_library(amaneshi_engine)

add_subdirectory(
    Core
    Game
    Utility
)

target_include_directories(amaneshi_engine
    core
    game
    utility
)
