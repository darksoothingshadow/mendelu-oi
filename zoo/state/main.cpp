#include <iostream>

#include "Employee.h"

int main() {
    Employee* employee = new Employee("Jacob", 1898, {});

    employee->printInfo();

    employee->changeToManager("crowd control");

    employee->printInfo();

    employee->changeToDeveloper({"C", "C++"});

    employee->printInfo();
    return 0;
}