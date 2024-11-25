#include "score.h"

// constructor implementation
Score::Score() : currScore{0}, hiScore{0} {}


// private methods implementation

// calculates points to be added when lines are cleared
int Score::calcLineClearScore(int lines, int level) {
    return (lines + level) * (lines + level);
}

// calculates points to be added when blocks are cleared
int Score::calcBlockClearScore(int level) {
    return (level + 1) * (level + 1);
}

// updates the high score if current score exceeds high score
void Score::checkUpdateHiScore() {
    if (currScore > hiScore) {
        hiScore = currScore;
    }
}


// public methods implementation

int Score::getCurrScore() {
    return currScore;
}

int Score::getHiScore() {
    return hiScore;
}

// updates current score after a line clear
void Score::updateLineClearScore(int lines, int level) {
    currScore += calcLineClearScore(lines, level);
    checkUpdateHiScore();
}

// updates current score after a block clear
void Score::updateBlockClearScore(int level) {
    currScore += calcBlockClearScore(level);
    checkUpdateHiScore();
}

// resets current and high scores
void Score::clearScore() {
    currScore = 0;
    hiScore = 0;
}

