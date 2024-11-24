#include "block.h"
#include <iostream>

// Helper functions

// Checks whether a set of coordinates is within a 11*18 boards grid
bool withinBounds(vector<pair<int, int>> coords) {
    for (auto coord : coords) {
        if (coord.first < 0 || coord.first > 10 || coord.second < 0 || coord.second > 17) return false;
    }
    return true;
}

// BLOCK

Block::Block(int generatedLevel, bool heavy): generatedLevel{generatedLevel}, heavy{heavy} {}

Block::~Block() {}

void Block::left() {
    // Check if the block goes out of bounds
    vector<pair<int, int>> newCoords { coords };
    for (auto &coord : newCoords) { coord.first -= 1; }
    if (!withinBounds(newCoords)) return;
    coords = newCoords;
    if (heavy) down();
}

void Block::right() {
    // Check if the block goes out of bounds
    vector<pair<int, int>> newCoords { coords };
    for (auto &coord : newCoords) { coord.first += 1; }
    if (!withinBounds(newCoords)) return;
    coords = newCoords;
    if (heavy) down();
}

void Block::down() {

}

vector<pair<int, int>> Block::getCoords() const { return coords; }
vector<vector<char>> Block::getDisplayBlock() const { return displayBlock; } 
int Block::getGeneratedLevel() const { return generatedLevel; }
bool Block::getHeavy() const { return heavy; }
void Block::setHeavy(bool heavy) { this->heavy = heavy; }

// IBLOCK

IBlock::IBlock(int generatedLevel, bool heavy): Block{generatedLevel, heavy} {
    coords.emplace_back(0, 1);
    coords.emplace_back(1, 1);
    coords.emplace_back(2, 1);
    coords.emplace_back(3, 1);
    displayBlock = {{' ', ' ', ' ', ' '}, {'I', 'I', 'I', 'I'}};
}

void IBlock::rotatecw() {
    vector<pair<int, int>> newCoords { coords };
    if (rotation == 0) {
        newCoords[0].first += 2;
        newCoords[0].second += 2;
        newCoords[1].first += 1;
        newCoords[1].second += 1;
        newCoords[3].first -= 1;
        newCoords[3].second -= 1;
    } else if (rotation == 1) {
        newCoords[0].first += 1;
        newCoords[0].second -= 1;
        newCoords[2].first -= 1;
        newCoords[2].second += 1;
        newCoords[3].first -= 2;
        newCoords[3].second += 2;
    } else if (rotation == 2) {
        newCoords[0].first -= 2;
        newCoords[0].second -= 2;
        newCoords[1].first -= 1;
        newCoords[1].second -= 1;
        newCoords[3].first += 1;
        newCoords[3].second += 1;
    } else {
        newCoords[0].first -= 1;
        newCoords[0].second += 1;
        newCoords[2].first += 1;
        newCoords[2].second -= 1;
        newCoords[3].first += 2;
        newCoords[3].second -= 2;
    }
    if (!withinBounds(newCoords)) return;
    coords = newCoords;
    rotation = (rotation + 1) % 4;
}

void IBlock::rotateccw() {
    vector<pair<int, int>> newCoords { coords };
    if (rotation == 0) {
        newCoords[0].first += 1;
        newCoords[0].second -= 1;
        newCoords[2].first -= 1;
        newCoords[2].second += 1;
        newCoords[3].first -= 2;
        newCoords[3].second += 2;
    } else if (rotation == 1) {
        newCoords[0].first -= 2;
        newCoords[0].second -= 2;
        newCoords[1].first -= 1;
        newCoords[1].second -= 1;
        newCoords[3].first += 1;
        newCoords[3].second += 1;
    } else if (rotation == 2) {
        newCoords[0].first -= 1;
        newCoords[0].second += 1;
        newCoords[2].first += 1;
        newCoords[2].second -= 1;
        newCoords[3].first += 2;
        newCoords[3].second -= 2;
    } else {
        newCoords[0].first += 2;
        newCoords[0].second += 2;
        newCoords[1].first += 1;
        newCoords[1].second += 1;
        newCoords[3].first -= 1;
        newCoords[3].second -= 1;
    }
    if (!withinBounds(newCoords)) return;
    coords = newCoords;
    rotation = (rotation - 1) % 4;
}

char IBlock::getType() const { return 'I'; }

// JBLOCK

JBlock::JBlock(int generatedLevel, bool heavy): Block{generatedLevel, heavy} {
    coords.emplace_back(0, 0);
    coords.emplace_back(0, 1);
    coords.emplace_back(1, 1);
    coords.emplace_back(2, 1);
    displayBlock = {{'J', ' ', ' ', ' '}, {'J', 'J', 'J', ' '}};
}

