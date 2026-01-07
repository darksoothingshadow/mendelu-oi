//
// Created by Michal Matonoha on 24.11.2025.
//

#ifndef CV9ONLINE_MAP_H
#define CV9ONLINE_MAP_H

#include "Tile.h"
#include <iostream>
#include <vector>

class Map {
    std::vector<std::vector<Tile*>> m_map;
    bool isInMap(int x, int y);

public:
    Map();
    Tile* getTile(int x, int y);
    void replaceTile(int x, int y, Tile* tile);
    void printMap();
    ~Map();
};


#endif //CV9ONLINE_MAP_H