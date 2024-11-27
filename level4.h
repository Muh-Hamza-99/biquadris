#ifndef _LEVELFOUR_H_
#define _LEVELFOUR_H_

#include "level.h"

class Level4 : public Level {
    string file;
    vector<char> blocks;
    vector<char> pool;
    bool randomize;
    int currentBlockIndex;
    public:
        Level4(string file, bool randomize = true, int currentBlockIndex = 0);
        shared_ptr<Block> generateBlock() override;
        void resetLevel() override;
        int getLevel() const override;
        void setRandom(bool random, const string& file); 
};

#endif
