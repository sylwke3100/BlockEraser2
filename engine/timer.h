#ifndef TIMER_H
#define TIMER_H

#include <SDL.h>

class Timer
{
    int startTime = 0;
    int tickTime = 0;
    bool status = 0;
public:
    Timer();
    void start();
    void stop();
    void set(int time);
    int getTimeToEnd();
    bool getStatus();
};

#endif // TIMER_H
