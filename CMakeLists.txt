message("------------")
message("- amaneshi -")
message("------------")
message("")

#--------------------------------------------------------
cmake_minimum_required(VERSION 3.13.2)

#--------------------------------------------------------
# this is what glfw told you to paste in.
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(Libraries/glfw3.2.1)
# glew just needs this folder
add_subdirectory(Libraries/glew2.1.0/build/cmake)

#--------------------------------------------------------
if(APPLE)
endif(APPLE)
if(WIN32)
endif(WIN32)

#--------------------------------------------------------
# a bodgy hello world that you should never use as an example 
# but i figured out how cmake works with it
add_subdirectory(Examples/00\ Hello\ CMake)
add_executable(glfw_hello Examples/glfwtest.cpp)
target_link_libraries(glfw_hello glew glfw)
target_link_libraries(glfw_hello hello_cmake) 
target_link_libraries(hello_cmake glfw)

#--------------------------------------------------------
# the engine
#add_subdirectory(Engine) # library: "amaneshi_engine"

#--------------------------------------------------------
# Games

add_subdirectory()