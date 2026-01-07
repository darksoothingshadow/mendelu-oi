//
// Created by xmatonoh on 19.11.2025.
//

#include "MagicTile.h"

MagicTile::MagicTile() {

}

void MagicTile::mineMaterials(Inventory *inventory) {
    if (inventory->getGoldCount() == 0) {
        inventory->addWheat(5);
    } else if (inventory->getWheatCount() == 0) {
        inventory->addGold(5);
    } else {
        std::cout << "Magic does not work here." << std::endl;
    }
}

void MagicTile::draw() {
    std::cout << " M ";
}
