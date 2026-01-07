//
// Created by Claude on 07.01.2026.
//

#include "Zkouska.h"

Zkouska::Zkouska(string date, string name) {
    setDate(date);
    setName(name);
    m_results = {};
}

void Zkouska::setDate(string date) {
    if (!date.empty()) {
        m_date = date;
        return;
    }
    m_date = "Unknown date";
}

void Zkouska::setName(string name) {
    if (!name.empty()) {
        m_name = name;
        return;
    }
    m_name = "Unknown exam";
}

string Zkouska::getDate() {
    return m_date;
}

string Zkouska::getName() {
    return m_name;
}

// (2b) Add multiple results at once
void Zkouska::addResults(vector<VysledekStudenta*> results) {
    for (VysledekStudenta* result : results) {
        if (result != nullptr) {
            m_results.push_back(result);
        }
    }
}

// (3b) Find and print all results by specific teacher
void Zkouska::printResultsByTeacher(string teacherName) {
    cout << "Results graded by " << teacherName << ":" << endl;
    for (VysledekStudenta* result : m_results) {
        if (result->getTeacher() != nullptr && 
            result->getTeacher()->getName() == teacherName) {
            result->printInfo();
        }
    }
}

// (3b) Calculate average grade
float Zkouska::getAverageGrade() {
    if (m_results.empty()) {
        return 0;
    }

    float sum = 0;
    for (VysledekStudenta* result : m_results) {
        sum += result->getGrade();
    }

    return sum / m_results.size();
}

// (2b) Get all grades from teachers of specific department
vector<int> Zkouska::getGradesByDepartment(string department) {
    vector<int> grades = {};

    for (VysledekStudenta* result : m_results) {
        if (result->getTeacher() != nullptr &&
            result->getTeacher()->getDepartment() == department) {
            grades.push_back(result->getGrade());
        }
    }

    return grades;
}

void Zkouska::printInfo() {
    cout << "Exam: " << m_name << " (" << m_date << ")" << endl;
    cout << "Number of results: " << m_results.size() << endl;
    cout << "Average grade: " << getAverageGrade() << endl;
    cout << "---" << endl;
    for (VysledekStudenta* result : m_results) {
        result->printInfo();
    }
}
