#ifndef __XWINDOW_H__
#define __XWINDOW_H__

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <string>

class Xwindow {
  Display *d;
  Window w;
  int s, width, height;
  GC gc;
  unsigned long colours[8]; 

 public:
 // constructors and destructors
  Xwindow(int width=500, int height=500);  
  ~Xwindow();                              

    // diff colors for diff block types
  enum {White=0, Black, Red, Green, Purple, Blue, Yellow, Cyan, Magenta, Orange}; // Available colours.

  // public getter methods
  int getWidth() const; 
  int getHeight() const; 

  // other public methods
  void clear(); 
  void flush(); 
  int cellTypeToColor(char cellType) const;
  void setColor(char cellType);
  void fillRectangle(int x, int y, int width, int height, int colour=Black);
  void drawString(int x, int y, std::string msg);
};

#endif
