//
// Created by xmatonoh on 13.11.2025.
//

#ifndef MAP_H
#define MAP_H

#include "Tile.h"
#include<iostream>
#include<vector>

using namespace std;

class Map {
    vector<vector<Tile*>> m_map;

    bool isInBounds(unsigned int row, unsigned int column); // TODO

public:
    Map(unsigned int width, unsigned int height);
    ~Map();
    void draw();
    void setTile(unsigned int row, unsigned int column, Tile* tile);
    Tile* getTile(unsigned int row, unsigned int column); // TODO

};



#endif //MAP_H
