#include <iostream>
#include <string>
#include <memory>
#include "board.h"
#include "game.h"
#include "text.h"
using namespace std;

int main(int argc, char* argv[]) {
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

    game->render();

    while (true) {
        string command;
        cin >> command;

        if (command == "left") {
            game->render();
        } else if (command == "right") {
            game->render();
        } else if (command == "down") {
            game->render();
        } else if (command == "clockwise") {
            game->render();
        } else if (command == "counterclockwise") {
            game->render();
        } else if (command == "drop") {
            game->render();            
        } else if (command == "levelup") {
            cout << "Game level increased to X" << endl;
        } else if (command == "leveldown") {
            cout << "Game level increased to X" << endl;
        } else if (command == "random") {

        } else if (command == "norandom") {

        } else if (command == "random") {

        } else if (command == "sequence") {

        } else if (command == "restart") {
            
        } else if (command == "quit") {
            break;
        } else {
            cout << "Invalid command. Please input a valid command.";
        }
    }
}