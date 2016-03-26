#include "StatePlay.h"
#include "Application.h"

bool PlayState::onInit()
{
    player = new Player(); //check
    SDL_Color color = { 28, 74, 151 }; //
    if (!player->load("res/hero.png", stateManager->game->getRenderer(), &color)) {
        return false;
    }

    player->setTextureRect(15, 5, 60, 85);  //
    player->setPosition(50, WINDOW_HEIGTH - 100);  //
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
        (*it)->move();
    }

    for (std::vector<Entity*>::iterator it = entityList.begin(); it != entityList.end(); ++it) {
        (*it)->animate();
    }
}

void PlayState::onRender()
{
    level.drawLevel(stateManager->game->getRenderer()); //tmp
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
    case SDLK_UP:
        if (player->isOnSurface()) {
            player->move(0, -30);
            player->setOnGround(false);
        }
        //     
        break;
    /*case SDLK_DOWN:
        player->move(0, 10);  //    
        break;*/
    default:
        break;
    }
}

void PlayState::onKeyUp(SDL_Keycode sym, Uint16 mod)
{
    switch (sym)
    {
    case SDLK_LEFT:
        player->move(0, 0); //
        break;
    case SDLK_RIGHT:
        player->move(0, 0);  //     
        break;
    /*case SDLK_UP:
        player->move(0, -30); //     
        break;
        /*case SDLK_DOWN:
        player->move(0, 10);  //
        break;*/
    default:
        break;
    }
}
