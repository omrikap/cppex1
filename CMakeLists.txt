cmake_minimum_required(VERSION 3.3)
project(ex1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES IntMatrix.cpp IntMatrix.h IntMatrixDriver.cpp)
add_executable(ex1 ${SOURCE_FILES})