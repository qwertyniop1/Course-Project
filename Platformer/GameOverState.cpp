#include "GameOverState.h"

bool GameOverState::onInit()
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

    textLabel.create(L"»гра закончена", font);
    textLabel.setPosition((DEFAULT_WINDOW_WIDTH - textLabel.getBounds().width) / 2, DEFAULT_WINDOW_HEIGHT / 2 - 100);
    scoreLabel.create(std::to_wstring(score), font);
    scoreLabel.setPosition((DEFAULT_WINDOW_WIDTH - scoreLabel.getBounds().width) / 2, DEFAULT_WINDOW_HEIGHT / 2);
    nameField.create(font, L"Player");
    nameField.setPosition((DEFAULT_WINDOW_WIDTH - nameField.getBounds().width) / 2, DEFAULT_WINDOW_HEIGHT / 2 + 100);

        
    return true;
}

void GameOverState::onEvent(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Return || event.key.code == sf::Keyboard::Escape) {
            stateManager->changeState(HighscoresState::getInstance(stateManager));
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
