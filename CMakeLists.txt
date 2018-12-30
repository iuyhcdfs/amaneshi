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
add_subdirectory(lib/glfw3.2.1)
# glew just needs this folder
add_subdirectory(lib/glew2.1.0/build/cmake)

#--------------------------------------------------------
if(APPLE)
endif(APPLE)
if(WIN32)
endif(WIN32)

#--------------------------------------------------------
# Hello world
# Engine

# glew/glfw hello world hard link
add_executable(glfw_hello src/glfwtest.c)
target_link_libraries(glfw_hello glew glfw)

# the engine
add_subdirectory(src/engine)
target_link_libraries(amaneshi glew glfw)

#--------------------------------------------------------
# Games

# amaneshi hello world
#add_executable(hello_engine src/01\ Hello\ World/HelloWorld.cpp)
#target_link_libraries(hello_engine amaneshi)

# now an actual game.
#add_executable
#target_link_libraries(hello_engine amaneshi)
