//
// Created by xmatonoh on 19.11.2025.
//

#ifndef WHEATFIELD_H
#define WHEATFIELD_H

#include "Tile.h"

class WheatField : public Tile {
public:
    WheatField();
    void mineMaterials(Inventory* inventory) override;
    void draw() override;
};



#endif //WHEATFIELD_H
