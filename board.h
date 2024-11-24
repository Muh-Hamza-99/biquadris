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
    int score, highScore;
    string name;
    vector<vector<Cell>> grid;
    vector<shared_ptr<Block>> blocks;
    shared_ptr<Block> currentBlock;
    shared_ptr<Block> nextBlock;
    shared_ptr<Level> level;
    public:
        Board(int score = 0, int highScore = 0, string name = "Player");
        Cell getCell(int x, int y) const;
        void reset();
        string getName() const;
        int getWidth() const;
        int getHeight() const;
        int getScore() const;
        int getHighScore() const;
        void setName(const string &name);
        void setScore(int score);
        void setHighScore(int highScore);
};

#endif