void JBlock::rotatecw() {
    vector<pair<int, int>> newCoords { coords };
    if (rotation == 0) {
        newCoords[0].first += 2;
        newCoords[1].first += 1;
        newCoords[1].second -= 1;
        newCoords[3].first -= 1;
        newCoords[3].second += 1;
    } else if (rotation == 1) {
        newCoords[0].second += 2;
        newCoords[1].first += 1;
        newCoords[1].second += 1;
        newCoords[3].first -= 1;
        newCoords[3].second -= 1;
    } else if (rotation == 2) {
        newCoords[0].first -= 2;
        newCoords[1].first -= 1;
        newCoords[1].second += 1;
        newCoords[3].first += 1;
        newCoords[3].second -= 1;
    } else {
        newCoords[0].second -= 2;
        newCoords[1].first -= 1;
        newCoords[1].second -= 1;
        newCoords[3].first += 1;
        newCoords[3].second += 1;
    }
    if (!withinBounds(newCoords)) return;
    coords = newCoords;
    rotation = (rotation + 1) % 4;
}

void JBlock::rotateccw() {
    vector<pair<int, int>> newCoords { coords };
    if (rotation == 0) {
        newCoords[0].second += 2;
        newCoords[1].first += 1;
        newCoords[1].second += 1;
        newCoords[3].first -= 1;
        newCoords[3].second -= 1;
    } else if (rotation == 1) {
        newCoords[0].first -= 2;
        newCoords[1].first -= 1;
        newCoords[1].second += 1;
        newCoords[3].first += 1;
        newCoords[3].second -= 1;
    } else if (rotation == 2) {
        newCoords[0].second -= 2;
        newCoords[1].first -= 1;
        newCoords[1].second -= 1;
        newCoords[3].first += 1;
        newCoords[3].second += 1;
    } else {
        newCoords[0].first += 2;
        newCoords[1].first += 1;
        newCoords[1].second -= 1;
        newCoords[3].first -= 1;
        newCoords[3].second += 1;
    }
    if (!withinBounds(newCoords)) return;
    coords = newCoords;
    rotation = (rotation - 1) % 4;
}

char JBlock::getType() const { return 'J'; }

// LBLOCK

LBlock::LBlock(int generatedLevel, bool heavy): Block{generatedLevel, heavy} {
    coords.emplace_back(2, 0);
    coords.emplace_back(2, 1);
    coords.emplace_back(1, 1);
    coords.emplace_back(0, 1);
    displayBlock = {{' ', ' ', 'L', ' '}, {'L', 'L', 'L', ' '}};
}

void LBlock::rotatecw() {
    vector<pair<int, int>> newCoords { coords };
    if (rotation == 0) {
        newCoords[0].second += 2;
        newCoords[1].first -= 1;
        newCoords[1].second += 1;
        newCoords[3].first += 1;
        newCoords[3].second -= 1;
    } else if (rotation == 1) {
        newCoords[0].first -= 2;
        newCoords[1].first -= 1;
        newCoords[1].second -= 1;
        newCoords[3].first += 1;
        newCoords[3].second += 1;
    } else if (rotation == 2) {
        newCoords[0].second -= 2;
        newCoords[1].first += 1;
        newCoords[1].second -= 1;
        newCoords[3].first -= 1;
        newCoords[3].second += 1;
    } else {
        newCoords[0].first += 2;
        newCoords[1].first += 1;
        newCoords[1].second += 1;
        newCoords[3].first -= 1;
        newCoords[3].second -= 1;
    }
    if (!withinBounds(newCoords)) return;
    coords = newCoords;
    rotation = (rotation + 1) % 4;
}

void LBlock::rotateccw() {
    vector<pair<int, int>> newCoords { coords };
    if (rotation == 0) {
        newCoords[0].first -= 2;
        newCoords[1].first -= 1;
        newCoords[1].second -= 1;
        newCoords[3].first += 1;
        newCoords[3].second += 1;
    } else if (rotation == 1) {
        newCoords[0].second -= 2;
        newCoords[1].first += 1;
        newCoords[1].second -= 1;
        newCoords[3].first -= 1;
        newCoords[3].second += 1;
    } else if (rotation == 2) {
        newCoords[0].first += 2;
        newCoords[1].first += 1;
        newCoords[1].second += 1;
        newCoords[3].first -= 1;
        newCoords[3].second -= 1;
    } else {
        newCoords[0].second += 2;
        newCoords[1].first -= 1;
        newCoords[1].second += 1;
        newCoords[3].first += 1;
        newCoords[3].second -= 1;
    }
    if (!withinBounds(newCoords)) return;
    coords = newCoords;
    rotation = (rotation - 1) % 4;
}

