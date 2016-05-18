#pragma once

#include "GameState.h"
#include "PlayState.h"

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
    sf::Texture pointPlayTexture;
    sf::Texture pointHighscoresTexture;
    sf::Texture pointSettingsTexture;
    sf::Texture pointExitTexture;
    sf::Sprite pointPlay;
    sf::Sprite pointHighscores;
    sf::Sprite pointSettings;
    sf::Sprite pointExit;
    sf::Sprite background;
        

};
