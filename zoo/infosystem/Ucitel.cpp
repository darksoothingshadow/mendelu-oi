//
// Created by Claude on 07.01.2026.
//

#include "Ucitel.h"

Ucitel::Ucitel(string name) {
    setName(name);
    m_department = "";
}

Ucitel::Ucitel(string name, string department) {
    setName(name);
    m_department = department;
}

void Ucitel::setName(string name) {
    if (!name.empty()) {
        m_name = name;
        return;
    }
    m_name = "Unknown teacher";
}

string Ucitel::getName() {
    return m_name;
}

string Ucitel::getDepartment() {
    return m_department;
}

void Ucitel::setDepartment(string department) {
    m_department = department;
}