char LBlock::getType() const { return 'L'; }

// OBLOCK

OBlock::OBlock(int generatedLevel, bool heavy): Block{generatedLevel, heavy} {
    coords.emplace_back(0, 0);
    coords.emplace_back(0, 1);
    coords.emplace_back(1, 0);
    coords.emplace_back(1, 1);
    displayBlock = {{'O', 'O', ' ', ' '}, {'O', 'O', ' ', ' '}};
}

void OBlock::rotatecw() {}
void OBlock::rotateccw() {}

char OBlock::getType() const { return 'O'; }

// SBLOCK

SBlock::SBlock(int generatedLevel, bool heavy): Block{generatedLevel, heavy} {
    coords.emplace_back(0, 1);
    coords.emplace_back(1, 1);
    coords.emplace_back(1, 0);
    coords.emplace_back(2, 0);
    displayBlock = {{' ', 'S', 'S', ' '}, {'S', 'S', ' ', ' '}};
}

void SBlock::rotatecw() {
    if (rotation == 0) {
        coords[0].first += 1;
        coords[0].second -= 1;
        coords[2].first += 1;
        coords[2].second += 1;
        coords[3].second += 2;
    } else if (rotation == 1) {
        coords[0].first += 1;
        coords[0].second += 1;
        coords[2].first -= 1;
        coords[2].second += 1;
        coords[3].first -= 2;
    } else if (rotation == 2) {
        coords[0].first -= 1;
        coords[0].second += 1;
        coords[2].first -= 1;
        coords[2].second -= 1;
        coords[3].second -= 2;
    } else {
        coords[0].first -= 1;
        coords[0].second -= 1;
        coords[2].first += 1;
        coords[2].second -= 1;
        coords[3].first += 2;
    }
    rotation = (rotation + 1) % 4;
}

void SBlock::rotateccw() {
    vector<pair<int, int>> newCoords { coords };
    if (rotation == 0) {
        newCoords[0].first += 1;
        newCoords[0].second += 1;
        newCoords[2].first -= 1;
        newCoords[2].second += 1;
        newCoords[3].first -= 2;
    } else if (rotation == 1) {
        newCoords[0].first -= 1;
        newCoords[0].second += 1;
        newCoords[2].first -= 1;
        newCoords[2].second -= 1;
        newCoords[3].second -= 2;
    } else if (rotation == 2) {
        newCoords[0].first += 1;
        newCoords[0].second += 1;
        newCoords[2].first += 1;
        newCoords[2].second -= 1;
        newCoords[3].first += 2;
    } else {
        newCoords[0].first += 1;
        newCoords[0].second -= 1;
        newCoords[2].first += 1;
        newCoords[2].second += 1;
        newCoords[3].second += 2;
    }
    if (!withinBounds(newCoords)) return;
    coords = newCoords;
    rotation = (rotation - 1) % 4;
}

char SBlock::getType() const { return 'S'; }

// ZBLOCK

ZBlock::ZBlock(int generatedLevel, bool heavy): Block{generatedLevel, heavy} {
    coords.emplace_back(0, 0);
    coords.emplace_back(1, 0);
    coords.emplace_back(1, 1);
    coords.emplace_back(2, 1);
    displayBlock = {{'Z', 'Z', ' ', ' '}, {' ', 'Z', 'Z', ' '}};
}

void ZBlock::rotatecw() {
    vector<pair<int, int>> newCoords { coords };
    if (rotation == 0) {
        newCoords[0].first += 2;
        newCoords[1].first += 1;
        newCoords[1].second += 1;
        newCoords[3].first -= 1;
        newCoords[3].second += 1;
    } else if (rotation == 1) {
        newCoords[0].second += 2;
        newCoords[1].first -= 1;
        newCoords[1].second += 1;
        newCoords[3].first -= 1;
        newCoords[3].second -= 1;
    } else if (rotation == 2) {
        newCoords[0].first -= 2;
        newCoords[1].first -= 1;
        newCoords[1].second -= 1;
        newCoords[3].first += 1;
        newCoords[3].second -= 1;
    } else {
        newCoords[0].second -= 2;
        newCoords[1].first += 1;
        newCoords[1].second -= 1;
        newCoords[3].first += 1;
        newCoords[3].second += 1;
    }
    if (!withinBounds(newCoords)) return;
    coords = newCoords;
    rotation = (rotation + 1) % 4;
}

