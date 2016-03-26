#pragma once

#include "Graphic.h"
//#include "GameStateManager.h"

#include "StateIntro.h"
#include "StateMainMenu.h" //tmp


class Application
{
private:
    bool running;

    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

    GameStateManager *stateManager = nullptr;
   
  
public:
    Application();
    int onExecute();

    bool onInit();   
    void onCleanup();

    void quit();

    SDL_Renderer* getRenderer();  // tmp

};

