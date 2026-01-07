//
// Created by Michal Matonoha on 24.11.2025.
//

#ifndef CV9ONLINE_SOIL_H
#define CV9ONLINE_SOIL_H


#include "Tile.h"

class Soil: public Tile {
public:
    Soil();
    void mineMaterials(Inventory* target) override;
    void print() override;
};


#endif //CV9ONLINE_SOIL_H