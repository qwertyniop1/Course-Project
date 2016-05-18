#pragma once

#include "GameStateManager.h"
#include "Global.h"

//class GameStateManager;

class GameState
{
protected:
    GameState() {};
    virtual ~GameState() {};
    GameStateManager *stateManager;

public:
    virtual bool onInit() = 0;
    virtual void onEvent(sf::Event event) = 0;
    virtual void onLoop() = 0; 
    virtual void onRender(sf::RenderWindow &window) = 0;
    virtual void onCleanup() = 0;   

    void changeState(GameStateManager *manager, GameState *nextState)
    {
        manager->changeState(nextState);
    }
};



