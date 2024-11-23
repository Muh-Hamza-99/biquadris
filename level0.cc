#include "level0.h"
#include "block.h"
#include <fstream>
#include <iostream>
using namespace std;

Level0::Level0(string file, int currentBlockIndex): file{file}, currentBlockIndex{currentBlockIndex} {
    ifstream fs { file };
    if (!fs) {
        cerr << "Error opening file " << file << endl;
        exit(1);
    }
    char block;
    while (fs >> block) { blocks.emplace_back(block); }
}

shared_ptr<Block> Level0::generateBlock() {
    if (currentBlockIndex == static_cast<int>(blocks.size())) { currentBlockIndex = 0; }
    char blockChar = blocks[currentBlockIndex];
    shared_ptr<Block> newBlock;
    if (blockChar == 'I') {
        newBlock = make_shared<IBlock>();
    } else if (blockChar == 'J') {
        newBlock = make_shared<JBlock>();
    } else if (blockChar == 'L') {
        newBlock = make_shared<LBlock>();
    } else if (blockChar == 'O') {
        newBlock = make_shared<OBlock>();
    } else if (blockChar == 'S') {
         newBlock = make_shared<SBlock>();
    } else if (blockChar == 'Z') {
        newBlock = make_shared<ZBlock>();
    } else if (blockChar == 'T') {
        newBlock = make_shared<TBlock>();
    } else {
        cerr << "Invalid block character: " << blockChar << " in " << file << endl;
        exit(1);
    }
    currentBlockIndex += 1;
    return newBlock;
}

int Level0::getLevel() const { return 0; }
