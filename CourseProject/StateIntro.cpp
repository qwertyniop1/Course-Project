#include "StateIntro.h"
#include "Application.h"
bool Intro::onInit()
{
    if (!textureLogo.loadTexture(stateManager->game->getRenderer(), "img.png")) {
        return false;
    }
    textureLogo.setBlendMode(SDL_BLENDMODE_BLEND);

    alpha = 0;
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
    alpha++;
}

void Intro::onRender()
{
    SDL_SetRenderDrawColor(stateManager->game->getRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(stateManager->game->getRenderer());
    textureLogo.setAlpha(alpha);
    textureLogo.render(stateManager->game->getRenderer(), 0, 0);
    SDL_RenderPresent(stateManager->game->getRenderer());
}

void Intro::onCleanup()
{
    textureLogo.free();
    //printf("FFFFFFFFFFFFFFFF");
}
