//
// Created by xmatonoh on 19.11.2025.
//

#include "GoldMine.h"

GoldMine::GoldMine() {

}

void GoldMine::draw() {
    std::cout << " G ";
}

void GoldMine::mineMaterials(Inventory *inventory) {
    inventory->addGold(7);
    std::cout << "Gold was added into inventory." << std::endl;
}
