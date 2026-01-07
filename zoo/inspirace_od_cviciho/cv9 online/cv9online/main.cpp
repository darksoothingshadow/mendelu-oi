#include <iostream>
#include "Map.h"
#include "GoldMine.h"

int main() {

    Map* map = new Map();
    Inventory* inventory = new Inventory(5, 5);

    map->printMap();

    map->getTile(0,0)->mineMaterials(inventory);
    map->getTile(0,0)->mineMaterials(inventory);
    map->getTile(0,0)->mineMaterials(inventory);
    map->getTile(1,1)->mineMaterials(inventory);

    map->printMap();

    map->replaceTile(0,0,new GoldMine(10));

    map->printMap();


    inventory->print();

    delete map;
    delete inventory;

    return 0;
}
