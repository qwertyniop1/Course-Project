#ifndef APPLICATION_H
#define APPLICATION_H

#include "GameStateManager.h"
#include "IntroState.h"

class Application {
public:
    Application() {};

    int onExecute();

    bool onInit();

    void onCleanup();

private:
    sf::RenderWindow window;
    GameStateManager stateManager;
};

#endif
