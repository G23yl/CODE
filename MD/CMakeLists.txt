cmake_minimum_required(VERSION 3.26)
project(MD)

set(CMAKE_CXX_STANDARD 20)

add_executable(MD main.cpp
        Matrix.h
        LinearEqu.h
        Matrix.cpp
        LinearEqu.cpp)
