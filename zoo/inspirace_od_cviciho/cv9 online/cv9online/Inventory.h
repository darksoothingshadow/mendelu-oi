//
// Created by Michal Matonoha on 24.11.2025.
//

#ifndef CV9ONLINE_INVENTORY_H
#define CV9ONLINE_INVENTORY_H

#include <iostream>

class Inventory {
    int m_gold;
    int m_wheat;

public:
    Inventory(int gold = 0, int wheat = 0);
    void addGold(int amount);
    void addWheat(int amount);
    void print();
};


#endif //CV9ONLINE_INVENTORY_H