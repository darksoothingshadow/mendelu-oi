//
// Created by xmusil on 11.12.2025.
//

#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <vector>

#include "Operation.h"


class Calculator {
    float m_number1;
    float m_number2;
    std::vector<Operation*> m_operations;
    Operation* m_chosenOperation;

public:
    Calculator();
    ~Calculator();
    void run();

private:
    void readNumbers();
    void printAvailableOperations();
    void chooseOperation();
    void callOperations();
};
//nic virtualniho, zadna dedicnost, jen prace s polem


#endif //CALCULATOR_H
