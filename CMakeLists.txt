message("------------")
message("- amaneshi -")
message("------------")
message("")

#--------------------------------------------------------
# Setup

cmake_minimum_required(VERSION 3.12.4)
project(amaneshi)

set(ENGINE_SRC src/engine)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(lib/glfw3.2.1)
add_subdirectory(lib/glew2.1.0/build/cmake)

#--------------------------------------------------------
# Targets
add_executable(demo ${ENGINE_SRC}/Demo.cpp)
add_executable(glfw_hello ${ENGINE_SRC}/glfwtest.c)
add_executable(bad_hello_engine src/01\ Hello\ World/HelloWorld.cpp)


target_link_libraries(glfw_hello glew glfw)




#message("------------------------")
#message("Source Glob:")
#file(GLOB_RECURSE ALL_SOURCES "src/*.cpp")
#message(${ALL_SOURCES})

#message("------------------------")
#message("Sources")

#message("------------------------")

#message("------------------------")

#message("------------------------")

#message("------------------------")

