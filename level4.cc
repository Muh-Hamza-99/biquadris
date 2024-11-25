#include "level4.h"
#include "block.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

Level4::Level4(string file, bool randomize, int currentBlockIndex): Level{file}, randomize{randomize}, currentBlockIndex{currentBlockIndex} {
    ifstream fs { file };
    if (!fs) {
        cerr << "Error opening file " << file << endl;
        exit(1);
    }
    char block;
    while (fs >> block) { blocks.emplace_back(block); }
    pool = {'S', 'S', 'Z', 'Z', 'T', 'I', 'J', 'L', 'O'};
}

shared_ptr<Block> Level4::generateBlock() {
    if (currentBlockIndex == static_cast<int>(blocks.size())) { currentBlockIndex = 0; }
    char blockChar = randomize ? pool[rand() % pool.size()] : blocks[currentBlockIndex];
    shared_ptr<Block> newBlock;
    if (blockChar == 'I') {
        newBlock = make_shared<IBlock>(4, true);
    } else if (blockChar == 'J') {
        newBlock = make_shared<JBlock>(4, true);
    } else if (blockChar == 'L') {
        newBlock = make_shared<LBlock>(4, true);
    } else if (blockChar == 'O') {
        newBlock = make_shared<OBlock>(4, true);
    } else if (blockChar == 'S') {
         newBlock = make_shared<SBlock>(4, true);
    } else if (blockChar == 'Z') {
        newBlock = make_shared<ZBlock>(4, true);
    } else if (blockChar == 'T') {
        newBlock = make_shared<TBlock>(4, true);
    }
    return newBlock;
}

void Level4::resetLevel() { currentBlockIndex = 0; }

int Level4::getLevel() const { return 4; }
