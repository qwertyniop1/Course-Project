#pragma once

#include "MenuState.h" 

class LoadState : public GameState
{
protected:
    LoadState(GameStateManager *manager) { stateManager = manager; };

public:
    static LoadState* getInstance(GameStateManager *manager)
    {
        static LoadState self(manager);
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

    sf::Font font;

    Label textLabel;
   
    sf::Texture playerTexture;
    AnimationManager playerAnimation;
    sf::Clock clock, timer;

};
