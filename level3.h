#ifndef _LEVELTHREE_H_
#define _LEVELTHREE_H_

#include "level.h"

class Level3 : public Level {
    public:
        shared_ptr<Block> generateBlock() override;
        int getLevel() const override;
};

#endif