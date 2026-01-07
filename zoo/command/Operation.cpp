//
// Created by xmusil on 11.12.2025.
//

#include "Operation.h"

Operation::Operation(std::string description) {
    m_description = description;//set
}

std::string Operation::getDescription() {
    return m_description;
}

//bez implementace calculate - ciste virtuali metody