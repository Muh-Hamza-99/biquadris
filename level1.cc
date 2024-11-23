#include "level1.h"
#include "block.h"
#include <cstdlib>
using namespace std;

Level1::Level1() {
    pool = {'S', 'Z', 'T', 'T', 'I', 'I', 'J', 'J', 'L', 'L', 'O', 'O'};
}

shared_ptr<Block> Level1::generateBlock() {
    int randomChar = pool[rand() % pool.size()];
    shared_ptr<Block> newBlock;
    if (randomChar == 'I') {
        newBlock = make_shared<IBlock>();
    } else if (randomChar == 'J') {
        newBlock = make_shared<JBlock>();
    } else if (randomChar == 'L') {
        newBlock = make_shared<LBlock>();
    } else if (randomChar == 'O') {
        newBlock = make_shared<OBlock>();
    } else if (randomChar == 'S') {
         newBlock = make_shared<SBlock>();
    } else if (randomChar == 'Z') {
        newBlock = make_shared<ZBlock>();
    } else if (randomChar == 'T') {
        newBlock = make_shared<TBlock>();
    }
    newBlock->init();
    return newBlock;
}

int Level1::getLevel() const { return 1; }
