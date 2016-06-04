#include "MenuState.h"

bool MenuState::onInit()
{    
    if (!backgroundTexture.loadFromFile("res/background.jpg")) {
        std::cout << "Can't load texture from file" << std::endl;
        return false;
    }
   
    setAndScale(background, backgroundTexture, stateManager->settings.getResolution().x, stateManager->settings.getResolution().y);

    if (!font.loadFromFile("res/comic.ttf")) {
        std::cout << "Can't load fonts" << std::endl;
        return false;
    }

    playButton.create(stateManager->settings.getLabel(Labels::START_GAME), font);
    playButton.setCharacterSize(70);
    playButton.setSize(playButton.getTextBounds().width + 50, 100);
    playButton.setPosition((stateManager->settings.getResolution().x - playButton.getBounds().width) / 2, 100);

    highscoresButton.create(stateManager->settings.getLabel(Labels::HIGHSCORES), font);
    highscoresButton.setCharacterSize(70);
    highscoresButton.setSize(highscoresButton.getTextBounds().width + 50, 100);
    highscoresButton.setPosition((stateManager->settings.getResolution().x - highscoresButton.getBounds().width) / 2, 200);
    
    settingsButton.create(stateManager->settings.getLabel(Labels::SETTINGS), font);
    settingsButton.setCharacterSize(70);
    settingsButton.setSize(settingsButton.getTextBounds().width + 50, 100);
    settingsButton.setPosition((stateManager->settings.getResolution().x - settingsButton.getBounds().width) / 2, 300);

    exitButton.create(stateManager->settings.getLabel(Labels::EXIT), font);
    exitButton.setCharacterSize(70);
    exitButton.setSize(exitButton.getTextBounds().width + 50, 100);
    exitButton.setPosition((stateManager->settings.getResolution().x - exitButton.getBounds().width) / 2, 400);

    return true;
}

void MenuState::onEvent(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Space) {
            //stateManager->changeState(PlayState::getInstance(stateManager));
        }
    }

    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (playButton.select(mouse)) {
                stateManager->changeState(PlayState::getInstance(stateManager));
            }
            if (highscoresButton.select(mouse)) {
                stateManager->changeState(HighscoresState::getInstance(stateManager));
            }
            if (settingsButton.select(mouse)) {
                stateManager->changeState(SettingsState::getInstance(stateManager));
            }
            if (exitButton.select(mouse)) {
                stateManager->quit();
            }
        }
    }
}

void MenuState::onLoop()
{
    
}

void MenuState::onRender(sf::RenderWindow & window)
{
    mouse = sf::Mouse::getPosition(window);

    window.setView(window.getDefaultView());
    window.draw(background);

    window.draw(playButton.displayButton());
    window.draw(playButton.displayText());
    
    window.draw(highscoresButton.displayButton());
    window.draw(highscoresButton.displayText());

    window.draw(settingsButton.displayButton());
    window.draw(settingsButton.displayText());

    window.draw(exitButton.displayButton());
    window.draw(exitButton.displayText());
}

void MenuState::onCleanup()
{

    background.setPosition(0, 0);
}
