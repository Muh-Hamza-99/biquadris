#ifndef _SCORE_H_
#define _SCORE_H_

class Score {
private:
    // private fields
    int currScore;
    int hiScore;

    // private methods
    int calcLineClearScore(int lines, int level);
    int calcBlockClearScore(int level);

public:
    // constructor
    Score();

    // public methods
    int getCurrScore();
    int getHiScore();
    void updateLineClearScore(int lines, int level);
    void updateBlockClearScore(int level);
    void checkUpdateHiScore();
    void clearScore();
};

#endif
