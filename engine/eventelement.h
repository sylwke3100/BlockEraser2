#ifndef EVENTELEMENT_H
#define EVENTELEMENT_H

#include <functional>
#include <SDL.h>

struct Position {
    int startX = -1;
    int startY = -1;
    int stopX  = -1;
    int stopY  = -1;
};

class EventElement
{

private:
    bool active = true;
public:
    std::function <void(SDL_Event)> callback;
    Position pos;
    EventElement(const Position element, std::function <void(SDL_Event)>cbak);
    bool isActive();
    void setStatus(bool status);

};

#endif // EVENTELEMENT_H
