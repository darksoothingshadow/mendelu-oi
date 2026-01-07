cmake_minimum_required(VERSION 3.31)
project(cvTyden8)

set(CMAKE_CXX_STANDARD 20)

add_executable(cvTyden8 main.cpp
        Tile.cpp
        Tile.h
        Map.cpp
        Map.h
        Inventory.cpp
        Inventory.h
        WheatField.cpp
        WheatField.h
        GoldMine.cpp
        GoldMine.h
        Soil.cpp
        Soil.h
        MagicTile.cpp
        MagicTile.h)
