#ifndef BLOCK_H
#define BLOCK_H
#include <random>
#include "header.h"

class Block{

public:
    Block();
    std::random_device rd;
    static void clearBlock(RGBColor &blk);
    static bool isActive(RGBColor blk);
    static void setBlock(const RGBColor &in, RGBColor& out);
    int getRandomColorId();
};

#endif // BLOCK_H
