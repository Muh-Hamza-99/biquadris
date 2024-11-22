#ifndef _SUBJECT_H_
#define _SUBJECT_H_

#include <vector>
#include <memory>
#include "observer.h"
using namespace std;

class Subject {
    vector<shared_ptr<Observer>> observers;
    public:
        void attach(shared_ptr<Observer> o);
        void detach(shared_ptr<Observer> o);
        void notifyObservers();
        virtual ~Subject() = 0;
};

#endif
