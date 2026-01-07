//
// Created by Michal Matonoha on 24.11.2025.
//

#ifndef CV9ONLINE_TILE_H
#define CV9ONLINE_TILE_H

#include "Inventory.h"

class Tile {
public:
    Tile() = default;
    virtual void mineMaterials(Inventory* target) = 0;
    virtual void print() = 0;
};


#endif //CV9ONLINE_TILE_H