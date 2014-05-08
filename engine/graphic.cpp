#include "graphic.h"


Graphic::Graphic(int width,
                 int height){
     screen = SDL_SetVideoMode( width, height, 32, SDL_HWSURFACE );
     TTF_Init();
}

void Graphic::drawText(short int x,
                       short int y,
                       std::string text,
                       int fontSize){
    TTF_Font* font = TTF_OpenFont("arial.ttf", fontSize);
    if(font){
        SDL_Color  background= { 0, 0, 0, 0 };
        SDL_Color  foreground= { 255, 255, 255, 0 };
        SDL_Surface* textSurface = TTF_RenderText_Shaded(font, text.c_str(),
                                                        foreground, background);
        SDL_Rect textPosition = { x, y, 0, 0 };
        SDL_BlitSurface(textSurface, NULL, screen, &textPosition);
        SDL_FreeSurface(textSurface);
        TTF_CloseFont(font);
    }
}
void Graphic::clearAll(){
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format , 0 , 0 , 0 ));
}

void Graphic::drawBlock(int x,
                        int y,
                        int height,
                        int width,
                        RGBColor Color){
    SDL_Rect* kwadrat = new SDL_Rect;
    kwadrat->h = height;
    kwadrat->w = width;
    kwadrat->x = x;
    kwadrat->y = y;
    SDL_FillRect(screen, kwadrat, SDL_MapRGB(screen->format , Color.first, Color.second, Color.third));
    delete kwadrat;
}

void Graphic::render(){
    SDL_Flip( screen );
}
