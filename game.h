#ifndef _GAME_H_
#define _GAME_H_

#include <memory>
#include <string>
#include "board.h"
#include "score.h"
#include "commandinterpreter.h"
#include "observer.h"
<<<<<<< Updated upstream
=======
#include "text.h"
#include "graphic.h"
>>>>>>> Stashed changes

using namespace std;

class Game : public Subject {
<<<<<<< Updated upstream
    shared_ptr<Board> board1;
    shared_ptr<Board> board2;
    shared_ptr<CommandInterpreter> commandInterpreter;
=======
private:
    // private fields
    unique_ptr<Board> board1;
    unique_ptr<Board> board2;
    unique_ptr<Score> score;
    unique_ptr<CommandInterpreter> commandInterpreter;
    unique_ptr<Text> textObserver;
    unique_ptr<Graphic> graphicsObserver;
>>>>>>> Stashed changes
    bool player1Turn;
    public:
        Game(shared_ptr<Board> board1, shared_ptr<Board> board2);
        void render();
        shared_ptr<Board> getBoard1() const;
        shared_ptr<Board> getBoard2() const;
        bool checkPlayer1Turn() const;
        void startGame();
        void restartGame();
};

#endif
