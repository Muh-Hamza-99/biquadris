#ifndef _GRAPHIC_H_
#define _GRAPHIC_H_

#include "observer.h"
#include "game.h"
#include "xwindow.h"
#include <memory>

class Graphic : public Observer {
private:
    std::shared_ptr<Game> subject;  
    Xwindow win;                    
    const int cellSize = 20;        

    // Helper methods
    void drawBoard(const Board& board, int xOffset);
    void drawBlock(const std::vector<std::vector<char>>& block, int xOffset, int yOffset, int width);

public:
    Graphic(std::shared_ptr<Game> subject);
    void notify() override;
};

#endif
