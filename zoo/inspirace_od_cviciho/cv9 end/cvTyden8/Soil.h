//
// Created by xmatonoh on 19.11.2025.
//

#ifndef SOIL_H
#define SOIL_H

#include "Tile.h"


class Soil: public Tile {
public:
    Soil();
    void mineMaterials(Inventory *inventory) override;
    void draw() override;
};



#endif //SOIL_H
