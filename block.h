#ifndef BLOCK_H
#define BLOCK_H
#include <random>
#include "header.h"


class Block
{

public:
    std::mt19937 engine ;
    void clearBlock(RGBColor &blk);
    bool isActive(RGBColor blk);
    void setBlock(const RGBColor in, RGBColor& out);
    int getRandomColorId();
};

#endif // BLOCK_H
