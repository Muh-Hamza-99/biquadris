#include <iostream>
#include "text.h"

Text::Text(shared_ptr<Game> subject): subject{subject} {}

void Text::notify() {
    string space = "          ";

    cout << "Level:    1";
    cout << space;
    cout << "Level:    1" << endl;

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
}
