#include "StatePlay.h"
#include "Application.h"

bool PlayState::onInit()
{
    levelManager.currentLevel = new Level(stateManager->game->getRenderer());
    levelManager.player = new Player(); //check
    SDL_Color color = { 28, 74, 151 }; //
    if (!levelManager.player->load("res/hero.png", stateManager->game->getRenderer(), &color)) {
        return false;
    }

    //levelManager.player->setTextureRect(15, 5, 60, 85);  //
    levelManager.player->setTextureRect(15, 95, 60, 65);  //
    levelManager.player->setPosition(80, 128);  //
    levelManager.player->setMaxFrame(6);
    levelManager.player->setAnimState(0);

    levelManager.entityList.push_back(levelManager.player);
    //levelManager.player->move(10, 0);
    return true;
}

void PlayState::onEvent(SDL_Event * _event)
{
    Event::onEvent(_event);
}

void PlayState::onLoop()
{
    for (std::vector<Entity*>::iterator it = levelManager.entityList.begin(); it != levelManager.entityList.end(); ++it) {
    //    (*it)->move();
        (*it)->moveX();
        levelManager.checkCollisionX(*it);
        (*it)->moveY();
        levelManager.checkCollisionY(*it);
    }

    for (std::vector<Entity*>::iterator it = levelManager.entityList.begin(); it != levelManager.entityList.end(); ++it) {
        (*it)->animate();
    }
}

void PlayState::onRender()
{
    levelManager.drawLevel(stateManager->game->getRenderer()); //tmp
    for (std::vector<Entity*>::iterator it = levelManager.entityList.begin(); it != levelManager.entityList.end(); ++it) {
        (*it)->render(stateManager->game->getRenderer(), levelManager.getCameraOffsetX(), levelManager.getCameraOffsetY());
    }
}

void PlayState::onCleanup()
{
    for each (Entity *entity in levelManager.entityList) {
        entity->cleanup();
    }

    delete levelManager.player;
    delete levelManager.currentLevel;
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
        levelManager.player->move(-10, 0); //
        break;
    case SDLK_RIGHT:
        levelManager.player->move(10, 0);  //     
        break;
    case SDLK_UP:
        if (levelManager.player->isOnSurface()) {
            levelManager.player->move(0, -20);
            levelManager.player->setOnGround(false);
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
        levelManager.player->move(0, 0); //
        break;
    case SDLK_RIGHT:
        levelManager.player->move(0, 0);  //     
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
