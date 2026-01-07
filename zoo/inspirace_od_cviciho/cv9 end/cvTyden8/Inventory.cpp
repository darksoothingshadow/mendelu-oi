//
// Created by xmatonoh on 19.11.2025.
//

#include "Inventory.h"

Inventory::Inventory(int goldCount, int wheatCount) {
    m_goldCount = goldCount;
    m_wheatCount = wheatCount;
}

Inventory::Inventory() : Inventory(0, 0) {}

void Inventory::addGold(int count) {
    m_goldCount += count;
}

void Inventory::addWheat(int count) {
    m_wheatCount += count;
}

int Inventory::getGoldCount() {
    return m_goldCount;
}

int Inventory::getWheatCount() {
    return m_wheatCount;
}

void Inventory::printInfo() {
    std::cout << "Inventory has: " << m_goldCount << " golds, "
    << m_wheatCount << " wheats." << std::endl;
}

