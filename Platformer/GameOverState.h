#pragma once

#include "GameState.h"

class GameOverState : public GameState
{
protected:
    GameOverState(GameStateManager *manager) { stateManager = manager; };

public:
    static GameOverState* getInstance(GameStateManager *manager)
    {
        static GameOverState self(manager);
        return &self;
    }

    bool onInit();
    void onEvent(sf::Event event);
    void onLoop();
    void onRender(sf::RenderWindow &window);
    void onCleanup();

private:
    sf::Texture backgroundTexture;
    sf::Sprite background;

};
