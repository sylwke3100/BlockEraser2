#ifndef MENU_H
#define MENU_H

#include "engine/engine.h"
#include "engine/graphic.h"
#include "header.h"
#include "game.h"


class Menu{
    Engine * eng;
    Graphic * gra;
    Game * gr;
public:
    Menu();
    void drawMainMenu();
    void drawHeader();
    void loopMenu();
    void runGame();
};

#endif // MENU_H
