message("------------")
message("- amaneshi -")
message("------------")
message("")

#--------------------------------------------------------
# Setup

cmake_minimum_required(VERSION 3.12.4)
project(amaneshi)

set(ENGINE_SRC src/engine)

# don't remember? this is what glfw told you to paste in.
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(lib/glfw3.2.1)

add_subdirectory(lib/glew2.1.0/build/cmake)

# glfw SHOULD handle the graphics. ain't using vulkan/metal 
if(APPLE)
endif(APPLE)

if(WIN32)
endif(WIN32)

#--------------------------------------------------------
# Games + Engine targets

# hello world for glfw and glew

add_executable(demo ${ENGINE_SRC}/Demo.cpp)

add_executable(glfw_hello ${ENGINE_SRC}/glfwtest.c)
target_link_libraries(glfw_hello glew glfw)

# the engine
# uses glfw/glew so i should only need to link the engine to any games

#target_link_libraries(amaneshi glew glfw)

# games
#add_executable(hello_engine src/01\ Hello\ World/HelloWorld.cpp)
#target_link_libraries(hello_engine amaneshi)

