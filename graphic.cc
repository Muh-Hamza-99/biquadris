#include "graphic.h"
#include <vector>

Graphic::Graphic(std::shared_ptr<Game> subject)
    : subject{subject}, win{800, 600} { 
}

void Graphic::notify() {
    win.clear(); 

    win.setColor(Xwindow::Black);

    // level and score display
    win.drawString(10, 20, "Level: " + std::to_string(subject->getBoard1()->getCurrentLevel()->getLevel()));
    win.drawString(410, 20, "Level: " + std::to_string(subject->getBoard2()->getCurrentLevel()->getLevel()));

    win.drawString(10, 40, "Score: " + std::to_string(subject->getBoard1()->getScore()));
    win.drawString(410, 40, "Score: " + std::to_string(subject->getBoard2()->getScore()));

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
            win.fillRectangle(xOffset + x * cellSize, y * cellSize + 60, cellSize, cellSize, color); // Offset below Level/Score rows
        }
    }

    // Draw the "Next:" label
    win.drawString(xOffset + 10, boardHeight * cellSize + 80, "Next:");

    // Draw the next block below the board
    std::vector<std::vector<char>> nextBlock = board.getNextBlock()->getDisplayBlock();
    drawBlock(nextBlock, xOffset, boardHeight * cellSize + 100, boardWidth);
}


void Graphic::drawBlock(const std::vector<std::vector<char>>& block, int xOffset, int yOffset, int width) {
    for (size_t i = 0; i < block.size(); ++i) {
        for (size_t j = 0; j < block[i].size(); ++j) {
            char cellType = block[i][j];
            if (cellType != ' ') { // Skip empty cells
                int color = win.cellTypeToColor(cellType);
                win.fillRectangle(
                    xOffset + j * cellSize,  // X position
                    yOffset + i * cellSize,  // Y position
                    cellSize, cellSize,      // Dimensions
                    color                    // Cell color
                );
            }
        }
    }
}

