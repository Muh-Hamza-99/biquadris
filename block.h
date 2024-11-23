#ifndef _BLOCK_H_
#define _BLOCK_H_

#include <vector>
#include <memory>
using namespace std;

class Block {
    protected:
        bool heavy;
        vector<pair<int, int>> coords; // Pairs of (x,y) coordinates
        int rotation;
    public:
        Block(bool heavy = false, int rotation = 0);
        void left();
        void right();
        void down();
        bool getHeavy() const;
        void setHeavy(bool heavy);
        virtual ~Block();
        virtual char getType() const = 0;
        virtual void init() = 0; // To initialize starting (x,y) coordinates
        virtual void rotatecw() = 0;
        virtual void rotateccw() = 0;
};

class IBlock : public Block {
    public:
        char getType() const override;
        void init() override;
        void rotatecw() override;
        void rotateccw() override;
};

class JBlock : public Block {
    public:
        char getType() const override;
        void init() override;
        void rotatecw() override;
        void rotateccw() override;
};

class LBlock : public Block {
    public:
        char getType() const override;
        void init() override;\
        void rotatecw() override;
        void rotateccw() override;
};

class OBlock : public Block {
    public:
        char getType() const override;
        void init() override;
        void rotatecw() override;
        void rotateccw() override;
};

class SBlock : public Block {
    public:
        char getType() const override;
        void init() override;
        void rotatecw() override;
        void rotateccw() override;
};

class ZBlock : public Block {
    public:
        char getType() const override;
        void init() override;
        void rotatecw() override;
        void rotateccw() override;
};

class TBlock : public Block {
    public:
        char getType() const override;
        void init() override;
        void rotatecw() override;
        void rotateccw() override;
};

class AsterikBlock : public Block {
    public:
        char getType() const override;
        void init() override;
        void rotatecw() override;
        void rotateccw() override;
};

#endif
