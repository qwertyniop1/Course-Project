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

    //levelManager.player->setTextureRect(10, 15, 55, 70);  //
    levelManager.player->setTextureRect(15, 95, 60, 65);  //
    levelManager.player->setPosition(80, 128);  //
    levelManager.player->setMaxFrame(6);
    levelManager.player->setAnimState(0);

    enemy = new Enemy();
    enemy->load("res/1.png", stateManager->game->getRenderer()); //tmp
    enemy->setTextureRect(0, 0, 50, 50);
    enemy->setPosition(600, 128);  //
    enemy->setDX(1);

    levelManager.entityList.push_back(enemy);

    enemy = new Enemy();
    enemy->load("res/1.png", stateManager->game->getRenderer()); //tmp
    enemy->setTextureRect(0, 0, 50, 50);
    enemy->setPosition(800, 128);  //
    enemy->setDX(1);

    levelManager.entityList.push_back(enemy);

    enemy = new Enemy();
    enemy->load("res/1.png", stateManager->game->getRenderer()); //tmp
    enemy->setTextureRect(0, 0, 50, 50);
    enemy->setPosition(1000, 128);  //
    enemy->setDX(1);

    levelManager.entityList.push_back(levelManager.player);
    levelManager.entityList.push_back(enemy);
    //levelManager.player->move(10, 0);
    return true;
}

void PlayState::onEvent(SDL_Event * _event)
{
    Event::onEvent(_event);

    if (keys[SDL_SCANCODE_LEFT]) {
        levelManager.player->move(-10); //
    } else if (keys[SDL_SCANCODE_RIGHT]) {
        levelManager.player->move(10); //
    }
    else {
        levelManager.player->move(0);
    }
    if (keys[SDL_SCANCODE_UP]) {
        if (levelManager.player->isOnSurface()) {
            levelManager.player->setDY(-20);
            levelManager.player->setOnGround(false);
        }
    }
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

    //
    if (levelManager.player->getRect().x >  WINDOW_WIDTH / 2) levelManager.camera.x = levelManager.player->getRect().x - WINDOW_WIDTH / 2;
    if (levelManager.player->getRect().y <  WINDOW_HEIGTH / 2 + 50) levelManager.camera.y = levelManager.player->getRect().y - WINDOW_HEIGTH / 2;
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

    delete enemy;
    delete levelManager.player;
    delete levelManager.currentLevel;
}

void PlayState::onExit()
{
    stateManager->quit();
}
#if 0
void PlayState::onKeyDown(SDL_Keycode sym, Uint16 mod)
{
    switch (sym)
    {
    case SDLK_LEFT:
        levelManager.player->move(-10); //
        break;
    case SDLK_RIGHT:
        levelManager.player->move(10);  //     
        break;
    case SDLK_UP:
        if (levelManager.player->isOnSurface()) {
            levelManager.player->setDY(-20);
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
        levelManager.player->move(0); //
        break;
    case SDLK_RIGHT:
        levelManager.player->move(0);  //     
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
#endif