//
// Created by Michal Matonoha on 03.12.2025.
//

#include "Developer.h"

Developer::Developer(std::vector<std::string> languages) {
    m_languages = languages;
}

void Developer::printInfo() {
    std::cout << "Work position: Developer; languages: ";
    for (std::string language: m_languages) {
        std::cout << language << "; ";
    }
    std::cout << "\n" << std::endl;
}


