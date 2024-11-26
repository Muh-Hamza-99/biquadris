#include "level3.h"
#include "block.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

Level3::Level3(string file, bool randomize, int currentBlockIndex): Level{file}, randomize{randomize}, currentBlockIndex{currentBlockIndex} {
    ifstream fs { file };
    if (!fs) {
        cerr << "Error opening file " << file << endl;
        exit(1);
    }
    char block;
    while (fs >> block) { blocks.emplace_back(block); }
    pool = {'S', 'S', 'Z', 'Z', 'T', 'I', 'J', 'L', 'O'};
}

shared_ptr<Block> Level3::generateBlock() {
    char randomChar = pool[rand() % pool.size()];
    shared_ptr<Block> newBlock;
    if (randomChar == 'I') {
        newBlock = make_shared<IBlock>(3, true);
    } else if (randomChar == 'J') {
        newBlock = make_shared<JBlock>(3, true);
    } else if (randomChar == 'L') {
        newBlock = make_shared<LBlock>(3, true);
    } else if (randomChar == 'O') {
        newBlock = make_shared<OBlock>(3, true);
    } else if (randomChar == 'S') {
         newBlock = make_shared<SBlock>(3, true);
    } else if (randomChar == 'Z') {
        newBlock = make_shared<ZBlock>(3, true);
    } else if (randomChar == 'T') {
        newBlock = make_shared<TBlock>(3, true);
    }
    return newBlock;
}

void Level3::resetLevel() { currentBlockIndex = 0; }

int Level3::getLevel() const { return 3; }

void Level3::setRandom() {
    randomize = random; 
    if (random == false) {
        blocks.clear(); // reset blocks
        ifstream infile {file}; 
        if (!infile) {
            cout << "Error: Could not open sequence file." << endl;
        }

        char block;
        while (infile >> block) {
            blocks.push_back(block);
        }
        currentBlockIndex = 0;
    }
}
