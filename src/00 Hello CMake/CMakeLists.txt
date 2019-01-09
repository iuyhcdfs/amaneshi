
# THIS IS HOW MODERN CMAKE WORKS

cmake_minimum_required(VERSION 3.13.2)
add_library(hello_cmake Private/printer.cpp)
#add_executable same styles

# you have to add each cpp file individually. 
# they'll just be bonded to this executable or library i hope.

# but you can grab all the h/hpp files via target_include_directories
# and choose to expose them as public or not.
# this will be important when you generate Xcode or Visual Studio solutions

#target
#target_compile_definitions
#target_compile_options
target_include_directories(hello_cmake PRIVATE Private) 
target_include_directories(hello_cmake PUBLIC Public)
#dependency
#target_link_libraries(main flags stuff)

