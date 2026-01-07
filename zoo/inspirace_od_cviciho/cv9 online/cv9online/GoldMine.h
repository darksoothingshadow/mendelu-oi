//
// Created by Michal Matonoha on 24.11.2025.
//

#ifndef CV9ONLINE_GOLDMINE_H
#define CV9ONLINE_GOLDMINE_H

#include "Tile.h"

class GoldMine: public Tile {
    int m_gold;

public:
    GoldMine(int gold);
    void mineMaterials(Inventory *target) override;
    void print() override;
};

#endif //CV9ONLINE_GOLDMINE_H