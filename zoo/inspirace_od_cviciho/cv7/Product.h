//
// Created by Michal Matonoha on 05.11.2025.
//

#ifndef CV7_PRODUCT_H
#define CV7_PRODUCT_H

#include <iostream>
using namespace std;

class Product {
    string m_description;
    float m_weight;

    void setDescription(string description);
    void setWeight(float weight);

    public:
    Product(string description, float weight);
    string getDescription();
    float getWeight();
};


#endif //CV7_PRODUCT_H