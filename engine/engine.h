#ifndef ENGINE_H
#define ENGINE_H
#include "blocksmanager.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <vector>
#include <string>
#include "events.h"
#include "boost/lexical_cast.hpp"

using namespace std::placeholders;
class Engine
{
    int width;
    int height;
    BlocksManager * localblocks;
    SDL_Event event;
    std::vector<std::pair<int, int> > startBlock;
    int c = 0;
public:
    SDL_Surface * screen = NULL;
    Events globalEvents;
    Engine();
    void delay(int mil);
    int getTicks();
    void setWindowTitle(std::string title);
template <typename input, typename output>
    output convertText(const input &var);

};

#endif // ENGINE_H
