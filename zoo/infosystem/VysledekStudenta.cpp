//
// Created by Claude on 07.01.2026.
//

#include "VysledekStudenta.h"

VysledekStudenta::VysledekStudenta(string studentName, int grade, Ucitel* teacher) {
    setStudentName(studentName);
    setGrade(grade);
    m_teacher = teacher;
}

void VysledekStudenta::setStudentName(string studentName) {
    if (!studentName.empty()) {
        m_studentName = studentName;
        return;
    }
    m_studentName = "Unknown student";
}

void VysledekStudenta::setGrade(int grade) {
    if (grade >= 1 && grade <= 5) {
        m_grade = grade;
        return;
    }
    m_grade = 5;
}

string VysledekStudenta::getStudentName() {
    return m_studentName;
}

int VysledekStudenta::getGrade() {
    return m_grade;
}

Ucitel* VysledekStudenta::getTeacher() {
    return m_teacher;
}

void VysledekStudenta::printInfo() {
    cout << "Student: " << m_studentName 
         << ", Grade: " << m_grade;
    if (m_teacher != nullptr) {
        cout << ", Teacher: " << m_teacher->getName();
    }
    cout << endl;
}
