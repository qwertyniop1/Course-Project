#pragma once

#include "GameState.h"
#include "MenuState.h" // highsores state

#include <fstream>

//
// TODO Поле для ввода имени

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
    sf::Text text;
    sf::Text scoreText;

};

//const size_t MAX_NAME_LENGTH = 256;

struct HighscoreNode {
    std::string name;
    size_t score;
    //date
};
