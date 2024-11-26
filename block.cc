#include "block.h"
#include <iostream>

// BLOCK

Block::Block(int generatedLevel, bool heavy): generatedLevel{generatedLevel}, heavy{heavy} {}
Block::Block(const Block &other): generatedLevel{other.generatedLevel}, heavy{other.heavy}, coords{other.coords} {}
Block::Block(Block &&other): generatedLevel{other.generatedLevel}, heavy{other.heavy}, coords{other.coords} {}

Block::~Block() {}

void Block::left() {
    for (auto &coord : coords) { coord.first -= 1; }
}

void Block::right() {
    for (auto &coord : coords) { coord.first += 1; }
}

void Block::down() {
    for (auto &coord : coords) { coord.second += 1; }
}

void Block::up() {
    for (auto &coord : coords) { coord.second -= 1; }
}

vector<pair<int, int>> Block::getCoords() const { return coords; }
vector<vector<char>> Block::getDisplayBlock() const { return displayBlock; } 
int Block::getGeneratedLevel() const { return generatedLevel; }
bool Block::getHeavy() const { return heavy; }
void Block::setHeavy(bool heavy) { this->heavy = heavy; }
void Block::removeCoord(pair<int, int> coord) {
    for (vector<pair<int, int>>::iterator it = coords.begin(); it != coords.end();) {
        if (it->first == coord.first && it->second == coord.second) {
            it = coords.erase(it);
        } else {
            ++it;
        }
    }
}

// IBLOCK

IBlock::IBlock(int generatedLevel, bool heavy): Block{generatedLevel, heavy} {
    coords.emplace_back(0, 1);
    coords.emplace_back(1, 1);
    coords.emplace_back(2, 1);
    coords.emplace_back(3, 1);
    displayBlock = {{' ', ' ', ' ', ' '}, {'I', 'I', 'I', 'I'}};
}

void IBlock::rotatecw() {
    if (rotation == 0) {
        coords[0].first += 2;
        coords[0].second += 2;
        coords[1].first += 1;
        coords[1].second += 1;
        coords[3].first -= 1;
        coords[3].second -= 1;
    } else if (rotation == 1) {
        coords[0].first += 1;
        coords[0].second -= 1;
        coords[2].first -= 1;
        coords[2].second += 1;
        coords[3].first -= 2;
        coords[3].second += 2;
    } else if (rotation == 2) {
        coords[0].first -= 2;
        coords[0].second -= 2;
        coords[1].first -= 1;
        coords[1].second -= 1;
        coords[3].first += 1;
        coords[3].second += 1;
    } else {
        coords[0].first -= 1;
        coords[0].second += 1;
        coords[2].first += 1;
        coords[2].second -= 1;
        coords[3].first += 2;
        coords[3].second -= 2;
    }
    rotation = (rotation + 1) % 4;
}

void IBlock::rotateccw() {
    if (rotation == 0) {
        coords[0].first += 1;
        coords[0].second -= 1;
        coords[2].first -= 1;
        coords[2].second += 1;
        coords[3].first -= 2;
        coords[3].second += 2;
    } else if (rotation == 1) {
        coords[0].first -= 2;
        coords[0].second -= 2;
        coords[1].first -= 1;
        coords[1].second -= 1;
        coords[3].first += 1;
        coords[3].second += 1;
    } else if (rotation == 2) {
        coords[0].first -= 1;
        coords[0].second += 1;
        coords[2].first += 1;
        coords[2].second -= 1;
        coords[3].first += 2;
        coords[3].second -= 2;
    } else {
        coords[0].first += 2;
        coords[0].second += 2;
        coords[1].first += 1;
        coords[1].second += 1;
        coords[3].first -= 1;
        coords[3].second -= 1;
    }
    rotation = (rotation - 1 + 4) % 4;
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
    if (rotation == 0) {
        coords[0].first += 2;
        coords[1].first += 1;
        coords[1].second -= 1;
        coords[3].first -= 1;
        coords[3].second += 1;
    } else if (rotation == 1) {
        coords[0].second += 2;
        coords[1].first += 1;
        coords[1].second += 1;
        coords[3].first -= 1;
        coords[3].second -= 1;
    } else if (rotation == 2) {
        coords[0].first -= 2;
        coords[1].first -= 1;
        coords[1].second += 1;
        coords[3].first += 1;
        coords[3].second -= 1;
    } else {
        coords[0].second -= 2;
        coords[1].first -= 1;
        coords[1].second -= 1;
        coords[3].first += 1;
        coords[3].second += 1;
    }
    rotation = (rotation + 1) % 4;
}

