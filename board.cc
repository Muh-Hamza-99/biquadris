#include "board.h"
#include <vector>
#include <string>
using namespace std;

Board::Board(shared_ptr<Level> currentLevel, string name): currentLevel{currentLevel}, name{name} {
    // Prepopulating the grid with cells
    for (int y = 0; y < height; ++y) {
        vector<Cell> row;
        grid.emplace_back(row);
        for (int x = 0; x < width; ++x) {
            Cell c { x, y };
            grid[y].emplace_back(c);
        }
    }
    currentBlock = currentLevel->generateBlock();
    nextBlock = currentLevel->generateBlock();

    vector<pair<int, int>> currentBlockCoords = currentBlock->getCoords();
    for (const pair<int, int> &coord : currentBlockCoords) {
        grid[coord.second][coord.first].setOccupied(true);
        grid[coord.second][coord.first].setContent(currentBlock->getType());
    }
}

void Board::reset() {
    grid.clear();
    blocks.clear();
    score = 0;
    over = false;
    for (int y = 0; y < height; ++y) {
        vector<Cell> row;
        grid.emplace_back(row);
        for (int x = 0; x < width; ++x) {
            Cell c { x, y };
            grid[y].emplace_back(c);
        }
    }
    currentLevel->resetLevel();
    currentBlock = currentLevel->generateBlock();
    nextBlock = currentLevel->generateBlock();

    vector<pair<int, int>> currentBlockCoords = currentBlock->getCoords();
    for (const pair<int, int> &coord : currentBlockCoords) {
        grid[coord.second][coord.first].setOccupied(true);
        grid[coord.second][coord.first].setContent(currentBlock->getType());
    }
}

void Board::endTurn() {
    blocks.emplace_back(currentBlock);
    currentBlock = nextBlock;
    nextBlock = currentLevel->generateBlock();

    vector<pair<int, int>> currentBlockCoords = currentBlock->getCoords();
    // Check if block can be placed in top-left corner
    for (const pair<int, int> &coord : currentBlockCoords) {
        if (grid[coord.second][coord.first].getOccupied()) {
            over = true;
            return;
        }
    }
    for (const pair<int, int> &coord : currentBlockCoords) {
        grid[coord.second][coord.first].setOccupied(true);
        grid[coord.second][coord.first].setContent(currentBlock->getType());
    }
}

bool Board::currentBlockWithinBounds() {
    for (const pair<int, int> &coord : currentBlock->getCoords()) {
        if (coord.first < 0 || coord.first > width - 1 || coord.second < 0 || coord.second > height - 1) return false;
    }
    return true;
}

bool Board::currentBlockColliding() {
    for (const pair<int, int> &coord : currentBlock->getCoords()) {
        if (grid[coord.second][coord.first].getOccupied()) return true;
    }
    return false;
}

void Board::clearFullRows() {
    int cleared = 0;
    for (int y = 0; y < height; ++y) {
        bool full = true;
        for (int x = 0 ; x < width; ++x) {
            if (!grid[y][x].getOccupied()) {
                full = false;
                break;
            }
        }

        if (!full) continue;
        // Clearing full row
        for (int x = 0; x < width; ++x) {
            grid[y][x].setOccupied(false);
            grid[y][x].setContent('.');
        }
        ++cleared;

        // Shifting previous rows down one row
        for (int i = y; i > 0; --i) {
            for (int j = 0; j < width; ++j) {
                grid[i][j].setContent(grid[i - 1][j].getContent());
                grid[i][j].setOccupied(grid[i - 1][j].getOccupied());
            }
        }

        // Clearing top row
        for (int i = 0; i < width; ++i) {
            grid[0][i].setOccupied(false);
            grid[0][i].setContent('.');
        }

        --y;
    }

    if (cleared > 0) {
        score += ((currentLevel->getLevel() + cleared) * (currentLevel->getLevel() + cleared));
    }
}

Cell Board::getCell(int x, int y) const { return grid.at(y).at(x); }
string Board::getName() const { return name; }
int Board::getWidth() const { return width; }
int Board::getHeight() const { return height; }
int Board::getScore() const { return score; }
int Board::getHighScore() const { return highScore; }
bool Board::isOver() const { return over; }
shared_ptr<Level> Board::getCurrentLevel() const { return currentLevel; }
shared_ptr<Block> Board::getCurrentBlock() const { return currentBlock; }
shared_ptr<Block> Board::getNextBlock() const { return nextBlock; }
void Board::setName(const string &name) { this->name = name; }
void Board::setScore(int score) { this->score = score; }
void Board::setHighScore(int highScore) { this->highScore = highScore; }
void Board::setCell(int x, int y, bool occupied, char content) {
    grid[y][x].setOccupied(occupied);
    grid[y][x].setContent(content);
}
void Board::setCurrentLevel(shared_ptr<Level> currentLevel) { this->currentLevel = currentLevel; }
