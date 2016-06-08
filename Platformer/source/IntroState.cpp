#include "IntroState.h"

bool IntroState::onInit()
{
    LOAD_TEXTURE(logo1.loadFromFile("res/bsuir.jpg"));
    LOAD_TEXTURE(logo2.loadFromFile("res/logo.png"));

    setAndScale(background, logo1, stateManager->settings.getResolution().x, stateManager->settings.getResolution().y);

    alpha = 0;
    sf::Color color = background.getColor();
    background.setColor(sf::Color(color.r, color.g, color.b, alpha));
    change = false;

    stateManager->settings.playSound(Music::INTRO);

    return true;
}

void IntroState::onEvent(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::Return || event.key.code == sf::Keyboard::Escape) {
            TRY_CHANGE_STATE(LoadState::getInstance(stateManager, 5));
        }
    }
}

void IntroState::onLoop()
{
    double time = timer.getElapsedTime().asSeconds();
    if (time > duration) {
        TRY_CHANGE_STATE(LoadState::getInstance(stateManager, 5));
    }

    if (time > 2) {
        sf::Color color = background.getColor();
        background.setColor(sf::Color(color.r, color.g, color.b, alpha));
        if (alpha < 255)
            alpha++;
    }
    if (time > 10 && !change) {
        change = true;
        alpha = 0;
        background.setTexture(logo2, true);
        sf::Color color = background.getColor();
        background.setColor(sf::Color(color.r, color.g, color.b, alpha));
        background.setScale(2, 2);
        background.setPosition((stateManager->settings.getResolution().x - background.getGlobalBounds().width) / 2, (stateManager->settings.getResolution().y - background.getGlobalBounds().height) / 2);
    }
}

void IntroState::onRender(sf::RenderWindow & window)
{
    window.draw(background);
}

void IntroState::onCleanup()
{
    stateManager->settings.stopMusic();
}
