cmake_minimum_required(VERSION 3.13.2)

add_library(thread
    Private/Thread_Queue.cpp
    Private/Thread_Task.cpp
)

target_include_directories(thread PRIVATE Private)
target_include_directories(thread PUBLIC Public)
