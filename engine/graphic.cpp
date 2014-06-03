#include "graphic.h"

Graphic::Graphic(int width,
                 int height,
                 SDL_Window* window){
    window = SDL_CreateWindow("BlockEraser2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    screen = SDL_GetWindowSurface(window);
    if (TTF_Init() == -1)
      throw std::runtime_error("TTF Init Failed");
}

void Graphic::drawText(short int x,
                       short int y,
                       std::string text,
                       int fontSize){
    TTF_Font* font = TTF_OpenFont("arial.ttf", fontSize);
    if(font != nullptr){
        SDL_Color  foreground= { 255, 255, 255, 0};
        SDL_Surface* textSurface =  TTF_RenderUTF8_Blended(font, text.c_str(),
                                                        foreground);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textSurface);
        int s = text.length()* 7;
        SDL_Rect textPosition = { x, y, s, fontSize };
        SDL_RenderCopy(renderer, texture, NULL, &textPosition);
        SDL_RenderPresent(renderer );
        SDL_DestroyTexture(texture);
        SDL_FreeSurface(textSurface);
        TTF_CloseFont(font);
    }
    else
        throw std::runtime_error(TTF_GetError());
}
void Graphic::clearAll(){
    SDL_SetRenderDrawColor(renderer, 0, 0 ,0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer );
}

void Graphic::drawBlock(int x,
                        int y,
                        int height,
                        int width,
                        RGBColor color){
    SDL_Rect kwadrat = {(short) x  , (short)y , (unsigned short) width, (unsigned short) height};
    blockList.push_back( graphicBlock(color ,kwadrat) );
}

void Graphic::render(){
    for(auto element:blockList){
        SDL_SetRenderDrawColor(renderer, element.color.first, element.color.second, element.color.third, 255);
        SDL_RenderFillRect(renderer, &element.square);
        SDL_RenderDrawRect(renderer, &element.square);
    }
    blockList.clear();
    SDL_RenderPresent(renderer );
}

Graphic::~Graphic(){
    SDL_DestroyRenderer(renderer);
}
