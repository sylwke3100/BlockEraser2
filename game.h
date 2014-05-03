#ifndef GAME_H
#define GAME_H
#include "blocksmanager.h"
#include "engine/engine.h"
#include "engine/graphic.h"
#include "blocksmanager.h"
#include "block.h"
#include "engine/config.h"
#include "engine/timer.h"
#include <string>

class Game{
private:
    BlocksManager * blocks;
    Engine * eng;
    Graphic * grap;
    int score = 0, lastscore = 0;
    Config *localConfig;
    Timer gameTime;
public:
    Game(Engine * e, Graphic *gr);
    void initGame();
    void actionMouse(int x, int y);
    void loopGame();
    void updateInterface();
    void updateTimer();
    void endScreen();
    ~Game();
};
#endif // GAME_H
