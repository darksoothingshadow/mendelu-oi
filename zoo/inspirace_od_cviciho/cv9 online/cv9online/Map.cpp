//
// Created by Michal Matonoha on 24.11.2025.
//

#include "Map.h"

#include "Map.h"
#include "Soil.h"
#include "GoldMine.h"
#include "WheatField.h"


Map::Map() {
    m_map = {
        {new GoldMine(3), new WheatField(3), new Soil()},
        {new Soil(), new WheatField(2), new Soil()},
        {new GoldMine(4), new Soil(), new GoldMine(1)}
    };
}

bool Map::isInMap(int x, int y) {
    if (x >= m_map.size()) {
        std::cerr << "Error! Field on this index doesn't exist" << std::endl;
        return false;
    }

    if (y >= m_map.at(x).size()) {
        std::cerr << "Error! Field on this index doesn't exist" << std::endl;
        return false;
    }

    return true;
}

Tile *Map::getTile(int x, int y) {
    if (isInMap(x, y)) {
        return m_map.at(x).at(y);
    } else {
        return nullptr;
    }
}

void Map::replaceTile(int x, int y, Tile *tile) {
    if (isInMap(x, y)) {
        delete m_map.at(x).at(y);
        m_map.at(x).at(y) = tile;
    }
}

void Map::printMap() {
    std::cout << "--- Map ---" << std::endl;

    for (std::vector<Tile*> row: m_map) {
        for (Tile* tile : row) {
            tile->print();
        }
        std::cout << std::endl;
    }
}

Map::~Map() {
    for (std::vector<Tile*> row : m_map) {
        for (Tile* tile: row) {
            delete tile;
        }
    }
}