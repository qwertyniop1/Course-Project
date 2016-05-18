#include "Application.h"

int Application::onExecute()
{
    if (!onInit()) {
        return -1;
    }

    stateManager.changeState(PlayState::getInstance(&stateManager));

    while (window.isOpen()) {
        sf::Event event;       

        while (window.pollEvent(event)) {            
            stateManager.onEvent(event);

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        stateManager.onLoop();

        window.clear(sf::Color::White);

        stateManager.onRender(window);

        window.display();
    }

    onCleanup();

    return 0;
}

bool Application::onInit()
{
    window.create(sf::VideoMode(600, 400), "Game");  // check    
    
    return true;
}

void Application::onCleanup()
{
    
}
