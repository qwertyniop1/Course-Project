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
    if (!states.top()->onInit()) {
        throw std::runtime_error("Error during loading resourses");
    }
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
        states.top()->onRender(window);
    }
    else {
        window.close(); // ???
    }
}

void GameStateManager::quit() 
{
    while (!states.empty())
    {
        states.top()->onCleanup();
        states.pop();
    }
}
