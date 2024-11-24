#include "level3.h"
#include "block.h"
#include <cstdlib>
using namespace std;

Level3::Level3(string file): Level{file} {
    pool = {'S', 'S', 'Z', 'Z', 'T', 'I', 'J', 'L', 'O'};
}

shared_ptr<Block> Level3::generateBlock() {
    int randomChar = pool[rand() % pool.size()];
    shared_ptr<Block> newBlock;
    if (randomChar == 'I') {
        newBlock = make_shared<IBlock>(true);
    } else if (randomChar == 'J') {
        newBlock = make_shared<JBlock>(true);
    } else if (randomChar == 'L') {
        newBlock = make_shared<LBlock>(true);
    } else if (randomChar == 'O') {
        newBlock = make_shared<OBlock>(true);
    } else if (randomChar == 'S') {
         newBlock = make_shared<SBlock>(true);
    } else if (randomChar == 'Z') {
        newBlock = make_shared<ZBlock>(true);
    } else if (randomChar == 'T') {
        newBlock = make_shared<TBlock>(true);
    }
    return newBlock;
}

int Level3::getLevel() const { return 3; }
