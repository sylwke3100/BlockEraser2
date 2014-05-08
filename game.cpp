#include "game.h"

using namespace std;


Game::Game(Engine * e, Graphic * gr): eng (e), grap(gr){
    localConfig = new Config ("game.cfg");
    localConfig->parse();
    eng-> setWindowTitle( localConfig->getStringValue("title_Game","BlockEraser2").c_str() );
    blocks = new BlocksManager(20, 20);
}

void Game::updateTimer(){
    grap->drawBlock(localConfig->getIntValue("time_bar_x", 0), localConfig->getIntValue("time_bar_y", 0), 10, 400, blocks->colorTable[0]);
    grap->drawBlock(localConfig->getIntValue("time_bar_x", 0), localConfig->getIntValue("time_bar_y", 0), 10, gameTime.getTimeToEnd() / 100, blocks->colorTable[localConfig->getIntValue("time_bar_color", 4)]);
    grap->render();
}

void Game::updateInterface(){
    grap->clearAll();
    int startPosX = 0, startPosY = 100;
    for(auto&& y :blocks->tableBlocks){
        for(auto&& x:y){
            grap->drawBlock(startPosX, startPosY, 20, 20, x);
            startPosX = startPosX + 25;
        }
        startPosY = startPosY + 25;
        startPosX = 0;
    }
    grap->drawText(10, 15, localConfig->getStringValue("score_bar_label", "Score: ") + boost::lexical_cast<std::string>(score* localConfig->getIntValue("p_score", 10)), 17);
    grap->render();
}
void Game::endScreen(){
    grap->clearAll();
    grap->drawText(250, 200, "Koniec Gry", 22);
    grap->drawText(280, 250, "Wynik: "+ boost::lexical_cast<std::string>(score*10), 16);
    grap->render();
}

void Game::initGame(){
    blocks->initGame();
    updateInterface();
    gameTime.set(localConfig->getIntValue("time", 40000));

}

void Game::actionMouse(int x,
                       int y){
    if (y>= 100){
        y = y - 100;
        int curentX = x % 25, curentY = y % 25;
        if (curentX < 20 && curentY < 20){
            blocks->searchNeighborhood(x/25, y/25, score);
            if (score - lastscore > localConfig->getIntValue("add_count_combination", 6 )){
                gameTime.set( gameTime.getTimeToEnd() + (score - lastscore)* localConfig->getIntValue("add_time_combination", 50) ) ;
            }
            if (score - lastscore > 2)
                updateInterface();
            lastscore = score;
        }
    }
}

void Game::loopGame(){
    int quit = 0;
    while (!quit){
        if (gameTime.getTimeToEnd() == 0 && gameTime.getStatus() == false)
            gameTime.start();
        else {
            updateTimer();
            if (gameTime.getTimeToEnd() <= 0 && gameTime.getStatus() == true){
                gameTime.stop();
                endScreen();
                eng->delay(2000);
                quit = 1;
                break;
            }
        }
        if (quit != 1)
            while (SDL_PollEvent(eng->event)){
                switch(eng->event->type){
                case SDL_MOUSEBUTTONDOWN:
                    if (eng->event->button.button == SDL_BUTTON_LEFT and eng->event->button.state == SDL_PRESSED )
                        actionMouse(eng->event->button.x, eng->event->button.y );
                    break;
                case SDL_QUIT:
                    quit =1;
                    break;
                }
            }
    }
}

Game::~Game(){
    delete localConfig;
}