void ZBlock::rotateccw() {
    vector<pair<int, int>> newCoords { coords };
    if (rotation == 0) {
        newCoords[0].second += 2;
        newCoords[1].first -= 1;
        newCoords[1].second += 1;
        newCoords[3].first -= 1;
        newCoords[3].second -= 1;
    } else if (rotation == 1) {
        newCoords[0].first -= 2;
        newCoords[1].first -= 1;
        newCoords[1].second -= 1;
        newCoords[3].first += 1;
        newCoords[3].second -= 1;
    } else if (rotation == 2) {
        newCoords[0].second -= 2;
        newCoords[1].first += 1;
        newCoords[1].second -= 1;
        newCoords[3].first += 1;
        newCoords[3].second += 1;
    } else {
        newCoords[0].first += 2;
        newCoords[1].first += 1;
        newCoords[1].second += 1;
        newCoords[3].first -= 1;
        newCoords[3].second += 1;
    }
    if (!withinBounds(newCoords)) return;
    coords = newCoords;
    rotation = (rotation - 1) % 4;
}

char ZBlock::getType() const { return 'Z'; }

// TBLOCK

TBlock::TBlock(int generatedLevel, bool heavy): Block{generatedLevel, heavy} {
    coords.emplace_back(1, 0);
    coords.emplace_back(0, 1);
    coords.emplace_back(1, 1);
    coords.emplace_back(2, 1);
    displayBlock = {{'T', 'T', 'T', ' '}, {' ', 'T', ' ', ' '}};
}

void TBlock::rotatecw() {
    vector<pair<int, int>> newCoords { coords };
    if (rotation == 0) {
        newCoords[0].first += 1;
        newCoords[0].second += 1;
        newCoords[1].first += 1;
        newCoords[1].second -= 1;
        newCoords[3].first -= 1;
        newCoords[3].second += 1;
    } else if (rotation == 1) {
        newCoords[0].first -= 1;
        newCoords[0].second += 1;
        newCoords[1].first += 1;
        newCoords[1].second += 1;
        newCoords[3].first -= 1;
        newCoords[3].second -= 1;
    } else if (rotation == 2) {
        newCoords[0].first -= 1;
        newCoords[0].second -= 1;
        newCoords[1].first -= 1;
        newCoords[1].second += 1;
        newCoords[3].first += 1;
        newCoords[3].second -= 1;
    } else {
        newCoords[0].first += 1;
        newCoords[0].second -= 1;
        newCoords[1].first -= 1;
        newCoords[1].second -= 1;
        newCoords[3].first += 1;
        newCoords[3].second += 1;
    }
    if (!withinBounds(newCoords)) return;
    coords = newCoords;
    rotation = (rotation + 1) % 4;
}

void TBlock::rotateccw() {
    vector<pair<int, int>> newCoords { coords };
    if (rotation == 0) {
        newCoords[0].first -= 1;
        newCoords[0].second += 1;
        newCoords[1].first += 1;
        newCoords[1].second += 1;
        newCoords[3].first -= 1;
        newCoords[3].second -= 1;
    } else if (rotation == 1) {
        newCoords[0].first -= 1;
        newCoords[0].second -= 1;
        newCoords[1].first -= 1;
        newCoords[1].second += 1;
        newCoords[3].first += 1;
        newCoords[3].second += 1;
    } else if (rotation == 2) {
        newCoords[0].first += 1;
        newCoords[0].second -= 1;
        newCoords[1].first -= 1;
        newCoords[1].second -= 1;
        newCoords[3].first += 1;
        newCoords[3].second += 1;
    } else {
        newCoords[0].first += 1;
        newCoords[0].second += 1;
        newCoords[1].first += 1;
        newCoords[1].second -= 1;
        newCoords[3].first -= 1;
        newCoords[3].second += 1;
    }
    if (!withinBounds(newCoords)) return;
    coords = newCoords;
    rotation = (rotation - 1) % 4;
}

char TBlock::getType() const { return 'T'; }

// ASTERIKBLOCK

AsterikBlock::AsterikBlock(int generatedLevel, bool heavy): Block{generatedLevel, heavy} {
    coords.emplace_back(5, 2);
}

void AsterikBlock::rotatecw() {}
void AsterikBlock::rotateccw() {}

char AsterikBlock::getType() const { return '*'; }
