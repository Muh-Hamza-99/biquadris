#include "cell.h"

Cell::Cell(int x, int y, bool occupied): x{x}, y{y}, occupied{occupied} {}

int Cell::getX() const { return x; }
int Cell::getY() const { return y; }
bool Cell::getOccupied() const { return occupied; }
void Cell::setX(int x) { this->x = x; }
void Cell::setY(int y) { this->y = y; }
void Cell::setOccupied(bool occupied) { this->occupied = occupied; }
