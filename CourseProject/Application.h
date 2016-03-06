#pragma once

#include <SDL.h>

class Application
{
private:
    bool running;
    //
    SDL_Surface *surfDisplay;
    //
public:
    Application();
    int OnExecute();

    bool OnInit();
    void OnEvent(SDL_Event* _event);
    void OnLoop();
    void OnRender();
    void OnCleanup();

};

