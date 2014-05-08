#ifndef DRAW_H
#define DRAW_H
#include <SDL.h>
#include "../header.h"
#include <SDL_ttf.h>
class Graphic
{
    SDL_Surface * screen = NULL;
public:
    Graphic(int width, int height);
    void drawText(short x, short y, std::string Text, int fontSize);
    void drawBlock(int x, int y, int height, int width, RGBColor Color);
    void clearAll();
    void render();
};

#endif // DRAW_H
