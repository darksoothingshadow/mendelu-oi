//
// Created by Michal Matonoha on 24.11.2025.
//

#include "Inventory.h"

Inventory::Inventory(int gold, int wheat) {
    m_gold = gold;
    m_wheat = wheat;
}

void Inventory::addGold(int amount) {
    if (amount < 0) {
        std::cerr << "Cannot add a negative number!" << std::endl;
    } else {
        m_gold += amount;
    }
}

void Inventory::addWheat(int amount) {
    if (amount < 0) {
        std::cerr << "Cannot add a negative number!" << std::endl;
        return;
    }
    m_wheat += amount;
}

void Inventory::print() {
    std::cout <<
    " --- Inventory --- " << std::endl <<
    "Gold: " << m_gold << std::endl <<
    "Wheat: " << m_wheat << std::endl;
}