#include "GameOverState.h"

bool GameOverState::onInit()
{
    if (!backgroundTexture.loadFromFile("res/background0.png")) {
        std::cout << "Can't load texture from file" << std::endl;
        return false;
    }

    background.setTexture(backgroundTexture);
    
    return true;
}

void GameOverState::onEvent(sf::Event event)
{
    if (event.type == sf::Event::Closed) {
        stateManager->quit();
    }
}

void GameOverState::onLoop()
{
}

void GameOverState::onRender(sf::RenderWindow & window)
{
    window.setView(window.getDefaultView());
    window.draw(background);
}

void GameOverState::onCleanup()
{
}
