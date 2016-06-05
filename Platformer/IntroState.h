#pragma once

#include "LoadState.h"

class IntroState : public GameState
{
protected:
    IntroState(GameStateManager *manager) { stateManager = manager; };

public:
    static IntroState* getInstance(GameStateManager *manager, double duration)
    {
        static IntroState self(manager);
        self.duration = duration;
        return &self;
    }

    bool onInit();
    void onEvent(sf::Event event);
    void onLoop();
    void onRender(sf::RenderWindow &window);
    void onCleanup();

private:
    sf::Texture logo1, logo2;
    sf::Sprite background;

    sf::Clock timer;
    double duration;

    bool change;
    sf::Uint8 alpha;
};
