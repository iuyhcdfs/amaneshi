message("------------")
message("- amaneshi -")
message("------------")
message("")

cmake_minimum_required(VERSION 3.12.4)
project(amaneshi)

set(SRC src/Amaneshi)
add_executable(demo ${SRC}/Demo.cpp)

message("------------------------")
message("Source Glob:")
file(GLOB_RECURSE ALL_SOURCES "src/*.cpp")
message(${ALL_SOURCES})

message("------------------------")
message("Sources")

#message("------------------------")

#message("------------------------")

#message("------------------------")

#message("------------------------")

