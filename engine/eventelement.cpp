#include "eventelement.h"
namespace BlockEngine{
    EventElement::EventElement(Position element, std::function<void(Position)> cbak): pos(element), callback(cbak){
    }

    bool &EventElement::isActive(){
        return active;
    }

    void EventElement::setStatus(bool status){
        this->active = status;
    }
}
