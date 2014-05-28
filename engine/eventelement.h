#ifndef EVENTELEMENT_H
#define EVENTELEMENT_H

#include <functional>
#include <SDL.h>
#include "position.h"

class EventElement{

private:
    bool active = true;
public:
    Position pos;
    std::function <void(Position)> callback;
    EventElement(Position element, std::function <void(Position)> cbak);
    bool isActive();
    void setStatus(bool status);

};

#endif // EVENTELEMENT_H
