//
// Created by Michal Matonoha on 10.11.2025.
//

#ifndef CV7_SECTION_H
#define CV7_SECTION_H

#include <iostream>
#include <vector>
#include "Product.h"
#include "Container.h"
using namespace std;


class Section {
    string m_position;
    vector<Container*> m_containers;

    bool isPositionFree(string position);
    Container* getContainerAtPosition(string position);

public:
    Section(string position);
    ~Section();

    void createContainer(string position, float maxCapacity);
    void createContainer(string position);
    void removeContainer(string containerPosition);
    void addProductToContainer(string containerPosition, Product* product);
    void removeProductsFromContainer(string containerPosition, string productDescription);
    void printStats();

};


#endif //CV7_SECTION_H