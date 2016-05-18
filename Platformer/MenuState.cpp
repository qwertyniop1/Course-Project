#include "MenuState.h"

bool MenuState::onInit()
{
    if (!backgroundTexture.loadFromFile("res/background0.png")) {
        std::cout << "Can't load texture from file" << std::endl;
        return false;
    }

    if (!pointPlayTexture.loadFromFile("res/menu/play.png")) {
        std::cout << "Can't load texture from file" << std::endl;
        return false;
    }
    if (!pointHighscoresTexture.loadFromFile("res/menu/highscores.png")) {
        std::cout << "Can't load texture from file" << std::endl;
        return false;
    }
    if (!pointSettingsTexture.loadFromFile("res/menu/settings.png")) {
        std::cout << "Can't load texture from file" << std::endl;
        return false;
    }if (!pointExitTexture.loadFromFile("res/menu/exit.png")) {
        std::cout << "Can't load texture from file" << std::endl;
        return false;
    }

    background.setTexture(backgroundTexture);

    return true;
}

void MenuState::onEvent(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Space) {
            stateManager->changeState(PlayState::getInstance(stateManager));
        }
    }
}

void MenuState::onLoop()
{
}

void MenuState::onRender(sf::RenderWindow & window)
{
    window.draw(background);
}

void MenuState::onCleanup()
{
}
