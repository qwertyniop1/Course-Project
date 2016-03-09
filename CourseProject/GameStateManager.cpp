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
    states.top()->onEvent(_event);
}

void GameStateManager::onLoop()
{
    states.top()->onLoop();
}

void GameStateManager::onRender()
{
    states.top()->onRender();
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
