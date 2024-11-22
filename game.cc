#include "game.h"

Game::Game(shared_ptr<Board> board1, shared_ptr<Board> board2): board1{board1}, board2{board2} {}

void Game::render() { notifyObservers(); }

shared_ptr<Board> Game::getBoard1() const { return board1; }
shared_ptr<Board> Game::getBoard2() const { return board2; }

// public methods implementation

void Game::startGame() {
  board1->reset();
  board2->reset();
  score->clearScore();
  player1Turn = true;
  notifyObservers();
}

void Game::restartGame() {
  startGame();
}

Bool Game::checkPlayer1Turn() {
  return player1Turn;
}

void Game::notifyObservers() {
  if (textObserver) {
    textObserver->notify();
  }
  if (graphicsObserver) {
    graphicsObserver->notify();
  }
}
