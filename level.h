#ifndef _LEVEL_H_
#define _LEVEL_H_

#include "block.h"
#include <memory>
#include <string>
using namespace std;

class Level {
    string file;
    public:
        Level(string &file);
        string getFile() const;
        virtual shared_ptr<Block> generateBlock() = 0;
        virtual void resetLevel() = 0;
        virtual int getLevel() const = 0;
        virtual ~Level();
};

#endif
