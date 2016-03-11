#include "GameStateManager.h"
#include "GameState.h"
#include "Application.h"

GameStateManager::GameStateManager(Application * app)
{
    game = app;
}

void GameStateManager::changeState(GameState * state)
{
    if (!states.empty()) {
        states.top()->onCleanup();
        states.pop();
    }
    states.push(state);
    states.top()->onInit();
}

void GameStateManager::onEvent(SDL_Event * _event)
{
    if (!states.empty()) {
        states.top()->onEvent(_event);
    }
}

void GameStateManager::onLoop()
{
    if (!states.empty()) {
        states.top()->onLoop();
    }
}

void GameStateManager::onRender()
{
    if (!states.empty()) {
        SDL_RenderClear(game->getRenderer());
        states.top()->onRender();
        SDL_RenderPresent(game->getRenderer());       
    }
}

void GameStateManager::quit() // delete
{
    while (!states.empty())
    {
        states.top()->onCleanup();
        states.pop();
    }
    game->quit();
}
