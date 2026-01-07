//
// Created by xmusil on 11.12.2025.
//

#include <iostream>
#include "Operation.h"
#include "Calculator.h"
#include "Adding.h"
#include "Multiplying.h"

Calculator::Calculator() {
    m_number1 = 0;//pro jistotu
    m_number2 = 0;
    m_operations.push_back(new Adding());
    m_operations.push_back(new Multiplying());
}

Calculator::~Calculator() {
    for (auto operation : m_operations) {
        delete operation;
    }
}

void Calculator::run() {
    readNumbers();
    printAvailableOperations();
    chooseOperation();
    callOperations();
}

void Calculator::readNumbers() {
    std::cout << "Write first num: ";
    std::cin >> m_number1;
    std::cout << "Write second num: ";
    std::cin >> m_number2;
}

void Calculator::printAvailableOperations() {
    std::cout << "Available operations: " << std::endl;
    int i = 1;

    for (auto operation : m_operations) {
        std::cout << i << ": " << operation->getDescription()<<std::endl;
        i++;
    }
}

void Calculator::chooseOperation() {
    int chosenNumber = 0;

    do {
        std::cout << "Choose one operation: ";
        std::cin >> chosenNumber;
    }while (chosenNumber < 1 || chosenNumber > m_operations.size());//do te doby, dokud bude zadavas spatne hodnoty

    m_chosenOperation = m_operations.at(chosenNumber - 1);
}

void Calculator::callOperations() {
    float result = m_chosenOperation->calculate(m_number1, m_number2);
    std::cout << "Result: " << result << std::endl;
}