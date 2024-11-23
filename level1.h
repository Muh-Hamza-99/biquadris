#ifndef _LEVELONE_H_
#define _LEVELONE_H_

#include "level.h"

class Level1 : public Level {
    public:
        shared_ptr<Block> generateBlock() override;
        int getLevel() const override;
};

#endif