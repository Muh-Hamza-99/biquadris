#include <iostream>
#include <string>
#include <memory>
#include "board.h"
#include "game.h"
#include "text.h"
using namespace std;

int main() {
    cout << "-------------------------------------" << endl;
    cout << "              BIQUADRIS              " << endl;
    cout << "-------------------------------------" << endl;

    string name1, name2;
    cout << "Enter player 1 name: ";
    cin >> name1;
    cout << "Enter player 2 name: ";
    cin >> name2;

    shared_ptr<Board> board1 { new Board() };
    shared_ptr<Board> board2 { new Board() };
    shared_ptr<Game> game { new Game(board1, board2) };
    shared_ptr<Text> textObserver { new Text(game) };
    game->attach(textObserver);

    game->notifyObservers();
}