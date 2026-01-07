//
// Created by xmusil on 11.12.2025.
//

#ifndef OPERATION_H
#define OPERATION_H
#include <string>
//jen virtualni - musime udelat implementaci
//ciste virtualni - =0; nema implementaci

class Operation {
    std::string m_description;
public:
    Operation(std::string description);
    std::string getDescription();//pridat do modelu!
    virtual float calculate(float number1, float number2) = 0;

};



#endif //OPERATION_H
