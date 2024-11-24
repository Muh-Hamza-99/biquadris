#ifndef _LEVEL_H_
#define _LEVEL_H_

#include "block.h"
#include <memory>
#include <string>
using namespace std;

class Level {
    string file;
    public:
        Level(string file);
        virtual void readFile();
        virtual shared_ptr<Block> generateBlock() = 0;
        virtual int getLevel() const = 0;
        virtual ~Level();
};

#endif
