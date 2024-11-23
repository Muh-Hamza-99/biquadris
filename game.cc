#include "game.h"

Game::Game(shared_ptr<Board> board1, shared_ptr<Board> board2): board1{board1}, board2{board2} {}

void Game::render() { notifyObservers(); }

shared_ptr<Board> Game::getBoard1() const { return board1; }
shared_ptr<Board> Game::getBoard2() const { return board2; }

void Game::startGame() {
  board1->reset();
  board2->reset();
  player1Turn = true;
  render();
}

void Game::restartGame() {
  startGame();
}

bool Game::checkPlayer1Turn() const { return player1Turn; }
