#ifndef _BLOCK_H_
#define _BLOCK_H_

#include <vector>
#include <memory>
using namespace std;

class Block {
    protected:
        bool heavy;
        vector<pair<int, int>> coords; // Pairs of (x,y) coordinates
        int rotation = 0;
    public:
        Block(bool heavy = false);
        void left();
        void right();
        void down();
        bool getHeavy() const;
        void setHeavy(bool heavy);
        virtual ~Block();
        virtual char getType() const = 0;
        virtual void rotatecw() = 0;
        virtual void rotateccw() = 0;
};

class IBlock : public Block {
    public:
        IBlock(bool heavy = false);
        char getType() const override;
        void rotatecw() override;
        void rotateccw() override;
};

class JBlock : public Block {
    public:
        JBlock(bool heavy = false);
        char getType() const override;
        void rotatecw() override;
        void rotateccw() override;
};

class LBlock : public Block {
    public:
        LBlock(bool heavy = false);
        char getType() const override;
        void rotatecw() override;
        void rotateccw() override;
};

class OBlock : public Block {
    public:
        OBlock(bool heavy = false);
        char getType() const override;
        void rotatecw() override;
        void rotateccw() override;
};

class SBlock : public Block {
    public:
        SBlock(bool heavy = false);
        char getType() const override;
        void rotatecw() override;
        void rotateccw() override;
};

class ZBlock : public Block {
    public:
        ZBlock(bool heavy = false);
        char getType() const override;
        void rotatecw() override;
        void rotateccw() override;
};

class TBlock : public Block {
    public:
        TBlock(bool heavy = false);
        char getType() const override;
        void rotatecw() override;
        void rotateccw() override;
};

class AsterikBlock : public Block {
    public:
        AsterikBlock(bool heavy = false);
        char getType() const override;
        void rotatecw() override;
        void rotateccw() override;
};

#endif
