#include "StatePlay.h"
#include "Application.h"

bool PlayState::onInit()
{
    Entity *player = new Entity();
    if (!player->load("res/foo.png", stateManager->game->getRenderer())) {
        return false;
    }

    entityList.push_back(player);

    return true;
}

void PlayState::onEvent(SDL_Event * _event)
{
    Event::onEvent(_event);
}

void PlayState::onLoop()
{
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
