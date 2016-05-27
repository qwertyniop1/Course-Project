#include "GameOverState.h"

bool GameOverState::onInit()
{
    if (!backgroundTexture.loadFromFile("res/background0.png")) {
        std::cout << "Can't load texture from file" << std::endl;
        return false;
    }

    background.setTexture(backgroundTexture);


    if (!font.loadFromFile("res/arial.ttf")) {
        std::cout << "Can't load fonts" << std::endl;
        return false;
    }

    text.setFont(font);
    text.setCharacterSize(48);
    text.setColor(sf::Color::Black); std::cout << text.getString().toAnsiString().c_str() << std::endl;
    text.setString("GAME OVER"); // TODO encoding
    text.setPosition((DEFAULT_WINDOW_WIDTH - text.getGlobalBounds().width) / 2, DEFAULT_WINDOW_HEIGHT / 2 - 100); std::cout << text.getString().toAnsiString().c_str() << std::endl;
    scoreText.setFont(font);
    scoreText.setCharacterSize(48);
    scoreText.setColor(sf::Color::Black); std::cout << scoreText.getString().toAnsiString().c_str() << std::endl;
    scoreText.setString(std::to_string(score)); std::cout << scoreText.getString().toAnsiString().c_str() << std::endl;
    scoreText.setPosition((DEFAULT_WINDOW_WIDTH - scoreText.getGlobalBounds().width) / 2, DEFAULT_WINDOW_HEIGHT / 2 - 50);
        
    return true;
}

void GameOverState::onEvent(sf::Event event)
{
    if (event.type == sf::Event::Closed) {
        stateManager->quit();
    }

    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::Return || event.key.code == sf::Keyboard::Escape) {
            stateManager->changeState(MenuState::getInstance(stateManager));
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

    window.draw(text);
    window.draw(scoreText);
}

void GameOverState::onCleanup()
{
    std::ofstream outputFile;
    outputFile.open("res/scores.dat", std::ios::app);

    outputFile << "Vitaly" << std::endl;
    outputFile << score << std::endl;

    outputFile.close(); text.setString("");
}
