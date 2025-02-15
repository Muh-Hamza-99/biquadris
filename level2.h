#ifndef _LEVELTWO_H_
#define _LEVELTWO_H_

#include "level.h"

class Level2 : public Level {
    vector<char> pool;
    public:
        Level2(string file);
        shared_ptr<Block> generateBlock() override;
        void resetLevel() override;
        int getLevel() const override;        
};

#endif
