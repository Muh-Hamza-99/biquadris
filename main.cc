#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include "board.h"
#include "game.h"
#include "level.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include "text.h"
using namespace std;

const int MIN_LEVEL = 0;
const int MAX_LEVEL = 4;

int main(int argc, char* argv[]) {
    bool graphics = false;
    int startLevel = 0;
    string scriptFile1 = "sequence1.txt";
    string scriptFile2 = "sequence2.txt";
    for (int i = 1; i < argc; ++i) {
        string arg { argv[i] };
        if (arg == "-text") {
            graphics = true;
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
            startLevel = level;
        } else if (arg == "-seed") {
            ++i;
            string arg2 { argv[i] };
            istringstream iss { arg2 };
            int seed;
            iss >> seed;
            // Set seed
        } else if (arg == "-scriptfile1") {
            ++i;
            string arg2 { argv[i] };
            scriptFile1 = arg2;
        } else if (arg == "-scriptfile2") {
            ++i;
            string arg2 { argv[i] };
            scriptFile2 = arg2;
        }
    }
    
    shared_ptr<Level> board1Level;
    shared_ptr<Level> board2Level;
    if (startLevel == 0) {
        board1Level = make_shared<Level0>(scriptFile1);
        board2Level = make_shared<Level0>(scriptFile2);
    } else if (startLevel == 1) {
        board1Level = make_shared<Level1>(scriptFile1);
        board2Level = make_shared<Level1>(scriptFile2);
    } else if (startLevel == 2) {
        board1Level = make_shared<Level2>(scriptFile1);
        board2Level = make_shared<Level2>(scriptFile2);
    } else if (startLevel == 3) {
        board1Level = make_shared<Level3>(scriptFile1);
        board2Level = make_shared<Level3>(scriptFile2);
    } else if (startLevel == 4) {
        board1Level = make_shared<Level4>(scriptFile1);
        board2Level = make_shared<Level4>(scriptFile2);
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

    shared_ptr<Board> board1 { new Board(board1Level, name1) };
    shared_ptr<Board> board2 { new Board(board2Level, name2) };
    shared_ptr<Game> game { new Game(board1, board2) };
    shared_ptr<Text> textObserver { new Text(game) };
    game->attach(textObserver);
    if (graphics) {
        // Add graphics observer
    }
    game->render();

    while (true) {
        if (game->checkPlayer1Turn()) {
            cout << name1 << "'s turn: ";
        } else {
            cout << name2 << "'s turn: ";
        }

        string command;
        cin >> command;

        if (command == "left") {
            game->left();
            game->render();
        } else if (command == "right") {
            game->right();
            game->render();
        } else if (command == "down") {
            game->down();
            game->render();
        } else if (command == "clockwise") {
            game->rotatecw();
            game->render();
        } else if (command == "counterclockwise") {
            game->rotateccw();
            game->render();
        } else if (command == "drop") {
            game->drop();
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