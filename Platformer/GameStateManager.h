#pragma once

#include <stack>
#include "Global.h"
#include "Settings.h"

class GameState;

class GameStateManager
{
public:
    GameStateManager();

    void pushState(GameState *state);
    void popState();
    void changeState(GameState *state);

    void onEvent(sf::Event event);
    void onLoop();
    void onRender(sf::RenderWindow &window);

    void quit();

    Settings settings;

private:
    std::stack<GameState*> states;   
   
};
