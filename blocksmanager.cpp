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

void BlocksManager::moveemptyBlocks(int x){
    std::vector <RGBColor> tmpColor;
    for(int y = 0; y < tableBlocks.size();  y++)
         if (isActive(tableBlocks[y][x]))
             tmpColor.push_back(tableBlocks[y][x]);
    int o = 0;
    for(int a = 0; a < sizeY; a++){
        std::cout<<++o<<std::endl;
        if (a < sizeY - (tmpColor.size()) )
            clearBlock(tableBlocks[a][x])  ;
        else
            tableBlocks[a][x] = tmpColor[ a - (sizeY - tmpColor.size())    ];
    };
}

void  BlocksManager::searchNeiberhood(int x,
                                      int y,
                                      int &counterPoints){
    RGBColor currentElement = tableBlocks[y][x];
    quene.emplace_back(x, y);
    for(unsigned i = 0; i< quene.size(); i++){
        int curentPosX = quene[i].first, curentPosY = quene[i].second;
        if (curentPosX+1 < sizeX )
            checkNeiberhood(curentPosX+1, curentPosY, currentElement);
        if (curentPosX-1 > -1 )
            checkNeiberhood(curentPosX - 1, curentPosY, currentElement);
        if (curentPosY+1 < sizeY )
            checkNeiberhood(curentPosX, curentPosY+1, currentElement);
        if (curentPosY-1 > -1 )
            checkNeiberhood(curentPosX, curentPosY-1, currentElement);
    }
   workinQuene(counterPoints);
}
void BlocksManager::workinQuene(int &counterPoints){
    if (quene.size() > 2){
        for(auto&& queneElement: quene){
            clearBlock(tableBlocks[queneElement.second][queneElement.first]);
            moveemptyBlocks(queneElement.first);
        }
        counterPoints += quene.size();
    }
    quene.clear();
}

void BlocksManager::checkNeiberhood(int x,
                                    int y,
                                    RGBColor currentElement){
    if ( currentElement == tableBlocks[y][x] &&
         std::find(quene.begin(), quene.end(), std::make_pair(x, y) ) == quene.end() &&
         isActive(currentElement)){
        quene.emplace_back(x, y);
    }
}
