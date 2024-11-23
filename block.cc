#include "block.h"

// Helper functions

// Checks whether a set of coordinates is within a 11*18 boards grid
bool validMove(vector<pair<int, int>> coords) {
    for (auto coord : coords) {
        if (coord.first < 0 || coord.first > 10 || coord.second < 0 || coord.second > 17) return false;
    }
    return true;
}

// BLOCK

Block::Block(bool heavy, int rotation): heavy{heavy}, rotation{rotation} {}

Block::~Block() {}

void Block::left() {
    // Check if the block goes out of bounds
    vector<pair<int, int>> newCoords { coords };
    for (auto &coord : newCoords) { coord.first -= 1; }
    if (!validMove(newCoords)) return;
    coords = newCoords;
    if (heavy) down();
}

void Block::right() {
    // Check if the block goes out of bounds
    vector<pair<int, int>> newCoords { coords };
    for (auto &coord : newCoords) { coord.first += 1; }
    if (!validMove(newCoords)) return;
    coords = newCoords;
    if (heavy) down();
}

void Block::down() {

}

// IBLOCK

char IBlock::getType() const { return 'I'; }

void IBlock::init() {
    coords.emplace_back(0, 1);
    coords.emplace_back(1, 1);
    coords.emplace_back(2, 1);
    coords.emplace_back(3, 1);
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
    if (!validMove(newCoords)) return;
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
    if (!validMove(newCoords)) return;
    coords = newCoords;
    rotation = (rotation - 1) % 4;
}

// JBLOCK

char JBlock::getType() const { return 'J'; }

void JBlock::init() {
    coords.emplace_back(0, 0);
    coords.emplace_back(0, 1);
    coords.emplace_back(1, 1);
    coords.emplace_back(2, 1);
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
    if (!validMove(newCoords)) return;
    coords = newCoords;
    rotation = (rotation + 1) % 4;
}

void JBlock::rotateccw() {
    vector<pair<int, int>> newCoords { coords };
    if (rotation == 0) {
        newCoords[0].second -= 2;
        newCoords[1].first -= 1;
        newCoords[1].second -= 1;
        newCoords[3].first += 1;
        newCoords[3].second += 1;
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
        newCoords[0].first -= 2;
        newCoords[1].first += 1;
        newCoords[1].second -= 1;
        newCoords[3].first -= 1;
        newCoords[3].second += 1;
    }
    if (!validMove(newCoords)) return;
    coords = newCoords;
    rotation = (rotation - 1) % 4;
}

// LBLOCK

char LBlock::getType() const { return 'L'; }

void LBlock::init() {
    coords.emplace_back(2, 0);
    coords.emplace_back(0, 1);
    coords.emplace_back(1, 1);
    coords.emplace_back(2, 1);
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
    if (!validMove(newCoords)) return;
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
    if (!validMove(newCoords)) return;
    coords = newCoords;
    rotation = (rotation - 1) % 4;
}

// OBLOCK

char OBlock::getType() const { return 'O'; }

void OBlock::init() {
    coords.emplace_back(0, 1);
    coords.emplace_back(0, 2);
    coords.emplace_back(1, 1);
    coords.emplace_back(1, 2);
}

void OBlock::rotatecw() {}

void OBlock::rotateccw() {}

// SBLOCK

char SBlock::getType() const { return 'S'; }

void SBlock::init() {
    coords.emplace_back(0, 1);
    coords.emplace_back(1, 1);
    coords.emplace_back(1, 0);
    coords.emplace_back(2, 0);
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
    if (!validMove(newCoords)) return;
    coords = newCoords;
    rotation = (rotation - 1) % 4;
}

// ZBLOCK

char ZBlock::getType() const { return 'Z'; }

void ZBlock::init() {
    coords.emplace_back(0, 0);
    coords.emplace_back(1, 0);
    coords.emplace_back(1, 1);
    coords.emplace_back(2, 1);
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
    if (!validMove(newCoords)) return;
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
    if (!validMove(newCoords)) return;
    coords = newCoords;
    rotation = (rotation - 1) % 4;
}

// TBLOCK

char TBlock::getType() const { return 'T'; }

void TBlock::init() {
    coords.emplace_back(1, 0);
    coords.emplace_back(0, 1);
    coords.emplace_back(1, 1);
    coords.emplace_back(2, 1);
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
    if (!validMove(newCoords)) return;
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
    if (!validMove(newCoords)) return;
    coords = newCoords;
    rotation = (rotation - 1) % 4;
}

// ASTERIKBLOCK

char AsterikBlock::getType() const { return '*'; }

void AsterikBlock::init() {
    coords.emplace_back(5, 2);
}

void AsterikBlock::rotatecw() {}

void AsterikBlock::rotateccw() {}
