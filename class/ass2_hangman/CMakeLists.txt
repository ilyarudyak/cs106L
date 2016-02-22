cmake_minimum_required(VERSION 3.3)
project(ass2_hangman)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Hangman.cpp Hangman.h)
add_executable(ass2_hangman ${SOURCE_FILES})