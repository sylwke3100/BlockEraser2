#ifndef MENU_H
#define MENU_H

#include "engine/engine.h"
#include "engine/graphic.h"
#include "header.h"
#include "game.h"


class Menu{
    Engine * eng;
    Graphic * gra;
public:
    Menu();
    void drawMainMenu();
    void drawHeader();
    void loopMenu();
};

#endif // MENU_H
