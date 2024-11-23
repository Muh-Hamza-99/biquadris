#include "block.h"

// BLOCK

Block::Block(bool heavy, int rotation): heavy{heavy}, rotation{rotation} {}

Block::~Block() {}

void Block::left() {
    // Check if the block goes out of bounds
    for (auto coord : coords) {
        if (coord.first - 1) return;
    }
    for (auto &coord : coords) { coord.first -= 1; }
    if (heavy) down();
}

void Block::right() {
    // Check if the block goes out of bounds
    for (auto coord : coords) {
        if (coord.first + 1) return;
    }
    for (auto &coord : coords) { coord.first += 1; }
    if (heavy) down();
}

void Block::down() {
    for (auto &coord : coords) { coord.second += 1; }
}

// IBLOCK

char IBlock::getType() const { return 'I'; }

void IBlock::init() {
    coords.emplace_back(0, 1);
    coords.emplace_back(1, 1);
    coords.emplace_back(2, 1);
    coords.emplace_back(3, 1);
}

// JBLOCK

char JBlock::getType() const { return 'J'; }

void JBlock::init() {
    coords.emplace_back(0, 0);
    coords.emplace_back(0, 1);
    coords.emplace_back(1, 1);
    coords.emplace_back(2, 1);
}

// LBLOCK

char LBlock::getType() const { return 'L'; }

void LBlock::init() {
    coords.emplace_back(2, 0);
    coords.emplace_back(0, 1);
    coords.emplace_back(1, 1);
    coords.emplace_back(2, 1);
}

// OBLOCK

char OBlock::getType() const { return 'O'; }

void OBlock::init() {
    coords.emplace_back(0, 1);
    coords.emplace_back(0, 2);
    coords.emplace_back(1, 1);
    coords.emplace_back(1, 2);
}

// SBLOCK

char SBlock::getType() const { return 'S'; }

void SBlock::init() {
    coords.emplace_back(0, 1);
    coords.emplace_back(1, 1);
    coords.emplace_back(1, 0);
    coords.emplace_back(2, 0);
}

// ZBLOCK

char ZBlock::getType() const { return 'Z'; }

void ZBlock::init() {
    coords.emplace_back(0, 0);
    coords.emplace_back(1, 0);
    coords.emplace_back(1, 1);
    coords.emplace_back(2, 1);
}

// TBLOCK

char TBlock::getType() const { return 'T'; }

void TBlock::init() {
    coords.emplace_back(1, 0);
    coords.emplace_back(0, 1);
    coords.emplace_back(1, 1);
    coords.emplace_back(2, 1);
}

// ASTERIKBLOCK

char AsterikBlock::getType() const { return '*'; }

void AsterikBlock::init() {
    coords.emplace_back(5, 2);
}