#include "xwindow.h"
#include <X11/Xutil.h>
#include <X11/Xutil.h>
#include <string>
#include <iostream>

Xwindow::Xwindow(int width, int height): width{width}, height{height} {
    d = XOpenDisplay(nullptr);
    if (d == NULL) {
        std::cerr << "Cannot open display" << std::endl;
        exit(1);
    }
    s = DefaultScreen(d);
    w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, width, height, 1,
                            BlackPixel(d, s), WhitePixel(d, s));
    XSelectInput(d, w, ExposureMask | KeyPressMask);
    XMapWindow(d, w);
    gc = XCreateGC(d, w, 0, nullptr);

    // Initialize available colours
    XColor xcolour;
    Colormap cmap = DefaultColormap(d, DefaultScreen(d));

    const char* colorNames[] = {"white", "black", "red", "green", "purple", "blue", "yellow", "cyan", "magenta"};
    for (int i = 0; i < 8; ++i) {
        XParseColor(d, cmap, colorNames[i], &xcolour);
        XAllocColor(d, cmap, &xcolour);
        colours[i] = xcolour.pixel;
    }

    XSetForeground(d, gc, colours[Black]);
}

Xwindow::~Xwindow() {
    XFreeGC(d, gc);
    XDestroyWindow(d, w);
    XCloseDisplay(d);
}

int Xwindow::getWidth() const {
    return width;
}

int Xwindow::getHeight() const {
    return height;
}

void Xwindow::clear() {
    XClearWindow(d, w);
}

void Xwindow::flush() {
    XFlush(d);
}

int Xwindow::cellTypeToColor(char cellType) const {
    switch (cellType) {
        case 'I': return Cyan;
        case 'J': return Blue;
        case 'L': return Yellow;
        case 'O': return Purple;
        case 'S': return Green;
        case 'T': return Magenta;
        case 'Z': return White;
        case '*': return Red;
        case ' ': return Black; // Empty cell
        default:  return Black; // Default color for unknown cell types
    }
}

void Xwindow::setColor(char colour) {
    XSetForeground(d, gc, colours[colour]);
}

void Xwindow::fillRectangle(int x, int y, int width, int height, int colour) {
    XSetForeground(d, gc, colours[colour]);
    XFillRectangle(d, w, gc, x, y, width, height);
}

void Xwindow::drawString(int x, int y, std::string msg) {
    XDrawString(d, w, gc, x, y, msg.c_str(), msg.length());
}
