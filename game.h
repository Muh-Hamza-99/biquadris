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
        void left(int repetitions = 1);
        void right(int repetitions = 1);
        void down(int repetitions = 1);
        void rotatecw(int repetitions);
        void rotateccw(int repetitions);
        void drop();
        void levelUp(int repetitions = 1);
        void levelDown(int repetitions = 1);
        shared_ptr<Board> getBoard1() const;
        shared_ptr<Board> getBoard2() const;
        bool checkPlayer1Turn() const;
        void startGame();
        void restart(); 
        void setRandom(const string &file); 
};

#endif
