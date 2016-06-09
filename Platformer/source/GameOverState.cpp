#include "GameOverState.h"
#include "HighscoresState.h" 

bool GameOverState::onInit()
{
    if (winState) {
        LOAD_TEXTURE(backgroundTexture.loadFromFile("res/win.jpg"));
    }
    else {
        LOAD_TEXTURE(backgroundTexture.loadFromFile("res/background.jpg"));
    }

    setAndScale(background, backgroundTexture, stateManager->settings.getResolution().x, stateManager->settings.getResolution().y);

    LOAD_FONT(font.loadFromFile("res/comic.ttf"));

    std::wstring label;
    if (winState)
        label = stateManager->settings.getLabel(Labels::WIN);
    else
        label = stateManager->settings.getLabel(Labels::GAME_OVER);
    textLabel.create(label, font);
    textLabel.setPosition((stateManager->settings.getResolution().x - textLabel.getBounds().width) / 2, stateManager->settings.getResolution().y / 2 - 100);
    scoreLabel.create(std::to_wstring(score), font);
    scoreLabel.setPosition((stateManager->settings.getResolution().x - scoreLabel.getBounds().width) / 2, stateManager->settings.getResolution().y / 2);
    nameField.create(font, L"Player");
    nameField.setPosition((stateManager->settings.getResolution().x - nameField.getBounds().width) / 2, stateManager->settings.getResolution().y / 2 + 100);

    if (!winState)
        stateManager->settings.playSound(Sounds::GAME_OVER_S);
    else
        stateManager->settings.playSound(Music::WINSTATE);
        
    return true;
}

void GameOverState::onEvent(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Return || event.key.code == sf::Keyboard::Escape) {
            TRY_CHANGE_STATE(HighscoresState::getInstance(stateManager));
        }
    }

    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            nameField.select(mouse);			//поле ввода
        }
    }

    if (event.type == sf::Event::TextEntered) {
        if (nameField.select()) {
            nameField.reText(event.text.unicode);
        }
    }
}

void GameOverState::onLoop()
{
}

void GameOverState::onRender(sf::RenderWindow & window)
{
    mouse = sf::Mouse::getPosition(window); // —читываем координаты мыши(если че обратитьс€ можно будет mouse.x mouse.y)

    window.setView(window.getDefaultView());
    window.draw(background);

    window.draw(textLabel.displayText());
    window.draw(scoreLabel.displayText());

    window.draw(nameField.displayButton());
    window.draw(nameField.displayText());
}

void GameOverState::onCleanup()
{
    std::wofstream outputFile;
    outputFile.open("res/scores.dat", std::ios::app);

    outputFile << nameField.readText() << std::endl;
    outputFile << score << std::endl;

    outputFile.close(); 
    
    background.setPosition(0, 0);
    textLabel.create(L"", font);
    scoreLabel.create(L"", font);
}
