#ifndef DRAW_H
#define DRAW_H
#include <SDL.h>
#include "../header.h"
#include <SDL_ttf.h>
#include <vector>
#include <stdexcept>

struct graphicBlock{
    RGBColor color;
    SDL_Rect square;
    graphicBlock(RGBColor col, SDL_Rect squa): color(col), square(squa){

    }
};

class Graphic
{
    SDL_Renderer* renderer;
    SDL_Surface* screen;
    std::vector<graphicBlock> blockList;
public:
    Graphic(int width, int height, SDL_Window *window);
    ~Graphic();
    void drawText(short x, short y, std::string Text, int fontSize);
    void drawBlock(int x, int y, int height, int width, RGBColor color);
    void clearAll();
    void render();
};

#endif // DRAW_H
