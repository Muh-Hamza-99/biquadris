#include "level.h"

Level::Level(string &file): file{file} {}

string Level::getFile() const { return file; }

Level::~Level() {}
