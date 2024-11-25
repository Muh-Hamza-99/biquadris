#include "level.h"

Level::Level(string file): file{file} {}

string Level::getFile() const { return file; }

void Level::readFile() {}

Level::~Level() {}
