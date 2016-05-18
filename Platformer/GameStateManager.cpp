#include "GameStateManager.h"
#include "GameState.h"

GameStateManager::GameStateManager()
{
   
}

void GameStateManager::changeState(GameState *state)
{
    if (!states.empty()) {
        states.top()->onCleanup();
        states.pop();
    }
    states.push(state);
    states.top()->onInit();
}

void GameStateManager::onEvent(sf::Event event)
{
    if (!states.empty()) {
        states.top()->onEvent(event);
    }
}

void GameStateManager::onLoop()
{
    if (!states.empty()) {
        states.top()->onLoop();
    }
}

void GameStateManager::onRender(sf::RenderWindow &window)
{
    if (!states.empty()) {
        //SDL_RenderClear(game->getRenderer());
        states.top()->onRender(window);
        //SDL_RenderPresent(game->getRenderer());       
    }
}

void GameStateManager::quit() 
{
    while (!states.empty())
    {
        states.top()->onCleanup();
        states.pop();
    }
    //game->quit();
}
