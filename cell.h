#ifndef _CELL_H_
#define _CELL_H_

class Cell {
    int x, y;
    bool occupied;
    char content;
    public:
        Cell(int x, int y, bool occupied = false, char content = '.');
        int getX() const;
        int getY() const;
        bool getOccupied() const;
        char getContent() const;
        void setX(int x);
        void setY(int y);
        void setOccupied(bool occupied);
        void setContent(char content);
};

#endif
