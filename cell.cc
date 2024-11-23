#include "cell.h"

Cell::Cell(int x, int y, bool occupied, char content): x{x}, y{y}, occupied{occupied}, content{content} {}

int Cell::getX() const { return x; }
int Cell::getY() const { return y; }
bool Cell::getOccupied() const { return occupied; }
char Cell::getContent() const { return content; }
void Cell::setX(int x) { this->x = x; }
void Cell::setY(int y) { this->y = y; }
void Cell::setOccupied(bool occupied) { this->occupied = occupied; }
void Cell::setContent(char content) { this->content = content; }
