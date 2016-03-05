#pragma once

#include <SDL.h>

class Application
{
public:
    Application();
    int OnExecute();

    bool OnInit();
    void OnEvent(SDL_Event* _event);
    void OnLoop();
    void OnRender();
    void OnCleanup();

};

