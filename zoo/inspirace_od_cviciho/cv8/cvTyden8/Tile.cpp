//
// Created by xmatonoh on 13.11.2025.
//

#include "Tile.h"

Tile::Tile(string symbol, int goldGenerated) {
    m_symbol = symbol; // zkusit zkontrolovat, zda je to jen jeden znak
    m_goldGenerated = goldGenerated;
}

void Tile::draw() {
    cout << " " << m_symbol << " ";
}

int Tile::getGoldGenerated() {
    return m_goldGenerated;
}

Tile* Tile::createTile(TileType type) {
    switch (type) {
        case TileType::Mine:
            return new Tile("M", -5);
        case TileType::Rose:
            return new Tile("R", 15);
        case TileType::Tree:
            return new Tile("T", 5);
    }
}

