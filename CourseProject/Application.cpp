#include "Application.h"
#include <stack>
Application::Application()
{
    running = true;
    stateManager = new GameStateManager(this);
}

int Application::onExecute()
{
    if (onInit() == false) {
        return -1;
    }

    SDL_Event Event;
       
    stateManager->changeState(Intro::getInstance(stateManager));

    while (running) {
       while (SDL_PollEvent(&Event)) {
            stateManager->onEvent(&Event);
        }
        stateManager->onLoop();
        stateManager->onRender();
    }

    onCleanup();

    return 0;
}

int main(int argc, char* argv[])
{
    Application application;

    return application.onExecute();    
}
