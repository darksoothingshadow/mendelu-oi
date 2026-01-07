//
// Created by xmatonoh on 19.11.2025.
//

#ifndef GOLDMINE_H
#define GOLDMINE_H

#include "Tile.h"

class GoldMine: public Tile {
public:
    GoldMine();
    void mineMaterials(Inventory *inventory) override;
    void draw() override;
};



#endif //GOLDMINE_H
