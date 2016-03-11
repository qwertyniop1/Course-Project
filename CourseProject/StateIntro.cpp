#include "StateIntro.h"
#include "Application.h"
#include "StateMainMenu.h"
bool Intro::onInit()
{
    if (!textureLogo.loadTexture(stateManager->game->getRenderer(), "res/img.png")) {
        return false;
    }
    textureLogo.setBlendMode(SDL_BLENDMODE_BLEND);

    if (!textureLoading.loadTexture(stateManager->game->getRenderer(), "res/loading.png")) {
        return false;
    }
    textureLoading.setBlendMode(SDL_BLENDMODE_BLEND);

    SDL_SetRenderDrawColor(stateManager->game->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);

    alpha = 0;
    currentTexture = &textureLogo;
    timer.start();

    return true;
}

void Intro::onEvent(SDL_Event * _event)
{
    if (_event->type == SDL_QUIT) {
        stateManager->quit();
    }
}

void Intro::onLoop()
{
    if (alpha < 255) {
        alpha++;
    }
    else {
        time = timer.getTicks();
        if (time > 12000) {
            stateManager->changeState(MainMenu::getInstance(stateManager));
        }
        currentTexture = &textureLoading;
    }
}

void Intro::onRender()
{
    currentTexture->setAlpha(alpha);
    currentTexture->render(stateManager->game->getRenderer(), 0, 0);
  
}

void Intro::onCleanup()
{
    timer.stop();
    textureLogo.free();
    textureLoading.free();   
}
