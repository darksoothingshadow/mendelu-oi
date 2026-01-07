//
// Created by Claude on 07.01.2026.
//

#ifndef INFOSYSTEM_VYSLEDEKSTUDENTA_H
#define INFOSYSTEM_VYSLEDEKSTUDENTA_H

#include <iostream>
#include "Ucitel.h"
using namespace std;

class VysledekStudenta {
    string m_studentName;
    int m_grade;
    Ucitel* m_teacher;

    void setStudentName(string studentName);
    void setGrade(int grade);

public:
    VysledekStudenta(string studentName, int grade, Ucitel* teacher);

    string getStudentName();
    int getGrade();
    Ucitel* getTeacher();
    void printInfo();
};

#endif //INFOSYSTEM_VYSLEDEKSTUDENTA_H
