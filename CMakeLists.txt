message("------------")
message("- amaneshi -")
message("------------")
message("")

#--------------------------------------------------------
cmake_minimum_required(VERSION 3.13.2)
if(APPLE)
endif(APPLE)
if(WIN32)
endif(WIN32)
#--------------------------------------------------------
# STEP ONE add the engine
    add_subdirectory(Engine) #libraryname="amaneshi_engine"
    

#--------------------------------------------------------
# STEP TWO then add your games
add_subdirectory(Examples)
    target_link_libraries(01\ Hello\ World amaneshi_engine)
    #target_link_libraries(02\ Stress\ Test amaneshi_engine)



#--------------------------------------------------------
# a bodgy hello world for reference thats now too old to work

# this is what glfw told you to paste in.
#set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
#set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
#set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
#add_subdirectory(Libraries/glfw3.2.1)
## glew just needs this folder
#add_subdirectory(Libraries/glew2.1.0/build/cmake)
    #add_subdirectory(Examples/00\ Hello\ CMake)
    #add_executable(glfw_hello Examples/glfwtest.cpp)
    #target_link_libraries(glfw_hello glew glfw)
    #target_link_libraries(glfw_hello hello_cmake) 
    #target_link_libraries(hello_cmake glfw)

