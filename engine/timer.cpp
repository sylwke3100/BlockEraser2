#include "timer.h"

Timer::Timer(){
}

void Timer::start(){
    status = 1;
    startTime = (int)SDL_GetTicks();
}

void Timer::stop(){
    status = 0;
    startTime = 0;
    tickTime = 0;
}

void Timer::set(int time){
    tickTime = time;
}

int Timer::getTimeToEnd(){
    if (status){
        int cTime = SDL_GetTicks();
        tickTime -=  (  cTime - startTime );
        startTime = cTime;
        return tickTime;
    }
    else
        return 0;

}

bool Timer::getStatus(){
    return status;
}
