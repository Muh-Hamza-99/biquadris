#ifndef _LEVELTHREE_H_
#define _LEVELTHREE_H_

#include "level.h"

class Level3 : public Level {
    string file;
    vector<char> blocks;
    vector<char> pool;
    bool randomize;
    int currentBlockIndex;
    public:
        Level3(string file, bool randomize = false, int currentBlockIndex = 0);
        shared_ptr<Block> generateBlock() override;
        void resetLevel() override;
        int getLevel() const override;
        void setRandom(bool random, const string& file); 
};

#endif
