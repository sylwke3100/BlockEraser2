#ifndef ENGINE_H
#define ENGINE_H
#include <SDL.h>
#include <SDL_ttf.h>
#include <vector>
#include <string>
#include "events.h"
#include "boost/lexical_cast.hpp"
#include <cstddef>

class Engine{
    std::vector<std::pair<int, int> > startBlock;
public:
    SDL_Event *event;
    SDL_Surface * screen = NULL;
    Events globalEvents;
    Engine();
    static void delay(int mil);
    static int getTicks();
    static void setWindowTitle(std::string title);
    void clearEvents();
};

#endif // ENGINE_H
