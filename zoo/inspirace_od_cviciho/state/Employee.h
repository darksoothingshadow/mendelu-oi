//
// Created by Michal Matonoha on 03.12.2025.
//

#ifndef STATE_EMLOYEE_H
#define STATE_EMLOYEE_H

#include <iostream>

#include "Developer.h"
#include "Manager.h"

class Employee {
    std::string m_name;
    int m_birthYear;
    WorkPosition* m_workPosition;

    void setName(std::string name);
    void setBirthYear(int birthYear);

public:
    Employee(std::string name, int birthYear, std::vector<std::string> languages);

    void changeToManager(std::string specialization);
    void changeToDeveloper(std::vector<std::string> languages);

    void printInfo();
};


#endif //STATE_EMLOYEE_H