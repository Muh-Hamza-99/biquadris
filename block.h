#ifndef _BLOCK_H_
#define _BLOCK_H_

class Block {
    public:
        virtual char getType() const = 0;
        virtual ~Block();
};

class IBlock : public Block {
    public:
        char getType() const override;
};

class JBlock : public Block {
    public:
        char getType() const override;
};

class LBlock : public Block {
    public:
        char getType() const override;
};

class OBlock : public Block {
    public:
        char getType() const override;
};

class SBlock : public Block {
    public:
        char getType() const override;
};

class ZBlock : public Block {
    public:
        char getType() const override;
};

class TBlock : public Block {
    public:
        char getType() const override;
};

class AsterikBlock : public Block {
    public:
        char getType() const override;
};

#endif
