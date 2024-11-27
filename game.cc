#include "game.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include "block.h"
#include <iostream>
using namespace std;

Game::Game(shared_ptr<Board> board1, shared_ptr<Board> board2): board1{board1}, board2{board2} {}

void Game::render() { notifyObservers(); }

void Game::left(int repetitions) {
  if (repetitions == 0) return;
  shared_ptr<Board> currentBoard = player1Turn ? board1 : board2;

  for (const pair<int, int> &coord : currentBoard->getCurrentBlock()->getCoords()) {
    currentBoard->setCell(coord.first, coord.second, false);
  }
  for (int i = 0; i < repetitions; ++i) {
    currentBoard->getCurrentBlock()->left();
    if (!currentBoard->currentBlockWithinBounds() || currentBoard->currentBlockColliding()) {
      currentBoard->getCurrentBlock()->right();
    }
  }
  // Checking for heavy block
  if (currentBoard->getCurrentBlock()->getHeavy()) {
    currentBoard->getCurrentBlock()->down();
    if (!currentBoard->currentBlockWithinBounds() || currentBoard->currentBlockColliding()) {
      currentBoard->getCurrentBlock()->up();
    }
  }
  // Checking for heavy effect
  if (currentBoard->getHeavy()) {
    for (int i = 0; i < 2; ++i) {
      currentBoard->getCurrentBlock()->down();
      if (!currentBoard->currentBlockWithinBounds() || currentBoard->currentBlockColliding()) {
        currentBoard->getCurrentBlock()->up();
      }
    }
  }
  for (const pair<int, int> &coord : currentBoard->getCurrentBlock()->getCoords()) {
    currentBoard->setCell(coord.first, coord.second, true, currentBoard->getCurrentBlock()->getType());
  }
}

void Game::right(int repetitions) {
  if (repetitions == 0) return;
  shared_ptr<Board> currentBoard = player1Turn ? board1 : board2;

  for (const pair<int, int> &coord : currentBoard->getCurrentBlock()->getCoords()) {
    currentBoard->setCell(coord.first, coord.second, false);
  }
  for (int i = 0; i < repetitions; ++i) {
    currentBoard->getCurrentBlock()->right();
    if (!currentBoard->currentBlockWithinBounds() || currentBoard->currentBlockColliding()) {
      currentBoard->getCurrentBlock()->left();
    }
  }
  // Checking for heavy block
  if (currentBoard->getCurrentBlock()->getHeavy()) {
    currentBoard->getCurrentBlock()->down();
    if (!currentBoard->currentBlockWithinBounds() || currentBoard->currentBlockColliding()) {
      currentBoard->getCurrentBlock()->up();
    }
  }
  // Checking for heavy effect
  if (currentBoard->getHeavy()) {
    for (int i = 0; i < 2; ++i) {
      currentBoard->getCurrentBlock()->down();
      if (!currentBoard->currentBlockWithinBounds() || currentBoard->currentBlockColliding()) {
        currentBoard->getCurrentBlock()->up();
      }
    }
  }
  for (const pair<int, int> &coord : currentBoard->getCurrentBlock()->getCoords()) {
    currentBoard->setCell(coord.first, coord.second, true, currentBoard->getCurrentBlock()->getType());
  }
}

void Game::down(int repetitions) {
  if (repetitions == 0) return;
  shared_ptr<Board> currentBoard = player1Turn ? board1 : board2;

  for (const pair<int, int> &coord : currentBoard->getCurrentBlock()->getCoords()) {
    currentBoard->setCell(coord.first, coord.second, false);
  }
  for (int i = 0; i < repetitions; ++i) {
    currentBoard->getCurrentBlock()->down();
    if (!currentBoard->currentBlockWithinBounds() || currentBoard->currentBlockColliding()) {
      currentBoard->getCurrentBlock()->up();
    }
  }
  for (const pair<int, int> &coord : currentBoard->getCurrentBlock()->getCoords()) {
    currentBoard->setCell(coord.first, coord.second, true, currentBoard->getCurrentBlock()->getType());
  }
}

void Game::rotatecw(int repetitions) {
  if (repetitions == 0) return;
  shared_ptr<Board> currentBoard = player1Turn ? board1 : board2;

  for (const pair<int, int> &coord : currentBoard->getCurrentBlock()->getCoords()) {
    currentBoard->setCell(coord.first, coord.second, false);
  }
  for (int i = 0; i < repetitions; ++i) {
    currentBoard->getCurrentBlock()->rotatecw();
    if (!currentBoard->currentBlockWithinBounds() || currentBoard->currentBlockColliding()) {
      currentBoard->getCurrentBlock()->rotateccw();
    }
  }
  // Checking for heavy block
  if (currentBoard->getCurrentBlock()->getHeavy()) {
    currentBoard->getCurrentBlock()->down();
    if (!currentBoard->currentBlockWithinBounds() || currentBoard->currentBlockColliding()) {
      currentBoard->getCurrentBlock()->up();
    }
  }
  for (const pair<int, int> &coord : currentBoard->getCurrentBlock()->getCoords()) {
    currentBoard->setCell(coord.first, coord.second, true, currentBoard->getCurrentBlock()->getType());
  }
}

