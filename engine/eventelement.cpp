#include "eventelement.h"

EventElement::EventElement(const Position element, std::function <void(SDL_Event)>cbak): pos(element), callback(cbak){
}

bool EventElement::isActive(){
    return active;
}

void EventElement::setStatus(bool status){
    this->active = status;
}
