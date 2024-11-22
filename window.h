#ifndef _WINDOW_H_
#define _WINDOW_H_

#include <X11/Xlib.h>
#include <iostream>
#include <string>
using namespace std;

class Xwindow {
  Display *d;
  Window w;
  int s, width, height;
  GC gc;
  unsigned long colours[5];

 public:
  Xwindow(int width=500, int height=500);
  ~Xwindow();
  enum {White=0, Black, Red, Green, Blue};
  int getWidth() const;
  int getHeight() const;
  void fillRectangle(int x, int y, int width, int height, int colour=Black);
  void drawString(int x, int y, string msg);

};

#endif
