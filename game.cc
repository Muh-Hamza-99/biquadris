#include "game.h"

// constructor and destructor implementation

Game::Game() : player1Turn{true} {
  // initialize boards
  board1 = make_unique<Board>();
  board2 = make_unique<Board>();

  // Initialize Observers
  textObserver = make_unique<TextObserver>(board1.get(), board2.get());
  graphicsObserver = make_unique<GraphicsObserver>(board1.get(), board2.get());

  // Initialize score
  score = make_unique<Score>();

  // Initialize commandInterpreter
  commandInterpreter = make_unique<commandInterpreter>(this);
}

Game::~Game() { // already handled by unique_ptr }


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
