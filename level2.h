#ifndef _LEVELTWO_H_
#define _LEVELTWO_H_

#include "level.h"

class Level2 : public Level {
    vector<char> pool;
    public:
        Level2();
        shared_ptr<Block> generateBlock() override;
        int getLevel() const override;        
};

#endif