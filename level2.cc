#include "level2.h"
#include "block.h"
#include <cstdlib>
using namespace std;

Level2::Level2(string file): Level{file} {
    pool = {'S', 'Z', 'T', 'I', 'J', 'L', 'O'};
}

shared_ptr<Block> Level2::generateBlock() {
    int randomChar = pool[rand() % pool.size()];
    shared_ptr<Block> newBlock;
    if (randomChar == 'I') {
        newBlock = make_shared<IBlock>(2);
    } else if (randomChar == 'J') {
        newBlock = make_shared<JBlock>(2);
    } else if (randomChar == 'L') {
        newBlock = make_shared<LBlock>(2);
    } else if (randomChar == 'O') {
        newBlock = make_shared<OBlock>(2);
    } else if (randomChar == 'S') {
         newBlock = make_shared<SBlock>(2);
    } else if (randomChar == 'Z') {
        newBlock = make_shared<ZBlock>(2);
    } else if (randomChar == 'T') {
        newBlock = make_shared<TBlock>(2);
    }
    return newBlock;
}

int Level2::getLevel() const { return 2; }
