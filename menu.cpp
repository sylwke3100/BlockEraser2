#include "menu.h"

Menu::Menu(){
    eng = new Engine();
    gra = new Graphic(600, 600);
    eng->setWindowTitle("BlockEraser 2");
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
    gr = NULL;
    gr = new Game(eng, gra);
    gr->initGame();
    gr->loopGame();
    eng->clearEvents();
}

void Menu::loopMenu(){
    int quit = 0;
    while (!quit){
        drawMainMenu();
      while (SDL_PollEvent(eng->event)){
        switch(eng->event->type){
        case SDL_MOUSEBUTTONDOWN:
            if (eng->event->button.button == SDL_BUTTON_LEFT and eng->event->button.state == SDL_PRESSED ){
                if ((eng->event->button.x >= 250 && eng->event->button.x <= 375 ) &&
                       (eng->event->button.y >= 200 && eng->event->button.y <= 230)){
                    runGame();
                 }
           }
            break;
        case SDL_QUIT:
            quit =1;
            SDL_Quit();
            break;
        }
      }
    }
}
