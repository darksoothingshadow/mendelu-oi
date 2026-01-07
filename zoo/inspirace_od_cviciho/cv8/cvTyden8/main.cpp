#include <iostream>
#include "Tile.h"
#include "Map.h"

int main() {
    Map* map = new Map(8, 9);

    map->draw();

    map->setTile(0, 0, Tile::createTile(TileType::Tree));
    map->setTile(0, 1, Tile::createTile(TileType::Tree));
    map->setTile(0, 2, Tile::createTile(TileType::Rose));
    map->setTile(1, 0, Tile::createTile(TileType::Mine));

    map->draw();
    delete map;
    return 0;
}