cmake_minimum_required(VERSION 3.13.2)

add_library(amaneshi_engine Engine_Presets.cpp Engine_Presets.hpp)

add_subdirectory(Utility)
add_subdirectory(Core)
add_subdirectory(Game)

target_link_libraries(amaneshi_engine input)
target_link_libraries(amaneshi_engine graphics)
target_link_libraries(amaneshi_engine thread)
target_link_libraries(amaneshi_engine camera)
target_link_libraries(amaneshi_engine world)
target_link_libraries(amaneshi_engine object)
target_link_libraries(amaneshi_engine file)
target_link_libraries(amaneshi_engine math)
target_link_libraries(amaneshi_engine time)
