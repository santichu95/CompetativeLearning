cmake_minimum_required(VERSION 3.3)
project(Burrow)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    burrow.cpp
    sample.ans
    sample.in)

add_executable(Burrow ${SOURCE_FILES})