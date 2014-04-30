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
    Timer * gameTime;
public:
    Game(int x, int y);
    void initGame();
    void actionMouse(int x, int y);
    void activateKeyControl();
    void updateInterface();
    void updateTimer();
    void endScreen();
};
#endif // GAME_H
