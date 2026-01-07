//
// Created by Michal Matonoha on 03.12.2025.
//

#include "Employee.h"


Employee::Employee(std::string name, int birthYear, std::vector<std::string> languages) {
    m_workPosition = nullptr; // musime alokovat nejakou pamet na tu nasi pozici
    setName(name);
    setBirthYear(birthYear);
    changeToDeveloper(languages);
}

void Employee::changeToDeveloper(std::vector<std::string> languages) {
    if (languages.empty()) {
        std::cout << "We belive this employee knows C++\n" << std::endl;
        languages.push_back("C++");
    }

    delete m_workPosition;
    m_workPosition = new Developer(languages);
}

void Employee::changeToManager(std::string specialization) {
    if (specialization.empty()) {
        std::cout << "We belive this employee is specialized in communication.\n" << std::endl;
        specialization = "communication";
    }

    delete m_workPosition;
    m_workPosition = new Manager(specialization);
}

void Employee::printInfo() {
    std::cout << "This employee is called: " << m_name << "\n"
    << "Was born in: " << m_birthYear << std::endl;
    m_workPosition->printInfo();
}

void Employee::setBirthYear(int birthYear) {
    if (birthYear < 1905) {
        std::cout << "Some biologist said that the maximum one person can live is 120 years. Setting to 1905.\n" << std::endl;
        m_birthYear = 1905;
    } else if (birthYear > 2007) {
        std::cout << "Employees can not be younger than 18 years (I think). Setting to 2007.\n" << std::endl;
        m_birthYear = 2007;
    } else {
        m_birthYear = birthYear;
    }
}

void Employee::setName(std::string name) {
    if (!name.empty()) {
        m_name = name;
    } else {
        std::cout << "Name can not be empty. This employee will be John from now on." << std::endl;
        m_name = "John";
    }
}

