//
// Created by xmatonoh on 13.11.2025.
//

#ifndef TILE_H
#define TILE_H

#include<iostream>

#include "Inventory.h"

using namespace std;

class Tile {
public:
    Tile() = default;
    virtual void mineMaterials(Inventory* inventory) = 0;
    virtual void draw() = 0;
};



#endif //TILE_H
