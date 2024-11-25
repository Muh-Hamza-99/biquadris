#include "game.h"

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
  };
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
  };
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
  };
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
  };
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
