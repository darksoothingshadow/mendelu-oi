//
// Created by Michal Matonoha on 24.11.2025.
//

#include "WheatField.h"

WheatField::WheatField(int wheat) {
    if (wheat < 0) {
        std::cerr << "Cannot set negative value!" << std::endl;
    } else {
        m_wheat = wheat;
    }
}

void WheatField::mineMaterials(Inventory *target) {
    if (m_wheat > 0) {
        target->addWheat(1);
        m_wheat--;
    } else {
        std::cerr << "This field is empty!" << std::endl;
    }
}

void WheatField::print() {
    std::cout << "W" << m_wheat << " ";
}