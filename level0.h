#ifndef _LEVELZERO_H_
#define _LEVELZERO_H_

#include "level.h"
#include <string>
using namespace std;

class Level0 : public Level {
    string file;
    vector<char> blocks;
    int currentBlockIndex; 
    public:
        Level0(string file, int currentBlockIndex = 0);
        shared_ptr<Block> generateBlock() override;
        void resetLevel() override;
        int getLevel() const override;
};

#endif
