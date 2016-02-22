cmake_minimum_required(VERSION 3.3)
project(city_finder)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp CityFinder.cpp CityFinder.h)
add_executable(city_finder ${SOURCE_FILES})