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
            srand(seed);
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
        int multiplier = 1;
        cin >> command;
        if (command.substr(0, 1) >= "0" && command.substr(0, 1) <= "9") {
            istringstream iss { command };
            iss >> multiplier;
            command = command.substr(1);
        }

        if (command.substr(0, 3) == "lef") { // left
            game->left(multiplier);
            game->render();
        } else if (command.substr(0, 2) == "ri") { // right
            game->right(multiplier);
            game->render();
        } else if (command.substr(0, 3) == "dow") { // down
            game->down(multiplier);
            game->render();
        } else if (command.substr(0, 3) == "clo") { // clockwise
            game->rotatecw(multiplier);
            game->render();
        } else if (command.substr(0, 3) == "cou") { // counterclockwise
            game->rotateccw(multiplier);
            game->render();
        } else if (command.substr(0, 3) == "dro") { // drop
            game->drop();
            game->render();            
        } else if (command.substr(0, 6) == "levelu") { // levelup
            game->levelUp(multiplier);
            game->render();
        } else if (command.substr(0, 6) == "leveld") { // leveldown
            game->levelDown(multiplier);
            game->render();
        } else if (command == "norandom") {
            string file; 
            cin >> file; 
            try {
                game->setRandom(false, file); 
                cout << "Switched to non-random mode with file: " << filename << endl; 
            } catch (const runtime_error &e) {
                cerr << e.what() << endl; // handle errors with the file
            }
            game->render(); 
        } else if (command == "random") {
            game->setRandom(true); 
            cout << "Switched to random mode." << endl;
            game->render(); 
        } else if (command == "sequence") {
            string file; 
            cin >> file; 
            ifstream infile { file }; 
            if (!infile) {
                cerr << "Can not open sequence file: " << filename << endl; 
                
            }
        } else if (command == "restart") {
            game->restart();
            game->render();
        } else if (command == "quit") {
            break;
        } else {
            cout << "Invalid command. Please input a valid command." << endl;
        }

        if (board1->isOver() || board2->isOver()) {
            string board1Message = board1->isOver() ? " loses!" : " wins!";
            string board2Message = board2->isOver() ? " loses!" : " wins!";
            
            cout << board1->getName() << board1Message << " Score: " << board1->getScore() << " High Score: " << board1->getHighScore() << endl;
            cout << board2->getName() << board2Message << " Score: " << board2->getScore() << " High Score: " << board2->getHighScore() << endl << endl;

            cout << "Game restarted!" << endl;
            game->restart();
            game->render();
        }
    }
}