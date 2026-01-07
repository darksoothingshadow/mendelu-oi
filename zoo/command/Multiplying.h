//
// Created by xmusil on 11.12.2025.
//

#ifndef MULTIPLYING_H
#define MULTIPLYING_H
#include "Operation.h"


class Multiplying: public Operation{
public:
    Multiplying();
    float calculate(float number1, float number2);
};



#endif //MULTIPLYING_H
