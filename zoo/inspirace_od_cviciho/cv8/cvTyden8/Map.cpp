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
    unsigned int height = m_map.size();
    unsigned int width = m_map.at(0).size();

    if (row >= height || column >= width) {
        cout << "You can not index out of bounds!" << endl;
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

int Map::getGoldGeneratedFromTile(unsigned int row, unsigned int column) {
    if (!isInBounds(row, column)) {
        return 0;
    }

    Tile* tile = m_map.at(row).at(column);
    if (tile == nullptr) {
        return 0;
    }

    return tile->getGoldGenerated();
}

void Map::draw() {
    for (vector<Tile*> row : m_map) {

        for (Tile* tile : row) {
            if (tile != nullptr) {
                tile->draw();
            } else {
                cout << " x ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

