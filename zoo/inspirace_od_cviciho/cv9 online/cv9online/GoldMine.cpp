//
// Created by Michal Matonoha on 24.11.2025.
//

#include "GoldMine.h"

GoldMine::GoldMine(int gold) {
    if (gold < 0) {
        std::cerr << "Cannot set negative amount of gold!" << std::endl;
        return;
    }
    m_gold = gold;
}

void GoldMine::mineMaterials(Inventory *target) {
    if (m_gold > 0) {
        target->addGold(1);
        m_gold--;
    } else {
        std::cerr << "This mine is empty!" << std::endl;
    }
}

void GoldMine::print() {
    std::cout << "G" << m_gold << " ";
}