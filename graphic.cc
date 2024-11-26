#include "graphic.h"
#include <vector>

Graphic::Graphic(std::shared_ptr<Game> subject)
    : subject{subject}, win{800, 600} { 
}

void Graphic::notify() {
    win.clear(); 

    // Draw Player 1's Board
    drawBoard(*subject->getBoard1(), 0);

    // Draw Player 2's Board
    drawBoard(*subject->getBoard2(), 400);

    win.flush();
}

void Graphic::drawBoard(const Board& board, int xOffset) {
    int boardWidth = board.getWidth();
    int boardHeight = board.getHeight();

    // Draw the grid
    for (int y = 0; y < boardHeight; ++y) {
        for (int x = 0; x < boardWidth; ++x) {
            char cellType = board.getCell(x, y).getContent();
            int color = win.cellTypeToColor(cellType);
            win.fillRectangle(xOffset + x * cellSize, y * cellSize, cellSize, cellSize, color);
        }
    }

    // Draw the next block
    std::vector<std::vector<char>> nextBlock = board.getNextBlock()->getDisplayBlock();
    drawBlock(nextBlock, xOffset, boardHeight * cellSize + 10, boardWidth);
}

void Graphic::drawBlock(const std::vector<std::vector<char>>& block, int xOffset, int yOffset, int width) {
    for (size_t i = 0; i < block.size(); ++i) {
        for (size_t j = 0; j < block[i].size(); ++j) {
            char cellType = block[i][j];
            int color = win.cellTypeToColor(cellType);
            win.fillRectangle(xOffset + j * cellSize, yOffset + i * cellSize, cellSize, cellSize);
        }
    }
}
