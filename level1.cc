#include "level1.h"
#include "block.h"
#include <cstdlib>
using namespace std;

Level1::Level1(string file): Level{file} {
    pool = {'S', 'Z', 'T', 'T', 'I', 'I', 'J', 'J', 'L', 'L', 'O', 'O'};
}

shared_ptr<Block> Level1::generateBlock() {
    int randomChar = pool[rand() % pool.size()];
    shared_ptr<Block> newBlock;
    if (randomChar == 'I') {
        newBlock = make_shared<IBlock>(1);
    } else if (randomChar == 'J') {
        newBlock = make_shared<JBlock>(1);
    } else if (randomChar == 'L') {
        newBlock = make_shared<LBlock>(1);
    } else if (randomChar == 'O') {
        newBlock = make_shared<OBlock>(1);
    } else if (randomChar == 'S') {
         newBlock = make_shared<SBlock>(1);
    } else if (randomChar == 'Z') {
        newBlock = make_shared<ZBlock>(1);
    } else if (randomChar == 'T') {
        newBlock = make_shared<TBlock>(1);
    }
    return newBlock;
}

int Level1::getLevel() const { return 1; }
