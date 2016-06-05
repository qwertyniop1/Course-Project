#pragma once

#include "GameState.h"
#include "HighscoresState.h" 
#include "Interface.h"

#include <fstream>

class GameOverState : public GameState
{
protected:
    GameOverState(GameStateManager *manager) { 
        stateManager = manager; 
        winState = false;
    };

public:
    static GameOverState* getInstance(GameStateManager *manager, size_t score, bool isWin = false)
    {
        static GameOverState self(manager);
        self.score = score;
        self.winState = isWin;
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

    size_t score;
    sf::Font font;
    Label textLabel;
    Label scoreLabel;
    Input nameField;

    sf::Vector2i mouse;

    bool winState;
};

