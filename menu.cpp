#include "menu.h"

Menu::Menu(){
    evn = new Events();
    eng = new Engine();
    gra = new Graphic(600, 600);
    eng->setWindowTitle("BlockEraser 2");
    std::function<void(Position)> newGameHandler = [this](Position e){ this->runGame(); };
    evn->addEvent(EventElement(Position(250, 375, 200, 230), newGameHandler ));
    std::function<void(Position)> aboutGameHandler = [this](Position e){ this->drawAboutMenu(); };
    evn->addEvent(EventElement(Position(250, 475, 200, 430), aboutGameHandler ));
}
void Menu::drawHeader(){
    gra ->clearAll();
    gra->drawText(150, 90, "Block Eraser 2", 50);
    gra->drawBlock(100,100, 15, 15, RGBColor(255, 255, 0));
    gra->drawBlock(120,100, 15, 15, RGBColor(255, 127, 0));
    gra->drawBlock(100,120, 15, 15, RGBColor(0, 139, 0));
    gra->drawBlock(120,120, 15, 15, RGBColor(255, 0, 0));
}

void Menu::drawAboutMenu(){
    drawHeader();

    evn->activateEvent(2);
    gra->drawText(100, 200, "Jest to prosta gra w które trzeba usuwać zbędne klocki", 15);
    gra->drawText(100, 220, "tego samego koloru. Za to dostaje się odpowiednio plunkty i", 15);
    gra->drawText(100, 240, "bonus czasowy", 15);
    gra->render();
    eng->delay(3000);
    drawMainMenu();
}

void Menu::drawMainMenu(){
    drawHeader();
    gra->drawText(250, 200, "Nowa gra", 30);
    gra->drawText(250, 240, "O grze", 30);
    gra->render();
}

void Menu::runGame(){
    gr = new Game(eng, gra, evn);
    gr->initGame();
    gr->loopGame();
    evn->activateEvent(0);
    evn->activateEvent(1);
    evn->removeEvent(2);
    drawMainMenu();
}

void Menu::loopMenu(){
    int quit = 0;
     drawMainMenu();
     while(!quit)
        evn->loopEvents(quit);

}
