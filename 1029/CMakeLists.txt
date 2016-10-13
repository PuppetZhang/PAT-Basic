cmake_minimum_required(VERSION 3.6)
project(1029)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(1029 ${SOURCE_FILES})