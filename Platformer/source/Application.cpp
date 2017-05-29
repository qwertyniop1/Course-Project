#include "Application.h"

int Application::onExecute() {
    if (!onInit()) {
        return EXIT_FAILURE;
    }

    try {
        stateManager.changeState(IntroState::getInstance(&stateManager, 15));
    }
    catch (std::runtime_error &err) {
        return EXIT_FAILURE;
    }

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

    return EXIT_SUCCESS;
}

bool Application::onInit()
{
    std::locale::global(std::locale(""));
    unsigned int style;
    if (stateManager.settings.isFullscreen()) {
        style = sf::Style::Fullscreen;
    } else {
        style = sf::Style::Close;
    }
    window.create(sf::VideoMode(stateManager.settings.getResolution().x, stateManager.settings.getResolution().y), APPLICATION_TITLE, style);
    window.setFramerateLimit(60);
    /*sf::Image icon;
    if (icon.loadFromFile("res/icon.jpg")) {
        window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    }*/

    return true;
}

void Application::onCleanup() {

}
