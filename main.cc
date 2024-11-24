#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include "board.h"
#include "game.h"
#include "text.h"
using namespace std;

const int MIN_LEVEL = 0;
const int MAX_LEVEL = 4;

int main(int argc, char* argv[]) {
    shared_ptr<Board> board1 { new Board() };
    shared_ptr<Board> board2 { new Board() };
    shared_ptr<Game> game { new Game(board1, board2) };
    
    shared_ptr<Text> textObserver { new Text(game) };
    game->attach(textObserver);

    for (int i = 1; i < argc; ++i) {
        string arg { argv[i] };
        if (arg == "-text") {
            // 
        } else if (arg == "-startlevel") {
            ++i;
            string arg2 { argv[i] };
            istringstream iss { arg2 };
            int level;
            iss >> level;
            if (level < MIN_LEVEL || level > MAX_LEVEL) {
                cerr << "Invalid level. Please enter a level between " << MIN_LEVEL << " and " << MAX_LEVEL << endl;
                exit(1);
            }
            // Set level for both boards
        } else if (arg == "-seed") {
            ++i;
            string arg2 { argv[i] };
            istringstream iss { arg2 };
            int seed;
            iss >> seed;
            // Set seed
        } else if (arg == "-scriptfile1") {
            ++i;
            string scriptfile1 { argv[i] };
            // Set sequence file for board 1
        } else if (arg == "-scriptfile2") {
            ++i;
            string scriptfile2 { argv[i] };
            // Set sequence file for board 2
        }
    }

    cout << "-------------------------------------" << endl;
    cout << "              BIQUADRIS              " << endl;
    cout << "-------------------------------------" << endl;

    string name1, name2;
    cout << "Enter player 1 name: ";
    cin >> name1;
    cout << "Enter player 2 name: ";
    cin >> name2;
    cout << endl << endl;

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