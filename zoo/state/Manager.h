//
// Created by Michal Matonoha on 03.12.2025.
//

#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H
#include "WorkPosition.h"
#include <iostream>


class Manager: public WorkPosition {
    std::string m_specialization;

public:
    Manager(std::string specialization);
    void printInfo() override;
    ~Manager() override = default;
};


#endif //STATE_MANAGER_H