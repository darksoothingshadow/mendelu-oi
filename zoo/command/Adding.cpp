//
// Created by xmusil on 11.12.2025.
//

#include "Adding.h"

Adding::Adding(): Operation("Adding") {}

float Adding::calculate(float number1, float number2) {
    return number1 + number2;
}
