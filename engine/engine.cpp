#include "engine.h"

Engine::Engine(){
    SDL_Init( SDL_INIT_EVERYTHING );
    SDL_ShowCursor(1);
}

void Engine::delay(int mil){
    SDL_Delay(mil);
}

void Engine::setWindowTitle(std::string title){
    SDL_WM_SetCaption(title.c_str(), "");
}

template<typename input, typename output>
output Engine::convertText(const input &var){
    return boost::lexical_cast<output>(var);
}

int Engine::getTicks(){
    return SDL_GetTicks();
}
