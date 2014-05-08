#include "blocksmanager.h"

BlocksManager::BlocksManager(int width, int height): sizeX(width), sizeY(height){
    tableBlocks.resize(width);
}

void BlocksManager::initGame(){
    for(int y = 0; y < sizeY; y++){
        for(int x = 0; x< sizeX ;x++){
            int randomColor =  Block::getRandomColorId();
            tableBlocks[y].push_back(colorTable[randomColor]);
        }
    }
}

void BlocksManager::moveemptyBlocks(){
    for(int x = 0; x < sizeX; x++){
        std::vector <RGBColor> tmpColor;
        for(unsigned y = 0; y < tableBlocks.size();  y++)
             if (isActive(tableBlocks[y][x]))
                 tmpColor.push_back(tableBlocks[y][x]);
        for(int a = 0; a < tableBlocks.size(); a++){
            if (a < ( tableBlocks.size() - tmpColor.size() ) )
                clearBlock(tableBlocks[a][x])  ;
            else
                tableBlocks[a][x] = tmpColor[ a - (tableBlocks.size()  - tmpColor.size())    ];
        }
        tmpColor.clear();
    }
}

void  BlocksManager::searchNeighborhood(int x,
                                      int y,
                                      int &counterPoints){
    RGBColor currentElement = tableBlocks[y][x];
    quene.emplace_back(x, y);
    for(unsigned i = 0; i< quene.size(); i++){
        int curentPosX = quene[i].first, curentPosY = quene[i].second;
        if (curentPosX+1 < sizeX )
            checkNeighborhood(curentPosX+1, curentPosY, currentElement);
        if (curentPosX-1 > -1 )
           checkNeighborhood(curentPosX - 1, curentPosY, currentElement);
        if (curentPosY+1 < sizeY )
            checkNeighborhood(curentPosX, curentPosY+1, currentElement);
        if (curentPosY-1 > -1 )
            checkNeighborhood(curentPosX, curentPosY-1, currentElement);
    }
   workinQuene(counterPoints);
}
void BlocksManager::workinQuene(int &counterPoints){
    if (quene.size() > 2){
        for(auto&& queneElement: quene){
            clearBlock(tableBlocks[queneElement.second][queneElement.first]);
        }
        counterPoints += quene.size();
        moveemptyBlocks();
    }
    quene.clear();
}

void BlocksManager::checkNeighborhood(int x,
                                    int y,
                                    RGBColor currentElement){
    if ( currentElement == tableBlocks[y][x] &&
         std::find(quene.begin(), quene.end(), std::make_pair(x, y) ) == quene.end() &&
         isActive(currentElement)){
        quene.emplace_back(x, y);
    }
}
