#ifndef _GAME_H_
#define _GAME_H_

#include <memory>
#include <string>
#include "board.h"
#include "score.h"
#include "commandinterpreter.h"
#include "observer.h"
#include "textobserver.h"
#include "graphicsobserver.h"

using namespace std;

class Game : public Subject {
private:
    // private fields
    unique_ptr<Board> board1;
    unique_ptr<Board> board2;
    unique_ptr<Score> score;
    unique_ptr<CommandInterpreter> commandInterpreter;
    unique_ptr<TextObserver> textObserver;
    unique_ptr<GraphicsObserver> graphicsObserver;
    bool player1Turn;

public:
    // constructor and destructor
    Game();
    ~Game();

    // public methods
    void startGame();
    void restartGame();
    Bool checkPlayer1Turn();
    void notifyObservers();
};

#endif
