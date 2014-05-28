#ifndef EVENTELEMENT_H
#define EVENTELEMENT_H

#include <functional>
#include <SDL.h>
#include "position.h"

class EventElement{

private:
    bool active = true;
public:
    std::function <void(SDL_Event)> callback;
    Position pos;
    EventElement(Position element, std::function <void(SDL_Event)> cbak);
    bool isActive();
    void setStatus(bool status);

};

#endif // EVENTELEMENT_H
