#ifndef _BOARD_H_
#define _BOARD_H_

#include "subject.h"
#include "cell.h"
#include "block.h"
#include "level.h"
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Board {
    int width = 11;
    int height = 18;
    int score = 0;
    int highScore = 0;
    bool over = false;
    string name;
    vector<vector<Cell>> grid;
    vector<shared_ptr<Block>> blocks;
    shared_ptr<Level> currentLevel;
    shared_ptr<Block> currentBlock;
    shared_ptr<Block> nextBlock;
    public:
        Board(shared_ptr<Level> currentLevel, string name = "Player");
        void reset();
        void endTurn();
        bool currentBlockWithinBounds();
        bool currentBlockColliding();
        void clearFullRows();
        Cell getCell(int x, int y) const;
        string getName() const;
        int getWidth() const;
        int getHeight() const;
        int getScore() const;
        int getHighScore() const;
        bool isOver() const;
        shared_ptr<Level> getCurrentLevel() const;
        shared_ptr<Block> getCurrentBlock() const;
        shared_ptr<Block> getNextBlock() const;
        void setName(const string &name);
        void setScore(int score);
        void setHighScore(int highScore);
        void setCell(int x, int y, bool occupied, char content = '.');
        void setCurrentLevel(shared_ptr<Level> currentLevel);
};

#endif
