cmake_minimum_required(VERSION 3.13.2)

add_library(amaneshi_engine)

# this is what glfw told you to paste in.
set(GLFW_BUILD_DOCS OFF CACHE BOOL  FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL  FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL  FORCE)
add_subdirectory(External/glfw3.2.1)
# glew just needs this folder
add_subdirectory(External/glew2.1.0/build/cmake)

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
