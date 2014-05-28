#ifndef EVENTS_H
#define EVENTS_H
#include <string>
#include <vector>
#include <memory>

#include "eventelement.h"

class Events{
    std::vector< EventElement > eventContainer;
    SDL_Event evnt;
public:
    Events();
    void addEvent(const EventElement &ev);
    void ignoreEvent(int eventId);
    void activateEvent(int eventId);
    void loopEvents(int& quitStatus);
};

#endif // EVENTS_H
