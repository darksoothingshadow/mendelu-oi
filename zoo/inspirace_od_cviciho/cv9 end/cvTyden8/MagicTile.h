//
// Created by xmatonoh on 19.11.2025.
//

#ifndef MAGICTILE_H
#define MAGICTILE_H
#include "Tile.h"


class MagicTile: public Tile {
public:
    MagicTile();
    void mineMaterials(Inventory *inventory) override;
    void draw() override;
};



#endif //MAGICTILE_H
