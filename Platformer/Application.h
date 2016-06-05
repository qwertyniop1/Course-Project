#pragma once
#include <iostream>

#include "Global.h"
#include "GameStateManager.h"

#include "LoadState.h"

class Application
{
public:
    Application() {};

    int onExecute();

    bool onInit();

    void onCleanup();

private:
    sf::RenderWindow window;

    GameStateManager stateManager;

};

