cmake_minimum_required(VERSION 3.13.2)

# all dependencies are resolved here.
add_library(amaneshi_engine Engine.cpp Engine.hpp)

#--------------------------------------------------------
# #defines for the whole family
add_subdirectory(Config)
    #target_link_libraries(amaneshi_engine config)

#--------------------------------------------------------
add_subdirectory(External)
    #target_link_libraries(amaneshi_engine linkglfw)
        set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
        set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
        set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
        add_subdirectory(/Libraries/glfw3.2.1)
        # glew just needs this folder
        add_subdirectory(/Libraries/glew2.1.0/build/cmake)
        target_link_libraries(linkglfw glew glfw)
    #target_link_libraries(amaneshi_engine linksdl)

#--------------------------------------------------------
add_subdirectory(Utility)
    #target_link_libraries(amaneshi_engine file)
    #target_link_libraries(amaneshi_engine math)
    #target_link_libraries(amaneshi_engine time)

#--------------------------------------------------------
add_subdirectory(Core)
    #target_link_libraries(amaneshi_engine input)
        target_link_libraries(input config)
    #target_link_libraries(amaneshi_engine graphics)
        #target_link_libraries(graphics config)
        #target_link_libraries(graphics math)
    #target_link_libraries(amaneshi_engine thread)

#--------------------------------------------------------
add_subdirectory(Game)
    #target_link_libraries(amaneshi_engine camera)
        target_link_libraries(camera math)    
    #target_link_libraries(amaneshi_engine world)
        target_link_libraries(world math)
    #target_link_libraries(amaneshi_engine object)
        target_link_libraries(object math)
