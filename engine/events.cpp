#include "events.h"

Events::Events(){
}

void Events::addEvent(const EventElement& ev){
    eventContainer.push_back(ev);
}

void Events::ignoreEvent(int eventId){
    eventContainer[eventId].setStatus(false);
}

void Events::activateEvent(int eventId){
    eventContainer[eventId].setStatus(true);
}

void Events::loopEvents(int &quitStatus){
    if (quitStatus != 1)
        while (SDL_PollEvent(&evnt)){
            switch(evnt.type){
            case SDL_MOUSEBUTTONDOWN:
                if (evnt.button.button == SDL_BUTTON_LEFT and evnt.button.state == SDL_PRESSED )
                    for(auto element: eventContainer){
                        if(element.isActive()){
                            if(evnt.button.x >=  element.pos.startX &&
                               evnt.button.x <=  element.pos.stopX &&
                               evnt.button.y >=  element.pos.startY &&
                               evnt.button.y <=  element.pos.stopY){
                                element.callback(evnt);
                            }

                        }
                    }
                break;
            case SDL_QUIT:
                quitStatus =1;
                break;
            }
        }
}

void Events::removeEvent(int eventId){
    eventContainer.erase(eventContainer.begin()+eventId, eventContainer.begin()+1+eventId);
}
