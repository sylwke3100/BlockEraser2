#include "timer.h"

Timer::Timer(int gameTickTime): tickTime(gameTickTime){

}

void Timer::start(){
    status = 1;
    startTime = (int)SDL_GetTicks();
}

void Timer::stop(){
    status = 0;
    startTime = 0;
}

void Timer::set(int time){
    tickTime = time;
}

int Timer::getTimeToEnd(){
    int cTime = SDL_GetTicks();
    tickTime -=  (  cTime - startTime );
    startTime = cTime;
    return tickTime;
}

bool Timer::getStatus(){
    return status;
}
