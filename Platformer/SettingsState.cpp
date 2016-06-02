#include "SettingsState.h"

bool SettingsState::onInit()
{
    if (!backgroundTexture.loadFromFile("res/background.jpg")) {
        std::cout << "Can't load texture from file" << std::endl;
        return false;
    }

    setAndScale(background, backgroundTexture);

    if (!font.loadFromFile("res/comic.ttf")) {
        std::cout << "Can't load fonts" << std::endl;
        return false;
    }

    textLabel.create(L"Настройки", font);
    textLabel.setPosition((DEFAULT_WINDOW_WIDTH - textLabel.getBounds().width) / 2, 100);
    languageLabel.create(L"Язык", font);
    languageLabel.setPosition(100, 100 + 100);
    resolutionLabel.create(L"Разрешение экрана", font);
    resolutionLabel.setPosition(100, 100 + 150);
    fullscreenLabel.create(L"Полный экран", font);
    fullscreenLabel.setPosition(100, 100 + 200);

    languageButton.create(L" RUSSIAN", font);
    languageButton.setPosition(DEFAULT_WINDOW_WIDTH - 100 - languageButton.getBounds().width, 220);
    resolutionButton.create(L"", font);
    resolutionButton.setPosition(DEFAULT_WINDOW_WIDTH - 100 - resolutionButton.getBounds().width, 270);
    fullscreenButton.create(L" ", font, 0, 0, 30);
    fullscreenButton.setPosition(DEFAULT_WINDOW_WIDTH - 100 - fullscreenButton.getBounds().width, 320);

    isFullscreen = false;

    return true;
}

void SettingsState::onEvent(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::Return || event.key.code == sf::Keyboard::Escape) {
            stateManager->changeState(MenuState::getInstance(stateManager));
        }
    }

    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (fullscreenButton.select(mouse)) { isFullscreen = true; }
        }
    }
}

void SettingsState::onLoop()
{
}

void SettingsState::onRender(sf::RenderWindow & window)
{
    if (isFullscreen) {
        isFullscreen = false;
        window.create(sf::VideoMode(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT), APPLICATION_TITLE, sf::Style::Fullscreen);
    }
    mouse = sf::Mouse::getPosition(window); // Считываем координаты мыши(если че обратиться можно будет mouse.x mouse.y)
    
    window.setView(window.getDefaultView());
    window.draw(background);

    window.draw(textLabel.displayText());
    window.draw(languageLabel.displayText());
    window.draw(resolutionLabel.displayText());
    window.draw(fullscreenLabel.displayText());

    window.draw(languageButton.displayButton());
    window.draw(languageButton.displayText());
    
    window.draw(fullscreenButton.displayButton());
    window.draw(fullscreenButton.displayText());

    window.draw(resolutionButton.displayButton());
    window.draw(resolutionButton.displayText());

}

void SettingsState::onCleanup()
{
    background.setPosition(0, 0);
    textLabel.create(L"", font);
    languageLabel.create(L"", font);
    resolutionLabel.create(L"", font);
    fullscreenLabel.create(L"", font);
}
