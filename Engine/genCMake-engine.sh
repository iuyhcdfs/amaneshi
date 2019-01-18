#echo "#--------------------------------------------------------
## this is what glfw told you to paste in.
#set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
#set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
#set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
#add_subdirectory(External/glfw3.2.1)
## glew just needs this folder
#add_subdirectory(External/glew2.1.0/build/cmake)\n" >> CMakeLists.txt

CMAKE_VERSION="3.13.2"
IFS=$'\n'

# just edit Engine/CMakeLists.txt manually. its not worth automating.

genCMake-all-subfolders.sh
