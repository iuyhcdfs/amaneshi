echo "cmake_minimum_required(VERSION 3.13.2)\n" > CMakeLists.txt
echo "add_library(amaneshi_engine)\n" >> CMakeLists.txt

echo "#--------------------------------------------------------
# this is what glfw told you to paste in.
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(External/glfw3.2.1)
# glew just needs this folder
add_subdirectory(External/glew2.1.0/build/cmake)\n" >> CMakeLists.txt

echo "add_subdirectory(Utility)" >> CMakeLists.txt
echo "add_subdirectory(Core)" >> CMakeLists.txt
echo "add_subdirectory(Game)" >> CMakeLists.txt
echo "" >> CMakeLists.txt

CMAKE_VERSION="3.13.2"
IFS=$'\n'

ALL_MODULES=`find . -mindepth 2 -maxdepth 2 -type d -exec basename {} \; | tr '[A-Z]' '[a-z]'`
for EACH_LINE in $ALL_MODULES; do
    echo "target_link_libraries(amaneshi_engine $EACH_LINE)" >> CMakeLists.txt
done

# genCMake-all-subfolders.sh
