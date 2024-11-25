#ifndef _GAME_H_
#define _GAME_H_

#include <memory>
#include <string>
#include "board.h"
#include "score.h"
#include "commandinterpreter.h"
#include "observer.h"

using namespace std;

class Game : public Subject {
    shared_ptr<Board> board1;
    shared_ptr<Board> board2;
    shared_ptr<CommandInterpreter> commandInterpreter;
    bool player1Turn = true;
    public:
        Game(shared_ptr<Board> board1, shared_ptr<Board> board2);
        void render();
        void left();
        void right();
        void down();
        void rotatecw();
        void rotateccw();
        void drop();
        void levelUp();
        void levelDown();
        shared_ptr<Board> getBoard1() const;
        shared_ptr<Board> getBoard2() const;
        bool checkPlayer1Turn() const;
        void startGame();
        void restart();
};

#endif