void Game::rotateccw(int repetitions) {
  if (repetitions == 0) return;
  shared_ptr<Board> currentBoard = player1Turn ? board1 : board2;

  for (const pair<int, int> &coord : currentBoard->getCurrentBlock()->getCoords()) {
    currentBoard->setCell(coord.first, coord.second, false);
  }
  for (int i = 0; i < repetitions; ++i) {
    currentBoard->getCurrentBlock()->rotateccw();
    if (!currentBoard->currentBlockWithinBounds() || currentBoard->currentBlockColliding()) {
      currentBoard->getCurrentBlock()->rotatecw();
    }
  }
  // Checking for heavy block
  if (currentBoard->getCurrentBlock()->getHeavy()) {
    currentBoard->getCurrentBlock()->down();
    if (!currentBoard->currentBlockWithinBounds() || currentBoard->currentBlockColliding()) {
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

  currentBoard->dropCurrentBlock();
  int cleared = currentBoard->clearFullRows();

  if (cleared >= 2) {
    shared_ptr<Board> otherBoard = player1Turn ? board2 : board1;
    cout << "You cleared more than 2 rows, " << currentBoard->getName() << "!" << endl;
    cout << "Choose an effect to cast upon " << otherBoard->getName() << endl;
    cout << "(1) blind - prevent your opponent from seeing majority of the board" << endl;
    cout << "(2) heavy - make your opponent's current block x2 heavy" << endl;
    cout << "(3) force X - choose your opponent's current block" << endl;
      
    string effect;
    cin >> effect;

    if (effect == "blind") {
      otherBoard->setBlind(true);
    } else if (effect == "heavy") {
      otherBoard->setHeavy(true);
    } else if (effect == "force") {
      char block;
      cin >> block;
      otherBoard->force(block);
    }
  }

  // Level 4 constructive block
  if (currentBoard->getCurrentLevel()->getLevel() == 4 && currentBoard->getPlacedBlocks() % 5 == 0 && currentBoard->getRowsCleared() == 0) {
    shared_ptr<Block> constructiveBlock = make_shared<AsterikBlock>(4);
    shared_ptr<Block> tempCurrentBlock = currentBoard->getCurrentBlock();
    currentBoard->setCurrentBlock(constructiveBlock);

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

    currentBoard->dropCurrentBlock();
    currentBoard->clearFullRows();
    currentBoard->setCurrentBlock(tempCurrentBlock);
    currentBoard->resetRowsCleared();
  } else if (currentBoard->getPlacedBlocks() % 5 == 0) {
    currentBoard->resetRowsCleared();
  }
  
  currentBoard->showNewCurrentBlock();
  currentBoard->setBlind(false);
  currentBoard->setHeavy(false);
  player1Turn = !player1Turn;
}

void Game::levelUp(int repetitions) {
  if (repetitions == 0) return;
  shared_ptr<Board> currentBoard = player1Turn ? board1 : board2;
  
  int currentLevelInt = currentBoard->getCurrentLevel()->getLevel();
  string currentLevelFile = currentBoard->getCurrentLevel()->getFile();
  if (currentLevelInt == 4) return;
  
  for (int i = 0; i < repetitions; ++i) currentLevelInt += 1;
  if (currentLevelInt > 4) currentLevelInt = 4;

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

void Game::levelDown(int repetitions) {
  if (repetitions == 0) return;
  shared_ptr<Board> currentBoard = player1Turn ? board1 : board2;

  int currentLevelInt = currentBoard->getCurrentLevel()->getLevel();
  string currentLevelFile = currentBoard->getCurrentLevel()->getFile();
  if (currentLevelInt == 0) return;
  for (int i = 0; i < repetitions; ++i) currentLevelInt -= 1;
  if (currentLevelInt < 0) currentLevelInt = 0;

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

void Game::restart() {
  board1->reset();
  board2->reset();
  player1Turn = true;
}

bool Game::checkPlayer1Turn() const { return player1Turn; }

void Game::setRandom(bool random, const string& file) {
  if (auto level = dynamic_pointer_cast<Level3>(board1->getCurrentLevel())) {
        level->setRandom(random, file);
    } else if (auto level = dynamic_pointer_cast<Level4>(board1->getCurrentLevel())) {
        level->setRandom(random, file); 
    }

    if (auto level = dynamic_pointer_cast<Level3>(board2->getCurrentLevel())) {
        level->setRandom(random, file);
    } else if (auto level = dynamic_pointer_cast<Level4>(board2->getCurrentLevel())) {
        level->setRandom(random, file);
    }
}