void JBlock::rotateccw() {
    if (rotation == 0) {
        coords[0].second += 2;
        coords[1].first += 1;
        coords[1].second += 1;
        coords[3].first -= 1;
        coords[3].second -= 1;
    } else if (rotation == 1) {
        coords[0].first -= 2;
        coords[1].first -= 1;
        coords[1].second += 1;
        coords[3].first += 1;
        coords[3].second -= 1;
    } else if (rotation == 2) {
        coords[0].second -= 2;
        coords[1].first -= 1;
        coords[1].second -= 1;
        coords[3].first += 1;
        coords[3].second += 1;
    } else {
        coords[0].first += 2;
        coords[1].first += 1;
        coords[1].second -= 1;
        coords[3].first -= 1;
        coords[3].second += 1;
    }
    rotation = (rotation - 1 + 4) % 4;
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
    if (rotation == 0) {
        coords[0].second += 2;
        coords[1].first -= 1;
        coords[1].second += 1;
        coords[3].first += 1;
        coords[3].second -= 1;
    } else if (rotation == 1) {
        coords[0].first -= 2;
        coords[1].first -= 1;
        coords[1].second -= 1;
        coords[3].first += 1;
        coords[3].second += 1;
    } else if (rotation == 2) {
        coords[0].second -= 2;
        coords[1].first += 1;
        coords[1].second -= 1;
        coords[3].first -= 1;
        coords[3].second += 1;
    } else {
        coords[0].first += 2;
        coords[1].first += 1;
        coords[1].second += 1;
        coords[3].first -= 1;
        coords[3].second -= 1;
    }
    rotation = (rotation + 1) % 4;
}

void LBlock::rotateccw() {
    if (rotation == 0) {
        coords[0].first -= 2;
        coords[1].first -= 1;
        coords[1].second -= 1;
        coords[3].first += 1;
        coords[3].second += 1;
    } else if (rotation == 1) {
        coords[0].second -= 2;
        coords[1].first += 1;
        coords[1].second -= 1;
        coords[3].first -= 1;
        coords[3].second += 1;
    } else if (rotation == 2) {
        coords[0].first += 2;
        coords[1].first += 1;
        coords[1].second += 1;
        coords[3].first -= 1;
        coords[3].second -= 1;
    } else {
        coords[0].second += 2;
        coords[1].first -= 1;
        coords[1].second += 1;
        coords[3].first += 1;
        coords[3].second -= 1;
    }
    rotation = (rotation - 1 + 4) % 4;
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
    if (rotation == 0) {
        coords[0].first += 1;
        coords[0].second += 1;
        coords[2].first -= 1;
        coords[2].second += 1;
        coords[3].first -= 2;
    } else if (rotation == 1) {
        coords[0].first -= 1;
        coords[0].second += 1;
        coords[2].first -= 1;
        coords[2].second -= 1;
        coords[3].second -= 2;
    } else if (rotation == 2) {
        coords[0].first -= 1;
        coords[0].second -= 1;
        coords[2].first += 1;
        coords[2].second -= 1;
        coords[3].first += 2;
    } else {
        coords[0].first += 1;
        coords[0].second -= 1;
        coords[2].first += 1;
        coords[2].second += 1;
        coords[3].second += 2;
    }
    rotation = (rotation - 1 + 4) % 4;
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
    if (rotation == 0) {
        coords[0].first += 2;
        coords[1].first += 1;
        coords[1].second += 1;
        coords[3].first -= 1;
        coords[3].second += 1;
    } else if (rotation == 1) {
        coords[0].second += 2;
        coords[1].first -= 1;
        coords[1].second += 1;
        coords[3].first -= 1;
        coords[3].second -= 1;
    } else if (rotation == 2) {
        coords[0].first -= 2;
        coords[1].first -= 1;
        coords[1].second -= 1;
        coords[3].first += 1;
        coords[3].second -= 1;
    } else {
        coords[0].second -= 2;
        coords[1].first += 1;
        coords[1].second -= 1;
        coords[3].first += 1;
        coords[3].second += 1;
    }
    rotation = (rotation + 1) % 4;
}

