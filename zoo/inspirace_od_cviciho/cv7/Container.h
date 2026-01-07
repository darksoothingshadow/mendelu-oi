//
// Created by Michal Matonoha on 05.11.2025.
//

#ifndef CV7_CONTAINER_H
#define CV7_CONTAINER_H

#include <iostream>
#include <vector>
#include "Product.h"
using namespace std;

class Container {
    string m_position;
    float m_maxLoad;
    vector<Product*> m_products;

    void setMaxLoad(float maxLoad);

public:
    Container(string position, float maxLoad);
    void storeProduct(Product* product);
    void removeProduct(string description);
    float getProductsWeight();
    string getProductsDescriptions();
    string getPosition();
    void setPosition(string position);
};


#endif //CV7_CONTAINER_H