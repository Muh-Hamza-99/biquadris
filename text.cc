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

    cout << "-----------";
    cout << space;
    cout << "-----------" << endl;

    for (int i = 0; i < subject->getBoard1()->getHeight(); ++i) {
        for (int j = 0; j < subject->getBoard1()->getWidth(); ++j) {
            char c = subject->getBoard1()->getCell(i, j).getOccupied() ? '*' : ' '; 
            cout << c;
        }
        cout << space;
        for (int j = 0; j < subject->getBoard2()->getWidth(); ++j) {
            char c = subject->getBoard2()->getCell(i, j).getOccupied() ? '*' : ' ';;
            cout << c;
        }
        cout << endl;
    }

    cout << "-----------";
    cout << space;
    cout << "-----------" << endl;

    cout << "Next:      ";
    cout << space;
    cout << "Next:      " << endl;
}
