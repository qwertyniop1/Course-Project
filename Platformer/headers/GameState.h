#ifndef GAME_STATE_H
#define GAME_STATE_H 

#include "GameStateManager.h"

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

#endif



