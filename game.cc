#include "game.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"

Game::Game(shared_ptr<Board> board1, shared_ptr<Board> board2): board1{board1}, board2{board2} {}

void Game::render() { notifyObservers(); }

void Game::left() {
  shared_ptr<Board> currentBoard = player1Turn ? board1 : board2;

  for (const pair<int, int> &coord : currentBoard->getCurrentBlock()->getCoords()) {
    currentBoard->setCell(coord.first, coord.second, false);
  }
  currentBoard->getCurrentBlock()->left();
  if (!currentBoard->withinBounds() || currentBoard->colliding()) {
    currentBoard->getCurrentBlock()->right();
  }
  // Checking for heavy block
  if (currentBoard->getCurrentBlock()->getHeavy()) {
    currentBoard->getCurrentBlock()->down();
    if (!currentBoard->withinBounds() || currentBoard->colliding()) {
      currentBoard->getCurrentBlock()->up();
    }
  }
  for (const pair<int, int> &coord : currentBoard->getCurrentBlock()->getCoords()) {
    currentBoard->setCell(coord.first, coord.second, true, currentBoard->getCurrentBlock()->getType());
  }
}

void Game::right() {
  shared_ptr<Board> currentBoard = player1Turn ? board1 : board2;

  for (const pair<int, int> &coord : currentBoard->getCurrentBlock()->getCoords()) {
    currentBoard->setCell(coord.first, coord.second, false);
  }
  currentBoard->getCurrentBlock()->right();
  if (!currentBoard->withinBounds() || currentBoard->colliding()) {
    currentBoard->getCurrentBlock()->left();
  }
  // Checking for heavy block
  if (currentBoard->getCurrentBlock()->getHeavy()) {
    currentBoard->getCurrentBlock()->down();
    if (!currentBoard->withinBounds() || currentBoard->colliding()) {
      currentBoard->getCurrentBlock()->up();
    }
  }
  for (const pair<int, int> &coord : currentBoard->getCurrentBlock()->getCoords()) {
    currentBoard->setCell(coord.first, coord.second, true, currentBoard->getCurrentBlock()->getType());
  }
}

void Game::down() {
  shared_ptr<Board> currentBoard = player1Turn ? board1 : board2;

  for (const pair<int, int> &coord : currentBoard->getCurrentBlock()->getCoords()) {
    currentBoard->setCell(coord.first, coord.second, false);
  }
  currentBoard->getCurrentBlock()->down();
  if (!currentBoard->withinBounds() || currentBoard->colliding()) {
    currentBoard->getCurrentBlock()->up();
  };
  for (const pair<int, int> &coord : currentBoard->getCurrentBlock()->getCoords()) {
    currentBoard->setCell(coord.first, coord.second, true, currentBoard->getCurrentBlock()->getType());
  }
}

void Game::rotatecw() {
  shared_ptr<Board> currentBoard = player1Turn ? board1 : board2;

  for (const pair<int, int> &coord : currentBoard->getCurrentBlock()->getCoords()) {
    currentBoard->setCell(coord.first, coord.second, false);
  }
  currentBoard->getCurrentBlock()->rotatecw();
  if (!currentBoard->withinBounds() || currentBoard->colliding()) {
    currentBoard->getCurrentBlock()->rotateccw();
  }
  // Checking for heavy block
  if (currentBoard->getCurrentBlock()->getHeavy()) {
    currentBoard->getCurrentBlock()->down();
    if (!currentBoard->withinBounds() || currentBoard->colliding()) {
      currentBoard->getCurrentBlock()->up();
    }
  }
  for (const pair<int, int> &coord : currentBoard->getCurrentBlock()->getCoords()) {
    currentBoard->setCell(coord.first, coord.second, true, currentBoard->getCurrentBlock()->getType());
  }
}

