#ifndef BLOCK_H
#define BLOCK_H
#include <random>
#include "header.h"


class Block
{

public:
    Block();
    std::random_device rd;
    void clearBlock(RGBColor &blk);
    bool isActive(RGBColor blk);
    void setBlock(const RGBColor in, RGBColor& out);
    int getRandomColorId();
};

#endif // BLOCK_H
