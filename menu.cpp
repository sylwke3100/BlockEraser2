#include "menu.h"

Menu::Menu(){
    evn = new Events();
    eng = new Engine();
    gra = new Graphic(600, 600);
    eng->setWindowTitle("BlockEraser 2");
    std::function<void(SDL_Event)> newGameHandler = [this](SDL_Event e){ this->runGame(); };
    evn->addEvent(EventElement(Position(250, 375, 200, 230), newGameHandler ));
}


void Menu::drawHeader(){
    gra ->clearAll();
    gra->drawText(150, 90, "Block Eraser 2", 50);
    gra->drawBlock(100,100, 15, 15, RGBColor(255, 255, 0));
    gra->drawBlock(120,100, 15, 15, RGBColor(255, 127, 0));
    gra->drawBlock(100,120, 15, 15, RGBColor(0, 139, 0));
    gra->drawBlock(120,120, 15, 15, RGBColor(255, 0, 0));
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
    evn->removeEvent(1);;
    evn->activateEvent(0);
    drawMainMenu();
}

void Menu::loopMenu(){
    int quit = 0;
     drawMainMenu();
     while(!quit)
        evn->loopEvents(quit);

}
