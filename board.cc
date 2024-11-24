#include "board.h"
#include <vector>
#include <string>
using namespace std;

Board::Board(shared_ptr<Level> currentLevel, string name): currentLevel{currentLevel}, name{name} {
    // Prepopulating the grid with cells
    for (int i = 0; i < height; ++i) {
        vector<Cell> row;
        grid.emplace_back(row);
        for (int j = 0; j < width; ++j) {
            Cell c { i, j };
            grid.at(i).emplace_back(c);
        }
    }
    currentBlock = currentLevel->generateBlock();
    nextBlock = currentLevel->generateBlock();
}

void Board::reset() {}

Cell Board::getCell(int x, int y) const { return grid.at(x).at(y); }
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