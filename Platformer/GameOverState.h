#pragma once

#include "GameState.h"
#include "HighscoresState.h" 
#include "Interface.h"

#include <fstream>

//
// TODO ���� ��� ����� �����

class GameOverState : public GameState
{
protected:
    GameOverState(GameStateManager *manager) { stateManager = manager; };

public:
    static GameOverState* getInstance(GameStateManager *manager, size_t score)
    {
        static GameOverState self(manager);
        self.score = score;
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
};

