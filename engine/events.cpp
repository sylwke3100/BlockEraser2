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

void Events::loopEvents(){
    int quit = 0;
    if (quit != 1)
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
                quit =1;
                break;
            }
        }
}
