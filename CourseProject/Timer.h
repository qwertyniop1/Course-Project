#pragma once

#include "Graphic.h"

class Timer
{
public:
    Timer();
    //~Timer();

    void start();
    void stop();
    void pause();
    void unpause();

    Time getTicks();

    bool isStarted();
    bool isPaused();

private:
    Time startTick;
    Time pausedTick;

    bool started;
    bool paused;

};
