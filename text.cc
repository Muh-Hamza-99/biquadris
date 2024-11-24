#include <iostream>
#include "text.h"

Text::Text(shared_ptr<Game> subject): subject{subject} {}

void Text::notify() {
    string space = "          ";

    cout << "Level:    " << subject->getBoard1()->getCurrentLevel()->getLevel();
    cout << space;
    cout << "Level:    " << subject->getBoard2()->getCurrentLevel()->getLevel() << endl;

    cout << "Score:    " << subject->getBoard1()->getScore();
    cout << space;
    cout << "Score:    " << subject->getBoard2()->getScore() << endl;

    for (int i = 0; i < subject->getBoard1()->getWidth(); ++i) cout << '-';
    cout << space;
    for (int i = 0; i < subject->getBoard2()->getWidth(); ++i) cout << '-';
    cout << endl;

    for (int i = 0; i < subject->getBoard1()->getHeight(); ++i) {
        for (int j = 0; j < subject->getBoard1()->getWidth(); ++j) {
            cout << subject->getBoard1()->getCell(i, j).getContent();
        }
        cout << space;
        for (int j = 0; j < subject->getBoard2()->getWidth(); ++j) {
            cout << subject->getBoard2()->getCell(i, j).getContent();
        }
        cout << endl;
    }

    for (int i = 0; i < subject->getBoard1()->getWidth(); ++i) cout << '-';
    cout << space;
    for (int i = 0; i < subject->getBoard2()->getWidth(); ++i) cout << '-';
    cout << endl;

    cout << "Next:      ";
    cout << space;
    cout << "Next:      " << endl;

    vector<vector<char>> nextBlock1 = subject->getBoard1()->getNextBlock()->getDisplayBlock();
    vector<vector<char>> nextBlock2 = subject->getBoard2()->getNextBlock()->getDisplayBlock();

    for (int i = 0; i < static_cast<int>(nextBlock1.size()); ++i) {
        for (int j = 0; j < static_cast<int>(nextBlock1[i].size()); ++j) { cout << nextBlock1[i][j]; }
        for (int j = 0; j < subject->getBoard1()->getWidth() - static_cast<int>(nextBlock1[i].size()); ++j) { cout << ' '; }
        cout << space;
        for (int j = 0; j < static_cast<int>(nextBlock2[i].size()); ++j) { cout << nextBlock2[i][j]; }
        for (int j = 0; j < subject->getBoard2()->getWidth() - static_cast<int>(nextBlock2[i].size()); ++j) { cout << ' '; }
        cout << endl;
    }
}
