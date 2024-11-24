#ifndef _BLOCK_H_
#define _BLOCK_H_

#include <vector>
#include <memory>
using namespace std;

class Block {
    protected:
        bool heavy;
        vector<pair<int, int>> coords; // Pairs of (x,y) coordinates
        vector<vector<char>> displayBlock; // Vector of vector of chars for printing next block
        int rotation = 0;
        int generatedLevel;
    public:
        Block(int generatedLevel, bool heavy = false);
        void left();
        void right();
        void down();
        vector<vector<char>> getDisplayBlock() const;
        int getGeneratedLevel() const;
        bool getHeavy() const;
        void setHeavy(bool heavy);
        virtual ~Block();
        virtual char getType() const = 0;
        virtual void rotatecw() = 0;
        virtual void rotateccw() = 0;
};

class IBlock : public Block {
    public:
        IBlock(int generatedLevel, bool heavy = false);
        char getType() const override;
        void rotatecw() override;
        void rotateccw() override;
};

class JBlock : public Block {
    public:
        JBlock(int generatedLevel, bool heavy = false);
        char getType() const override;
        void rotatecw() override;
        void rotateccw() override;
};

class LBlock : public Block {
    public:
        LBlock(int generatedLevel, bool heavy = false);
        char getType() const override;
        void rotatecw() override;
        void rotateccw() override;
};

class OBlock : public Block {
    public:
        OBlock(int generatedLevel, bool heavy = false);
        char getType() const override;
        void rotatecw() override;
        void rotateccw() override;
};

class SBlock : public Block {
    public:
        SBlock(int generatedLevel, bool heavy = false);
        char getType() const override;
        void rotatecw() override;
        void rotateccw() override;
};

class ZBlock : public Block {
    public:
        ZBlock(int generatedLevel, bool heavy = false);
        char getType() const override;
        void rotatecw() override;
        void rotateccw() override;
};

class TBlock : public Block {
    public:
        TBlock(int generatedLevel, bool heavy = false);
        char getType() const override;
        void rotatecw() override;
        void rotateccw() override;
};

class AsterikBlock : public Block {
    public:
        AsterikBlock(int generatedLevel, bool heavy = false);
        char getType() const override;
        void rotatecw() override;
        void rotateccw() override;
};

#endif
