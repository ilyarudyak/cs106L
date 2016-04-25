cmake_minimum_required(VERSION 3.5)
project(kd_tree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp KDTree.cpp KDTree.h Point.h BoundedPQueue.h)
add_executable(kd_tree ${SOURCE_FILES})