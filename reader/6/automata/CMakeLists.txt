cmake_minimum_required(VERSION 3.3)
project(automata)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp DFA.cpp DFA.h)
add_executable(automata ${SOURCE_FILES})