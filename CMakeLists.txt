cmake_minimum_required(VERSION 3.21)
project(thread_types)

set(CMAKE_CXX_STANDARD 14)

SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -pthread")

find_package (Threads)

add_executable(thread_types main.cpp)

target_link_libraries(thread_types ${CMAKE_THREAD_LIBS_INIT})