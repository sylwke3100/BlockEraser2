#ifndef ENGINE_H
#define ENGINE_H
#include <SDL.h>
#include <SDL_ttf.h>
#include <vector>
#include <string>
#include "events.h"
#include "boost/lexical_cast.hpp"
#include <cstddef>

using namespace std::placeholders;
class Engine{
    int width;
    int height;
    std::vector<std::pair<int, int> > startBlock;
    int c = 0;
public:
    SDL_Event *event;
    SDL_Surface * screen = NULL;
    Events globalEvents;
    Engine();
    void delay(int mil);
    int getTicks();
    void setWindowTitle(std::string title);
    void clearEvents();
};

#endif // ENGINE_H
