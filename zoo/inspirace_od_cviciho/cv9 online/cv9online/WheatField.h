//
// Created by Michal Matonoha on 24.11.2025.
//

#ifndef CV9ONLINE_WHEATFIELD_H
#define CV9ONLINE_WHEATFIELD_H

#include "Tile.h"

class WheatField: public Tile {
    int m_wheat;

public:
    WheatField(int wheat);
    void mineMaterials(Inventory *target) override;
    void print() override;
};


#endif //CV9ONLINE_WHEATFIELD_H