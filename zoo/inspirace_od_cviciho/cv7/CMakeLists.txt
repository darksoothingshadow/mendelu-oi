cmake_minimum_required(VERSION 4.0)
project(cv7)

set(CMAKE_CXX_STANDARD 20)

add_executable(cv7 main.cpp
        Product.cpp
        Product.h
        Container.cpp
        Container.h
        Section.cpp
        Section.h)
