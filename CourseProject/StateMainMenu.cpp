#include "StateMainMenu.h"
#include "Application.h"
#include "StatePlay.h"

bool MainMenu::onInit()
{
    if (!background.loadTexture(stateManager->game->getRenderer(), "res/menu.png")) {
        return false;
    }

    SDL_SetRenderDrawColor(stateManager->game->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);

    return true;
}

void MainMenu::onEvent(SDL_Event * _event)
{
    Event::onEvent(_event);
}

void MainMenu::onLoop()
{
}

void MainMenu::onRender()
{   
    background.render(stateManager->game->getRenderer(), 0, 0);
}

void MainMenu::onCleanup()
{
    background.free();
}

void MainMenu::onExit() 
{
    stateManager->quit();
}

void MainMenu::onKeyDown(SDL_Keycode sym, Uint16 mod)
{
    stateManager->changeState(PlayState::getInstance(stateManager));
}