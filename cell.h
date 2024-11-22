#ifndef _CELL_H_
#define _CELL_H_

class Cell {
    int x, y;
    bool occupied;
    public:
        Cell(int x, int y, bool occupied = false);
        int getX() const;
        int getY() const;
        bool getOccupied() const;
        void setX(int x);
        void setY(int y);
        void setOccupied(bool occupied);
};

#endif
