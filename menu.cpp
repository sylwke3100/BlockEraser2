#include "menu.h"

Menu::Menu()
{
    eng = new Engine();
    gra = new Graphic(eng->screen, 600, 600);
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


void Menu::loopMenu(){
    SDL_Event event;
    int quit = 0;
    drawMainMenu();
    while (!quit){
        switch(event.type){
        std::cout<<"Ok23"<<std::endl;
        case SDL_MOUSEBUTTONDOWN:
            if (event.button.button == SDL_BUTTON_LEFT and event.button.state == SDL_PRESSED ){
                if ((event.button.x >= 250 || event.button.x >= 280 ) && (event.button.y >= 200 || event.button.y <= 260)){
                    std::cout<<"Ok"<<std::endl;
                    Game gr ( 600, 600, eng);
                    gr.initGame();
                    gr.loopGame();
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
