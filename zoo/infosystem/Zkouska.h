//
// Created by Claude on 07.01.2026.
//

#ifndef INFOSYSTEM_ZKOUSKA_H
#define INFOSYSTEM_ZKOUSKA_H

#include <iostream>
#include <vector>
#include "VysledekStudenta.h"
#include "Ucitel.h"
using namespace std;

class Zkouska {
    string m_date;
    string m_name;
    vector<VysledekStudenta*> m_results;

    void setDate(string date);
    void setName(string name);

public:
    Zkouska(string date, string name);

    string getDate();
    string getName();

    // (2b) Add multiple results at once
    void addResults(vector<VysledekStudenta*> results);

    // (3b) Find and print all results by specific teacher
    void printResultsByTeacher(string teacherName);

    // (3b) Calculate average grade
    float getAverageGrade();

    // (2b) Get all grades from teachers of specific department
    vector<int> getGradesByDepartment(string department);

    void printInfo();
};

#endif //INFOSYSTEM_ZKOUSKA_H
