#include "Timer.h"

Timer::Timer()
{
    startTick = 0;
    pausedTick = 0;

    started = false;
    paused = false;
}

void Timer::start()
{
    started = true;
    paused = false;

    startTick = SDL_GetTicks();
    pausedTick = 0;
}

void Timer::stop()
{
    startTick = 0;
    pausedTick = 0;

    started = false;
    paused = false;
}

void Timer::pause()
{
    if (started && !paused) {
        paused = true;

        pausedTick = SDL_GetTicks() - startTick;
        startTick = 0;
    }
}

void Timer::unpause()
{
    if (started && paused) {
        paused = false;

        startTick = SDL_GetTicks() - pausedTick;
        pausedTick = 0;
    }
}

Time Timer::getTicks()
{
    Time time = 0;

    if (started) {
        if (paused) {
            time = pausedTick;
        }
        else {
            time = SDL_GetTicks() - startTick;
        }
    }

    return time;
}

bool Timer::isStarted()
{
    return started;
}

bool Timer::isPaused()
{
    return paused;
}
