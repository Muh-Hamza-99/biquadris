#ifndef _BOARD_H_
#define _BOARD_H_

#include "subject.h"
#include "cell.h"
#include <string>
#include <vector>

class Board {
    int width, height;
    int score, highScore;
    string name;
    vector<vector<Cell>> grid;
    public:
        Board(int width = 11, int height = 18, int score = 0, int highScore = 0, string name = "Player");
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
