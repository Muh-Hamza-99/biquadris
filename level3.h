#ifndef _LEVELTHREE_H_
#define _LEVELTHREE_H_

#include "level.h"

class Level3 : public Level {
    vector<char> pool;
    public:
        Level3(string file);
        shared_ptr<Block> generateBlock() override;
        int getLevel() const override;
};

#endif