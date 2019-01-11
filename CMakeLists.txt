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
# Hello CMake
add_subdirectory(src/00\ Hello\ CMake)
# test with glew/glfw hello world hard link
add_executable(glfw_hello src/glfwtest.cpp)
target_link_libraries(glfw_hello glew glfw)
# now prints 2 random continguous numbers on my mac
target_link_libraries(glfw_hello hello_cmake) 

#--------------------------------------------------------
# the engine
add_subdirectory(src/Engine)
target_link_libraries(amaneshi glew glfw)

#--------------------------------------------------------
# Games

# amaneshi hello world
#add_executable(hello_engine src/01\ Hello\ World/HelloWorld.cpp)
#target_link_libraries(hello_engine amaneshi)

# now an actual game.
#add_executable
#target_link_libraries(hello_engine amaneshi)



#reference

# THIS IS HOW MODERN CMAKE WORKS

#cmake_minimum_required(VERSION 3.13.2)
#add_library(hello_cmake Private/printer.cpp)
#add_executable same styles

# you have to add each cpp file individually. 
# they'll just be bonded to this executable or library i hope.

# but you can grab all the h/hpp files via target_include_directories
# and choose to expose them as public or not.
# this will be important when you generate Xcode or Visual Studio solutions

#target
#target_compile_definitions
#target_compile_options
#target_include_directories(hello_cmake PRIVATE Private) 
#target_include_directories(hello_cmake PUBLIC Public)
#dependency
#target_link_libraries(main flags stuff)


