//
// Created by Michal Matonoha on 03.12.2025.
//

#include "Manager.h"

Manager::Manager(std::string specialization) {
    m_specialization = specialization;
}

void Manager::printInfo() {
    std::cout << "Work position: Manager; specialization: " << m_specialization << "\n" << std::endl;
}

