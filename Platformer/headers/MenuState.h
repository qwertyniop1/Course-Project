#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "GameState.h"
#include "Interface.h"

class MenuState : public GameState {
protected:
    MenuState(GameStateManager *manager) { stateManager = manager; };

public:
    static MenuState* getInstance(GameStateManager *manager) {
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
    sf::Font font;
    sf::Vector2i mouse;
    Button playButton, highscoresButton, settingsButton, exitButton;
};

#endif
