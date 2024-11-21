#ifndef _TEXT_H_
#define _TEXT_H_

#include "observer.h"
#include "board.h"

class Text : public Observer {
    public:
        void notify() override;
};

#endif
