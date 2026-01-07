#include <iostream>

#include "MagicTile.h"
#include "Tile.h"
#include "Map.h"

int main() {
    Inventory* inventory = new Inventory();
    Map* map = new Map(8, 9);

    map->setTile(0, 0, new MagicTile());

    map->draw();

    inventory->printInfo();

    map->getTile(0, 0)->mineMaterials(inventory);

    inventory->printInfo();

    return 0;
}