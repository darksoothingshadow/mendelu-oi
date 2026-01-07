//
// Created by Michal Matonoha on 03.12.2025.
//

#ifndef STATE_DEVELOPER_H
#define STATE_DEVELOPER_H
#include "WorkPosition.h"
#include <iostream>
#include <vector>

class Developer: public WorkPosition {
    std::vector<std::string> m_languages;

public:
    Developer(std::vector<std::string> languages);
    void printInfo() override;
    ~Developer() override = default;
};


#endif //STATE_DEVELOPER_H