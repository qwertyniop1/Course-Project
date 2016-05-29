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

    textLabel.create("Game over", font);
    textLabel.setPosition((DEFAULT_WINDOW_WIDTH - textLabel.getBounds().width) / 2, DEFAULT_WINDOW_HEIGHT / 2 - 100);
    scoreLabel.create(std::to_string(score), font);
    scoreLabel.setPosition((DEFAULT_WINDOW_WIDTH - scoreLabel.getBounds().width) / 2, DEFAULT_WINDOW_HEIGHT / 2);

    //text.setString("Игра закончена"); // TODO encoding
        
    return true;
}

void GameOverState::onEvent(sf::Event event)
{
    if (event.type == sf::Event::Closed) {
        stateManager->quit();
    }

    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::Return || event.key.code == sf::Keyboard::Escape) {
            stateManager->changeState(HighscoresState::getInstance(stateManager));
        }
    }
}

void GameOverState::onLoop()
{
}

void GameOverState::onRender(sf::RenderWindow & window)
{
    window.setView(window.getDefaultView());
    window.draw(background);

    window.draw(textLabel.displayText());
    window.draw(scoreLabel.displayText());
}

void GameOverState::onCleanup()
{
    std::ofstream outputFile;
    outputFile.open("res/scores.dat", std::ios::app);

    outputFile << "Vitaly" << std::endl;
    outputFile << score << std::endl;

    outputFile.close(); 
    
    background.setPosition(0, 0);
    textLabel.create("", font);
    scoreLabel.create("", font);
}
