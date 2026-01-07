//
// Created by xmatonoh on 19.11.2025.
//

#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>

class Inventory {
    int m_goldCount;
    int m_wheatCount;

public:
    Inventory(int goldCount, int wheatCount);
    Inventory();
    void printInfo();
    void addWheat(int count);
    void addGold(int count);
    int getGoldCount();
    int getWheatCount();
};



#endif //INVENTORY_H
