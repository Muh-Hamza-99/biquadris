#ifndef _BOARD_H_
#define _BOARD_H_

#include "subject.h"
#include "cell.h"
#include <string>
#include <vector>
#include <memory>

class Board {
    vector<shared_ptr<vector<shared_ptr<Cell>>>> grid;
    string name;
};

#endif
