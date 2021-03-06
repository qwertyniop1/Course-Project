#include "SettingsState.h"
#include "MenuState.h"

bool SettingsState::onInit() {
    LOAD_TEXTURE(backgroundTexture.loadFromFile("res/background.jpg"));

    setAndScale(background,
                backgroundTexture,
                stateManager->settings.getResolution().x,
                stateManager->settings.getResolution().y);

    LOAD_FONT(font.loadFromFile("res/comic.ttf"));

    textLabel.create(stateManager->settings.getLabel(Labels::SETTINGS), font);
    textLabel.setPosition((stateManager->settings.getResolution().x - textLabel.getBounds().width) / 2, 100);
    languageLabel.create(stateManager->settings.getLabel(Labels::LANGUAGE), font);
    languageLabel.setPosition(100, 100 + 100);
    resolutionLabel.create(stateManager->settings.getLabel(Labels::RESOLUTION), font);
    resolutionLabel.setPosition(100, 100 + 150);
    fullscreenLabel.create(stateManager->settings.getLabel(Labels::FULLSCREEN), font);
    fullscreenLabel.setPosition(100, 100 + 200);
    soundLabel.create(stateManager->settings.getLabel(Labels::SOUND), font);
    soundLabel.setPosition(100, 100 + 250);
    musicLabel.create(stateManager->settings.getLabel(Labels::MUSIC), font);
    musicLabel.setPosition(100, 100 + 300);

    std::wstring label = L" " + stateManager->settings.getLanguage();
    languageButton.create(label, font);
    languageButton.setPosition(stateManager->settings.getResolution().x - 100 - languageButton.getBounds().width, 220);
    label = std::to_wstring(stateManager->settings.getResolution().x) + L" x " + std::to_wstring(stateManager->settings.getResolution().y);
    resolutionButton.create(label, font);
    resolutionButton.setPosition(stateManager->settings.getResolution().x - 100 - resolutionButton.getBounds().width, 270);
    if (stateManager->settings.isFullscreen())
        label = L" X ";
    else
        label = L" ";
    fullscreenButton.create(label, font, 0, 0, 30);
    fullscreenButton.setPosition(stateManager->settings.getResolution().x - 100 - fullscreenButton.getBounds().width, 320);
    if (stateManager->settings.isSound())
        label = L" X ";
    else
        label = L" ";
    soundButton.create(label, font, 0, 0, 30);
    soundButton.setPosition(stateManager->settings.getResolution().x - 100 - fullscreenButton.getBounds().width, 370);
    if (stateManager->settings.isMusic())
        label = L" X ";
    else
        label = L" ";
    musicButton.create(label, font, 0, 0, 30);
    musicButton.setPosition(stateManager->settings.getResolution().x - 100 - fullscreenButton.getBounds().width, 420);

    return true;
}

void SettingsState::onEvent(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Space
            || event.key.code == sf::Keyboard::Return
            || event.key.code == sf::Keyboard::Escape) {
            TRY_CHANGE_STATE(MenuState::getInstance(stateManager));
        }
    }

    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (languageButton.select(mouse)) {
                stateManager->settings.changeLanguage();
                languageButton.setText(stateManager->settings.getLanguage());
                stateManager->changeState(this);
            }
            if (resolutionButton.select(mouse)) {
                changeResolution = true;
                stateManager->settings.changeResolution();
                resolutionButton.setText(std::to_wstring(stateManager->settings.getResolution().x)
                    + L" x "
                    + std::to_wstring(stateManager->settings.getResolution().y));
                stateManager->changeState(this);
            }
            if (fullscreenButton.select(mouse)) {
                changeFullscreen = true;
                stateManager->settings.switchFullscreen();
                if (stateManager->settings.isFullscreen())
                    fullscreenButton.setText(L" X ");
                else
                    fullscreenButton.setText(L" ");
            }
            if (soundButton.select(mouse)) {
                stateManager->settings.switchSound();
                if (stateManager->settings.isSound())
                    soundButton.setText(L" X ");
                else
                    soundButton.setText(L" ");
            }
            if (musicButton.select(mouse)) {
                stateManager->settings.switchMusic();
                if (stateManager->settings.isMusic()) {
                    musicButton.setText(L" X ");
                    stateManager->settings.playSound(Music::MENU);
                }
                else {
                    musicButton.setText(L" ");
                    stateManager->settings.stopMusic();
                }
            }
        }
    }
}

void SettingsState::onLoop() {

}

void SettingsState::onRender(sf::RenderWindow & window) {
    if (changeResolution) {
        changeResolution = false;
        unsigned int style;
        if (stateManager->settings.isFullscreen()) {
            style = sf::Style::Fullscreen;
        } else {
            style = sf::Style::Close;
        }
        window.create(sf::VideoMode(stateManager->settings.getResolution().x,
                                    stateManager->settings.getResolution().y),
                      APPLICATION_TITLE, style);
    }
    if (changeFullscreen) {
        changeFullscreen = false;
        unsigned int style;
        if (stateManager->settings.isFullscreen()) {
            style = sf::Style::Fullscreen;
        } else {
            style = sf::Style::Close;
        }
        window.create(sf::VideoMode(stateManager->settings.getResolution().x,
                                    stateManager->settings.getResolution().y),
                      APPLICATION_TITLE, style);
    }
    mouse = sf::Mouse::getPosition(window);

    window.setView(window.getDefaultView());
    window.draw(background);

    window.draw(textLabel.displayText());
    window.draw(languageLabel.displayText());
    window.draw(resolutionLabel.displayText());
    window.draw(fullscreenLabel.displayText());
    window.draw(soundLabel.displayText());
    window.draw(musicLabel.displayText());

    window.draw(languageButton.displayButton());
    window.draw(languageButton.displayText());

    window.draw(fullscreenButton.displayButton());
    window.draw(fullscreenButton.displayText());

    window.draw(resolutionButton.displayButton());
    window.draw(resolutionButton.displayText());

    window.draw(soundButton.displayButton());
    window.draw(soundButton.displayText());

    window.draw(musicButton.displayButton());
    window.draw(musicButton.displayText());
}

void SettingsState::onCleanup() {
    background.setPosition(0, 0);
    textLabel.create(L"", font);
    languageLabel.create(L"", font);
    resolutionLabel.create(L"", font);
    fullscreenLabel.create(L"", font);
}
