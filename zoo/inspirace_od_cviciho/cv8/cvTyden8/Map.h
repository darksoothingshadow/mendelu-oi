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

    bool isInBounds(unsigned int row, unsigned int column);

public:
    Map(unsigned int width, unsigned int height);
    int getGoldGeneratedFromTile(unsigned int row, unsigned int column);
    ~Map();
    void draw();
    void setTile(unsigned int row, unsigned int column, Tile* tile);
};



#endif //MAP_H
