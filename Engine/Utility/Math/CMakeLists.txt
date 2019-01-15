cmake_minimum_required(VERSION 3.13.2)\n
add_library(math\n    Private/Math_Vector.cpp\n)\n
target_include_directories(math PRIVATE Private)
target_include_directories(math PUBLIC Public)
