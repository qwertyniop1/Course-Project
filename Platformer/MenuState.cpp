#include "MenuState.h"

bool MenuState::onInit()
{    
    if (!backgroundTexture.loadFromFile("res/background.jpg")) {
        std::cout << "Can't load texture from file" << std::endl;
        return false;
    }

    size_t i = 1;
    for each (std::string path in menuTexturesPath) {
        menuPointTextures.push_back(new sf::Texture());
        menuPointTextures.back()->loadFromFile("res/menu/" + path);
        menuPoints.push_back(new sf::Sprite(*menuPointTextures.back()));
        menuPoints.back()->setPosition((DEFAULT_WINDOW_WIDTH - menuPoints.back()->getTextureRect().width) / 2, (i++) * 120);
    }
   
    setAndScale(background, backgroundTexture);

    currentPoint = 0;
    
    return true;
}

void MenuState::onEvent(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Space) {
            //stateManager->changeState(PlayState::getInstance(stateManager));
        }
    }
}

void MenuState::onLoop()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        switch (currentPoint) {
        case 1:
            stateManager->changeState(PlayState::getInstance(stateManager));
            break;
        case 2:
            stateManager->changeState(HighscoresState::getInstance(stateManager));
            break;
        case 3:
            stateManager->changeState(SettingsState::getInstance(stateManager));
            break;
        case 4:
            stateManager->quit();
            break;
        }
    }
}

void MenuState::onRender(sf::RenderWindow & window)
{
    window.setView(window.getDefaultView());
    window.draw(background);

    for each (sf::Sprite *sprite in menuPoints) {
        if (sf::IntRect(sprite->getGlobalBounds()).contains(sf::Mouse::getPosition(window))) {
            sprite->setColor(sf::Color::Blue);
            currentPoint = sprite->getGlobalBounds().top / 120;
        }
        else {
            sprite->setColor(sf::Color::White);
        }

        window.draw(*sprite); 
    }
}

void MenuState::onCleanup()
{
    for each (sf::Sprite *sprite in menuPoints) {
        delete sprite;
    }
    menuPoints.clear();
    for each (sf::Texture *texture in menuPointTextures) {
        delete texture;
    }
    menuPointTextures.clear();

    background.setPosition(0, 0);
}
