#ifndef _GAME_H_
#define _GAME_H_

#include "subject.h"
#include "board.h"
#include <memory>
using namespace std;

class Game : public Subject {
    shared_ptr<Board> board1;
    shared_ptr<Board> board2;
};

#endif