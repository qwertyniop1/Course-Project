#include "Application.h"

int Application::onExecute()
{
    if (!onInit()) {
        return -1;
    }

    stateManager.changeState(MenuState::getInstance(&stateManager));

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
    std::locale::global(std::locale("Russian_Russia"));
    window.create(sf::VideoMode(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT), APPLICATION_TITLE, sf::Style::Close);  
    //window.setVerticalSyncEnabled(true);
    //window.create(sf::VideoMode(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT), APPLICATION_TITLE, sf::Style::Fullscreen);    

    return true;
}

void Application::onCleanup()
{
    
}
