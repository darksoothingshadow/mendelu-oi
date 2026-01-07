//
// Created by Claude on 07.01.2026.
//

#ifndef INFOSYSTEM_UCITEL_H
#define INFOSYSTEM_UCITEL_H

#include <iostream>
using namespace std;

class Ucitel {
    string m_name;
    string m_department;

    void setName(string name);

public:
    Ucitel(string name);
    Ucitel(string name, string department);

    string getName();
    string getDepartment();
    void setDepartment(string department);
};

#endif //INFOSYSTEM_UCITEL_H
