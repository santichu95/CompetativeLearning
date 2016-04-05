cmake_minimum_required(VERSION 3.3)
project(Sodoku)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    sodoku.cpp)

add_executable(Sodoku ${SOURCE_FILES})