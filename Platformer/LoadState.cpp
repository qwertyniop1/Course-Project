#include "LoadState.h"

bool LoadState::onInit()
{
    if (!backgroundTexture.loadFromFile("res/loading.jpg")) {
        std::cout << "Can't load texture from file" << std::endl;
        return false;
    }

    setAndScale(background, backgroundTexture, stateManager->settings.getResolution().x, stateManager->settings.getResolution().y);

    if (!font.loadFromFile("res/comic.ttf")) {
        std::cout << "Can't load fonts" << std::endl;
        return false;
    }

    textLabel.create(stateManager->settings.getLabel(Labels::LOADING), font);
    textLabel.setPosition((stateManager->settings.getResolution().x - textLabel.getBounds().width) / 2, stateManager->settings.getResolution().y - 150);
    textLabel.setFontColor(sf::Color::Blue);

    if (!playerTexture.loadFromFile("res/aladdin.png")) {
        std::cout << "Can't load texture from file" << std::endl;
        return false;
    }
    playerAnimation.loadFromXML("res/aladdin.xml", playerTexture); 
    playerAnimation.set("walk");

    timer.restart();

    return true;
}

void LoadState::onEvent(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Space) {
        }
    }
}

void LoadState::onLoop()
{
    double time = clock.getElapsedTime().asMicroseconds();
    clock.restart();
    time /= 600;
    playerAnimation.tick(time);

    time = timer.getElapsedTime().asSeconds();
    if (time > duration) {
        stateManager->changeState(MenuState::getInstance(stateManager));
    }
}

void LoadState::onRender(sf::RenderWindow & window)
{
    window.setView(window.getDefaultView());

    window.draw(background);

    window.draw(textLabel.displayText());

    playerAnimation.draw(window, stateManager->settings.getResolution().x - 150, stateManager->settings.getResolution().y - 100);
}

void LoadState::onCleanup()
{
    background.setPosition(0, 0);
    textLabel.setText(L"");
}
