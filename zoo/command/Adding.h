//
// Created by xmusil on 11.12.2025.
//

#ifndef ADDING_H
#define ADDING_H
#include "Operation.h"


class Adding: public Operation{
public:
    Adding();
    float calculate(float number1, float number2);
};



#endif //ADDING_H
