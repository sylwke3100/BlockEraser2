#include "engine.h"

Engine::Engine(){
    SDL_Init( SDL_INIT_EVERYTHING );
    SDL_ShowCursor(1);
    event = new SDL_Event;
}

void Engine::delay(int mil){
    SDL_Delay(mil);
}

void Engine::setWindowTitle(std::string title){
    SDL_WM_SetCaption(title.c_str(), "");
}

int Engine::getTicks(){
    return SDL_GetTicks();
}

void Engine::clearEvents(){
    event = new SDL_Event;
}

