# the actual engine
cmake_minimum_required(VERSION 3.13.2)

add_library(amaneshi "")

# common
add_subdirectory(Utility)

# external
add_subdirectory(Graphics)
add_subdirectory(Input)

# game related
add_subdirectory(Object)
#add_subdirectory(Thread)
#add_subdirectory(World)
