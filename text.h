#ifndef _TEXT_H_
#define _TEXT_H_

#include "observer.h"
#include "board.h"
#include "game.h"
#include <memory>

class Text : public Observer {
    shared_ptr<Game> subject;
    public:
        Text(shared_ptr<Game> subject);
        void notify() override;
};

#endif
