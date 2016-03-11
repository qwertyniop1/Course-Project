#include "StatePlay.h"
#include "Application.h"

bool PlayState::onInit()
{
    player = new Entity(); //check
    if (!player->load("res/hero.png", stateManager->game->getRenderer())) {
        return false;
    }

    player->setTextureRect(0, 0, 60, 85);  //
    player->setPosition(150, 150);  //
    player->setMaxFrame(6);
    player->setAnimState(1);

    entityList.push_back(player);

    return true;
}

void PlayState::onEvent(SDL_Event * _event)
{
    Event::onEvent(_event);
}

void PlayState::onLoop()
{
    for (std::vector<Entity*>::iterator it = entityList.begin(); it != entityList.end(); ++it) {
        (*it)->animate();
    }
}

void PlayState::onRender()
{
    for (std::vector<Entity*>::iterator it = entityList.begin(); it != entityList.end(); ++it) {
        (*it)->render(stateManager->game->getRenderer());
    }
}

void PlayState::onCleanup()
{
    for each (Entity *entity in entityList) {
        entity->cleanup();
    }
}

void PlayState::onExit()
{
    stateManager->quit();
}

void PlayState::onKeyDown(SDL_Keycode sym, Uint16 mod)
{
    switch (sym)
    {
    case SDLK_LEFT:
        player->move(-10, 0); //
        break;
    case SDLK_RIGHT:
        player->move(10, 0);  //
        break;
    default:
        break;
    }
}
