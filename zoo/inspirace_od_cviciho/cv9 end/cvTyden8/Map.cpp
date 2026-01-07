//
// Created by xmatonoh on 13.11.2025.
//

#include "Map.h"

Map::Map(unsigned int width, unsigned int height) {
    for (int i = 0; i < height; i++) {
        vector<Tile*> emptyRow(width, nullptr);
        m_map.push_back(emptyRow);
    }
}

Map::~Map() {
    for (vector<Tile*> row : m_map) {
        for (Tile* tile : row) {
            delete tile;
        }
    }
}

bool Map::isInBounds(unsigned int row, unsigned int column) {
    int height = m_map.size();
    int width = m_map.at(0).size();

    if (row >= height || column >= width) {
        return false;
    }
    return true;
}

void Map::setTile(unsigned int row, unsigned int column, Tile* tile) {
    if (!isInBounds(row, column)) {
        return;
    }

    Tile* oldTile = m_map.at(row).at(column);
    if (oldTile == nullptr) {
        m_map.at(row).at(column) = tile;
    } else {
        delete oldTile;
        m_map.at(row).at(column) = tile;
    }
}

void Map::draw() {
    // TODO change this for-each loop into indexed one
    for (vector<Tile*> row : m_map) {

        for (Tile* tile : row) {
            if (tile != nullptr) {
                tile->draw();
            } else {
                cout << " 0 ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

Tile *Map::getTile(unsigned int row, unsigned int column) {
    if (!isInBounds(row, column)) {
        cout << "There is no explicit Tile" << endl;
        return nullptr;
    }

    return m_map.at(row).at(column);
}

