#ifndef _LEVELONE_H_
#define _LEVELONE_H_

#include "level.h"

class Level1 : public Level {
    vector<char> pool;
    public:
        Level1(string file);
        shared_ptr<Block> generateBlock() override;
        void resetLevel() override;
        int getLevel() const override;
};

#endif
