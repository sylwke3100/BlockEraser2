#ifndef MENU_H
#define MENU_H

#include "engine/engine.h"
#include "engine/graphic.h"
#include "header.h"
#include "game.h"
#include "engine/events.h"
#include <functional>


class Menu{
    Engine * eng;
    Graphic * gra;
    Game * gr;
    Events *evn;
public:
    Menu();
    void drawMainMenu();
    void drawHeader();
    void drawAboutMenu();
    void loopMenu();
    void runGame();
};

#endif // MENU_H
