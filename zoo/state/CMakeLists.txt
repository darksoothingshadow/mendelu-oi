cmake_minimum_required(VERSION 4.0)
project(state)

set(CMAKE_CXX_STANDARD 20)

add_executable(state main.cpp
        Employee.cpp
        Employee.h
        WorkPosition.h
        Manager.cpp
        Manager.h
        Developer.cpp
        Developer.h)
