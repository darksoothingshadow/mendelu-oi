cmake_minimum_required(VERSION 4.0)
project(cv9online)

set(CMAKE_CXX_STANDARD 20)

add_executable(cv9online main.cpp
        Tile.cpp
        Tile.h
        Inventory.cpp
        Inventory.h
        Map.cpp
        Map.h
        WheatField.cpp
        WheatField.h
        Soil.cpp
        Soil.h
        GoldMine.cpp
        GoldMine.h
)
