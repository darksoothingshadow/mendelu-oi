//
// Created by xmatonoh on 13.11.2025.
//

#ifndef TILE_H
#define TILE_H

#include<iostream>
using namespace std;

enum class TileType {
    Tree, Mine, Rose
};

class Tile {
    string m_symbol;
    int m_goldGenerated;

public:
    Tile(string symbol, int goldGenerated);
    void draw();
    int getGoldGenerated();

    static Tile* createTile(TileType type);
};



#endif //TILE_H
