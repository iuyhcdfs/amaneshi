cmake_minimum_required(VERSION 3.13.2)\n
add_library(thread\n    Private/Thread_Queue.cpp
    Private/Thread_Task.cpp\n)\n
target_include_directories(thread PRIVATE Private)
target_include_directories(thread PUBLIC Public)