void Game::rotateccw() {
  shared_ptr<Board> currentBoard = player1Turn ? board1 : board2;

  for (const pair<int, int> &coord : currentBoard->getCurrentBlock()->getCoords()) {
    currentBoard->setCell(coord.first, coord.second, false);
  }
  currentBoard->getCurrentBlock()->rotateccw();
  if (!currentBoard->withinBounds() || currentBoard->colliding()) {
    currentBoard->getCurrentBlock()->rotatecw();
  }
  // Checking for heavy block
  if (currentBoard->getCurrentBlock()->getHeavy()) {
    currentBoard->getCurrentBlock()->down();
    if (!currentBoard->withinBounds() || currentBoard->colliding()) {
      currentBoard->getCurrentBlock()->up();
    }
  }
  for (const pair<int, int> &coord : currentBoard->getCurrentBlock()->getCoords()) {
    currentBoard->setCell(coord.first, coord.second, true, currentBoard->getCurrentBlock()->getType());
  }
}

void Game::drop() {
  shared_ptr<Board> currentBoard = player1Turn ? board1 : board2;

  vector<pair<int, int>> previousCurrentBlockCoords = currentBoard->getCurrentBlock()->getCoords();
  vector<pair<int, int>> currentCurrentBlockCoords = currentBoard->getCurrentBlock()->getCoords();
  while (true) {
    down();
    previousCurrentBlockCoords = currentCurrentBlockCoords;
    currentCurrentBlockCoords = currentBoard->getCurrentBlock()->getCoords();
    bool sameCoords = true;
    for (int i = 0; i < static_cast<int>(currentCurrentBlockCoords.size()); i++) {
      if (currentCurrentBlockCoords[i].first != previousCurrentBlockCoords[i].first ||
          currentCurrentBlockCoords[i].second != previousCurrentBlockCoords[i].second) {
        sameCoords = false;
      }
    }
    if (sameCoords) {
      break;
    } else {
      continue;
    }
  }

  // Clear any filled rows, update blocks' coordinates and clear empty blocks
  // Check number of eliminated rows >= 2 and ask for special effect

  currentBoard->endTurn();
  player1Turn = !player1Turn;
}

void Game::levelUp() {
  shared_ptr<Board> currentBoard = player1Turn ? board1 : board2;
  
  int currentLevelInt = currentBoard->getCurrentLevel()->getLevel();
  string currentLevelFile = currentBoard->getCurrentLevel()->getFile();
  if (currentLevelInt == 4) return;
  currentLevelInt += 1;

  if (currentLevelInt == 1) {
    currentBoard->setCurrentLevel(make_shared<Level1>(currentLevelFile));
  } else if (currentLevelInt == 2) {
    currentBoard->setCurrentLevel(make_shared<Level2>(currentLevelFile));
  } else if (currentLevelInt == 3) {
    currentBoard->setCurrentLevel(make_shared<Level3>(currentLevelFile));
  } else if (currentLevelInt == 4) {
    currentBoard->setCurrentLevel(make_shared<Level4>(currentLevelFile));
  }
}

void Game::levelDown() {
  shared_ptr<Board> currentBoard = player1Turn ? board1 : board2;

  int currentLevelInt = currentBoard->getCurrentLevel()->getLevel();
  string currentLevelFile = currentBoard->getCurrentLevel()->getFile();
  if (currentLevelInt == 0) return;
  currentLevelInt -= 1;

  if (currentLevelInt == 0) {
    currentBoard->setCurrentLevel(make_shared<Level0>(currentLevelFile));
  } else if (currentLevelInt == 1) {
    currentBoard->setCurrentLevel(make_shared<Level1>(currentLevelFile));
  } else if (currentLevelInt == 2) {
    currentBoard->setCurrentLevel(make_shared<Level2>(currentLevelFile));
  } else if (currentLevelInt == 3) {
    currentBoard->setCurrentLevel(make_shared<Level3>(currentLevelFile));
  }
}

shared_ptr<Board> Game::getBoard1() const { return board1; }
shared_ptr<Board> Game::getBoard2() const { return board2; }

void Game::startGame() {
  board1->reset();
  board2->reset();
  player1Turn = true;
  render();
}

void Game::restart() {
  board1->reset();
  board2->reset();
  player1Turn = true;
}

bool Game::checkPlayer1Turn() const { return player1Turn; }