void ZBlock::rotateccw() {
    if (rotation == 0) {
        coords[0].second += 2;
        coords[1].first -= 1;
        coords[1].second += 1;
        coords[3].first -= 1;
        coords[3].second -= 1;
    } else if (rotation == 1) {
        coords[0].first -= 2;
        coords[1].first -= 1;
        coords[1].second -= 1;
        coords[3].first += 1;
        coords[3].second -= 1;
    } else if (rotation == 2) {
        coords[0].second -= 2;
        coords[1].first += 1;
        coords[1].second -= 1;
        coords[3].first += 1;
        coords[3].second += 1;
    } else {
        coords[0].first += 2;
        coords[1].first += 1;
        coords[1].second += 1;
        coords[3].first -= 1;
        coords[3].second += 1;
    }
    rotation = (rotation - 1 + 4) % 4;
}

char ZBlock::getType() const { return 'Z'; }

// TBLOCK

TBlock::TBlock(int generatedLevel, bool heavy): Block{generatedLevel, heavy} {
    coords.emplace_back(1, 0);
    coords.emplace_back(0, 1);
    coords.emplace_back(1, 1);
    coords.emplace_back(2, 1);
    displayBlock = {{' ', 'T', ' ', ' '}, {'T', 'T', 'T', ' '}};
}

void TBlock::rotatecw() {
    if (rotation == 0) {
        coords[0].first += 1;
        coords[0].second += 1;
        coords[1].first += 1;
        coords[1].second -= 1;
        coords[3].first -= 1;
        coords[3].second += 1;
    } else if (rotation == 1) {
        coords[0].first -= 1;
        coords[0].second += 1;
        coords[1].first += 1;
        coords[1].second += 1;
        coords[3].first -= 1;
        coords[3].second -= 1;
    } else if (rotation == 2) {
        coords[0].first -= 1;
        coords[0].second -= 1;
        coords[1].first -= 1;
        coords[1].second += 1;
        coords[3].first += 1;
        coords[3].second -= 1;
    } else {
        coords[0].first += 1;
        coords[0].second -= 1;
        coords[1].first -= 1;
        coords[1].second -= 1;
        coords[3].first += 1;
        coords[3].second += 1;
    }
    rotation = (rotation + 1) % 4;
}

void TBlock::rotateccw() {
    if (rotation == 0) {
        coords[0].first -= 1;
        coords[0].second += 1;
        coords[1].first += 1;
        coords[1].second += 1;
        coords[3].first -= 1;
        coords[3].second -= 1;
    } else if (rotation == 1) {
        coords[0].first -= 1;
        coords[0].second -= 1;
        coords[1].first -= 1;
        coords[1].second += 1;
        coords[3].first += 1;
        coords[3].second -= 1;
    } else if (rotation == 2) {
        coords[0].first += 1;
        coords[0].second -= 1;
        coords[1].first -= 1;
        coords[1].second -= 1;
        coords[3].first += 1;
        coords[3].second += 1;
    } else {
        coords[0].first += 1;
        coords[0].second += 1;
        coords[1].first += 1;
        coords[1].second -= 1;
        coords[3].first -= 1;
        coords[3].second += 1;
    }
    rotation = (rotation - 1 + 4) % 4;
}

char TBlock::getType() const { return 'T'; }

// ASTERIKBLOCK

AsterikBlock::AsterikBlock(int generatedLevel, bool heavy): Block{generatedLevel, heavy} {
    coords.emplace_back(5, 2);
}

void AsterikBlock::rotatecw() {}
void AsterikBlock::rotateccw() {}

char AsterikBlock::getType() const { return '*'; }
