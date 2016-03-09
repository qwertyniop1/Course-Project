#pragma once

#include <stack>
#include "Graphic.h"
//#include "Application.h"
class Application;
class GameState;

class GameStateManager
{
public:
    GameStateManager(Application *app);

    void pushState(GameState* state);
    void popState();
    void changeState(GameState* state);

    void onEvent(SDL_Event *_event);
    void onLoop();
    void onRender();

    void quit();

private:
    std::stack<GameState* > states;

public:
    Application *game;
    
   
};
