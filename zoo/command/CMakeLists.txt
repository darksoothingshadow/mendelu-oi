cmake_minimum_required(VERSION 3.31)
project(Documents)

set(CMAKE_CXX_STANDARD 17)

add_executable(Documents main.cpp
        Calculator.cpp
        Calculator.h
        Operation.cpp
        Operation.h
        Adding.cpp
        Adding.h
        Multiplying.cpp
        Multiplying.h)
