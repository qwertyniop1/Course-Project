#include "MenuState.h"
#include "LoadState.h"
#include "HighscoresState.h"
#include "SettingsState.h"

bool MenuState::onInit() {
    LOAD_TEXTURE(backgroundTexture.loadFromFile("res/background.jpg"));

    setAndScale(background, backgroundTexture, stateManager->settings.getResolution().x, stateManager->settings.getResolution().y);

    LOAD_FONT(font.loadFromFile("res/comic.ttf"));

    playButton.create(stateManager->settings.getLabel(Labels::START_GAME), font);
    playButton.setCharacterSize(70);
    playButton.setSize(playButton.getTextBounds().width + 50, 100);
    playButton.setPosition((stateManager->settings.getResolution().x - playButton.getBounds().width) / 2, 100);
    playButton.setFillColor(sf::Color::Transparent);
    playButton.setBoundsColor(sf::Color::Transparent);

    highscoresButton.create(stateManager->settings.getLabel(Labels::HIGHSCORES), font);
    highscoresButton.setCharacterSize(70);
    highscoresButton.setSize(highscoresButton.getTextBounds().width + 50, 100);
    highscoresButton.setPosition((stateManager->settings.getResolution().x - highscoresButton.getBounds().width) / 2, 200);
    highscoresButton.setFillColor(sf::Color::Transparent);
    highscoresButton.setBoundsColor(sf::Color::Transparent);

    settingsButton.create(stateManager->settings.getLabel(Labels::SETTINGS), font);
    settingsButton.setCharacterSize(70);
    settingsButton.setSize(settingsButton.getTextBounds().width + 50, 100);
    settingsButton.setPosition((stateManager->settings.getResolution().x - settingsButton.getBounds().width) / 2, 300);
    settingsButton.setFillColor(sf::Color::Transparent);
    settingsButton.setBoundsColor(sf::Color::Transparent);

    exitButton.create(stateManager->settings.getLabel(Labels::EXIT), font);
    exitButton.setCharacterSize(70);
    exitButton.setSize(exitButton.getTextBounds().width + 50, 100);
    exitButton.setPosition((stateManager->settings.getResolution().x - exitButton.getBounds().width) / 2, 400);
    exitButton.setFillColor(sf::Color::Transparent);
    exitButton.setBoundsColor(sf::Color::Transparent);

    stateManager->settings.playSound(Music::MENU);

    return true;
}

void MenuState::onEvent(sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (playButton.select(mouse)) {
                TRY_CHANGE_STATE(LoadState::getInstance(stateManager, 3, true));
            }
            if (highscoresButton.select(mouse)) {
                TRY_CHANGE_STATE(HighscoresState::getInstance(stateManager));
            }
            if (settingsButton.select(mouse)) {
                TRY_CHANGE_STATE(SettingsState::getInstance(stateManager));
            }
            if (exitButton.select(mouse)) {
                stateManager->quit();
            }
        }
    }
}

void MenuState::onLoop() {
    if (playButton.select(mouse)) {
        playButton.setFontColor(sf::Color::Blue);
    } else {
        playButton.setFontColor(sf::Color::White);
    }
    if (highscoresButton.select(mouse)) {
        highscoresButton.setFontColor(sf::Color::Blue);
    } else {
        highscoresButton.setFontColor(sf::Color::White);
    }
    if (settingsButton.select(mouse)) {
        settingsButton.setFontColor(sf::Color::Blue);
    } else {
        settingsButton.setFontColor(sf::Color::White);
    }
    if (exitButton.select(mouse)) {
        exitButton.setFontColor(sf::Color::Blue);
    } else {
        exitButton.setFontColor(sf::Color::White);
    }
}

void MenuState::onRender(sf::RenderWindow & window) {
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

void MenuState::onCleanup() {
    background.setPosition(0, 0);
}
