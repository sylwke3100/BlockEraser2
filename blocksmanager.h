#ifndef BLOCKSMANAGER_H
#define BLOCKSMANAGER_H
#include "header.h"
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include "block.h"

class BlocksManager: public Block{
    int sizeX = 0;
    int sizeY = 0;
public:
    std::vector< std::vector<RGBColor> > tableBlocks;
    std::vector<RGBColor> colorTable = {{0, 0, 0}, {255, 127, 0}, {0, 139, 0},
                                                 {0, 0, 225}, {255, 225, 0}, {255, 0, 0}, {230, 232, 250}};
    std::vector<std::pair<int, int> > quene;
    BlocksManager(int width, int height);
    void initGame();
    void searchNeiberhood(int x, int y, int &counterPoints);
    void checkNeiberhood(int x, int y, RGBColor currentElement);
    void moveemptyBlocks();
    void workinQuene(int &counterPoints);
};

#endif // BLOCKSMANAGER_H

