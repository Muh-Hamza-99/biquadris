#include "game.h"

Game::Game(shared_ptr<Board> board1, shared_ptr<Board> board2): board1{board1}, board2{board2} {}

<<<<<<< Updated upstream
void Game::render() { notifyObservers(); }
=======
Game::Game() : player1Turn{true} {
  // initialize boards
  board1 = make_unique<Board>();
  board2 = make_unique<Board>();

  // Initialize Observers
  textObserver = make_unique<Text>(board1.get(), board2.get());
  graphicsObserver = make_unique<Graphic>(board1.get(), board2.get());

  // Initialize score
  score = make_unique<Score>();

  // Initialize commandInterpreter
  commandInterpreter = make_unique<commandInterpreter>(this);
}

Game::~Game() { // already handled by unique_ptr 
}
>>>>>>> Stashed changes

shared_ptr<Board> Game::getBoard1() const { return board1; }
shared_ptr<Board> Game::getBoard2() const { return board2; }

// public methods implementation

void Game::startGame() {
  board1->reset();
  board2->reset();
  player1Turn = true;
  notifyObservers();
}

void Game::restartGame() {
  startGame();
}

bool Game::checkPlayer1Turn() const { return player1Turn; }
