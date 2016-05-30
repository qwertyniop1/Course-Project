#pragma once

#include "GameState.h"
#include "PlayState.h"
#include "HighscoresState.h"

class MenuState : public GameState
{
protected:
    MenuState(GameStateManager *manager) { stateManager = manager; };

public:
    static MenuState* getInstance(GameStateManager *manager)
    {
        static MenuState self(manager);
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

    std::vector<sf::Texture*> menuPointTextures;
    std::vector<sf::Sprite*> menuPoints;

    size_t currentPoint;
  
        

};
