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

void Board::reset() {}

Cell Board::getCell(int x, int y) const { return grid.at(y).at(x); }
string Board::getName() const { return name; }
int Board::getWidth() const { return width; }
int Board::getHeight() const { return height; }
int Board::getScore() const { return score; }
int Board::getHighScore() const { return highScore; }
shared_ptr<Level> Board::getCurrentLevel() const { return currentLevel; }
shared_ptr<Block> Board::getCurrentBlock() const { return currentBlock; }
shared_ptr<Block> Board::getNextBlock() const { return nextBlock; }
void Board::setName(const string &name) { this->name = name; }
void Board::setScore(int score) { this->score = score; }
void Board::setHighScore(int highScore) { this->highScore = highScore; }