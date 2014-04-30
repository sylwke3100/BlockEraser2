#include "block.h"

Block::Block(){

}
void Block::clearBlock(RGBColor &blk){
    blk.set(0, 0, 0);
}

bool Block::isActive(RGBColor blk){
    if (blk == RGBColor(0,0,0))
        return false;
    else
        return true;
}

void Block::setBlock(const RGBColor in,
                     RGBColor &out){
    out = in;
}

int Block::getRandomColorId(){
    std::default_random_engine e1(rd());
    std::uniform_int_distribution<int> rando(1,6);
    int r = rando(e1);
    return r;
}
