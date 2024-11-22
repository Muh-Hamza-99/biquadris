#include "block.h"

// BLOCK

Block::~Block() {}

// IBLOCK

char IBlock::getType() const { return 'I'; }

// JBLOCK

char JBlock::getType() const { return 'J'; }

// LBLOCK

char LBlock::getType() const { return 'L'; }

// OBLOCK

char OBlock::getType() const { return 'O'; }

// SBLOCK

char SBlock::getType() const { return 'S'; }

// ZBLOCK

char ZBlock::getType() const { return 'Z'; }

// TBLOCK

char TBlock::getType() const { return 'T'; }

// ASTERIKBLOCK

char AsterikBlock::getType() const { return '*'; }
