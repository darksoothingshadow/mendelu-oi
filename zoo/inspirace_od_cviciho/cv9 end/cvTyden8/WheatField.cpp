//
// Created by xmatonoh on 19.11.2025.
//

#include "WheatField.h"

void WheatField::mineMaterials(Inventory *inventory) {
    inventory->addWheat(7);
    std::cout << "Wheat was added to inventory." << std::endl;
}

WheatField::WheatField() {}

void WheatField::draw() {
    std::cout << " F ";
}