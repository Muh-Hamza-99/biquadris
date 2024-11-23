#ifndef _LEVELFOUR_H_
#define _LEVELFOUR_H_

#include "level.h"

class Level4 : public Level {
    public:
        shared_ptr<Block> generateBlock() override;
        int getLevel() const override;
};

#endif